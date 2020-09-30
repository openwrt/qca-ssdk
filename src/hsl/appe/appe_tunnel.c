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
#include "appe_tunnel_reg.h"
#include "appe_tunnel.h"

sw_error_t
appe_tl_tbl_op_get(
		a_uint32_t dev_id,
		union tl_tbl_op_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_set(
		a_uint32_t dev_id,
		union tl_tbl_op_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data0_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data0_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA0_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data0_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data0_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA0_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data1_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data1_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA1_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data1_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data1_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA1_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data2_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data2_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA2_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data2_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data2_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA2_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data3_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data3_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA3_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data3_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data3_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA3_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data4_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data4_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA4_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data4_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data4_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA4_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data5_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data5_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA5_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data5_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data5_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA5_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data6_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data6_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA6_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data6_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data6_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA6_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data7_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data7_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA7_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data7_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data7_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA7_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data8_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data8_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA8_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data8_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data8_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA8_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data9_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data9_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA9_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data9_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data9_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA9_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data10_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data10_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA10_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data10_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data10_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA10_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data11_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data11_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA11_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data11_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data11_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA11_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data12_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data12_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA12_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data12_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data12_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA12_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data13_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data13_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA13_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data13_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data13_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA13_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data14_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data14_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA14_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data14_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data14_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA14_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data15_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data15_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA15_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data15_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data15_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA15_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_op_data16_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data16_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA16_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_op_data16_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data16_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_OP_DATA16_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data0_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data0_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA0_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data0_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data0_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA0_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data1_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data1_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA1_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data1_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data1_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA1_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data2_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data2_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA2_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data2_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data2_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA2_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data3_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data3_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA3_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data3_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data3_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA3_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data4_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data4_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA4_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data4_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data4_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA4_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data5_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data5_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA5_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data5_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data5_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA5_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data6_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data6_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA6_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data6_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data6_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA6_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data7_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data7_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA7_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data7_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data7_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA7_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data8_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data8_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA8_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data8_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data8_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA8_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data9_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data9_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA9_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data9_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data9_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA9_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data10_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data10_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA10_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data10_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data10_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA10_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data11_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data11_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA11_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data11_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data11_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA11_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data12_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data12_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA12_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data12_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data12_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA12_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data13_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data13_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA13_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data13_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data13_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA13_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data14_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data14_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA14_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data14_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data14_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA14_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data15_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data15_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA15_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data15_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data15_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA15_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data16_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data16_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA16_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_op_data16_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data16_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_OP_DATA16_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data0_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data0_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA0_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data1_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data1_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA1_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data2_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data2_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA2_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data3_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data3_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA3_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data4_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data4_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA4_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data5_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data5_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA5_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data6_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data6_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA6_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data7_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data7_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA7_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data8_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data8_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA8_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data9_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data9_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA9_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data10_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data10_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA10_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data11_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data11_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA11_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data12_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data12_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA12_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data13_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data13_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA13_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data14_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data14_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA14_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data15_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data15_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA15_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_tbl_rd_rslt_data16_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data16_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_RD_RSLT_DATA16_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_ctrl_get(
		a_uint32_t dev_id,
		union tl_ctrl_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_CTRL_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_ctrl_set(
		a_uint32_t dev_id,
		union tl_ctrl_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_CTRL_ADDRESS,
				value->val);
}

sw_error_t
appe_tl_ingress_cnt_get(
		a_uint32_t dev_id,
		union tl_ingress_cnt_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_INGRESS_CNT_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_egress_cnt_get(
		a_uint32_t dev_id,
		union tl_egress_cnt_u *value)
{
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_EGRESS_CNT_ADDRESS,
				&value->val);
}

sw_error_t
appe_tl_l3_if_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_l3_if_tbl_u *value)
{
	if (index >= TL_L3_IF_TBL_MAX_ENTRY)
		return SW_OUT_OF_RANGE;
	return hppe_reg_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_L3_IF_TBL_ADDRESS + \
				index * TL_L3_IF_TBL_INC,
				&value->val);
}

sw_error_t
appe_tl_l3_if_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_l3_if_tbl_u *value)
{
	return hppe_reg_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_L3_IF_TBL_ADDRESS + \
				index * TL_L3_IF_TBL_INC,
				value->val);
}

