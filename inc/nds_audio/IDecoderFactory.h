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
 *  Declaration of nuance_audio_IDecoderFactory class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IDecoderFactory
 *  @{
 *  @file IDecoderFactory.h
 *
 *  @brief  Interface of the 'DecoderFactory' component. <p>
 *
 *  The AudioDecoderFactory is used by the audio decoder module to implement the feature of
 *  using different implementations of the IAudioDecoder interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioDecoderFactory").
 */

#ifndef NUANCE_AUDIO_IDECODERFACTORY_H
#define NUANCE_AUDIO_IDECODERFACTORY_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'DecoderFactory' component. <p>
 *
 *  The AudioDecoderFactory is used by the audio decoder module to implement the feature of
 *  using different implementations of the IAudioDecoder interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioDecoderFactory").
 */
struct _nuance_audio_IDecoderFactory;
/**
 *  @brief  Interface of the 'DecoderFactory' component. <p>
 *
 *  The AudioDecoderFactory is used by the audio decoder module to implement the feature of
 *  using different implementations of the IAudioDecoder interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioDecoderFactory").
 */
typedef struct _nuance_audio_IDecoderFactory nuance_audio_IDecoderFactory;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IDecoderFactoryListener.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  Returns the type identifier of the audio decoders created, for instance "OPUS"
 *
 *  This is the value which needs to be set at the "decoder_type" property of the decoder module to trigger the creation of such a decoder.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return type identifier of the decoders this factory is creating.
 */
typedef nuance_common_String *(*FUNC_nuance_audio_IDecoderFactory_getDecoderType)(const void *instance);

/**
 *  Creates an decoder instance.
 *
 *  This method will be called by the audio manager to create an instance of the required decoder type.
 *
 *  @param[in,out] instance                 The instance pointer
 *  @param[in]     instanceHandleReceiver   listener object handle which receives the created decoder instance.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IDecoderFactory_createDecoder)
(
    const void *instance,
    nuance_audio_IDecoderFactoryListener *instanceHandleReceiver
);

/**
 *  Release this instance of the factory.
 *  No further calls to the interface of this factory will be done after that call.
 *  The audio manager has removed that factory handle from its internal registry.
 *
 *  The implementation of that factory can be destroyed.
 *
 *  Since the audio manager calls this releaseFactory method in the context of its destructor,
 *  the deletion of the instance is probably the best solution in the majority of the use cases.
 *
 *  @param[in,out] instance The instance pointer
 */
typedef void (*FUNC_nuance_audio_IDecoderFactory_releaseFactory)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Interface of the 'DecoderFactory' component. <p>
 *
 *  The AudioDecoderFactory is used by the audio decoder module to implement the feature of
 *  using different implementations of the IAudioDecoder interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioDecoderFactory").
 */
struct _vtable_nuance_audio_IDecoderFactory
{
    /**
     *  Returns the type identifier of the audio decoders created, for instance "OPUS"
     *
     *  This is the value which needs to be set at the "decoder_type" property of the decoder module to trigger the creation of such a decoder.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return type identifier of the decoders this factory is creating.
     */
    FUNC_nuance_audio_IDecoderFactory_getDecoderType getDecoderType;

    /**
     *  Creates an decoder instance.
     *
     *  This method will be called by the audio manager to create an instance of the required decoder type.
     *
     *  @param[in,out] instance                 The instance pointer
     *  @param[in]     instanceHandleReceiver   listener object handle which receives the created decoder instance.
     *
     */
    FUNC_nuance_audio_IDecoderFactory_createDecoder createDecoder;

    /**
     *  Release this instance of the factory.
     *  No further calls to the interface of this factory will be done after that call.
     *  The audio manager has removed that factory handle from its internal registry.
     *
     *  The implementation of that factory can be destroyed.
     *
     *  Since the audio manager calls this releaseFactory method in the context of its destructor,
     *  the deletion of the instance is probably the best solution in the majority of the use cases.
     *
     *  @param[in,out] instance The instance pointer
     */
    FUNC_nuance_audio_IDecoderFactory_releaseFactory releaseFactory;

};
/**
 *  @brief  Interface of the 'DecoderFactory' component. <p>
 *
 *  The AudioDecoderFactory is used by the audio decoder module to implement the feature of
 *  using different implementations of the IAudioDecoder interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioDecoderFactory").
 */
typedef struct _vtable_nuance_audio_IDecoderFactory vtable_nuance_audio_IDecoderFactory;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IDecoderFactory *nuance_audio_IDecoderFactory_create
(
    const vtable_nuance_audio_IDecoderFactory *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IDecoderFactory_destroy(nuance_audio_IDecoderFactory *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IDECODERFACTORY_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
