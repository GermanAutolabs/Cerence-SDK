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
 *  Declaration of nuance_audio_IAudioManager class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioManager
 *  @{
 *  @file IAudioManager.h
 *
 *  @brief  Interface of the 'AudioManager' component. <p>
 *
 *  The 'AudioManager' is the central management instance of the SDK's audio framework.
 *
 *  At creation it is responsible to instantiate and set up all audio backbone components.
 *  This includes for instance the creation of the chunk and codec pool for the audio modules.
 *
 *  The audio manager instance is given to each created audio module. At creation each audio
 *  module has to register to the audio manager and retrieves the runner, chunk and codec pool.
 *  At destruction each audio module has to deregister from the audio manager. With that the
 *  audio manager has the possibility to connect all registered audio modules.
 *
 *  The audio manager provides a method to build up an audio module chain based on an audio
 *  scenario defined in the audio configuration.
 */

#ifndef NUANCE_AUDIO_IAUDIOMANAGER_H
#define NUANCE_AUDIO_IAUDIOMANAGER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'AudioManager' component. <p>
 *
 *  The 'AudioManager' is the central management instance of the SDK's audio framework.
 *
 *  At creation it is responsible to instantiate and set up all audio backbone components.
 *  This includes for instance the creation of the chunk and codec pool for the audio modules.
 *
 *  The audio manager instance is given to each created audio module. At creation each audio
 *  module has to register to the audio manager and retrieves the runner, chunk and codec pool.
 *  At destruction each audio module has to deregister from the audio manager. With that the
 *  audio manager has the possibility to connect all registered audio modules.
 *
 *  The audio manager provides a method to build up an audio module chain based on an audio
 *  scenario defined in the audio configuration.
 */
struct _nuance_audio_IAudioManager;
/**
 *  @brief  Interface of the 'AudioManager' component. <p>
 *
 *  The 'AudioManager' is the central management instance of the SDK's audio framework.
 *
 *  At creation it is responsible to instantiate and set up all audio backbone components.
 *  This includes for instance the creation of the chunk and codec pool for the audio modules.
 *
 *  The audio manager instance is given to each created audio module. At creation each audio
 *  module has to register to the audio manager and retrieves the runner, chunk and codec pool.
 *  At destruction each audio module has to deregister from the audio manager. With that the
 *  audio manager has the possibility to connect all registered audio modules.
 *
 *  The audio manager provides a method to build up an audio module chain based on an audio
 *  scenario defined in the audio configuration.
 */
typedef struct _nuance_audio_IAudioManager nuance_audio_IAudioManager;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IAudioInputAdapterFactory.h"
#include "IAudioManagerListener.h"
#include "IAudioOutputAdapterFactory.h"
#include "IConfiguration.h"
#include "IContainerPackerFactory.h"
#include "IContainerUnpackerFactory.h"
#include "IDecoderFactory.h"
#include "IEncoderFactory.h"
#include "IManager.h"
#include "ISystemManager.h"
#include "ResultCode.h"
#include "StringList.h"
#include "audio_IDiagnosisListener.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates an IAudioManager object instance.
 *
 *  @param[in]     name            Name of the audio manager instance to be created.
 *  @param[in]     systemManager   Object instance of the ISystemManager.
 *  @param[in]     config          IConfiguration object instance containing the audio JSON configuration
 *  @param[in]     listener        Listener that is informed about asynchronous audio manager events.
 *  @param[out]    audioManager    Created IAudioManager object instance.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_create
(
    const LH_CHAR *name,
    nuance_common_ISystemManager *systemManager,
    const nuance_common_IConfiguration *config,
    nuance_audio_IAudioManagerListener *listener,
    nuance_audio_IAudioManager **audioManager
);


/**
 *  @brief  Connects a source pad to a sink pad of two different audio modules. <p>
 *
 *  DEPRRECATED: This method shall not be used anymore, please use 'activateScenario' instead.
 *
 *  @param[in,out] instance      The instance pointer
 *  @param[in]     sourcePadId   Identifier of the source pad to be connected.
 *  @param[in]     sinkPadId     Identifier of the sink pad to be connected.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_connect
(
    nuance_audio_IAudioManager *instance,
    const LH_CHAR *sourcePadId,
    const LH_CHAR *sinkPadId
);


/**
 *  @brief  Disconnects a source pad from a sink pad of two different audio modules. <p>
 *
 *  DEPRRECATED: This method shall not be used anymore, please use 'deactivateScenario' instead.
 *
 *  @param[in,out] instance      The instance pointer
 *  @param[in]     sourcePadId   Identifier of the source pad to be disconnected.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_disconnect
(
    nuance_audio_IAudioManager *instance,
    const LH_CHAR *sourcePadId
);


/**
 *  @brief  Prepares a list of scenarios. <p>
 *
 *  With this method the automatic preparation step done at each scenario activation can be done
 *  explicitly once all modules required by the application are created.
 *
 *  This will speed up the subsequent scenario activation/deactivation calls.
 *
 *  During the scenario preparation it is checked if all necessary generators, processors and consumers
 *  are available to build the audio paths defined in the handed scenarios.
 *
 *  Missing modules will be started implicitly under the hood, if configured for automated startup.
 *
 *  If a module is missing and not configured for automated startup, a log message is written and an error will be returned.
 *
 *  This way it can be checked if the desired scenarios are ready for use.
 *
 *  The activation can fail afterwards, if an already active scenario uses the same modules in
 *  a different audio path.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     scenarioList   list of scenario names to be prepared
 *  @param[in]     nscenarioList  Number of elements in scenarioList
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_prepareScenarios
(
    nuance_audio_IAudioManager *instance,
    const LH_CHAR * const *scenarioList, LH_S32 nscenarioList
);


/**
 *  @brief  Un-prepares a list of scenarios. <p>
 *
 *  With this method the effects of an previously call to prepareScenarios() are reverted.
 *
 *  The call to unPrepareScenarios() will free all the modules created while calling prepareScenarios() if
 *  they are not used in other prepared scenarios.
 *
 *  If prepareScenarios() was called, it is mandatory to call unPrepareScenarios() before ending the application
 *  to clean up the implicitly created audio modules.
 *
 *  Calling this method on an active scenario leads to an error.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     scenarioList   list of scenario names to be unprepared
 *  @param[in]     nscenarioList  Number of elements in scenarioList
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_unPrepareScenarios
(
    nuance_audio_IAudioManager *instance,
    const LH_CHAR * const *scenarioList, LH_S32 nscenarioList
);


/**
 *  @brief  Activates an audio scenario by connecting the involved modules. <p>
 *
 *  If the handed scenario is not prepared this will be done automatically.
 *
 *  It is valid to activate multiple scenarios in parallel as long as they don't connect
 *  the same audio modules in mutually exclusive audio paths. Using the same audio
 *  paths in different activated scenarios is supported.
 *
 *  Trying to activate an already active scenario will lead to an error.
 *
 *  It is recommended to deactivate an activated scenario before destruction of audio modules.
 *  If this is not considered, the activated audio paths are disconnected,
 *  the scenario is no more valid and enters an error state.
 *  Afterwards the scenario still needs to be deactivated before it can be used again.
 *
 *  If a scenario is only activated and not prepared explicitly before, a later call of
 *  deactivateScenario will lead to the destruction of implicitly started modules.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     scenarioName   name of the scenario which should be activated
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_activateScenario
(
    nuance_audio_IAudioManager *instance,
    const LH_CHAR *scenarioName
);


/**
 *  @brief  Deactivates an audio scenario by disconnecting the involved modules. <p>
 *
 *  Trying to deactivate an already inactive scenario will lead to an error.
 *
 *  It is recommended to deactivate an activated scenario before destruction of audio modules.
 *  If this is not considered, the activated audio paths are disconnected,
 *  the scenario is no more valid and enters an error state.
 *  Afterwards the scenario still needs to be deactivated before it can be used again.
 *
 *  If the handed scenario was prepared automatically during an activateScenario() this will trigger an
 *  automatic cleanup/unprepare of the scenario.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     scenarioName   name of the scenario which should be deactivated
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_deActivateScenario
(
    nuance_audio_IAudioManager *instance,
    const LH_CHAR *scenarioName
);


/**
 *  @brief  registers an audio container packer factory.<p>
 *
 *  once a factory instance for a specific audio container packer is registered the
 *  creation of modules using those container packers is possible.
 *
 *  It is only possible to register one packer factory instance per container type.
 *  Trying to register another packer factory instance for the same container type results in an error.
 *
 *  Once the audio manager does not need/access that instance anymore the method releaseFactory is called.
 *  This is the case when the audio manager is destroyed.
 *
 *  @param[in,out] instance                      The instance pointer
 *  @param[in]     audioContainerPackerFactory   audio container packer factory instance which should be registered.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_registerAudioContainerPackerFactory
(
    nuance_audio_IAudioManager *instance,
    nuance_audio_IContainerPackerFactory *audioContainerPackerFactory
);


/**
 *  @brief  registers an audio container unpacker factory.<p>
 *
 *  once a factory instance for a specific audio container unpacker is registered the
 *  creation of modules using those container unpackers is possible.
 *
 *  It is only possible to register one unpacker factory instance per container type.
 *  Trying to register another unpacker factory instance for the same container type results in an error.
 *
 *  Once the audio manager does not need/access that instance anymore the method releaseFactory is called.
 *  This is the case when the audio manager is destroyed.
 *
 *  @param[in,out] instance                        The instance pointer
 *  @param[in]     audioContainerUnpackerFactory   audio container unpacker factory instance which should be registered.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_registerAudioContainerUnpackerFactory
(
    nuance_audio_IAudioManager *instance,
    nuance_audio_IContainerUnpackerFactory *audioContainerUnpackerFactory
);


/**
 *  @brief  registers an audio encoder factory.<p>
 *
 *  once a factory instance for a specific audio encoder is registered the
 *  creation of modules using those encoders is possible.
 *
 *  It is only possible to register one factory instance per encoder type.
 *  Trying to register another factory instance for the same encoder type results in an error.
 *
 *  Once the audio manager does not need/access that instance anymore the method releaseFactory is called.
 *  This is the case when the audio manager is destroyed.
 *
 *  @param[in,out] instance              The instance pointer
 *  @param[in]     audioEncoderFactory   audio encoder factory instance which should be registered.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_registerAudioEncoderFactory
(
    nuance_audio_IAudioManager *instance,
    nuance_audio_IEncoderFactory *audioEncoderFactory
);


/**
 *  @brief  registers an audio decoder factory.<p>
 *
 *  once a factory instance for a specific audio decoder is registered the
 *  creation of modules using those decoders is possible.
 *
 *  It is only possible to register one factory instance per decoder type.
 *  Trying to register another factory instance for the same decoder type results in an error.
 *
 *  Once the audio manager does not need/access that instance anymore the method releaseFactory is called.
 *  This is the case when the audio manager is destroyed.
 *
 *  @param[in,out] instance              The instance pointer
 *  @param[in]     audioDecoderFactory   audio decoder factory instance which should be registered.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_registerAudioDecoderFactory
(
    nuance_audio_IAudioManager *instance,
    nuance_audio_IDecoderFactory *audioDecoderFactory
);


/**
 *  @brief  registers an audio input adapter factory.<p>
 *
 *  once a factory instance for a specific audio input adapter is registered the
 *  creation of modules using those adapters is possible.
 *
 *  It is only possible to register one factory instance per adapter type.
 *  Trying to register another factory instance for the same adapter type results in an error.
 *
 *  Once the audio manager does not need/access that instance anymore the method releaseFactory is called.
 *  This is the case when the audio manager is destroyed.
 *
 *  @param[in,out] instance                   The instance pointer
 *  @param[in]     audioInputAdapterFactory   audio input adapter factory instance which should be registered.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_registerAudioInputAdapterFactory
(
    nuance_audio_IAudioManager *instance,
    nuance_audio_IAudioInputAdapterFactory *audioInputAdapterFactory
);


/**
 *  @brief  registers an audio output adapter factory.<p>
 *
 *  once a factory instance for a specific audio output adapter is registered the
 *  creation of modules using those adapters is possible.
 *
 *  It is only possible to register one factory instance per adapter type.
 *  Trying to register another factory instance for the same adapter type results in an error.
 *
 *  Once the audio manager does not need/access that instance anymore the method releaseFactory is called.
 *  This is the case when the audio manager is destroyed.
 *
 *  @param[in,out] instance                    The instance pointer
 *  @param[in]     audioOutputAdapterFactory   audio output adapter factory instance which should be registered.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_registerAudioOutputAdapterFactory
(
    nuance_audio_IAudioManager *instance,
    nuance_audio_IAudioOutputAdapterFactory *audioOutputAdapterFactory
);


/**
 *  @brief  Returns the versions for the audio component. <p>
 *
 *  This method is meant to be used at the DDFW only.
 *
 *  Each module version number corresponds to the module name at the same list index.
 *
 *  @param[in,out] instance         The instance pointer
 *  @param[out]    version          The product version the audio component is part of.
 *  @param[out]    moduleNames      Names of the audio modules.
 *  @param[out]    moduleVersions   Versions of the audio modules.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_getVersions
(
    nuance_audio_IAudioManager *instance,
    nuance_common_String **version,
    nuance_common_StringList **moduleNames,
    nuance_common_StringList **moduleVersions
);


/**
 *  @brief Hand in an instance of an IDiagnosisListener Object.<p>
 *
 *  This method is meant to be used at the DDFW only.
 *
 *  Hand in an instance of an IDiagnosisListener Object, which has an
 *  higher priority than an audio manager listener.
 *  This means that as long as this listener is registered it is ensured that the events are emitted here.
 *
 *  The handle has to be valid until the registration is reverted by handing in NULL or as long as the audio manager lives
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     listener   Listener for the Diagnosis events
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IAudioManager_registerDiagnosisListener
(
    nuance_audio_IAudioManager *instance,
    nuance_audio_IDiagnosisListener *listener
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
AUDIO_C_EXPORT nuance_common_String *nuance_audio_IAudioManager_getType(const nuance_audio_IAudioManager *instance);


/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IAudioManager_destroy(nuance_audio_IAudioManager *);


AUDIO_C_EXPORT nuance_common_IManager *nuance_audio_IAudioManager_as_nuance_common_IManager(nuance_audio_IAudioManager *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOMANAGER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
