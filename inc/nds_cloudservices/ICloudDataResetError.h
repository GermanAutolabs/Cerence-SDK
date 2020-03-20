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
 *  Declaration of nuance_cloudservices_ICloudDataResetError class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudDataResetError
 *  @{
 *  @file ICloudDataResetError.h
 *
 *  @brief  The cloud data reset error. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDDATARESETERROR_H
#define NUANCE_CLOUDSERVICES_ICLOUDDATARESETERROR_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  The cloud data reset error. <p>
 */
struct _nuance_cloudservices_ICloudDataResetError;
/**
 *  @brief  The cloud data reset error. <p>
 */
typedef struct _nuance_cloudservices_ICloudDataResetError nuance_cloudservices_ICloudDataResetError;


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
 *  @brief  Returns data reset error type. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return The error type.
 */
CLOUDSERVICES_C_EXPORT nuance_cloudservices_CloudDataUploadErrorType nuance_cloudservices_ICloudDataResetError_getType(const nuance_cloudservices_ICloudDataResetError *instance);


/**
 *  @brief  Returns the Session ID that this result came from. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return The session id.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudDataResetError_getSessionId(const nuance_cloudservices_ICloudDataResetError *instance);


/**
 *  @brief  Returns the complete contents of this error. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the contents.
 */
CLOUDSERVICES_C_EXPORT nuance_common_IDictionary *nuance_cloudservices_ICloudDataResetError_getContents(nuance_cloudservices_ICloudDataResetError *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudDataResetError_destroy(nuance_cloudservices_ICloudDataResetError *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDDATARESETERROR_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
