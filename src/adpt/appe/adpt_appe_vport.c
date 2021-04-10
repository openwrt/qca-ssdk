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
#include "fal_vport.h"
#if defined(IN_QM)
#include "fal_qm.h"
#endif
#include "appe_l2_vp_reg.h"
#include "appe_l2_vp.h"
#include "appe_counter_reg.h"
#include "appe_counter.h"
#include "appe_portvlan_reg.h"
#include "appe_portvlan.h"
#include "hppe_portctrl_reg.h"
#include "hppe_portctrl.h"

#include "adpt.h"

sw_error_t
adpt_appe_vport_physical_port_id_get(a_uint32_t dev_id,
		fal_port_t vport_id, fal_port_t *phyport_id)
{
	sw_error_t rv = SW_OK;
	a_uint32_t pport_id = 0;
	a_uint32_t vport_value = FAL_PORT_ID_VALUE(vport_id);

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(phyport_id);

	rv = appe_l2_vp_port_tbl_physical_port_get(dev_id, vport_value, &pport_id);
	SW_RTN_ON_ERROR(rv);

	*phyport_id = FAL_PORT_ID(FAL_PORT_TYPE_PPORT, pport_id);

	return rv;
}

sw_error_t
adpt_appe_vport_physical_port_id_set(a_uint32_t dev_id,
		fal_port_t vport_id, fal_port_t phyport_id)
{
	sw_error_t rv = SW_OK;
	a_uint32_t pport_id = 0;
	a_uint32_t vport_value = 0;
#if defined(IN_QM)
	adpt_api_t *p_adpt_api = NULL;
	a_uint32_t queue_base = 0;
	a_uint8_t profile = 0;
	fal_ucast_queue_dest_t queue_dest;
#endif

	ADPT_DEV_ID_CHECK(dev_id);
	vport_value = FAL_PORT_ID_VALUE(vport_id);
	pport_id = FAL_PORT_ID_VALUE(phyport_id);

	rv = appe_l2_vp_port_tbl_physical_port_set(dev_id, vport_value, pport_id);
	SW_RTN_ON_ERROR(rv);

#if defined(IN_QM)
	p_adpt_api = adpt_api_ptr_get(dev_id);
	ADPT_NULL_POINT_CHECK(p_adpt_api);
	ADPT_NULL_POINT_CHECK(p_adpt_api->adpt_ucast_queue_base_profile_set);
	ADPT_NULL_POINT_CHECK(p_adpt_api->adpt_ucast_queue_base_profile_get);

	aos_mem_zero(&queue_dest, sizeof(fal_ucast_queue_dest_t));

	/* configure the queue base of vport with the queue base of physical port
	 * the source profile id 0 is selected by default.
	 * */
	queue_dest.src_profile = 0;
	queue_dest.dst_port = pport_id;
	rv = p_adpt_api->adpt_ucast_queue_base_profile_get(dev_id,
			&queue_dest, &queue_base, &profile);
	SW_RTN_ON_ERROR(rv);

	queue_dest.dst_port = vport_value;
	rv = p_adpt_api->adpt_ucast_queue_base_profile_set(dev_id,
			&queue_dest, queue_base, profile);
#endif

	return rv;
}

sw_error_t
adpt_appe_vport_state_check_get(a_uint32_t dev_id, fal_port_t port_id, fal_vport_state_t *vp_state)
{
	sw_error_t rv = SW_OK;
	union l2_vp_port_tbl_u l2_vp_port_tbl;
	a_uint32_t port_value = FAL_PORT_ID_VALUE(port_id);

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(vp_state);

	aos_mem_zero(&l2_vp_port_tbl, sizeof(union l2_vp_port_tbl_u));

	rv = appe_l2_vp_port_tbl_get(dev_id, port_value, &l2_vp_port_tbl);
	SW_RTN_ON_ERROR(rv);

	vp_state->check_en = l2_vp_port_tbl.bf.vp_state_check_en;
	vp_state->vp_type = l2_vp_port_tbl.bf.vp_type;
	vp_state->vp_active = l2_vp_port_tbl.bf.vp_context_active;
	vp_state->eg_data_valid = l2_vp_port_tbl.bf.vp_eg_data_valid;

	return rv;
}