sw_error_t
appe_tl_key_gen_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_key_gen_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_KEY_GEN_ADDRESS + \
				index * TL_KEY_GEN_INC,
				value->val,
				3);
}

sw_error_t
appe_tl_key_gen_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_key_gen_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_KEY_GEN_ADDRESS + \
				index * TL_KEY_GEN_INC,
				value->val,
				3);
}

sw_error_t
appe_tl_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_tbl_u *value)
{
	return hppe_reg_tbl_get(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_ADDRESS + \
				index * TL_TBL_INC,
				value->val,
				14);
}

sw_error_t
appe_tl_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_tbl_u *value)
{
	return hppe_reg_tbl_set(
				dev_id,
				TUNNEL_LOOKUP_BASE_ADDR + TL_TBL_ADDRESS + \
				index * TL_TBL_INC,
				value->val,
				14);
}

sw_error_t
appe_tl_tbl_op_op_mode_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	*value = reg_val.bf.op_mode;
	return ret;
}

sw_error_t
appe_tl_tbl_op_op_mode_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.op_mode = value;
	ret = appe_tl_tbl_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_op_type_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	*value = reg_val.bf.op_type;
	return ret;
}

sw_error_t
appe_tl_tbl_op_op_type_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.op_type = value;
	ret = appe_tl_tbl_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_op_rslt_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	*value = reg_val.bf.op_rslt;
	return ret;
}

sw_error_t
appe_tl_tbl_op_op_rslt_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.op_rslt = value;
	ret = appe_tl_tbl_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_busy_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	*value = reg_val.bf.busy;
	return ret;
}

sw_error_t
appe_tl_tbl_op_busy_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.busy = value;
	ret = appe_tl_tbl_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_entry_index_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	*value = reg_val.bf.entry_index;
	return ret;
}

sw_error_t
appe_tl_tbl_op_entry_index_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.entry_index = value;
	ret = appe_tl_tbl_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_hash_block_bitmap_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	*value = reg_val.bf.hash_block_bitmap;
	return ret;
}

