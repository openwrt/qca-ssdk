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
#ifndef APPE_TUNNEL_REG_H
#define APPE_TUNNEL_REG_H

/*[register] TL_TBL_OP*/
#define TL_TBL_OP
#define TL_TBL_OP_ADDRESS 0x0
#define TL_TBL_OP_NUM     1
#define TL_TBL_OP_INC     0x4
#define TL_TBL_OP_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DEFAULT 0x0
	/*[field] OP_TYPE*/
	#define TL_TBL_OP_OP_TYPE
	#define TL_TBL_OP_OP_TYPE_OFFSET  0
	#define TL_TBL_OP_OP_TYPE_LEN     3
	#define TL_TBL_OP_OP_TYPE_DEFAULT 0x0
	/*[field] HASH_BLOCK_BITMAP*/
	#define TL_TBL_OP_HASH_BLOCK_BITMAP
	#define TL_TBL_OP_HASH_BLOCK_BITMAP_OFFSET  3
	#define TL_TBL_OP_HASH_BLOCK_BITMAP_LEN     2
	#define TL_TBL_OP_HASH_BLOCK_BITMAP_DEFAULT 0x0
	/*[field] OP_MODE*/
	#define TL_TBL_OP_OP_MODE
	#define TL_TBL_OP_OP_MODE_OFFSET  5
	#define TL_TBL_OP_OP_MODE_LEN     1
	#define TL_TBL_OP_OP_MODE_DEFAULT 0x0
	/*[field] ENTRY_INDEX*/
	#define TL_TBL_OP_ENTRY_INDEX
	#define TL_TBL_OP_ENTRY_INDEX_OFFSET  6
	#define TL_TBL_OP_ENTRY_INDEX_LEN     7
	#define TL_TBL_OP_ENTRY_INDEX_DEFAULT 0x0
	/*[field] OP_RSLT*/
	#define TL_TBL_OP_OP_RSLT
	#define TL_TBL_OP_OP_RSLT_OFFSET  13
	#define TL_TBL_OP_OP_RSLT_LEN     1
	#define TL_TBL_OP_OP_RSLT_DEFAULT 0x0
	/*[field] BUSY*/
	#define TL_TBL_OP_BUSY
	#define TL_TBL_OP_BUSY_OFFSET  14
	#define TL_TBL_OP_BUSY_LEN     1
	#define TL_TBL_OP_BUSY_DEFAULT 0x0

struct tl_tbl_op {
	a_uint32_t  op_type:3;
	a_uint32_t  hash_block_bitmap:2;
	a_uint32_t  op_mode:1;
	a_uint32_t  entry_index:7;
	a_uint32_t  op_rslt:1;
	a_uint32_t  busy:1;
	a_uint32_t  _reserved0:17;
};

union tl_tbl_op_u {
	a_uint32_t val;
	struct tl_tbl_op bf;
};

/*[register] TL_TBL_OP_DATA0*/
#define TL_TBL_OP_DATA0
#define TL_TBL_OP_DATA0_ADDRESS 0x4
#define TL_TBL_OP_DATA0_NUM     1
#define TL_TBL_OP_DATA0_INC     0x4
#define TL_TBL_OP_DATA0_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA0_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA0_DATA
	#define TL_TBL_OP_DATA0_DATA_OFFSET  0
	#define TL_TBL_OP_DATA0_DATA_LEN     32
	#define TL_TBL_OP_DATA0_DATA_DEFAULT 0x0

struct tl_tbl_op_data0 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data0_u {
	a_uint32_t val;
	struct tl_tbl_op_data0 bf;
};

/*[register] TL_TBL_OP_DATA1*/
#define TL_TBL_OP_DATA1
#define TL_TBL_OP_DATA1_ADDRESS 0x8
#define TL_TBL_OP_DATA1_NUM     1
#define TL_TBL_OP_DATA1_INC     0x4
#define TL_TBL_OP_DATA1_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA1_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA1_DATA
	#define TL_TBL_OP_DATA1_DATA_OFFSET  0
	#define TL_TBL_OP_DATA1_DATA_LEN     32
	#define TL_TBL_OP_DATA1_DATA_DEFAULT 0x0

struct tl_tbl_op_data1 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data1_u {
	a_uint32_t val;
	struct tl_tbl_op_data1 bf;
};

/*[register] TL_TBL_OP_DATA2*/
#define TL_TBL_OP_DATA2
#define TL_TBL_OP_DATA2_ADDRESS 0xc
#define TL_TBL_OP_DATA2_NUM     1
#define TL_TBL_OP_DATA2_INC     0x4
#define TL_TBL_OP_DATA2_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA2_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA2_DATA
	#define TL_TBL_OP_DATA2_DATA_OFFSET  0
	#define TL_TBL_OP_DATA2_DATA_LEN     32
	#define TL_TBL_OP_DATA2_DATA_DEFAULT 0x0

struct tl_tbl_op_data2 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data2_u {
	a_uint32_t val;
	struct tl_tbl_op_data2 bf;
};

/*[register] TL_TBL_OP_DATA3*/
#define TL_TBL_OP_DATA3
#define TL_TBL_OP_DATA3_ADDRESS 0x10
#define TL_TBL_OP_DATA3_NUM     1
#define TL_TBL_OP_DATA3_INC     0x4
#define TL_TBL_OP_DATA3_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA3_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA3_DATA
	#define TL_TBL_OP_DATA3_DATA_OFFSET  0
	#define TL_TBL_OP_DATA3_DATA_LEN     32
	#define TL_TBL_OP_DATA3_DATA_DEFAULT 0x0

struct tl_tbl_op_data3 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data3_u {
	a_uint32_t val;
	struct tl_tbl_op_data3 bf;
};

/*[register] TL_TBL_OP_DATA4*/
#define TL_TBL_OP_DATA4
#define TL_TBL_OP_DATA4_ADDRESS 0x14
#define TL_TBL_OP_DATA4_NUM     1
#define TL_TBL_OP_DATA4_INC     0x4
#define TL_TBL_OP_DATA4_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA4_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA4_DATA
	#define TL_TBL_OP_DATA4_DATA_OFFSET  0
	#define TL_TBL_OP_DATA4_DATA_LEN     32
	#define TL_TBL_OP_DATA4_DATA_DEFAULT 0x0

struct tl_tbl_op_data4 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data4_u {
	a_uint32_t val;
	struct tl_tbl_op_data4 bf;
};

/*[register] TL_TBL_OP_DATA5*/
#define TL_TBL_OP_DATA5
#define TL_TBL_OP_DATA5_ADDRESS 0x18
#define TL_TBL_OP_DATA5_NUM     1
#define TL_TBL_OP_DATA5_INC     0x4
#define TL_TBL_OP_DATA5_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA5_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA5_DATA
	#define TL_TBL_OP_DATA5_DATA_OFFSET  0
	#define TL_TBL_OP_DATA5_DATA_LEN     32
	#define TL_TBL_OP_DATA5_DATA_DEFAULT 0x0

struct tl_tbl_op_data5 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data5_u {
	a_uint32_t val;
	struct tl_tbl_op_data5 bf;
};

/*[register] TL_TBL_OP_DATA6*/
#define TL_TBL_OP_DATA6
#define TL_TBL_OP_DATA6_ADDRESS 0x1c
#define TL_TBL_OP_DATA6_NUM     1
#define TL_TBL_OP_DATA6_INC     0x4
#define TL_TBL_OP_DATA6_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA6_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA6_DATA
	#define TL_TBL_OP_DATA6_DATA_OFFSET  0
	#define TL_TBL_OP_DATA6_DATA_LEN     32
	#define TL_TBL_OP_DATA6_DATA_DEFAULT 0x0

struct tl_tbl_op_data6 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data6_u {
	a_uint32_t val;
	struct tl_tbl_op_data6 bf;
};

/*[register] TL_TBL_OP_DATA7*/
#define TL_TBL_OP_DATA7
#define TL_TBL_OP_DATA7_ADDRESS 0x20
#define TL_TBL_OP_DATA7_NUM     1
#define TL_TBL_OP_DATA7_INC     0x4
#define TL_TBL_OP_DATA7_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA7_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA7_DATA
	#define TL_TBL_OP_DATA7_DATA_OFFSET  0
	#define TL_TBL_OP_DATA7_DATA_LEN     32
	#define TL_TBL_OP_DATA7_DATA_DEFAULT 0x0

struct tl_tbl_op_data7 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data7_u {
	a_uint32_t val;
	struct tl_tbl_op_data7 bf;
};

/*[register] TL_TBL_OP_DATA8*/
#define TL_TBL_OP_DATA8
#define TL_TBL_OP_DATA8_ADDRESS 0x24
#define TL_TBL_OP_DATA8_NUM     1
#define TL_TBL_OP_DATA8_INC     0x4
#define TL_TBL_OP_DATA8_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA8_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA8_DATA
	#define TL_TBL_OP_DATA8_DATA_OFFSET  0
	#define TL_TBL_OP_DATA8_DATA_LEN     32
	#define TL_TBL_OP_DATA8_DATA_DEFAULT 0x0

struct tl_tbl_op_data8 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data8_u {
	a_uint32_t val;
	struct tl_tbl_op_data8 bf;
};

