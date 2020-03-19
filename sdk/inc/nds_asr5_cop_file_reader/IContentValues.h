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
 *  Declaration of nuance_cvi_IContentValues class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cvi  nuance_cvi
 *  @{
 *  @addtogroup IContentValues
 *  @{
 *  @file IContentValues.h
 *
 *  @brief  Interface to dynamically add content using key-value pairs. <p>
 *
 *
 *  \sa IDynamicContentConsumerListener
 */

#ifndef NUANCE_CVI_ICONTENTVALUES_H
#define NUANCE_CVI_ICONTENTVALUES_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare inner types of class ************************************************************************************/


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface to dynamically add content using key-value pairs. <p>
 *
 *
 *  \sa IDynamicContentConsumerListener
 */
struct _nuance_cvi_IContentValues;
/**
 *  @brief  Interface to dynamically add content using key-value pairs. <p>
 *
 *
 *  \sa IDynamicContentConsumerListener
 */
typedef struct _nuance_cvi_IContentValues nuance_cvi_IContentValues;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cvi_api_defs.h"

/* API types */
#include "ResultCode.h"
#include "StringList.h"
#include "StringListList.h"


/*** Methods **********************************************************************************************************/


/**
 *  Add a key-value pair with value of type integer.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key     The key
 *  @param[in]     value   The value
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentValues_putInt
(
    nuance_cvi_IContentValues *instance,
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
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentValues_putString
(
    nuance_cvi_IContentValues *instance,
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
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentValues_putStringList
(
    nuance_cvi_IContentValues *instance,
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
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentValues_putStringListList
(
    nuance_cvi_IContentValues *instance,
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
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentValues_putInt64
(
    nuance_cvi_IContentValues *instance,
    const LH_CHAR *key,
    LH_S64 value
);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CVI_ICONTENTVALUES_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