sw_error_t
appe_tl_tbl_op_hash_block_bitmap_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.hash_block_bitmap = value;
	ret = appe_tl_tbl_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data0_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data0_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data0_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data0_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data0_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data1_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data1_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data1_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data1_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data1_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data2_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data2_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data2_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data2_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data2_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data2_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data2_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data3_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data3_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data3_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data3_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data3_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data3_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data3_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data4_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data4_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data4_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data4_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data4_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data4_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data4_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data5_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data5_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data5_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data5_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data5_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data5_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data5_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data6_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data6_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data6_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data6_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data6_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data6_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data6_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data7_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data7_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data7_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data7_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data7_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data8_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data8_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data8_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data8_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data8_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data8_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data8_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data9_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data9_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data9_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data9_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data9_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data9_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data9_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data10_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data10_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data10_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data10_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data10_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data10_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data10_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data11_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data11_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data11_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data11_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data11_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data11_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data11_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data12_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data12_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data12_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data12_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data12_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data12_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data12_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data13_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data13_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data13_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data13_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data13_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data13_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data13_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data14_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data14_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data14_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data14_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data14_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data14_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data14_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data15_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data15_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data15_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data15_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data15_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data15_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data15_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_op_data16_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_op_data16_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data16_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_op_data16_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_op_data16_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_op_data16_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_op_data16_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_op_mode_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	*value = reg_val.bf.op_mode;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_op_mode_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.op_mode = value;
	ret = appe_tl_tbl_rd_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_op_type_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	*value = reg_val.bf.op_type;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_op_type_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.op_type = value;
	ret = appe_tl_tbl_rd_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_op_rslt_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	*value = reg_val.bf.op_rslt;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_op_rslt_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.op_rslt = value;
	ret = appe_tl_tbl_rd_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_busy_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	*value = reg_val.bf.busy;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_busy_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.busy = value;
	ret = appe_tl_tbl_rd_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_entry_index_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	*value = reg_val.bf.entry_index;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_entry_index_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.entry_index = value;
	ret = appe_tl_tbl_rd_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_hash_block_bitmap_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	*value = reg_val.bf.hash_block_bitmap;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_hash_block_bitmap_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.hash_block_bitmap = value;
	ret = appe_tl_tbl_rd_op_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data0_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data0_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data0_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data0_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data0_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data1_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data1_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data1_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data1_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data1_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data2_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data2_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data2_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data2_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data2_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data2_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data2_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data3_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data3_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data3_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data3_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data3_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data3_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data3_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data4_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data4_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data4_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data4_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data4_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data4_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data4_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data5_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data5_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data5_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data5_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data5_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data5_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data5_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data6_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data6_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data6_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data6_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data6_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data6_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data6_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data7_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data7_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data7_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data7_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data7_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data8_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data8_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data8_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data8_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data8_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data8_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data8_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data9_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data9_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data9_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data9_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data9_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data9_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data9_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data10_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data10_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data10_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data10_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data10_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data10_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data10_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data11_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data11_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data11_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data11_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data11_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data11_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data11_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data12_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data12_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data12_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data12_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data12_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data12_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data12_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data13_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data13_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data13_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data13_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data13_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data13_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data13_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data14_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data14_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data14_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data14_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data14_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data14_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data14_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data15_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data15_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data15_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data15_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data15_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data15_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data15_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data16_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_op_data16_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data16_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_op_data16_data_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_tbl_rd_op_data16_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_op_data16_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.data = value;
	ret = appe_tl_tbl_rd_op_data16_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data0_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data0_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data0_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data1_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data1_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data1_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data2_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data2_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data2_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data3_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data3_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data3_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data4_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data4_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data4_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data5_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data5_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data5_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data6_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data6_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data6_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data7_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data7_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data7_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data8_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data8_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data8_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data9_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data9_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data9_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data10_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data10_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data10_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data11_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data11_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data11_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data12_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data12_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data12_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data13_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data13_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data13_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data14_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data14_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data14_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data15_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data15_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data15_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_tbl_rd_rslt_data16_data_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_tbl_rd_rslt_data16_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_rd_rslt_data16_get(dev_id, &reg_val);
	*value = reg_val.bf.data;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_hash_mode_0_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.tl_hash_mode_0;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_hash_mode_0_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tl_hash_mode_0 = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_pppoe_multicast_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pppoe_multicast_cmd;
	return ret;
}

sw_error_t
appe_tl_ctrl_pppoe_multicast_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pppoe_multicast_cmd = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_vlan_check_de_acce_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.tl_vlan_check_de_acce;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_vlan_check_de_acce_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tl_vlan_check_de_acce = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_udp_csum_zero_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.udp_csum_zero_cmd;
	return ret;
}

sw_error_t
appe_tl_ctrl_udp_csum_zero_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udp_csum_zero_cmd = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_vlan_check_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.tl_vlan_check_cmd;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_vlan_check_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tl_vlan_check_cmd = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_src_if_check_de_acce_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.tl_src_if_check_de_acce;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_src_if_check_de_acce_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tl_src_if_check_de_acce = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_map_non_tcp_udp_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.tl_map_non_tcp_udp_cmd;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_map_non_tcp_udp_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tl_map_non_tcp_udp_cmd = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_pppoe_multicast_de_acce_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.pppoe_multicast_de_acce;
	return ret;
}

sw_error_t
appe_tl_ctrl_pppoe_multicast_de_acce_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.pppoe_multicast_de_acce = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_src_if_check_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.tl_src_if_check_cmd;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_src_if_check_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tl_src_if_check_cmd = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_hash_mode_1_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.tl_hash_mode_1;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_hash_mode_1_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tl_hash_mode_1 = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_map_udp_csum_zero_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.tl_map_udp_csum_zero_cmd;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_map_udp_csum_zero_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tl_map_udp_csum_zero_cmd = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_map_dst_check_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.tl_map_dst_check_cmd;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_map_dst_check_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tl_map_dst_check_cmd = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_udp_csum_zero_de_acce_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.udp_csum_zero_de_acce;
	return ret;
}

sw_error_t
appe_tl_ctrl_udp_csum_zero_de_acce_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udp_csum_zero_de_acce = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_map_src_check_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.tl_map_src_check_cmd;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_map_src_check_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tl_map_src_check_cmd = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_ipv4_df_set_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.ipv4_df_set;
	return ret;
}

