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
 * @defgroup mht_init MHT_SEC_CTRL
 * @{
 */
#ifndef _MHT_SEC_CTRL_H_
#define _MHT_SEC_CTRL_H_


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum {
	SWITCH_MODE = 0,
	SWITCH_BYPASS_PORT5_MODE,
	PHY_USXGMII_MODE,
	PHY_SGMII_USXGMII_MODE,
} mht_work_mode_t;

sw_error_t
qca_mht_work_mode_set(a_uint32_t dev_id, mht_work_mode_t work_mode);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MHT_SEC_CTRL_H_ */
/**
 * @}
 */
