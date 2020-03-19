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
 *  Declaration of nuance_common_KeyValuePoolError enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common nuance_common
 * @{
 *  @addtogroup KeyValuePoolError
 *  @{
 *  @file KeyValuePoolError.h
 * @brief Defines enumeration KeyValuePoolError
 */

#ifndef NUANCE_COMMON_KEYVALUEPOOLERROR_H
#define NUANCE_COMMON_KEYVALUEPOOLERROR_H

#include "lh_types.h"
#include "common_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration type describes the errors which can occur in a KeyValuePool object.
 */
typedef enum
{
    NUANCE_COMMON_KVP_OK,                       /**< Indicates that no error occured (yet). */
    NUANCE_COMMON_KVP_INVALID_KEY,              /**< Indicates that an invalid key was used. */
    NUANCE_COMMON_KVP_INVALID_JSON,             /**< Indicates that something is wrong in the KVP JSON config. */
    NUANCE_COMMON_KVP_INVALID_VALUE_TYPE,       /**< Indicates that a value of the wrong type was passed. */
    NUANCE_COMMON_KVP_INVALID_VALUE_TOO_LARGE,  /**< Indicates that a value was larger than the allowed maximum. */
    NUANCE_COMMON_KVP_INVALID_VALUE_TOO_SMALL   /**< Indicates that a value was smaller than the allowed minimum. */
} nuance_common_KeyValuePoolError;

COMMON_C_EXPORT const LH_CHAR *nuance_common_KeyValuePoolError_toString(nuance_common_KeyValuePoolError enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_KEYVALUEPOOLERROR_H */

/** @} */
/** @} */

