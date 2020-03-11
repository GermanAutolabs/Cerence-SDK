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
 *  Declaration of nuance_audio_IEncoder class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IEncoder
 *  @{
 *  @file IEncoder.h
 *
 *  @brief  Interface of an audio encoder. <p>
 */

#ifndef NUANCE_AUDIO_IENCODER_H
#define NUANCE_AUDIO_IENCODER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of an audio encoder. <p>
 */
struct _nuance_audio_IEncoder;
/**
 *  @brief  Interface of an audio encoder. <p>
 */
typedef struct _nuance_audio_IEncoder nuance_audio_IEncoder;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "AudioContainer.h"
#include "AudioData.h"
#include "AudioData_8Bit.h"
#include "AudioEncoding.h"
#include "ByteArray.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  Returns the version descriptor of the used Encoder.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return version descriptor.
 */
typedef nuance_common_String *(*FUNC_nuance_audio_IEncoder_getVersion)(void *instance);

/**
 *  Returns the descriptor for the encoding this encoder applies to the PCM data.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Encoding enumeration value.
 */
typedef nuance_audio_AudioEncoding (*FUNC_nuance_audio_IEncoder_getEncoding)(void *instance);

/**
 *  Checks whether the handed sample rate and channel count is supported by the encoder or not
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     sampleRate     sample rate in hertz.
 *  @param[in]     channelCount   number of channels.
 *
 *  @return true if the format can be handled, false otherwise
 */
typedef LH_BOOL (*FUNC_nuance_audio_IEncoder_isFormatSupported)
(
    void *instance,
    LH_S32 sampleRate,
    LH_S32 channelCount
);

/**
 *  Configures this encoder instance.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     sampleRate     Sample rate in hertz.
 *  @param[in]     channelCount   Number of channels.
 *  @param[in]     container      Container enumeration value.
 *  @param[in]     encoderParam   Encoder specific Json parameter string.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IEncoder_configure)
(
    void *instance,
    LH_S32 sampleRate,
    LH_S32 channelCount,
    nuance_audio_AudioContainer container,
    const LH_CHAR *encoderParam
);

/**
 *  Returns the input granularity of the encoder in samples per channel.
 *  To ensure a correct value it is recommended to configure the instance before getting its granularity.
 *
 *  A returned 0 indicates that the encoder has no granularity at all.
 *
 *  A returned -1 indicates an error.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return granularity.
 */
typedef LH_S32 (*FUNC_nuance_audio_IEncoder_getInputGranularity)(void *instance);

/**
 *  Returns a container specific header information.
 *
 *  In case the encoded audio data shall be packed into a specific container it may be necessary to pack
 *  container specific header information (media mapping) prior to the encoded audio data to the container. To retrieve
 *  this specific header information this method has to be called at the encoder. As it may be the case that
 *  more than one header is required, this method has to be called in sequence until an empty header information
 *  is returned. In case a specific container does not require a specific header information or is not known
 *  by the encoder, an empty header information shall be returned.
 *
 *  The container has to be set with a call to the encoder's configure() method. This method is allowed to
 *  be called only before the first call to the encode() method.
 *
 *  The calling component takes care to clear the provided output buffer,
 *  before calling this method if that is needed. Encoded data shall be appended only.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    header   Container specific header information.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IEncoder_getContainerHeader)
(
    void *instance,
    nuance_common_ByteArray **header
);

/**
 *  Encodes the provided audio data of the input buffer to the output buffer.
 *
 *  The size of the input buffer must not exceed the maximum size supported by this encoder
 *  instance. This maximum size in samples can be calculated by the multiplication of the
 *  result values of getChannelCount() and getSamplesPerChannel(). The audio data of the
 *  input buffer must be in the following format:
 *
 *  - interleaved 16-bit raw PCM
 *  - sample rate = getSampleRate()
 *  - channel count = getChannelCount()
 *  - maximum samples per channel = getSamplesPerChannel()
 *
 *  The calling component takes care to clear the provided output buffer,
 *  before calling this method if that is needed. Encoded data shall be appended only.
 *
 *  The audio input data passed to this method is fully encoded to the provided output buffer.
 *  The output buffer is resized implicitly if needed.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     inputBuffer    Input buffer containing audio data to be encoded.
 *  @param[in]     ninputBuffer   Number of elements in inputBuffer
 *  @param[out]    outputBuffer   Output buffer the encoded audio data will be written to.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IEncoder_encode)
(
    void *instance,
    LH_S16  const *inputBuffer, LH_S32 ninputBuffer,
    nuance_audio_AudioData_8Bit **outputBuffer
);

/**
 *  Resets this encoder instance to initial state.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IEncoder_reset)(void *instance);

/**
 *  Release this instance of the encoder.
 *  No further calls to the interface of this encoder will be done after that call.
 *  The audio module has removed that encoder handle from its internal registry.
 *
 *  The implementation of that handle can be destroyed.
 *
 *  Since the audio module calls this releaseEncoder method in the context of its destructor,
 *  the deletion of the instance is probably the best solution in the majority of the use cases.
 *
 *  @param[in,out] instance The instance pointer
 */
typedef void (*FUNC_nuance_audio_IEncoder_destroyEncoder)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Interface of an audio encoder. <p>
 */
struct _vtable_nuance_audio_IEncoder
{
    /**
     *  Returns the version descriptor of the used Encoder.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return version descriptor.
     */
    FUNC_nuance_audio_IEncoder_getVersion getVersion;

    /**
     *  Returns the descriptor for the encoding this encoder applies to the PCM data.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return Encoding enumeration value.
     */
    FUNC_nuance_audio_IEncoder_getEncoding getEncoding;

    /**
     *  Checks whether the handed sample rate and channel count is supported by the encoder or not
     *
     *  @param[in,out] instance       The instance pointer
     *  @param[in]     sampleRate     sample rate in hertz.
     *  @param[in]     channelCount   number of channels.
     *
     *  @return true if the format can be handled, false otherwise
     */
    FUNC_nuance_audio_IEncoder_isFormatSupported isFormatSupported;

    /**
     *  Configures this encoder instance.
     *
     *  @param[in,out] instance       The instance pointer
     *  @param[in]     sampleRate     Sample rate in hertz.
     *  @param[in]     channelCount   Number of channels.
     *  @param[in]     container      Container enumeration value.
     *  @param[in]     encoderParam   Encoder specific Json parameter string.
     *
     */
    FUNC_nuance_audio_IEncoder_configure configure;

    /**
     *  Returns the input granularity of the encoder in samples per channel.
     *  To ensure a correct value it is recommended to configure the instance before getting its granularity.
     *
     *  A returned 0 indicates that the encoder has no granularity at all.
     *
     *  A returned -1 indicates an error.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return granularity.
     */
    FUNC_nuance_audio_IEncoder_getInputGranularity getInputGranularity;

    /**
     *  Returns a container specific header information.
     *
     *  In case the encoded audio data shall be packed into a specific container it may be necessary to pack
     *  container specific header information (media mapping) prior to the encoded audio data to the container. To retrieve
     *  this specific header information this method has to be called at the encoder. As it may be the case that
     *  more than one header is required, this method has to be called in sequence until an empty header information
     *  is returned. In case a specific container does not require a specific header information or is not known
     *  by the encoder, an empty header information shall be returned.
     *
     *  The container has to be set with a call to the encoder's configure() method. This method is allowed to
     *  be called only before the first call to the encode() method.
     *
     *  The calling component takes care to clear the provided output buffer,
     *  before calling this method if that is needed. Encoded data shall be appended only.
     *
     *  @param[in,out] instance The instance pointer
     *  @param[out]    header   Container specific header information.
     *
     */
    FUNC_nuance_audio_IEncoder_getContainerHeader getContainerHeader;

    /**
     *  Encodes the provided audio data of the input buffer to the output buffer.
     *
     *  The size of the input buffer must not exceed the maximum size supported by this encoder
     *  instance. This maximum size in samples can be calculated by the multiplication of the
     *  result values of getChannelCount() and getSamplesPerChannel(). The audio data of the
     *  input buffer must be in the following format:
     *
     *  - interleaved 16-bit raw PCM
     *  - sample rate = getSampleRate()
     *  - channel count = getChannelCount()
     *  - maximum samples per channel = getSamplesPerChannel()
     *
     *  The calling component takes care to clear the provided output buffer,
     *  before calling this method if that is needed. Encoded data shall be appended only.
     *
     *  The audio input data passed to this method is fully encoded to the provided output buffer.
     *  The output buffer is resized implicitly if needed.
     *
     *  @param[in,out] instance       The instance pointer
     *  @param[in]     inputBuffer    Input buffer containing audio data to be encoded.
     *  @param[in]     ninputBuffer   Number of elements in inputBuffer
     *  @param[out]    outputBuffer   Output buffer the encoded audio data will be written to.
     *
     */
    FUNC_nuance_audio_IEncoder_encode encode;

    /**
     *  Resets this encoder instance to initial state.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IEncoder_reset reset;

    /**
     *  Release this instance of the encoder.
     *  No further calls to the interface of this encoder will be done after that call.
     *  The audio module has removed that encoder handle from its internal registry.
     *
     *  The implementation of that handle can be destroyed.
     *
     *  Since the audio module calls this releaseEncoder method in the context of its destructor,
     *  the deletion of the instance is probably the best solution in the majority of the use cases.
     *
     *  @param[in,out] instance The instance pointer
     */
    FUNC_nuance_audio_IEncoder_destroyEncoder destroyEncoder;

};
/**
 *  @brief  Interface of an audio encoder. <p>
 */
typedef struct _vtable_nuance_audio_IEncoder vtable_nuance_audio_IEncoder;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IEncoder *nuance_audio_IEncoder_create
(
    const vtable_nuance_audio_IEncoder *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IEncoder_destroy(nuance_audio_IEncoder *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IENCODER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
