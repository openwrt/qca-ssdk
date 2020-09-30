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
#ifndef _APPE_TUNNEL_H_
#define _APPE_TUNNEL_H_

#define TL_L3_IF_TBL_MAX_ENTRY	128
#define TL_KEY_GEN_MAX_ENTRY	16
#define TL_TBL_MAX_ENTRY	128


sw_error_t
appe_tl_tbl_op_get(
		a_uint32_t dev_id,
		union tl_tbl_op_u *value);

sw_error_t
appe_tl_tbl_op_set(
		a_uint32_t dev_id,
		union tl_tbl_op_u *value);

sw_error_t
appe_tl_tbl_op_data0_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data0_u *value);

sw_error_t
appe_tl_tbl_op_data0_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data0_u *value);

sw_error_t
appe_tl_tbl_op_data1_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data1_u *value);

sw_error_t
appe_tl_tbl_op_data1_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data1_u *value);

sw_error_t
appe_tl_tbl_op_data2_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data2_u *value);

sw_error_t
appe_tl_tbl_op_data2_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data2_u *value);

sw_error_t
appe_tl_tbl_op_data3_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data3_u *value);

sw_error_t
appe_tl_tbl_op_data3_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data3_u *value);

sw_error_t
appe_tl_tbl_op_data4_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data4_u *value);

sw_error_t
appe_tl_tbl_op_data4_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data4_u *value);

sw_error_t
appe_tl_tbl_op_data5_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data5_u *value);

sw_error_t
appe_tl_tbl_op_data5_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data5_u *value);

sw_error_t
appe_tl_tbl_op_data6_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data6_u *value);

sw_error_t
appe_tl_tbl_op_data6_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data6_u *value);

sw_error_t
appe_tl_tbl_op_data7_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data7_u *value);

sw_error_t
appe_tl_tbl_op_data7_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data7_u *value);

sw_error_t
appe_tl_tbl_op_data8_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data8_u *value);

sw_error_t
appe_tl_tbl_op_data8_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data8_u *value);

sw_error_t
appe_tl_tbl_op_data9_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data9_u *value);

sw_error_t
appe_tl_tbl_op_data9_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data9_u *value);

sw_error_t
appe_tl_tbl_op_data10_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data10_u *value);

sw_error_t
appe_tl_tbl_op_data10_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data10_u *value);

sw_error_t
appe_tl_tbl_op_data11_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data11_u *value);

sw_error_t
appe_tl_tbl_op_data11_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data11_u *value);

sw_error_t
appe_tl_tbl_op_data12_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data12_u *value);

sw_error_t
appe_tl_tbl_op_data12_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data12_u *value);

sw_error_t
appe_tl_tbl_op_data13_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data13_u *value);

sw_error_t
appe_tl_tbl_op_data13_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data13_u *value);

sw_error_t
appe_tl_tbl_op_data14_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data14_u *value);

sw_error_t
appe_tl_tbl_op_data14_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data14_u *value);

sw_error_t
appe_tl_tbl_op_data15_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data15_u *value);

sw_error_t
appe_tl_tbl_op_data15_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data15_u *value);

sw_error_t
appe_tl_tbl_op_data16_get(
		a_uint32_t dev_id,
		union tl_tbl_op_data16_u *value);

sw_error_t
appe_tl_tbl_op_data16_set(
		a_uint32_t dev_id,
		union tl_tbl_op_data16_u *value);

sw_error_t
appe_tl_tbl_rd_op_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_u *value);

sw_error_t
appe_tl_tbl_rd_op_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_u *value);

sw_error_t
appe_tl_tbl_rd_op_data0_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data0_u *value);

sw_error_t
appe_tl_tbl_rd_op_data0_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data0_u *value);

sw_error_t
appe_tl_tbl_rd_op_data1_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data1_u *value);

sw_error_t
appe_tl_tbl_rd_op_data1_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data1_u *value);

sw_error_t
appe_tl_tbl_rd_op_data2_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data2_u *value);

sw_error_t
appe_tl_tbl_rd_op_data2_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data2_u *value);

sw_error_t
appe_tl_tbl_rd_op_data3_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data3_u *value);

sw_error_t
appe_tl_tbl_rd_op_data3_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data3_u *value);

sw_error_t
appe_tl_tbl_rd_op_data4_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data4_u *value);

sw_error_t
appe_tl_tbl_rd_op_data4_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data4_u *value);

sw_error_t
appe_tl_tbl_rd_op_data5_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data5_u *value);

sw_error_t
appe_tl_tbl_rd_op_data5_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data5_u *value);

sw_error_t
appe_tl_tbl_rd_op_data6_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data6_u *value);

sw_error_t
appe_tl_tbl_rd_op_data6_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data6_u *value);