/*[register] TL_TBL_OP_DATA9*/
#define TL_TBL_OP_DATA9
#define TL_TBL_OP_DATA9_ADDRESS 0x28
#define TL_TBL_OP_DATA9_NUM     1
#define TL_TBL_OP_DATA9_INC     0x4
#define TL_TBL_OP_DATA9_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA9_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA9_DATA
	#define TL_TBL_OP_DATA9_DATA_OFFSET  0
	#define TL_TBL_OP_DATA9_DATA_LEN     32
	#define TL_TBL_OP_DATA9_DATA_DEFAULT 0x0

struct tl_tbl_op_data9 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data9_u {
	a_uint32_t val;
	struct tl_tbl_op_data9 bf;
};

/*[register] TL_TBL_OP_DATA10*/
#define TL_TBL_OP_DATA10
#define TL_TBL_OP_DATA10_ADDRESS 0x2c
#define TL_TBL_OP_DATA10_NUM     1
#define TL_TBL_OP_DATA10_INC     0x4
#define TL_TBL_OP_DATA10_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA10_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA10_DATA
	#define TL_TBL_OP_DATA10_DATA_OFFSET  0
	#define TL_TBL_OP_DATA10_DATA_LEN     32
	#define TL_TBL_OP_DATA10_DATA_DEFAULT 0x0

struct tl_tbl_op_data10 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data10_u {
	a_uint32_t val;
	struct tl_tbl_op_data10 bf;
};

/*[register] TL_TBL_OP_DATA11*/
#define TL_TBL_OP_DATA11
#define TL_TBL_OP_DATA11_ADDRESS 0x30
#define TL_TBL_OP_DATA11_NUM     1
#define TL_TBL_OP_DATA11_INC     0x4
#define TL_TBL_OP_DATA11_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA11_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA11_DATA
	#define TL_TBL_OP_DATA11_DATA_OFFSET  0
	#define TL_TBL_OP_DATA11_DATA_LEN     32
	#define TL_TBL_OP_DATA11_DATA_DEFAULT 0x0

struct tl_tbl_op_data11 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data11_u {
	a_uint32_t val;
	struct tl_tbl_op_data11 bf;
};

/*[register] TL_TBL_OP_DATA12*/
#define TL_TBL_OP_DATA12
#define TL_TBL_OP_DATA12_ADDRESS 0x34
#define TL_TBL_OP_DATA12_NUM     1
#define TL_TBL_OP_DATA12_INC     0x4
#define TL_TBL_OP_DATA12_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA12_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA12_DATA
	#define TL_TBL_OP_DATA12_DATA_OFFSET  0
	#define TL_TBL_OP_DATA12_DATA_LEN     32
	#define TL_TBL_OP_DATA12_DATA_DEFAULT 0x0

struct tl_tbl_op_data12 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data12_u {
	a_uint32_t val;
	struct tl_tbl_op_data12 bf;
};

/*[register] TL_TBL_OP_DATA13*/
#define TL_TBL_OP_DATA13
#define TL_TBL_OP_DATA13_ADDRESS 0x38
#define TL_TBL_OP_DATA13_NUM     1
#define TL_TBL_OP_DATA13_INC     0x4
#define TL_TBL_OP_DATA13_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA13_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA13_DATA
	#define TL_TBL_OP_DATA13_DATA_OFFSET  0
	#define TL_TBL_OP_DATA13_DATA_LEN     32
	#define TL_TBL_OP_DATA13_DATA_DEFAULT 0x0

struct tl_tbl_op_data13 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data13_u {
	a_uint32_t val;
	struct tl_tbl_op_data13 bf;
};

/*[register] TL_TBL_OP_DATA14*/
#define TL_TBL_OP_DATA14
#define TL_TBL_OP_DATA14_ADDRESS 0x3c
#define TL_TBL_OP_DATA14_NUM     1
#define TL_TBL_OP_DATA14_INC     0x4
#define TL_TBL_OP_DATA14_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA14_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA14_DATA
	#define TL_TBL_OP_DATA14_DATA_OFFSET  0
	#define TL_TBL_OP_DATA14_DATA_LEN     32
	#define TL_TBL_OP_DATA14_DATA_DEFAULT 0x0

struct tl_tbl_op_data14 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data14_u {
	a_uint32_t val;
	struct tl_tbl_op_data14 bf;
};

/*[register] TL_TBL_OP_DATA15*/
#define TL_TBL_OP_DATA15
#define TL_TBL_OP_DATA15_ADDRESS 0x40
#define TL_TBL_OP_DATA15_NUM     1
#define TL_TBL_OP_DATA15_INC     0x4
#define TL_TBL_OP_DATA15_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA15_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA15_DATA
	#define TL_TBL_OP_DATA15_DATA_OFFSET  0
	#define TL_TBL_OP_DATA15_DATA_LEN     32
	#define TL_TBL_OP_DATA15_DATA_DEFAULT 0x0

struct tl_tbl_op_data15 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data15_u {
	a_uint32_t val;
	struct tl_tbl_op_data15 bf;
};

/*[register] TL_TBL_OP_DATA16*/
#define TL_TBL_OP_DATA16
#define TL_TBL_OP_DATA16_ADDRESS 0x44
#define TL_TBL_OP_DATA16_NUM     1
#define TL_TBL_OP_DATA16_INC     0x4
#define TL_TBL_OP_DATA16_TYPE    REG_TYPE_RW
#define TL_TBL_OP_DATA16_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_OP_DATA16_DATA
	#define TL_TBL_OP_DATA16_DATA_OFFSET  0
	#define TL_TBL_OP_DATA16_DATA_LEN     32
	#define TL_TBL_OP_DATA16_DATA_DEFAULT 0x0

struct tl_tbl_op_data16 {
	a_uint32_t  data:32;
};

union tl_tbl_op_data16_u {
	a_uint32_t val;
	struct tl_tbl_op_data16 bf;
};

/*[register] TL_TBL_RD_OP*/
#define TL_TBL_RD_OP
#define TL_TBL_RD_OP_ADDRESS 0x54
#define TL_TBL_RD_OP_NUM     1
#define TL_TBL_RD_OP_INC     0x4
#define TL_TBL_RD_OP_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DEFAULT 0x0
	/*[field] OP_TYPE*/
	#define TL_TBL_RD_OP_OP_TYPE
	#define TL_TBL_RD_OP_OP_TYPE_OFFSET  0
	#define TL_TBL_RD_OP_OP_TYPE_LEN     3
	#define TL_TBL_RD_OP_OP_TYPE_DEFAULT 0x0
	/*[field] HASH_BLOCK_BITMAP*/
	#define TL_TBL_RD_OP_HASH_BLOCK_BITMAP
	#define TL_TBL_RD_OP_HASH_BLOCK_BITMAP_OFFSET  3
	#define TL_TBL_RD_OP_HASH_BLOCK_BITMAP_LEN     2
	#define TL_TBL_RD_OP_HASH_BLOCK_BITMAP_DEFAULT 0x0
	/*[field] OP_MODE*/
	#define TL_TBL_RD_OP_OP_MODE
	#define TL_TBL_RD_OP_OP_MODE_OFFSET  5
	#define TL_TBL_RD_OP_OP_MODE_LEN     1
	#define TL_TBL_RD_OP_OP_MODE_DEFAULT 0x0
	/*[field] ENTRY_INDEX*/
	#define TL_TBL_RD_OP_ENTRY_INDEX
	#define TL_TBL_RD_OP_ENTRY_INDEX_OFFSET  6
	#define TL_TBL_RD_OP_ENTRY_INDEX_LEN     7
	#define TL_TBL_RD_OP_ENTRY_INDEX_DEFAULT 0x0
	/*[field] OP_RSLT*/
	#define TL_TBL_RD_OP_OP_RSLT
	#define TL_TBL_RD_OP_OP_RSLT_OFFSET  13
	#define TL_TBL_RD_OP_OP_RSLT_LEN     1
	#define TL_TBL_RD_OP_OP_RSLT_DEFAULT 0x0
	/*[field] BUSY*/
	#define TL_TBL_RD_OP_BUSY
	#define TL_TBL_RD_OP_BUSY_OFFSET  14
	#define TL_TBL_RD_OP_BUSY_LEN     1
	#define TL_TBL_RD_OP_BUSY_DEFAULT 0x0

struct tl_tbl_rd_op {
	a_uint32_t  op_type:3;
	a_uint32_t  hash_block_bitmap:2;
	a_uint32_t  op_mode:1;
	a_uint32_t  entry_index:7;
	a_uint32_t  op_rslt:1;
	a_uint32_t  busy:1;
	a_uint32_t  _reserved0:17;
};

union tl_tbl_rd_op_u {
	a_uint32_t val;
	struct tl_tbl_rd_op bf;
};

/*[register] TL_TBL_RD_OP_DATA0*/
#define TL_TBL_RD_OP_DATA0
#define TL_TBL_RD_OP_DATA0_ADDRESS 0x58
#define TL_TBL_RD_OP_DATA0_NUM     1
#define TL_TBL_RD_OP_DATA0_INC     0x4
#define TL_TBL_RD_OP_DATA0_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA0_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA0_DATA
	#define TL_TBL_RD_OP_DATA0_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA0_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA0_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data0 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data0_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data0 bf;
};

