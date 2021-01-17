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
#ifndef APPE_ACL_REG_H
#define APPE_ACL_REG_H

/*[register] IPR_UDF_CTRL*/
#define IPR_UDF_CTRL
#define IPR_UDF_CTRL_ADDRESS 0x400
#define IPR_UDF_CTRL_NUM     16
#define IPR_UDF_CTRL_INC     0x4
#define IPR_UDF_CTRL_TYPE    REG_TYPE_RW
#define IPR_UDF_CTRL_DEFAULT 0x0
	/*[field] L3_TYPE*/
	#define IPR_UDF_CTRL_L3_TYPE
	#define IPR_UDF_CTRL_L3_TYPE_OFFSET  0
	#define IPR_UDF_CTRL_L3_TYPE_LEN     2
	#define IPR_UDF_CTRL_L3_TYPE_DEFAULT 0x0
	/*[field] L3_TYPE_INCL*/
	#define IPR_UDF_CTRL_L3_TYPE_INCL
	#define IPR_UDF_CTRL_L3_TYPE_INCL_OFFSET  2
	#define IPR_UDF_CTRL_L3_TYPE_INCL_LEN     1
	#define IPR_UDF_CTRL_L3_TYPE_INCL_DEFAULT 0x0
	/*[field] L4_TYPE*/
	#define IPR_UDF_CTRL_L4_TYPE
	#define IPR_UDF_CTRL_L4_TYPE_OFFSET  4
	#define IPR_UDF_CTRL_L4_TYPE_LEN     3
	#define IPR_UDF_CTRL_L4_TYPE_DEFAULT 0x0
	/*[field] L4_TYPE_INCL*/
	#define IPR_UDF_CTRL_L4_TYPE_INCL
	#define IPR_UDF_CTRL_L4_TYPE_INCL_OFFSET  7
	#define IPR_UDF_CTRL_L4_TYPE_INCL_LEN     1
	#define IPR_UDF_CTRL_L4_TYPE_INCL_DEFAULT 0x0
	/*[field] UDF_PROFILE*/
	#define IPR_UDF_CTRL_UDF_PROFILE
	#define IPR_UDF_CTRL_UDF_PROFILE_OFFSET  8
	#define IPR_UDF_CTRL_UDF_PROFILE_LEN     3
	#define IPR_UDF_CTRL_UDF_PROFILE_DEFAULT 0x0
	/*[field] VALID*/
	#define IPR_UDF_CTRL_VALID
	#define IPR_UDF_CTRL_VALID_OFFSET  31
	#define IPR_UDF_CTRL_VALID_LEN     1
	#define IPR_UDF_CTRL_VALID_DEFAULT 0x0

struct ipr_udf_ctrl {
	a_uint32_t  l3_type:2;
	a_uint32_t  l3_type_incl:1;
	a_uint32_t  _reserved0:1;
	a_uint32_t  l4_type:3;
	a_uint32_t  l4_type_incl:1;
	a_uint32_t  udf_profile:3;
	a_uint32_t  _reserved1:20;
	a_uint32_t  valid:1;
};

union ipr_udf_ctrl_u {
	a_uint32_t val;
	struct ipr_udf_ctrl bf;
};

/*[register] IPR_UDF_PROFILE_BASE*/
#define IPR_UDF_PROFILE_BASE
#define IPR_UDF_PROFILE_BASE_ADDRESS 0x440
#define IPR_UDF_PROFILE_BASE_NUM     8
#define IPR_UDF_PROFILE_BASE_INC     0x4
#define IPR_UDF_PROFILE_BASE_TYPE    REG_TYPE_RW
#define IPR_UDF_PROFILE_BASE_DEFAULT 0x0
	/*[field] UDF0_BASE*/
	#define IPR_UDF_PROFILE_BASE_UDF0_BASE
	#define IPR_UDF_PROFILE_BASE_UDF0_BASE_OFFSET  0
	#define IPR_UDF_PROFILE_BASE_UDF0_BASE_LEN     2
	#define IPR_UDF_PROFILE_BASE_UDF0_BASE_DEFAULT 0x0
	/*[field] UDF1_BASE*/
	#define IPR_UDF_PROFILE_BASE_UDF1_BASE
	#define IPR_UDF_PROFILE_BASE_UDF1_BASE_OFFSET  8
	#define IPR_UDF_PROFILE_BASE_UDF1_BASE_LEN     3
	#define IPR_UDF_PROFILE_BASE_UDF1_BASE_DEFAULT 0x0
	/*[field] UDF2_BASE*/
	#define IPR_UDF_PROFILE_BASE_UDF2_BASE
	#define IPR_UDF_PROFILE_BASE_UDF2_BASE_OFFSET  16
	#define IPR_UDF_PROFILE_BASE_UDF2_BASE_LEN     3
	#define IPR_UDF_PROFILE_BASE_UDF2_BASE_DEFAULT 0x0
	/*[field] UDF3_BASE*/
	#define IPR_UDF_PROFILE_BASE_UDF3_BASE
	#define IPR_UDF_PROFILE_BASE_UDF3_BASE_OFFSET  24
	#define IPR_UDF_PROFILE_BASE_UDF3_BASE_LEN     3
	#define IPR_UDF_PROFILE_BASE_UDF3_BASE_DEFAULT 0x0

