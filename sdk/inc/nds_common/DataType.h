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
 *  Declaration of nuance_common_DataType enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common nuance_common
 * @{
 *  @addtogroup DataType
 *  @{
 *  @file DataType.h
 * @brief Defines enumeration DataType
 */

#ifndef NUANCE_COMMON_DATATYPE_H
#define NUANCE_COMMON_DATATYPE_H

#include "lh_types.h"
#include "common_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  data type. <p>
 *
 *  Defines the type of an data element stored in a Dictionary or Sequence object.
 */
typedef enum
{
    NUANCE_COMMON_TYPE_NULL,        /**<  */
    NUANCE_COMMON_TYPE_INTEGER,     /**<  */
    NUANCE_COMMON_TYPE_BYTES,       /**<  */
    NUANCE_COMMON_TYPE_STRING,      /**<  */
    NUANCE_COMMON_TYPE_BOOLEAN,     /**<  */
    NUANCE_COMMON_TYPE_DOUBLE,      /**<  */
    NUANCE_COMMON_TYPE_DICTIONARY,  /**<  */
    NUANCE_COMMON_TYPE_SEQUENCE     /**<  */
} nuance_common_DataType;

COMMON_C_EXPORT const LH_CHAR *nuance_common_DataType_toString(nuance_common_DataType enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_DATATYPE_H */

/** @} */
/** @} */