/*[register] TL_TBL_RD_OP_DATA1*/
#define TL_TBL_RD_OP_DATA1
#define TL_TBL_RD_OP_DATA1_ADDRESS 0x5c
#define TL_TBL_RD_OP_DATA1_NUM     1
#define TL_TBL_RD_OP_DATA1_INC     0x4
#define TL_TBL_RD_OP_DATA1_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA1_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA1_DATA
	#define TL_TBL_RD_OP_DATA1_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA1_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA1_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data1 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data1_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data1 bf;
};

/*[register] TL_TBL_RD_OP_DATA2*/
#define TL_TBL_RD_OP_DATA2
#define TL_TBL_RD_OP_DATA2_ADDRESS 0x60
#define TL_TBL_RD_OP_DATA2_NUM     1
#define TL_TBL_RD_OP_DATA2_INC     0x4
#define TL_TBL_RD_OP_DATA2_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA2_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA2_DATA
	#define TL_TBL_RD_OP_DATA2_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA2_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA2_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data2 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data2_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data2 bf;
};

/*[register] TL_TBL_RD_OP_DATA3*/
#define TL_TBL_RD_OP_DATA3
#define TL_TBL_RD_OP_DATA3_ADDRESS 0x64
#define TL_TBL_RD_OP_DATA3_NUM     1
#define TL_TBL_RD_OP_DATA3_INC     0x4
#define TL_TBL_RD_OP_DATA3_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA3_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA3_DATA
	#define TL_TBL_RD_OP_DATA3_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA3_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA3_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data3 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data3_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data3 bf;
};

/*[register] TL_TBL_RD_OP_DATA4*/
#define TL_TBL_RD_OP_DATA4
#define TL_TBL_RD_OP_DATA4_ADDRESS 0x68
#define TL_TBL_RD_OP_DATA4_NUM     1
#define TL_TBL_RD_OP_DATA4_INC     0x4
#define TL_TBL_RD_OP_DATA4_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA4_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA4_DATA
	#define TL_TBL_RD_OP_DATA4_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA4_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA4_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data4 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data4_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data4 bf;
};

/*[register] TL_TBL_RD_OP_DATA5*/
#define TL_TBL_RD_OP_DATA5
#define TL_TBL_RD_OP_DATA5_ADDRESS 0x6c
#define TL_TBL_RD_OP_DATA5_NUM     1
#define TL_TBL_RD_OP_DATA5_INC     0x4
#define TL_TBL_RD_OP_DATA5_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA5_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA5_DATA
	#define TL_TBL_RD_OP_DATA5_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA5_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA5_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data5 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data5_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data5 bf;
};

/*[register] TL_TBL_RD_OP_DATA6*/
#define TL_TBL_RD_OP_DATA6
#define TL_TBL_RD_OP_DATA6_ADDRESS 0x70
#define TL_TBL_RD_OP_DATA6_NUM     1
#define TL_TBL_RD_OP_DATA6_INC     0x4
#define TL_TBL_RD_OP_DATA6_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA6_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA6_DATA
	#define TL_TBL_RD_OP_DATA6_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA6_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA6_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data6 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data6_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data6 bf;
};

/*[register] TL_TBL_RD_OP_DATA7*/
#define TL_TBL_RD_OP_DATA7
#define TL_TBL_RD_OP_DATA7_ADDRESS 0x74
#define TL_TBL_RD_OP_DATA7_NUM     1
#define TL_TBL_RD_OP_DATA7_INC     0x4
#define TL_TBL_RD_OP_DATA7_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA7_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA7_DATA
	#define TL_TBL_RD_OP_DATA7_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA7_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA7_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data7 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data7_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data7 bf;
};

/*[register] TL_TBL_RD_OP_DATA8*/
#define TL_TBL_RD_OP_DATA8
#define TL_TBL_RD_OP_DATA8_ADDRESS 0x78
#define TL_TBL_RD_OP_DATA8_NUM     1
#define TL_TBL_RD_OP_DATA8_INC     0x4
#define TL_TBL_RD_OP_DATA8_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA8_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA8_DATA
	#define TL_TBL_RD_OP_DATA8_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA8_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA8_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data8 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data8_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data8 bf;
};

/*[register] TL_TBL_RD_OP_DATA9*/
#define TL_TBL_RD_OP_DATA9
#define TL_TBL_RD_OP_DATA9_ADDRESS 0x7c
#define TL_TBL_RD_OP_DATA9_NUM     1
#define TL_TBL_RD_OP_DATA9_INC     0x4
#define TL_TBL_RD_OP_DATA9_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA9_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA9_DATA
	#define TL_TBL_RD_OP_DATA9_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA9_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA9_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data9 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data9_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data9 bf;
};

/*[register] TL_TBL_RD_OP_DATA10*/
#define TL_TBL_RD_OP_DATA10
#define TL_TBL_RD_OP_DATA10_ADDRESS 0x80
#define TL_TBL_RD_OP_DATA10_NUM     1
#define TL_TBL_RD_OP_DATA10_INC     0x4
#define TL_TBL_RD_OP_DATA10_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA10_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA10_DATA
	#define TL_TBL_RD_OP_DATA10_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA10_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA10_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data10 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data10_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data10 bf;
};

/*[register] TL_TBL_RD_OP_DATA11*/
#define TL_TBL_RD_OP_DATA11
#define TL_TBL_RD_OP_DATA11_ADDRESS 0x84
#define TL_TBL_RD_OP_DATA11_NUM     1
#define TL_TBL_RD_OP_DATA11_INC     0x4
#define TL_TBL_RD_OP_DATA11_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA11_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA11_DATA
	#define TL_TBL_RD_OP_DATA11_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA11_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA11_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data11 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data11_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data11 bf;
};

/*[register] TL_TBL_RD_OP_DATA12*/
#define TL_TBL_RD_OP_DATA12
#define TL_TBL_RD_OP_DATA12_ADDRESS 0x88
#define TL_TBL_RD_OP_DATA12_NUM     1
#define TL_TBL_RD_OP_DATA12_INC     0x4
#define TL_TBL_RD_OP_DATA12_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA12_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA12_DATA
	#define TL_TBL_RD_OP_DATA12_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA12_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA12_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data12 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data12_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data12 bf;
};

/*[register] TL_TBL_RD_OP_DATA13*/
#define TL_TBL_RD_OP_DATA13
#define TL_TBL_RD_OP_DATA13_ADDRESS 0x8c
#define TL_TBL_RD_OP_DATA13_NUM     1
#define TL_TBL_RD_OP_DATA13_INC     0x4
#define TL_TBL_RD_OP_DATA13_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA13_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA13_DATA
	#define TL_TBL_RD_OP_DATA13_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA13_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA13_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data13 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data13_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data13 bf;
};

/*[register] TL_TBL_RD_OP_DATA14*/
#define TL_TBL_RD_OP_DATA14
#define TL_TBL_RD_OP_DATA14_ADDRESS 0x90
#define TL_TBL_RD_OP_DATA14_NUM     1
#define TL_TBL_RD_OP_DATA14_INC     0x4
#define TL_TBL_RD_OP_DATA14_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA14_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA14_DATA
	#define TL_TBL_RD_OP_DATA14_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA14_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA14_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data14 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data14_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data14 bf;
};

/*[register] TL_TBL_RD_OP_DATA15*/
#define TL_TBL_RD_OP_DATA15
#define TL_TBL_RD_OP_DATA15_ADDRESS 0x94
#define TL_TBL_RD_OP_DATA15_NUM     1
#define TL_TBL_RD_OP_DATA15_INC     0x4
#define TL_TBL_RD_OP_DATA15_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA15_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA15_DATA
	#define TL_TBL_RD_OP_DATA15_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA15_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA15_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data15 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data15_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data15 bf;
};

/*[register] TL_TBL_RD_OP_DATA16*/
#define TL_TBL_RD_OP_DATA16
#define TL_TBL_RD_OP_DATA16_ADDRESS 0x98
#define TL_TBL_RD_OP_DATA16_NUM     1
#define TL_TBL_RD_OP_DATA16_INC     0x4
#define TL_TBL_RD_OP_DATA16_TYPE    REG_TYPE_RW
#define TL_TBL_RD_OP_DATA16_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_OP_DATA16_DATA
	#define TL_TBL_RD_OP_DATA16_DATA_OFFSET  0
	#define TL_TBL_RD_OP_DATA16_DATA_LEN     32
	#define TL_TBL_RD_OP_DATA16_DATA_DEFAULT 0x0

