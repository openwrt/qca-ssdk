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
#include "fal_tunnel.h"
#include "appe_tunnel_reg.h"
#include "appe_tunnel.h"
#include "adpt.h"

sw_error_t
adpt_appe_tunnel_decap_entry_add(a_uint32_t dev_id,
		fal_tunnel_op_mode_t add_mode, fal_tunnel_decap_entry_t *value)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_decap_entry_del(a_uint32_t dev_id,
		fal_tunnel_op_mode_t del_mode, fal_tunnel_decap_entry_t *value)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_decap_entry_get(a_uint32_t dev_id,
		fal_tunnel_op_mode_t get_mode, fal_tunnel_decap_entry_t *entry)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_decap_entry_getnext(a_uint32_t dev_id,
		fal_tunnel_op_mode_t next_mode, fal_tunnel_decap_entry_t *value)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_decap_entry_flush(a_uint32_t dev_id)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_header_ctrl_set(a_uint32_t dev_id,
		fal_tunnel_encap_header_ctrl_t *header_ctrl)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_header_ctrl_get(a_uint32_t dev_id,
		fal_tunnel_encap_header_ctrl_t *header_ctrl)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_decap_header_ctrl_set(a_uint32_t dev_id,
		fal_tunnel_decap_header_ctrl_t *header_ctrl)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_decap_header_ctrl_get(a_uint32_t dev_id,
		fal_tunnel_decap_header_ctrl_t *header_ctrl)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_global_cfg_get(a_uint32_t dev_id,
		fal_tunnel_global_cfg_t *cfg)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_global_cfg_set(a_uint32_t dev_id,
		fal_tunnel_global_cfg_t *cfg)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_port_intf_set(a_uint32_t dev_id,
		fal_port_t port_id, fal_tunnel_intf_t *port_cfg)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_port_intf_get(a_uint32_t dev_id,
		fal_port_t port_id, fal_tunnel_intf_t *port_cfg)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_vlan_intf_add(a_uint32_t dev_id,
		fal_tunnel_vlan_intf_t *vlan_cfg)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_vlan_intf_getfirst(a_uint32_t dev_id,
		fal_tunnel_vlan_intf_t *vlan_cfg)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_vlan_intf_getnext(a_uint32_t dev_id,
		fal_tunnel_vlan_intf_t *vlan_cfg)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_vlan_intf_del(a_uint32_t dev_id,
		fal_tunnel_vlan_intf_t *vlan_cfg)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_intf_set(a_uint32_t dev_id,
		a_uint32_t l3_if, fal_tunnel_intf_t *intf_t)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_intf_get(a_uint32_t dev_id,
		a_uint32_t l3_if, fal_tunnel_intf_t *intf_t)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_port_tunnelid_set(a_uint32_t dev_id,
		fal_port_t port_id, fal_tunnel_id_t *tunnel_id)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_port_tunnelid_get(a_uint32_t dev_id,
		fal_port_t port_id, fal_tunnel_id_t *tunnel_id)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_intf_tunnelid_set(a_uint32_t dev_id,
		a_uint32_t intf_id, fal_tunnel_id_t *tunnel_id)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_intf_tunnelid_get(a_uint32_t dev_id,
		a_uint32_t intf_id, fal_tunnel_id_t *tunnel_id)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_entry_add(a_uint32_t dev_id,
		a_uint32_t tunnel_id, fal_tunnel_encap_cfg_t *tunnel_encap_cfg)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_entry_del(a_uint32_t dev_id,
		a_uint32_t tunnel_id)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_entry_get(a_uint32_t dev_id,
		a_uint32_t tunnel_id, fal_tunnel_encap_cfg_t *tunnel_encap_cfg)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_entry_getnext(a_uint32_t dev_id,
		a_uint32_t tunnel_id, fal_tunnel_encap_cfg_t *tunnel_encap_cfg)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_rule_entry_set(a_uint32_t dev_id,
		a_uint32_t rule_id, fal_tunnel_encap_rule_t *rule_entry)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_rule_entry_get(a_uint32_t dev_id,
		a_uint32_t rule_id, fal_tunnel_encap_rule_t *rule_entry)
{
	sw_error_t rv = SW_OK;
	return rv;
}

