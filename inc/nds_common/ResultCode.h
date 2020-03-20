/*--------------------------COPYRIGHT INFORMATION----------------------------+
 |                                                                           |
 | This program contains proprietary information that is a trade secret      |
 | of Cerence, Inc. and also is protected as an unpublished                  |
 | work under applicable Copyright laws. Recipient is to retain this         |
 | program in confidence and is not permitted to use or make copies          |
 | thereof other than as permitted in a prior written agreement with         |
 | Cerence, Inc. or its affiliates.                                          |
 |                                                                           |
 | Copyright (c) 2020 Cerence, Inc.                                          |
 | All rights reserved. Company confidential.                                |
 |                                                                           |
 +---------------------------------------------------------------------------*/

/**
 *  Declaration of nuance_common_ResultCode enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common nuance_common
 * @{
 *  @addtogroup ResultCode
 *  @{
 *  @file ResultCode.h
 * @brief Defines enumeration ResultCode
 */

#ifndef NUANCE_COMMON_RESULTCODE_H
#define NUANCE_COMMON_RESULTCODE_H

#include "lh_types.h"
#include "common_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief The enumeration is used to indicate an error.<p>
 */
typedef enum
{
    NUANCE_COMMON_OK,     /**< No error occurred */
    NUANCE_COMMON_ERROR,  /**< The called function failed. It had no effect, the overall system */
    /**< is in the same state as before the function call. */
    NUANCE_COMMON_FATAL   /**< A fatal error occured, e.g. the system ran out of resources. The component and all */
    /**< sub-components which depend on it must be destroyed. Otherwise all subsequent */
    /**< calls on these components will also fail with FATAL */
} nuance_common_ResultCode;

COMMON_C_EXPORT const LH_CHAR *nuance_common_ResultCode_toString(nuance_common_ResultCode enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_RESULTCODE_H */

/** @} */
/** @} */

