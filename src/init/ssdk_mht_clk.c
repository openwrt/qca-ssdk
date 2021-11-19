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

#include <linux/delay.h>
#include <asm/div64.h>

#include "ssdk_init.h"
#include "ssdk_plat.h"
#include "ssdk_mht_clk.h"
#include "ssdk_clk.h"

#define MHT_PORT_CLK_CBC_MAX		8
/* 2 uniphy with rx and tx */
#define MHT_UNIPHY_INSTANCE		2
static a_uint64_t mht_uniphy_raw_clock[MHT_UNIPHY_INSTANCE * 2];

static const unsigned long mht_switch_core_support_rates[] = {
	UQXGMII_SPEED_2500M_CLK,
};

static const unsigned long mht_cpuport_clk_support_rates[] = {
	UQXGMII_SPEED_10M_CLK,
	UQXGMII_SPEED_100M_CLK,
	UQXGMII_SPEED_1000M_CLK,
	UQXGMII_SPEED_2500M_CLK,
};

static const unsigned long mht_phyport_clk_support_rates[] = {
	UQXGMII_SPEED_10M_CLK,
	UQXGMII_SPEED_100M_CLK,
	UQXGMII_SPEED_1000M_CLK,
	UQXGMII_SPEED_2500M_CLK,
	UQXGMII_XPCS_SPEED_2500M_CLK,
};

static const unsigned long mht_ahb_clk_support_rates[] = {
	MHT_AHB_CLK_RATE_104P17M
};

static const unsigned long mht_sys_clk_support_rates[] = {
	MHT_SYS_CLK_RATE_25M,
};

static const struct mht_parent_data mht_switch_core_pdata[] = {
	{ MHT_XO_CLK_RATE_50M, MHT_P_XO, 0 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY1_TX312P5M, 1 },
};

static const struct mht_parent_data mht_mac0_tx_clk_pdata[] = {
	{ MHT_XO_CLK_RATE_50M, MHT_P_XO, 0 } ,
	{ UQXGMII_SPEED_1000M_CLK, MHT_P_UNIPHY1_TX, 2 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY1_TX, 2 },
};

static const struct mht_parent_data mht_mac0_rx_clk_pdata[] = {
	{ MHT_XO_CLK_RATE_50M, MHT_P_XO, 0 } ,
	{ UQXGMII_SPEED_1000M_CLK, MHT_P_UNIPHY1_RX, 1 },
	{ UQXGMII_SPEED_1000M_CLK, MHT_P_UNIPHY1_TX, 2 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY1_RX, 1 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY1_TX, 2 },
};

/* port 1, 2, 3 rx/tx clock have the same parents */
static const struct mht_parent_data mht_mac1_tx_clk_pdata[] = {
	{ MHT_XO_CLK_RATE_50M, MHT_P_XO, 0 } ,
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY1_TX312P5M, 6 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY1_RX312P5M, 7 },
};

static const struct mht_parent_data mht_mac1_rx_clk_pdata[] = {
	{ MHT_XO_CLK_RATE_50M, MHT_P_XO, 0 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY1_TX312P5M, 6 },
};

static const struct mht_parent_data mht_mac4_tx_clk_pdata[] = {
	{ MHT_XO_CLK_RATE_50M, MHT_P_XO, 0 },
	{ UQXGMII_SPEED_1000M_CLK, MHT_P_UNIPHY0_RX, 1 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY0_RX, 1 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY1_TX312P5M, 3 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY1_RX312P5M, 7 },
};

static const struct mht_parent_data mht_mac4_rx_clk_pdata[] = {
	{ MHT_XO_CLK_RATE_50M, MHT_P_XO, 0 },
	{ UQXGMII_SPEED_1000M_CLK, MHT_P_UNIPHY0_TX, 2 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY0_TX, 2 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY1_TX312P5M, 3 },
};

static const struct mht_parent_data mht_mac5_tx_clk_pdata[] = {
	{ MHT_XO_CLK_RATE_50M, MHT_P_XO, 0 },
	{ UQXGMII_SPEED_1000M_CLK, MHT_P_UNIPHY0_TX, 2 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY0_TX, 2 },
};

static const struct mht_parent_data mht_mac5_rx_clk_pdata[] = {
	{ MHT_XO_CLK_RATE_50M, MHT_P_XO, 0 },
	{ UQXGMII_SPEED_1000M_CLK, MHT_P_UNIPHY0_RX, 1 },
	{ UQXGMII_SPEED_1000M_CLK, MHT_P_UNIPHY0_TX, 2 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY0_RX, 1 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY0_TX, 2 },
};

static const struct mht_parent_data mht_ahb_clk_pdata[] = {
	{ MHT_XO_CLK_RATE_50M, MHT_P_XO, 0 },
	{ UQXGMII_SPEED_2500M_CLK, MHT_P_UNIPHY1_TX312P5M, 2 },
};

static const struct mht_parent_data mht_sys_clk_pdata[] = {
	{ MHT_XO_CLK_RATE_50M, MHT_P_XO, 0 },
};

