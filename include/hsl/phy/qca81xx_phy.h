/*
 * Copyright (c) 2024-2025 Qualcomm Innovation Center, Inc. All rights reserved.
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

#ifndef _QCA81XX_PHY_H_
#define _QCA81XX_PHY_H_

#ifdef __cplusplus
extern "C"
{
#endif				/* __cplusplus */
/*PHY debug registers*/
#define QCA81XX_PHY_DEBUG_HIBERNATION_CTRL                     0xb
#define QCA81XX_PHY_DEBUG_HIBERNATION_STAT                     0xc
#define QCA81XX_PHY_DEBUG_AFE_DAC8_DP                          0x2f80
#define QCA81XX_PHY_DEBUG_AFE_DAC9_DP                          0x3080

/*PHY debug register fields*/
#define QCA81XX_PHY_HIBERNATION_CFG                            0x8000
#define QCA81XX_PHY_HIBERNATION_STAT_EN                        0x0800

/*PHY MMD3 registers*/
#define QCA81XX_PHY_MMD3_10G_FRAME_CHECK_CTRL                  0xa110
#define QCA81XX_PHY_MMD3_10G_EGRESS_COUNTER_HIGH               0xa146
#define QCA81XX_PHY_MMD3_10G_EGRESS_COUNTER_MIDDLE             0xa115
#define QCA81XX_PHY_MMD3_10G_EGRESS_COUNTER_LOW                0xa114
#define QCA81XX_PHY_MMD3_10G_EGRESS_ERROR_COUNTER              0xa116
#define QCA81XX_PHY_MMD3_10G_INGRESS_COUNTER_HIGH              0xa145
#define QCA81XX_PHY_MMD3_10G_INGRESS_COUNTER_MIDDLE            0xa119
#define QCA81XX_PHY_MMD3_10G_INGRESS_COUNTER_LOW               0xa118
#define QCA81XX_PHY_MMD3_10G_INGRESS_ERROR_COUNTER             0xa11a
#define QCA81XX_PHY_MMD3_CDT_STATUS                            0x8064
#define QCA81XX_PHY_MMD3_CDT_PAIR0                             0x8065
#define QCA81XX_PHY_MMD3_CDT_PAIR1                             0x8066
#define QCA81XX_PHY_MMD3_CDT_PAIR2                             0x8067
#define QCA81XX_PHY_MMD3_CDT_PAIR3                             0x8068
#define QCA81XX_PHY_MMD3_WOL_MAGIC_MAC_CTRL1                   0x804a
#define QCA81XX_PHY_MMD3_WOL_MAGIC_MAC_CTRL2                   0x804b
#define QCA81XX_PHY_MMD3_WOL_MAGIC_MAC_CTRL3                   0x804c
#define QCA81XX_PHY_MMD3_WOL_CTRL                              0x8012
#define QCA81XX_PHY_MMD3_ADDR_REMOTE_LOOPBACK_CTRL             0x805a
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL2                      0x8073
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL3                      0x8074
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL4                      0x8075
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL5                      0x8076
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL6                      0x8077
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL7                      0x8078
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL9                      0x807a
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL13                     0x807e
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL14                     0x807f
#define QCA81XX_PHY_MMD3_BYPASS_SIGNAL                         0x2003

/*PHY MMD3 register fields*/
#define QCA81XX_PHY_MMD3_REMOTE_LOOPBACK_EN                    0x0001
#define QCA81XX_PHY_MMD3_WOL_EN                                0x0020
#define QCA81XX_PHY_MMD3_10G_FRAME_CHECK_EN                    0x80
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL2_VAL                  0xb03f
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL3_VAL                  0xc040
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL4_VAL                  0xa060
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL5_VAL                  0xc040
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL6_VAL                  0xa060
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL7_VAL                  0xae50
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL9_VAL                  0xc060
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL13_VAL                 0xb060
#define QCA81XX_PHY_MMD3_CDT_THRESH_CTRL14_VAL                 0xb8b0
#define QCA81XX_PHY_MMD3_PCS_BYPASS_LINK                       0x200

