/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


/**
 * @defgroup
 * @{
 */
#include "sw.h"
#include "adpt.h"
#include "adpt_hppe.h"
#include "appe_acl_reg.h"
#include "appe_acl.h"

#define NON_IP_PROFILE_ID 7
#define IP4_PROFILE_ID 6
#define IP6_PROFILE_ID 5
#define ADPT_UDF_MAX_NUM 4

static a_bool_t
_adpt_appe_is_udf_profile_entry_equal(a_uint32_t dev_id,
		fal_acl_udf_profile_entry_t * entry1, fal_acl_udf_profile_entry_t * entry2)
{
	if (entry1->field_flag[0] == entry2->field_flag[0] &&
		entry1->l3_type == entry2->l3_type &&
		entry1->l4_type == entry2->l4_type)
	{
		return A_TRUE;
	}
	else
	{
		return A_FALSE;
	}
}

static a_bool_t
_adpt_appe_get_udf_profile_entry_by_index(a_uint32_t dev_id,
		a_uint32_t index, fal_acl_udf_profile_entry_t * entry, a_uint32_t * profile_id)
{
	union ipr_udf_ctrl_u udf_ctrl = {0};

	SW_RTN_ON_ERROR(appe_ipr_udf_ctrl_get(dev_id, index, &udf_ctrl));
	if (!udf_ctrl.bf.valid)
	{
		aos_mem_zero(&udf_ctrl, sizeof (udf_ctrl));
	}
	entry->l3_type = udf_ctrl.bf.l3_type;
	entry->l4_type = udf_ctrl.bf.l4_type;
	*profile_id = udf_ctrl.bf.udf_profile;

	if (udf_ctrl.bf.l3_type_incl)
	{
		FAL_FIELD_FLG_SET(entry->field_flag, FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L3_TYPE);
	}
	else
	{
		FAL_FIELD_FLG_CLR(entry->field_flag, FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L3_TYPE);
	}
	if (udf_ctrl.bf.l4_type_incl)
	{
		FAL_FIELD_FLG_SET(entry->field_flag, FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L4_TYPE);
	}
	else
	{
		FAL_FIELD_FLG_CLR(entry->field_flag, FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L4_TYPE);
	}
	return udf_ctrl.bf.valid;
}

static sw_error_t
_adpt_appe_insert_udf_profile_entry_by_index(a_uint32_t dev_id,
		a_uint32_t index, fal_acl_udf_profile_entry_t * entry, a_uint32_t profile_id)
{
	union ipr_udf_ctrl_u udf_ctrl = {0};

	udf_ctrl.bf.valid = A_TRUE;
	udf_ctrl.bf.l3_type = entry->l3_type;
	udf_ctrl.bf.l4_type = entry->l4_type;
	udf_ctrl.bf.udf_profile = profile_id;

	if (FAL_FIELD_FLG_TST(entry->field_flag, FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L3_TYPE))
	{
		udf_ctrl.bf.l3_type_incl = A_TRUE;
	}
	if (FAL_FIELD_FLG_TST(entry->field_flag, FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L4_TYPE))
	{
		udf_ctrl.bf.l4_type_incl = A_TRUE;
	}
	return appe_ipr_udf_ctrl_set(dev_id, index, &udf_ctrl);
}

static a_uint32_t
_adpt_appe_udf_profile_entry_weight(fal_acl_udf_profile_entry_t * entry)
{
	a_uint32_t weight = 0;
	if (FAL_FIELD_FLG_TST(entry->field_flag, FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L3_TYPE))
	{
		weight++;
	}
	if (FAL_FIELD_FLG_TST(entry->field_flag, FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L4_TYPE))
	{
		weight++;
	}
	return weight;
}

