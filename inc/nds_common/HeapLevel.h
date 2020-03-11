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
 *  Declaration of nuance_common_HeapLevel enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common nuance_common
 * @{
 *  @addtogroup HeapLevel
 *  @{
 *  @file HeapLevel.h
 * @brief Defines enumeration HeapLevel
 */

#ifndef NUANCE_COMMON_HEAPLEVEL_H
#define NUANCE_COMMON_HEAPLEVEL_H

#include "lh_types.h"
#include "common_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration type describes the different fill levels of the used heap.
 */
typedef enum
{
    NUANCE_COMMON_HEAP_LEVEL_NORMAL,  /**< Normal heap fill level. */
    NUANCE_COMMON_HEAP_LEVEL_ERROR    /**< Heap fill level higher than the limit that has been set. */
} nuance_common_HeapLevel;

COMMON_C_EXPORT const LH_CHAR *nuance_common_HeapLevel_toString(nuance_common_HeapLevel enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_HEAPLEVEL_H */

/** @} */
/** @} */

