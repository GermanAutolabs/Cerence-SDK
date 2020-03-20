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
 *  Declaration of nuance_audio_ISampleRateConverter class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup ISampleRateConverter
 *  @{
 *  @file ISampleRateConverter.h
 *
 *  @brief  Interface of the 'SampleRateConverter' audio module. <p>
 *
 *  The SRC audio module offers the possibility to change the sampling rate and as a side effect also the audio packet
 *  size (resp. "samples per channel") of a n-channel audio data stream. But note that the SRC module is not capable to
 *  change the number of audio channels from the audio input stream to the audio output stream.
 *
 *  The SRC module is usable in the audio input and audio output path of an audio scenario to connect audio modules
 *  with different audio formats (except for different number of audio channels).
 *
 *  The audio input format of the SRC module is automatically given by the audio format of the audio module connected
 *  to the input of the SRC. The audio output format of the SRC module has to be configured and has to match to the
 *  audio format of the audio module connected to the output of the SRC.
 *
 *  With different filter scopes it is possible to define a specific filter set to be used by the SRC module. Thereby
 *  the SRC provides internal filter sets optimized for recognition and audibility use cases. Additionally, it is
 *  possible to set a project specific filter scope with filter settings defined in a filter file.
 *
 *  [b]Note:[/b] Except for the occasional one the SRC module may not be used between the SpeechSignalEnhancement (SSE)
 *  and the VoConHigh ASR. Dependent on its configuration the SSE module passes additional information in the audio
 *  signal to the VoConHigh ASR. This additional information can be useful for the VoConHigh ASR for an optimized
 *  recognition. A sample rate conversion in between would destroy this information. Thus it is recommended to perform
 *  a sample rate conversion in front of the SSE. In case a sample rate conversion is really needed between SSE and
 *  VoConHigh ASR please contact your support.
 */

#ifndef NUANCE_AUDIO_ISAMPLERATECONVERTER_H
#define NUANCE_AUDIO_ISAMPLERATECONVERTER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'SampleRateConverter' audio module. <p>
 *
 *  The SRC audio module offers the possibility to change the sampling rate and as a side effect also the audio packet
 *  size (resp. "samples per channel") of a n-channel audio data stream. But note that the SRC module is not capable to
 *  change the number of audio channels from the audio input stream to the audio output stream.
 *
 *  The SRC module is usable in the audio input and audio output path of an audio scenario to connect audio modules
 *  with different audio formats (except for different number of audio channels).
 *
 *  The audio input format of the SRC module is automatically given by the audio format of the audio module connected
 *  to the input of the SRC. The audio output format of the SRC module has to be configured and has to match to the
 *  audio format of the audio module connected to the output of the SRC.
 *
 *  With different filter scopes it is possible to define a specific filter set to be used by the SRC module. Thereby
 *  the SRC provides internal filter sets optimized for recognition and audibility use cases. Additionally, it is
 *  possible to set a project specific filter scope with filter settings defined in a filter file.
 *
 *  [b]Note:[/b] Except for the occasional one the SRC module may not be used between the SpeechSignalEnhancement (SSE)
 *  and the VoConHigh ASR. Dependent on its configuration the SSE module passes additional information in the audio
 *  signal to the VoConHigh ASR. This additional information can be useful for the VoConHigh ASR for an optimized
 *  recognition. A sample rate conversion in between would destroy this information. Thus it is recommended to perform
 *  a sample rate conversion in front of the SSE. In case a sample rate conversion is really needed between SSE and
 *  VoConHigh ASR please contact your support.
 */
struct _nuance_audio_ISampleRateConverter;
/**
 *  @brief  Interface of the 'SampleRateConverter' audio module. <p>
 *
 *  The SRC audio module offers the possibility to change the sampling rate and as a side effect also the audio packet
 *  size (resp. "samples per channel") of a n-channel audio data stream. But note that the SRC module is not capable to
 *  change the number of audio channels from the audio input stream to the audio output stream.
 *
 *  The SRC module is usable in the audio input and audio output path of an audio scenario to connect audio modules
 *  with different audio formats (except for different number of audio channels).
 *
 *  The audio input format of the SRC module is automatically given by the audio format of the audio module connected
 *  to the input of the SRC. The audio output format of the SRC module has to be configured and has to match to the
 *  audio format of the audio module connected to the output of the SRC.
 *
 *  With different filter scopes it is possible to define a specific filter set to be used by the SRC module. Thereby
 *  the SRC provides internal filter sets optimized for recognition and audibility use cases. Additionally, it is
 *  possible to set a project specific filter scope with filter settings defined in a filter file.
 *
 *  [b]Note:[/b] Except for the occasional one the SRC module may not be used between the SpeechSignalEnhancement (SSE)
 *  and the VoConHigh ASR. Dependent on its configuration the SSE module passes additional information in the audio
 *  signal to the VoConHigh ASR. This additional information can be useful for the VoConHigh ASR for an optimized
 *  recognition. A sample rate conversion in between would destroy this information. Thus it is recommended to perform
 *  a sample rate conversion in front of the SSE. In case a sample rate conversion is really needed between SSE and
 *  VoConHigh ASR please contact your support.
 */
typedef struct _nuance_audio_ISampleRateConverter nuance_audio_ISampleRateConverter;


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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISampleRateConverter_registerFactory(nuance_audio_IAudioManager *audioManager);


/**
 *  Creates a 'SampleRateConverter' audio module instance.
 *
 *  @param[in]     name                  Unique name of this audio module instance.
 *  @param[in]     audioManager          Audio manager instance.
 *  @param[in]     config                Configuration object.
 *  @param[in]     moduleListener        Listener of this audio module.
 *  @param[out]    sampleRateConverter   User interface of the created audio module instance.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISampleRateConverter_create
(
    const LH_CHAR *name,
    nuance_audio_IAudioManager *audioManager,
    const nuance_common_IConfiguration *config,
    nuance_common_IModuleListener *moduleListener,
    nuance_audio_ISampleRateConverter **sampleRateConverter
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISampleRateConverter_getPadNames
(
    const nuance_audio_ISampleRateConverter *instance,
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
AUDIO_C_EXPORT nuance_common_String *nuance_audio_ISampleRateConverter_getName(const nuance_audio_ISampleRateConverter *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISampleRateConverter_getStatus
(
    nuance_audio_ISampleRateConverter *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISampleRateConverter_waitForCompletionWithTimeout
(
    nuance_audio_ISampleRateConverter *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISampleRateConverter_waitForCompletion
(
    nuance_audio_ISampleRateConverter *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISampleRateConverter_waitForCompletionAsync
(
    nuance_audio_ISampleRateConverter *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISampleRateConverter_waitForCompletionWithTimeoutAsync
(
    nuance_audio_ISampleRateConverter *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISampleRateConverter_abortOperation(nuance_audio_ISampleRateConverter *instance);


/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_ISampleRateConverter_destroy(nuance_audio_ISampleRateConverter *);


AUDIO_C_EXPORT nuance_audio_IAudioModule *nuance_audio_ISampleRateConverter_as_nuance_audio_IAudioModule(nuance_audio_ISampleRateConverter *obj);

AUDIO_C_EXPORT nuance_common_IModule *nuance_audio_ISampleRateConverter_as_nuance_common_IModule(nuance_audio_ISampleRateConverter *obj);

AUDIO_C_EXPORT nuance_common_IBackgroundOperation *nuance_audio_ISampleRateConverter_as_nuance_common_IBackgroundOperation(nuance_audio_ISampleRateConverter *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_ISAMPLERATECONVERTER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
