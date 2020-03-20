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
 *  Declaration of nuance_cloudservices_CloudDataUploaderMode enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices nuance_cloudservices
 * @{
 *  @addtogroup CloudDataUploaderMode
 *  @{
 *  @file CloudDataUploaderMode.h
 * @brief Defines enumeration CloudDataUploaderMode
 */

#ifndef NUANCE_CLOUDSERVICES_CLOUDDATAUPLOADERMODE_H
#define NUANCE_CLOUDSERVICES_CLOUDDATAUPLOADERMODE_H

#include "lh_types.h"
#include "cloudservices_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  Define the data uploader mode. <p>
 */
typedef enum
{
    NUANCE_CLOUDSERVICES_UPLOADER_MODE_NVC,   /**< the NVC data upload mode */
    NUANCE_CLOUDSERVICES_UPLOADER_MODE_NCS,   /**< the NCS data upload mode */
    NUANCE_CLOUDSERVICES_UPLOADER_MODE_NDSP   /**< the NDSP data upload mode */
} nuance_cloudservices_CloudDataUploaderMode;

CLOUDSERVICES_C_EXPORT const LH_CHAR *nuance_cloudservices_CloudDataUploaderMode_toString(nuance_cloudservices_CloudDataUploaderMode enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_CLOUDDATAUPLOADERMODE_H */

/** @} */
/** @} */

