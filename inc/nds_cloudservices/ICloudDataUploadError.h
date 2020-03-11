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
 *  Declaration of nuance_cloudservices_ICloudDataUploadError class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudDataUploadError
 *  @{
 *  @file ICloudDataUploadError.h
 *
 *  @brief  The cloud data upload error. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADERROR_H
#define NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADERROR_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  The cloud data upload error. <p>
 */
struct _nuance_cloudservices_ICloudDataUploadError;
/**
 *  @brief  The cloud data upload error. <p>
 */
typedef struct _nuance_cloudservices_ICloudDataUploadError nuance_cloudservices_ICloudDataUploadError;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "CloudDataUploadErrorType.h"
#include "IDictionary.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  Returns data upload error type. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return The error type.
 */
CLOUDSERVICES_C_EXPORT nuance_cloudservices_CloudDataUploadErrorType nuance_cloudservices_ICloudDataUploadError_getType(const nuance_cloudservices_ICloudDataUploadError *instance);


/**
 *  @brief  Returns the Session ID that this result came from. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return The session id.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudDataUploadError_getSessionId(const nuance_cloudservices_ICloudDataUploadError *instance);


/**
 *  @brief  Returns the time in which you could only upload data, otherwise server returns busy.<p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return The time in MS
 */
CLOUDSERVICES_C_EXPORT LH_S64 nuance_cloudservices_ICloudDataUploadError_getTimeToUploadMs(const nuance_cloudservices_ICloudDataUploadError *instance);


/**
 *  @brief  Returns the extra error code, if applicable. <p>
 *
 *  CONN_ERROR_NETWORK_UNAVAILABLE             = 0x0fff0000,
 *  CONN_ERROR_COMMAND_IDLE_FOR_TOO_LONG       = 5,
 *  CONN_ERROR_REMOTE_DISCONNECTION            = 3,
 *  CONN_ERROR_TIMED_OUT_WAITING_FOR_RESULT    = 1,
 *  CONN_ERROR_COMMAND_ENDED_UNEXPECTEDLY      = 4
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the error code.
 */
CLOUDSERVICES_C_EXPORT LH_S32 nuance_cloudservices_ICloudDataUploadError_getErrorCode(const nuance_cloudservices_ICloudDataUploadError *instance);


/**
 *  @brief  Returns the error message. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the error message.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudDataUploadError_getErrorMessage(const nuance_cloudservices_ICloudDataUploadError *instance);


/**
 *  @brief  Returns the complete contents of this error. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the contents.
 */
CLOUDSERVICES_C_EXPORT nuance_common_IDictionary *nuance_cloudservices_ICloudDataUploadError_getContents(nuance_cloudservices_ICloudDataUploadError *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudDataUploadError_destroy(nuance_cloudservices_ICloudDataUploadError *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADERROR_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