sw_error_t
appe_tl_tbl_rd_op_data7_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data7_u *value);

sw_error_t
appe_tl_tbl_rd_op_data7_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data7_u *value);

sw_error_t
appe_tl_tbl_rd_op_data8_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data8_u *value);

sw_error_t
appe_tl_tbl_rd_op_data8_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data8_u *value);

sw_error_t
appe_tl_tbl_rd_op_data9_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data9_u *value);

sw_error_t
appe_tl_tbl_rd_op_data9_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data9_u *value);

sw_error_t
appe_tl_tbl_rd_op_data10_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data10_u *value);

sw_error_t
appe_tl_tbl_rd_op_data10_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data10_u *value);

sw_error_t
appe_tl_tbl_rd_op_data11_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data11_u *value);

sw_error_t
appe_tl_tbl_rd_op_data11_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data11_u *value);

sw_error_t
appe_tl_tbl_rd_op_data12_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data12_u *value);

sw_error_t
appe_tl_tbl_rd_op_data12_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data12_u *value);

sw_error_t
appe_tl_tbl_rd_op_data13_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data13_u *value);

sw_error_t
appe_tl_tbl_rd_op_data13_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data13_u *value);

sw_error_t
appe_tl_tbl_rd_op_data14_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data14_u *value);

sw_error_t
appe_tl_tbl_rd_op_data14_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data14_u *value);

sw_error_t
appe_tl_tbl_rd_op_data15_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data15_u *value);

sw_error_t
appe_tl_tbl_rd_op_data15_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data15_u *value);

sw_error_t
appe_tl_tbl_rd_op_data16_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data16_u *value);

sw_error_t
appe_tl_tbl_rd_op_data16_set(
		a_uint32_t dev_id,
		union tl_tbl_rd_op_data16_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data0_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data0_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data1_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data1_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data2_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data2_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data3_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data3_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data4_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data4_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data5_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data5_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data6_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data6_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data7_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data7_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data8_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data8_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data9_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data9_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data10_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data10_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data11_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data11_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data12_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data12_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data13_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data13_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data14_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data14_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data15_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data15_u *value);

sw_error_t
appe_tl_tbl_rd_rslt_data16_get(
		a_uint32_t dev_id,
		union tl_tbl_rd_rslt_data16_u *value);

sw_error_t
appe_tl_ctrl_get(
		a_uint32_t dev_id,
		union tl_ctrl_u *value);

sw_error_t
appe_tl_ctrl_set(
		a_uint32_t dev_id,
		union tl_ctrl_u *value);

sw_error_t
appe_tl_ingress_cnt_get(
		a_uint32_t dev_id,
		union tl_ingress_cnt_u *value);

sw_error_t
appe_tl_egress_cnt_get(
		a_uint32_t dev_id,
		union tl_egress_cnt_u *value);

sw_error_t
appe_tl_l3_if_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_l3_if_tbl_u *value);

sw_error_t
appe_tl_l3_if_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_l3_if_tbl_u *value);

sw_error_t
appe_tl_key_gen_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_key_gen_u *value);

sw_error_t
appe_tl_key_gen_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_key_gen_u *value);

sw_error_t
appe_tl_tbl_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_tbl_u *value);

sw_error_t
appe_tl_tbl_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		union tl_tbl_u *value);

sw_error_t
appe_tl_tbl_op_op_mode_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_op_mode_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_op_type_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_op_type_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_op_rslt_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_op_rslt_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_busy_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_busy_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_entry_index_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_entry_index_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_hash_block_bitmap_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_hash_block_bitmap_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data0_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data0_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data1_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data1_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data2_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data2_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data3_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data3_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data4_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data4_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data5_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data5_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data6_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data6_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data7_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data7_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data8_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data8_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data9_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data9_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data10_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data10_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data11_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data11_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data12_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data12_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data13_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data13_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data14_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data14_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data15_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data15_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_op_data16_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_op_data16_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_op_mode_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_op_mode_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_op_type_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_op_type_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_op_rslt_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_op_rslt_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_busy_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_busy_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_entry_index_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_entry_index_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_hash_block_bitmap_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_hash_block_bitmap_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data0_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data0_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data1_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data1_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data2_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data2_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data3_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data3_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data4_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data4_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data5_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data5_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data6_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data6_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data7_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data7_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data8_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data8_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data9_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data9_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data10_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data10_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data11_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data11_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data12_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data12_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data13_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data13_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data14_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data14_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data15_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data15_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_op_data16_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_op_data16_data_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_tbl_rd_rslt_data0_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data1_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data2_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data3_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data4_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data5_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data6_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data7_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data8_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data9_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data10_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data11_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data12_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data13_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data14_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data15_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_tbl_rd_rslt_data16_data_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_hash_mode_0_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_hash_mode_0_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_pppoe_multicast_cmd_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_pppoe_multicast_cmd_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_tl_vlan_check_de_acce_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_vlan_check_de_acce_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_udp_csum_zero_cmd_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_udp_csum_zero_cmd_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_tl_vlan_check_cmd_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_vlan_check_cmd_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_tl_src_if_check_de_acce_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_src_if_check_de_acce_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_tl_map_non_tcp_udp_cmd_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_map_non_tcp_udp_cmd_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_pppoe_multicast_de_acce_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_pppoe_multicast_de_acce_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_tl_src_if_check_cmd_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_src_if_check_cmd_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_tl_hash_mode_1_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_hash_mode_1_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_tl_map_udp_csum_zero_cmd_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_map_udp_csum_zero_cmd_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_tl_map_dst_check_cmd_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_map_dst_check_cmd_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_udp_csum_zero_de_acce_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_udp_csum_zero_de_acce_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_tl_map_src_check_cmd_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_map_src_check_cmd_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_ipv4_df_set_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_ipv4_df_set_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ctrl_tl_de_acce_cmd_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_ctrl_tl_de_acce_cmd_set(
		a_uint32_t dev_id,
		unsigned int value);

