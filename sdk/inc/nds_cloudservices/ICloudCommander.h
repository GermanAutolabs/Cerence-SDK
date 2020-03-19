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
 *  Declaration of nuance_cloudservices_ICloudCommander class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudCommander
 *  @{
 *  @file ICloudCommander.h
 *
 *  @brief  Interface of the 'CloudCommander' module.<p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDCOMMANDER_H
#define NUANCE_CLOUDSERVICES_ICLOUDCOMMANDER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'CloudCommander' module.<p>
 */
struct _nuance_cloudservices_ICloudCommander;
/**
 *  @brief  Interface of the 'CloudCommander' module.<p>
 */
typedef struct _nuance_cloudservices_ICloudCommander nuance_cloudservices_ICloudCommander;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "IAudioManager.h"
#include "IAudioModule.h"
#include "ICloudCommand.h"
#include "ICloudCommandJsonListener.h"
#include "ICloudCommandListener.h"
#include "ICloudCommanderListener.h"
#include "ICloudManager.h"
#include "IConfiguration.h"
#include "IDictionary.h"
#include "ResultCode.h"
#include "StringList.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates an 'ICloudCommander' module instance.
 *
 *  @param[in]     name             Unique name of this audio module instance
 *  @param[in]     audioManager     Audio manager instance.
 *  @param[in]     cloudManager     Cloud manager instance
 *  @param[in]     config           Configuration object.
 *  @param[in]     moduleListener   Listener that is informed about module changes (e.g creation finished)
 *  @param[out]    cloudCommander   User interface of the created cloud commander module instance.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_create
(
    const LH_CHAR *name,
    nuance_audio_IAudioManager *audioManager,
    nuance_cloudservices_ICloudManager *cloudManager,
    const nuance_common_IConfiguration *config,
    nuance_cloudservices_ICloudCommanderListener *moduleListener,
    nuance_cloudservices_ICloudCommander **cloudCommander
);


/**
 *  Creates a cloud command
 *
 *  @param[in,out] instance           The instance pointer
 *  @param[in]     commandName        the nmas command name.
 *  @param[in]     commandTimeout     the nmas command timeout in milliseconds.
 *  @param[in]     optionalSettings   the optional settings, it could be NULL.
 *  @param[in]     listener           the cloud command listener.
 *  @param[out]    cloudCommand       The created cloud command instance.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_createCloudCommand
(
    nuance_cloudservices_ICloudCommander *instance,
    const LH_CHAR *commandName,
    LH_S32 commandTimeout,
    nuance_common_IDictionary *optionalSettings,
    nuance_cloudservices_ICloudCommandListener *listener,
    nuance_cloudservices_ICloudCommand **cloudCommand
);


/**
 *  Creates a cloud command
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     commandName    the name of the command configuration.
 *  @param[in]     listener       the cloud command listener.
 *  @param[out]    cloudCommand   The created cloud command instance.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_sendCloudCommand
(
    nuance_cloudservices_ICloudCommander *instance,
    const LH_CHAR *commandName,
    nuance_cloudservices_ICloudCommandJsonListener *listener,
    nuance_cloudservices_ICloudCommand **cloudCommand
);


/**
 *  Starts receiving audio data for the specified pad name.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     padName   the pad name to start on.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_start
(
    nuance_cloudservices_ICloudCommander *instance,
    const LH_CHAR *padName
);


/**
 *  Stops receiving audio data for the specified pad name.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     padName   the pad name to stop on.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_stop
(
    nuance_cloudservices_ICloudCommander *instance,
    const LH_CHAR *padName
);


/**
 *  Generates a new UUID of version 4.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    uuid   the generated UUID.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_generateUuidV4
(
    const nuance_cloudservices_ICloudCommander *instance,
    nuance_common_String **uuid
);


/**
 *  @brief  Returns the sink and source pad name(s) of this SDK audio module. <p>
 *
 *  The pad names are given in the configuration of this audio module.
 *  In case this audio module does only have one single sink respectively source pad the pad name is equal to the instance name of this module.
 *  The pad names have to be unambiguous as they are used as identifier of a specific pad.
 *  They are used in conjunction with the instance name to establish/abolish pad connections.
 *  The pad name order in the list corresponds the descending order of the sink resp. source pads of this audio module.
 *
 *  This method is thread safe.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[out]    sinkPads     Sink pad name list of this audio module.
 *  @param[out]    sourcePads   Source pad name list of this audio module.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_getPadNames
(
    const nuance_cloudservices_ICloudCommander *instance,
    nuance_common_StringList **sinkPads,
    nuance_common_StringList **sourcePads
);


/**
 *  @brief  Returns the instance name of this SDK module. <p>
 *
 *  The instance name is given as parameter to the create call of this SDK module.
 *  The name has to be unambiguous as it is used as identifier of this SDK module instance.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Name of this SDK module instance.
 */
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudCommander_getName(const nuance_cloudservices_ICloudCommander *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_getStatus
(
    nuance_cloudservices_ICloudCommander *instance,
    nuance_common_IBackgroundOperation_Status *status
);


/**
 *  Waits until the background operation is finished.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), this method waits until all operations which are in the
 *  queue finish or until timeout expires, providing the timeout value is positive. If timeout value is
 *  negative or 0 (undefined) then it waits until all operations finish.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     timeout   Timeout in milliseconds after which the method should return even if the background operation is not yet finished
 *  @param[out]    status    The state of the background operation, either RUNNING (if returned due to timeout), COMPLETED (on success), FAILED (on error) or FAILED_FATAL (on fatal error)
 *
 *  @return The result code of the execution
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_waitForCompletionWithTimeout
(
    nuance_cloudservices_ICloudCommander *instance,
    LH_S32 timeout,
    nuance_common_IBackgroundOperation_Status *status
);


/**
 *  Waits until the background operation is finished.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), this method waits until all operations are
 *  finished, which are in the queue when waitForCompletion() was called.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   The state of the background operation, either COMPLETED (on success), FAILED (on error) or FAILED_FATAL (on fatal error)
 *
 *  @return Result code
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_waitForCompletion
(
    nuance_cloudservices_ICloudCommander *instance,
    nuance_common_IBackgroundOperation_Status *status
);


/**
 *  Returns directly and triggers an internal wait for the background operation to finish.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), the listener is called once all operations are finished that were in the
 *  queue when waitForCompletion() was called.
 *
 *  Note: This method is intended for DragonDriveFramework use only.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     listener   An IBackgroundListener instance.
 *
 *  @return Result code
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_waitForCompletionAsync
(
    nuance_cloudservices_ICloudCommander *instance,
    nuance_common_IBackgroundListener *listener
);


/**
 *  Returns directly and triggers an internal wait for the background operation to finish.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), the listener is called once all operations are finished or the timeout expired.
 *  If the timeout value is negative or 0 (undefined) it waits until all operations are finished.
 *
 *  Note: This method is intended for DragonDriveFramework use only.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     timeout    Timeout in milliseconds after which the method should return even if the background operation is not yet finished
 *  @param[in]     listener   An IBackgroundListener instance.
 *
 *  @return The result code of the execution
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_waitForCompletionWithTimeoutAsync
(
    nuance_cloudservices_ICloudCommander *instance,
    LH_S32 timeout,
    nuance_common_IBackgroundListener *listener
);


/**
 *  Aborts the current background operation, if other tasks are queued these are removed, too.
 *  The worker thread status is switched to ABORTING and the method returns immediately.
 *  If there's no active background operation, this method does nothing.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Result code
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommander_abortOperation(nuance_cloudservices_ICloudCommander *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudCommander_destroy(nuance_cloudservices_ICloudCommander *);


CLOUDSERVICES_C_EXPORT nuance_audio_IAudioModule *nuance_cloudservices_ICloudCommander_as_nuance_audio_IAudioModule(nuance_cloudservices_ICloudCommander *obj);

CLOUDSERVICES_C_EXPORT nuance_common_IModule *nuance_cloudservices_ICloudCommander_as_nuance_common_IModule(nuance_cloudservices_ICloudCommander *obj);

CLOUDSERVICES_C_EXPORT nuance_common_IBackgroundOperation *nuance_cloudservices_ICloudCommander_as_nuance_common_IBackgroundOperation(nuance_cloudservices_ICloudCommander *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDCOMMANDER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
