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
#include "mht_reg.h"
#include "mht_sec_ctrl.h"
#include "ssdk_plat.h"

sw_error_t
qca_mht_work_mode_set(a_uint32_t dev_id, mht_work_mode_t work_mode)
{
	sw_error_t rv = SW_OK;
	a_uint32_t data = 0;
	a_int8_t val = 0;

	HSL_DEV_ID_CHECK(dev_id);

	switch (work_mode) {
		case SWITCH_MODE:
			val = BIT(WORK_MODE_PHY3_SEL1_BOFFSET);
			break;
		case SWITCH_BYPASS_PORT5_MODE:
			val = BIT(WORK_MODE_PORT5_SEL_BOFFSET);
			break;
		case PHY_USXGMII_MODE:
			val = BIT(WORK_MODE_PORT5_SEL_BOFFSET) |
				BIT(WORK_MODE_PHY3_SEL0_BOFFSET) |
				BIT(WORK_MODE_PHY2_SEL_BOFFSET) |
				BIT(WORK_MODE_PHY1_SEL_BOFFSET) |
				BIT(WORK_MODE_PHY0_SEL_BOFFSET);
			break;
		case PHY_SGMII_USXGMII_MODE:
			val = BIT(WORK_MODE_PORT5_SEL_BOFFSET) |
				BIT(WORK_MODE_PHY2_SEL_BOFFSET) |
				BIT(WORK_MODE_PHY1_SEL_BOFFSET) |
				BIT(WORK_MODE_PHY0_SEL_BOFFSET);
			break;
		default:
			SSDK_ERROR("Unknow work mode: %d\n", work_mode);
			return SW_BAD_VALUE;
	}

	data = qca_mht_mii_read(dev_id, WORK_MODE_OFFSET);

	data &= ~(BITS(WORK_MODE_PHY0_SEL_BOFFSET, WORK_MODE_PORT5_SEL_BOFFSET + 1));
	data |= val;

	qca_mht_mii_write(dev_id, WORK_MODE_OFFSET, val);

	return rv;
}

/**
 * @}
 */
