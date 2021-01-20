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
#ifndef _ADPT_APPE_ACL_H_
#define _ADPT_APPE_ACL_H_

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

sw_error_t
adpt_appe_acl_udf_profile_set(a_uint32_t dev_id, fal_acl_udf_pkt_type_t pkt_type,
	a_uint32_t udf_idx, fal_acl_udf_type_t udf_type, a_uint32_t offset);
sw_error_t
adpt_appe_acl_udf_profile_get(a_uint32_t dev_id, fal_acl_udf_pkt_type_t pkt_type,
	a_uint32_t udf_idx, fal_acl_udf_type_t * udf_type, a_uint32_t * offset);
sw_error_t
adpt_appe_acl_udf_profile_entry_add(a_uint32_t dev_id, a_uint32_t profile_id,
	fal_acl_udf_profile_entry_t * entry);
sw_error_t
adpt_appe_acl_udf_profile_entry_del(a_uint32_t dev_id, a_uint32_t profile_id,
	fal_acl_udf_profile_entry_t * entry);
sw_error_t
adpt_appe_acl_udf_profile_entry_getfirst(a_uint32_t dev_id, a_uint32_t profile_id,
	fal_acl_udf_profile_entry_t * entry);
sw_error_t
adpt_appe_acl_udf_profile_entry_getnext(a_uint32_t dev_id, a_uint32_t profile_id,
	fal_acl_udf_profile_entry_t * entry);
sw_error_t
adpt_appe_acl_udf_profile_cfg_set(a_uint32_t dev_id, a_uint32_t profile_id,
	a_uint32_t udf_idx, fal_acl_udf_type_t udf_type, a_uint32_t offset);
sw_error_t
adpt_appe_acl_udf_profile_cfg_get(a_uint32_t dev_id, a_uint32_t profile_id,
	a_uint32_t udf_idx, fal_acl_udf_type_t * udf_type, a_uint32_t * offset);

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif
/**
 * @}
 */