struct ipr_udf_profile_base {
	a_uint32_t  udf0_base:2;
	a_uint32_t  _reserved0:6;
	a_uint32_t  udf1_base:3;
	a_uint32_t  _reserved1:5;
	a_uint32_t  udf2_base:3;
	a_uint32_t  _reserved2:5;
	a_uint32_t  udf3_base:3;
	a_uint32_t  _reserved3:5;
};

union ipr_udf_profile_base_u {
	a_uint32_t val;
	struct ipr_udf_profile_base bf;
};

/*[register] IPR_UDF_PROFILE_OFFSET*/
#define IPR_UDF_PROFILE_OFFSET
#define IPR_UDF_PROFILE_OFFSET_ADDRESS 0x460
#define IPR_UDF_PROFILE_OFFSET_NUM     8
#define IPR_UDF_PROFILE_OFFSET_INC     0x4
#define IPR_UDF_PROFILE_OFFSET_TYPE    REG_TYPE_RW
#define IPR_UDF_PROFILE_OFFSET_DEFAULT 0x0
	/*[field] UDF0_OFFSET*/
	#define IPR_UDF_PROFILE_OFFSET_UDF0_OFFSET
	#define IPR_UDF_PROFILE_OFFSET_UDF0_OFFSET_OFFSET  0
	#define IPR_UDF_PROFILE_OFFSET_UDF0_OFFSET_LEN     6
	#define IPR_UDF_PROFILE_OFFSET_UDF0_OFFSET_DEFAULT 0x0
	/*[field] UDF1_OFFSET*/
	#define IPR_UDF_PROFILE_OFFSET_UDF1_OFFSET
	#define IPR_UDF_PROFILE_OFFSET_UDF1_OFFSET_OFFSET  8
	#define IPR_UDF_PROFILE_OFFSET_UDF1_OFFSET_LEN     6
	#define IPR_UDF_PROFILE_OFFSET_UDF1_OFFSET_DEFAULT 0x0
	/*[field] UDF2_OFFSET*/
	#define IPR_UDF_PROFILE_OFFSET_UDF2_OFFSET
	#define IPR_UDF_PROFILE_OFFSET_UDF2_OFFSET_OFFSET  16
	#define IPR_UDF_PROFILE_OFFSET_UDF2_OFFSET_LEN     6
	#define IPR_UDF_PROFILE_OFFSET_UDF2_OFFSET_DEFAULT 0x0
	/*[field] UDF3_OFFSET*/
	#define IPR_UDF_PROFILE_OFFSET_UDF3_OFFSET
	#define IPR_UDF_PROFILE_OFFSET_UDF3_OFFSET_OFFSET  24
	#define IPR_UDF_PROFILE_OFFSET_UDF3_OFFSET_LEN     6
	#define IPR_UDF_PROFILE_OFFSET_UDF3_OFFSET_DEFAULT 0x0

struct ipr_udf_profile_offset {
	a_uint32_t  udf0_offset:6;
	a_uint32_t  _reserved0:2;
	a_uint32_t  udf1_offset:6;
	a_uint32_t  _reserved1:2;
	a_uint32_t  udf2_offset:6;
	a_uint32_t  _reserved2:2;
	a_uint32_t  udf3_offset:6;
	a_uint32_t  _reserved3:2;
};

union ipr_udf_profile_offset_u {
	a_uint32_t val;
	struct ipr_udf_profile_offset bf;
};

#endif
