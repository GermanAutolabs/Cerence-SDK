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
 *  Declaration of nuance_cvi_ModificationType enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cvi nuance_cvi
 * @{
 *  @addtogroup ModificationType
 *  @{
 *  @file ModificationType.h
 * @brief Defines enumeration ModificationType
 */

#ifndef NUANCE_CVI_MODIFICATIONTYPE_H
#define NUANCE_CVI_MODIFICATIONTYPE_H

#include "lh_types.h"
#include "cvi_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Modification type
 */
typedef enum
{
    NUANCE_CVI_MT_ADD,                        /**< Add the content value */
    NUANCE_CVI_MT_DELETE_MATCHTYPE_EXACT,     /**< Delete the given entry (Note: Only supported for Local DCC) */
    NUANCE_CVI_MT_DELETE_MATCHTYPE_CONTAINS   /**< Delete entries that contains this value (Note: Only supported for Local DCC) */
} nuance_cvi_ModificationType;

CVI_C_EXPORT const LH_CHAR *nuance_cvi_ModificationType_toString(nuance_cvi_ModificationType enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CVI_MODIFICATIONTYPE_H */

/** @} */
/** @} */

