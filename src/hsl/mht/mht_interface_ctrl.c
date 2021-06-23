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
#include "hsl.h"
#include "hsl_phy.h"
#include "ssdk_plat.h"
#include "mht_interface_ctrl.h"
#include "mht_sec_ctrl.h"
#include "hsl_dev.h"
#include "qca808x_phy.h"
#include "qca8084_phy.h"
#include "ssdk_mht_clk.h"

static a_uint16_t
mht_uniphy_xpcs_mmd_read(a_uint32_t dev_id, a_uint16_t mmd_num,
	a_uint16_t mmd_reg)
{
	sw_error_t rv = SW_OK;
	a_uint32_t uniphy_xpcs_addr = 0;

	rv = qca_mht_serdes_addr_get(dev_id, MHT_UNIPHY_XPCS, &uniphy_xpcs_addr);
	if(rv != SW_OK)
		return PHY_INVALID_DATA;

	return qca808x_phy_mmd_read(dev_id, uniphy_xpcs_addr, mmd_num,
		mmd_reg);
}

static sw_error_t
mht_uniphy_xpcs_mmd_write(a_uint32_t dev_id, a_uint16_t mmd_num,
	a_uint16_t mmd_reg, a_uint16_t reg_val)
{
	sw_error_t rv = SW_OK;
	a_uint32_t uniphy_xpcs_addr = 0;
	a_uint16_t phy_data = 0;

	rv = qca_mht_serdes_addr_get(dev_id, MHT_UNIPHY_XPCS, &uniphy_xpcs_addr);
	SW_RTN_ON_ERROR (rv);

	rv = qca808x_phy_mmd_write(dev_id, uniphy_xpcs_addr, mmd_num, mmd_reg,
		reg_val);
	/*check the mmd register value*/
	phy_data = mht_uniphy_xpcs_mmd_read(dev_id, mmd_num, mmd_reg);
	SSDK_INFO ("phy_addr:0x%x, mmd_num:0x%x, mmd_reg:0x%x, phy_data:0x%x",
		uniphy_xpcs_addr, mmd_num, mmd_reg, phy_data);

	return rv;
}

static sw_error_t
mht_uniphy_xpcs_modify_mmd(a_uint32_t dev_id, a_uint32_t mmd_num, a_uint32_t mmd_reg,
	a_uint32_t mask, a_uint32_t value)
{
	sw_error_t rv = SW_OK;
	a_uint16_t phy_data = 0, new_phy_data = 0;

	phy_data = mht_uniphy_xpcs_mmd_read(dev_id, mmd_num, mmd_reg);
	PHY_RTN_ON_READ_ERROR(phy_data);
	new_phy_data = (phy_data & ~mask) | value;
	rv = mht_uniphy_xpcs_mmd_write(dev_id, mmd_num, mmd_reg, new_phy_data);

	return rv;
}

static sw_error_t
mht_uniphy_xpcs_modify_port_mmd(a_uint32_t dev_id, a_uint32_t mht_port_id,
	a_uint32_t mmd_reg, a_uint32_t mask, a_uint32_t value)
{
	a_uint32_t mmd_id = 0;
	sw_error_t rv = SW_OK;

	switch(mht_port_id)
	{
		case SSDK_PHYSICAL_PORT1:
			mmd_id = MHT_UNIPHY_MMD31;
			break;
		case SSDK_PHYSICAL_PORT2:
			mmd_id = MHT_UNIPHY_MMD26;
			break;
		case SSDK_PHYSICAL_PORT3:
			mmd_id = MHT_UNIPHY_MMD27;
			break;
		case SSDK_PHYSICAL_PORT4:
			mmd_id = MHT_UNIPHY_MMD28;
			break;
		default:
			return SW_NOT_SUPPORTED;
	}

	rv = mht_uniphy_xpcs_modify_mmd(dev_id, mmd_id, mmd_reg, mask, value);

	return rv;
}

