/*
 * Copyright (c) 2024 Qualcomm Innovation Center, Inc. All rights reserved.
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
 * @defgroup fal_pktedit FAL_PKTEDIT
 * @{
 */
#include "sw.h"
#include "fal_pktedit.h"
#include "hsl_api.h"
#include "adpt.h"

sw_error_t
_fal_pktedit_padding_set(a_uint32_t dev_id, fal_pktedit_padding_t *padding)
{
    adpt_api_t *p_api;
    sw_error_t rv = SW_OK;

    SW_RTN_ON_NULL(p_api = adpt_api_ptr_get(dev_id));

    if (NULL == p_api->adpt_pktedit_padding_set)
        return SW_NOT_SUPPORTED;

    rv = p_api->adpt_pktedit_padding_set(dev_id, padding);
    return rv;
}

sw_error_t
_fal_pktedit_padding_get(a_uint32_t dev_id, fal_pktedit_padding_t *padding)
{
    adpt_api_t *p_api;
    sw_error_t rv = SW_OK;

    SW_RTN_ON_NULL(p_api = adpt_api_ptr_get(dev_id));

    if (NULL == p_api->adpt_pktedit_padding_get)
        return SW_NOT_SUPPORTED;

    rv = p_api->adpt_pktedit_padding_get(dev_id, padding);
    return rv;
}


/**
 * @brief Set pktedit padding
 * @param[in] dev_id device id
 * @param[in] padding pktedit padding
 * @return SW_OK or error code
 */
sw_error_t
fal_pktedit_padding_set(a_uint32_t dev_id, fal_pktedit_padding_t *padding)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_pktedit_padding_set(dev_id, padding);
    FAL_API_UNLOCK;
    return rv;
}

/**
 * @brief Get pktedit padding configuration
 * @param[in] dev_id device id
 * @param[in|out] padding pktedit padding
 * @return SW_OK or error code
 */
sw_error_t
fal_pktedit_padding_get(a_uint32_t dev_id, fal_pktedit_padding_t *padding)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_pktedit_padding_get(dev_id, padding);
    FAL_API_UNLOCK;
    return rv;
}

EXPORT_SYMBOL(fal_pktedit_padding_set);
EXPORT_SYMBOL(fal_pktedit_padding_get);
