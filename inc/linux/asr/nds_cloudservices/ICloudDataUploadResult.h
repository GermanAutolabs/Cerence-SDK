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
 *  Declaration of nuance_cloudservices_ICloudDataUploadResult class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudDataUploadResult
 *  @{
 *  @file ICloudDataUploadResult.h
 *
 *  @brief  The cloud data upload result. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADRESULT_H
#define NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADRESULT_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  The cloud data upload result. <p>
 */
struct _nuance_cloudservices_ICloudDataUploadResult;
/**
 *  @brief  The cloud data upload result. <p>
 */
typedef struct _nuance_cloudservices_ICloudDataUploadResult nuance_cloudservices_ICloudDataUploadResult;


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
 *  @return The session id.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudDataUploadResult_getSessionId(const nuance_cloudservices_ICloudDataUploadResult *instance);


/**
 *  @brief  Returns the result type, taken from the 'result_type' key of the result dictionary. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return The result type.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudDataUploadResult_getResultType(const nuance_cloudservices_ICloudDataUploadResult *instance);


/**
 *  @brief  Returns current checksum on server. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return The current checksum on server
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudDataUploadResult_getCurrentChecksum(const nuance_cloudservices_ICloudDataUploadResult *instance);


/**
 *  @brief  Returns the time in which you could only upload data, otherwise server returns busy.<p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return The time in MS
 */
CLOUDSERVICES_C_EXPORT LH_S64 nuance_cloudservices_ICloudDataUploadResult_getTimeToUploadMs(const nuance_cloudservices_ICloudDataUploadResult *instance);


/**
 *  @brief  Returns the complete contents of this result. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the contents.
 */
CLOUDSERVICES_C_EXPORT nuance_common_IDictionary *nuance_cloudservices_ICloudDataUploadResult_getContents(nuance_cloudservices_ICloudDataUploadResult *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudDataUploadResult_destroy(nuance_cloudservices_ICloudDataUploadResult *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADRESULT_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