static sw_error_t
mht_uniphy_xpcs_8023az_enable(a_uint32_t dev_id)
{
	sw_error_t rv = SW_OK;
	a_uint16_t uniphy_data = 0;

	uniphy_data = mht_uniphy_xpcs_mmd_read(dev_id, MHT_UNIPHY_MMD3,
		MHT_UNIPHY_MMD3_AN_LP_BASE_ABL2);
	PHY_RTN_ON_READ_ERROR(uniphy_data);
	if(!(uniphy_data & MHT_UNIPHY_MMD3_XPCS_EEE_CAP))
		return SW_NOT_SUPPORTED;

	/*Configure the EEE related timer*/
	rv = mht_uniphy_xpcs_modify_mmd(dev_id, MHT_UNIPHY_MMD3,
		MHT_UNIPHY_MMD3_EEE_MODE_CTRL, 0x0f40, MHT_UNIPHY_MMD3_EEE_RES_REGS |
		MHT_UNIPHY_MMD3_EEE_SIGN_BIT_REGS);
	SW_RTN_ON_ERROR (rv);

	rv = mht_uniphy_xpcs_modify_mmd(dev_id, MHT_UNIPHY_MMD3,
		MHT_UNIPHY_MMD3_EEE_TX_TIMER, 0x1fff, MHT_UNIPHY_MMD3_EEE_TSL_REGS|
		MHT_UNIPHY_MMD3_EEE_TLU_REGS | MHT_UNIPHY_MMD3_EEE_TWL_REGS);
	SW_RTN_ON_ERROR (rv);

	rv = mht_uniphy_xpcs_modify_mmd(dev_id, MHT_UNIPHY_MMD3,
		MHT_UNIPHY_MMD3_EEE_RX_TIMER, 0x1fff, MHT_UNIPHY_MMD3_EEE_RWR_REG_REGS|
		MHT_UNIPHY_MMD3_EEE_RWR_REG_REGS);
	SW_RTN_ON_ERROR (rv);

	/*enable TRN_LPI*/
	rv = mht_uniphy_xpcs_modify_mmd(dev_id, MHT_UNIPHY_MMD3,
		MHT_UNIPHY_MMD3_EEE_MODE_CTRL1, 0x101, MHT_UNIPHY_MMD3_EEE_TRANS_LPI_MODE|
		MHT_UNIPHY_MMD3_EEE_TRANS_RX_LPI_MODE);
	SW_RTN_ON_ERROR (rv);

	/*enable TX/RX LPI pattern*/
	rv = mht_uniphy_xpcs_modify_mmd(dev_id, MHT_UNIPHY_MMD3,
		MHT_UNIPHY_MMD3_EEE_MODE_CTRL, 0x3, MHT_UNIPHY_MMD3_EEE_EN);

	return rv;
}

static sw_error_t
mht_uniphy_calibration(a_uint32_t dev_id, a_uint32_t uniphy_addr)
{
	a_uint16_t uniphy_data = 0;
	a_uint32_t retries = 100, calibration_done = 0;

	/* wait calibration done to uniphy*/
	while (calibration_done != MHT_UNIPHY_MMD1_CALIBRATION_DONE) {
		mdelay(1);
		if (retries-- == 0)
		{
			SSDK_ERROR("uniphy callibration time out!\n");
			return SW_TIMEOUT;
		}
		uniphy_data = qca808x_phy_mmd_read(dev_id, uniphy_addr, MHT_UNIPHY_MMD1,
			MHT_UNIPHY_MMD1_CALIBRATION4);
		PHY_RTN_ON_READ_ERROR(uniphy_data);

		calibration_done = (uniphy_data & MHT_UNIPHY_MMD1_CALIBRATION_DONE);
	}

	return SW_OK;
}

