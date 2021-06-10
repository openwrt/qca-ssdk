/*
 * Copyright (c) 2021 Qualcomm Innovation Center, Inc. All rights reserved.
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
 * @defgroup mht_init MHT_INIT
 * @{
 */
#include "sw.h"
#include "ssdk_init.h"
#include "ssdk_plat.h"
#include "mht_sec_ctrl.h"

static sw_error_t
qca_mht_work_mode_init(a_uint32_t dev_id, a_uint32_t mac_mode0, a_uint32_t mac_mode1)
{
	sw_error_t ret = SW_OK;

	switch (mac_mode0) {
		case PORT_WRAPPER_SGMII_PLUS:
		case PORT_WRAPPER_SGMII_CHANNEL0:
			break;
		default:
			return SW_NOT_SUPPORTED;
	}

	switch (mac_mode1) {
		case PORT_WRAPPER_SGMII_PLUS:
		case PORT_WRAPPER_SGMII_CHANNEL0:
			ret = qca_mht_work_mode_set(dev_id, MHT_SWITCH_MODE);
			SW_RTN_ON_ERROR(ret);
			break;
		case PORT_WRAPPER_MAX:
			ret = qca_mht_work_mode_set(dev_id, MHT_SWITCH_BYPASS_PORT5_MODE);
			SW_RTN_ON_ERROR(ret);
		default:
			break;
	}

	return ret;
}

int qca_mht_hw_init(struct qca_phy_priv *priv)
{
	int ret = 0;
	a_uint32_t mac_mode0, mac_mode1, dev_id;

	SW_RTN_ON_NULL(priv);

	dev_id = priv->device_id;
	mac_mode0 = ssdk_dt_global_get_mac_mode(dev_id, SSDK_UNIPHY_INSTANCE0);
	mac_mode1 = ssdk_dt_global_get_mac_mode(dev_id, SSDK_UNIPHY_INSTANCE1);

	ret = qca_mht_work_mode_init(dev_id, mac_mode0, mac_mode1);
	SW_RTN_ON_ERROR(ret);

	qca_switch_init(priv->device_id);
#ifdef IN_PORTVLAN
	ssdk_portvlan_init(priv->device_id);
#endif
	return ret;
}

/**
 * @}
 */