sw_error_t
appe_tl_ctrl_ipv4_df_set_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ipv4_df_set = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_de_acce_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	*value = reg_val.bf.tl_de_acce_cmd;
	return ret;
}

sw_error_t
appe_tl_ctrl_tl_de_acce_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t value)
{
	union tl_ctrl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ctrl_get(dev_id, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.tl_de_acce_cmd = value;
	ret = appe_tl_ctrl_set(dev_id, &reg_val);
	return ret;
}

sw_error_t
appe_tl_ingress_cnt_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_ingress_cnt_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_ingress_cnt_get(dev_id, &reg_val);
	*value = reg_val.bf.cnt;
	return ret;
}

sw_error_t
appe_tl_egress_cnt_cnt_get(
		a_uint32_t dev_id,
		a_uint32_t *value)
{
	union tl_egress_cnt_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_egress_cnt_get(dev_id, &reg_val);
	*value = reg_val.bf.cnt;
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_ttl_exceed_de_acce_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ttl_exceed_de_acce;
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_ttl_exceed_de_acce_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ttl_exceed_de_acce = value;
	ret = appe_tl_l3_if_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_ipv6_decap_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ipv6_decap_en;
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_ipv6_decap_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ipv6_decap_en = value;
	ret = appe_tl_l3_if_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_ttl_exceed_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ttl_exceed_cmd;
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_ttl_exceed_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ttl_exceed_cmd = value;
	ret = appe_tl_l3_if_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_min_ipv6_mtu_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.min_ipv6_mtu;
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_min_ipv6_mtu_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.min_ipv6_mtu = value;
	ret = appe_tl_l3_if_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_dmac_check_dis_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.dmac_check_dis;
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_dmac_check_dis_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.dmac_check_dis = value;
	ret = appe_tl_l3_if_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_lpm_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.lpm_en;
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_lpm_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.lpm_en = value;
	ret = appe_tl_l3_if_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_ipv4_decap_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ipv4_decap_en;
	return ret;
}

sw_error_t
appe_tl_l3_if_tbl_ipv4_decap_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_l3_if_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_l3_if_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ipv4_decap_en = value;
	ret = appe_tl_l3_if_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_key_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.key_type;
	return ret;
}

sw_error_t
appe_tl_key_gen_key_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.key_type = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_ip_prot_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.ip_prot_inc;
	return ret;
}

sw_error_t
appe_tl_key_gen_ip_prot_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.ip_prot_inc = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_udf1_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf1_id;
	return ret;
}

sw_error_t
appe_tl_key_gen_udf1_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf1_id = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_udf0_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf0_inc;
	return ret;
}

sw_error_t
appe_tl_key_gen_udf0_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf0_inc = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_sport_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.sport_inc;
	return ret;
}

sw_error_t
appe_tl_key_gen_sport_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.sport_inc = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_vni_resv_mask_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.vni_resv_mask_1 << 20 | \
		reg_val.bf.vni_resv_mask_0;
	return ret;
}

sw_error_t
appe_tl_key_gen_vni_resv_mask_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.vni_resv_mask_1 = value >> 20;
	reg_val.bf.vni_resv_mask_0 = value & (((a_uint64_t)1<<20)-1);
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_udf1_mask_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf1_mask_1 << 4 | \
		reg_val.bf.udf1_mask_0;
	return ret;
}

sw_error_t
appe_tl_key_gen_udf1_mask_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf1_mask_1 = value >> 4;
	reg_val.bf.udf1_mask_0 = value & (((a_uint64_t)1<<4)-1);
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_sip_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.sip_inc;
	return ret;
}

sw_error_t
appe_tl_key_gen_sip_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.sip_inc = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_udf0_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf0_id;
	return ret;
}

sw_error_t
appe_tl_key_gen_udf0_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf0_id = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_dport_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.dport_inc;
	return ret;
}

sw_error_t
appe_tl_key_gen_dport_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.dport_inc = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_vni_resv_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.vni_resv_inc;
	return ret;
}

sw_error_t
appe_tl_key_gen_vni_resv_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.vni_resv_inc = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_udf0_mask_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf0_mask;
	return ret;
}