static sw_error_t
mht_uniphy_xpcs_10g_r_linkup(a_uint32_t dev_id)
{
	a_uint16_t uniphy_data = 0;
	a_uint32_t retries = 100, linkup = 0;

	/* wait 10G_R link up */
	while (linkup != MHT_UNIPHY_MMD3_10GBASE_R_UP) {
		mdelay(1);
		if (retries-- == 0)
		{
			SSDK_ERROR ("10g_r link up timeout\n");
			return SW_TIMEOUT;
		}
		uniphy_data = mht_uniphy_xpcs_mmd_read(dev_id, MHT_UNIPHY_MMD3,
			MHT_UNIPHY_MMD3_10GBASE_R_PCS_STATUS1);
		PHY_RTN_ON_READ_ERROR(uniphy_data);

		linkup = (uniphy_data & MHT_UNIPHY_MMD3_10GBASE_R_UP);
	}

	return SW_OK;
}

static sw_error_t
mht_uniphy_xpcs_soft_reset(a_uint32_t dev_id)
{
	sw_error_t rv = SW_OK;
	a_uint16_t uniphy_data = 0;
	a_uint32_t retries = 100, reset_done = MHT_UNIPHY_MMD3_XPCS_SOFT_RESET;

	rv = mht_uniphy_xpcs_modify_mmd(dev_id, MHT_UNIPHY_MMD3,
		MHT_UNIPHY_MMD3_DIG_CTRL1, 0x8000, MHT_UNIPHY_MMD3_XPCS_SOFT_RESET);
	SW_RTN_ON_ERROR (rv);

	while (reset_done) {
		mdelay(1);
		if (retries-- == 0)
			return SW_TIMEOUT;
		uniphy_data = mht_uniphy_xpcs_mmd_read(dev_id, MHT_UNIPHY_MMD3,
			MHT_UNIPHY_MMD3_DIG_CTRL1);
		PHY_RTN_ON_READ_ERROR(uniphy_data);

		reset_done = (uniphy_data & MHT_UNIPHY_MMD3_XPCS_SOFT_RESET);
	}

	return rv;
}