sw_error_t
adpt_appe_vport_state_check_set(a_uint32_t dev_id, fal_port_t port_id, fal_vport_state_t *vp_state)
{
	sw_error_t rv = SW_OK;
	union l2_vp_port_tbl_u l2_vp_port_tbl;
	a_uint32_t port_value = FAL_PORT_ID_VALUE(port_id);

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(vp_state);

	aos_mem_zero(&l2_vp_port_tbl, sizeof(union l2_vp_port_tbl_u));

	rv = appe_l2_vp_port_tbl_get(dev_id, port_value, &l2_vp_port_tbl);
	SW_RTN_ON_ERROR(rv);

	l2_vp_port_tbl.bf.vp_state_check_en = vp_state->check_en;
	l2_vp_port_tbl.bf.vp_type = vp_state->vp_type;
	l2_vp_port_tbl.bf.vp_context_active = vp_state->vp_active;
	l2_vp_port_tbl.bf.vp_eg_data_valid = vp_state->eg_data_valid;

	rv = appe_l2_vp_port_tbl_set(dev_id, port_value, &l2_vp_port_tbl);

	return rv;
}

sw_error_t
adpt_appe_vport_cnt_cfg_set(a_uint32_t dev_id, fal_port_t port_id, fal_vport_cnt_cfg_t *cnt_cfg)
{
	sw_error_t rv = SW_OK;
	union port_vp_rx_cnt_mode_tbl_u port_vp_rx_cnt_mode_tbl;
	union eg_vp_tbl_u eg_vp_tbl;
	a_uint32_t port_value = FAL_PORT_ID_VALUE(port_id);

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(cnt_cfg);

	aos_mem_zero(&port_vp_rx_cnt_mode_tbl, sizeof(union port_vp_rx_cnt_mode_tbl_u));
	aos_mem_zero(&eg_vp_tbl, sizeof(union eg_vp_tbl_u));

	/* set RX counter configs */
	rv = appe_port_vp_rx_cnt_mode_tbl_get(dev_id, port_value/32, &port_vp_rx_cnt_mode_tbl);
	SW_RTN_ON_ERROR(rv);

	switch (cnt_cfg->rx_cnt_mode) {
		case FAL_VPORT_CNT_MODE_IP_PKT:
			port_vp_rx_cnt_mode_tbl.bf.cnt_mode &= ~BIT(port_value%32);
			break;
		case FAL_VPORT_CNT_MODE_FULL_PKT:
			port_vp_rx_cnt_mode_tbl.bf.cnt_mode |= BIT(port_value%32);
			break;
		default:
			SSDK_ERROR("Unsupported rx_cnt_mode: %d\n", cnt_cfg->rx_cnt_mode);
			return SW_BAD_PARAM;
	}

	rv = appe_port_vp_rx_cnt_mode_tbl_set(dev_id, port_value/32, &port_vp_rx_cnt_mode_tbl);
	SW_RTN_ON_ERROR(rv);

	/* set TX counter configs */
	rv = appe_egress_vp_tbl_get(dev_id, port_value, &eg_vp_tbl);
	SW_RTN_ON_ERROR(rv);

	eg_vp_tbl.bf.cnt_mode = cnt_cfg->tx_cnt_mode;

	rv = appe_egress_vp_tbl_set(dev_id, port_value, &eg_vp_tbl);
	SW_RTN_ON_ERROR(rv);

	return rv;
}

