/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
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
#include "fal_vport.h"
#include "appe_l2_vp_reg.h"
#include "appe_l2_vp.h"
#include "adpt.h"

sw_error_t
adpt_appe_vport_physical_port_id_get(a_uint32_t dev_id,
		fal_port_t vport_id, fal_port_t *phyport_id)
{
	sw_error_t rv = SW_OK;
	a_uint32_t pport_id = 0;
	a_uint32_t vport_value = FAL_PORT_ID_VALUE(vport_id);

	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(phyport_id);

	rv = appe_l2_vp_port_tbl_physical_port_get(dev_id, vport_value, &pport_id);
	SW_RTN_ON_ERROR(rv);

	*phyport_id = FAL_PORT_ID(FAL_PORT_TYPE_PPORT, pport_id);

	return rv;
}

sw_error_t
adpt_appe_vport_physical_port_id_set(a_uint32_t dev_id,
		fal_port_t vport_id, fal_port_t phyport_id)
{
	sw_error_t rv = SW_OK;
	a_uint32_t pport_id = 0;
	a_uint32_t vport_value = 0;

	ADPT_DEV_ID_CHECK(dev_id);

	vport_value = FAL_PORT_ID_VALUE(vport_id);
	pport_id = FAL_PORT_ID_VALUE(phyport_id);

	rv = appe_l2_vp_port_tbl_physical_port_set(dev_id, vport_value, pport_id);

	return rv;
}

void adpt_appe_vport_func_bitmap_init(a_uint32_t dev_id)
{
	adpt_api_t *p_adpt_api = NULL;

	p_adpt_api = adpt_api_ptr_get(dev_id);

	if(p_adpt_api == NULL)
		return;

	p_adpt_api->adpt_vport_func_bitmap = 0;

	return;
}

static void adpt_appe_vport_func_unregister(a_uint32_t dev_id, adpt_api_t *p_adpt_api)
{
	if(p_adpt_api == NULL)
		return;

	p_adpt_api->adpt_vport_physical_port_id_set = NULL;
	p_adpt_api->adpt_vport_physical_port_id_get = NULL;

	return;
}

sw_error_t
adpt_appe_vport_init(a_uint32_t dev_id)
{
	adpt_api_t *p_adpt_api = NULL;

	p_adpt_api = adpt_api_ptr_get(dev_id);

	ADPT_NULL_POINT_CHECK(p_adpt_api);

	adpt_appe_vport_func_unregister(dev_id, p_adpt_api);

	if (p_adpt_api->adpt_vport_func_bitmap & (1 << FUNC_VPORT_PHYSICAL_PORT_SET))
		p_adpt_api->adpt_vport_physical_port_id_set =
			adpt_appe_vport_physical_port_id_set;
	if (p_adpt_api->adpt_vport_func_bitmap & (1 << FUNC_VPORT_PHYSICAL_PORT_GET))
		p_adpt_api->adpt_vport_physical_port_id_get =
			adpt_appe_vport_physical_port_id_get;


	return SW_OK;
}

/**
 * @}
 */
