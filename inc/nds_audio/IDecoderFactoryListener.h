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
 *  Declaration of nuance_audio_IDecoderFactoryListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IDecoderFactoryListener
 *  @{
 *  @file IDecoderFactoryListener.h
 *
 *  @brief  Listener interface of the audio decoder factory. <p>
 */

#ifndef NUANCE_AUDIO_IDECODERFACTORYLISTENER_H
#define NUANCE_AUDIO_IDECODERFACTORYLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Listener interface of the audio decoder factory. <p>
 */
struct _nuance_audio_IDecoderFactoryListener;
/**
 *  @brief  Listener interface of the audio decoder factory. <p>
 */
typedef struct _nuance_audio_IDecoderFactoryListener nuance_audio_IDecoderFactoryListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IDecoder.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  gets the handle of a freshly created IAudioDecoder object. <p>
 *
 *  This method is called only in the context of IAudioDecoderFactory::createAudioDecoder.
 *
 *  From now on the responsibility to destroy the object is in the hand of the caller.
 *
 *  @param[in,out] instance         The instance pointer
 *  @param[in]     instanceHandle   IDecoder interface of the created audio decoder instance.
 */
AUDIO_C_EXPORT void nuance_audio_IDecoderFactoryListener_onDecoderCreated
(
    nuance_audio_IDecoderFactoryListener *instance,
    nuance_audio_IDecoder *instanceHandle
);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IDECODERFACTORYLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
