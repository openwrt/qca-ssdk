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


#ifndef _MHT_PORT_CTRL_H_
#define _MHT_PORT_CTRL_H_

#ifdef __cplusplus
extern "C"
{
#endif				/* __cplusplus */

#include "fal_port_ctrl.h"
sw_error_t
mht_port_congestion_drop_set(a_uint32_t dev_id, fal_port_t port_id,
		a_uint32_t queue_id, a_bool_t enable);
sw_error_t
mht_port_congestion_drop_get(a_uint32_t dev_id, fal_port_t port_id,
		a_uint32_t queue_id, a_bool_t * enable);
sw_error_t
mht_ring_flow_ctrl_thres_set(a_uint32_t dev_id, a_uint32_t ring_id,
		a_uint16_t on_thres, a_uint16_t off_thres);
sw_error_t
mht_ring_flow_ctrl_thres_get(a_uint32_t dev_id, a_uint32_t ring_id,
		a_uint16_t * on_thres, a_uint16_t * off_thres);
sw_error_t
mht_ring_flow_ctrl_status_get(a_uint32_t dev_id, a_uint32_t ring_id, a_bool_t *status);
#ifdef __cplusplus
}
#endif				/* __cplusplus */
#endif				/* _MHT_PORT_CTRL_H_ */
