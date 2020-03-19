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
 *  Declaration of nuance_audio_IAudioOutputAdapterListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioOutputAdapterListener
 *  @{
 *  @file IAudioOutputAdapterListener.h
 *
 *  @brief  Listener interface of the audio output adapter. <p>
 *
 *  This interface is used from an audio output adapter interface implementation to announce played
 *  out resp. aborted audio packages to the SDK's audio framework.
 *
 *  This listener interface is implemented by the AudioOutput audio module.
 */

#ifndef NUANCE_AUDIO_IAUDIOOUTPUTADAPTERLISTENER_H
#define NUANCE_AUDIO_IAUDIOOUTPUTADAPTERLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Listener interface of the audio output adapter. <p>
 *
 *  This interface is used from an audio output adapter interface implementation to announce played
 *  out resp. aborted audio packages to the SDK's audio framework.
 *
 *  This listener interface is implemented by the AudioOutput audio module.
 */
struct _nuance_audio_IAudioOutputAdapterListener;
/**
 *  @brief  Listener interface of the audio output adapter. <p>
 *
 *  This interface is used from an audio output adapter interface implementation to announce played
 *  out resp. aborted audio packages to the SDK's audio framework.
 *
 *  This listener interface is implemented by the AudioOutput audio module.
 */
typedef struct _nuance_audio_IAudioOutputAdapterListener nuance_audio_IAudioOutputAdapterListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  The audio output adapter announces a played out resp. an aborted audio data package. <p>
 *
 *  The audio data packages must be announced in the order corresponding to their IAudioOutputAdapter::write()
 *  calls. Means, first audio package written to the audio output adapter must be also announced first and
 *  so on.
 *
 *  This method may be called in context of the IAudioOutputAdapter::abort() method but not in context of any
 *  other IAudioOutputAdapter interface method.
 *
 *  In context of this method it is allowed to call the IAudioOutputAdapter::getErrorText() method but no
 *  other IAudioOutputAdapter interface method.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Playback result code.
 */
AUDIO_C_EXPORT void nuance_audio_IAudioOutputAdapterListener_onAudioDataPlayed
(
    nuance_audio_IAudioOutputAdapterListener *instance,
    nuance_common_ResultCode resultCode
);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOOUTPUTADAPTERLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
