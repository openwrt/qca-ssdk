/*
 * Copyright (c) 2020, The Linux Foundation. All rights reserved.
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

#include "sw.h"
#include "appe_global_reg.h"
#include "appe_global.h"
#include "adpt.h"
#include "adpt_appe_portctrl.h"

sw_error_t
_adpt_appe_port_mux_mac_set(a_uint32_t dev_id, fal_port_t port_id,
	a_uint32_t port_type)
{
	sw_error_t rv = SW_OK;
	a_uint32_t mode0, mode1;
	a_uint32_t mux_mac_type;
	union appe_port_mux_ctrl_u appe_port_mux_ctrl;

	ADPT_DEV_ID_CHECK(dev_id);
	memset(&appe_port_mux_ctrl, 0, sizeof(appe_port_mux_ctrl));

	if (port_type == PORT_GMAC_TYPE) {
		mux_mac_type = APPE_PORT_MUX_MAC_TYPE;
	} else if (port_type == PORT_XGMAC_TYPE) {
		mux_mac_type = APPE_PORT_MUX_XMAC_TYPE;
	} else {
		return SW_BAD_VALUE;
	}

	rv = appe_port_mux_ctrl_get(dev_id, &appe_port_mux_ctrl);
	SW_RTN_ON_ERROR (rv);

	switch (port_id) {
		case SSDK_PHYSICAL_PORT1:
			appe_port_mux_ctrl.bf.port1_mac_sel = mux_mac_type;
			break;
		case SSDK_PHYSICAL_PORT2:
			appe_port_mux_ctrl.bf.port2_mac_sel = mux_mac_type;
			break;
		case SSDK_PHYSICAL_PORT3:
			appe_port_mux_ctrl.bf.port3_mac_sel = mux_mac_type;
			break;
		case SSDK_PHYSICAL_PORT4:
			appe_port_mux_ctrl.bf.port4_mac_sel = mux_mac_type;
			break;
		case SSDK_PHYSICAL_PORT5:
			mode0 = ssdk_dt_global_get_mac_mode(dev_id,
						SSDK_UNIPHY_INSTANCE0);
			mode1 = ssdk_dt_global_get_mac_mode(dev_id,
						SSDK_UNIPHY_INSTANCE1);
			appe_port_mux_ctrl.bf.port5_mac_sel = mux_mac_type;
			if ((((mode0 == PORT_WRAPPER_PSGMII) ||
				(mode0 == PORT_WRAPPER_PSGMII_FIBER)) &&
				(mode1 == PORT_WRAPPER_MAX)) ||
				(((mode0 == PORT_WRAPPER_SGMII4_RGMII4) ||
				(mode0 == PORT_WRAPPER_SGMII_CHANNEL4)) &&
				(mode1 == PORT_WRAPPER_MAX))) {
			    	appe_port_mux_ctrl.bf.port5_pcs_sel =
					APPE_PORT5_MUX_PCS_UNIPHY0;
			}
			if (mode1 != PORT_WRAPPER_MAX) {
				appe_port_mux_ctrl.bf.port5_pcs_sel =
					APPE_PORT5_MUX_PCS_UNIPHY1;
			}
			break;
		case SSDK_PHYSICAL_PORT6:
			appe_port_mux_ctrl.bf.port6_mac_sel = mux_mac_type;
			break;
		default:
			break;
	}

	rv = appe_port_mux_ctrl_set(dev_id, &appe_port_mux_ctrl);
	SW_RTN_ON_ERROR (rv);

	SSDK_INFO("appe port %d mac type is %d\n", port_id, port_type);

	return rv;
}
