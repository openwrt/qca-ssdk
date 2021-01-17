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
#include "hsl.h"
#include "hppe_reg_access.h"
#include "appe_acl_reg.h"
#include "appe_acl.h"

sw_error_t
appe_ipr_udf_ctrl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_ctrl_u *value)
{
	if (index >= IPR_UDF_CTRL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_CTRL_ADDRESS + \
				index * IPR_UDF_CTRL_INC,
				&value->val);
}

sw_error_t
appe_ipr_udf_ctrl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_ctrl_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_CTRL_ADDRESS + \
				index * IPR_UDF_CTRL_INC,
				value->val);
}

sw_error_t
appe_ipr_udf_profile_base_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_profile_base_u *value)
{
	if (index >= IPR_UDF_PROFILE_BASE_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_PROFILE_BASE_ADDRESS + \
				index * IPR_UDF_PROFILE_BASE_INC,
				&value->val);
}

sw_error_t
appe_ipr_udf_profile_base_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_profile_base_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_PROFILE_BASE_ADDRESS + \
				index * IPR_UDF_PROFILE_BASE_INC,
				value->val);
}

sw_error_t
appe_ipr_udf_profile_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_profile_offset_u *value)
{
	if (index >= IPR_UDF_PROFILE_OFFSET_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_PROFILE_OFFSET_ADDRESS + \
				index * IPR_UDF_PROFILE_OFFSET_INC,
				&value->val);
}

sw_error_t
appe_ipr_udf_profile_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union ipr_udf_profile_offset_u *value)
{
	return hppe_reg_set(
				dev_id,
				IPR_CSR_BASE_ADDR + IPR_UDF_PROFILE_OFFSET_ADDRESS + \
				index * IPR_UDF_PROFILE_OFFSET_INC,
				value->val);
}

sw_error_t
appe_ipr_udf_ctrl_l3_type_incl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.l3_type_incl;
	return ret;
}

sw_error_t
appe_ipr_udf_ctrl_l3_type_incl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.l3_type_incl = value;
	ret = appe_ipr_udf_ctrl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_ctrl_l4_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.l4_type;
	return ret;
}

sw_error_t
appe_ipr_udf_ctrl_l4_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.l4_type = value;
	ret = appe_ipr_udf_ctrl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_ctrl_udf_profile_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf_profile;
	return ret;
}

sw_error_t
appe_ipr_udf_ctrl_udf_profile_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf_profile = value;
	ret = appe_ipr_udf_ctrl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_ctrl_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.valid;
	return ret;
}

sw_error_t
appe_ipr_udf_ctrl_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.valid = value;
	ret = appe_ipr_udf_ctrl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_ctrl_l3_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.l3_type;
	return ret;
}

sw_error_t
appe_ipr_udf_ctrl_l3_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.l3_type = value;
	ret = appe_ipr_udf_ctrl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_ctrl_l4_type_incl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.l4_type_incl;
	return ret;
}

sw_error_t
appe_ipr_udf_ctrl_l4_type_incl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_ctrl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.l4_type_incl = value;
	ret = appe_ipr_udf_ctrl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_profile_base_udf3_base_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_profile_base_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_base_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf3_base;
	return ret;
}

sw_error_t
appe_ipr_udf_profile_base_udf3_base_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_profile_base_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_base_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf3_base = value;
	ret = appe_ipr_udf_profile_base_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_profile_base_udf0_base_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_profile_base_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_base_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf0_base;
	return ret;
}

sw_error_t
appe_ipr_udf_profile_base_udf0_base_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_profile_base_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_base_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf0_base = value;
	ret = appe_ipr_udf_profile_base_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_profile_base_udf1_base_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_profile_base_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_base_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf1_base;
	return ret;
}

sw_error_t
appe_ipr_udf_profile_base_udf1_base_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_profile_base_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_base_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf1_base = value;
	ret = appe_ipr_udf_profile_base_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_profile_base_udf2_base_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_profile_base_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_base_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf2_base;
	return ret;
}

sw_error_t
appe_ipr_udf_profile_base_udf2_base_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_profile_base_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_base_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf2_base = value;
	ret = appe_ipr_udf_profile_base_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_profile_offset_udf1_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_profile_offset_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_offset_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf1_offset;
	return ret;
}

sw_error_t
appe_ipr_udf_profile_offset_udf1_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_profile_offset_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_offset_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf1_offset = value;
	ret = appe_ipr_udf_profile_offset_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_profile_offset_udf3_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_profile_offset_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_offset_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf3_offset;
	return ret;
}

sw_error_t
appe_ipr_udf_profile_offset_udf3_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_profile_offset_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_offset_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf3_offset = value;
	ret = appe_ipr_udf_profile_offset_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_profile_offset_udf0_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_profile_offset_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_offset_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf0_offset;
	return ret;
}

sw_error_t
appe_ipr_udf_profile_offset_udf0_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_profile_offset_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_offset_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf0_offset = value;
	ret = appe_ipr_udf_profile_offset_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_ipr_udf_profile_offset_udf2_offset_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union ipr_udf_profile_offset_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_offset_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf2_offset;
	return ret;
}

sw_error_t
appe_ipr_udf_profile_offset_udf2_offset_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union ipr_udf_profile_offset_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_ipr_udf_profile_offset_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf2_offset = value;
	ret = appe_ipr_udf_profile_offset_set(dev_id, index, &reg_val);
	return ret;
}