struct tl_tbl_rd_op_data16 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_op_data16_u {
	a_uint32_t val;
	struct tl_tbl_rd_op_data16 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA0*/
#define TL_TBL_RD_RSLT_DATA0
#define TL_TBL_RD_RSLT_DATA0_ADDRESS 0xa0
#define TL_TBL_RD_RSLT_DATA0_NUM     1
#define TL_TBL_RD_RSLT_DATA0_INC     0x4
#define TL_TBL_RD_RSLT_DATA0_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA0_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA0_DATA
	#define TL_TBL_RD_RSLT_DATA0_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA0_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA0_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data0 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data0_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data0 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA1*/
#define TL_TBL_RD_RSLT_DATA1
#define TL_TBL_RD_RSLT_DATA1_ADDRESS 0xa4
#define TL_TBL_RD_RSLT_DATA1_NUM     1
#define TL_TBL_RD_RSLT_DATA1_INC     0x4
#define TL_TBL_RD_RSLT_DATA1_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA1_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA1_DATA
	#define TL_TBL_RD_RSLT_DATA1_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA1_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA1_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data1 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data1_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data1 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA2*/
#define TL_TBL_RD_RSLT_DATA2
#define TL_TBL_RD_RSLT_DATA2_ADDRESS 0xa8
#define TL_TBL_RD_RSLT_DATA2_NUM     1
#define TL_TBL_RD_RSLT_DATA2_INC     0x4
#define TL_TBL_RD_RSLT_DATA2_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA2_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA2_DATA
	#define TL_TBL_RD_RSLT_DATA2_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA2_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA2_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data2 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data2_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data2 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA3*/
#define TL_TBL_RD_RSLT_DATA3
#define TL_TBL_RD_RSLT_DATA3_ADDRESS 0xac
#define TL_TBL_RD_RSLT_DATA3_NUM     1
#define TL_TBL_RD_RSLT_DATA3_INC     0x4
#define TL_TBL_RD_RSLT_DATA3_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA3_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA3_DATA
	#define TL_TBL_RD_RSLT_DATA3_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA3_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA3_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data3 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data3_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data3 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA4*/
#define TL_TBL_RD_RSLT_DATA4
#define TL_TBL_RD_RSLT_DATA4_ADDRESS 0xb0
#define TL_TBL_RD_RSLT_DATA4_NUM     1
#define TL_TBL_RD_RSLT_DATA4_INC     0x4
#define TL_TBL_RD_RSLT_DATA4_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA4_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA4_DATA
	#define TL_TBL_RD_RSLT_DATA4_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA4_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA4_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data4 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data4_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data4 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA5*/
#define TL_TBL_RD_RSLT_DATA5
#define TL_TBL_RD_RSLT_DATA5_ADDRESS 0xb4
#define TL_TBL_RD_RSLT_DATA5_NUM     1
#define TL_TBL_RD_RSLT_DATA5_INC     0x4
#define TL_TBL_RD_RSLT_DATA5_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA5_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA5_DATA
	#define TL_TBL_RD_RSLT_DATA5_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA5_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA5_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data5 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data5_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data5 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA6*/
#define TL_TBL_RD_RSLT_DATA6
#define TL_TBL_RD_RSLT_DATA6_ADDRESS 0xb8
#define TL_TBL_RD_RSLT_DATA6_NUM     1
#define TL_TBL_RD_RSLT_DATA6_INC     0x4
#define TL_TBL_RD_RSLT_DATA6_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA6_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA6_DATA
	#define TL_TBL_RD_RSLT_DATA6_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA6_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA6_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data6 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data6_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data6 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA7*/
#define TL_TBL_RD_RSLT_DATA7
#define TL_TBL_RD_RSLT_DATA7_ADDRESS 0xbc
#define TL_TBL_RD_RSLT_DATA7_NUM     1
#define TL_TBL_RD_RSLT_DATA7_INC     0x4
#define TL_TBL_RD_RSLT_DATA7_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA7_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA7_DATA
	#define TL_TBL_RD_RSLT_DATA7_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA7_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA7_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data7 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data7_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data7 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA8*/
#define TL_TBL_RD_RSLT_DATA8
#define TL_TBL_RD_RSLT_DATA8_ADDRESS 0xc0
#define TL_TBL_RD_RSLT_DATA8_NUM     1
#define TL_TBL_RD_RSLT_DATA8_INC     0x4
#define TL_TBL_RD_RSLT_DATA8_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA8_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA8_DATA
	#define TL_TBL_RD_RSLT_DATA8_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA8_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA8_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data8 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data8_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data8 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA9*/
#define TL_TBL_RD_RSLT_DATA9
#define TL_TBL_RD_RSLT_DATA9_ADDRESS 0xc4
#define TL_TBL_RD_RSLT_DATA9_NUM     1
#define TL_TBL_RD_RSLT_DATA9_INC     0x4
#define TL_TBL_RD_RSLT_DATA9_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA9_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA9_DATA
	#define TL_TBL_RD_RSLT_DATA9_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA9_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA9_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data9 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data9_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data9 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA10*/
#define TL_TBL_RD_RSLT_DATA10
#define TL_TBL_RD_RSLT_DATA10_ADDRESS 0xc8
#define TL_TBL_RD_RSLT_DATA10_NUM     1
#define TL_TBL_RD_RSLT_DATA10_INC     0x4
#define TL_TBL_RD_RSLT_DATA10_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA10_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA10_DATA
	#define TL_TBL_RD_RSLT_DATA10_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA10_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA10_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data10 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data10_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data10 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA11*/
#define TL_TBL_RD_RSLT_DATA11
#define TL_TBL_RD_RSLT_DATA11_ADDRESS 0xcc
#define TL_TBL_RD_RSLT_DATA11_NUM     1
#define TL_TBL_RD_RSLT_DATA11_INC     0x4
#define TL_TBL_RD_RSLT_DATA11_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA11_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA11_DATA
	#define TL_TBL_RD_RSLT_DATA11_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA11_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA11_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data11 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data11_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data11 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA12*/
#define TL_TBL_RD_RSLT_DATA12
#define TL_TBL_RD_RSLT_DATA12_ADDRESS 0xd0
#define TL_TBL_RD_RSLT_DATA12_NUM     1
#define TL_TBL_RD_RSLT_DATA12_INC     0x4
#define TL_TBL_RD_RSLT_DATA12_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA12_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA12_DATA
	#define TL_TBL_RD_RSLT_DATA12_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA12_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA12_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data12 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data12_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data12 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA13*/
#define TL_TBL_RD_RSLT_DATA13
#define TL_TBL_RD_RSLT_DATA13_ADDRESS 0xd4
#define TL_TBL_RD_RSLT_DATA13_NUM     1
#define TL_TBL_RD_RSLT_DATA13_INC     0x4
#define TL_TBL_RD_RSLT_DATA13_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA13_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA13_DATA
	#define TL_TBL_RD_RSLT_DATA13_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA13_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA13_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data13 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data13_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data13 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA14*/
#define TL_TBL_RD_RSLT_DATA14
#define TL_TBL_RD_RSLT_DATA14_ADDRESS 0xd8
#define TL_TBL_RD_RSLT_DATA14_NUM     1
#define TL_TBL_RD_RSLT_DATA14_INC     0x4
#define TL_TBL_RD_RSLT_DATA14_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA14_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA14_DATA
	#define TL_TBL_RD_RSLT_DATA14_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA14_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA14_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data14 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data14_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data14 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA15*/
#define TL_TBL_RD_RSLT_DATA15
#define TL_TBL_RD_RSLT_DATA15_ADDRESS 0xdc
#define TL_TBL_RD_RSLT_DATA15_NUM     1
#define TL_TBL_RD_RSLT_DATA15_INC     0x4
#define TL_TBL_RD_RSLT_DATA15_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA15_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA15_DATA
	#define TL_TBL_RD_RSLT_DATA15_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA15_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA15_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data15 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data15_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data15 bf;
};

/*[register] TL_TBL_RD_RSLT_DATA16*/
#define TL_TBL_RD_RSLT_DATA16
#define TL_TBL_RD_RSLT_DATA16_ADDRESS 0xe0
#define TL_TBL_RD_RSLT_DATA16_NUM     1
#define TL_TBL_RD_RSLT_DATA16_INC     0x4
#define TL_TBL_RD_RSLT_DATA16_TYPE    REG_TYPE_RO
#define TL_TBL_RD_RSLT_DATA16_DEFAULT 0x0
	/*[field] DATA*/
	#define TL_TBL_RD_RSLT_DATA16_DATA
	#define TL_TBL_RD_RSLT_DATA16_DATA_OFFSET  0
	#define TL_TBL_RD_RSLT_DATA16_DATA_LEN     32
	#define TL_TBL_RD_RSLT_DATA16_DATA_DEFAULT 0x0

struct tl_tbl_rd_rslt_data16 {
	a_uint32_t  data:32;
};

union tl_tbl_rd_rslt_data16_u {
	a_uint32_t val;
	struct tl_tbl_rd_rslt_data16 bf;
};

