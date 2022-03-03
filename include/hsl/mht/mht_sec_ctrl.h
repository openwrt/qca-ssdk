/*
 * Copyright (c) 2021-2022 Qualcomm Innovation Center, Inc. All rights reserved.
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
 * @defgroup mht_init MHT_SEC_CTRL
 * @{
 */
#ifndef _MHT_SEC_CTRL_H_
#define _MHT_SEC_CTRL_H_


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include "ssdk_plat.h"
#include "mht_reg.h"

typedef enum {
	MHT_SWITCH_MODE =
		(BIT(WORK_MODE_PHY3_SEL1_BOFFSET)),
	MHT_SWITCH_BYPASS_PORT5_MODE =
		(BIT(WORK_MODE_PORT5_SEL_BOFFSET)),
	MHT_PHY_UQXGMII_MODE =
		(BIT(WORK_MODE_PORT5_SEL_BOFFSET) |
		BIT(WORK_MODE_PHY3_SEL0_BOFFSET) |
		BIT(WORK_MODE_PHY2_SEL_BOFFSET) |
		BIT(WORK_MODE_PHY1_SEL_BOFFSET) |
		BIT(WORK_MODE_PHY0_SEL_BOFFSET)),
	MHT_PHY_SGMII_UQXGMII_MODE =
		(BIT(WORK_MODE_PORT5_SEL_BOFFSET) |
		BIT(WORK_MODE_PHY2_SEL_BOFFSET) |
		BIT(WORK_MODE_PHY1_SEL_BOFFSET) |
		BIT(WORK_MODE_PHY0_SEL_BOFFSET)),
	MHT_WORK_MODE_MAX,
} mht_work_mode_t;

#define MHT_WORK_MODE_MASK \
	(BITS(WORK_MODE_PHY0_SEL_BOFFSET, WORK_MODE_PORT5_SEL_BOFFSET + 1))

sw_error_t
qca_mht_work_mode_set(a_uint32_t dev_id, mht_work_mode_t work_mode);

sw_error_t
qca_mht_work_mode_get(a_uint32_t dev_id, mht_work_mode_t *work_mode);

sw_error_t
qca_mht_serdes_addr_get(a_uint32_t dev_id, a_uint32_t serdes_id,
	a_uint32_t *address);

sw_error_t
qca_mht_ephy_addr_get(a_uint32_t dev_id, a_uint32_t port_id,
	a_uint32_t *address);

sw_error_t
qca_mht_port_id_get(a_uint32_t dev_id, a_uint32_t phy_addr,
	a_uint32_t *mht_port_id);

sw_error_t
qca_mht_phy_intr_enable(a_uint32_t dev_id, a_uint32_t phy_addr,
	a_uint32_t intr_bmp);

#if defined(IN_PTP)
sw_error_t
qca_mht_ptp_sync_set(a_uint32_t dev_id, a_uint32_t mht_port_id, a_bool_t enable);

sw_error_t
qca_mht_ptp_sync_get(a_uint32_t dev_id, a_uint32_t mht_port_id, a_bool_t *enable);

sw_error_t
qca_mht_ptp_async_set(a_uint32_t dev_id, a_uint32_t mht_port_id, a_uint32_t src_id);

sw_error_t
qca_mht_ptp_async_get(a_uint32_t dev_id, a_uint32_t mht_port_id, a_uint32_t *src_id);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MHT_SEC_CTRL_H_ */
/**
 * @}
 */
