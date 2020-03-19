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
 *  Declaration of nuance_audio_IEncoderFactory class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IEncoderFactory
 *  @{
 *  @file IEncoderFactory.h
 *
 *  @brief  Interface of the 'EncoderFactory' component. <p>
 *
 *  The AudioEncoderFactory is used by the audio encoder module to implement the feature of
 *  using different implementations of the IAudioEncoder interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioEncoderFactory").
 */

#ifndef NUANCE_AUDIO_IENCODERFACTORY_H
#define NUANCE_AUDIO_IENCODERFACTORY_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'EncoderFactory' component. <p>
 *
 *  The AudioEncoderFactory is used by the audio encoder module to implement the feature of
 *  using different implementations of the IAudioEncoder interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioEncoderFactory").
 */
struct _nuance_audio_IEncoderFactory;
/**
 *  @brief  Interface of the 'EncoderFactory' component. <p>
 *
 *  The AudioEncoderFactory is used by the audio encoder module to implement the feature of
 *  using different implementations of the IAudioEncoder interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioEncoderFactory").
 */
typedef struct _nuance_audio_IEncoderFactory nuance_audio_IEncoderFactory;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IEncoderFactoryListener.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  Returns the type identifier of the audio encoders created, for instance "OPUS"
 *
 *  This is the value which needs to be set at the "encoder_type" property of the encoder module to trigger the creation of such a encoder.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return type identifier of the encoders this factory is creating.
 */
typedef nuance_common_String *(*FUNC_nuance_audio_IEncoderFactory_getEncoderType)(const void *instance);

/**
 *  Creates an encoder instance.
 *
 *  This method will be called by the audio manager to create an instance of the required encoder type.
 *
 *  @param[in,out] instance                 The instance pointer
 *  @param[in]     instanceHandleReceiver   listener object handle which receives the created encoder instance.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IEncoderFactory_createEncoder)
(
    const void *instance,
    nuance_audio_IEncoderFactoryListener *instanceHandleReceiver
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
typedef void (*FUNC_nuance_audio_IEncoderFactory_releaseFactory)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Interface of the 'EncoderFactory' component. <p>
 *
 *  The AudioEncoderFactory is used by the audio encoder module to implement the feature of
 *  using different implementations of the IAudioEncoder interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioEncoderFactory").
 */
struct _vtable_nuance_audio_IEncoderFactory
{
    /**
     *  Returns the type identifier of the audio encoders created, for instance "OPUS"
     *
     *  This is the value which needs to be set at the "encoder_type" property of the encoder module to trigger the creation of such a encoder.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return type identifier of the encoders this factory is creating.
     */
    FUNC_nuance_audio_IEncoderFactory_getEncoderType getEncoderType;

    /**
     *  Creates an encoder instance.
     *
     *  This method will be called by the audio manager to create an instance of the required encoder type.
     *
     *  @param[in,out] instance                 The instance pointer
     *  @param[in]     instanceHandleReceiver   listener object handle which receives the created encoder instance.
     *
     */
    FUNC_nuance_audio_IEncoderFactory_createEncoder createEncoder;

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
    FUNC_nuance_audio_IEncoderFactory_releaseFactory releaseFactory;

};
/**
 *  @brief  Interface of the 'EncoderFactory' component. <p>
 *
 *  The AudioEncoderFactory is used by the audio encoder module to implement the feature of
 *  using different implementations of the IAudioEncoder interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioEncoderFactory").
 */
typedef struct _vtable_nuance_audio_IEncoderFactory vtable_nuance_audio_IEncoderFactory;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IEncoderFactory *nuance_audio_IEncoderFactory_create
(
    const vtable_nuance_audio_IEncoderFactory *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IEncoderFactory_destroy(nuance_audio_IEncoderFactory *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IENCODERFACTORY_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
