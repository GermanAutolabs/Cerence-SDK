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
 *  Declaration of nuance_audio_IAudioInputFromFile class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioInputFromFile
 *  @{
 *  @file IAudioInputFromFile.h
 *
 *  @brief  Interface of the 'AudioInputFromFile' audio module, for DDFW only.<p>
 *
 *  This interface is DEPRECATED and for DDFW only. SDK users shall use the AudioFromFile interface.
 *
 *  In general the AudioInputFromFile module offers the possibility to stream audio data from an audio file list
 *  with 1 to n elements to subsequent connected audio modules. The streaming is automatically started and stopped
 *  when an audio session becomes active respectively inactive. For each audio session one file is streamed only.
 *  Each start of a session triggers the AudioInputFromFile audio module to stream the next audio file from the file list.
 *  In case the file list would exceed it is streamed from the beginning again.
 *
 *  The AudioInputFromFile module is usable in two manifestations:
 *
 *  1. AUTOMATICALLY CREATED WITH A PRE-CONFIGURED AUDIO FILE LIST IN THE AUDIO CONFIGURATION FILE (.json):
 *  With calling prepareScenario() resp. activateScenario() an involved AudioInputFromFile instance is automatically
 *  created. NOTE: In this use case the <tt>audio_files</tt> parameter in the audio configuration file (.json) is mandatory!
 *  With automated creation there is no interface handle available to set a file list by customer API.
 *
 *  2. CREATED BY THE CUSTOMER WITH THE OPTION TO SET AN AUDIO FILE LIST DYNAMICALLY BY THE API:
 *  Use the following customer API to create and set up an AudioInputFromFile module. NOTE: In this use case the
 *  <tt>audio_files</tt> parameter in the audio configuration file (.json) is optional in case it is set by the customer
 *  API before an audio session is started!
 *
 *  Supported file formats are:
 *
 *  <ul>
 *  <li> standard wav files </li>
 *  <li> NIST files </li>
 *  <li> header-less raw files, it has to be kept in mind, that multichannel signals are expected in interleaved format (123123123123 and not 111122223333). </li>
 *  <li> OGG/OPUS files </li>
 *  <li> encoded audio files with a constant bitrate (blocksize needs to be configured as 'samples_per_channel' in the audio format) </li>
 *  </ul>
 *
 *  The audio file path of each element in the audio file list (pre-configured or set with customer API) is build
 *  using the following mechanism:
 *
 *  1. A file with an absolute path remains unchanged. A set root path is not considered. Example:
 *
 *  <ul>
 *  <li> audio_files="/test_path/test_file.wav" ==> "/test_path/test_file.wav"</li>
 *  </ul>
 *
 *  2. A file with a relative path is prepended with the pre-configured resp. set root path. The resulting path
 *  is expected to be in relation to the JSON configuration directory. Examples (JSON config dir = "../config/json"):
 *
 *  <ul>
 *  <li> root_path=""          + audio_files="test_file.raw"    ==> "../config/json/test_file.raw"</li>
 *  <li> root_path="test_path" + audio_files="test_file.raw"    ==> "../config/json/test_path/test_file.raw"</li>
 *  <li> root_path="test_path" + audio_files="../test_file.raw" ==> "../config/json/test_file.raw"</li>
 *  </ul>
 */

#ifndef NUANCE_AUDIO_IAUDIOINPUTFROMFILE_H
#define NUANCE_AUDIO_IAUDIOINPUTFROMFILE_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'AudioInputFromFile' audio module, for DDFW only.<p>
 *
 *  This interface is DEPRECATED and for DDFW only. SDK users shall use the AudioFromFile interface.
 *
 *  In general the AudioInputFromFile module offers the possibility to stream audio data from an audio file list
 *  with 1 to n elements to subsequent connected audio modules. The streaming is automatically started and stopped
 *  when an audio session becomes active respectively inactive. For each audio session one file is streamed only.
 *  Each start of a session triggers the AudioInputFromFile audio module to stream the next audio file from the file list.
 *  In case the file list would exceed it is streamed from the beginning again.
 *
 *  The AudioInputFromFile module is usable in two manifestations:
 *
 *  1. AUTOMATICALLY CREATED WITH A PRE-CONFIGURED AUDIO FILE LIST IN THE AUDIO CONFIGURATION FILE (.json):
 *  With calling prepareScenario() resp. activateScenario() an involved AudioInputFromFile instance is automatically
 *  created. NOTE: In this use case the <tt>audio_files</tt> parameter in the audio configuration file (.json) is mandatory!
 *  With automated creation there is no interface handle available to set a file list by customer API.
 *
 *  2. CREATED BY THE CUSTOMER WITH THE OPTION TO SET AN AUDIO FILE LIST DYNAMICALLY BY THE API:
 *  Use the following customer API to create and set up an AudioInputFromFile module. NOTE: In this use case the
 *  <tt>audio_files</tt> parameter in the audio configuration file (.json) is optional in case it is set by the customer
 *  API before an audio session is started!
 *
 *  Supported file formats are:
 *
 *  <ul>
 *  <li> standard wav files </li>
 *  <li> NIST files </li>
 *  <li> header-less raw files, it has to be kept in mind, that multichannel signals are expected in interleaved format (123123123123 and not 111122223333). </li>
 *  <li> OGG/OPUS files </li>
 *  <li> encoded audio files with a constant bitrate (blocksize needs to be configured as 'samples_per_channel' in the audio format) </li>
 *  </ul>
 *
 *  The audio file path of each element in the audio file list (pre-configured or set with customer API) is build
 *  using the following mechanism:
 *
 *  1. A file with an absolute path remains unchanged. A set root path is not considered. Example:
 *
 *  <ul>
 *  <li> audio_files="/test_path/test_file.wav" ==> "/test_path/test_file.wav"</li>
 *  </ul>
 *
 *  2. A file with a relative path is prepended with the pre-configured resp. set root path. The resulting path
 *  is expected to be in relation to the JSON configuration directory. Examples (JSON config dir = "../config/json"):
 *
 *  <ul>
 *  <li> root_path=""          + audio_files="test_file.raw"    ==> "../config/json/test_file.raw"</li>
 *  <li> root_path="test_path" + audio_files="test_file.raw"    ==> "../config/json/test_path/test_file.raw"</li>
 *  <li> root_path="test_path" + audio_files="../test_file.raw" ==> "../config/json/test_file.raw"</li>
 *  </ul>
 */
struct _nuance_audio_IAudioInputFromFile;
/**
 *  @brief  Interface of the 'AudioInputFromFile' audio module, for DDFW only.<p>
 *
 *  This interface is DEPRECATED and for DDFW only. SDK users shall use the AudioFromFile interface.
 *
 *  In general the AudioInputFromFile module offers the possibility to stream audio data from an audio file list
 *  with 1 to n elements to subsequent connected audio modules. The streaming is automatically started and stopped
 *  when an audio session becomes active respectively inactive. For each audio session one file is streamed only.
 *  Each start of a session triggers the AudioInputFromFile audio module to stream the next audio file from the file list.
 *  In case the file list would exceed it is streamed from the beginning again.
 *
 *  The AudioInputFromFile module is usable in two manifestations:
 *
 *  1. AUTOMATICALLY CREATED WITH A PRE-CONFIGURED AUDIO FILE LIST IN THE AUDIO CONFIGURATION FILE (.json):
 *  With calling prepareScenario() resp. activateScenario() an involved AudioInputFromFile instance is automatically
 *  created. NOTE: In this use case the <tt>audio_files</tt> parameter in the audio configuration file (.json) is mandatory!
 *  With automated creation there is no interface handle available to set a file list by customer API.
 *
 *  2. CREATED BY THE CUSTOMER WITH THE OPTION TO SET AN AUDIO FILE LIST DYNAMICALLY BY THE API:
 *  Use the following customer API to create and set up an AudioInputFromFile module. NOTE: In this use case the
 *  <tt>audio_files</tt> parameter in the audio configuration file (.json) is optional in case it is set by the customer
 *  API before an audio session is started!
 *
 *  Supported file formats are:
 *
 *  <ul>
 *  <li> standard wav files </li>
 *  <li> NIST files </li>
 *  <li> header-less raw files, it has to be kept in mind, that multichannel signals are expected in interleaved format (123123123123 and not 111122223333). </li>
 *  <li> OGG/OPUS files </li>
 *  <li> encoded audio files with a constant bitrate (blocksize needs to be configured as 'samples_per_channel' in the audio format) </li>
 *  </ul>
 *
 *  The audio file path of each element in the audio file list (pre-configured or set with customer API) is build
 *  using the following mechanism:
 *
 *  1. A file with an absolute path remains unchanged. A set root path is not considered. Example:
 *
 *  <ul>
 *  <li> audio_files="/test_path/test_file.wav" ==> "/test_path/test_file.wav"</li>
 *  </ul>
 *
 *  2. A file with a relative path is prepended with the pre-configured resp. set root path. The resulting path
 *  is expected to be in relation to the JSON configuration directory. Examples (JSON config dir = "../config/json"):
 *
 *  <ul>
 *  <li> root_path=""          + audio_files="test_file.raw"    ==> "../config/json/test_file.raw"</li>
 *  <li> root_path="test_path" + audio_files="test_file.raw"    ==> "../config/json/test_path/test_file.raw"</li>
 *  <li> root_path="test_path" + audio_files="../test_file.raw" ==> "../config/json/test_file.raw"</li>
 *  </ul>
 */
typedef struct _nuance_audio_IAudioInputFromFile nuance_audio_IAudioInputFromFile;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IAudioFromFileListener.h"
#include "IAudioManager.h"
#include "IAudioModule.h"
#include "IConfiguration.h"
#include "ResultCode.h"
#include "StringList.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates an 'IAudioInputFromFile' audio module instance.
 *
 *  @param[in]     name             Unique name of this audio module instance
 *  @param[in]     audioManager     Audio manager instance.
 *  @param[in]     config           Configuration object.
 *  @param[in]     moduleListener   Listener that is informed about the completion of asynchronous interface calls
 *  @param[out]    audioFromFile    User interface of the created audio module instance.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioInputFromFile_create
(
    const LH_CHAR *name,
    nuance_audio_IAudioManager *audioManager,
    const nuance_common_IConfiguration *config,
    nuance_audio_IAudioFromFileListener *moduleListener,
    nuance_audio_IAudioInputFromFile **audioFromFile
);


/**
 *  Sets a relative or absolute path that is prepended to audio files having a relative path. Audio files with
 *  an absolute path are not affected. A previously set root path even in the audio configuration file (.json)
 *  is being overwritten.
 *
 *  NOTE:
 *  This is a pure convenience method to prevent the customer from the need to add explicitly a root path
 *  in the file list entries in case it is the same. The root path may be empty to 'clear' a previously set one.
 *
 *  A relative path is considered to be in relation to the JSON configuration directory.
 *
 *  The set root path becomes valid with a call of <tt>setFile()</tt> or <tt>setFileList()</tt>.
 *
 *  An error is returned in case audio file streaming is active when calling this method or when
 *  the given root path does not exist.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     rootPath   Root path to be prepended to audio files.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioInputFromFile_setRootPath
(
    nuance_audio_IAudioInputFromFile *instance,
    const LH_CHAR *rootPath
);


/**
 *  Sets an audio file list with a single audio file element. A previously set file list even in the audio
 *  configuration file (.json) is being overwritten. For a list of supported file formats please have a look
 *  into the general description of the AudioInputFromFile module above.
 *
 *  NOTE:
 *  This is a pure convenience method to prevent the customer from having the need to set up a string list
 *  in case of setting a single file only.
 *
 *  In case a root path is set it is prepended to audio files with a relative path. Audio files with an absolute
 *  path are not affected.
 *
 *  An error is returned in case audio file streaming is active when calling this method or when the
 *  given file does not exist.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     file   Audio file name to be set.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioInputFromFile_setFile
(
    nuance_audio_IAudioInputFromFile *instance,
    const LH_CHAR *file
);


/**
 *  Sets an audio file list. A previously set file list even in the audio configuration file (.json) is
 *  being overwritten. For a list of supported file formats please have a look into the general description
 *  of the AudioInputFromFile module above.
 *
 *  The file list will be iterated in a circular manner each time an audio session is being started
 *  (e.g. when a recognition is started). If the end of the list is reached the next capture
 *  request will be serviced using the first file of the list again.
 *
 *  NOTE:
 *  In case a root path is set it is prepended to audio files with a relative path. Audio files with
 *  an absolute path are not affected. It is allowed to mix audio files with absolute and relative
 *  path in one list.
 *
 *  An error is returned in case audio file streaming is active or a file of the file list does not
 *  exist.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     fileList   Audio file list to be set.
 *  @param[in]     nfileList  Number of elements in fileList
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioInputFromFile_setFileList
(
    nuance_audio_IAudioInputFromFile *instance,
    const LH_CHAR * const *fileList, LH_S32 nfileList
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioInputFromFile_getPadNames
(
    const nuance_audio_IAudioInputFromFile *instance,
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
AUDIO_C_EXPORT nuance_common_String *nuance_audio_IAudioInputFromFile_getName(const nuance_audio_IAudioInputFromFile *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioInputFromFile_getStatus
(
    nuance_audio_IAudioInputFromFile *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioInputFromFile_waitForCompletionWithTimeout
(
    nuance_audio_IAudioInputFromFile *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioInputFromFile_waitForCompletion
(
    nuance_audio_IAudioInputFromFile *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioInputFromFile_waitForCompletionAsync
(
    nuance_audio_IAudioInputFromFile *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioInputFromFile_waitForCompletionWithTimeoutAsync
(
    nuance_audio_IAudioInputFromFile *instance,
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioInputFromFile_abortOperation(nuance_audio_IAudioInputFromFile *instance);


/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IAudioInputFromFile_destroy(nuance_audio_IAudioInputFromFile *);


AUDIO_C_EXPORT nuance_audio_IAudioModule *nuance_audio_IAudioInputFromFile_as_nuance_audio_IAudioModule(nuance_audio_IAudioInputFromFile *obj);

AUDIO_C_EXPORT nuance_common_IModule *nuance_audio_IAudioInputFromFile_as_nuance_common_IModule(nuance_audio_IAudioInputFromFile *obj);

AUDIO_C_EXPORT nuance_common_IBackgroundOperation *nuance_audio_IAudioInputFromFile_as_nuance_common_IBackgroundOperation(nuance_audio_IAudioInputFromFile *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOINPUTFROMFILE_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
