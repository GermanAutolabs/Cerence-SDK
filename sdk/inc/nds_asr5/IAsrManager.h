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
 *  Declaration of nuance_asr5_IAsrManager class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5  nuance_asr5
 *  @{
 *  @addtogroup IAsrManager
 *  @{
 *  @file IAsrManager.h
 *
 *  @brief  Interface to AsrManager <p>
 */

#ifndef NUANCE_ASR5_IASRMANAGER_H
#define NUANCE_ASR5_IASRMANAGER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface to AsrManager <p>
 */
struct _nuance_asr5_IAsrManager;
/**
 *  @brief  Interface to AsrManager <p>
 */
typedef struct _nuance_asr5_IAsrManager nuance_asr5_IAsrManager;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "asr5_api_defs.h"

/* API types */
#include "IAsrManagerListener.h"
#include "IAudioManager.h"
#include "ICloudManager.h"
#include "IConfiguration.h"
#include "ResultCode.h"
#include "StringList.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates an instance.
 *
 *  @param[in]     name           Name of the instance to be created.
 *  @param[in]     config         IConfiguration object instance containing the JSON configuration
 *  @param[in]     cloudManager   A cloud manager, a NULL pointer can be passed for local only recognition.
 *  @param[in]     audioManager   An audio manager
 *  @param[in]     listener       An AsrManager listener to receive errors and warnings
 *  @param[out]    theInstance    The object instance created
 *
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IAsrManager_create
(
    const LH_CHAR *name,
    const nuance_common_IConfiguration *config,
    nuance_cloudservices_ICloudManager *cloudManager,
    nuance_audio_IAudioManager *audioManager,
    nuance_asr5_IAsrManagerListener *listener,
    nuance_asr5_IAsrManager **theInstance
);


/**
 *  @brief Set applications on AsrManager, and config contexts for recognizer<p>
 *  <p> This will set domains on AsrManager, and wait for all contexts ready, then set contexts on recognizer.
 *  If the applications is empty, the recognizer will be reset.
 *  The interested audio started time is 0.
 *  If the application require audio be routed, e.g, cloud, the interested audio ended time is determined by the end of speech.
 *  </p>
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     applications   applications
 *  @param[in]     napplications  Number of elements in applications
 *  @param[in]     rec            recognizer
 *
 *  @return Result code
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IAsrManager_setApplicationsWithDefaultTime
(
    nuance_asr5_IAsrManager *instance,
    const LH_CHAR * const *applications, LH_S32 napplications,
    const LH_CHAR *rec
);


/**
 *  @brief Set applications on AsrManager, and config contexts for recognizer<p>
 *  <p> This will set domains on AsrManager, and wait for all contexts ready, then set contexts on recognizer.
 *  If the applications is empty, the recognizer will be reset.
 *  The interested audio started time is defined.
 *  If the application require audio be routed, e.g, cloud, the interested audio ended time is determined by the end of speech.
 *  </p>
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     applications   applications
 *  @param[in]     napplications  Number of elements in applications
 *  @param[in]     rec            recognizer
 *  @param[in]     startTimeMs    Signal time at which the specified StreamingConfig needs to start listening to the audio
 *
 *  @return Result code
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IAsrManager_setApplications
(
    nuance_asr5_IAsrManager *instance,
    const LH_CHAR * const *applications, LH_S32 napplications,
    const LH_CHAR *rec,
    LH_S32 startTimeMs
);


/**
 *  @brief Set applications on AsrManager, and config contexts for recognizer<p>
 *  <p> This will set domains on AsrManager, and wait for all contexts ready, then set contexts on recognizer.
 *  If the applications is empty, the recognizer will be reset.
 *  The interested audio started time is defined.
 *  If the application require audio be routed, e.g, cloud, the interested audio ended time defined, value -1
 *  is equal to the time of the end of speech.
 *  </p>
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     applications   applications
 *  @param[in]     napplications  Number of elements in applications
 *  @param[in]     rec            recognizer
 *  @param[in]     startTimeMs    Signal time at which the specified StreamingConfig needs to start listening to the audio
 *  @param[in]     endTimeMs      Signal time at which the specified StreamingConfig needs to stop listening to the audio
 *
 *  @return Result code
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IAsrManager_setApplicationsWithEndTime
(
    nuance_asr5_IAsrManager *instance,
    const LH_CHAR * const *applications, LH_S32 napplications,
    const LH_CHAR *rec,
    LH_S32 startTimeMs,
    LH_S32 endTimeMs
);


/**
 *  @brief set a specific language<p>
 *
 *  <p> This is method will set the current language for asr paths.
 *  The methoud should be called before:
 *  - creation of recognizer
 *  - creation of application
 *  - creation of dcc
 *  - setApplication
 *  - startData preparation
 *
 *  In case of calling the method, and there are active applications, recognizers, and dccs. An Error will be returned.
 *
 *  </p>
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     language   The current language that will be set and used
 *
 *  @return Result code
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IAsrManager_setLanguage
(
    nuance_asr5_IAsrManager *instance,
    const LH_CHAR *language
);


/**
 *  @brief Load a specific plugin<p>
 *
 *  <p> This is a synchronous method that will load the plugin implementation into the memory, the
 *  interface provided by the plugin is fetched and ready for usage.
 *  The optional parameters could be passed to the plugin.
 *  </p>
 *
 *  @param[in,out] instance      The instance pointer
 *  @param[in]     pluginType    The type of the plugin, can be post_processor, content_values_iterator, or external
 *  @param[in]     pluginName    name of the plugin
 *  @param[in]     configParam   optional parameters passed to the plugin, ignored by post_processor
 *
 *  @return Result code
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IAsrManager_registerPlugin
(
    nuance_asr5_IAsrManager *instance,
    const LH_CHAR *pluginType,
    const LH_CHAR *pluginName,
    const LH_CHAR *configParam
);


/**
 *  @brief Get paths configured for the given IAsrPathsConfig key<p>
 *
 *  <p> This is a synchronous method that will fill the given argument paths
 *  with the list of paths for the given argument IAsrPathsConfig key as
 *  it is configured in the JSON configurations.
 *  </p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key     The IAsrPathsConfig key
 *  @param[out]    paths   List of paths to be filled
 *
 *  @return Result code
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IAsrManager_getPaths
(
    const nuance_asr5_IAsrManager *instance,
    const LH_CHAR *key,
    nuance_common_StringList **paths
);


/**
 *  Destructor
 */
ASR5_C_EXPORT void nuance_asr5_IAsrManager_destroy(nuance_asr5_IAsrManager *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_IASRMANAGER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