sw_error_t
appe_tl_ingress_cnt_cnt_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_egress_cnt_cnt_get(
		a_uint32_t dev_id,
		unsigned int *value);

sw_error_t
appe_tl_l3_if_tbl_ttl_exceed_de_acce_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_l3_if_tbl_ttl_exceed_de_acce_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_l3_if_tbl_ipv6_decap_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_l3_if_tbl_ipv6_decap_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_l3_if_tbl_ttl_exceed_cmd_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_l3_if_tbl_ttl_exceed_cmd_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_l3_if_tbl_min_ipv6_mtu_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_l3_if_tbl_min_ipv6_mtu_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_l3_if_tbl_dmac_check_dis_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_l3_if_tbl_dmac_check_dis_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_l3_if_tbl_lpm_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_l3_if_tbl_lpm_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_l3_if_tbl_ipv4_decap_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_l3_if_tbl_ipv4_decap_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_key_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_key_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_ip_prot_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_ip_prot_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_udf1_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_udf1_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_udf0_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_udf0_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_sport_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_sport_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_vni_resv_mask_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_vni_resv_mask_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_udf1_mask_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_udf1_mask_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_sip_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_sip_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_udf0_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_udf0_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_dport_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_dport_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_vni_resv_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_vni_resv_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_udf0_mask_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_udf0_mask_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_udf1_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_udf1_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_key_gen_dip_inc_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_key_gen_dip_inc_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_protocol_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_protocol_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_key_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_key_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_exp_profile_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_exp_profile_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_cvlan_fmt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_cvlan_fmt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_tl_l3_if_check_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_tl_l3_if_check_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_cdei_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_cdei_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_svlan_check_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_svlan_check_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_dscp_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_dscp_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_udf0_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_udf0_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_l4_dport_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_l4_dport_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_l4_sport_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_l4_sport_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_tl_l3_if_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_tl_l3_if_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_decap_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_decap_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_svlan_fmt_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_svlan_fmt_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_udf0_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_udf0_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_de_acce_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_de_acce_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_vni_resv_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_vni_resv_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_sdei_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_sdei_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_ipv6_dst_addr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value);

sw_error_t
appe_tl_tbl_ipv6_dst_addr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value);

sw_error_t
appe_tl_tbl_ecn_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_ecn_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_spcp_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_spcp_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_vni_resv_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_vni_resv_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_udp_csum_zero_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_udp_csum_zero_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_src_info_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_src_info_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_src_info_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_src_info_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_udf1_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_udf1_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_cpcp_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_cpcp_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_ipv4_src_addr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_ipv4_src_addr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_ipv4_dst_addr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_ipv4_dst_addr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_udf1_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_udf1_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_fwd_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_fwd_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_service_code_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_service_code_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_svlan_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_svlan_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_cvlan_check_en_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_cvlan_check_en_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_service_code_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_service_code_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_src_info_valid_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_src_info_valid_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_entry_type_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_entry_type_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_cvlan_id_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_cvlan_id_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

sw_error_t
appe_tl_tbl_ipv6_src_addr_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t *value);

sw_error_t
appe_tl_tbl_ipv6_src_addr_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint64_t value);

sw_error_t
appe_tl_tbl_ttl_mode_get(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t *value);

sw_error_t
appe_tl_tbl_ttl_mode_set(
		a_uint32_t dev_id,
		a_uint32_t index,
		a_uint32_t value);

#endif

