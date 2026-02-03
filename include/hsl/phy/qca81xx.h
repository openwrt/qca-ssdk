/*
 * Copyright (c) 2024, Qualcomm Innovation Center, Inc. All rights reserved.
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

#ifndef _QCA81XX_H_
#define _QCA81XX_H_

enum {
	GPIO0_WOL_INT = 0,
	GPIO1_PHY_INT,
	GPIO2_LED0,
	GPIO3_LED1,
	GPIO4_LED3,
	GPIO5_PPS_IN = 5,
	GPIO6_TOD_IN = 6,
	GPIO7_REFCLK_IN = 7,
	GPIO10_PPS_OUT = 10,
	GPIO11_TOD_OUT = 11,
	GPIO12_CLK125_TDI = 12,
	GPIO_MAX
};

#define QCA8111_PHY					0x004dd1c0
#define QCA81XX_PHY_DRIVER_NAME				"Qualcomm QCA81xx"

/*SOC TLMM registers*/
#define TLMM_BASE					0x400000
#define TLMM_GPIO_OFFSET				0x1000
#define TO_TLMM_CFG_REG(pin)				(TLMM_BASE + TLMM_GPIO_OFFSET * pin)
#define TLMM_FUNC_MASK					GENMASK(5, 2)

int qca81xx_phy_debug_modify(struct phy_device *phydev,
			     unsigned int reg, u16 clear, u16 set);
int qca81xx_soc_modify(struct phy_device *phydev,
		       u32 reg, u32 mask, u32 set);
int qca81xx_phy_driver_register(void);
void qca81xx_phy_driver_unregister(void);

#endif /* _QCA81XX_H_ */
