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
#include "adpt.h"
#include "appe_portvlan.h"
#include "appe_l2_vp.h"

sw_error_t
adpt_appe_port_vlan_vpgroup_set(a_uint32_t dev_id, a_uint32_t vport_id,
		fal_port_vlan_direction_t direction, a_uint32_t vpgroup_id)
{
	sw_error_t rtn = SW_OK;

	ADPT_DEV_ID_CHECK(dev_id);

	switch (direction) {
		case FAL_PORT_VLAN_INGRESS:
			rtn = appe_vlan_port_vp_tbl_vlan_profile_set(dev_id, vport_id, vpgroup_id);
			break;
		case FAL_PORT_VLAN_EGRESS:
			rtn = appe_eg_vp_tbl_xlat_profile_set(dev_id, vport_id, vpgroup_id);
			SW_RTN_ON_ERROR(rtn);
			break;
		case FAL_PORT_VLAN_ALL:
		default:
			rtn = SW_BAD_PARAM;
			break;
	}

	return rtn;
}

sw_error_t
adpt_appe_port_vlan_vpgroup_get(a_uint32_t dev_id, a_uint32_t vport_id,
		fal_port_vlan_direction_t direction, a_uint32_t *vpgroup_id)
{
	sw_error_t rtn = SW_OK;

	ADPT_DEV_ID_CHECK(dev_id);

	switch (direction) {
		case FAL_PORT_VLAN_INGRESS:
			rtn = appe_vlan_port_vp_tbl_vlan_profile_get(dev_id, vport_id, vpgroup_id);
			SW_RTN_ON_ERROR(rtn);
			break;
		case FAL_PORT_VLAN_EGRESS:
			rtn = appe_eg_vp_tbl_xlat_profile_get(dev_id, vport_id, vpgroup_id);
			SW_RTN_ON_ERROR(rtn);
			break;
		case FAL_PORT_VLAN_ALL:
		default:
			rtn = SW_BAD_PARAM;
			break;
	}

	return rtn;
}

sw_error_t
adpt_appe_portvlan_vpmember_get(a_uint32_t dev_id, fal_port_t port_id, fal_pbmp_t * mem_port_map)
{
	ADPT_DEV_ID_CHECK(dev_id);
	ADPT_NULL_POINT_CHECK(mem_port_map);
	port_id = FAL_PORT_ID_VALUE(port_id);

	return appe_l2_vp_port_tbl_port_isolation_bitmap_get(dev_id, port_id, mem_port_map);
}

sw_error_t
adpt_appe_portvlan_vpmember_update(a_uint32_t dev_id, fal_port_t port_id, fal_pbmp_t mem_port_map)
{
	ADPT_DEV_ID_CHECK(dev_id);
	port_id = FAL_PORT_ID_VALUE(port_id);

	return appe_l2_vp_port_tbl_port_isolation_bitmap_set(dev_id, port_id, (a_uint32_t)mem_port_map);
}

sw_error_t
adpt_appe_portvlan_vpmember_add(a_uint32_t dev_id, fal_port_t port_id, fal_port_t mem_port_id)
{
	sw_error_t rv = SW_OK;
	union l2_vp_port_tbl_u l2_vp_port_tbl = {0};

	ADPT_DEV_ID_CHECK(dev_id);
	port_id = FAL_PORT_ID_VALUE(port_id);
	mem_port_id = FAL_PORT_ID_VALUE(mem_port_id);

	rv = appe_l2_vp_port_tbl_get(dev_id, port_id, &l2_vp_port_tbl);
	SW_RTN_ON_ERROR(rv);

	l2_vp_port_tbl.bf.port_isolation_bitmap |= (0x1 << mem_port_id);

	rv = appe_l2_vp_port_tbl_set(dev_id, port_id, &l2_vp_port_tbl);

	return rv;
}

sw_error_t
adpt_appe_portvlan_vpmember_del(a_uint32_t dev_id, fal_port_t port_id, fal_port_t mem_port_id)
{
	sw_error_t rv = SW_OK;
	union l2_vp_port_tbl_u l2_vp_port_tbl = {0};

	ADPT_DEV_ID_CHECK(dev_id);
	port_id = FAL_PORT_ID_VALUE(port_id);
	mem_port_id = FAL_PORT_ID_VALUE(mem_port_id);

	rv = appe_l2_vp_port_tbl_get(dev_id, port_id, &l2_vp_port_tbl);
	SW_RTN_ON_ERROR(rv);

	l2_vp_port_tbl.bf.port_isolation_bitmap &= ~(0x1 << mem_port_id);

	rv = appe_l2_vp_port_tbl_set(dev_id, port_id, &l2_vp_port_tbl);

	return rv;
}

/**
 * @}
 */