sw_error_t
adpt_appe_tunnel_encap_rule_entry_del(a_uint32_t dev_id,
		a_uint32_t rule_id, fal_tunnel_encap_rule_t *rule_entry)
{
	sw_error_t rv = SW_OK;
	return rv;
}

void adpt_appe_tunnel_func_bitmap_init(a_uint32_t dev_id)
{
	adpt_api_t *p_adpt_api = NULL;

	p_adpt_api = adpt_api_ptr_get(dev_id);

	if(p_adpt_api == NULL)
		return;

	p_adpt_api->adpt_tunnel_func_bitmap = 0;

	return;
}

static void adpt_appe_tunnel_func_unregister(a_uint32_t dev_id, adpt_api_t *p_adpt_api)
{
	if(p_adpt_api == NULL)
		return;

	p_adpt_api->adpt_tunnel_decap_entry_add = NULL;
	p_adpt_api->adpt_tunnel_decap_entry_del = NULL;
	p_adpt_api->adpt_tunnel_decap_entry_get = NULL;
	p_adpt_api->adpt_tunnel_decap_entry_getnext = NULL;
	p_adpt_api->adpt_tunnel_decap_entry_flush = NULL;
	p_adpt_api->adpt_tunnel_global_cfg_get = NULL;
	p_adpt_api->adpt_tunnel_global_cfg_set = NULL;
	p_adpt_api->adpt_tunnel_port_intf_set = NULL;
	p_adpt_api->adpt_tunnel_port_intf_get = NULL;
	p_adpt_api->adpt_tunnel_vlan_intf_add = NULL;
	p_adpt_api->adpt_tunnel_vlan_intf_getfirst = NULL;
	p_adpt_api->adpt_tunnel_vlan_intf_getnext = NULL;
	p_adpt_api->adpt_tunnel_vlan_intf_del = NULL;
	p_adpt_api->adpt_tunnel_intf_set = NULL;
	p_adpt_api->adpt_tunnel_intf_get = NULL;
	p_adpt_api->adpt_tunnel_encap_port_tunnelid_set = NULL;
	p_adpt_api->adpt_tunnel_encap_port_tunnelid_get = NULL;
	p_adpt_api->adpt_tunnel_encap_intf_tunnelid_set = NULL;
	p_adpt_api->adpt_tunnel_encap_intf_tunnelid_get = NULL;
	p_adpt_api->adpt_tunnel_encap_entry_add = NULL;
	p_adpt_api->adpt_tunnel_encap_entry_del = NULL;
	p_adpt_api->adpt_tunnel_encap_entry_get = NULL;
	p_adpt_api->adpt_tunnel_encap_entry_getnext = NULL;
	p_adpt_api->adpt_tunnel_encap_rule_entry_set = NULL;
	p_adpt_api->adpt_tunnel_encap_rule_entry_get = NULL;
	p_adpt_api->adpt_tunnel_encap_rule_entry_del = NULL;

	return;
}

