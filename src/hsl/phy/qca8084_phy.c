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

#include "sw.h"
#include "hsl_phy.h"
#include "ssdk_plat.h"
#include "qca808x_phy.h"
#include "qca8084_phy.h"
#include "mht_sec_ctrl.h"

sw_error_t
qca8084_phy_interface_set_mode(a_uint32_t dev_id, a_uint32_t phy_id,
		fal_port_interface_mode_t interface_mode)
{
	sw_error_t rv = SW_OK;

	/* configure the phy work mode of manhattan chip */
	switch (interface_mode) {
		case PORT_UQXGMII:
			rv = qca_mht_work_mode_set(dev_id, PHY_USXGMII_MODE);
			break;
		case PORT_UQXGMII_3CHANNELS:
			rv = qca_mht_work_mode_set(dev_id, PHY_SGMII_USXGMII_MODE);
			break;
		default:
			rv = SW_NOT_SUPPORTED;
			SSDK_WARN("Unsupport interface mode: %d\n", interface_mode);
			break;
	}

	return rv;
}

sw_error_t
qca8084_phy_set_8023az(a_uint32_t dev_id, a_uint32_t phy_id, a_bool_t enable)
{
	a_uint16_t phy_data;
	sw_error_t rv = SW_OK;

	phy_data = qca808x_phy_mmd_read(dev_id, phy_id, QCA8084_PHY_MMD7_NUM,
		QCA8084_PHY_MMD7_ADDR_8023AZ_EEE_2500M_CTRL);
	PHY_RTN_ON_READ_ERROR(phy_data);

	if (enable == A_TRUE) {
		phy_data |= QCA8084_PHY_8023AZ_EEE_2500BT;
	} else {
		phy_data &= ~QCA8084_PHY_8023AZ_EEE_2500BT;
	}

	rv = qca808x_phy_mmd_write(dev_id, phy_id, QCA8084_PHY_MMD7_NUM,
		QCA8084_PHY_MMD7_ADDR_8023AZ_EEE_2500M_CTRL, phy_data);

	return rv;
}

sw_error_t
qca8084_phy_get_8023az(a_uint32_t dev_id, a_uint32_t phy_id, a_bool_t * enable)
{
	a_uint16_t phy_data;

	*enable = A_FALSE;

	phy_data = qca808x_phy_mmd_read(dev_id, phy_id, QCA8084_PHY_MMD7_NUM,
		QCA8084_PHY_MMD7_ADDR_8023AZ_EEE_2500M_CTRL);
	PHY_RTN_ON_READ_ERROR(phy_data);

	if (phy_data & QCA8084_PHY_8023AZ_EEE_2500BT) {
		*enable = A_TRUE;
	}

	return SW_OK;
}

sw_error_t
qca8084_phy_set_eee_adv(a_uint32_t dev_id, a_uint32_t phy_id,
	a_uint32_t adv)
{
	a_uint16_t phy_data = 0;
	sw_error_t rv = SW_OK;

	phy_data = qca808x_phy_mmd_read(dev_id, phy_id, QCA8084_PHY_MMD7_NUM,
		QCA8084_PHY_MMD7_ADDR_8023AZ_EEE_2500M_CTRL);
	PHY_RTN_ON_READ_ERROR(phy_data);
	phy_data &= ~(QCA8084_PHY_8023AZ_EEE_2500BT);

	if (adv & FAL_PHY_EEE_2500BASE_T) {
		phy_data |= QCA8084_PHY_8023AZ_EEE_2500BT;
	}

	rv = qca808x_phy_mmd_write(dev_id, phy_id, QCA8084_PHY_MMD7_NUM,
		QCA8084_PHY_MMD7_ADDR_8023AZ_EEE_2500M_CTRL, phy_data);

	return rv;
}

sw_error_t
qca8084_phy_get_eee_adv(a_uint32_t dev_id, a_uint32_t phy_id,
	a_uint32_t *adv)
{
	a_uint16_t phy_data = 0;

	phy_data = qca808x_phy_mmd_read(dev_id, phy_id, QCA8084_PHY_MMD7_NUM,
		QCA8084_PHY_MMD7_ADDR_8023AZ_EEE_2500M_CTRL);
	PHY_RTN_ON_READ_ERROR(phy_data);

	if (phy_data & QCA8084_PHY_8023AZ_EEE_2500BT) {
		*adv |= FAL_PHY_EEE_2500BASE_T;
	}

	return SW_OK;
}

sw_error_t
qca8084_phy_get_eee_partner_adv(a_uint32_t dev_id, a_uint32_t phy_id,
	a_uint32_t *adv)
{
	a_uint16_t phy_data = 0;

	phy_data = qca808x_phy_mmd_read(dev_id, phy_id, QCA8084_PHY_MMD7_NUM,
		QCA8084_PHY_MMD7_ADDR_8023AZ_EEE_2500M_PARTNER);
	PHY_RTN_ON_READ_ERROR(phy_data);

	if (phy_data & QCA8084_PHY_8023AZ_EEE_2500BT) {
		*adv |= FAL_PHY_EEE_2500BASE_T;
	}

	return SW_OK;
}