/*PHY MMD7 registers*/
#define QCA81XX_PHY_MMD7_COUNTER_CTRL                          0x8029
#define QCA81XX_PHY_MMD7_INGRESS_COUNTER_HIGH                  0x802a
#define QCA81XX_PHY_MMD7_INGRESS_COUNTER_LOW                   0x802b
#define QCA81XX_PHY_MMD7_INGRESS_ERROR_COUNTER                 0x802c
#define QCA81XX_PHY_MMD7_EGRESS_COUNTER_HIGH                   0x802d
#define QCA81XX_PHY_MMD7_EGRESS_COUNTER_LOW                    0x802e
#define QCA81XX_PHY_MMD7_EGRESS_ERROR_COUNTER                  0x802f
#define QCA81XX_PHY_MMD7_LED0_CTRL                             0x8078
#define QCA81XX_PHY_MMD7_LED1_CTRL                             0x8074
#define QCA81XX_PHY_MMD7_LED2_CTRL                             0x8076
#define QCA81XX_PHY_MMD7_LED0_FORCE_CTRL                       0x8079
#define QCA81XX_PHY_MMD7_LED1_FORCE_CTRL                       0x8075
#define QCA81XX_PHY_MMD7_LED2_FORCE_CTRL                       0x8077
#define QCA81XX_PHY_MMD7_LED_10G_CTRL                          0x807a

/*PHY MMD7 register fields*/
#define QCA81XX_PHY_MMD7_FRAME_CHECK_EN                        0x0001
#define QCA81XX_PHY_MMD7_XMIT_MAC_CNT_SELFCLR                  0x0002
#define QCA81XX_PHY_MMD7_LINK_2500M_LIGHT_EN                   0x8000
#define QCA81XX_PHY_MMD7_10G_SRC0_OFFSET                       0x7
#define QCA81XX_PHY_MMD7_5G_SRC0_OFFSET                        0x1

/*PHY MMD31 registers*/
#define QCA81XX_PHY_INTR_MASK                                  0x12
#define QCA81XX_PHY_INTR_STATUS                                0x13
#define QCA81XX_PHY_CDT_CONTROL                                0x16

/*PHY MMD31 register fields*/
#define QCA81XX_PHY_INTR_SPEED_CHANGE                          0x4000
#define QCA81XX_PHY_INTR_STATUS_DOWN_CHANGE                    0x0800
#define QCA81XX_PHY_INTR_STATUS_UP_CHANGE                      0x0400
#define QCA81XX_PHY_INTR_POE                                   0x0002
#define QCA81XX_PHY_INTR_WOL                                   0x0001
#define QCA81XX_PHY_MDI_PAIR_NUM                               0x4
#define QCA81XX_PHY_RUN_CDT                                    0x8000
#define QCA81XX_PHY_CABLE_LENGTH_UNIT                          0x0400
#define QCA81XX_PHY_AUTO_SOFT_RESET_EN                         0x8

/*SERDES registers*/
#define QCA81XX_PHY_PCS_PLL_POWER_ON_AND_RESET                 0
#define QCA81XX_PHY_PCS_ANA_SOFT_RESET_MASK                    0x40
#define QCA81XX_PHY_PCS_ANA_SOFT_RELEASE                       0x40
#define QCA81XX_PHY_PCS_ANA_SOFT_RESET                         0

int qca81xx_phy_init(a_uint32_t dev_id, a_uint32_t port_bmp);
void qca81xx_phy_exit(a_uint32_t dev_id, a_uint32_t port_bmp);
sw_error_t qca81xx_phy_poweron(a_uint32_t dev_id, a_uint32_t phy_addr);
sw_error_t qca81xx_phy_poweroff(a_uint32_t dev_id, a_uint32_t phy_addr);
sw_error_t qca81xx_phy_soft_reset(a_uint32_t dev_id, a_uint32_t phy_addr);
#ifdef __cplusplus
}
#endif				/* __cplusplus */
#endif				/* _qca808x_PHY_H_ */