static struct clk_lookup mht_clk_lookup_table[] = {
	/* switch core clock */
	CLK_LOOKUP(4, 0, 8, CBCR_CLK_RESET,
			MHT_SWITCH_CORE_CLK,
			mht_switch_core_support_rates, ARRAY_SIZE(mht_switch_core_support_rates),
			mht_switch_core_pdata, ARRAY_SIZE(mht_switch_core_pdata)),
	CLK_LOOKUP(4, 0, 0x10, CBCR_CLK_RESET,
			MHT_APB_BRIDGE_CLK,
			mht_switch_core_support_rates, ARRAY_SIZE(mht_switch_core_support_rates),
			mht_switch_core_pdata, ARRAY_SIZE(mht_switch_core_pdata)),
	/* port 0 tx clock */
	CLK_LOOKUP(0x18, 0x1c, 0x20, CBCR_CLK_RESET,
			MHT_MAC0_TX_CLK,
			mht_cpuport_clk_support_rates, ARRAY_SIZE(mht_cpuport_clk_support_rates),
			mht_mac0_tx_clk_pdata, ARRAY_SIZE(mht_mac0_tx_clk_pdata)),
	CLK_LOOKUP(0x18, 0x1c, 0x24, CBCR_CLK_RESET,
			MHT_MAC0_TX_UNIPHY1_CLK,
			mht_cpuport_clk_support_rates, ARRAY_SIZE(mht_cpuport_clk_support_rates),
			mht_mac0_tx_clk_pdata, ARRAY_SIZE(mht_mac0_tx_clk_pdata)),
	/* port 0 rx clock */
	CLK_LOOKUP(0x2c, 0x30, 0x34, CBCR_CLK_RESET,
			MHT_MAC0_RX_CLK,
			mht_cpuport_clk_support_rates, ARRAY_SIZE(mht_cpuport_clk_support_rates),
			mht_mac0_rx_clk_pdata, ARRAY_SIZE(mht_mac0_rx_clk_pdata)),
	CLK_LOOKUP(0x2c, 0x30, 0x3c, CBCR_CLK_RESET,
			MHT_MAC0_RX_UNIPHY1_CLK,
			mht_cpuport_clk_support_rates, ARRAY_SIZE(mht_cpuport_clk_support_rates),
			mht_mac0_rx_clk_pdata, ARRAY_SIZE(mht_mac0_rx_clk_pdata)),
	/* port 1 tx clock */
	CLK_LOOKUP(0x44, 0x48, 0x50, CBCR_CLK_RESET,
			MHT_MAC1_UNIPHY1_CH0_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	CLK_LOOKUP(0x44, 0x48, 0x54, CBCR_CLK_RESET,
			MHT_MAC1_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	CLK_LOOKUP(0x44, 0x48, 0x58, CBCR_CLK_RESET,
			MHT_MAC1_GEPHY0_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	CLK_LOOKUP(0x44, 0x4c, 0x5c, CBCR_CLK_RESET,
			MHT_MAC1_UNIPHY1_CH0_XGMII_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	/* port 1 rx clock */
	CLK_LOOKUP(0x64, 0x68, 0x70, CBCR_CLK_RESET,
			MHT_MAC1_UNIPHY1_CH0_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	CLK_LOOKUP(0x64, 0x68, 0x74, CBCR_CLK_RESET,
			MHT_MAC1_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	CLK_LOOKUP(0x64, 0x68, 0x78, CBCR_CLK_RESET,
			MHT_MAC1_GEPHY0_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	CLK_LOOKUP(0x64, 0x6c, 0x7c, CBCR_CLK_RESET,
			MHT_MAC1_UNIPHY1_CH0_XGMII_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	/* port 2 tx clock */
	CLK_LOOKUP(0x84, 0x88, 0x90, CBCR_CLK_RESET,
			MHT_MAC2_UNIPHY1_CH1_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	CLK_LOOKUP(0x84, 0x88, 0x94, CBCR_CLK_RESET,
			MHT_MAC2_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	CLK_LOOKUP(0x84, 0x88, 0x98, CBCR_CLK_RESET,
			MHT_MAC2_GEPHY1_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	CLK_LOOKUP(0x84, 0x8c, 0x9c, CBCR_CLK_RESET,
			MHT_MAC2_UNIPHY1_CH1_XGMII_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	/* port 2 rx clock */
	CLK_LOOKUP(0xa4, 0xa8, 0xb0, CBCR_CLK_RESET,
			MHT_MAC2_UNIPHY1_CH1_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	CLK_LOOKUP(0xa4, 0xa8, 0xb4, CBCR_CLK_RESET,
			MHT_MAC2_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	CLK_LOOKUP(0xa4, 0xa8, 0xb8, CBCR_CLK_RESET,
			MHT_MAC2_GEPHY1_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	CLK_LOOKUP(0xa4, 0xac, 0xbc, CBCR_CLK_RESET,
			MHT_MAC2_UNIPHY1_CH1_XGMII_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	/* port 3 tx clock */
	CLK_LOOKUP(0xc4, 0xc8, 0xd0, CBCR_CLK_RESET,
			MHT_MAC3_UNIPHY1_CH2_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	CLK_LOOKUP(0xc4, 0xc8, 0xd4, CBCR_CLK_RESET,
			MHT_MAC3_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	CLK_LOOKUP(0xc4, 0xc8, 0xd8, CBCR_CLK_RESET,
			MHT_MAC3_GEPHY2_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	CLK_LOOKUP(0xc4, 0xcc, 0xdc, CBCR_CLK_RESET,
			MHT_MAC3_UNIPHY1_CH2_XGMII_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_tx_clk_pdata, ARRAY_SIZE(mht_mac1_tx_clk_pdata)),
	/* port 3 rx clock */
	CLK_LOOKUP(0xe4, 0xe8, 0xf0, CBCR_CLK_RESET,
			MHT_MAC3_UNIPHY1_CH2_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	CLK_LOOKUP(0xe4, 0xe8, 0xf4, CBCR_CLK_RESET,
			MHT_MAC3_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	CLK_LOOKUP(0xe4, 0xe8, 0xf8, CBCR_CLK_RESET,
			MHT_MAC3_GEPHY2_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	CLK_LOOKUP(0xe4, 0xec, 0xfc, CBCR_CLK_RESET,
			MHT_MAC3_UNIPHY1_CH2_XGMII_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac1_rx_clk_pdata, ARRAY_SIZE(mht_mac1_rx_clk_pdata)),
	/* port 4 tx clock */
	CLK_LOOKUP(0x104, 0x108, 0x110, CBCR_CLK_RESET,
			MHT_MAC4_UNIPHY1_CH3_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac4_tx_clk_pdata, ARRAY_SIZE(mht_mac4_tx_clk_pdata)),
	CLK_LOOKUP(0x104, 0x108, 0x114, CBCR_CLK_RESET,
			MHT_MAC4_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac4_tx_clk_pdata, ARRAY_SIZE(mht_mac4_tx_clk_pdata)),
	CLK_LOOKUP(0x104, 0x108, 0x118, CBCR_CLK_RESET,
			MHT_MAC4_GEPHY3_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac4_tx_clk_pdata, ARRAY_SIZE(mht_mac4_tx_clk_pdata)),
	CLK_LOOKUP(0x104, 0x10c, 0x11c, CBCR_CLK_RESET,
			MHT_MAC4_UNIPHY1_CH3_XGMII_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac4_tx_clk_pdata, ARRAY_SIZE(mht_mac4_tx_clk_pdata)),
	/* port 4 rx clock */
	CLK_LOOKUP(0x124, 0x128, 0x130, CBCR_CLK_RESET,
			MHT_MAC4_UNIPHY1_CH3_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac4_rx_clk_pdata, ARRAY_SIZE(mht_mac4_rx_clk_pdata)),
	CLK_LOOKUP(0x124, 0x128, 0x134, CBCR_CLK_RESET,
			MHT_MAC4_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac4_rx_clk_pdata, ARRAY_SIZE(mht_mac4_rx_clk_pdata)),
	CLK_LOOKUP(0x124, 0x128, 0x138, CBCR_CLK_RESET,
			MHT_MAC4_GEPHY3_RX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac4_rx_clk_pdata, ARRAY_SIZE(mht_mac4_rx_clk_pdata)),
	CLK_LOOKUP(0x124, 0x12c, 0x13c, CBCR_CLK_RESET,
			MHT_MAC4_UNIPHY1_CH3_XGMII_TX_CLK,
			mht_phyport_clk_support_rates, ARRAY_SIZE(mht_phyport_clk_support_rates),
			mht_mac4_rx_clk_pdata, ARRAY_SIZE(mht_mac4_rx_clk_pdata)),
	/* port 5 tx clock */
	CLK_LOOKUP(0x144, 0x148, 0x14c, CBCR_CLK_RESET,
			MHT_MAC5_TX_CLK,
			mht_cpuport_clk_support_rates, ARRAY_SIZE(mht_cpuport_clk_support_rates),
			mht_mac5_tx_clk_pdata, ARRAY_SIZE(mht_mac5_tx_clk_pdata)),
	CLK_LOOKUP(0x144, 0x148, 0x150, CBCR_CLK_RESET,
			MHT_MAC5_TX_UNIPHY0_CLK,
			mht_cpuport_clk_support_rates, ARRAY_SIZE(mht_cpuport_clk_support_rates),
			mht_mac5_tx_clk_pdata, ARRAY_SIZE(mht_mac5_tx_clk_pdata)),
	/* port 5 rx clock */
	CLK_LOOKUP(0x158, 0x15c, 0x160, CBCR_CLK_RESET,
			MHT_MAC5_RX_CLK,
			mht_cpuport_clk_support_rates, ARRAY_SIZE(mht_cpuport_clk_support_rates),
			mht_mac5_rx_clk_pdata, ARRAY_SIZE(mht_mac5_rx_clk_pdata)),
	CLK_LOOKUP(0x158, 0x15c, 0x164, CBCR_CLK_RESET,
			MHT_MAC5_RX_UNIPHY0_CLK,
			mht_cpuport_clk_support_rates, ARRAY_SIZE(mht_cpuport_clk_support_rates),
			mht_mac5_rx_clk_pdata, ARRAY_SIZE(mht_mac5_rx_clk_pdata)),
	/* AHB bridge clock */
	CLK_LOOKUP(0x16c, 0, 0x170, CBCR_CLK_RESET,
			MHT_AHB_CLK,
			mht_ahb_clk_support_rates, ARRAY_SIZE(mht_ahb_clk_support_rates),
			mht_ahb_clk_pdata, ARRAY_SIZE(mht_ahb_clk_pdata)),
	CLK_LOOKUP(0x16c, 0, 0x174, CBCR_CLK_RESET,
			MHT_SEC_CTRL_AHB_CLK,
			mht_ahb_clk_support_rates, ARRAY_SIZE(mht_ahb_clk_support_rates),
			mht_ahb_clk_pdata, ARRAY_SIZE(mht_ahb_clk_pdata)),
	CLK_LOOKUP(0x16c, 0, 0x178, CBCR_CLK_RESET,
			MHT_TLMM_CLK,
			mht_ahb_clk_support_rates, ARRAY_SIZE(mht_ahb_clk_support_rates),
			mht_ahb_clk_pdata, ARRAY_SIZE(mht_ahb_clk_pdata)),
	CLK_LOOKUP(0x16c, 0, 0x190, CBCR_CLK_RESET,
			MHT_TLMM_AHB_CLK,
			mht_ahb_clk_support_rates, ARRAY_SIZE(mht_ahb_clk_support_rates),
			mht_ahb_clk_pdata, ARRAY_SIZE(mht_ahb_clk_pdata)),
	CLK_LOOKUP(0x16c, 0, 0x194, CBCR_CLK_RESET,
			MHT_CNOC_AHB_CLK,
			mht_ahb_clk_support_rates, ARRAY_SIZE(mht_ahb_clk_support_rates),
			mht_ahb_clk_pdata, ARRAY_SIZE(mht_ahb_clk_pdata)),
	CLK_LOOKUP(0x16c, 0, 0x198, CBCR_CLK_RESET,
			MHT_MDIO_AHB_CLK,
			mht_ahb_clk_support_rates, ARRAY_SIZE(mht_ahb_clk_support_rates),
			mht_ahb_clk_pdata, ARRAY_SIZE(mht_ahb_clk_pdata)),
	CLK_LOOKUP(0x16c, 0, 0x19c, CBCR_CLK_RESET,
			MHT_MDIO_MASTER_AHB_CLK,
			mht_ahb_clk_support_rates, ARRAY_SIZE(mht_ahb_clk_support_rates),
			mht_ahb_clk_pdata, ARRAY_SIZE(mht_ahb_clk_pdata)),
	/* SYS clock */
	CLK_LOOKUP(0x1a4, 0, 0x1a8, CBCR_CLK_RESET,
			MHT_SRDS0_SYS_CLK,
			mht_sys_clk_support_rates, ARRAY_SIZE(mht_sys_clk_support_rates),
			mht_sys_clk_pdata, ARRAY_SIZE(mht_sys_clk_pdata)),
	CLK_LOOKUP(0x1a4, 0, 0x1ac, CBCR_CLK_RESET,
			MHT_SRDS1_SYS_CLK,
			mht_sys_clk_support_rates, ARRAY_SIZE(mht_sys_clk_support_rates),
			mht_sys_clk_pdata, ARRAY_SIZE(mht_sys_clk_pdata)),
	CLK_LOOKUP(0x1a4, 0, 0x1b0, CBCR_CLK_RESET,
			MHT_GEPHY0_SYS_CLK,
			mht_sys_clk_support_rates, ARRAY_SIZE(mht_sys_clk_support_rates),
			mht_sys_clk_pdata, ARRAY_SIZE(mht_sys_clk_pdata)),
	CLK_LOOKUP(0x1a4, 0, 0x1b4, CBCR_CLK_RESET,
			MHT_GEPHY1_SYS_CLK,
			mht_sys_clk_support_rates, ARRAY_SIZE(mht_sys_clk_support_rates),
			mht_sys_clk_pdata, ARRAY_SIZE(mht_sys_clk_pdata)),
	CLK_LOOKUP(0x1a4, 0, 0x1b8, CBCR_CLK_RESET,
			MHT_GEPHY2_SYS_CLK,
			mht_sys_clk_support_rates, ARRAY_SIZE(mht_sys_clk_support_rates),
			mht_sys_clk_pdata, ARRAY_SIZE(mht_sys_clk_pdata)),
	CLK_LOOKUP(0x1a4, 0, 0x1bc, CBCR_CLK_RESET,
			MHT_GEPHY3_SYS_CLK,
			mht_sys_clk_support_rates, ARRAY_SIZE(mht_sys_clk_support_rates),
			mht_sys_clk_pdata, ARRAY_SIZE(mht_sys_clk_pdata)),

	/* SEC control clock */
	CLK_LOOKUP(0x1c4, 0, 0x1c8, CBCR_CLK_RESET,
			MHT_SEC_CTRL_CLK,
			mht_sys_clk_support_rates, ARRAY_SIZE(mht_sys_clk_support_rates),
			mht_sys_clk_pdata, ARRAY_SIZE(mht_sys_clk_pdata)),
	CLK_LOOKUP(0x1c4, 0, 0x1d0, CBCR_CLK_RESET,
			MHT_SEC_CTRL_SENSE_CLK,
			mht_sys_clk_support_rates, ARRAY_SIZE(mht_sys_clk_support_rates),
			mht_sys_clk_pdata, ARRAY_SIZE(mht_sys_clk_pdata)),

	/* GEPHY reset */
	CLK_LOOKUP(0, 0, 0x304, BIT(0), MHT_GEPHY_P0_MDC_SW_RST, NULL, 0, NULL, 0),
	CLK_LOOKUP(0, 0, 0x304, BIT(1), MHT_GEPHY_P1_MDC_SW_RST, NULL, 0, NULL, 0),
	CLK_LOOKUP(0, 0, 0x304, BIT(2), MHT_GEPHY_P2_MDC_SW_RST, NULL, 0, NULL, 0),
	CLK_LOOKUP(0, 0, 0x304, BIT(3), MHT_GEPHY_P3_MDC_SW_RST, NULL, 0, NULL, 0),
	CLK_LOOKUP(0, 0, 0x304, BIT(4), MHT_GEPHY_DSP_HW_RST, NULL, 0, NULL, 0),

	/* Global reset */
	CLK_LOOKUP(0, 0, 0x308, BIT(0), MHT_GLOBAL_RST, NULL, 0, NULL, 0),

	/* XPCS reset */
	CLK_LOOKUP(0, 0, 0x30c, BIT(0), MHT_UNIPHY_XPCS_RST, NULL, 0, NULL, 0),
};

static inline struct clk_lookup *ssdk_mht_clk_find(const char *clock_id)
{
	int i;
	struct clk_lookup *clk;

	for (i = 0; i < ARRAY_SIZE(mht_clk_lookup_table); i++) {
		clk = &mht_clk_lookup_table[i];
		if (!strncmp(clock_id, clk->clk_name, strlen(clock_id)))
			return clk;
	}

	return NULL;
}

static inline sw_error_t ssdk_mht_clk_update(a_uint32_t dev_id, a_uint32_t cmd_reg)
{
	a_uint32_t i, reg_val;

	/* update RCG to the new programmed configuration */
	reg_val = qca_mht_mii_read(dev_id, cmd_reg);
	reg_val |= RCGR_CMD_UPDATE;
	qca_mht_mii_write(dev_id, cmd_reg, reg_val);

	for (i = 1000; i > 0; i--) {
		reg_val = qca_mht_mii_read(dev_id, cmd_reg);
		if (!(reg_val & RCGR_CMD_UPDATE))
			return SW_OK;

		udelay(1);
	}

	SSDK_ERROR("CLK cmd reg 0x%x fails updating to new configurations\n", cmd_reg);
	return SW_FAIL;
}

sw_error_t ssdk_mht_clk_assert(a_uint32_t dev_id, const char *clock_id)
{
	struct clk_lookup *clk;
	a_uint32_t cbc_reg = 0;

	clk = ssdk_mht_clk_find(clock_id);
	if (!clk) {
		SSDK_ERROR("CLK %s is not found!\n", clock_id);
		return SW_NOT_FOUND;
	}

	cbc_reg = MHT_CLK_BASE_REG + clk->cbc;

	qca_mht_mii_update(dev_id, cbc_reg, clk->rst_bit, clk->rst_bit);
	return SW_OK;
}

sw_error_t ssdk_mht_clk_deassert(a_uint32_t dev_id, const char *clock_id)
{
	struct clk_lookup *clk;
	a_uint32_t cbc_reg = 0;

	clk = ssdk_mht_clk_find(clock_id);
	if (!clk) {
		SSDK_ERROR("CLK %s is not found!\n", clock_id);
		return SW_NOT_FOUND;
	}

	cbc_reg = MHT_CLK_BASE_REG + clk->cbc;

	qca_mht_mii_update(dev_id, cbc_reg, clk->rst_bit, 0);
	return SW_OK;
}

sw_error_t ssdk_mht_clk_reset(a_uint32_t dev_id, const char *clock_id)
{
	sw_error_t rv = SW_OK;

	rv = ssdk_mht_clk_assert(dev_id, clock_id);
	SW_RTN_ON_ERROR(rv);

	/* Time required by HW to complete assert */
	udelay(10);

	rv = ssdk_mht_clk_deassert(dev_id, clock_id);

	return rv;
}

sw_error_t ssdk_mht_clk_enable(a_uint32_t dev_id, const char *clock_id)
{
	struct clk_lookup *clk;
	a_uint32_t cbc_reg = 0;

	clk = ssdk_mht_clk_find(clock_id);
	if (!clk) {
		SSDK_ERROR("CLK %s is not found!\n", clock_id);
		return SW_NOT_FOUND;
	}

	cbc_reg = MHT_CLK_BASE_REG + clk->cbc;

	qca_mht_mii_update(dev_id, cbc_reg, CBCR_CLK_ENABLE, CBCR_CLK_ENABLE);
	return SW_OK;
}

sw_error_t ssdk_mht_clk_disable(a_uint32_t dev_id, const char *clock_id)
{
	struct clk_lookup *clk;
	a_uint32_t cbc_reg = 0;

	clk = ssdk_mht_clk_find(clock_id);
	if (!clk) {
		SSDK_ERROR("CLK %s is not found!\n", clock_id);
		return SW_NOT_FOUND;
	}

	cbc_reg = MHT_CLK_BASE_REG + clk->cbc;

	qca_mht_mii_update(dev_id, cbc_reg, CBCR_CLK_ENABLE, 0);
	return SW_OK;
}

sw_error_t ssdk_mht_clk_parent_set(a_uint32_t dev_id,
		const char *clock_id, mht_clk_parent_t parent)
{
	struct clk_lookup *clk;
	a_uint32_t i, reg_val;
	a_uint32_t rcg_reg = 0, cmd_reg = 0, cfg = 0, cur_cfg = 0;
	const struct mht_parent_data *pdata = NULL;

	clk = ssdk_mht_clk_find(clock_id);
	if (!clk) {
		SSDK_ERROR("CLK %s is not found!\n", clock_id);
		return SW_NOT_FOUND;
	}

	for (i = 0; i < clk->num_parent; i++) {
		pdata = &(clk->pdata[i]);
		if (pdata->parent == parent)
			break;
	}

	if (i == clk->num_parent) {
		SSDK_ERROR("CLK %s is configured as incorrect parent %d\n", clock_id, parent);
		return SW_BAD_VALUE;
	}

	rcg_reg = MHT_CLK_BASE_REG + clk->rcg;
	cmd_reg = MHT_CLK_BASE_REG + clk->rcg - 4;

	reg_val = qca_mht_mii_read(dev_id, rcg_reg);
	cur_cfg = (reg_val & RCGR_SRC_SEL) >> RCGR_SRC_SEL_SHIFT;
	cfg = pdata->cfg;

	if (cfg == cur_cfg) {
		SSDK_DEBUG("CLK %s parent %d is already configured correctly\n", clock_id, parent);
		return SW_OK;
	}

	/* update clock parent */
	reg_val &= ~RCGR_SRC_SEL;
	reg_val |= cfg << RCGR_SRC_SEL_SHIFT;
	qca_mht_mii_write(dev_id, rcg_reg, reg_val);

	/* update RCG to the new programmed configuration */
	return ssdk_mht_clk_update(dev_id, cmd_reg);
}

void ssdk_mht_uniphy_raw_clock_set(a_uint32_t dev_id, mht_clk_parent_t uniphy_clk, a_uint64_t rate)
{
	switch (uniphy_clk) {
		case MHT_P_UNIPHY0_RX:
		case MHT_P_UNIPHY0_TX:
		case MHT_P_UNIPHY1_RX:
		case MHT_P_UNIPHY1_TX:
			break;
		default:
			SSDK_ERROR("Invalid uniphy_clk %d\n", uniphy_clk);
			return;
	}

	mht_uniphy_raw_clock[uniphy_clk - MHT_P_UNIPHY0_RX] = rate;
	return;
}

a_uint64_t ssdk_mht_uniphy_raw_clock_get(a_uint32_t dev_id, mht_clk_parent_t uniphy_clk)
{
	switch (uniphy_clk) {
		case MHT_P_UNIPHY0_RX:
		case MHT_P_UNIPHY0_TX:
		case MHT_P_UNIPHY1_RX:
		case MHT_P_UNIPHY1_TX:
			break;
		default:
			SSDK_ERROR("Invalid uniphy_clk %d\n", uniphy_clk);
			return MHT_XO_CLK_RATE_50M;
	}

	return mht_uniphy_raw_clock[uniphy_clk - MHT_P_UNIPHY0_RX];
}

sw_error_t ssdk_mht_clk_rate_set(a_uint32_t dev_id,
		const char *clock_id, a_uint32_t rate)
{
	struct clk_lookup *clk;
	a_uint64_t div, prate = 0;
	a_uint32_t i, reg_val, parent_index = 0;
	a_uint32_t rcg_reg = 0, cmd_reg = 0, cdiv_reg = 0, cdiv_val = 0;
	const struct mht_parent_data *pdata = NULL;

	clk = ssdk_mht_clk_find(clock_id);
	if (!clk) {
		SSDK_ERROR("CLK %s is not found!\n", clock_id);
		return SW_NOT_FOUND;
	}

	for (i = 0; i < clk->num_rate; i++)
		if (rate == clk->support_rate[i])
			break;

	if (i == clk->num_rate) {
		SSDK_ERROR("CLK %s does not support to configure rate %d\n", clock_id, rate);
		return SW_BAD_PARAM;
	}

	rcg_reg = MHT_CLK_BASE_REG + clk->rcg;
	cmd_reg = MHT_CLK_BASE_REG + clk->rcg - 4;
	if (clk->cdiv != 0)
		cdiv_reg = MHT_CLK_BASE_REG + clk->cdiv;

	reg_val = qca_mht_mii_read(dev_id, rcg_reg);

	/* get the parent rate of clock */
	parent_index = (reg_val & RCGR_SRC_SEL) >> RCGR_SRC_SEL_SHIFT;
	for (i = 0; i < clk->num_parent; i++) {
		pdata = &(clk->pdata[i]);
		if (pdata->cfg == parent_index) {
			/* uniphy0 rx, tx and unphy1 rx, tx clock can be 125M or 312.5M, which
			 * depends on the current link speed, the clock rate needs to be acquired
			 * dynamically.
			 */
			switch (pdata->parent) {
				case MHT_P_UNIPHY0_RX:
				case MHT_P_UNIPHY0_TX:
				case MHT_P_UNIPHY1_RX:
				case MHT_P_UNIPHY1_TX:
					prate = ssdk_mht_uniphy_raw_clock_get(dev_id,
							pdata->parent);
					break;
				default:
					/* XO 50M or 315P5M fix clock rate */
					prate = pdata->prate;
					break;
			}
			/* find the parent clock rate */
			break;
		}
	}

	if (i == clk->num_parent || prate == 0) {
		SSDK_ERROR("CLK %s is configured as unsupported parent value %d\n",
				clock_id, parent_index);
		return SW_BAD_VALUE;
	}

	/* when configuring XPSC clock to UQXGMII_XPCS_SPEED_2500M_CLK, the RCGR divider
	 * need to be bypassed, since there are two dividers from the same RCGR, one is
	 * for XPCS clock, the other is for EPHY port clock.
	 */
	if (rate == UQXGMII_XPCS_SPEED_2500M_CLK) {
		if (prate != UQXGMII_SPEED_2500M_CLK) {
			SSDK_ERROR("CLK %s parent(%lld) needs to be updated to %d\n",
					clock_id, prate, UQXGMII_SPEED_2500M_CLK);
			return SW_BAD_VALUE;
		}
		div = RCGR_DIV_BYPASS;
		cdiv_val = UQXGMII_SPEED_2500M_CLK / UQXGMII_XPCS_SPEED_2500M_CLK;
	} else {

		/* calculate the RCGR divider prate/rate = (rcg_divider + 1)/2 */
		div = prate * 2;
		do_div(div, rate);
		div--;

		/* if the RCG divider can't meet the requirement, the CDIV reg can be simply
		 * divided by 10 to satisfy the required clock rate.
		 */
		if (div > RCGR_DIV_MAX) {
			/* update CDIV Reg to be divided by 10(N+1) */
			cdiv_val = CDIVR_DIVIDER_10;

			/* caculate the new RCG divider */
			do_div(prate, CDIVR_DIVIDER_10 + 1);
			div = prate * 2;
			do_div(div, rate);
			div--;
		}
	}

	/* update CDIV Reg to be divided by N(N-1 for reg value) */
	if (cdiv_val > 0) {
		if (cdiv_reg == 0) {
			SSDK_ERROR("CLK %s needs CDIVR to generate rate %d from prate %lld\n",
					clock_id, rate, prate);
			return SW_BAD_VALUE;
		}
		qca_mht_mii_write(dev_id, cdiv_reg, cdiv_val);
	}

	/* update RCGR */
	reg_val &= ~RCGR_HDIV;
	reg_val |= div << RCGR_HDIV_SHIFT;
	qca_mht_mii_write(dev_id, rcg_reg, reg_val);

	/* update RCG to the new programmed configuration */
	return ssdk_mht_clk_update(dev_id, cmd_reg);
}

sw_error_t ssdk_mht_port5_uniphy0_clk_src_set(a_uint32_t dev_id, a_bool_t bypass_en)
{
	a_uint32_t mux_sel = 0;

	/* In switch mode, uniphy0 rx clock is from mac5 rx, uniphy0 tx clock is from mac5 tx;
	 * In bypass mode, uniphy0 rx clock is from mac4 tx, uniphy0 tx clock is from mac4 rx;
	 */

	if (bypass_en)
		mux_sel = MHT_UNIPHY0_SEL_MAC4;
	else
		mux_sel = MHT_UNIPHY0_SEL_MAC5;

	qca_mht_mii_update(dev_id, MHT_CLK_BASE_REG + MHT_CLK_MUX_SEL,
			MHT_UNIPHY0_MUX_SEL_MASK, mux_sel);
	return SW_OK;
}

sw_error_t ssdk_mht_port5_uniphy0_clk_src_get(a_uint32_t dev_id, a_bool_t *bypass_en)
{
	a_uint32_t reg_val = 0;

	/* In switch mode, uniphy0 rx clock is from mac5 rx, uniphy0 tx clock is from mac5 tx;
	 * In bypass mode, uniphy0 rx clock is from mac4 tx, uniphy0 tx clock is from mac4 rx;
	 */
	reg_val = qca_mht_mii_read(dev_id, MHT_CLK_BASE_REG + MHT_CLK_MUX_SEL);
	*bypass_en = (reg_val & MHT_UNIPHY0_MUX_SEL_MASK) ? A_FALSE : A_TRUE;

	return SW_OK;
}

sw_error_t ssdk_mht_port_clk_rate_set(a_uint32_t dev_id,
		a_uint32_t mht_port_id, a_uint32_t rate)
{
	sw_error_t rv = SW_OK;
	char *mac_rx_clk = NULL, *mac_tx_clk = NULL;
	char *xgmii_tx_clk = NULL, *xgmii_rx_clk = NULL;

	switch (mht_port_id) {
		case SSDK_PHYSICAL_PORT0:
			mac_rx_clk = MHT_MAC0_RX_CLK;
			mac_tx_clk = MHT_MAC0_TX_CLK;
			break;
		case SSDK_PHYSICAL_PORT1:
			mac_rx_clk = MHT_MAC1_RX_CLK;
			mac_tx_clk = MHT_MAC1_TX_CLK;
			xgmii_rx_clk = MHT_MAC1_UNIPHY1_CH0_XGMII_RX_CLK;
			xgmii_tx_clk = MHT_MAC1_UNIPHY1_CH0_XGMII_TX_CLK;
			break;
		case SSDK_PHYSICAL_PORT2:
			mac_rx_clk = MHT_MAC2_RX_CLK;
			mac_tx_clk = MHT_MAC2_TX_CLK;
			xgmii_rx_clk = MHT_MAC2_UNIPHY1_CH1_XGMII_RX_CLK;
			xgmii_tx_clk = MHT_MAC2_UNIPHY1_CH1_XGMII_TX_CLK;
			break;
		case SSDK_PHYSICAL_PORT3:
			mac_rx_clk = MHT_MAC3_RX_CLK;
			mac_tx_clk = MHT_MAC3_TX_CLK;
			xgmii_rx_clk = MHT_MAC3_UNIPHY1_CH2_XGMII_RX_CLK;
			xgmii_tx_clk = MHT_MAC3_UNIPHY1_CH2_XGMII_TX_CLK;
			break;
		case SSDK_PHYSICAL_PORT4:
			mac_rx_clk = MHT_MAC4_RX_CLK;
			mac_tx_clk = MHT_MAC4_TX_CLK;
			xgmii_rx_clk = MHT_MAC4_UNIPHY1_CH3_XGMII_RX_CLK;
			xgmii_tx_clk = MHT_MAC4_UNIPHY1_CH3_XGMII_TX_CLK;
			break;
		case SSDK_PHYSICAL_PORT5:
			mac_rx_clk = MHT_MAC5_RX_CLK;
			mac_tx_clk = MHT_MAC5_TX_CLK;
			break;
		default:
			SSDK_ERROR("Unsupported mht_port_id %d\n", mht_port_id);
			return SW_BAD_PARAM;
	}

	rv = ssdk_mht_clk_rate_set(dev_id, mac_rx_clk, rate);
	SW_RTN_ON_ERROR(rv);
	rv = ssdk_mht_clk_rate_set(dev_id, mac_tx_clk, rate);
	SW_RTN_ON_ERROR(rv);

	if (xgmii_rx_clk != NULL && xgmii_tx_clk != NULL) {
		/* XGMII take the different clock rate from MAC clock when the link
		 * speed is 2.5G.
		 */
		if (rate == UQXGMII_SPEED_2500M_CLK)
			rate = UQXGMII_XPCS_SPEED_2500M_CLK;
		rv = ssdk_mht_clk_rate_set(dev_id, xgmii_rx_clk, rate);
		SW_RTN_ON_ERROR(rv);
		rv = ssdk_mht_clk_rate_set(dev_id, xgmii_tx_clk, rate);
		SW_RTN_ON_ERROR(rv);
	}

	return SW_OK;
}

static inline sw_error_t ssdk_mht_clk_ids_get(a_uint32_t mht_port_id,
		a_uint8_t mask, char **clk_ids)
{
	switch (mht_port_id) {
		case SSDK_PHYSICAL_PORT0:
			if (mask & MHT_CLK_TYPE_MAC) {
				*clk_ids++ = MHT_MAC0_TX_CLK;
				*clk_ids++ = MHT_MAC0_RX_CLK;
			}

			if (mask & MHT_CLK_TYPE_UNIPHY) {
				*clk_ids++ = MHT_MAC0_TX_UNIPHY1_CLK;
				*clk_ids++ = MHT_MAC0_RX_UNIPHY1_CLK;
			}
			break;
		case SSDK_PHYSICAL_PORT1:
			if (mask & MHT_CLK_TYPE_MAC) {
				*clk_ids++ = MHT_MAC1_TX_CLK;
				*clk_ids++ = MHT_MAC1_RX_CLK;
			}

			if (mask & MHT_CLK_TYPE_UNIPHY) {
				*clk_ids++ = MHT_MAC1_UNIPHY1_CH0_RX_CLK;
				*clk_ids++ = MHT_MAC1_UNIPHY1_CH0_TX_CLK;
				*clk_ids++ = MHT_MAC1_UNIPHY1_CH0_XGMII_RX_CLK;
				*clk_ids++ = MHT_MAC1_UNIPHY1_CH0_XGMII_TX_CLK;
			}

			if (mask & MHT_CLK_TYPE_EPHY) {
				*clk_ids++ = MHT_MAC1_GEPHY0_TX_CLK;
				*clk_ids++ = MHT_MAC1_GEPHY0_RX_CLK;
			}
			break;
		case SSDK_PHYSICAL_PORT2:
			if (mask & MHT_CLK_TYPE_MAC) {
				*clk_ids++ = MHT_MAC2_TX_CLK;
				*clk_ids++ = MHT_MAC2_RX_CLK;
			}

			if (mask & MHT_CLK_TYPE_UNIPHY) {
				*clk_ids++ = MHT_MAC2_UNIPHY1_CH1_RX_CLK;
				*clk_ids++ = MHT_MAC2_UNIPHY1_CH1_TX_CLK;
				*clk_ids++ = MHT_MAC2_UNIPHY1_CH1_XGMII_RX_CLK;
				*clk_ids++ = MHT_MAC2_UNIPHY1_CH1_XGMII_TX_CLK;
			}

			if (mask & MHT_CLK_TYPE_EPHY) {
				*clk_ids++ = MHT_MAC2_GEPHY1_TX_CLK;
				*clk_ids++ = MHT_MAC2_GEPHY1_RX_CLK;
			}
			break;
		case SSDK_PHYSICAL_PORT3:
			if (mask & MHT_CLK_TYPE_MAC) {
				*clk_ids++ = MHT_MAC3_TX_CLK;
				*clk_ids++ = MHT_MAC3_RX_CLK;
			}

			if (mask & MHT_CLK_TYPE_UNIPHY) {
				*clk_ids++ = MHT_MAC3_UNIPHY1_CH2_RX_CLK;
				*clk_ids++ = MHT_MAC3_UNIPHY1_CH2_TX_CLK;
				*clk_ids++ = MHT_MAC3_UNIPHY1_CH2_XGMII_RX_CLK;
				*clk_ids++ = MHT_MAC3_UNIPHY1_CH2_XGMII_TX_CLK;
			}

			if (mask & MHT_CLK_TYPE_EPHY) {
				*clk_ids++ = MHT_MAC3_GEPHY2_TX_CLK;
				*clk_ids++ = MHT_MAC3_GEPHY2_RX_CLK;
			}
			break;
		case SSDK_PHYSICAL_PORT4:
			if (mask & MHT_CLK_TYPE_MAC) {
				*clk_ids++ = MHT_MAC4_TX_CLK;
				*clk_ids++ = MHT_MAC4_RX_CLK;
			}

			if (mask & MHT_CLK_TYPE_UNIPHY) {
				*clk_ids++ = MHT_MAC4_UNIPHY1_CH3_RX_CLK;
				*clk_ids++ = MHT_MAC4_UNIPHY1_CH3_TX_CLK;
				*clk_ids++ = MHT_MAC4_UNIPHY1_CH3_XGMII_RX_CLK;
				*clk_ids++ = MHT_MAC4_UNIPHY1_CH3_XGMII_TX_CLK;
			}

			if (mask & MHT_CLK_TYPE_EPHY) {
				*clk_ids++ = MHT_MAC4_GEPHY3_TX_CLK;
				*clk_ids++ = MHT_MAC4_GEPHY3_RX_CLK;
			}
			break;
		case SSDK_PHYSICAL_PORT5:
			if (mask & MHT_CLK_TYPE_MAC) {
				*clk_ids++ = MHT_MAC5_TX_CLK;
				*clk_ids++ = MHT_MAC5_RX_CLK;
			}

			if (mask & MHT_CLK_TYPE_UNIPHY) {
				*clk_ids++ = MHT_MAC5_TX_UNIPHY0_CLK;
				*clk_ids++ = MHT_MAC5_RX_UNIPHY0_CLK;
			}
			break;
		default:
			SSDK_ERROR("Unsupported mht_port_id %d\n", mht_port_id);
			return SW_BAD_PARAM;
	}

	return SW_OK;
}

sw_error_t ssdk_mht_port_clk_reset(a_uint32_t dev_id, a_uint32_t mht_port_id, a_uint8_t mask)
{
	sw_error_t rv = SW_OK;
	char *clk_ids[MHT_PORT_CLK_CBC_MAX + 1] = {NULL};
	a_uint32_t i = 0;

	rv = ssdk_mht_clk_ids_get(mht_port_id, mask, clk_ids);
	SW_RTN_ON_ERROR(rv);

	while(clk_ids[i] != NULL) {
		rv = ssdk_mht_clk_reset(dev_id, clk_ids[i]);
		SW_RTN_ON_ERROR(rv);
		i++;
	}

	return SW_OK;
}

sw_error_t ssdk_mht_port_clk_en_set(a_uint32_t dev_id,
		a_uint32_t mht_port_id, a_uint8_t mask, a_bool_t enable)
{
	sw_error_t rv = SW_OK;
	char *clk_ids[MHT_PORT_CLK_CBC_MAX + 1] = {NULL};
	a_uint32_t i = 0;

	rv = ssdk_mht_clk_ids_get(mht_port_id, mask, clk_ids);
	SW_RTN_ON_ERROR(rv);

	while(clk_ids[i] != NULL) {
		if (enable)
			rv = ssdk_mht_clk_enable(dev_id, clk_ids[i]);
		else
			rv = ssdk_mht_clk_disable(dev_id, clk_ids[i]);
		SW_RTN_ON_ERROR(rv);
		i++;
	}

	return SW_OK;
}
