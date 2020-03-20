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
 *  Declaration of nuance_common_ISystemManager class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup ISystemManager
 *  @{
 *  @file ISystemManager.h
 *
 *  @brief  Interface of the NDS 'SystemManager' component. <p>
 *
 *  The 'SystemManager' is the central management instance of the DragonDriveFramework / Companion SDK.
 *
 *  It is responsible for the instantiation and configuration of all objects that are common
 *  over all NDS components (e.g. logging, threading, timing).
 *
 *  The SystemManager is manatory on each system. Besides it there can be other (optional)
 *  managers for dedicated tasks (e.g. audio, cloud, etc.). All these managers receive the
 *  SystemManager handle on their creation. They can use it to get access to common resources.
 */

#ifndef NUANCE_COMMON_ISYSTEMMANAGER_H
#define NUANCE_COMMON_ISYSTEMMANAGER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the NDS 'SystemManager' component. <p>
 *
 *  The 'SystemManager' is the central management instance of the DragonDriveFramework / Companion SDK.
 *
 *  It is responsible for the instantiation and configuration of all objects that are common
 *  over all NDS components (e.g. logging, threading, timing).
 *
 *  The SystemManager is manatory on each system. Besides it there can be other (optional)
 *  managers for dedicated tasks (e.g. audio, cloud, etc.). All these managers receive the
 *  SystemManager handle on their creation. They can use it to get access to common resources.
 */
struct _nuance_common_ISystemManager;
/**
 *  @brief  Interface of the NDS 'SystemManager' component. <p>
 *
 *  The 'SystemManager' is the central management instance of the DragonDriveFramework / Companion SDK.
 *
 *  It is responsible for the instantiation and configuration of all objects that are common
 *  over all NDS components (e.g. logging, threading, timing).
 *
 *  The SystemManager is manatory on each system. Besides it there can be other (optional)
 *  managers for dedicated tasks (e.g. audio, cloud, etc.). All these managers receive the
 *  SystemManager handle on their creation. They can use it to get access to common resources.
 */
typedef struct _nuance_common_ISystemManager nuance_common_ISystemManager;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "IConfiguration.h"
#include "IManager.h"
#include "ITimer.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates an ISystemManager object instance.
 *
 *  @param[in]     name            Name of the system manager instance to be created.
 *  @param[in]     config          IConfiguration object instance containing the common JSON configuration
 *  @param[out]    systemManager   Created ISystemManager object instance
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISystemManager_create
(
    const LH_CHAR *name,
    const nuance_common_IConfiguration *config,
    nuance_common_ISystemManager **systemManager
);


/**
 *  @brief  Request an NDS manager from this SystemManager instance.<p>
 *
 *  If a manager of the desired type is registered at the SystemManager it's instance handle is returned.
 *  Else an error is returned.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     type      NDS manager type.
 *  @param[out]    manager   NDS manager.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISystemManager_getManager
(
    const nuance_common_ISystemManager *instance,
    const LH_CHAR *type,
    nuance_common_IManager **manager
);


/**
 *  @brief  Create an ITimer object <p>
 *
 *  This is a prerequisite for using timer functionality with ITimer APIs which need an ITimer instance as input
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    timer   freshly created ITimer instance
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISystemManager_createTimer
(
    nuance_common_ISystemManager *instance,
    nuance_common_ITimer **timer
);


/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_ISystemManager_destroy(nuance_common_ISystemManager *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_ISYSTEMMANAGER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
