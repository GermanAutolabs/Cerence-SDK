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
 *  Declaration of nuance_cvi_IContentValuesInternal class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cvi  nuance_cvi
 *  @{
 *  @addtogroup IContentValuesInternal
 *  @{
 *  @file IContentValuesInternal.h
 *
 */

#ifndef NUANCE_CVI_ICONTENTVALUESINTERNAL_H
#define NUANCE_CVI_ICONTENTVALUESINTERNAL_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare inner types of class ************************************************************************************/


/*** Declare class handle *********************************************************************************************/

struct _nuance_cvi_IContentValuesInternal;
typedef struct _nuance_cvi_IContentValuesInternal nuance_cvi_IContentValuesInternal;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cvi_api_defs.h"

/* API types */
#include "IContentValues.h"
#include "ResultCode.h"
#include "StringList.h"
#include "StringListList.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  check if there is a value for a certain key
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT LH_BOOL nuance_cvi_IContentValuesInternal_hasValue
(
    const nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  remove key/value pair
 *
 *  @param[in,out] instance The instance pointer
 */
CVI_C_EXPORT void nuance_cvi_IContentValuesInternal_removeValue
(
    nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  check if has a string value
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT LH_BOOL nuance_cvi_IContentValuesInternal_hasStringValue
(
    const nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  get value as string
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_String *nuance_cvi_IContentValuesInternal_getValueAsString
(
    const nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  check if has an int value
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT LH_BOOL nuance_cvi_IContentValuesInternal_hasIntValue
(
    const nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  get values as int
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT LH_S32 nuance_cvi_IContentValuesInternal_getValueAsInt
(
    const nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  check if has a string list value
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT LH_BOOL nuance_cvi_IContentValuesInternal_hasStringListValue
(
    const nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  get value as string list
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_StringList *nuance_cvi_IContentValuesInternal_getValueAsStringList
(
    const nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  get a list of all keys that have a string value
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_StringList *nuance_cvi_IContentValuesInternal_getAllStringValueKeys(const nuance_cvi_IContentValuesInternal *instance);


/**
 *  get a list of all keys that have an int value
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_StringList *nuance_cvi_IContentValuesInternal_getAllIntValueKeys(const nuance_cvi_IContentValuesInternal *instance);


/**
 *  get a list of all keys that have a string list value
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_StringList *nuance_cvi_IContentValuesInternal_getAllStringListValueKeys(const nuance_cvi_IContentValuesInternal *instance);


/**
 *  check if has a string list list value
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT LH_BOOL nuance_cvi_IContentValuesInternal_hasStringListListValue
(
    const nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  get a list of all keys that have a string list list value
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_StringList *nuance_cvi_IContentValuesInternal_getAllStringListListValueKeys(const nuance_cvi_IContentValuesInternal *instance);


/**
 *  get value as string list list
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_StringListList *nuance_cvi_IContentValuesInternal_getValueAsStringListList
(
    const nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  check if has an int (64 bit) value
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT LH_BOOL nuance_cvi_IContentValuesInternal_hasInt64Value
(
    const nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  get values as int (64 bit)
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT LH_S64 nuance_cvi_IContentValuesInternal_getValueAsInt64
(
    const nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key
);


/**
 *  get a list of all keys that have an int (64 bit) value
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_StringList *nuance_cvi_IContentValuesInternal_getAllInt64ValueKeys(const nuance_cvi_IContentValuesInternal *instance);


/**
 *  Add a key-value pair with value of type integer.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key     The key
 *  @param[in]     value   The value
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentValuesInternal_putInt
(
    nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key,
    LH_S32 value
);


/**
 *  Add a key-value pair with value of type String.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key     The key
 *  @param[in]     value   The value
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentValuesInternal_putString
(
    nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key,
    const LH_CHAR *value
);


/**
 *  Add a key-value pair with value of type StringList.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key     The key
 *  @param[in]     value   The value
 *  @param[in]     nvalue  Number of elements in value
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentValuesInternal_putStringList
(
    nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key,
    const LH_CHAR * const *value, LH_S32 nvalue
);


/**
 *  Add a key-value pair with value of type list of StringList.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key     The key
 *  @param[in]     value   The value
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentValuesInternal_putStringListList
(
    nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key,
    const nuance_common_StringListList *value
);


/**
 *  Add a key-value pair with value of type integer (64 bit).
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key     The key
 *  @param[in]     value   The value
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentValuesInternal_putInt64
(
    nuance_cvi_IContentValuesInternal *instance,
    const LH_CHAR *key,
    LH_S64 value
);


CVI_C_EXPORT nuance_cvi_IContentValues *nuance_cvi_IContentValuesInternal_as_nuance_cvi_IContentValues(nuance_cvi_IContentValuesInternal *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CVI_ICONTENTVALUESINTERNAL_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
