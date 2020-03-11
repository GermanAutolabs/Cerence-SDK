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
 *  Declaration of nuance_audio_IDiagnosis class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IDiagnosis
 *  @{
 *  @file audio_IDiagnosis.h
 *
 *  @brief Diagnosis interface for DragonDrive Audio diagnosis calls <p>
 *
 *  This interface is meant to be used at the DDFW only.
 */

#ifndef NUANCE_AUDIO_IDIAGNOSIS_H
#define NUANCE_AUDIO_IDIAGNOSIS_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief Diagnosis interface for DragonDrive Audio diagnosis calls <p>
 *
 *  This interface is meant to be used at the DDFW only.
 */
struct _nuance_audio_IDiagnosis;
/**
 *  @brief Diagnosis interface for DragonDrive Audio diagnosis calls <p>
 *
 *  This interface is meant to be used at the DDFW only.
 */
typedef struct _nuance_audio_IDiagnosis nuance_audio_IDiagnosis;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IAudioManager.h"
#include "ResultCode.h"
#include "audio_IDiagnosisListener.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Returns the Version of the audio component.
 *
 *  @param[in]     audioManager   Audio manager instance.
 *  @param[out]    sseVersion     Version of the SSE module.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IDiagnosis_getVersion
(
    nuance_audio_IAudioManager *audioManager,
    nuance_common_String **sseVersion
);


/**
 *  activates a special diagnosis audio scenario
 *
 *  @param[in]     audioManager   Audio manager instance.
 *  @param[in]     listener       Listener for the Diagnosis events
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IDiagnosis_startAudioInAnalysis
(
    nuance_audio_IAudioManager *audioManager,
    nuance_audio_IDiagnosisListener *listener
);


/**
 *  deactivates a special diagnosis audio scenario
 *
 *  @param[in]     audioManager   Audio manager instance.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IDiagnosis_stopAudioInAnalysis(nuance_audio_IAudioManager *audioManager);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IDIAGNOSIS_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
