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
 *  Declaration of nuance_cvi_IContentFormat class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cvi  nuance_cvi
 *  @{
 *  @addtogroup IContentFormat
 *  @{
 *  @file IContentFormat.h
 *
 *  @brief  Interface to retrieve content format of a dynamic content consumer. <p>
 *
 *  The content format of the dynamic content consumer is represented with a json array:
 *
 *  \code
 *  "content" :[
 *  {
 *  "name": "....",
 *  "type": "string|integer|json|..."
 *  },
 *  ...
 *  ]
 *  \endcode
 *  This interface allows the application to query the value of the names and their corresponding type value.
 */

#ifndef NUANCE_CVI_ICONTENTFORMAT_H
#define NUANCE_CVI_ICONTENTFORMAT_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface to retrieve content format of a dynamic content consumer. <p>
 *
 *  The content format of the dynamic content consumer is represented with a json array:
 *
 *  \code
 *  "content" :[
 *  {
 *  "name": "....",
 *  "type": "string|integer|json|..."
 *  },
 *  ...
 *  ]
 *  \endcode
 *  This interface allows the application to query the value of the names and their corresponding type value.
 */
struct _nuance_cvi_IContentFormat;
/**
 *  @brief  Interface to retrieve content format of a dynamic content consumer. <p>
 *
 *  The content format of the dynamic content consumer is represented with a json array:
 *
 *  \code
 *  "content" :[
 *  {
 *  "name": "....",
 *  "type": "string|integer|json|..."
 *  },
 *  ...
 *  ]
 *  \endcode
 *  This interface allows the application to query the value of the names and their corresponding type value.
 */
typedef struct _nuance_cvi_IContentFormat nuance_cvi_IContentFormat;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cvi_api_defs.h"

/* API types */
#include "ResultCode.h"
#include "StringList.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Get the type of the specified name
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     name   The name value for which you want to retrieve the type
 *  @param[out]    type   The returned type
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentFormat_getType
(
    const nuance_cvi_IContentFormat *instance,
    const LH_CHAR *name,
    nuance_common_String **type
);


/**
 *  return the list of names in the content in the content value
 *  This function returns a copy of the list of names, any modification done on this list has no impact on the
 *  dynamic content consumer.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    names   the list of names
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_IContentFormat_getNames
(
    const nuance_cvi_IContentFormat *instance,
    nuance_common_StringList **names
);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CVI_ICONTENTFORMAT_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
