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
 * @defgroup mht_sec_ctrl MHT_SEC_CTRL
 * @{
 */
#include "sw.h"
#include "hsl.h"
#include "hsl_dev.h"
#include "mht_sec_ctrl.h"
#include "mht_interface_ctrl.h"

sw_error_t
qca_mht_work_mode_set(a_uint32_t dev_id, mht_work_mode_t work_mode)
{
	a_uint32_t data = 0;

	HSL_DEV_ID_CHECK(dev_id);

	data = qca_mht_mii_read(dev_id, WORK_MODE_OFFSET);
	data = ~MHT_WORK_MODE_MASK;
	data |= work_mode;

	qca_mht_mii_write(dev_id, WORK_MODE_OFFSET, data);

	return SW_OK;
}

sw_error_t
qca_mht_work_mode_get(a_uint32_t dev_id, mht_work_mode_t *work_mode)
{
	a_uint32_t data = 0;

	HSL_DEV_ID_CHECK(dev_id);

	data = qca_mht_mii_read(dev_id, WORK_MODE_OFFSET);
	SSDK_DEBUG("work mode reg is 0x%x\n", data);

	*work_mode = data & MHT_WORK_MODE_MASK;

	return SW_OK;
}

sw_error_t
qca_mht_serdes_addr_get(a_uint32_t dev_id, a_uint32_t serdes_id,
	a_uint32_t *address)
{
	a_uint32_t data = 0;

	HSL_DEV_ID_CHECK(dev_id);
	data = qca_mht_mii_read(dev_id, SERDES_CFG_OFFSET);
	switch(serdes_id)
	{
		case MHT_UNIPHY_SGMII_0:
			*address = (data >> SERDES_CFG_S0_ADDR_BOFFSET) & 0x1f;
			break;
		case MHT_UNIPHY_SGMII_1:
			*address = (data >> SERDES_CFG_S1_ADDR_BOFFSET) & 0x1f;
			break;
		case MHT_UNIPHY_XGMII:
			*address = (data >> SERDES_CFG_S1_XPCS_ADDR_BOFFSET) & 0x1f;
			break;
		default:
			return SW_NOT_SUPPORTED;
	}

	return SW_OK;
}

sw_error_t
qca_mht_ephy_addr_get(a_uint32_t dev_id, a_uint32_t mht_port_id,
	a_uint32_t *phy_addr)
{
	a_uint32_t data = 0;

	HSL_DEV_ID_CHECK(dev_id);
	data = qca_mht_mii_read(dev_id, EPHY_CFG_OFFSET);
	switch(mht_port_id)
	{
		case SSDK_PHYSICAL_PORT1:
			*phy_addr = (data >> EPHY_CFG_EPHY0_ADDR_BOFFSET) & 0x1f;
			break;
		case SSDK_PHYSICAL_PORT2:
			*phy_addr = (data >> EPHY_CFG_EPHY1_ADDR_BOFFSET) & 0x1f;
			break;
		case SSDK_PHYSICAL_PORT3:
			*phy_addr = (data >> EPHY_CFG_EPHY2_ADDR_BOFFSET) & 0x1f;
			break;
		case SSDK_PHYSICAL_PORT4:
			*phy_addr = (data >> EPHY_CFG_EPHY3_ADDR_BOFFSET) & 0x1f;
			break;
		default:
			return SW_NOT_SUPPORTED;
	}

	return SW_OK;
}

sw_error_t
qca_mht_port_id_get(a_uint32_t dev_id, a_uint32_t phy_addr,
	a_uint32_t *mht_port_id)
{
	a_uint32_t port_index = 0, phy_addr_tmp = 0;
	sw_error_t rv = SW_OK;

	for(port_index = SSDK_PHYSICAL_PORT1; port_index <= SSDK_PHYSICAL_PORT4;
		port_index++)
	{
		rv = qca_mht_ephy_addr_get(dev_id, port_index, &phy_addr_tmp);
		SW_RTN_ON_ERROR (rv);
		if(phy_addr == phy_addr_tmp)
		{
			*mht_port_id = port_index;
			return SW_OK;
		}
	}

	return SW_NOT_FOUND;
}
/**
 * @}
 */
