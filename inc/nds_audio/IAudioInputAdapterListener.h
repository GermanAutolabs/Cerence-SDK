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
 *  Declaration of nuance_audio_IAudioInputAdapterListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioInputAdapterListener
 *  @{
 *  @file IAudioInputAdapterListener.h
 *
 *  @brief  Listener interface of the audio input adapter. <p>
 *
 *  This interface is used from an audio input adapter interface implementation to:
 *
 *  1) announce captured audio packages from the system's audio device to the audio framework of the SDK
 *  2) retrieve the flow status of the SDK's audio framework
 *
 *  The listener interface is implemented by the AudioInput audio module.
 */

#ifndef NUANCE_AUDIO_IAUDIOINPUTADAPTERLISTENER_H
#define NUANCE_AUDIO_IAUDIOINPUTADAPTERLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare inner types of class ************************************************************************************/

/**
 *  @brief  Flow status of the SDK's audio framework. <p>
 *
 *  This enumeration represents the flow state of the SDK's audio framework.
 */
typedef enum
{
    NUANCE_AUDIO_IAUDIOINPUTADAPTERLISTENER_NORMAL,     /**< Further audio data can be handled. */
    NUANCE_AUDIO_IAUDIOINPUTADAPTERLISTENER_WILL_DROP,  /**< The next passed audio data object will be dropped. No action required for adapter                                           representing real audio devices, other data sources (file/memory) have to pause                                           writing until resume() is called. */
    NUANCE_AUDIO_IAUDIOINPUTADAPTERLISTENER_DROPPED     /**< The currently passed audio data object was dropped. No action required. */
} nuance_audio_IAudioInputAdapterListener_FlowState;


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Listener interface of the audio input adapter. <p>
 *
 *  This interface is used from an audio input adapter interface implementation to:
 *
 *  1) announce captured audio packages from the system's audio device to the audio framework of the SDK
 *  2) retrieve the flow status of the SDK's audio framework
 *
 *  The listener interface is implemented by the AudioInput audio module.
 */
struct _nuance_audio_IAudioInputAdapterListener;
/**
 *  @brief  Listener interface of the audio input adapter. <p>
 *
 *  This interface is used from an audio input adapter interface implementation to:
 *
 *  1) announce captured audio packages from the system's audio device to the audio framework of the SDK
 *  2) retrieve the flow status of the SDK's audio framework
 *
 *  The listener interface is implemented by the AudioInput audio module.
 */
typedef struct _nuance_audio_IAudioInputAdapterListener nuance_audio_IAudioInputAdapterListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "AudioData.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  The audio input adapter announces captured audio data. <p>
 *
 *  The passed audio data has to be in the audio format the audio input adapter is configured for.
 *  The passed audio data has to be only valid until this method returns.
 *
 *  This method may be called only if the audio input adapter is started.
 *
 *  This method may be called first in context of the IAudioInputAdapter::start() method.
 *
 *  In context of this method it is allowed to call the IAudioInputAdapter::getErrorText() method but no
 *  other IAudioInputAdapter interface method.
 *
 *  If isLast is set to true this is interpreted as the end of the current audio stream. While the audio input
 *  is started multiple streams can be sent. Only if this flag is set it is allowed to pass less audio data than
 *  defined in the audio format.
 *
 *  The flowState can be used by the adapter to implement a flow control between the adapter and the SDK's audio framework.
 *  Flow control should not be used by adapters capturing from real audio devices.
 *
 *  If a different data source is used (memory, file), writing data to the SDK's audio framework should be paused by the
 *  adapter on a switch of the flowState from NORMAL to WILL_DROP. To ensure full data integrity writing should
 *  not be resumed before IAudioInputAdapter::resume() method was called. If that is not considered data can be
 *  dropped.
 *
 *  When accessing real audio devices dropped data will be announced. It is not intended to implement any further
 *  logic in this adapter, since dropped data is an indication of a wrong configured system then.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     audioData    AudioData object containing the captured audio data.
 *  @param[in]     naudioData   Number of elements in audioData
 *  @param[in]     isLast       This is the last package of this audio stream.
 *  @param[in]     resultCode   Capture result code.
 *  @param[out]    flowState    The current flow state of the SDK's audio framework.
 */
AUDIO_C_EXPORT void nuance_audio_IAudioInputAdapterListener_onAudioDataCaptured
(
    nuance_audio_IAudioInputAdapterListener *instance,
    LH_S16  const *audioData, LH_S32 naudioData,
    LH_BOOL isLast,
    nuance_common_ResultCode resultCode,
    nuance_audio_IAudioInputAdapterListener_FlowState *flowState
);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOINPUTADAPTERLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
