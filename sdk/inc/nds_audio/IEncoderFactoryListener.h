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
 *  Declaration of nuance_audio_IEncoderFactoryListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IEncoderFactoryListener
 *  @{
 *  @file IEncoderFactoryListener.h
 *
 *  @brief  Listener interface of the audio encoder factory. <p>
 */

#ifndef NUANCE_AUDIO_IENCODERFACTORYLISTENER_H
#define NUANCE_AUDIO_IENCODERFACTORYLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Listener interface of the audio encoder factory. <p>
 */
struct _nuance_audio_IEncoderFactoryListener;
/**
 *  @brief  Listener interface of the audio encoder factory. <p>
 */
typedef struct _nuance_audio_IEncoderFactoryListener nuance_audio_IEncoderFactoryListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IEncoder.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  gets the handle of a freshly created IAudioEncoder object. <p>
 *
 *  This method is called only in the context of IAudioEncoderFactory::createAudioEncoder.
 *
 *  From now on the responsibility to destroy the object is in the hand of the caller.
 *
 *  @param[in,out] instance         The instance pointer
 *  @param[in]     instanceHandle   IEncoder interface of the created audio encoder instance.
 */
AUDIO_C_EXPORT void nuance_audio_IEncoderFactoryListener_onEncoderCreated
(
    nuance_audio_IEncoderFactoryListener *instance,
    nuance_audio_IEncoder *instanceHandle
);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IENCODERFACTORYLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
