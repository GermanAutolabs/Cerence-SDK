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
 *  Declaration of nuance_cloudservices_ICloudLoggerResult class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudLoggerResult
 *  @{
 *  @file ICloudLoggerResult.h
 *
 *  @brief  Interface of cloud logger result. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDLOGGERRESULT_H
#define NUANCE_CLOUDSERVICES_ICLOUDLOGGERRESULT_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of cloud logger result. <p>
 */
struct _nuance_cloudservices_ICloudLoggerResult;
/**
 *  @brief  Interface of cloud logger result. <p>
 */
typedef struct _nuance_cloudservices_ICloudLoggerResult nuance_cloudservices_ICloudLoggerResult;


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
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudLoggerResult_getSessionId(const nuance_cloudservices_ICloudLoggerResult *instance);


/**
 *  @brief  Returns the complete contents of this result. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the contents.
 */
CLOUDSERVICES_C_EXPORT nuance_common_IDictionary *nuance_cloudservices_ICloudLoggerResult_getContents(nuance_cloudservices_ICloudLoggerResult *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudLoggerResult_destroy(nuance_cloudservices_ICloudLoggerResult *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDLOGGERRESULT_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