static sw_error_t
_mht_interface_uqxgmii_mode_set(a_uint32_t dev_id, a_uint32_t uniphy_addr)
{
	sw_error_t rv = SW_OK;
	a_uint32_t mht_port_id = 0, phy_addr = 0;

	/*reset xpcs*/
	SSDK_INFO("reset xpcs\n");
	rv = ssdk_mht_clk_assert(dev_id, MHT_UNIPHY_XPCS_RST);
	SW_RTN_ON_ERROR (rv);
	/*select xpcs mode*/
	SSDK_INFO("select xpcs mode\n");
	rv = qca808x_phy_modify_mmd(dev_id, uniphy_addr, MHT_UNIPHY_MMD1,
		MHT_UNIPHY_MMD1_MODE_CTRL, 0x1f00, MHT_UNIPHY_MMD1_XPCS_MODE);
	SW_RTN_ON_ERROR (rv);
	/*config QP_USXG_OPTION1*/
	SSDK_INFO("config QP_USXG_OPTION1\n");
	rv = qca808x_phy_modify_mmd(dev_id, uniphy_addr, MHT_UNIPHY_MMD1,
		MHT_UNIPHY_MMD1_QP_USXG_OPTION1, 0x1, MHT_UNIPHY_MMD1_QP_USXGMII_GMII);
	SW_RTN_ON_ERROR (rv);
	/*reset and release uniphy GMII/XGMII and ethphy GMII*/
	SSDK_INFO("reset and release uniphy GMII/XGMII and ethphy GMII\n");
	for(mht_port_id = SSDK_PHYSICAL_PORT1; mht_port_id <= SSDK_PHYSICAL_PORT4;
		mht_port_id++)
	{
		rv = ssdk_mht_port_clk_reset(dev_id, mht_port_id,
			MHT_CLK_TYPE_UNIPHY|MHT_CLK_TYPE_EPHY);
		SW_RTN_ON_ERROR(rv);
	}

	/*ana sw reset and release*/
	SSDK_INFO("ana sw reset and release\n");
	rv = qca808x_phy_modify_mii(dev_id, uniphy_addr,
		MHT_UNIPHY_PLL_POWER_ON_AND_RESET, 0x40, MHT_UNIPHY_ANA_SOFT_RESET);
	SW_RTN_ON_ERROR (rv);
	mdelay(100);
	rv = qca808x_phy_modify_mii(dev_id, uniphy_addr,
		MHT_UNIPHY_PLL_POWER_ON_AND_RESET, 0x40, MHT_UNIPHY_ANA_SOFT_RELEASE);
	SW_RTN_ON_ERROR (rv);

	/*Wait calibration done*/
	SSDK_INFO("Wait calibration done\n");
	mht_uniphy_calibration(dev_id, uniphy_addr);
	/*Enable SSCG(Spread Spectrum Clock Generator)*/
	SSDK_INFO("enable uniphy sscg\n");
	rv = qca808x_phy_modify_mmd(dev_id, uniphy_addr, MHT_UNIPHY_MMD1,
		MHT_UNIPHY_MMD1_CDA_CONTROL1, 0x8, MHT_UNIPHY_MMD1_SSCG_ENABLE);
	SW_RTN_ON_ERROR (rv);
	/*release XPCS*/
	SSDK_INFO("release XPCS\n");
	rv = ssdk_mht_clk_deassert(dev_id, MHT_UNIPHY_XPCS_RST);
	SW_RTN_ON_ERROR (rv);
	/*ethphy software reset*/
	SSDK_INFO("ethphy software reset\n");
	for(mht_port_id = SSDK_PHYSICAL_PORT1; mht_port_id <= SSDK_PHYSICAL_PORT4;
		mht_port_id++)
	{
		rv = qca_mht_ephy_addr_get(dev_id, mht_port_id, &phy_addr);
		SW_RTN_ON_ERROR (rv);
		rv = qca808x_phy_reset(dev_id, phy_addr);
		SW_RTN_ON_ERROR (rv);
	}
	/*Set BaseR mode*/
	SSDK_INFO("Set BaseR mode\n");
	rv = mht_uniphy_xpcs_modify_mmd(dev_id, MHT_UNIPHY_MMD3,
		MHT_UNIPHY_MMD3_PCS_CTRL2, 0xf, MHT_UNIPHY_MMD3_PCS_TYPE_10GBASE_R);
	SW_RTN_ON_ERROR (rv);
	/*wait 10G base_r link up*/
	SSDK_INFO("wait 10G base_r link up\n");
	rv = mht_uniphy_xpcs_10g_r_linkup(dev_id);
	SW_RTN_ON_ERROR (rv);
	/*enable UQXGMII mode*/
	SSDK_INFO("enable UQSXGMII mode\n");
	rv = mht_uniphy_xpcs_modify_mmd(dev_id, MHT_UNIPHY_MMD3,
		MHT_UNIPHY_MMD3_DIG_CTRL1, 0x200, MHT_UNIPHY_MMD3_USXGMII_EN);
	SW_RTN_ON_ERROR (rv);
	/*set UQXGMII mode*/
	SSDK_INFO("set QXGMII mode\n");
	rv = mht_uniphy_xpcs_modify_mmd(dev_id, MHT_UNIPHY_MMD3,
		MHT_UNIPHY_MMD3_VR_RPCS_TPC, 0x1c00, MHT_UNIPHY_MMD3_QXGMII_EN);
	SW_RTN_ON_ERROR (rv);
	/*set AM interval*/
	SSDK_INFO("set AM interval\n");
	rv = mht_uniphy_xpcs_mmd_write(dev_id, MHT_UNIPHY_MMD3,
		MHT_UNIPHY_MMD3_MII_AM_INTERVAL, MHT_UNIPHY_MMD3_MII_AM_INTERVAL_VAL);
	SW_RTN_ON_ERROR (rv);
	/*xpcs software reset*/
	SSDK_INFO("xpcs software reset\n");
	rv = mht_uniphy_xpcs_soft_reset(dev_id);

	return rv;
}

