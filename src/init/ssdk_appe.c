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
#include "ssdk_dts.h"
#include "adpt.h"
#include "fal.h"

#if defined(IN_BM) && defined(IN_QOS)
fal_port_scheduler_cfg_t appe_port_scheduler0_tbl[] = {
	{0xcf, 6, 5},
	{0x9f, 7, 6},
	{0x3f, 1, 7},
	{0x3f, 5, 6},
	{0xbd, 0, 1},
	{0xdd, 6, 5},
	{0xde, 2, 0},
	{0xde, 6, 5},
	{0x9f, 0, 6},
	{0xbb, 5, 2},
	{0xfa, 6, 0},
	{0xbe, 5, 6},
	{0x9f, 0, 5},
	{0xde, 6, 0},
	{0x7e, 5, 7},
	{0x5f, 6, 5},
	{0x9f, 7, 6},
	{0xbe, 3, 0},
	{0xbe, 5, 6},
	{0xb7, 0, 3},
	{0xd7, 6, 5},
	{0xde, 4, 0},
	{0xde, 6, 5},
	{0x9f, 0, 6},
	{0xaf, 5, 4},
	{0xee, 6, 0},
	{0xbe, 1, 6},
	{0x9f, 2, 5},
	{0xde, 6, 0},
	{0x7e, 5, 7},
	{0x5f, 0, 5},
	{0x9f, 3, 6},
	{0xbe, 5, 0},
	{0xbe, 7, 6},
	{0xbd, 0, 1},
	{0xdd, 6, 5},
	{0x9f, 0, 6},
	{0x9f, 7, 5},
	{0xde, 6, 0},
	{0xfa, 5, 2},
	{0xdb, 0, 5},
	{0x9f, 7, 6},
	{0x9f, 0, 5},
	{0x9f, 1, 6},
	{0xbe, 5, 0},
	{0xde, 6, 5},
	{0x9f, 0, 6},
	{0x9f, 2, 5},
	{0x9f, 0, 6},
	{0xbe, 5, 0},
	{0xbe, 6, 5},
	{0x9f, 3, 6},
	{0x9f, 0, 5},
	{0x9f, 4, 6},
	{0xbe, 5, 0},
	{0x7e, 6, 7},
	{0x77, 5, 3},
	{0xf6, 6, 0},
	{0xee, 5, 4},
};

fal_port_tdm_tick_cfg_t appe_port_tdm0_tbl[] = {
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 4},
	{1, FAL_PORT_TDB_DIR_INGRESS, 5},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 1},
	{1, FAL_PORT_TDB_DIR_EGRESS, 5},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 1},
	{1, FAL_PORT_TDB_DIR_INGRESS, 6},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 7},
	{1, FAL_PORT_TDB_DIR_EGRESS, 6},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 7},
	{1, FAL_PORT_TDB_DIR_INGRESS, 5},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 2},
	{1, FAL_PORT_TDB_DIR_EGRESS, 5},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 2},
	{1, FAL_PORT_TDB_DIR_INGRESS, 6},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{0, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 6},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{0, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 5},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 3},
	{1, FAL_PORT_TDB_DIR_EGRESS, 5},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 3},
	{1, FAL_PORT_TDB_DIR_INGRESS, 6},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 7},
	{1, FAL_PORT_TDB_DIR_EGRESS, 6},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 7},
	{1, FAL_PORT_TDB_DIR_INGRESS, 5},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 4},
	{1, FAL_PORT_TDB_DIR_EGRESS, 5},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 4},
	{1, FAL_PORT_TDB_DIR_INGRESS, 6},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 1},
	{1, FAL_PORT_TDB_DIR_EGRESS, 6},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 1},
	{1, FAL_PORT_TDB_DIR_INGRESS, 5},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{0, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 5},
	{1, FAL_PORT_TDB_DIR_INGRESS,0},
	{0, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 6},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 2},
	{1, FAL_PORT_TDB_DIR_EGRESS, 6},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 2},
	{1, FAL_PORT_TDB_DIR_INGRESS, 5},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{0, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 5},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{0, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 6},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 3},
	{1, FAL_PORT_TDB_DIR_EGRESS, 6},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 3},
	{1, FAL_PORT_TDB_DIR_INGRESS, 5},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 7},
	{1, FAL_PORT_TDB_DIR_EGRESS, 5},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 7},
	{1, FAL_PORT_TDB_DIR_INGRESS, 6},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 4},
	{1, FAL_PORT_TDB_DIR_EGRESS, 6},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 4},
	{1, FAL_PORT_TDB_DIR_INGRESS, 5},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 1},
	{1, FAL_PORT_TDB_DIR_EGRESS, 5},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 1},
	{1, FAL_PORT_TDB_DIR_INGRESS, 6},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{0, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 6},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{0, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 5},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 2},
	{1, FAL_PORT_TDB_DIR_EGRESS, 5},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 2},
	{1, FAL_PORT_TDB_DIR_INGRESS, 6},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 7},
	{1, FAL_PORT_TDB_DIR_EGRESS, 6},
	{1, FAL_PORT_TDB_DIR_INGRESS, 0},
	{1, FAL_PORT_TDB_DIR_EGRESS, 7},
	{1, FAL_PORT_TDB_DIR_INGRESS, 5},
	{1, FAL_PORT_TDB_DIR_EGRESS, 0},
	{1, FAL_PORT_TDB_DIR_INGRESS, 3},
	{1, FAL_PORT_TDB_DIR_EGRESS, 5},
	{1, FAL_PORT_TDB_DIR_INGRESS, 6},
	{1, FAL_PORT_TDB_DIR_EGRESS, 3},
	{1, FAL_PORT_TDB_DIR_INGRESS, 4},
	{1, FAL_PORT_TDB_DIR_EGRESS, 6},
};