sw_error_t
adpt_appe_vport_cnt_cfg_get(a_uint32_t dev_id, fal_port_t port_id, fal_vport_cnt_cfg_t *cnt_cfg)
{
	sw_error_t rv = SW_OK;
	union port_vp_rx_cnt_mode_tbl_u port_vp_rx_cnt_mode_tbl;
	union eg_vp_tbl_u eg_vp_tbl;
	a_uint32_t port_value = FAL_PORT_ID_VALUE(port_id);

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(cnt_cfg);

	aos_mem_zero(&port_vp_rx_cnt_mode_tbl, sizeof(union port_vp_rx_cnt_mode_tbl_u));
	aos_mem_zero(&eg_vp_tbl, sizeof(union eg_vp_tbl_u));

	/* get RX counter configs */
	rv = appe_port_vp_rx_cnt_mode_tbl_get(dev_id, port_value/32, &port_vp_rx_cnt_mode_tbl);
	SW_RTN_ON_ERROR(rv);

	if (port_vp_rx_cnt_mode_tbl.bf.cnt_mode & BIT(port_value%32))
		cnt_cfg->rx_cnt_mode = FAL_VPORT_CNT_MODE_FULL_PKT;
	else
		cnt_cfg->rx_cnt_mode = FAL_VPORT_CNT_MODE_IP_PKT;

	/* get TX counter configs */
	rv = appe_egress_vp_tbl_get(dev_id, port_value, &eg_vp_tbl);
	SW_RTN_ON_ERROR(rv);

	cnt_cfg->tx_cnt_mode = eg_vp_tbl.bf.cnt_mode;

	return rv;
}

sw_error_t
adpt_appe_vport_cnt_get(a_uint32_t dev_id, fal_port_t port_id, fal_vport_cnt_t *vp_cnt)
{
	sw_error_t rv = SW_OK;
	union port_rx_cnt_tbl_u port_rx_cnt_tbl;
	union vp_tx_counter_tbl_reg_u port_tx_cnt_tbl;
	a_uint32_t port_value = FAL_PORT_ID_VALUE(port_id);

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(vp_cnt);

	aos_mem_zero(&port_rx_cnt_tbl, sizeof(union port_rx_cnt_tbl_u));
	aos_mem_zero(&port_tx_cnt_tbl, sizeof(union vp_tx_counter_tbl_reg_u));

	rv = appe_port_rx_cnt_tbl_get(dev_id, port_value, &port_rx_cnt_tbl);
	SW_RTN_ON_ERROR(rv);

	rv = hppe_vp_tx_counter_tbl_reg_get(dev_id, port_value, &port_tx_cnt_tbl);
	SW_RTN_ON_ERROR(rv);

	vp_cnt->rx_pkt_cnt = port_rx_cnt_tbl.bf.rx_pkt_cnt;

	vp_cnt->rx_byte_cnt = ((a_uint64_t)port_rx_cnt_tbl.bf.rx_byte_cnt_1 <<
			SW_FIELD_OFFSET_IN_WORD(PORT_RX_CNT_TBL_RX_BYTE_CNT_OFFSET)) |
		port_rx_cnt_tbl.bf.rx_byte_cnt_0;

	vp_cnt->rx_drop_pkt_cnt = ((a_uint32_t)port_rx_cnt_tbl.bf.rx_drop_pkt_cnt_1 <<
		SW_FIELD_OFFSET_IN_WORD(PORT_RX_CNT_TBL_RX_DROP_PKT_CNT_OFFSET)) |
		port_rx_cnt_tbl.bf.rx_drop_pkt_cnt_0;

	vp_cnt->rx_drop_byte_cnt = ((a_uint64_t)port_rx_cnt_tbl.bf.rx_drop_byte_cnt_1 <<
		SW_FIELD_OFFSET_IN_WORD(PORT_RX_CNT_TBL_RX_DROP_BYTE_CNT_OFFSET)) |
		port_rx_cnt_tbl.bf.rx_drop_byte_cnt_0;

	vp_cnt->tx_pkt_cnt = port_tx_cnt_tbl.bf.tx_packets;
	vp_cnt->tx_byte_cnt = ((a_uint64_t)port_tx_cnt_tbl.bf.tx_bytes_1 <<
		SW_FIELD_OFFSET_IN_WORD(VP_TX_COUNTER_TBL_REG_TX_BYTES_OFFSET)) |
		port_tx_cnt_tbl.bf.tx_bytes_0;

	return rv;
}

