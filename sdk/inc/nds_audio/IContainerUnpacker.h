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
 *  Declaration of nuance_audio_IContainerUnpacker class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IContainerUnpacker
 *  @{
 *  @file IContainerUnpacker.h
 *
 *  @brief  Interface of an audio container. <p>
 */

#ifndef NUANCE_AUDIO_ICONTAINERUNPACKER_H
#define NUANCE_AUDIO_ICONTAINERUNPACKER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of an audio container. <p>
 */
struct _nuance_audio_IContainerUnpacker;
/**
 *  @brief  Interface of an audio container. <p>
 */
typedef struct _nuance_audio_IContainerUnpacker nuance_audio_IContainerUnpacker;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "AudioContainer.h"
#include "ByteArray.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  Returns the version descriptor of the used Container.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return version descriptor.
 */
typedef nuance_common_String *(*FUNC_nuance_audio_IContainerUnpacker_getVersion)(void *instance);

/**
 *  Returns the descriptor of the container this instance will unpack data from.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Container enumeration value.
 */
typedef nuance_audio_AudioContainer (*FUNC_nuance_audio_IContainerUnpacker_getContainer)(void *instance);

/**
 *  configure the container instance.
 *
 *  @param[in,out] instance         The instance pointer
 *  @param[in]     containerParam   container specific param string.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IContainerUnpacker_configure)
(
    void *instance,
    const LH_CHAR *containerParam
);

/**
 *  Resets this container instance to initial state.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IContainerUnpacker_reset)(void *instance);

/**
 *  Hands in packed data for unpacking.
 *
 *  This method adds the handed data to unpack it.
 *
 *  It is not guaranteed that now output data is ready.
 *  This may be the case but it can also be that more data has to be added before the
 *  container can emit unpacked data.
 *
 *  Nevertheless it is recommended to call the "getData" method until no more data is emitted.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     packet      Input buffer containing audio data to be unpacket by the container.
 *  @param[in]     npacket     Number of elements in packet
 *  @param[in]     finalData   marker that this is the final data buffer.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IContainerUnpacker_setPacket)
(
    void *instance,
    LH_S8  const *packet, LH_S32 npacket,
    LH_BOOL finalData
);

/**
 *  checks if the container can return data and retrieves it if so.
 *
 *  This method checks if the container is able to emit data.
 *  If that is the case the data is retrieved and returned.
 *
 *  The calling component takes care to clear the provided output data buffer,
 *  before calling this method if that is needed.
 *
 *  It is possible that the container can emit more than one piece of unpacked data.
 *  It is therefore recommended to call this method until no more data is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    data   Output buffer the unpacked audio data will be returned in.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IContainerUnpacker_getData)
(
    void *instance,
    nuance_common_ByteArray **data
);

/**
 *  Release this instance of the container.
 *  No further calls to the interface of this container will be done after that call.
 *  The audio module has removed that container handle from its internal registry.
 *
 *  The implementation of that handle can be destroyed.
 *
 *  Since the audio module calls this releaseContainer method in the context of its destructor,
 *  the deletion of the instance is probably the best solution in the majority of the use cases.
 *
 *  @param[in,out] instance The instance pointer
 */
typedef void (*FUNC_nuance_audio_IContainerUnpacker_destroyContainer)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Interface of an audio container. <p>
 */
struct _vtable_nuance_audio_IContainerUnpacker
{
    /**
     *  Returns the version descriptor of the used Container.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return version descriptor.
     */
    FUNC_nuance_audio_IContainerUnpacker_getVersion getVersion;

    /**
     *  Returns the descriptor of the container this instance will unpack data from.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return Container enumeration value.
     */
    FUNC_nuance_audio_IContainerUnpacker_getContainer getContainer;

    /**
     *  configure the container instance.
     *
     *  @param[in,out] instance         The instance pointer
     *  @param[in]     containerParam   container specific param string.
     *
     */
    FUNC_nuance_audio_IContainerUnpacker_configure configure;

    /**
     *  Resets this container instance to initial state.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IContainerUnpacker_reset reset;

    /**
     *  Hands in packed data for unpacking.
     *
     *  This method adds the handed data to unpack it.
     *
     *  It is not guaranteed that now output data is ready.
     *  This may be the case but it can also be that more data has to be added before the
     *  container can emit unpacked data.
     *
     *  Nevertheless it is recommended to call the "getData" method until no more data is emitted.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     packet      Input buffer containing audio data to be unpacket by the container.
     *  @param[in]     npacket     Number of elements in packet
     *  @param[in]     finalData   marker that this is the final data buffer.
     *
     */
    FUNC_nuance_audio_IContainerUnpacker_setPacket setPacket;

    /**
     *  checks if the container can return data and retrieves it if so.
     *
     *  This method checks if the container is able to emit data.
     *  If that is the case the data is retrieved and returned.
     *
     *  The calling component takes care to clear the provided output data buffer,
     *  before calling this method if that is needed.
     *
     *  It is possible that the container can emit more than one piece of unpacked data.
     *  It is therefore recommended to call this method until no more data is returned.
     *
     *  @param[in,out] instance The instance pointer
     *  @param[out]    data   Output buffer the unpacked audio data will be returned in.
     *
     */
    FUNC_nuance_audio_IContainerUnpacker_getData getData;

    /**
     *  Release this instance of the container.
     *  No further calls to the interface of this container will be done after that call.
     *  The audio module has removed that container handle from its internal registry.
     *
     *  The implementation of that handle can be destroyed.
     *
     *  Since the audio module calls this releaseContainer method in the context of its destructor,
     *  the deletion of the instance is probably the best solution in the majority of the use cases.
     *
     *  @param[in,out] instance The instance pointer
     */
    FUNC_nuance_audio_IContainerUnpacker_destroyContainer destroyContainer;

};
/**
 *  @brief  Interface of an audio container. <p>
 */
typedef struct _vtable_nuance_audio_IContainerUnpacker vtable_nuance_audio_IContainerUnpacker;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IContainerUnpacker *nuance_audio_IContainerUnpacker_create
(
    const vtable_nuance_audio_IContainerUnpacker *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IContainerUnpacker_destroy(nuance_audio_IContainerUnpacker *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_ICONTAINERUNPACKER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
