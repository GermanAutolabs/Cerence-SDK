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
 *  Declaration of nuance_audio_IContainerPacker class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IContainerPacker
 *  @{
 *  @file IContainerPacker.h
 *
 *  @brief  Interface of an audio container. <p>
 */

#ifndef NUANCE_AUDIO_ICONTAINERPACKER_H
#define NUANCE_AUDIO_ICONTAINERPACKER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of an audio container. <p>
 */
struct _nuance_audio_IContainerPacker;
/**
 *  @brief  Interface of an audio container. <p>
 */
typedef struct _nuance_audio_IContainerPacker nuance_audio_IContainerPacker;


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
typedef nuance_common_String *(*FUNC_nuance_audio_IContainerPacker_getVersion)(void *instance);

/**
 *  Returns the descriptor of the container this instance will pack data into.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Container enumeration value.
 */
typedef nuance_audio_AudioContainer (*FUNC_nuance_audio_IContainerPacker_getContainer)(void *instance);

/**
 *  configure the container instance.
 *
 *  @param[in,out] instance          The instance pointer
 *  @param[in]     codecSampleRate   native sample rate the codec is running with.
 *  @param[in]     containerParam    container specific param string.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IContainerPacker_configure)
(
    void *instance,
    LH_S32 codecSampleRate,
    const LH_CHAR *containerParam
);

/**
 *  Resets this container instance to initial state.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IContainerPacker_reset)(void *instance);

/**
 *  Adds the handed header data to the packed data stream.
 *
 *  This method adds the handed header data to the container.
 *
 *  It is not guaranteed that now output data is ready.
 *  This may be the case but it can also be that more data has to be added before the
 *  container can emit packed data.
 *
 *  Nevertheless it is recommended to call the "getPacket" method until no more data is emitted.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     header   byte array containing header data to be packet into the container.
 *  @param[in]     nheader  Number of elements in header
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IContainerPacker_setHeader)
(
    void *instance,
    LH_S8  const *header, LH_S32 nheader
);

/**
 *  Adds the handed data to the packed data stream.
 *
 *  This method adds the handed data to the container.
 *
 *  It is not guaranteed that now output data is ready.
 *  This may be the case but it can also be that more data has to be added before the
 *  container can emit packed data.
 *
 *  Nevertheless it is recommended to call the "getPacket" method until no more data is emitted.
 *
 *  @param[in,out] instance               The instance pointer
 *  @param[in]     data                   byte array containing audio data to be packet into the container.
 *  @param[in]     ndata                  Number of elements in data
 *  @param[in]     pcmSamplesPerChannel   amount of samples_per_channel which were used to create the data handed in.
 *  @param[in]     finalData              marker that this is the final data buffer.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IContainerPacker_setData)
(
    void *instance,
    LH_S8  const *data, LH_S32 ndata,
    LH_S32 pcmSamplesPerChannel,
    LH_BOOL finalData
);

/**
 *  checks if the container can return data and retrieves it if so.
 *
 *  This method checks if the container is able to emit data.
 *  If that is the case the data is retrieved and returned.
 *
 *  This method also returns the amount of samples per channel which is packet into the
 *  returned packet.
 *
 *  The returned value is referring to the codecSampleRate set via the configure method,
 *  accumulating the pcmSamplesPerChannel handed in via the setData method.
 *
 *  The calling component takes care to clear the provided output buffer,
 *  before calling this method if that is needed as well as to initialize
 *  the pcmSamplesPerChannel parameter.
 *
 *  It is possible that the container can emit more than one piece of packed data.
 *  It is therefore recommended to call this method until no more data is returned.
 *
 *  @param[in,out] instance               The instance pointer
 *  @param[out]    packet                 Output buffer the packed audio data will be returned in.
 *  @param[out]    pcmSamplesPerChannel   The amount of samples per channel packed into this packet.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IContainerPacker_getPacket)
(
    void *instance,
    nuance_common_ByteArray **packet,
    LH_S32 *pcmSamplesPerChannel
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
typedef void (*FUNC_nuance_audio_IContainerPacker_destroyContainer)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Interface of an audio container. <p>
 */
struct _vtable_nuance_audio_IContainerPacker
{
    /**
     *  Returns the version descriptor of the used Container.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return version descriptor.
     */
    FUNC_nuance_audio_IContainerPacker_getVersion getVersion;

    /**
     *  Returns the descriptor of the container this instance will pack data into.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return Container enumeration value.
     */
    FUNC_nuance_audio_IContainerPacker_getContainer getContainer;

    /**
     *  configure the container instance.
     *
     *  @param[in,out] instance          The instance pointer
     *  @param[in]     codecSampleRate   native sample rate the codec is running with.
     *  @param[in]     containerParam    container specific param string.
     *
     */
    FUNC_nuance_audio_IContainerPacker_configure configure;

    /**
     *  Resets this container instance to initial state.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IContainerPacker_reset reset;

    /**
     *  Adds the handed header data to the packed data stream.
     *
     *  This method adds the handed header data to the container.
     *
     *  It is not guaranteed that now output data is ready.
     *  This may be the case but it can also be that more data has to be added before the
     *  container can emit packed data.
     *
     *  Nevertheless it is recommended to call the "getPacket" method until no more data is emitted.
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     header   byte array containing header data to be packet into the container.
     *  @param[in]     nheader  Number of elements in header
     *
     */
    FUNC_nuance_audio_IContainerPacker_setHeader setHeader;

    /**
     *  Adds the handed data to the packed data stream.
     *
     *  This method adds the handed data to the container.
     *
     *  It is not guaranteed that now output data is ready.
     *  This may be the case but it can also be that more data has to be added before the
     *  container can emit packed data.
     *
     *  Nevertheless it is recommended to call the "getPacket" method until no more data is emitted.
     *
     *  @param[in,out] instance               The instance pointer
     *  @param[in]     data                   byte array containing audio data to be packet into the container.
     *  @param[in]     ndata                  Number of elements in data
     *  @param[in]     pcmSamplesPerChannel   amount of samples_per_channel which were used to create the data handed in.
     *  @param[in]     finalData              marker that this is the final data buffer.
     *
     */
    FUNC_nuance_audio_IContainerPacker_setData setData;

    /**
     *  checks if the container can return data and retrieves it if so.
     *
     *  This method checks if the container is able to emit data.
     *  If that is the case the data is retrieved and returned.
     *
     *  This method also returns the amount of samples per channel which is packet into the
     *  returned packet.
     *
     *  The returned value is referring to the codecSampleRate set via the configure method,
     *  accumulating the pcmSamplesPerChannel handed in via the setData method.
     *
     *  The calling component takes care to clear the provided output buffer,
     *  before calling this method if that is needed as well as to initialize
     *  the pcmSamplesPerChannel parameter.
     *
     *  It is possible that the container can emit more than one piece of packed data.
     *  It is therefore recommended to call this method until no more data is returned.
     *
     *  @param[in,out] instance               The instance pointer
     *  @param[out]    packet                 Output buffer the packed audio data will be returned in.
     *  @param[out]    pcmSamplesPerChannel   The amount of samples per channel packed into this packet.
     *
     */
    FUNC_nuance_audio_IContainerPacker_getPacket getPacket;

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
    FUNC_nuance_audio_IContainerPacker_destroyContainer destroyContainer;

};
/**
 *  @brief  Interface of an audio container. <p>
 */
typedef struct _vtable_nuance_audio_IContainerPacker vtable_nuance_audio_IContainerPacker;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IContainerPacker *nuance_audio_IContainerPacker_create
(
    const vtable_nuance_audio_IContainerPacker *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IContainerPacker_destroy(nuance_audio_IContainerPacker *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_ICONTAINERPACKER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