/*[register] TL_CTRL*/
#define TL_CTRL
#define TL_CTRL_ADDRESS 0xe4
#define TL_CTRL_NUM     1
#define TL_CTRL_INC     0x4
#define TL_CTRL_TYPE    REG_TYPE_RW
#define TL_CTRL_DEFAULT 0xff11b03
	/*[field] TL_DE_ACCE_CMD*/
	#define TL_CTRL_TL_DE_ACCE_CMD
	#define TL_CTRL_TL_DE_ACCE_CMD_OFFSET  0
	#define TL_CTRL_TL_DE_ACCE_CMD_LEN     2
	#define TL_CTRL_TL_DE_ACCE_CMD_DEFAULT 0x3
	/*[field] TL_SRC_IF_CHECK_CMD*/
	#define TL_CTRL_TL_SRC_IF_CHECK_CMD
	#define TL_CTRL_TL_SRC_IF_CHECK_CMD_OFFSET  2
	#define TL_CTRL_TL_SRC_IF_CHECK_CMD_LEN     2
	#define TL_CTRL_TL_SRC_IF_CHECK_CMD_DEFAULT 0x0
	/*[field] TL_SRC_IF_CHECK_DE_ACCE*/
	#define TL_CTRL_TL_SRC_IF_CHECK_DE_ACCE
	#define TL_CTRL_TL_SRC_IF_CHECK_DE_ACCE_OFFSET  4
	#define TL_CTRL_TL_SRC_IF_CHECK_DE_ACCE_LEN     1
	#define TL_CTRL_TL_SRC_IF_CHECK_DE_ACCE_DEFAULT 0x0
	/*[field] TL_VLAN_CHECK_CMD*/
	#define TL_CTRL_TL_VLAN_CHECK_CMD
	#define TL_CTRL_TL_VLAN_CHECK_CMD_OFFSET  5
	#define TL_CTRL_TL_VLAN_CHECK_CMD_LEN     2
	#define TL_CTRL_TL_VLAN_CHECK_CMD_DEFAULT 0x0
	/*[field] TL_VLAN_CHECK_DE_ACCE*/
	#define TL_CTRL_TL_VLAN_CHECK_DE_ACCE
	#define TL_CTRL_TL_VLAN_CHECK_DE_ACCE_OFFSET  7
	#define TL_CTRL_TL_VLAN_CHECK_DE_ACCE_LEN     1
	#define TL_CTRL_TL_VLAN_CHECK_DE_ACCE_DEFAULT 0x0
	/*[field] PPPOE_MULTICAST_CMD*/
	#define TL_CTRL_PPPOE_MULTICAST_CMD
	#define TL_CTRL_PPPOE_MULTICAST_CMD_OFFSET  8
	#define TL_CTRL_PPPOE_MULTICAST_CMD_LEN     2
	#define TL_CTRL_PPPOE_MULTICAST_CMD_DEFAULT 0x3
	/*[field] PPPOE_MULTICAST_DE_ACCE*/
	#define TL_CTRL_PPPOE_MULTICAST_DE_ACCE
	#define TL_CTRL_PPPOE_MULTICAST_DE_ACCE_OFFSET  10
	#define TL_CTRL_PPPOE_MULTICAST_DE_ACCE_LEN     1
	#define TL_CTRL_PPPOE_MULTICAST_DE_ACCE_DEFAULT 0x0
	/*[field] UDP_CSUM_ZERO_CMD*/
	#define TL_CTRL_UDP_CSUM_ZERO_CMD
	#define TL_CTRL_UDP_CSUM_ZERO_CMD_OFFSET  11
	#define TL_CTRL_UDP_CSUM_ZERO_CMD_LEN     2
	#define TL_CTRL_UDP_CSUM_ZERO_CMD_DEFAULT 0x3
	/*[field] UDP_CSUM_ZERO_DE_ACCE*/
	#define TL_CTRL_UDP_CSUM_ZERO_DE_ACCE
	#define TL_CTRL_UDP_CSUM_ZERO_DE_ACCE_OFFSET  13
	#define TL_CTRL_UDP_CSUM_ZERO_DE_ACCE_LEN     1
	#define TL_CTRL_UDP_CSUM_ZERO_DE_ACCE_DEFAULT 0x0
	/*[field] TL_HASH_MODE_0*/
	#define TL_CTRL_TL_HASH_MODE_0
	#define TL_CTRL_TL_HASH_MODE_0_OFFSET  14
	#define TL_CTRL_TL_HASH_MODE_0_LEN     2
	#define TL_CTRL_TL_HASH_MODE_0_DEFAULT 0x0
	/*[field] TL_HASH_MODE_1*/
	#define TL_CTRL_TL_HASH_MODE_1
	#define TL_CTRL_TL_HASH_MODE_1_OFFSET  16
	#define TL_CTRL_TL_HASH_MODE_1_LEN     2
	#define TL_CTRL_TL_HASH_MODE_1_DEFAULT 0x1
	/*[field] IPV4_DF_SET*/
	#define TL_CTRL_IPV4_DF_SET
	#define TL_CTRL_IPV4_DF_SET_OFFSET  18
	#define TL_CTRL_IPV4_DF_SET_LEN     2
	#define TL_CTRL_IPV4_DF_SET_DEFAULT 0x0
	/*[field] TL_MAP_SRC_CHECK_CMD*/
	#define TL_CTRL_TL_MAP_SRC_CHECK_CMD
	#define TL_CTRL_TL_MAP_SRC_CHECK_CMD_OFFSET  20
	#define TL_CTRL_TL_MAP_SRC_CHECK_CMD_LEN     2
	#define TL_CTRL_TL_MAP_SRC_CHECK_CMD_DEFAULT 0x3
	/*[field] TL_MAP_DST_CHECK_CMD*/
	#define TL_CTRL_TL_MAP_DST_CHECK_CMD
	#define TL_CTRL_TL_MAP_DST_CHECK_CMD_OFFSET  22
	#define TL_CTRL_TL_MAP_DST_CHECK_CMD_LEN     2
	#define TL_CTRL_TL_MAP_DST_CHECK_CMD_DEFAULT 0x3
	/*[field] TL_MAP_NON_TCP_UDP_CMD*/
	#define TL_CTRL_TL_MAP_NON_TCP_UDP_CMD
	#define TL_CTRL_TL_MAP_NON_TCP_UDP_CMD_OFFSET  24
	#define TL_CTRL_TL_MAP_NON_TCP_UDP_CMD_LEN     2
	#define TL_CTRL_TL_MAP_NON_TCP_UDP_CMD_DEFAULT 0x3
	/*[field] TL_MAP_UDP_CSUM_ZERO_CMD*/
	#define TL_CTRL_TL_MAP_UDP_CSUM_ZERO_CMD
	#define TL_CTRL_TL_MAP_UDP_CSUM_ZERO_CMD_OFFSET  26
	#define TL_CTRL_TL_MAP_UDP_CSUM_ZERO_CMD_LEN     2
	#define TL_CTRL_TL_MAP_UDP_CSUM_ZERO_CMD_DEFAULT 0x3

struct tl_ctrl {
	a_uint32_t  tl_de_acce_cmd:2;
	a_uint32_t  tl_src_if_check_cmd:2;
	a_uint32_t  tl_src_if_check_de_acce:1;
	a_uint32_t  tl_vlan_check_cmd:2;
	a_uint32_t  tl_vlan_check_de_acce:1;
	a_uint32_t  pppoe_multicast_cmd:2;
	a_uint32_t  pppoe_multicast_de_acce:1;
	a_uint32_t  udp_csum_zero_cmd:2;
	a_uint32_t  udp_csum_zero_de_acce:1;
	a_uint32_t  tl_hash_mode_0:2;
	a_uint32_t  tl_hash_mode_1:2;
	a_uint32_t  ipv4_df_set:2;
	a_uint32_t  tl_map_src_check_cmd:2;
	a_uint32_t  tl_map_dst_check_cmd:2;
	a_uint32_t  tl_map_non_tcp_udp_cmd:2;
	a_uint32_t  tl_map_udp_csum_zero_cmd:2;
	a_uint32_t  _reserved0:4;
};

union tl_ctrl_u {
	a_uint32_t val;
	struct tl_ctrl bf;
};

/*[register] TL_INGRESS_CNT*/
#define TL_INGRESS_CNT
#define TL_INGRESS_CNT_ADDRESS 0x108
#define TL_INGRESS_CNT_NUM     1
#define TL_INGRESS_CNT_INC     0x4
#define TL_INGRESS_CNT_TYPE    REG_TYPE_RO
#define TL_INGRESS_CNT_DEFAULT 0x0
	/*[field] CNT*/
	#define TL_INGRESS_CNT_CNT
	#define TL_INGRESS_CNT_CNT_OFFSET  0
	#define TL_INGRESS_CNT_CNT_LEN     32
	#define TL_INGRESS_CNT_CNT_DEFAULT 0x0

struct tl_ingress_cnt {
	a_uint32_t  cnt:32;
};

union tl_ingress_cnt_u {
	a_uint32_t val;
	struct tl_ingress_cnt bf;
};

/*[register] TL_EGRESS_CNT*/
#define TL_EGRESS_CNT
#define TL_EGRESS_CNT_ADDRESS 0x10c
#define TL_EGRESS_CNT_NUM     1
#define TL_EGRESS_CNT_INC     0x4
#define TL_EGRESS_CNT_TYPE    REG_TYPE_RO
#define TL_EGRESS_CNT_DEFAULT 0x0
	/*[field] CNT*/
	#define TL_EGRESS_CNT_CNT
	#define TL_EGRESS_CNT_CNT_OFFSET  0
	#define TL_EGRESS_CNT_CNT_LEN     32
	#define TL_EGRESS_CNT_CNT_DEFAULT 0x0

struct tl_egress_cnt {
	a_uint32_t  cnt:32;
};

union tl_egress_cnt_u {
	a_uint32_t val;
	struct tl_egress_cnt bf;
};

