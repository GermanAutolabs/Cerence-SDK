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
 *  Declaration of nuance_audio_IAudioInputAdapterFactoryListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioInputAdapterFactoryListener
 *  @{
 *  @file IAudioInputAdapterFactoryListener.h
 *
 *  @brief  Listener interface of the audio input adapter factory. <p>
 */

#ifndef NUANCE_AUDIO_IAUDIOINPUTADAPTERFACTORYLISTENER_H
#define NUANCE_AUDIO_IAUDIOINPUTADAPTERFACTORYLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Listener interface of the audio input adapter factory. <p>
 */
struct _nuance_audio_IAudioInputAdapterFactoryListener;
/**
 *  @brief  Listener interface of the audio input adapter factory. <p>
 */
typedef struct _nuance_audio_IAudioInputAdapterFactoryListener nuance_audio_IAudioInputAdapterFactoryListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IAudioInputAdapter.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  gets the handle of a freshly created IAudioInputAdapter object. <p>
 *
 *  This method is called only in the context of IAudioInputAdapterFactory::createAudioInputAdapter.
 *
 *  From now on the responsibility to destroy the object is in the hand of the caller.
 *
 *  @param[in,out] instance         The instance pointer
 *  @param[in]     instanceHandle   IAudioInputAdapter interface of the created audio adapter instance.
 */
AUDIO_C_EXPORT void nuance_audio_IAudioInputAdapterFactoryListener_onInputAdapterCreated
(
    nuance_audio_IAudioInputAdapterFactoryListener *instance,
    nuance_audio_IAudioInputAdapter *instanceHandle
);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOINPUTADAPTERFACTORYLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