sw_error_t
qca8084_phy_get_eee_cap(a_uint32_t dev_id, a_uint32_t phy_id,
	a_uint32_t *cap)
{
	a_uint16_t phy_data = 0;

	phy_data = qca808x_phy_mmd_read(dev_id, phy_id, QCA8084_PHY_MMD3_NUM,
		QCA8084_PHY_MMD3_ADDR_8023AZ_EEE_2500M_CAPABILITY);

	if (phy_data & QCA8084_PHY_EEE_CAPABILITY_2500M) {
		*cap |= FAL_PHY_EEE_2500BASE_T;
	}

	return SW_OK;
}

sw_error_t
qca8084_phy_get_eee_status(a_uint32_t dev_id, a_uint32_t phy_id,
	a_uint32_t *status)
{
	a_uint32_t adv = 0, lp_adv = 0;
	sw_error_t rv = SW_OK;

	rv = qca8084_phy_get_eee_adv(dev_id, phy_id, &adv);
	SW_RTN_ON_ERROR(rv);

	rv = qca8084_phy_get_eee_partner_adv(dev_id, phy_id, &lp_adv);
	SW_RTN_ON_ERROR(rv);

	*status |= (adv & lp_adv);

	return SW_OK;
}

static sw_error_t
qca8084_phy_cdt_thresh_init(a_uint32_t dev_id, a_uint32_t phy_id)
{
	sw_error_t rv = SW_OK;

	rv = qca808x_phy_mmd_write(dev_id, phy_id, QCA8084_PHY_MMD3_NUM,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL3,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL3_VAL);
	SW_RTN_ON_ERROR(rv);
	rv = qca808x_phy_mmd_write(dev_id, phy_id, QCA8084_PHY_MMD3_NUM,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL4,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL4_VAL);
	SW_RTN_ON_ERROR(rv);
	rv = qca808x_phy_mmd_write(dev_id, phy_id, QCA8084_PHY_MMD3_NUM,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL5,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL5_VAL);
	SW_RTN_ON_ERROR(rv);
	rv = qca808x_phy_mmd_write(dev_id, phy_id, QCA8084_PHY_MMD3_NUM,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL6,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL6_VAL);
	SW_RTN_ON_ERROR(rv);
	rv = qca808x_phy_mmd_write(dev_id, phy_id, QCA8084_PHY_MMD3_NUM,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL7,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL7_VAL);
	SW_RTN_ON_ERROR(rv);
	rv = qca808x_phy_mmd_write(dev_id, phy_id, QCA8084_PHY_MMD3_NUM,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL9,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL9_VAL);
	SW_RTN_ON_ERROR(rv);
	rv = qca808x_phy_mmd_write(dev_id, phy_id, QCA8084_PHY_MMD3_NUM,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL13,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL13_VAL);
	SW_RTN_ON_ERROR(rv);
	rv = qca808x_phy_mmd_write(dev_id, phy_id, QCA8084_PHY_MMD3_NUM,
		QCA8084_PHY_MMD3_CDT_THRESH_CTRL14,
		QCA8084_PHY_MMD3_NEAR_ECHO_THRESH_VAL);

	return rv;
}

static sw_error_t
qca8084_phy_function_reset(a_uint32_t dev_id, a_uint32_t phy_id,
	hsl_phy_function_reset_t phy_reset_type)
{
	a_uint16_t phy_data = 0;
	sw_error_t rv = SW_OK;

	phy_data = qca808x_phy_reg_read (dev_id, phy_id, QCA8084_PHY_FIFO_CONTROL);
	PHY_RTN_ON_READ_ERROR(phy_data);

	rv = qca808x_phy_reg_write(dev_id, phy_id, QCA8084_PHY_FIFO_CONTROL,
		phy_data & (~QCA8084_PHY_FIFO_RESET));
	SW_RTN_ON_ERROR(rv);

	aos_mdelay(50);

	rv = qca808x_phy_reg_write(dev_id, phy_id, QCA8084_PHY_FIFO_CONTROL,
	phy_data | QCA8084_PHY_FIFO_RESET);
	SW_RTN_ON_ERROR(rv);

	return rv;
}

void
qca8084_phy_api_ops_init(hsl_phy_ops_t * hsl_phy_ops)
{
	if(hsl_phy_ops == NULL)
	{
		SSDK_ERROR ("hsl_phy_ops is null\n");
		return;
	}
	hsl_phy_ops->phy_function_reset = qca8084_phy_function_reset;
}

sw_error_t
qca8084_phy_hw_init(a_uint32_t dev_id, a_uint32_t phy_addr)
{
	sw_error_t rv = SW_OK;

	/*adjust CDT threshold*/
	qca8084_phy_cdt_thresh_init(dev_id, phy_addr);

	return rv;
}
