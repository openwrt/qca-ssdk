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


#ifndef _MHT_REG_H
#define _MHT_REG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define HSL_RW 1
#define HSL_RO 0

/*
 * Manhattan GCC Gloabl Control Register
 */

/* work mode */
#define WORK_MODE					"work_mode"
#define WORK_MODE_ID					0
#define WORK_MODE_OFFSET				0xC907030
#define WORK_MODE_E_LENGTH				4
#define WORK_MODE_E_OFFSET				0
#define WORK_MODE_NR_E					1

/* port5 sel */
#define WORK_MODE_PORT5_SEL				"port5_sel"
#define WORK_MODE_PORT5_SEL_BOFFSET			5
#define WORK_MODE_PORT5_SEL_BLEN			1
#define WORK_MODE_PORT5_SEL_FLAG			HSL_RW

/* phy3 sel1 */
#define WORK_MODE_PHY3_SEL1				"phy3_sel1"
#define WORK_MODE_PHY3_SEL1_BOFFSET			4
#define WORK_MODE_PHY3_SEL1_BLEN			1
#define WORK_MODE_PHY3_SEL1_FLAG			HSL_RW

/* phy3 sel0 */
#define WORK_MODE_PHY3_SEL0				"phy3_sel0"
#define WORK_MODE_PHY3_SEL0_BOFFSET			3
#define WORK_MODE_PHY3_SEL0_BLEN			1
#define WORK_MODE_PHY3_SEL0_FLAG			HSL_RW

/* phy2 sel */
#define WORK_MODE_PHY2_SEL				"phy2_sel"
#define WORK_MODE_PHY2_SEL_BOFFSET			2
#define WORK_MODE_PHY2_SEL_BLEN				1
#define WORK_MODE_PHY2_SEL_FLAG				HSL_RW

/* phy1 sel */
#define WORK_MODE_PHY1_SEL				"phy1_sel"
#define WORK_MODE_PHY1_SEL_BOFFSET			1
#define WORK_MODE_PHY1_SEL_BLEN				1
#define WORK_MODE_PHY1_SEL_FLAG				HSL_RW

/* phy0 sel */
#define WORK_MODE_PHY0_SEL				"phy0_sel"
#define WORK_MODE_PHY0_SEL_BOFFSET			0
#define WORK_MODE_PHY0_SEL_BLEN				1
#define WORK_MODE_PHY0_SEL_FLAG				HSL_RW

#define GCC_SWITCH_CORE_CBCR				"switch_core"
#define GCC_SWITCH_CORE_CBCR_ID				0
#define GCC_SWITCH_CORE_CBCR_OFFSET			0xC800008
#define GCC_SWITCH_CORE_CBCR_E_LENGTH			4
#define GCC_SWITCH_CORE_CBCR_E_OFFSET			0
#define GCC_SWITCH_CORE_CBCR_NR_E			0

/* reset switch core */
#define GCC_SWITCH_CORE_CBCR_CLK_ARES			"clk_ares"
#define GCC_SWITCH_CORE_CBCR_CLK_ARES_BOFFSET		2
#define GCC_SWITCH_CORE_CBCR_CLK_ARES_BLEN		1
#define GCC_SWITCH_CORE_CBCR_CLK_ARES_FLAG		HSL_RW

#define GCC_GLOBAL_CTL					"global_ctl"
#define GCC_GLOBAL_CTL_ID				1
#define GCC_GLOBAL_CTL_OFFSET				0xC800308
#define GCC_GLOBAL_CTL_E_LENGTH				4
#define GCC_GLOBAL_CTL_E_OFFSET				0
#define GCC_GLOBAL_CTL_NR_E				0

/* reset soc */
#define GCC_GLOBAL_CTL_GCC_TOP_FUNC_ARES		"func_ares"
#define GCC_GLOBAL_CTL_GCC_TOP_FUNC_ARES_BOFFSET	0
#define GCC_GLOBAL_CTL_GCC_TOP_FUNC_ARES_BLEN		1
#define GCC_GLOBAL_CTL_GCC_TOP_FUNC_ARES_FLAG		HSL_RW

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MHT_REG_H */