sw_error_t
appe_tl_key_gen_udf0_mask_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf0_mask = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_udf1_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.udf1_inc;
	return ret;
}

sw_error_t
appe_tl_key_gen_udf1_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.udf1_inc = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_key_gen_dip_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	*value = reg_val.bf.dip_inc;
	return ret;
}

sw_error_t
appe_tl_key_gen_dip_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_key_gen_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_key_gen_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf.dip_inc = value;
	ret = appe_tl_key_gen_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_protocol_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.protocol;
	return ret;
}

sw_error_t
appe_tl_tbl_protocol_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.protocol = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_key_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.key_type;
	return ret;
}

sw_error_t
appe_tl_tbl_key_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.key_type = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_exp_profile_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.exp_profile;
	return ret;
}

sw_error_t
appe_tl_tbl_exp_profile_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.exp_profile = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_cvlan_fmt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.cvlan_fmt;
	return ret;
}

sw_error_t
appe_tl_tbl_cvlan_fmt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.cvlan_fmt = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_tl_l3_if_check_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.tl_l3_if_check_en;
	return ret;
}

sw_error_t
appe_tl_tbl_tl_l3_if_check_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.tl_l3_if_check_en = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_cdei_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.cdei_mode;
	return ret;
}

sw_error_t
appe_tl_tbl_cdei_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.cdei_mode = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_svlan_check_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.svlan_check_en;
	return ret;
}

sw_error_t
appe_tl_tbl_svlan_check_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.svlan_check_en = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_dscp_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.dscp_mode;
	return ret;
}

sw_error_t
appe_tl_tbl_dscp_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.dscp_mode = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_udf0_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.udf0_valid;
	return ret;
}

sw_error_t
appe_tl_tbl_udf0_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.udf0_valid = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_l4_dport_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.l4_dport_1 << 2 | \
		reg_val.bf0.l4_dport_0;
	return ret;
}

sw_error_t
appe_tl_tbl_l4_dport_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.l4_dport_1 = value >> 2;
	reg_val.bf0.l4_dport_0 = value & (((a_uint64_t)1<<2)-1);
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.valid;
	return ret;
}

sw_error_t
appe_tl_tbl_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.valid = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_l4_sport_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.l4_sport;
	return ret;
}

sw_error_t
appe_tl_tbl_l4_sport_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.l4_sport = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_tl_l3_if_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.tl_l3_if;
	return ret;
}

sw_error_t
appe_tl_tbl_tl_l3_if_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.tl_l3_if = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_decap_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.decap_en;
	return ret;
}

sw_error_t
appe_tl_tbl_decap_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.decap_en = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_svlan_fmt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.svlan_fmt;
	return ret;
}

sw_error_t
appe_tl_tbl_svlan_fmt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.svlan_fmt = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_udf0_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.udf0;
	return ret;
}

sw_error_t
appe_tl_tbl_udf0_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.udf0 = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_de_acce_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.de_acce;
	return ret;
}

sw_error_t
appe_tl_tbl_de_acce_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.de_acce = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_vni_resv_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.vni_resv_valid;
	return ret;
}

sw_error_t
appe_tl_tbl_vni_resv_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.vni_resv_valid = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_sdei_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.sdei_mode;
	return ret;
}

sw_error_t
appe_tl_tbl_sdei_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.sdei_mode = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_ipv6_dst_addr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf0.ipv6_dst_addr_1 << 18 | \
		reg_val.bf0.ipv6_dst_addr_0;
	return ret;
}

sw_error_t
appe_tl_tbl_ipv6_dst_addr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.ipv6_dst_addr_1 = value >> 18;
	reg_val.bf0.ipv6_dst_addr_0 = value & (((a_uint64_t)1<<18)-1);
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_ecn_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.ecn_mode;
	return ret;
}

sw_error_t
appe_tl_tbl_ecn_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.ecn_mode = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_spcp_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.spcp_mode;
	return ret;
}

sw_error_t
appe_tl_tbl_spcp_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.spcp_mode = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_vni_resv_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.vni_resv_1 << 18 | \
		reg_val.bf0.vni_resv_0;
	return ret;
}

