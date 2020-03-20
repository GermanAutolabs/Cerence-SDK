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
 *  Declaration of nuance_audio_IAudioDecoder class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioDecoder
 *  @{
 *  @file IAudioDecoder.h
 *
 *  @brief  Interface of the 'AudioDecoder' audio module. <p>
 *
 *  The 'AudioDecoder' module decodes an incoming 8bit encoded audio data stream using the defined decoder and container.
 *  The output data stream will contain 16bit PCM audio only.
 *  The AudioDecoder will request an IDecoder as well as an IContainerUnpacker of the configured type during creation at the audio manager.
 *  The IContainerUnpacker will only be requested if configured.
 *
 *  It has to be ensured that the IDecoder and the IContainerUnpacker factories were registered at the audio manager via their 'registerFactory' methods before.
 *  If that is not considered the creation of the AudioDecoder will fail with an error.
 */

#ifndef NUANCE_AUDIO_IAUDIODECODER_H
#define NUANCE_AUDIO_IAUDIODECODER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'AudioDecoder' audio module. <p>
 *
 *  The 'AudioDecoder' module decodes an incoming 8bit encoded audio data stream using the defined decoder and container.
 *  The output data stream will contain 16bit PCM audio only.
 *  The AudioDecoder will request an IDecoder as well as an IContainerUnpacker of the configured type during creation at the audio manager.
 *  The IContainerUnpacker will only be requested if configured.
 *
 *  It has to be ensured that the IDecoder and the IContainerUnpacker factories were registered at the audio manager via their 'registerFactory' methods before.
 *  If that is not considered the creation of the AudioDecoder will fail with an error.
 */
struct _nuance_audio_IAudioDecoder;
/**
 *  @brief  Interface of the 'AudioDecoder' audio module. <p>
 *
 *  The 'AudioDecoder' module decodes an incoming 8bit encoded audio data stream using the defined decoder and container.
 *  The output data stream will contain 16bit PCM audio only.
 *  The AudioDecoder will request an IDecoder as well as an IContainerUnpacker of the configured type during creation at the audio manager.
 *  The IContainerUnpacker will only be requested if configured.
 *
 *  It has to be ensured that the IDecoder and the IContainerUnpacker factories were registered at the audio manager via their 'registerFactory' methods before.
 *  If that is not considered the creation of the AudioDecoder will fail with an error.
 */
typedef struct _nuance_audio_IAudioDecoder nuance_audio_IAudioDecoder;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IAudioManager.h"
#include "IAudioModule.h"
#include "IConfiguration.h"
#include "IModuleListener.h"
#include "ResultCode.h"
#include "StringList.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  enables the implicit creation feature for this module at the handed audio manager instance. <p>
 *
 *  This method enables the implicit creation feature for this module at the handed audio manager instance.
 *  It takes care of all necessary internal steps to do that, including the creation of the needed factory
 *  as well as the registration of that factory object at the audio manager.
 *
 *  The ownership of the factory object is handed to the audio manager by calling this method.
 *  It will be destroyed once the audio manager is destroyed.
 *
 *  This feature can be activated only once and stays active as long as the handed audio manager instance is available.
 *  Trying to activate that feature a second time will result in an error.
 *
 *  @param[in]     audioManager   Audio manager instance.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioDecoder_registerFactory(nuance_audio_IAudioManager *audioManager);


/**
 *  Creates an 'AudioDecoder' audio module.
 *
 *  @param[in]     name             Name of the module instance to be created.
 *  @param[in]     audioManager     Audio manager instance.
 *  @param[in]     config           Configuration object.
 *  @param[in]     moduleListener   Listener that is informed about module changes (e.g creation finished)
 *  @param[out]    audioDecoder     User interface of the created audio module instance.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioDecoder_create
(
    const LH_CHAR *name,
    nuance_audio_IAudioManager *audioManager,
    const nuance_common_IConfiguration *config,
    nuance_common_IModuleListener *moduleListener,
    nuance_audio_IAudioDecoder **audioDecoder
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioDecoder_getPadNames
(
    const nuance_audio_IAudioDecoder *instance,
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
AUDIO_C_EXPORT nuance_common_String *nuance_audio_IAudioDecoder_getName(const nuance_audio_IAudioDecoder *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioDecoder_getStatus
(
    nuance_audio_IAudioDecoder *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioDecoder_waitForCompletionWithTimeout
(
    nuance_audio_IAudioDecoder *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioDecoder_waitForCompletion
(
    nuance_audio_IAudioDecoder *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioDecoder_waitForCompletionAsync
(
    nuance_audio_IAudioDecoder *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioDecoder_waitForCompletionWithTimeoutAsync
(
    nuance_audio_IAudioDecoder *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioDecoder_abortOperation(nuance_audio_IAudioDecoder *instance);


/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IAudioDecoder_destroy(nuance_audio_IAudioDecoder *);


AUDIO_C_EXPORT nuance_audio_IAudioModule *nuance_audio_IAudioDecoder_as_nuance_audio_IAudioModule(nuance_audio_IAudioDecoder *obj);

AUDIO_C_EXPORT nuance_common_IModule *nuance_audio_IAudioDecoder_as_nuance_common_IModule(nuance_audio_IAudioDecoder *obj);

AUDIO_C_EXPORT nuance_common_IBackgroundOperation *nuance_audio_IAudioDecoder_as_nuance_common_IBackgroundOperation(nuance_audio_IAudioDecoder *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIODECODER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
