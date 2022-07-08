/*
 * Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
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
 * @defgroup
 * @{
 */
#include "sw.h"
#include "adpt.h"
#include "mppe_servcode_reg.h"
#include "mppe_servcode.h"

#define ADPT_MAX_SERVCODE_NUM 256

sw_error_t
adpt_mppe_port_servcode_set(a_uint32_t dev_id, fal_port_t port_id,
			a_uint32_t servcode_index)
{
	union tl_vp_service_code_gen_u reg_val = {0};

	ADPT_DEV_ID_CHECK(dev_id);

	if((servcode_index >= ADPT_MAX_SERVCODE_NUM &&
		servcode_index != FAL_SERVCODE_INVALID)||
		(FAL_PORT_ID_VALUE(port_id) >= TL_VP_SERVICE_CODE_GEN_MAX_ENTRY))
	{
		return SW_OUT_OF_RANGE;
	}

	SW_RTN_ON_ERROR(mppe_tl_vp_service_code_gen_get(dev_id,
					FAL_PORT_ID_VALUE(port_id), &reg_val));

	if(FAL_SERVCODE_INVALID == servcode_index)
	{
		reg_val.bf.service_code_en = A_FALSE;
		reg_val.bf.service_code = 0;
	}
	else
	{
		reg_val.bf.service_code_en = A_TRUE;
		reg_val.bf.service_code = servcode_index;
	}
	return mppe_tl_vp_service_code_gen_set(dev_id,
					FAL_PORT_ID_VALUE(port_id), &reg_val);
}

sw_error_t
adpt_mppe_port_servcode_get(a_uint32_t dev_id, fal_port_t port_id,
			a_uint32_t *servcode_index)
{
	union tl_vp_service_code_gen_u reg_val={0};

	ADPT_DEV_ID_CHECK(dev_id);

	if(FAL_PORT_ID_VALUE(port_id) >= TL_VP_SERVICE_CODE_GEN_MAX_ENTRY)
	{
		return SW_OUT_OF_RANGE;
	}

	SW_RTN_ON_ERROR(mppe_tl_vp_service_code_gen_get(dev_id,
					FAL_PORT_ID_VALUE(port_id), &reg_val));

	if(reg_val.bf.service_code_en)
	{
		*servcode_index = reg_val.bf.service_code;
	}
	else
	{
		*servcode_index = FAL_SERVCODE_INVALID;
	}
	return SW_OK;
}

/**
 * @}
 */


