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
 *  Declaration of nuance_cloudservices_CloudDataUploadErrorType enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices nuance_cloudservices
 * @{
 *  @addtogroup CloudDataUploadErrorType
 *  @{
 *  @file CloudDataUploadErrorType.h
 * @brief Defines enumeration CloudDataUploadErrorType
 */

#ifndef NUANCE_CLOUDSERVICES_CLOUDDATAUPLOADERRORTYPE_H
#define NUANCE_CLOUDSERVICES_CLOUDDATAUPLOADERRORTYPE_H

#include "lh_types.h"
#include "cloudservices_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  Define cloud data upload error types. <p>
 */
typedef enum
{
    NUANCE_CLOUDSERVICES_UPLOAD_ERROR_STORAGE,      /**< Unable to add or delete content on the server. */
    NUANCE_CLOUDSERVICES_UPLOAD_ERROR_GRAMMAR,      /**< Unable to generate grammar for content on the server. */
    NUANCE_CLOUDSERVICES_UPLOAD_ERROR_SERVER_BUSY,  /**< Server busy, try again later. */
    NUANCE_CLOUDSERVICES_UPLOAD_ERROR_NETWORK,      /**< Network error (timeout, connection dropped, etc.). */
    NUANCE_CLOUDSERVICES_UPLOAD_ERROR_MISMATCHED,   /**< Data version of server and client is mismatched. Application needs to take a decision to do full data upload or not. */
    NUANCE_CLOUDSERVICES_UPLOAD_ERROR_CANCELED,     /**< Upload or deletion has been canceled. */
    NUANCE_CLOUDSERVICES_UPLOAD_ERROR_INTERNAL      /**< Internal error. */
} nuance_cloudservices_CloudDataUploadErrorType;

CLOUDSERVICES_C_EXPORT const LH_CHAR *nuance_cloudservices_CloudDataUploadErrorType_toString(nuance_cloudservices_CloudDataUploadErrorType enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_CLOUDDATAUPLOADERRORTYPE_H */

/** @} */
/** @} */

