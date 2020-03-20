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
 *  Declaration of nuance_audio_IContainerPackerFactory class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IContainerPackerFactory
 *  @{
 *  @file IContainerPackerFactory.h
 *
 *  @brief  Interface of the 'ContainerPackerFactory' component. <p>
 *
 *  The ContainerPackerFactory is used by the audio encoder module to implement the feature of
 *  using different implementations of the IContainerPacker interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioContainerPackerFactory").
 */

#ifndef NUANCE_AUDIO_ICONTAINERPACKERFACTORY_H
#define NUANCE_AUDIO_ICONTAINERPACKERFACTORY_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'ContainerPackerFactory' component. <p>
 *
 *  The ContainerPackerFactory is used by the audio encoder module to implement the feature of
 *  using different implementations of the IContainerPacker interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioContainerPackerFactory").
 */
struct _nuance_audio_IContainerPackerFactory;
/**
 *  @brief  Interface of the 'ContainerPackerFactory' component. <p>
 *
 *  The ContainerPackerFactory is used by the audio encoder module to implement the feature of
 *  using different implementations of the IContainerPacker interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioContainerPackerFactory").
 */
typedef struct _nuance_audio_IContainerPackerFactory nuance_audio_IContainerPackerFactory;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IContainerPackerFactoryListener.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  Returns the type identifier of the audio containers used to pack the data into, for instance "OGG"
 *
 *  This is the value which needs to be set at the "container_type" property of the encoder module to trigger the creation of such an container packer.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return type identifier of the containers this factory is creating.
 */
typedef nuance_common_String *(*FUNC_nuance_audio_IContainerPackerFactory_getContainerType)(const void *instance);

/**
 *  Creates an container packer instance.
 *
 *  This method will be called by the audio manager to create an instance of the required container packer type.
 *
 *  @param[in,out] instance                 The instance pointer
 *  @param[in]     instanceHandleReceiver   listener object handle which receives the created container packer instance.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IContainerPackerFactory_createContainerPacker)
(
    const void *instance,
    nuance_audio_IContainerPackerFactoryListener *instanceHandleReceiver
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
typedef void (*FUNC_nuance_audio_IContainerPackerFactory_releaseFactory)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Interface of the 'ContainerPackerFactory' component. <p>
 *
 *  The ContainerPackerFactory is used by the audio encoder module to implement the feature of
 *  using different implementations of the IContainerPacker interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioContainerPackerFactory").
 */
struct _vtable_nuance_audio_IContainerPackerFactory
{
    /**
     *  Returns the type identifier of the audio containers used to pack the data into, for instance "OGG"
     *
     *  This is the value which needs to be set at the "container_type" property of the encoder module to trigger the creation of such an container packer.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return type identifier of the containers this factory is creating.
     */
    FUNC_nuance_audio_IContainerPackerFactory_getContainerType getContainerType;

    /**
     *  Creates an container packer instance.
     *
     *  This method will be called by the audio manager to create an instance of the required container packer type.
     *
     *  @param[in,out] instance                 The instance pointer
     *  @param[in]     instanceHandleReceiver   listener object handle which receives the created container packer instance.
     *
     */
    FUNC_nuance_audio_IContainerPackerFactory_createContainerPacker createContainerPacker;

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
    FUNC_nuance_audio_IContainerPackerFactory_releaseFactory releaseFactory;

};
/**
 *  @brief  Interface of the 'ContainerPackerFactory' component. <p>
 *
 *  The ContainerPackerFactory is used by the audio encoder module to implement the feature of
 *  using different implementations of the IContainerPacker interface.
 *
 *  The factory needs to be known a the audio manager (see "registerAudioContainerPackerFactory").
 */
typedef struct _vtable_nuance_audio_IContainerPackerFactory vtable_nuance_audio_IContainerPackerFactory;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IContainerPackerFactory *nuance_audio_IContainerPackerFactory_create
(
    const vtable_nuance_audio_IContainerPackerFactory *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IContainerPackerFactory_destroy(nuance_audio_IContainerPackerFactory *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_ICONTAINERPACKERFACTORY_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