sw_error_t
mht_interface_uqxgmii_mode_set(a_uint32_t dev_id)
{
	sw_error_t rv = SW_OK;
	a_uint32_t uniphy_addr = 0, mht_port_id = 0;

	rv = qca_mht_serdes_addr_get(dev_id, MHT_UNIPHY_SGMII_1, &uniphy_addr);
	SW_RTN_ON_ERROR (rv);

	/*disable IPG_tuning bypass*/
	SSDK_INFO("disable IPG_tuning bypass\n");
	rv = qca808x_phy_modify_mmd(dev_id, uniphy_addr, MHT_UNIPHY_MMD1,
		MHT_UNIPHY_MMD1_BYPASS_TUNING_IPG,
		MHT_UNIPHY_MMD1_BYPASS_TUNING_IPG_EN, 0);
	SW_RTN_ON_ERROR (rv);
	/*disable uniphy GMII/XGMII clock and disable ethphy GMII clock*/
	SSDK_INFO("disable uniphy GMII/XGMII clock and ethphy GMII clock\n");
	for(mht_port_id = SSDK_PHYSICAL_PORT1; mht_port_id <= SSDK_PHYSICAL_PORT4;
		mht_port_id++)
	{
		rv = ssdk_mht_port_clk_en_set(dev_id, mht_port_id,
			MHT_CLK_TYPE_UNIPHY|MHT_CLK_TYPE_EPHY, A_FALSE);
		SW_RTN_ON_ERROR (rv);
	}
	/*configure uqxgmii mode*/
	SSDK_INFO("configure uqxgmii mode\n");
	rv = _mht_interface_uqxgmii_mode_set(dev_id, uniphy_addr);
	SW_RTN_ON_ERROR (rv);
	/*enable auto-neg complete interrupt,Mii using mii-4bits,
		configure as PHY mode, enable autoneg ability*/
	SSDK_INFO("enable auto-neg complete interrupt,Mii using mii-4bits,"
		"configure as PHY mode, enable autoneg ability, disable TICD\n");
	for (mht_port_id = SSDK_PHYSICAL_PORT1; mht_port_id <= SSDK_PHYSICAL_PORT4;
		mht_port_id++)
	{
		/*enable auto-neg complete interrupt,Mii using mii-4bits,configure as PHY mode*/
		rv = mht_uniphy_xpcs_modify_port_mmd(dev_id, mht_port_id,
			MHT_UNIPHY_MMD_MII_AN_INT_MSK, 0x109,
			MHT_UNIPHY_MMD_AN_COMPLETE_INT |
			MHT_UNIPHY_MMD_MII_4BITS_CTRL |
			MHT_UNIPHY_MMD_TX_CONFIG_CTRL);
		SW_RTN_ON_ERROR (rv);

		/*enable autoneg ability*/
		rv = mht_uniphy_xpcs_modify_port_mmd(dev_id, mht_port_id,
			MHT_UNIPHY_MMD_MII_CTRL, 0x3060, MHT_UNIPHY_MMD_MII_AN_ENABLE |
			MHT_UNIPHY_MMD_XPC_SPEED_1000);
		SW_RTN_ON_ERROR (rv);

		/*disable TICD*/
		rv = mht_uniphy_xpcs_modify_port_mmd(dev_id, mht_port_id,
			MHT_UNIPHY_MMD_MII_XAUI_MODE_CTRL, 0x1,
			MHT_UNIPHY_MMD_TX_IPG_CHECK_DISABLE);
		SW_RTN_ON_ERROR (rv);
	}

	/*enable EEE for xpcs*/
	SSDK_INFO("enable EEE for xpcs\n");
	rv = mht_uniphy_xpcs_8023az_enable(dev_id);

	return rv;
}
