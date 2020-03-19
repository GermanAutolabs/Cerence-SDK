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
 *  Declaration of nuance_audio_IAudioInputAdapterFactory class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioInputAdapterFactory
 *  @{
 *  @file IAudioInputAdapterFactory.h
 *
 *  @brief  Interface of the 'AudioInputAdapterFactory' component. <p>
 *
 *  The AudioInputAdapterFactory is used by the audio input module to implement the feature of
 *  using different implementations of the IAudioAdapter interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioInputAdapterFactory").
 */

#ifndef NUANCE_AUDIO_IAUDIOINPUTADAPTERFACTORY_H
#define NUANCE_AUDIO_IAUDIOINPUTADAPTERFACTORY_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'AudioInputAdapterFactory' component. <p>
 *
 *  The AudioInputAdapterFactory is used by the audio input module to implement the feature of
 *  using different implementations of the IAudioAdapter interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioInputAdapterFactory").
 */
struct _nuance_audio_IAudioInputAdapterFactory;
/**
 *  @brief  Interface of the 'AudioInputAdapterFactory' component. <p>
 *
 *  The AudioInputAdapterFactory is used by the audio input module to implement the feature of
 *  using different implementations of the IAudioAdapter interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioInputAdapterFactory").
 */
typedef struct _nuance_audio_IAudioInputAdapterFactory nuance_audio_IAudioInputAdapterFactory;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IAudioInputAdapterFactoryListener.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  Returns the type identifier of the audio adapters created, for instance "PAL_AUDIO".
 *
 *  This is the value which needs to be set at the "adapter_type" property of the audio input module to trigger the creation of such an adapter.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return type identifier of the adapters this factory is creating.
 */
typedef nuance_common_String *(*FUNC_nuance_audio_IAudioInputAdapterFactory_getAdapterType)(const void *instance);

/**
 *  Creates an audio input adapter instance.
 *
 *  This method will be called by the audio manager to create an instance of the required adapter type.
 *
 *  @param[in,out] instance                 The instance pointer
 *  @param[in]     instanceHandleReceiver   listener object handle which receives the created adapter instance.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioInputAdapterFactory_createAudioInputAdapter)
(
    const void *instance,
    nuance_audio_IAudioInputAdapterFactoryListener *instanceHandleReceiver
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
typedef void (*FUNC_nuance_audio_IAudioInputAdapterFactory_releaseFactory)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Interface of the 'AudioInputAdapterFactory' component. <p>
 *
 *  The AudioInputAdapterFactory is used by the audio input module to implement the feature of
 *  using different implementations of the IAudioAdapter interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioInputAdapterFactory").
 */
struct _vtable_nuance_audio_IAudioInputAdapterFactory
{
    /**
     *  Returns the type identifier of the audio adapters created, for instance "PAL_AUDIO".
     *
     *  This is the value which needs to be set at the "adapter_type" property of the audio input module to trigger the creation of such an adapter.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return type identifier of the adapters this factory is creating.
     */
    FUNC_nuance_audio_IAudioInputAdapterFactory_getAdapterType getAdapterType;

    /**
     *  Creates an audio input adapter instance.
     *
     *  This method will be called by the audio manager to create an instance of the required adapter type.
     *
     *  @param[in,out] instance                 The instance pointer
     *  @param[in]     instanceHandleReceiver   listener object handle which receives the created adapter instance.
     *
     */
    FUNC_nuance_audio_IAudioInputAdapterFactory_createAudioInputAdapter createAudioInputAdapter;

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
    FUNC_nuance_audio_IAudioInputAdapterFactory_releaseFactory releaseFactory;

};
/**
 *  @brief  Interface of the 'AudioInputAdapterFactory' component. <p>
 *
 *  The AudioInputAdapterFactory is used by the audio input module to implement the feature of
 *  using different implementations of the IAudioAdapter interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioInputAdapterFactory").
 */
typedef struct _vtable_nuance_audio_IAudioInputAdapterFactory vtable_nuance_audio_IAudioInputAdapterFactory;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IAudioInputAdapterFactory *nuance_audio_IAudioInputAdapterFactory_create
(
    const vtable_nuance_audio_IAudioInputAdapterFactory *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IAudioInputAdapterFactory_destroy(nuance_audio_IAudioInputAdapterFactory *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOINPUTADAPTERFACTORY_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