static sw_error_t
qca_appe_tdm_hw_init(a_uint32_t dev_id)
{
	adpt_api_t *p_api;
	a_uint32_t i = 0;
	a_uint32_t num;
	fal_port_tdm_ctrl_t tdm_ctrl;
	fal_port_scheduler_cfg_t *scheduler_cfg;
	fal_port_tdm_tick_cfg_t *bm_cfg;
	a_uint8_t tm_tick_mode, bm_tick_mode;

	SW_RTN_ON_NULL(p_api = adpt_api_ptr_get(dev_id));
	SW_RTN_ON_NULL(p_api->adpt_port_scheduler_cfg_set);
	SW_RTN_ON_NULL(p_api->adpt_tdm_tick_num_set);

	tm_tick_mode = ssdk_tm_tick_mode_get(dev_id);
	bm_tick_mode = ssdk_bm_tick_mode_get(dev_id);

	if (tm_tick_mode == 0) {
		num = sizeof(appe_port_scheduler0_tbl) /
				sizeof(fal_port_scheduler_cfg_t);
		scheduler_cfg = appe_port_scheduler0_tbl;

	} else {
		return SW_BAD_VALUE;
	}

	for (i = 0; i < num; i++) {
		p_api->adpt_port_scheduler_cfg_set(dev_id, i, &scheduler_cfg[i]);
	}
	p_api->adpt_tdm_tick_num_set(dev_id, num);
	SSDK_INFO("appe scheduler tdm setup num=%d\n", num);

	SW_RTN_ON_NULL(p_api->adpt_port_tdm_tick_cfg_set);
	SW_RTN_ON_NULL(p_api->adpt_port_tdm_ctrl_set);

	if (bm_tick_mode == 0) {
		num = sizeof(appe_port_tdm0_tbl) /
				sizeof(fal_port_tdm_tick_cfg_t);
		bm_cfg = appe_port_tdm0_tbl;
	} else {
		return SW_BAD_VALUE;
	}

	for (i = 0; i < num; i++) {
		p_api->adpt_port_tdm_tick_cfg_set(dev_id, i, &bm_cfg[i]);
	}
	tdm_ctrl.enable = A_TRUE;
	tdm_ctrl.offset = A_FALSE;
	tdm_ctrl.depth = num;
	p_api->adpt_port_tdm_ctrl_set(dev_id, &tdm_ctrl);
	SSDK_INFO("appe tdm setup num=%d\n", num);

	return SW_OK;
}
#endif

#if defined(IN_PORTCONTROL)
static sw_error_t
qca_appe_portctrl_hw_init(a_uint32_t dev_id)
{
	a_uint32_t i = 0;
	a_uint32_t port_max = SSDK_PHYSICAL_PORT7;
	a_bool_t force_port;

	for(i = SSDK_PHYSICAL_PORT1; i < port_max; i++) {
		force_port = ssdk_port_feature_get(dev_id, i,
			PHY_F_FORCE);
		if (force_port == A_TRUE) {
			fal_port_txmac_status_set(dev_id, i, A_TRUE);
			fal_port_rxmac_status_set(dev_id, i, A_TRUE);
			fal_port_rxfc_status_set(dev_id, i, A_TRUE);
			fal_port_txfc_status_set(dev_id, i, A_TRUE);
			SSDK_INFO("appe port %d is force port\n", i);
		} else {
			fal_port_txmac_status_set(dev_id, i, A_FALSE);
			fal_port_rxmac_status_set(dev_id, i, A_FALSE);
			fal_port_rxfc_status_set(dev_id, i, A_FALSE);
			fal_port_txfc_status_set(dev_id, i, A_FALSE);
		}
		fal_port_max_frame_size_set(dev_id, i, SSDK_MAX_FRAME_SIZE);
	}
	SSDK_INFO("appe portctrl initialization\n");

	return SW_OK;
}
#endif

sw_error_t qca_appe_hw_init(ssdk_init_cfg *cfg, a_uint32_t dev_id)
{
	sw_error_t rv = SW_OK;

	if(!ssdk_is_emulation(dev_id)) {
		/* reset ppe */
		ssdk_ppe_reset_init();
	}

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

#if defined(IN_BM) && defined(IN_QOS)
	rv = qca_appe_tdm_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
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

	rv = qca_hppe_interface_mode_init(dev_id, cfg->mac_mode,
		cfg->mac_mode1, cfg->mac_mode2);
	SW_RTN_ON_ERROR(rv);

#if defined(IN_PORTCONTROL)
	rv = qca_appe_portctrl_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif

#if 0
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

#if defined(IN_CTRLPKT)
	rv = qca_hppe_ctlpkt_hw_init(dev_id);
	SW_RTN_ON_ERROR(rv);
#endif

	return rv;
}