static sw_error_t
_adpt_appe_insert_udf_profile_entry_by_sort(a_uint32_t dev_id,
		a_uint32_t index, fal_acl_udf_profile_entry_t * entry, a_uint32_t profile_id)
{
	fal_acl_udf_profile_entry_t temp_entry = {0};
	a_uint32_t temp_profile_id;
	a_uint32_t idx, weight, temp_weight;

	weight = _adpt_appe_udf_profile_entry_weight(entry);

	for (idx = index; idx < IPR_UDF_CTRL_MAX_ENTRY-1; idx++)
	{
		aos_mem_zero(&temp_entry, sizeof (fal_acl_udf_profile_entry_t));
		_adpt_appe_get_udf_profile_entry_by_index(dev_id, idx+1,
				&temp_entry, &temp_profile_id);
		temp_weight = _adpt_appe_udf_profile_entry_weight(&temp_entry);
		if (weight < temp_weight)
		{
			SW_RTN_ON_ERROR(_adpt_appe_insert_udf_profile_entry_by_index(dev_id, idx,
								&temp_entry, temp_profile_id));
		}
		else
		{
			break;
		}
	}
	return _adpt_appe_insert_udf_profile_entry_by_index(dev_id, idx, entry, profile_id);
}

static a_bool_t
_adpt_appe_is_udf_profile_entry_exist(a_uint32_t dev_id,
		a_uint32_t profile_id, fal_acl_udf_profile_entry_t * entry)
{
	a_uint32_t idx, temp_profile_id;
	a_bool_t entry_valid;
	fal_acl_udf_profile_entry_t temp_entry;

	ADPT_DEV_ID_CHECK(dev_id);

	if (profile_id >= IPR_UDF_PROFILE_BASE_MAX_ENTRY)
	{
		return SW_OUT_OF_RANGE;
	}

	for (idx = 0; idx < IPR_UDF_CTRL_MAX_ENTRY; idx++)
	{
		aos_mem_zero(&temp_entry, sizeof (fal_acl_udf_profile_entry_t));
		entry_valid = _adpt_appe_get_udf_profile_entry_by_index(dev_id, idx,
						&temp_entry, &temp_profile_id);
		if (entry_valid == A_TRUE)
		{
			if (A_TRUE == _adpt_appe_is_udf_profile_entry_equal(dev_id,
						&temp_entry, entry))
			{
				if (temp_profile_id == profile_id)
				{
					return A_TRUE;
				}
			}
		}
	}
	return A_FALSE;
}

static sw_error_t
_adpt_appe_acl_udf_profile_entry_get(a_uint32_t dev_id, a_uint32_t profile_id,
		fal_acl_udf_profile_entry_t * entry, a_bool_t sign_tag)
{
	a_uint32_t idx, temp_profile_id;
	a_bool_t entry_valid;
	fal_acl_udf_profile_entry_t temp_entry;

	ADPT_DEV_ID_CHECK(dev_id);

	if (profile_id >= IPR_UDF_PROFILE_BASE_MAX_ENTRY)
	{
		return SW_OUT_OF_RANGE;
	}

	for (idx = 0; idx < IPR_UDF_CTRL_MAX_ENTRY; idx++)
	{
		aos_mem_zero(&temp_entry, sizeof (fal_acl_udf_profile_entry_t));
		entry_valid = _adpt_appe_get_udf_profile_entry_by_index(dev_id, idx,
						&temp_entry, &temp_profile_id);
		if (entry_valid == A_TRUE)
		{
			if (temp_profile_id == profile_id)
			{
				if (sign_tag == A_TRUE)
				{
					aos_mem_copy(entry, &temp_entry,
						sizeof (fal_acl_udf_profile_entry_t));
					break;
				}
				if (A_TRUE == _adpt_appe_is_udf_profile_entry_equal(dev_id,
						&temp_entry, entry))
				{
					sign_tag = A_TRUE;
				}
			}
		}
	}
	if (idx == IPR_UDF_CTRL_MAX_ENTRY)
	{
		return SW_NOT_FOUND;
	}
	return SW_OK;
}

