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
 *  Declaration of nuance_cloudservices_ICloudDataResetResult class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudDataResetResult
 *  @{
 *  @file ICloudDataResetResult.h
 *
 *  @brief  The cloud data reset result. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDDATARESETRESULT_H
#define NUANCE_CLOUDSERVICES_ICLOUDDATARESETRESULT_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  The cloud data reset result. <p>
 */
struct _nuance_cloudservices_ICloudDataResetResult;
/**
 *  @brief  The cloud data reset result. <p>
 */
typedef struct _nuance_cloudservices_ICloudDataResetResult nuance_cloudservices_ICloudDataResetResult;


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
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudDataResetResult_getSessionId(const nuance_cloudservices_ICloudDataResetResult *instance);


/**
 *  @brief  Returns the complete contents of this result. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return the contents.
 */
CLOUDSERVICES_C_EXPORT nuance_common_IDictionary *nuance_cloudservices_ICloudDataResetResult_getContents(nuance_cloudservices_ICloudDataResetResult *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudDataResetResult_destroy(nuance_cloudservices_ICloudDataResetResult *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDDATARESETRESULT_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
