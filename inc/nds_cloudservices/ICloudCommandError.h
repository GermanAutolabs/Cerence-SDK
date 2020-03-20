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
 *  Declaration of nuance_cloudservices_ICloudCommandError class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudCommandError
 *  @{
 *  @file ICloudCommandError.h
 *
 *  @brief  Interface of command error. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERROR_H
#define NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERROR_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare inner types of class ************************************************************************************/

/**
 *  Possible command error types.
 */
typedef enum
{
    NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERROR_TYPE_ERROR_CANCELED,    /**<  */
    NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERROR_TYPE_ERROR_CONNECTION,  /**<  */
    NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERROR_TYPE_ERROR_RETRY,       /**<  */
    NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERROR_TYPE_ERROR_QUERY,       /**<  */
    NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERROR_TYPE_ERROR_OTHER,       /**<  */
    NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERROR_TYPE_ERROR_SECURITY     /**<  */
} nuance_cloudservices_ICloudCommandError_Type;


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of command error. <p>
 */
struct _nuance_cloudservices_ICloudCommandError;
/**
 *  @brief  Interface of command error. <p>
 */
typedef struct _nuance_cloudservices_ICloudCommandError nuance_cloudservices_ICloudCommandError;


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
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudCommandError_getSessionId(const nuance_cloudservices_ICloudCommandError *instance);


/**
 *  @brief  Returns the error type. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the error type.
 */
CLOUDSERVICES_C_EXPORT nuance_cloudservices_ICloudCommandError_Type nuance_cloudservices_ICloudCommandError_getType(const nuance_cloudservices_ICloudCommandError *instance);


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
CLOUDSERVICES_C_EXPORT LH_S32 nuance_cloudservices_ICloudCommandError_getErrorCode(const nuance_cloudservices_ICloudCommandError *instance);


/**
 *  @brief  Returns the error message. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the error message.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudCommandError_getErrorMessage(const nuance_cloudservices_ICloudCommandError *instance);


/**
 *  @brief  Returns the complete contents of this error. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the contents.
 */
CLOUDSERVICES_C_EXPORT nuance_common_IDictionary *nuance_cloudservices_ICloudCommandError_getContents(nuance_cloudservices_ICloudCommandError *instance);


/**
 *  @brief  Returns the complete error structure as a JSON string. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the error string.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudCommandError_getJSON(const nuance_cloudservices_ICloudCommandError *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudCommandError_destroy(nuance_cloudservices_ICloudCommandError *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERROR_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