sw_error_t
adpt_appe_tunnel_init(a_uint32_t dev_id)
{
	adpt_api_t *p_adpt_api = NULL;

	p_adpt_api = adpt_api_ptr_get(dev_id);

	if(p_adpt_api == NULL)
		return SW_FAIL;

	adpt_appe_tunnel_func_unregister(dev_id, p_adpt_api);

	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_DECAP_ENTRY_ADD))
		p_adpt_api->adpt_tunnel_decap_entry_add =
			adpt_appe_tunnel_decap_entry_add;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_DECAP_ENTRY_DEL))
		p_adpt_api->adpt_tunnel_decap_entry_del =
			adpt_appe_tunnel_decap_entry_del;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_DECAP_ENTRY_GET))
		p_adpt_api->adpt_tunnel_decap_entry_get =
			adpt_appe_tunnel_decap_entry_get;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_DECAP_ENTRY_GETNEXT))
		p_adpt_api->adpt_tunnel_decap_entry_getnext =
			adpt_appe_tunnel_decap_entry_getnext;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_DECAP_ENTRY_FLUSH))
		p_adpt_api->adpt_tunnel_decap_entry_flush =
			adpt_appe_tunnel_decap_entry_flush;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_GLOBAL_CFG_SET))
		p_adpt_api->adpt_tunnel_global_cfg_set =
			adpt_appe_tunnel_global_cfg_set;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_GLOBAL_CFG_GET))
		p_adpt_api->adpt_tunnel_global_cfg_get =
			adpt_appe_tunnel_global_cfg_get;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_PORT_INTF_SET))
		p_adpt_api->adpt_tunnel_port_intf_set =
			adpt_appe_tunnel_port_intf_set;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_PORT_INTF_GET))
		p_adpt_api->adpt_tunnel_port_intf_get =
			adpt_appe_tunnel_port_intf_get;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_VLAN_INTF_ADD))
		p_adpt_api->adpt_tunnel_vlan_intf_add =
			adpt_appe_tunnel_vlan_intf_add;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_VLAN_INTF_GETFIRST))
		p_adpt_api->adpt_tunnel_vlan_intf_getfirst =
			adpt_appe_tunnel_vlan_intf_getfirst;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_VLAN_INTF_GETNEXT))
		p_adpt_api->adpt_tunnel_vlan_intf_getnext =
			adpt_appe_tunnel_vlan_intf_getnext;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_VLAN_INTF_DEL))
		p_adpt_api->adpt_tunnel_vlan_intf_del =
			adpt_appe_tunnel_vlan_intf_del;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_INTF_SET))
		p_adpt_api->adpt_tunnel_intf_set =
			adpt_appe_tunnel_intf_set;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_INTF_GET))
		p_adpt_api->adpt_tunnel_intf_get =
			adpt_appe_tunnel_intf_get;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_ENCAP_PORT_TUNNELID_SET))
		p_adpt_api->adpt_tunnel_encap_port_tunnelid_set =
			adpt_appe_tunnel_encap_port_tunnelid_set;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_ENCAP_PORT_TUNNELID_GET))
		p_adpt_api->adpt_tunnel_encap_port_tunnelid_get =
			adpt_appe_tunnel_encap_port_tunnelid_get;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_ENCAP_INTF_TUNNELID_SET))
		p_adpt_api->adpt_tunnel_encap_intf_tunnelid_set =
			adpt_appe_tunnel_encap_intf_tunnelid_set;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_ENCAP_INTF_TUNNELID_GET))
		p_adpt_api->adpt_tunnel_encap_intf_tunnelid_get =
			adpt_appe_tunnel_encap_intf_tunnelid_get;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_ENCAP_ENTRY_ADD))
		p_adpt_api->adpt_tunnel_encap_entry_add =
			adpt_appe_tunnel_encap_entry_add;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_ENCAP_ENTRY_DEL))
		p_adpt_api->adpt_tunnel_encap_entry_del =
			adpt_appe_tunnel_encap_entry_del;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_ENCAP_ENTRY_GET))
		p_adpt_api->adpt_tunnel_encap_entry_get =
			adpt_appe_tunnel_encap_entry_get;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_ENCAP_ENTRY_GETNEXT))
		p_adpt_api->adpt_tunnel_encap_entry_getnext =
			adpt_appe_tunnel_encap_entry_getnext;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_ENCAP_RULE_ENTRY_SET))
		p_adpt_api->adpt_tunnel_encap_rule_entry_set =
			adpt_appe_tunnel_encap_rule_entry_set;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_ENCAP_RULE_ENTRY_GET))
		p_adpt_api->adpt_tunnel_encap_rule_entry_get =
			adpt_appe_tunnel_encap_rule_entry_get;
	if (p_adpt_api->adpt_tunnel_func_bitmap & BIT(FUNC_TUNNEL_ENCAP_RULE_ENTRY_DEL))
		p_adpt_api->adpt_tunnel_encap_rule_entry_del =
			adpt_appe_tunnel_encap_rule_entry_del;

	return SW_OK;
}

/**
 * @}
 */
