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
#include "ssdk_mht_pinctrl.h"
#include "mht_sec_ctrl.h"
#include "ssdk_dts.h"
#include "fal_interface_ctrl.h"
#include "fal_port_ctrl.h"

static sw_error_t
qca_mht_work_mode_init(a_uint32_t dev_id)
{
	mht_work_mode_t clk_mode = ssdk_clk_mode_get(dev_id);

	if (clk_mode == MHT_WORK_MODE_MAX)
		return SW_OUT_OF_RANGE;

	return qca_mht_work_mode_set(dev_id, clk_mode);
}

static sw_error_t
_qca_mht_interface_mode_init(a_uint32_t dev_id, a_uint32_t port_id,
	a_uint32_t mac_mode)
{
	sw_error_t rv = SW_OK;
	fal_mac_config_t mac_config = {0};
	a_bool_t force_en = A_FALSE;
	a_uint32_t force_speed = FAL_SPEED_BUTT;

	force_en = ssdk_port_feature_get(dev_id, port_id, PHY_F_FORCE);
	if (force_en == A_TRUE) {
		force_speed = ssdk_port_force_speed_get(dev_id, port_id);

		rv = fal_port_speed_set(dev_id, port_id, force_speed);
		SW_RTN_ON_ERROR(rv);

		rv = fal_port_duplex_set(dev_id, port_id, FAL_FULL_DUPLEX);
		SW_RTN_ON_ERROR(rv);
	}


	if(mac_mode == PORT_WRAPPER_SGMII_PLUS)
		mac_config.mac_mode = FAL_MAC_MODE_SGMII_PLUS;
	else if(mac_mode == PORT_WRAPPER_SGMII_CHANNEL0)
		mac_config.mac_mode = FAL_MAC_MODE_SGMII;
	else
		return SW_NOT_SUPPORTED;
	mac_config.config.sgmii.clock_mode = FAL_INTERFACE_CLOCK_MAC_MODE;
	mac_config.config.sgmii.auto_neg = !force_en;
	mac_config.config.sgmii.force_speed = force_speed;

	rv = fal_interface_mac_mode_set(dev_id, port_id, &mac_config);

	return rv;
}

static sw_error_t
qca_mht_interface_mode_init(a_uint32_t dev_id, a_uint32_t mac_mode0,
	a_uint32_t mac_mode1)
{
	sw_error_t rv = SW_OK;

	rv = _qca_mht_interface_mode_init(dev_id, SSDK_PHYSICAL_PORT0, mac_mode0);
	SW_RTN_ON_ERROR(rv);

	rv = _qca_mht_interface_mode_init(dev_id, SSDK_PHYSICAL_PORT5, mac_mode1);
	SW_RTN_ON_ERROR(rv);

	if (A_TRUE == ssdk_port_feature_get(dev_id, SSDK_PHYSICAL_PORT0, PHY_F_FORCE)) {
		rv = fal_port_txmac_status_set(dev_id, SSDK_PHYSICAL_PORT0, A_TRUE);
		SW_RTN_ON_ERROR(rv);
		rv = fal_port_rxmac_status_set(dev_id, SSDK_PHYSICAL_PORT0, A_TRUE);
		SW_RTN_ON_ERROR(rv);
	}

	if (A_TRUE == ssdk_port_feature_get(dev_id, SSDK_PHYSICAL_PORT5, PHY_F_FORCE)) {
		rv = fal_port_txmac_status_set(dev_id, SSDK_PHYSICAL_PORT5, A_TRUE);
		SW_RTN_ON_ERROR(rv);
		rv = fal_port_rxmac_status_set(dev_id, SSDK_PHYSICAL_PORT5, A_TRUE);
	}

	return rv;
}

int qca_mht_hw_init(ssdk_init_cfg *cfg, a_uint32_t dev_id)
{
	int ret = 0;

	ret = qca_mht_work_mode_init(dev_id);
	SW_RTN_ON_ERROR(ret);

	ret = qca_switch_init(dev_id);
	SW_RTN_ON_ERROR(ret);

#ifdef IN_PORTVLAN
	ssdk_portvlan_init(dev_id);
#endif
	ret = qca_mht_interface_mode_init(dev_id, cfg->mac_mode, cfg->mac_mode1);
	SW_RTN_ON_ERROR(ret);

	ret = ssdk_mht_pinctrl_init(dev_id);

	return ret;
}

/**
 * @}
 */
