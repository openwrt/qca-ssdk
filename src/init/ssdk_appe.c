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

#include "ssdk_init.h"
#include "ssdk_hppe.h"
#include "ssdk_clk.h"

sw_error_t qca_appe_hw_init(ssdk_init_cfg *cfg, a_uint32_t dev_id)
{
	sw_error_t rv = SW_OK;

	/* reset ppe */
	ssdk_ppe_reset_init();

	rv = qca_switch_init(dev_id);
	SW_RTN_ON_ERROR(rv);

#if 0
#if defined(IN_BM)
	rv = qca_appe_bm_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#if defined(IN_QM)
	rv = qca_appe_qm_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#endif
#if defined(IN_QOS)
	rv = qca_hppe_qos_scheduler_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#if 0
#if defined(IN_BM) && defined(IN_QOS)
	rv = qca_appe_tdm_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#endif

#if defined(IN_FDB)
	rv= qca_hppe_fdb_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#if defined(IN_VSI)
	rv= qca_hppe_vsi_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#if defined(IN_PORTVLAN)
	rv = qca_hppe_portvlan_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#if 0
#if defined(IN_PORTCONTROL)
	rv = qca_appe_portctrl_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#if defined(IN_POLICER)
	rv = qca_appe_policer_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#if defined(IN_SHAPER)
	rv = qca_appe_shaper_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#endif
#if defined(IN_FLOW)
	rv = qca_hppe_flow_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#if 0
#if defined(IN_ACL)
	rv = qca_hppe_acl_byp_intf_mac_learn(dev_id);
	SW_RTN_ON_ERROR(rv);
#if defined(IN_PTP)
	rv = qca_hppe_acl_remark_ptp_servcode(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif
#endif
#endif
	rv = qca_hppe_interface_mode_init(dev_id, cfg->mac_mode, cfg->mac_mode1,
				cfg->mac_mode2);
	SW_RTN_ON_ERROR(rv);
#if defined(IN_CTRLPKT)
	rv = qca_hppe_ctlpkt_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif

	return rv;
}
