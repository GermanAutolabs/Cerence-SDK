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
 *  Declaration of nuance_audio_IAudioToFile class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioToFile
 *  @{
 *  @file IAudioToFile.h
 *
 *  @brief  Interface of the 'AudioToFile' audio module. <p>
 *
 *  The instance of this module can be used to write audio data streamed inside the SDK into
 *  a file with the provided name. There are two possible modes of operation of this module:
 *
 *  1. IMPLICIT CONFIGURATION - module will first look in the configuration directory passed over when the module is
 *  created. If it finds it and if the configuration contains an output file name then the module will start to save
 *  audio samples to that file after the connection is established. Recording stops after the disconnect call on the
 *  module that provides the data.
 *
 *  2. EXPLICIT CONFIGURATION - if no configuration is found then the module will operate in explicit mode where
 *  the streaming can be started and stopped by the interface functions start() and stop(). In this case output
 *  file name is given as a parameter to the start method. With other two parameters to the start() method it can
 *  be selected if the module prepends WAV header to the audio samples or not and also if the samples will be
 *  appended to the already existing file.
 */

#ifndef NUANCE_AUDIO_IAUDIOTOFILE_H
#define NUANCE_AUDIO_IAUDIOTOFILE_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'AudioToFile' audio module. <p>
 *
 *  The instance of this module can be used to write audio data streamed inside the SDK into
 *  a file with the provided name. There are two possible modes of operation of this module:
 *
 *  1. IMPLICIT CONFIGURATION - module will first look in the configuration directory passed over when the module is
 *  created. If it finds it and if the configuration contains an output file name then the module will start to save
 *  audio samples to that file after the connection is established. Recording stops after the disconnect call on the
 *  module that provides the data.
 *
 *  2. EXPLICIT CONFIGURATION - if no configuration is found then the module will operate in explicit mode where
 *  the streaming can be started and stopped by the interface functions start() and stop(). In this case output
 *  file name is given as a parameter to the start method. With other two parameters to the start() method it can
 *  be selected if the module prepends WAV header to the audio samples or not and also if the samples will be
 *  appended to the already existing file.
 */
struct _nuance_audio_IAudioToFile;
/**
 *  @brief  Interface of the 'AudioToFile' audio module. <p>
 *
 *  The instance of this module can be used to write audio data streamed inside the SDK into
 *  a file with the provided name. There are two possible modes of operation of this module:
 *
 *  1. IMPLICIT CONFIGURATION - module will first look in the configuration directory passed over when the module is
 *  created. If it finds it and if the configuration contains an output file name then the module will start to save
 *  audio samples to that file after the connection is established. Recording stops after the disconnect call on the
 *  module that provides the data.
 *
 *  2. EXPLICIT CONFIGURATION - if no configuration is found then the module will operate in explicit mode where
 *  the streaming can be started and stopped by the interface functions start() and stop(). In this case output
 *  file name is given as a parameter to the start method. With other two parameters to the start() method it can
 *  be selected if the module prepends WAV header to the audio samples or not and also if the samples will be
 *  appended to the already existing file.
 */
typedef struct _nuance_audio_IAudioToFile nuance_audio_IAudioToFile;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "FileMode.h"
#include "FileType.h"
#include "IAudioManager.h"
#include "IAudioModule.h"
#include "IAudioToFileListener.h"
#include "IConfiguration.h"
#include "ResultCode.h"
#include "StopMode.h"
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioToFile_registerFactory(nuance_audio_IAudioManager *audioManager);


/**
 *  Creates an 'IAudioToFile' audio module instance.
 *
 *  @param[in]     name             Name of the module instance to be created.
 *  @param[in]     audioManager     Audio manager instance.
 *  @param[in]     config           Configuration object.
 *  @param[in]     moduleListener   Listener that is informed about the completion of asynchronous interface calls
 *  @param[out]    audioToFile      User interface of the created audio module instance.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioToFile_create
(
    const LH_CHAR *name,
    nuance_audio_IAudioManager *audioManager,
    const nuance_common_IConfiguration *config,
    nuance_audio_IAudioToFileListener *moduleListener,
    nuance_audio_IAudioToFile **audioToFile
);


/**
 *  Start to receive audio data and record them into a file. If the file name parameter
 *  does not include an absolute file path, the file will be located relative to the configuration directory.
 *  The FileType determines if an audio header (for instance WAV) with information about the contained
 *  audio data is written. The FileMode determines if a file should be created/overwritten or if the
 *  recorded data should be appended to an existing file. The FileType should be consistent between
 *  recordings when using FM_APPEND mode. This method is executed asynchronous.
 *  IBackgroundOperation::waitForCompletion() can be used to wait until the stream is started.
 *  (The only exception is the DDFW interface where this method is synchronous.)
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     filename   File to write data into
 *  @param[in]     fileType   type of the file
 *  @param[in]     fileMode   mode of the file
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioToFile_start
(
    nuance_audio_IAudioToFile *instance,
    const LH_CHAR *filename,
    nuance_audio_FileType fileType,
    nuance_audio_FileMode fileMode
);


/**
 *  Stop to receive audio data and close the file. The StopMode defines if this function should return
 *  immediately after writing the already announced data to the file, or if it should block until the current
 *  stream is finished. The segmentation depends on the connected audio module, so using an infinite streaming
 *  source like a microphone directly in front of this module will never end the stream. This method is
 *  executed asynchronous.
 *  IBackgroundOperation::waitForCompletion() can be used to wait for the stop to finish.
 *  (The only exception is the DDFW interface where this method is synchronous.)
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     stopMode   mode determines when to return
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioToFile_stop
(
    nuance_audio_IAudioToFile *instance,
    nuance_audio_StopMode stopMode
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioToFile_getPadNames
(
    const nuance_audio_IAudioToFile *instance,
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
AUDIO_C_EXPORT nuance_common_String *nuance_audio_IAudioToFile_getName(const nuance_audio_IAudioToFile *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioToFile_getStatus
(
    nuance_audio_IAudioToFile *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioToFile_waitForCompletionWithTimeout
(
    nuance_audio_IAudioToFile *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioToFile_waitForCompletion
(
    nuance_audio_IAudioToFile *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioToFile_waitForCompletionAsync
(
    nuance_audio_IAudioToFile *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioToFile_waitForCompletionWithTimeoutAsync
(
    nuance_audio_IAudioToFile *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioToFile_abortOperation(nuance_audio_IAudioToFile *instance);


/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IAudioToFile_destroy(nuance_audio_IAudioToFile *);


AUDIO_C_EXPORT nuance_audio_IAudioModule *nuance_audio_IAudioToFile_as_nuance_audio_IAudioModule(nuance_audio_IAudioToFile *obj);

AUDIO_C_EXPORT nuance_common_IModule *nuance_audio_IAudioToFile_as_nuance_common_IModule(nuance_audio_IAudioToFile *obj);

AUDIO_C_EXPORT nuance_common_IBackgroundOperation *nuance_audio_IAudioToFile_as_nuance_common_IBackgroundOperation(nuance_audio_IAudioToFile *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOTOFILE_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
