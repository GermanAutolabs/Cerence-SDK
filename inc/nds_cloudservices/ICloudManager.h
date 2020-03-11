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
 *  Declaration of nuance_cloudservices_ICloudManager class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudManager
 *  @{
 *  @file ICloudManager.h
 *
 *  @brief  Interface of the 'CloudManager' component.<p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDMANAGER_H
#define NUANCE_CLOUDSERVICES_ICLOUDMANAGER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'CloudManager' component.<p>
 */
struct _nuance_cloudservices_ICloudManager;
/**
 *  @brief  Interface of the 'CloudManager' component.<p>
 */
typedef struct _nuance_cloudservices_ICloudManager nuance_cloudservices_ICloudManager;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "IConfiguration.h"
#include "IManager.h"
#include "ISystemManager.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates a 'CloudManager' component instance.
 *  This is a helper component for automatic creation of cloud-module and -protocol instances. Currently it is provided to ease the useage
 *  of cloud-logging.
 *
 *  @param[in]     name            Name of the module instance to be created.
 *  @param[in]     systemManager   System manager instance.
 *  @param[in]     config          Configuration object.
 *  @param[out]    cloudManager    User interface of the created cloud manager component.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudManager_create
(
    const LH_CHAR *name,
    nuance_common_ISystemManager *systemManager,
    const nuance_common_IConfiguration *config,
    nuance_cloudservices_ICloudManager **cloudManager
);


/**
 *  @brief  Returns the type of this NDS manager instance. <p>
 *
 *  Only one manager of a certain type can be registered at the SystemManager at
 *  a time.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Type of this NDS manager instance.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudManager_getType(const nuance_cloudservices_ICloudManager *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudManager_destroy(nuance_cloudservices_ICloudManager *);


CLOUDSERVICES_C_EXPORT nuance_common_IManager *nuance_cloudservices_ICloudManager_as_nuance_common_IManager(nuance_cloudservices_ICloudManager *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDMANAGER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