/*[table] TL_L3_IF_TBL*/
#define TL_L3_IF_TBL
#define TL_L3_IF_TBL_ADDRESS 0x3000
#define TL_L3_IF_TBL_NUM     128
#define TL_L3_IF_TBL_INC     0x10
#define TL_L3_IF_TBL_TYPE    REG_TYPE_RW
#define TL_L3_IF_TBL_DEFAULT 0x0
	/*[field] IPV4_DECAP_EN*/
	#define TL_L3_IF_TBL_IPV4_DECAP_EN
	#define TL_L3_IF_TBL_IPV4_DECAP_EN_OFFSET  0
	#define TL_L3_IF_TBL_IPV4_DECAP_EN_LEN     1
	#define TL_L3_IF_TBL_IPV4_DECAP_EN_DEFAULT 0x0
	/*[field] IPV6_DECAP_EN*/
	#define TL_L3_IF_TBL_IPV6_DECAP_EN
	#define TL_L3_IF_TBL_IPV6_DECAP_EN_OFFSET  1
	#define TL_L3_IF_TBL_IPV6_DECAP_EN_LEN     1
	#define TL_L3_IF_TBL_IPV6_DECAP_EN_DEFAULT 0x0
	/*[field] DMAC_CHECK_DIS*/
	#define TL_L3_IF_TBL_DMAC_CHECK_DIS
	#define TL_L3_IF_TBL_DMAC_CHECK_DIS_OFFSET  2
	#define TL_L3_IF_TBL_DMAC_CHECK_DIS_LEN     1
	#define TL_L3_IF_TBL_DMAC_CHECK_DIS_DEFAULT 0x0
	/*[field] TTL_EXCEED_CMD*/
	#define TL_L3_IF_TBL_TTL_EXCEED_CMD
	#define TL_L3_IF_TBL_TTL_EXCEED_CMD_OFFSET  3
	#define TL_L3_IF_TBL_TTL_EXCEED_CMD_LEN     2
	#define TL_L3_IF_TBL_TTL_EXCEED_CMD_DEFAULT 0x0
	/*[field] TTL_EXCEED_DE_ACCE*/
	#define TL_L3_IF_TBL_TTL_EXCEED_DE_ACCE
	#define TL_L3_IF_TBL_TTL_EXCEED_DE_ACCE_OFFSET  5
	#define TL_L3_IF_TBL_TTL_EXCEED_DE_ACCE_LEN     1
	#define TL_L3_IF_TBL_TTL_EXCEED_DE_ACCE_DEFAULT 0x0
	/*[field] LPM_EN*/
	#define TL_L3_IF_TBL_LPM_EN
	#define TL_L3_IF_TBL_LPM_EN_OFFSET  6
	#define TL_L3_IF_TBL_LPM_EN_LEN     1
	#define TL_L3_IF_TBL_LPM_EN_DEFAULT 0x0
	/*[field] MIN_IPV6_MTU*/
	#define TL_L3_IF_TBL_MIN_IPV6_MTU
	#define TL_L3_IF_TBL_MIN_IPV6_MTU_OFFSET  7
	#define TL_L3_IF_TBL_MIN_IPV6_MTU_LEN     14
	#define TL_L3_IF_TBL_MIN_IPV6_MTU_DEFAULT 0x0

struct tl_l3_if_tbl {
	a_uint32_t  ipv4_decap_en:1;
	a_uint32_t  ipv6_decap_en:1;
	a_uint32_t  dmac_check_dis:1;
	a_uint32_t  ttl_exceed_cmd:2;
	a_uint32_t  ttl_exceed_de_acce:1;
	a_uint32_t  lpm_en:1;
	a_uint32_t  min_ipv6_mtu:14;
	a_uint32_t  _reserved0:11;
};

union tl_l3_if_tbl_u {
	a_uint32_t val;
	struct tl_l3_if_tbl bf;
};

/*[table] TL_KEY_GEN*/
#define TL_KEY_GEN
#define TL_KEY_GEN_ADDRESS 0x3800
#define TL_KEY_GEN_NUM     16
#define TL_KEY_GEN_INC     0x10
#define TL_KEY_GEN_TYPE    REG_TYPE_RW
#define TL_KEY_GEN_DEFAULT 0x0
	/*[field] SIP_INC*/
	#define TL_KEY_GEN_SIP_INC
	#define TL_KEY_GEN_SIP_INC_OFFSET  0
	#define TL_KEY_GEN_SIP_INC_LEN     1
	#define TL_KEY_GEN_SIP_INC_DEFAULT 0x0
	/*[field] DIP_INC*/
	#define TL_KEY_GEN_DIP_INC
	#define TL_KEY_GEN_DIP_INC_OFFSET  1
	#define TL_KEY_GEN_DIP_INC_LEN     1
	#define TL_KEY_GEN_DIP_INC_DEFAULT 0x0
	/*[field] IP_PROT_INC*/
	#define TL_KEY_GEN_IP_PROT_INC
	#define TL_KEY_GEN_IP_PROT_INC_OFFSET  2
	#define TL_KEY_GEN_IP_PROT_INC_LEN     1
	#define TL_KEY_GEN_IP_PROT_INC_DEFAULT 0x0
	/*[field] SPORT_INC*/
	#define TL_KEY_GEN_SPORT_INC
	#define TL_KEY_GEN_SPORT_INC_OFFSET  3
	#define TL_KEY_GEN_SPORT_INC_LEN     1
	#define TL_KEY_GEN_SPORT_INC_DEFAULT 0x0
	/*[field] DPORT_INC*/
	#define TL_KEY_GEN_DPORT_INC
	#define TL_KEY_GEN_DPORT_INC_OFFSET  4
	#define TL_KEY_GEN_DPORT_INC_LEN     1
	#define TL_KEY_GEN_DPORT_INC_DEFAULT 0x0
	/*[field] VNI_RESV_INC*/
	#define TL_KEY_GEN_VNI_RESV_INC
	#define TL_KEY_GEN_VNI_RESV_INC_OFFSET  5
	#define TL_KEY_GEN_VNI_RESV_INC_LEN     1
	#define TL_KEY_GEN_VNI_RESV_INC_DEFAULT 0x0
	/*[field] UDF0_INC*/
	#define TL_KEY_GEN_UDF0_INC
	#define TL_KEY_GEN_UDF0_INC_OFFSET  6
	#define TL_KEY_GEN_UDF0_INC_LEN     1
	#define TL_KEY_GEN_UDF0_INC_DEFAULT 0x0
	/*[field] UDF0_ID*/
	#define TL_KEY_GEN_UDF0_ID
	#define TL_KEY_GEN_UDF0_ID_OFFSET  7
	#define TL_KEY_GEN_UDF0_ID_LEN     2
	#define TL_KEY_GEN_UDF0_ID_DEFAULT 0x0
	/*[field] UDF1_INC*/
	#define TL_KEY_GEN_UDF1_INC
	#define TL_KEY_GEN_UDF1_INC_OFFSET  9
	#define TL_KEY_GEN_UDF1_INC_LEN     1
	#define TL_KEY_GEN_UDF1_INC_DEFAULT 0x0
	/*[field] UDF1_ID*/
	#define TL_KEY_GEN_UDF1_ID
	#define TL_KEY_GEN_UDF1_ID_OFFSET  10
	#define TL_KEY_GEN_UDF1_ID_LEN     2
	#define TL_KEY_GEN_UDF1_ID_DEFAULT 0x0
	/*[field] VNI_RESV_MASK*/
	#define TL_KEY_GEN_VNI_RESV_MASK
	#define TL_KEY_GEN_VNI_RESV_MASK_OFFSET  12
	#define TL_KEY_GEN_VNI_RESV_MASK_LEN     32
	#define TL_KEY_GEN_VNI_RESV_MASK_DEFAULT 0x0
	/*[field] UDF0_MASK*/
	#define TL_KEY_GEN_UDF0_MASK
	#define TL_KEY_GEN_UDF0_MASK_OFFSET  44
	#define TL_KEY_GEN_UDF0_MASK_LEN     16
	#define TL_KEY_GEN_UDF0_MASK_DEFAULT 0x0
	/*[field] UDF1_MASK*/
	#define TL_KEY_GEN_UDF1_MASK
	#define TL_KEY_GEN_UDF1_MASK_OFFSET  60
	#define TL_KEY_GEN_UDF1_MASK_LEN     16
	#define TL_KEY_GEN_UDF1_MASK_DEFAULT 0x0
	/*[field] KEY_TYPE*/
	#define TL_KEY_GEN_KEY_TYPE
	#define TL_KEY_GEN_KEY_TYPE_OFFSET  76
	#define TL_KEY_GEN_KEY_TYPE_LEN     4
	#define TL_KEY_GEN_KEY_TYPE_DEFAULT 0x0

struct tl_key_gen {
	a_uint32_t  sip_inc:1;
	a_uint32_t  dip_inc:1;
	a_uint32_t  ip_prot_inc:1;
	a_uint32_t  sport_inc:1;
	a_uint32_t  dport_inc:1;
	a_uint32_t  vni_resv_inc:1;
	a_uint32_t  udf0_inc:1;
	a_uint32_t  udf0_id:2;
	a_uint32_t  udf1_inc:1;
	a_uint32_t  udf1_id:2;
	a_uint32_t  vni_resv_mask_0:20;
	a_uint32_t  vni_resv_mask_1:12;
	a_uint32_t  udf0_mask:16;
	a_uint32_t  udf1_mask_0:4;
	a_uint32_t  udf1_mask_1:12;
	a_uint32_t  key_type:4;
	a_uint32_t  _reserved0:16;
};