sw_error_t
appe_tl_tbl_vni_resv_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.vni_resv_1 = value >> 18;
	reg_val.bf0.vni_resv_0 = value & (((a_uint64_t)1<<18)-1);
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_udp_csum_zero_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.udp_csum_zero;
	return ret;
}

sw_error_t
appe_tl_tbl_udp_csum_zero_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.udp_csum_zero = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_src_info_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.src_info_type;
	return ret;
}

sw_error_t
appe_tl_tbl_src_info_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.src_info_type = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_src_info_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.src_info;
	return ret;
}

sw_error_t
appe_tl_tbl_src_info_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.src_info = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_udf1_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.udf1_1 << 2 | \
		reg_val.bf0.udf1_0;
	return ret;
}

sw_error_t
appe_tl_tbl_udf1_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.udf1_1 = value >> 2;
	reg_val.bf0.udf1_0 = value & (((a_uint64_t)1<<2)-1);
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_cpcp_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.cpcp_mode;
	return ret;
}

sw_error_t
appe_tl_tbl_cpcp_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.cpcp_mode = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_ipv4_src_addr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf1.ipv4_src_addr_1 << 18 | \
		reg_val.bf1.ipv4_src_addr_0;
	return ret;
}

sw_error_t
appe_tl_tbl_ipv4_src_addr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf1.ipv4_src_addr_1 = value >> 18;
	reg_val.bf1.ipv4_src_addr_0 = value & (((a_uint64_t)1<<18)-1);
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_ipv4_dst_addr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf1.ipv4_dst_addr_1 << 18 | \
		reg_val.bf1.ipv4_dst_addr_0;
	return ret;
}

sw_error_t
appe_tl_tbl_ipv4_dst_addr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf1.ipv4_dst_addr_1 = value >> 18;
	reg_val.bf1.ipv4_dst_addr_0 = value & (((a_uint64_t)1<<18)-1);
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_udf1_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.udf1_valid;
	return ret;
}

sw_error_t
appe_tl_tbl_udf1_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.udf1_valid = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_fwd_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.fwd_type;
	return ret;
}

sw_error_t
appe_tl_tbl_fwd_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.fwd_type = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_service_code_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.service_code_en;
	return ret;
}

sw_error_t
appe_tl_tbl_service_code_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.service_code_en = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_svlan_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.svlan_id_1 << 7 | \
		reg_val.bf0.svlan_id_0;
	return ret;
}

sw_error_t
appe_tl_tbl_svlan_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.svlan_id_1 = value >> 7;
	reg_val.bf0.svlan_id_0 = value & (((a_uint64_t)1<<7)-1);
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_cvlan_check_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.cvlan_check_en;
	return ret;
}

sw_error_t
appe_tl_tbl_cvlan_check_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.cvlan_check_en = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_service_code_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.service_code;
	return ret;
}

sw_error_t
appe_tl_tbl_service_code_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.service_code = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_src_info_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.src_info_valid;
	return ret;
}

sw_error_t
appe_tl_tbl_src_info_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.src_info_valid = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_entry_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.entry_type;
	return ret;
}

sw_error_t
appe_tl_tbl_entry_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.entry_type = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_cvlan_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.cvlan_id;
	return ret;
}

sw_error_t
appe_tl_tbl_cvlan_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.cvlan_id = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_ipv6_src_addr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = (a_uint64_t)reg_val.bf0.ipv6_src_addr_1 << 18 | \
		reg_val.bf0.ipv6_src_addr_0;
	return ret;
}

sw_error_t
appe_tl_tbl_ipv6_src_addr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.ipv6_src_addr_1 = value >> 18;
	reg_val.bf0.ipv6_src_addr_0 = value & (((a_uint64_t)1<<18)-1);
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}

sw_error_t
appe_tl_tbl_ttl_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	*value = reg_val.bf0.ttl_mode;
	return ret;
}

sw_error_t
appe_tl_tbl_ttl_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value)
{
	union tl_tbl_u reg_val;
	sw_error_t ret = SW_OK;

	ret = appe_tl_tbl_get(dev_id, index, &reg_val);
	if (SW_OK != ret)
		return ret;
	reg_val.bf0.ttl_mode = value;
	ret = appe_tl_tbl_set(dev_id, index, &reg_val);
	return ret;
}