sw_error_t
adpt_appe_vport_cnt_flush(a_uint32_t dev_id, fal_port_t port_id)
{
	sw_error_t rv = SW_OK;
	union port_rx_cnt_tbl_u port_rx_cnt_tbl;
	union vp_tx_counter_tbl_reg_u port_tx_cnt_tbl;
	a_uint32_t port_value = FAL_PORT_ID_VALUE(port_id);

	ADPT_DEV_ID_CHECK(dev_id);

	aos_mem_zero(&port_rx_cnt_tbl, sizeof(union port_rx_cnt_tbl_u));
	aos_mem_zero(&port_tx_cnt_tbl, sizeof(union vp_tx_counter_tbl_reg_u));

	rv = appe_port_rx_cnt_tbl_set(dev_id, port_value, &port_rx_cnt_tbl);
	SW_RTN_ON_ERROR(rv);

	rv = hppe_vp_tx_counter_tbl_reg_set(dev_id, port_value, &port_tx_cnt_tbl);

	return rv;
}

void adpt_appe_vport_func_bitmap_init(a_uint32_t dev_id)
{
	adpt_api_t *p_adpt_api = NULL;

	p_adpt_api = adpt_api_ptr_get(dev_id);

	if(p_adpt_api == NULL)
		return;

	p_adpt_api->adpt_vport_func_bitmap = 0;

	return;
}

static void adpt_appe_vport_func_unregister(a_uint32_t dev_id, adpt_api_t *p_adpt_api)
{
	if(p_adpt_api == NULL)
		return;

	p_adpt_api->adpt_vport_physical_port_id_set = NULL;
	p_adpt_api->adpt_vport_physical_port_id_get = NULL;
	p_adpt_api->adpt_vport_state_check_set = NULL;
	p_adpt_api->adpt_vport_state_check_get = NULL;
	p_adpt_api->adpt_vport_cnt_cfg_set = NULL;
	p_adpt_api->adpt_vport_cnt_cfg_get = NULL;
	p_adpt_api->adpt_vport_cnt_flush = NULL;
	p_adpt_api->adpt_vport_cnt_get = NULL;

	return;
}

sw_error_t
adpt_appe_vport_init(a_uint32_t dev_id)
{
	adpt_api_t *p_adpt_api = NULL;

	p_adpt_api = adpt_api_ptr_get(dev_id);

	ADPT_NULL_POINT_CHECK(p_adpt_api);

	adpt_appe_vport_func_unregister(dev_id, p_adpt_api);

	if (p_adpt_api->adpt_vport_func_bitmap & BIT(FUNC_VPORT_PHYSICAL_PORT_SET))
		p_adpt_api->adpt_vport_physical_port_id_set =
			adpt_appe_vport_physical_port_id_set;
	if (p_adpt_api->adpt_vport_func_bitmap & BIT(FUNC_VPORT_PHYSICAL_PORT_GET))
		p_adpt_api->adpt_vport_physical_port_id_get =
			adpt_appe_vport_physical_port_id_get;
	if (p_adpt_api->adpt_vport_func_bitmap & BIT(FUNC_VPORT_STATE_CHECK_SET))
		p_adpt_api->adpt_vport_state_check_set =
			adpt_appe_vport_state_check_set;
	if (p_adpt_api->adpt_vport_func_bitmap & BIT(FUNC_VPORT_STATE_CHECK_GET))
		p_adpt_api->adpt_vport_state_check_get =
			adpt_appe_vport_state_check_get;
	if (p_adpt_api->adpt_vport_func_bitmap & BIT(FUNC_VPORT_CNT_CFG_SET))
		p_adpt_api->adpt_vport_cnt_cfg_set = adpt_appe_vport_cnt_cfg_set;
	if (p_adpt_api->adpt_vport_func_bitmap & BIT(FUNC_VPORT_CNT_CFG_GET))
		p_adpt_api->adpt_vport_cnt_cfg_get = adpt_appe_vport_cnt_cfg_get;
	if (p_adpt_api->adpt_vport_func_bitmap & BIT(FUNC_VPORT_CNT_FLUSH))
		p_adpt_api->adpt_vport_cnt_flush = adpt_appe_vport_cnt_flush;
	if (p_adpt_api->adpt_vport_func_bitmap & BIT(FUNC_VPORT_CNT_GET))
		p_adpt_api->adpt_vport_cnt_get = adpt_appe_vport_cnt_get;

	return SW_OK;
}

/**
 * @}
 */