union tl_key_gen_u {
	a_uint32_t val[3];
	struct tl_key_gen bf;
};

/*[table] TL_TBL*/
#define TL_TBL
#define TL_TBL_ADDRESS 0x4000
#define TL_TBL_NUM     128
#define TL_TBL_INC     0x40
#define TL_TBL_TYPE    REG_TYPE_RW
#define TL_TBL_DEFAULT 0x0
	/*[field] VALID*/
	#define TL_TBL_VALID
	#define TL_TBL_VALID_OFFSET  0
	#define TL_TBL_VALID_LEN     1
	#define TL_TBL_VALID_DEFAULT 0x0
	/*[field] ENTRY_TYPE*/
	#define TL_TBL_ENTRY_TYPE
	#define TL_TBL_ENTRY_TYPE_OFFSET  1
	#define TL_TBL_ENTRY_TYPE_LEN     1
	#define TL_TBL_ENTRY_TYPE_DEFAULT 0x0
	/*[field] KEY_TYPE*/
	#define TL_TBL_KEY_TYPE
	#define TL_TBL_KEY_TYPE_OFFSET  2
	#define TL_TBL_KEY_TYPE_LEN     4
	#define TL_TBL_KEY_TYPE_DEFAULT 0x0
	/*[field] PROTOCOL*/
	#define TL_TBL_PROTOCOL
	#define TL_TBL_PROTOCOL_OFFSET  6
	#define TL_TBL_PROTOCOL_LEN     8
	#define TL_TBL_PROTOCOL_DEFAULT 0x0
	/*[field] IPV4_SRC_ADDR reuse ENTRY_TYPE[1]*/
	#define TL_TBL_IPV4_SRC_ADDR
	#define TL_TBL_IPV4_SRC_ADDR_OFFSET  14
	#define TL_TBL_IPV4_SRC_ADDR_LEN     32
	#define TL_TBL_IPV4_SRC_ADDR_DEFAULT 0x0
	/*[field] IPV6_SRC_ADDR reuse ENTRY_TYPE[0]*/
	#define TL_TBL_IPV6_SRC_ADDR
	#define TL_TBL_IPV6_SRC_ADDR_OFFSET  14
	#define TL_TBL_IPV6_SRC_ADDR_LEN     128
	#define TL_TBL_IPV6_SRC_ADDR_DEFAULT 0x0
	/*[field] IPV4_DST_ADDR reuse ENTRY_TYPE[1]*/
	#define TL_TBL_IPV4_DST_ADDR
	#define TL_TBL_IPV4_DST_ADDR_OFFSET  46
	#define TL_TBL_IPV4_DST_ADDR_LEN     32
	#define TL_TBL_IPV4_DST_ADDR_DEFAULT 0x0
	/*[field] IPV6_DST_ADDR reuse ENTRY_TYPE[0]*/
	#define TL_TBL_IPV6_DST_ADDR
	#define TL_TBL_IPV6_DST_ADDR_OFFSET  142
	#define TL_TBL_IPV6_DST_ADDR_LEN     128
	#define TL_TBL_IPV6_DST_ADDR_DEFAULT 0x0
	/*[field] L4_SPORT*/
	#define TL_TBL_L4_SPORT
	#define TL_TBL_L4_SPORT_OFFSET  270
	#define TL_TBL_L4_SPORT_LEN     16
	#define TL_TBL_L4_SPORT_DEFAULT 0x0
	/*[field] L4_DPORT*/
	#define TL_TBL_L4_DPORT
	#define TL_TBL_L4_DPORT_OFFSET  286
	#define TL_TBL_L4_DPORT_LEN     16
	#define TL_TBL_L4_DPORT_DEFAULT 0x0
	/*[field] VNI_RESV*/
	#define TL_TBL_VNI_RESV
	#define TL_TBL_VNI_RESV_OFFSET  302
	#define TL_TBL_VNI_RESV_LEN     32
	#define TL_TBL_VNI_RESV_DEFAULT 0x0
	/*[field] UDF0*/
	#define TL_TBL_UDF0
	#define TL_TBL_UDF0_OFFSET  334
	#define TL_TBL_UDF0_LEN     16
	#define TL_TBL_UDF0_DEFAULT 0x0
	/*[field] UDF1*/
	#define TL_TBL_UDF1
	#define TL_TBL_UDF1_OFFSET  350
	#define TL_TBL_UDF1_LEN     16
	#define TL_TBL_UDF1_DEFAULT 0x0
	/*[field] VNI_RESV_VALID*/
	#define TL_TBL_VNI_RESV_VALID
	#define TL_TBL_VNI_RESV_VALID_OFFSET  366
	#define TL_TBL_VNI_RESV_VALID_LEN     1
	#define TL_TBL_VNI_RESV_VALID_DEFAULT 0x0
	/*[field] UDF0_VALID*/
	#define TL_TBL_UDF0_VALID
	#define TL_TBL_UDF0_VALID_OFFSET  367
	#define TL_TBL_UDF0_VALID_LEN     1
	#define TL_TBL_UDF0_VALID_DEFAULT 0x0
	/*[field] UDF1_VALID*/
	#define TL_TBL_UDF1_VALID
	#define TL_TBL_UDF1_VALID_OFFSET  368
	#define TL_TBL_UDF1_VALID_LEN     1
	#define TL_TBL_UDF1_VALID_DEFAULT 0x0
	/*[field] FWD_TYPE*/
	#define TL_TBL_FWD_TYPE
	#define TL_TBL_FWD_TYPE_OFFSET  369
	#define TL_TBL_FWD_TYPE_LEN     2
	#define TL_TBL_FWD_TYPE_DEFAULT 0x0
	/*[field] DE_ACCE*/
	#define TL_TBL_DE_ACCE
	#define TL_TBL_DE_ACCE_OFFSET  371
	#define TL_TBL_DE_ACCE_LEN     1
	#define TL_TBL_DE_ACCE_DEFAULT 0x0
	/*[field] DECAP_EN*/
	#define TL_TBL_DECAP_EN
	#define TL_TBL_DECAP_EN_OFFSET  372
	#define TL_TBL_DECAP_EN_LEN     1
	#define TL_TBL_DECAP_EN_DEFAULT 0x0
	/*[field] UDP_CSUM_ZERO*/
	#define TL_TBL_UDP_CSUM_ZERO
	#define TL_TBL_UDP_CSUM_ZERO_OFFSET  373
	#define TL_TBL_UDP_CSUM_ZERO_LEN     1
	#define TL_TBL_UDP_CSUM_ZERO_DEFAULT 0x0
	/*[field] SERVICE_CODE_EN*/
	#define TL_TBL_SERVICE_CODE_EN
	#define TL_TBL_SERVICE_CODE_EN_OFFSET  374
	#define TL_TBL_SERVICE_CODE_EN_LEN     1
	#define TL_TBL_SERVICE_CODE_EN_DEFAULT 0x0
	/*[field] SERVICE_CODE*/
	#define TL_TBL_SERVICE_CODE
	#define TL_TBL_SERVICE_CODE_OFFSET  375
	#define TL_TBL_SERVICE_CODE_LEN     8
	#define TL_TBL_SERVICE_CODE_DEFAULT 0x0
	/*[field] SPCP_MODE*/
	#define TL_TBL_SPCP_MODE
	#define TL_TBL_SPCP_MODE_OFFSET  383
	#define TL_TBL_SPCP_MODE_LEN     1
	#define TL_TBL_SPCP_MODE_DEFAULT 0x0
	/*[field] SDEI_MODE*/
	#define TL_TBL_SDEI_MODE
	#define TL_TBL_SDEI_MODE_OFFSET  384
	#define TL_TBL_SDEI_MODE_LEN     1
	#define TL_TBL_SDEI_MODE_DEFAULT 0x0
	/*[field] CPCP_MODE*/
	#define TL_TBL_CPCP_MODE
	#define TL_TBL_CPCP_MODE_OFFSET  385
	#define TL_TBL_CPCP_MODE_LEN     1
	#define TL_TBL_CPCP_MODE_DEFAULT 0x0
	/*[field] CDEI_MODE*/
	#define TL_TBL_CDEI_MODE
	#define TL_TBL_CDEI_MODE_OFFSET  386
	#define TL_TBL_CDEI_MODE_LEN     1
	#define TL_TBL_CDEI_MODE_DEFAULT 0x0
	/*[field] TTL_MODE*/
	#define TL_TBL_TTL_MODE
	#define TL_TBL_TTL_MODE_OFFSET  387
	#define TL_TBL_TTL_MODE_LEN     1
	#define TL_TBL_TTL_MODE_DEFAULT 0x0
	/*[field] DSCP_MODE*/
	#define TL_TBL_DSCP_MODE
	#define TL_TBL_DSCP_MODE_OFFSET  388
	#define TL_TBL_DSCP_MODE_LEN     1
	#define TL_TBL_DSCP_MODE_DEFAULT 0x0
	/*[field] ECN_MODE*/
	#define TL_TBL_ECN_MODE
	#define TL_TBL_ECN_MODE_OFFSET  389
	#define TL_TBL_ECN_MODE_LEN     2
	#define TL_TBL_ECN_MODE_DEFAULT 0x0
	/*[field] SRC_INFO_VALID*/
	#define TL_TBL_SRC_INFO_VALID
	#define TL_TBL_SRC_INFO_VALID_OFFSET  391
	#define TL_TBL_SRC_INFO_VALID_LEN     1
	#define TL_TBL_SRC_INFO_VALID_DEFAULT 0x0
	/*[field] SRC_INFO_TYPE*/
	#define TL_TBL_SRC_INFO_TYPE
	#define TL_TBL_SRC_INFO_TYPE_OFFSET  392
	#define TL_TBL_SRC_INFO_TYPE_LEN     1
	#define TL_TBL_SRC_INFO_TYPE_DEFAULT 0x0
	/*[field] SRC_INFO*/
	#define TL_TBL_SRC_INFO
	#define TL_TBL_SRC_INFO_OFFSET  393
	#define TL_TBL_SRC_INFO_LEN     8
	#define TL_TBL_SRC_INFO_DEFAULT 0x0
	/*[field] TL_L3_IF*/
	#define TL_TBL_TL_L3_IF
	#define TL_TBL_TL_L3_IF_OFFSET  401
	#define TL_TBL_TL_L3_IF_LEN     7
	#define TL_TBL_TL_L3_IF_DEFAULT 0x0
	/*[field] SVLAN_FMT*/
	#define TL_TBL_SVLAN_FMT
	#define TL_TBL_SVLAN_FMT_OFFSET  408
	#define TL_TBL_SVLAN_FMT_LEN     1
	#define TL_TBL_SVLAN_FMT_DEFAULT 0x0
	/*[field] SVLAN_ID*/
	#define TL_TBL_SVLAN_ID
	#define TL_TBL_SVLAN_ID_OFFSET  409
	#define TL_TBL_SVLAN_ID_LEN     12
	#define TL_TBL_SVLAN_ID_DEFAULT 0x0
	/*[field] CVLAN_FMT*/
	#define TL_TBL_CVLAN_FMT
	#define TL_TBL_CVLAN_FMT_OFFSET  421
	#define TL_TBL_CVLAN_FMT_LEN     1
	#define TL_TBL_CVLAN_FMT_DEFAULT 0x0
	/*[field] CVLAN_ID*/
	#define TL_TBL_CVLAN_ID
	#define TL_TBL_CVLAN_ID_OFFSET  422
	#define TL_TBL_CVLAN_ID_LEN     12
	#define TL_TBL_CVLAN_ID_DEFAULT 0x0
	/*[field] SVLAN_CHECK_EN*/
	#define TL_TBL_SVLAN_CHECK_EN
	#define TL_TBL_SVLAN_CHECK_EN_OFFSET  434
	#define TL_TBL_SVLAN_CHECK_EN_LEN     1
	#define TL_TBL_SVLAN_CHECK_EN_DEFAULT 0x0
	/*[field] CVLAN_CHECK_EN*/
	#define TL_TBL_CVLAN_CHECK_EN
	#define TL_TBL_CVLAN_CHECK_EN_OFFSET  435
	#define TL_TBL_CVLAN_CHECK_EN_LEN     1
	#define TL_TBL_CVLAN_CHECK_EN_DEFAULT 0x0
	/*[field] TL_L3_IF_CHECK_EN*/
	#define TL_TBL_TL_L3_IF_CHECK_EN
	#define TL_TBL_TL_L3_IF_CHECK_EN_OFFSET  436
	#define TL_TBL_TL_L3_IF_CHECK_EN_LEN     1
	#define TL_TBL_TL_L3_IF_CHECK_EN_DEFAULT 0x0
	/*[field] EXP_PROFILE*/
	#define TL_TBL_EXP_PROFILE
	#define TL_TBL_EXP_PROFILE_OFFSET  437
	#define TL_TBL_EXP_PROFILE_LEN     2
	#define TL_TBL_EXP_PROFILE_DEFAULT 0x0