sw_error_t
adpt_appe_acl_udf_profile_entry_add(a_uint32_t dev_id, a_uint32_t profile_id,
		fal_acl_udf_profile_entry_t * entry)
{
	a_uint32_t entry_idx, temp_profile_id;
	a_bool_t entry_valid;
	a_int32_t idx;
	fal_acl_udf_profile_entry_t temp_entry;

	ADPT_DEV_ID_CHECK(dev_id);

	if (profile_id >= IPR_UDF_PROFILE_BASE_MAX_ENTRY)
	{
		return SW_OUT_OF_RANGE;
	}

	for (idx = IPR_UDF_CTRL_MAX_ENTRY-1; idx >= 0; idx--)
	{
		aos_mem_zero(&temp_entry, sizeof (fal_acl_udf_profile_entry_t));
		entry_valid = _adpt_appe_get_udf_profile_entry_by_index(dev_id, idx,
						&temp_entry, &temp_profile_id);
		if (entry_valid == A_TRUE)
		{
			if (A_TRUE == _adpt_appe_is_udf_profile_entry_equal(dev_id,
						&temp_entry, entry))
			{
				if (temp_profile_id == profile_id)
				{
					return SW_ALREADY_EXIST;
				}
				else
				{
					SSDK_DEBUG("original profile %d, updated profile %d\n",
								temp_profile_id, profile_id);
					return _adpt_appe_insert_udf_profile_entry_by_index(dev_id,
								idx, entry, profile_id);
				}
			}
		}
		else
		{
			entry_idx = idx;
			break;
		}
	}
	if (idx < 0)
	{
		return SW_NO_RESOURCE;
	}
	/* insert new udf entry and sort the entries*/
	return _adpt_appe_insert_udf_profile_entry_by_sort(dev_id, entry_idx, entry, profile_id);
}

sw_error_t
adpt_appe_acl_udf_profile_entry_del(a_uint32_t dev_id, a_uint32_t profile_id,
		fal_acl_udf_profile_entry_t * entry)
{
	a_uint32_t idx, temp_profile_id;
	a_int32_t j;
	a_bool_t entry_valid;
	fal_acl_udf_profile_entry_t temp_entry;
	union ipr_udf_ctrl_u udf_ctrl_zero_entry = {0};

	ADPT_DEV_ID_CHECK(dev_id);

	if (profile_id >= IPR_UDF_PROFILE_BASE_MAX_ENTRY)
	{
		return SW_OUT_OF_RANGE;
	}

	for (idx = 0; idx < IPR_UDF_CTRL_MAX_ENTRY; idx++)
	{
		aos_mem_zero(&temp_entry, sizeof (fal_acl_udf_profile_entry_t));
		entry_valid = _adpt_appe_get_udf_profile_entry_by_index(dev_id, idx,
						&temp_entry, &temp_profile_id);
		if (entry_valid == A_TRUE)
		{
			if (A_TRUE == _adpt_appe_is_udf_profile_entry_equal(dev_id,
						&temp_entry, entry))
			{
				if (temp_profile_id == profile_id)
				{
					/* find the entry*/
					break;
				}
			}
		}
	}

	if (idx == IPR_UDF_CTRL_MAX_ENTRY)
	{
		return SW_NOT_FOUND;
	}

	/* clear the find entry and resort the entries */
	for (j = idx; j > 0; j --)
	{
		aos_mem_zero(&temp_entry, sizeof (fal_acl_udf_profile_entry_t));
		entry_valid = _adpt_appe_get_udf_profile_entry_by_index(dev_id, j-1,
						&temp_entry, &temp_profile_id);
		if (entry_valid == A_TRUE)
		{
			SW_RTN_ON_ERROR(_adpt_appe_insert_udf_profile_entry_by_index(dev_id, j,
						&temp_entry, temp_profile_id));
		}
		else
		{
			break;
		}
	}
	return appe_ipr_udf_ctrl_set(dev_id, j, &udf_ctrl_zero_entry);
}

sw_error_t
adpt_appe_acl_udf_profile_entry_getfirst(a_uint32_t dev_id, a_uint32_t profile_id,
		fal_acl_udf_profile_entry_t * entry)
{
	return _adpt_appe_acl_udf_profile_entry_get(dev_id, profile_id, entry, A_TRUE);
}

sw_error_t
adpt_appe_acl_udf_profile_entry_getnext(a_uint32_t dev_id, a_uint32_t profile_id,
		fal_acl_udf_profile_entry_t * entry)
{
	return _adpt_appe_acl_udf_profile_entry_get(dev_id, profile_id, entry, A_FALSE);
}

