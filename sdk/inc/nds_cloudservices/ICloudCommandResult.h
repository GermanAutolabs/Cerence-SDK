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
 *  Declaration of nuance_cloudservices_ICloudCommandResult class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudCommandResult
 *  @{
 *  @file ICloudCommandResult.h
 *
 *  @brief  Interface of command result. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDCOMMANDRESULT_H
#define NUANCE_CLOUDSERVICES_ICLOUDCOMMANDRESULT_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of command result. <p>
 */
struct _nuance_cloudservices_ICloudCommandResult;
/**
 *  @brief  Interface of command result. <p>
 */
typedef struct _nuance_cloudservices_ICloudCommandResult nuance_cloudservices_ICloudCommandResult;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "IDictionary.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  Returns the Session ID that this result came from. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the session id.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudCommandResult_getSessionId(const nuance_cloudservices_ICloudCommandResult *instance);


/**
 *  @brief  Returns the result type, taken from the 'result_type' key of the result dictionary. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the result type.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudCommandResult_getResultType(const nuance_cloudservices_ICloudCommandResult *instance);


/**
 *  @brief  Returns the result format, taken from the 'result_format' key of the result dictionary. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the result format.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudCommandResult_getResultFormat(const nuance_cloudservices_ICloudCommandResult *instance);


/**
 *  @brief  Returns the complete contents of this result. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the contents.
 */
CLOUDSERVICES_C_EXPORT nuance_common_IDictionary *nuance_cloudservices_ICloudCommandResult_getContents(nuance_cloudservices_ICloudCommandResult *instance);


/**
 *  @brief  Returns the complete result structure as a JSON string. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the result string.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudCommandResult_getJSON(const nuance_cloudservices_ICloudCommandResult *instance);


/**
 *  @brief  Tells whether this result is the final one, or if more is expected. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return is final or not
 */
CLOUDSERVICES_C_EXPORT LH_BOOL nuance_cloudservices_ICloudCommandResult_isFinal(const nuance_cloudservices_ICloudCommandResult *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudCommandResult_destroy(nuance_cloudservices_ICloudCommandResult *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDCOMMANDRESULT_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