struct tl_tbl_0 {
	a_uint32_t  valid:1;
	a_uint32_t  entry_type:1;
	a_uint32_t  key_type:4;
	a_uint32_t  protocol:8;
	a_uint32_t  ipv6_src_addr_0:18;
	a_uint32_t  ipv6_src_addr_1:32;
	a_uint32_t  ipv6_src_addr_2:32;
	a_uint32_t  ipv6_src_addr_3:32;
	a_uint32_t  ipv6_src_addr_4:14;
	a_uint32_t  ipv6_dst_addr_0:18;
	a_uint32_t  ipv6_dst_addr_1:32;
	a_uint32_t  ipv6_dst_addr_2:32;
	a_uint32_t  ipv6_dst_addr_3:32;
	a_uint32_t  ipv6_dst_addr_4:14;
	a_uint32_t  l4_sport:16;
	a_uint32_t  l4_dport_0:2;
	a_uint32_t  l4_dport_1:14;
	a_uint32_t  vni_resv_0:18;
	a_uint32_t  vni_resv_1:14;
	a_uint32_t  udf0:16;
	a_uint32_t  udf1_0:2;
	a_uint32_t  udf1_1:14;
	a_uint32_t  vni_resv_valid:1;
	a_uint32_t  udf0_valid:1;
	a_uint32_t  udf1_valid:1;
	a_uint32_t  fwd_type:2;
	a_uint32_t  de_acce:1;
	a_uint32_t  decap_en:1;
	a_uint32_t  udp_csum_zero:1;
	a_uint32_t  service_code_en:1;
	a_uint32_t  service_code:8;
	a_uint32_t  spcp_mode:1;
	a_uint32_t  sdei_mode:1;
	a_uint32_t  cpcp_mode:1;
	a_uint32_t  cdei_mode:1;
	a_uint32_t  ttl_mode:1;
	a_uint32_t  dscp_mode:1;
	a_uint32_t  ecn_mode:2;
	a_uint32_t  src_info_valid:1;
	a_uint32_t  src_info_type:1;
	a_uint32_t  src_info:8;
	a_uint32_t  tl_l3_if:7;
	a_uint32_t  svlan_fmt:1;
	a_uint32_t  svlan_id_0:7;
	a_uint32_t  svlan_id_1:5;
	a_uint32_t  cvlan_fmt:1;
	a_uint32_t  cvlan_id:12;
	a_uint32_t  svlan_check_en:1;
	a_uint32_t  cvlan_check_en:1;
	a_uint32_t  tl_l3_if_check_en:1;
	a_uint32_t  exp_profile:2;
	a_uint32_t  _reserved0:9;
};

struct tl_tbl_1 {
	a_uint32_t  valid:1;
	a_uint32_t  entry_type:1;
	a_uint32_t  key_type:4;
	a_uint32_t  protocol:8;
	a_uint32_t  ipv4_src_addr_0:18;
	a_uint32_t  ipv4_src_addr_1:14;
	a_uint32_t  ipv4_dst_addr_0:18;
	a_uint32_t  ipv4_dst_addr_1:14;
	a_uint32_t  _reserved0_0:18;
	a_uint32_t  _reserved0_1:32;
	a_uint32_t  _reserved0_2:32;
	a_uint32_t  _reserved0_3:32;
	a_uint32_t  _reserved0_4:32;
	a_uint32_t  _reserved0_5:32;
	a_uint32_t  _reserved0_6:14;
	a_uint32_t  l4_sport:16;
	a_uint32_t  l4_dport_0:2;
	a_uint32_t  l4_dport_1:14;
	a_uint32_t  vni_resv_0:18;
	a_uint32_t  vni_resv_1:14;
	a_uint32_t  udf0:16;
	a_uint32_t  udf1_0:2;
	a_uint32_t  udf1_1:14;
	a_uint32_t  vni_resv_valid:1;
	a_uint32_t  udf0_valid:1;
	a_uint32_t  udf1_valid:1;
	a_uint32_t  fwd_type:2;
	a_uint32_t  de_acce:1;
	a_uint32_t  decap_en:1;
	a_uint32_t  udp_csum_zero:1;
	a_uint32_t  service_code_en:1;
	a_uint32_t  service_code:8;
	a_uint32_t  spcp_mode:1;
	a_uint32_t  sdei_mode:1;
	a_uint32_t  cpcp_mode:1;
	a_uint32_t  cdei_mode:1;
	a_uint32_t  ttl_mode:1;
	a_uint32_t  dscp_mode:1;
	a_uint32_t  ecn_mode:2;
	a_uint32_t  src_info_valid:1;
	a_uint32_t  src_info_type:1;
	a_uint32_t  src_info:8;
	a_uint32_t  tl_l3_if:7;
	a_uint32_t  svlan_fmt:1;
	a_uint32_t  svlan_id_0:7;
	a_uint32_t  svlan_id_1:5;
	a_uint32_t  cvlan_fmt:1;
	a_uint32_t  cvlan_id:12;
	a_uint32_t  svlan_check_en:1;
	a_uint32_t  cvlan_check_en:1;
	a_uint32_t  tl_l3_if_check_en:1;
	a_uint32_t  exp_profile:2;
	a_uint32_t  _reserved1:9;
};

union tl_tbl_u {
	a_uint32_t val[14];
	struct tl_tbl_0 bf0;
	struct tl_tbl_1 bf1;
};
#endif
