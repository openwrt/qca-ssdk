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
 * @defgroup mht_init MHT_INIT
 * @{
 */
#include "sw.h"
#include "ssdk_init.h"
#include "ssdk_plat.h"
#include "mht_sec_ctrl.h"
#include "ssdk_dts.h"

static sw_error_t
qca_mht_work_mode_init(a_uint32_t dev_id)
{
	mht_work_mode_t clk_mode = ssdk_clk_mode_get(dev_id);

	if (clk_mode == MHT_WORK_MODE_MAX)
		return SW_OUT_OF_RANGE;

	return qca_mht_work_mode_set(dev_id, clk_mode);
}

int qca_mht_hw_init(struct qca_phy_priv *priv)
{
	int ret = 0;
	a_uint32_t dev_id;

	SW_RTN_ON_NULL(priv);

	dev_id = priv->device_id;

	ret = qca_mht_work_mode_init(dev_id);
	SW_RTN_ON_ERROR(ret);

	ret = qca_switch_init(dev_id);
	SW_RTN_ON_ERROR(ret);

#ifdef IN_PORTVLAN
	ssdk_portvlan_init(dev_id);
#endif
	return ret;
}

/**
 * @}
 */