sw_error_t
adpt_appe_acl_udf_profile_cfg_set(a_uint32_t dev_id, a_uint32_t profile_id,
		a_uint32_t udf_idx, fal_acl_udf_type_t udf_type, a_uint32_t offset)
{
	a_uint8_t udf_base = 0;
	union ipr_udf_profile_base_u udf_profile_base = {0};
	union ipr_udf_profile_offset_u udf_profile_offset = {0};

	ADPT_DEV_ID_CHECK(dev_id);

	if (offset % 2)
	{ /*only support even data*/
		return SW_BAD_VALUE;
	}

	switch(udf_type)
	{
		case FAL_ACL_UDF_TYPE_L2:
			udf_base = 0;
			break;
		case FAL_ACL_UDF_TYPE_L3:
			udf_base = 1;
			break;
		case FAL_ACL_UDF_TYPE_L4:
			udf_base = 2;
			break;
		default:
			return SW_NOT_SUPPORTED;
	}

	SW_RTN_ON_ERROR(appe_ipr_udf_profile_base_get(dev_id, profile_id, &udf_profile_base));
	SW_RTN_ON_ERROR(appe_ipr_udf_profile_offset_get(dev_id, profile_id, &udf_profile_offset));

	switch(udf_idx)
	{
		case 0:
			udf_profile_base.bf.udf0_base = udf_base;
			udf_profile_offset.bf.udf0_offset = offset/2;
			break;
		case 1:
			udf_profile_base.bf.udf1_base = udf_base;
			udf_profile_offset.bf.udf1_offset = offset/2;
			break;
		case 2:
			udf_profile_base.bf.udf2_base = udf_base;
			udf_profile_offset.bf.udf2_offset = offset/2;
			break;
		case 3:
			udf_profile_base.bf.udf3_base = udf_base;
			udf_profile_offset.bf.udf3_offset = offset/2;
			break;
		default:
			return SW_OUT_OF_RANGE;
	}

	SW_RTN_ON_ERROR(appe_ipr_udf_profile_base_set(dev_id, profile_id, &udf_profile_base));
	return appe_ipr_udf_profile_offset_set(dev_id, profile_id, &udf_profile_offset);
}

sw_error_t
adpt_appe_acl_udf_profile_cfg_get(a_uint32_t dev_id, a_uint32_t profile_id,
		a_uint32_t udf_idx, fal_acl_udf_type_t * udf_type, a_uint32_t * offset)
{
	a_uint8_t udf_base = 0;
	union ipr_udf_profile_base_u udf_profile_base = {0};
	union ipr_udf_profile_offset_u udf_profile_offset = {0};

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(udf_type);
	ADPT_NULL_POINT_CHECK(offset);

	SW_RTN_ON_ERROR(appe_ipr_udf_profile_base_get(dev_id, profile_id, &udf_profile_base));
	SW_RTN_ON_ERROR(appe_ipr_udf_profile_offset_get(dev_id, profile_id, &udf_profile_offset));

	switch(udf_idx)
	{
		case 0:
			udf_base = udf_profile_base.bf.udf0_base;
			*offset = udf_profile_offset.bf.udf0_offset*2;
			break;
		case 1:
			udf_base = udf_profile_base.bf.udf1_base;
			*offset = udf_profile_offset.bf.udf1_offset*2;
			break;
		case 2:
			udf_base = udf_profile_base.bf.udf2_base;
			*offset = udf_profile_offset.bf.udf2_offset*2;
			break;
		case 3:
			udf_base = udf_profile_base.bf.udf3_base;
			*offset = udf_profile_offset.bf.udf3_offset*2;
			break;
		default:
			return SW_OUT_OF_RANGE;
	}

	switch(udf_base)
	{
		case 0:
			*udf_type = FAL_ACL_UDF_TYPE_L2;
			break;
		case 1:
			*udf_type = FAL_ACL_UDF_TYPE_L3;
			break;
		case 2:
			*udf_type = FAL_ACL_UDF_TYPE_L4;
			break;
		default:
			return SW_NOT_SUPPORTED;
	}

	return SW_OK;
}

