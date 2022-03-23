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
 * @defgroup mht_port_ctrl MHT_PORT_CONTROL
 * @{
 */
#include "sw.h"
#include "hsl.h"
#include "hsl_dev.h"
#include "hsl_port_prop.h"
#include "mht_port_ctrl.h"
#include "mht_reg.h"
#include "isisc_reg.h"

#define PORT0_MAX_VIRT_RING	8
#define PORT5_MAX_VIRT_RING	16

/*
PORT0 egress 6 queues
PORT1~4 egress 4 queues
PORT5 egress 6 queues
*/
static a_uint32_t port_queue[6] = { 6, 4, 4, 4, 4, 6 };

static sw_error_t
_mht_port_congestion_drop_set (a_uint32_t dev_id, fal_port_t port_id,
		a_uint32_t queue_id, a_bool_t enable)
{
	sw_error_t rv = SW_OK;
	a_uint32_t val = 0, offset = 0, field = 0;

	HSL_DEV_ID_CHECK (dev_id);

	if (A_TRUE != hsl_port_prop_check (dev_id, port_id, HSL_PP_INCL_CPU))
	{
		return SW_BAD_PARAM;
	}

	if (queue_id >= port_queue[port_id])
	{
		return SW_BAD_PARAM;
	}

	if (port_id != 0)
		offset = port_id * 4 + 2;
	offset += queue_id;

	if (A_TRUE == enable)
	{
		field = 1 << offset;
	}
	else if (A_FALSE == enable)
	{
		field = ~(1 << offset);
	}
	else
	{
		return SW_BAD_PARAM;
	}

	HSL_REG_ENTRY_GET (rv, dev_id, FLOW_CONGE_DROP_CTRL0, 0,
			(a_uint8_t *) (&val), sizeof (a_uint32_t));
	if (A_TRUE == enable)
	{
		val = val | field;
	}
	else
	{
		val = val & field;
	}

	HSL_REG_ENTRY_SET (rv, dev_id, FLOW_CONGE_DROP_CTRL0, 0,
			(a_uint8_t *) (&val), sizeof (a_uint32_t));
	return rv;
}

static sw_error_t
_mht_port_congestion_drop_get (a_uint32_t dev_id, fal_port_t port_id,
		a_uint32_t queue_id, a_bool_t * enable)
{
	sw_error_t rv = SW_OK;
	a_uint32_t val, offset = 0;

	HSL_DEV_ID_CHECK (dev_id);

	if (A_TRUE != hsl_port_prop_check (dev_id, port_id, HSL_PP_INCL_CPU))
	{
		return SW_BAD_PARAM;
	}

	if (queue_id >= port_queue[port_id])
	{
		return SW_BAD_PARAM;
	}

	if (port_id != 0)
		offset = port_id * 4 + 2;
	offset += queue_id;

	HSL_REG_ENTRY_GET (rv, dev_id, FLOW_CONGE_DROP_CTRL0, 0,
			(a_uint8_t *) (&val), sizeof (a_uint32_t));
	val = (val >> offset) & 0x1;
	if (val == 0)
	{
		*enable = A_FALSE;
	}
	else if (val == 1)
	{
		*enable = A_TRUE;
	}
	return rv;
}

static sw_error_t
_mht_ring_flow_ctrl_thres_set (a_uint32_t dev_id, a_uint32_t ring_id,
		a_uint16_t on_thres, a_uint16_t off_thres)
{
	sw_error_t rv;
	a_uint32_t val = 0;

	HSL_DEV_ID_CHECK (dev_id);

	if (ring_id >= PORT5_MAX_VIRT_RING)
	{
		return SW_BAD_PARAM;
	}

	if (on_thres > off_thres || on_thres == 0)
	{
		return SW_BAD_PARAM;
	}

	if (ring_id < PORT0_MAX_VIRT_RING) {
		SW_SET_REG_BY_FIELD (RING_FLOW_CTRL_THRES, XON, on_thres, val);
		SW_SET_REG_BY_FIELD (RING_FLOW_CTRL_THRES, XOFF, off_thres, val);
		HSL_REG_ENTRY_SET (rv, dev_id, RING_FLOW_CTRL_THRES, ring_id,
				(a_uint8_t *) (&val), sizeof (a_uint32_t));
	} else {
		SW_SET_REG_BY_FIELD (PORT5_RING_FLOW_CTRL_THRES, XON, on_thres, val);
		SW_SET_REG_BY_FIELD (PORT5_RING_FLOW_CTRL_THRES, XOFF, off_thres, val);
		HSL_REG_ENTRY_SET (rv, dev_id, PORT5_RING_FLOW_CTRL_THRES,
				(ring_id-PORT0_MAX_VIRT_RING),
				(a_uint8_t *) (&val), sizeof (a_uint32_t));
	}

	return rv;
}

static sw_error_t
_mht_ring_flow_ctrl_thres_get (a_uint32_t dev_id, a_uint32_t ring_id,
		a_uint16_t * on_thres, a_uint16_t * off_thres)
{

	sw_error_t rv;
	a_uint32_t val = 0;
	a_uint16_t hthres, lthres;

	HSL_DEV_ID_CHECK (dev_id);

	if (ring_id >= PORT5_MAX_VIRT_RING)
	{
		return SW_BAD_PARAM;
	}

	if (ring_id < PORT0_MAX_VIRT_RING) {
		HSL_REG_ENTRY_GET (rv, dev_id, RING_FLOW_CTRL_THRES, ring_id,
				(a_uint8_t *) (&val), sizeof (a_uint32_t));

		SW_GET_FIELD_BY_REG (RING_FLOW_CTRL_THRES, XON, hthres, val);
		SW_GET_FIELD_BY_REG (RING_FLOW_CTRL_THRES, XOFF, lthres, val);
	} else {
		HSL_REG_ENTRY_GET (rv, dev_id, PORT5_RING_FLOW_CTRL_THRES,
				(ring_id-PORT0_MAX_VIRT_RING),
				(a_uint8_t *) (&val), sizeof (a_uint32_t));

		SW_GET_FIELD_BY_REG (PORT5_RING_FLOW_CTRL_THRES, XON, hthres, val);
		SW_GET_FIELD_BY_REG (PORT5_RING_FLOW_CTRL_THRES, XOFF, lthres, val);
	}

	*on_thres = hthres;
	*off_thres = lthres;

	return rv;
}

#define MHT_RX_DMA_RING_PAUSE_DEBUG_ADDR	0x28
static sw_error_t
_mht_ring_flow_ctrl_status_get(a_uint32_t dev_id, a_uint32_t ring_id, a_bool_t *status)
{

	sw_error_t rv = SW_OK;
	a_uint32_t val = 0;

	HSL_DEV_ID_CHECK (dev_id);
	if (ring_id >= PORT5_MAX_VIRT_RING) {
		return SW_BAD_PARAM;
	}

	val = MHT_RX_DMA_RING_PAUSE_DEBUG_ADDR;
	HSL_REG_ENTRY_SET(rv, dev_id, SWITCH_QM_DEBUG_ADDR, 0,
			(a_uint8_t *)(&val), sizeof(a_uint32_t));

	HSL_REG_ENTRY_GET(rv, dev_id, SWITCH_QM_DEBUG_DATA, 0,
			(a_uint8_t *)(&val), sizeof(a_uint32_t));

	*status = (val >> ring_id) & 1;

	return rv;
}

static sw_error_t
_mht_ring_union_set(a_uint32_t dev_id, a_bool_t enable)
{
	sw_error_t rv;
	a_uint32_t val;

	HSL_DEV_ID_CHECK(dev_id);

	val = enable ? 1 : 0;
	HSL_REG_FIELD_SET(rv, dev_id, PORT0_PORT5_RING_UNION, 0, EN,
			(a_uint8_t *)(&val), sizeof(a_uint32_t));

	return rv;
}

static sw_error_t
_mht_ring_union_get(a_uint32_t dev_id, a_bool_t *enable)
{
	sw_error_t rv;
	a_uint32_t val;

	HSL_DEV_ID_CHECK(dev_id);

	HSL_REG_FIELD_GET(rv, dev_id, PORT0_PORT5_RING_UNION, 0, EN,
			(a_uint8_t *)(&val), sizeof(a_uint32_t));

	*enable = val ? A_TRUE : A_FALSE;

	return rv;
}

static sw_error_t
_mht_port_flowctrl_thresh_get(a_uint32_t dev_id, fal_port_t port_id,
		a_uint16_t *on, a_uint16_t *off)
{
	sw_error_t rv;
	a_uint32_t val = 0;
	a_uint16_t hthres, lthres;

	HSL_DEV_ID_CHECK(dev_id);

	HSL_REG_ENTRY_GET(rv, dev_id, PORT_FLOC_CTRL_THRESH, port_id,
			(a_uint8_t *)(&val), sizeof(a_uint32_t));

	SW_GET_FIELD_BY_REG(PORT_FLOC_CTRL_THRESH, XON, hthres, val);
	SW_GET_FIELD_BY_REG(PORT_FLOC_CTRL_THRESH, XOFF, lthres, val);

	*on = hthres;
	*off = lthres;

	return rv;
}

static sw_error_t
_mht_port_flowctrl_thresh_set(a_uint32_t dev_id, fal_port_t port_id,
		a_uint16_t on, a_uint16_t off)
{
	sw_error_t rv;
	a_uint32_t val = 0;

	HSL_DEV_ID_CHECK(dev_id);

	SW_SET_REG_BY_FIELD(PORT_FLOC_CTRL_THRESH, XON, on, val);
	SW_SET_REG_BY_FIELD(PORT_FLOC_CTRL_THRESH, XOFF, off, val);
	HSL_REG_ENTRY_SET(rv, dev_id, PORT_FLOC_CTRL_THRESH, port_id,
			(a_uint8_t *)(&val), sizeof(a_uint32_t));

	return rv;
}

static sw_error_t
_mht_ring_flow_ctrl_config_set(a_uint32_t dev_id, a_uint32_t ring_id, a_bool_t status)
{

	sw_error_t rv = SW_OK;
	a_uint32_t val = 0;

	HSL_DEV_ID_CHECK (dev_id);
	if (ring_id >= PORT5_MAX_VIRT_RING) {
		return SW_BAD_PARAM;
	}

	HSL_REG_ENTRY_GET(rv, dev_id, SWITCH_CORE_SWITCH_RING_FC, 0,
			(a_uint8_t *)(&val), sizeof(a_uint32_t));

	val &= ~BIT(ring_id);
	val |= status << ring_id;

	HSL_REG_ENTRY_SET(rv, dev_id, SWITCH_CORE_SWITCH_RING_FC, 0,
			(a_uint8_t *)(&val), sizeof(a_uint32_t));
	return rv;
}

static sw_error_t
_mht_ring_flow_ctrl_config_get(a_uint32_t dev_id, a_uint32_t ring_id, a_bool_t *status)
{

	sw_error_t rv = SW_OK;
	a_uint32_t val = 0;

	HSL_DEV_ID_CHECK (dev_id);
	if (ring_id >= PORT5_MAX_VIRT_RING) {
		return SW_BAD_PARAM;
	}

	HSL_REG_ENTRY_GET(rv, dev_id, SWITCH_CORE_SWITCH_RING_FC, 0,
			(a_uint8_t *)(&val), sizeof(a_uint32_t));

	*status = (val & BIT(ring_id)) ? A_TRUE : A_FALSE;

	return rv;
}

/**
 * @brief Set flow congestion drop on a particular port queue.
 * @param[in] dev_id device id
 * @param[in] port_id port id
 * @param[in] queue_id queue id
 * @param[in] enable A_TRUE or A_FALSE
 * @return SW_OK or error code
 */
sw_error_t
mht_port_congestion_drop_set (a_uint32_t dev_id, fal_port_t port_id,
			       a_uint32_t queue_id, a_bool_t enable)
{
	sw_error_t rv;
	HSL_API_LOCK;
	rv = _mht_port_congestion_drop_set (dev_id, port_id, queue_id, enable);
	HSL_API_UNLOCK;
	return rv;
}

/**
 * @brief Set flow congestion drop on a particular port.
 * @param[in] dev_id device id
 * @param[in] port_id port id
 * @param[in] queue_id queue id
 * @param[out] enable A_TRUE or A_FALSE
 * @return SW_OK or error code
 */
sw_error_t
mht_port_congestion_drop_get (a_uint32_t dev_id, fal_port_t port_id,
			       a_uint32_t queue_id, a_bool_t * enable)
{
	sw_error_t rv;

	HSL_API_LOCK;
	rv = _mht_port_congestion_drop_get (dev_id, port_id, queue_id, enable);
	HSL_API_UNLOCK;
	return rv;
}

/**
 * @brief Set flow ctrl thres on a particular DMA ring.
 * @param[in] dev_id device id
 * @param[in] ring_id ring id
 * @param[in] on_thres on_thres
 * @param[in] off_thres off_thres
 * @return SW_OK or error code
 */
sw_error_t
mht_ring_flow_ctrl_thres_set (a_uint32_t dev_id, a_uint32_t ring_id,
			       a_uint16_t on_thres, a_uint16_t off_thres)
{
	sw_error_t rv;
	HSL_API_LOCK;
	rv = _mht_ring_flow_ctrl_thres_set (dev_id, ring_id, on_thres, off_thres);
	HSL_API_UNLOCK;
	return rv;
}

/**
 * @brief Get flow ctrl thres on a particular DMA ring.
 * @param[in] dev_id device id
 * @param[in] ring_id ring id
 * @param[out] on_thres on_thres
 * @param[out] off_thres off_thres
 * @return SW_OK or error code
 */
sw_error_t
mht_ring_flow_ctrl_thres_get (a_uint32_t dev_id, a_uint32_t ring_id,
			       a_uint16_t * on_thres, a_uint16_t * off_thres)
{
	sw_error_t rv;

	HSL_API_LOCK;
	rv = _mht_ring_flow_ctrl_thres_get (dev_id, ring_id, on_thres, off_thres);
	HSL_API_UNLOCK;
	return rv;
}

/**
 * @brief Get flow ctrl status on a particular DMA ring.
 * @param[in] dev_id device id
 * @param[in] ring_id ring id
 * @param[out] status backpressure status
 * @return SW_OK or error code
 */
sw_error_t
mht_ring_flow_ctrl_status_get(a_uint32_t dev_id, a_uint32_t ring_id, a_bool_t *status)
{
	sw_error_t rv;

	HSL_API_LOCK;
	rv = _mht_ring_flow_ctrl_status_get (dev_id, ring_id, status);
	HSL_API_UNLOCK;
	return rv;
}

/**
 * @brief Set port0 port5 ring union.
 * @param[in] dev_id device id
 * @param[in] enable or not
 * @return SW_OK or error code
 */
sw_error_t
mht_ring_union_set(a_uint32_t dev_id, a_bool_t en)
{
	sw_error_t rv;
	HSL_API_LOCK;
	rv = _mht_ring_union_set(dev_id, en);
	HSL_API_UNLOCK;
	return rv;
}

/**
 * @brief Get port0 port5 ring union.
 * @param[in] dev_id device id
 * @param[out] enable or not
 * @return SW_OK or error code
 */
sw_error_t
mht_ring_union_get(a_uint32_t dev_id, a_bool_t *en)
{
	sw_error_t rv;
	HSL_API_LOCK;
	rv = _mht_ring_union_get(dev_id, en);
	HSL_API_UNLOCK;
	return rv;
}

/**
 * @brief Get flow control(rx/tx/bp) threshold on a particular port.
 * @param[in] dev_id device id
 * @param[in] port_id port id
 * @param[out] on on threshold
 * @param[out] off off threshold
 * @return SW_OK or error code
 */
sw_error_t
mht_port_flowctrl_thresh_get(a_uint32_t dev_id, fal_port_t port_id,
		a_uint16_t *on, a_uint16_t *off)
{
	sw_error_t rv;

	HSL_API_LOCK;
	rv = _mht_port_flowctrl_thresh_get(dev_id, port_id, on, off);
	HSL_API_UNLOCK;
	return rv;
}

/**
 * @brief Set flow control(rx/tx/bp) threshold on a particular port.
 * @param[in] dev_id device id
 * @param[in] port_id port id
 * @param[in] on on threshold
 * @param[in] off off threshold
 * @return SW_OK or error code
 */
sw_error_t
mht_port_flowctrl_thresh_set(a_uint32_t dev_id, fal_port_t port_id,
		a_uint16_t on, a_uint16_t off)
{
	sw_error_t rv;

	HSL_API_LOCK;
	rv = _mht_port_flowctrl_thresh_set(dev_id, port_id, on, off);
	HSL_API_UNLOCK;
	return rv;
}

/**
 * @brief Get port 0 & port5 ring flow control status.
 * @param[in] dev_id device id
 * @param[in] ring_id ring id
 * @param[in] status enable or not
 * @return SW_OK or error code
 */
sw_error_t
mht_ring_flow_ctrl_config_set(a_uint32_t dev_id, a_uint32_t ring_id, a_bool_t status)
{
	sw_error_t rv;
	HSL_API_LOCK;
	rv = _mht_ring_flow_ctrl_config_set(dev_id, ring_id, status);
	HSL_API_UNLOCK;
	return rv;
}

/**
 * @brief Set port 0 & port5 ring flow control status.
 * @param[in] dev_id device id
 * @param[in] ring_id ring id
 * @param[out] status enable or not
 * @return SW_OK or error code
 */
sw_error_t
mht_ring_flow_ctrl_config_get(a_uint32_t dev_id, a_uint32_t ring_id, a_bool_t *status)
{
	sw_error_t rv;
	HSL_API_LOCK;
	rv = _mht_ring_flow_ctrl_config_get(dev_id, ring_id, status);
	HSL_API_UNLOCK;
	return rv;
}

/**
 * @}
 */