sw_error_t
adpt_appe_acl_udf_profile_set(a_uint32_t dev_id, fal_acl_udf_pkt_type_t pkt_type,
		a_uint32_t udf_idx, fal_acl_udf_type_t udf_type, a_uint32_t offset)
{
	sw_error_t rv;
	a_uint32_t profile_id;
	fal_acl_udf_profile_entry_t udf_entry = {0};

	ADPT_DEV_ID_CHECK(dev_id);

	if (udf_idx >= ADPT_UDF_MAX_NUM)
	{
		return SW_OUT_OF_RANGE;
	}

	switch(pkt_type)
	{
		case FAL_ACL_UDF_NON_IP:
			profile_id = NON_IP_PROFILE_ID;
			udf_entry.l3_type = FAL_L3_TYPE_OTHERS;
			udf_entry.l4_type = FAL_L4_TYPE_OTHERS;
			FAL_FIELD_FLG_SET(udf_entry.field_flag,
				FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L3_TYPE);
			FAL_FIELD_FLG_SET(udf_entry.field_flag,
				FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L4_TYPE);
			break;
		case FAL_ACL_UDF_IP4:
			profile_id = IP4_PROFILE_ID;
			udf_entry.l3_type = FAL_L3_TYPE_IPV4;
			FAL_FIELD_FLG_SET(udf_entry.field_flag,
				FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L3_TYPE);
			break;
		case FAL_ACL_UDF_IP6:
			profile_id = IP6_PROFILE_ID;
			udf_entry.l3_type = FAL_L3_TYPE_IPV6;
			FAL_FIELD_FLG_SET(udf_entry.field_flag,
				FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L3_TYPE);
			break;
		default:
			return SW_NOT_SUPPORTED;
	}
	rv = adpt_appe_acl_udf_profile_entry_add(dev_id, profile_id, &udf_entry);
	/* if pkt udf entry is already exist, only update the udfprofile base and offset cfg */
	if(rv != SW_OK && rv != SW_ALREADY_EXIST)
	{
		return rv;
	}
	return adpt_appe_acl_udf_profile_cfg_set(dev_id, profile_id, udf_idx, udf_type, offset);
}

sw_error_t
adpt_appe_acl_udf_profile_get(a_uint32_t dev_id, fal_acl_udf_pkt_type_t pkt_type,
		a_uint32_t udf_idx, fal_acl_udf_type_t * udf_type, a_uint32_t * offset)
{
	a_uint32_t profile_id;
	a_bool_t exist = A_FALSE;
	fal_acl_udf_profile_entry_t udf_entry = {0};

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(udf_type);
	ADPT_NULL_POINT_CHECK(offset);

	if (udf_idx >= ADPT_UDF_MAX_NUM)
	{
		return SW_OUT_OF_RANGE;
	}

	switch(pkt_type)
	{
		case FAL_ACL_UDF_NON_IP:
			profile_id = NON_IP_PROFILE_ID;
			udf_entry.l3_type = FAL_L3_TYPE_OTHERS;
			udf_entry.l4_type = FAL_L4_TYPE_OTHERS;
			FAL_FIELD_FLG_SET(udf_entry.field_flag,
				FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L3_TYPE);
			FAL_FIELD_FLG_SET(udf_entry.field_flag,
				FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L4_TYPE);
			break;
		case FAL_ACL_UDF_IP4:
			profile_id = IP4_PROFILE_ID;
			udf_entry.l3_type = FAL_L3_TYPE_IPV4;
			FAL_FIELD_FLG_SET(udf_entry.field_flag,
				FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L3_TYPE);
			break;
		case FAL_ACL_UDF_IP6:
			profile_id = IP6_PROFILE_ID;
			udf_entry.l3_type = FAL_L3_TYPE_IPV6;
			FAL_FIELD_FLG_SET(udf_entry.field_flag,
				FAL_ACL_UDF_PROFILE_ENTRY_FIELD_L3_TYPE);
			break;
		default:
			return SW_NOT_SUPPORTED;
	}
	/* check if pkt type udf entry is exist */
	exist = _adpt_appe_is_udf_profile_entry_exist(dev_id, profile_id, &udf_entry);
	if (exist == A_FALSE)
	{
		SSDK_DEBUG("pkt type udf entry is not exist!\n");
		return SW_NOT_FOUND;
	}
	return adpt_appe_acl_udf_profile_cfg_get(dev_id, profile_id, udf_idx, udf_type, offset);
}

/**
 * @}
 */
