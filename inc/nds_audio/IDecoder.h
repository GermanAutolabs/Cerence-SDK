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
 *  Declaration of nuance_audio_IDecoder class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IDecoder
 *  @{
 *  @file IDecoder.h
 *
 *  @brief  Interface of an audio decoder. <p>
 */

#ifndef NUANCE_AUDIO_IDECODER_H
#define NUANCE_AUDIO_IDECODER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of an audio decoder. <p>
 */
struct _nuance_audio_IDecoder;
/**
 *  @brief  Interface of an audio decoder. <p>
 */
typedef struct _nuance_audio_IDecoder nuance_audio_IDecoder;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "AudioContainer.h"
#include "AudioData.h"
#include "AudioData_8Bit.h"
#include "AudioEncoding.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  Returns the version descriptor of the used Decoder.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return version descriptor.
 */
typedef nuance_common_String *(*FUNC_nuance_audio_IDecoder_getVersion)(void *instance);

/**
 *  Returns the descriptor for the encoding this decoder can transform into PCM data.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Encoding enumeration value.
 */
typedef nuance_audio_AudioEncoding (*FUNC_nuance_audio_IDecoder_getEncoding)(void *instance);

/**
 *  check whether the handed sample rate and channel count is supported by the decoder or not
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     sampleRate     sample rate in hertz.
 *  @param[in]     channelCount   number of channels.
 *
 *  @return true if the format can be handled, false otherwise
 */
typedef LH_BOOL (*FUNC_nuance_audio_IDecoder_isFormatSupported)
(
    void *instance,
    LH_S32 sampleRate,
    LH_S32 channelCount
);

/**
 *  Configures this decoder instance.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     sampleRate     Sample rate in hertz.
 *  @param[in]     channelCount   Number of channels.
 *  @param[in]     container      Container enumeration value.
 *  @param[in]     decoderParam   Decoder specific Json parameter string.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IDecoder_configure)
(
    void *instance,
    LH_S32 sampleRate,
    LH_S32 channelCount,
    nuance_audio_AudioContainer container,
    const LH_CHAR *decoderParam
);

/**
 *  Decodes audio data.
 *
 *  It is assumed that the audio data of the handed over input buffer was encoded by a corresponding
 *  encoder with a sample rate and a channel count that corresponds to the configuration of this
 *  decoder instance.
 *
 *  In case the encoded audio data was packed into a specific container the first call(s) to
 *  this method may hand over container specific header information prior to the encoded
 *  audio data. By usage of the specific container that was set with a call to the decoder's
 *  configure() method the decoder has to interpret whether the incoming data is header information (from media mapping)
 *  or encoded audio data. In case an unknown or none container is configured all incoming
 *  data has to be interpreted as encoded audio data. Handed over header information may be used
 *  to verify a correct configuration of the decoder (e.g. sample rate, channel count,..). In case
 *  header information was handed over to this method, an unchanged output buffer and a result
 *  reflecting a potentially performed header information verification is returned.
 *
 *  The calling component takes care to clear the provided output buffer,
 *  before calling this method if that is needed. Decoded data shall be appended only.
 *
 *  Encoded audio data is fully decoded to the provided output buffer
 *  The output buffer is resized implicitly if needed.
 *  The audio data of the output buffer is in the following format:
 *
 *  - interleaved 16-bit raw PCM
 *  - sample rate = getSampleRate()
 *  - channel count = getChannelCount()
 *
 *  In case the encoded audio data is not sufficient to complete a decoding operation, this method
 *  returns OK but an output buffer with empty size.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     inputBuffer    Input buffer containing either header information or encoded audio data to be decoded.
 *  @param[in]     ninputBuffer   Number of elements in inputBuffer
 *  @param[in]     finalData      marker that this is the final data buffer.
 *  @param[out]    outputBuffer   Output buffer the decoded audio data will be written to.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IDecoder_decode)
(
    void *instance,
    LH_S8  const *inputBuffer, LH_S32 ninputBuffer,
    LH_BOOL finalData,
    nuance_audio_AudioData **outputBuffer
);

/**
 *  Resets this decoder instance to initial state.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IDecoder_reset)(void *instance);

/**
 *  Release this instance of the decoder.
 *  No further calls to the interface of this decoder will be done after that call.
 *  The audio module has removed that decoder handle from its internal registry.
 *
 *  The implementation of that handle can be destroyed.
 *
 *  Since the audio module calls this releaseDecoder method in the context of its destructor,
 *  the deletion of the instance is probably the best solution in the majority of the use cases.
 *
 *  @param[in,out] instance The instance pointer
 */
typedef void (*FUNC_nuance_audio_IDecoder_destroyDecoder)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Interface of an audio decoder. <p>
 */
struct _vtable_nuance_audio_IDecoder
{
    /**
     *  Returns the version descriptor of the used Decoder.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return version descriptor.
     */
    FUNC_nuance_audio_IDecoder_getVersion getVersion;

    /**
     *  Returns the descriptor for the encoding this decoder can transform into PCM data.
     *
     *  @param[in,out] instance The instance pointer
     *
     *  @return Encoding enumeration value.
     */
    FUNC_nuance_audio_IDecoder_getEncoding getEncoding;

    /**
     *  check whether the handed sample rate and channel count is supported by the decoder or not
     *
     *  @param[in,out] instance       The instance pointer
     *  @param[in]     sampleRate     sample rate in hertz.
     *  @param[in]     channelCount   number of channels.
     *
     *  @return true if the format can be handled, false otherwise
     */
    FUNC_nuance_audio_IDecoder_isFormatSupported isFormatSupported;

    /**
     *  Configures this decoder instance.
     *
     *  @param[in,out] instance       The instance pointer
     *  @param[in]     sampleRate     Sample rate in hertz.
     *  @param[in]     channelCount   Number of channels.
     *  @param[in]     container      Container enumeration value.
     *  @param[in]     decoderParam   Decoder specific Json parameter string.
     *
     */
    FUNC_nuance_audio_IDecoder_configure configure;

    /**
     *  Decodes audio data.
     *
     *  It is assumed that the audio data of the handed over input buffer was encoded by a corresponding
     *  encoder with a sample rate and a channel count that corresponds to the configuration of this
     *  decoder instance.
     *
     *  In case the encoded audio data was packed into a specific container the first call(s) to
     *  this method may hand over container specific header information prior to the encoded
     *  audio data. By usage of the specific container that was set with a call to the decoder's
     *  configure() method the decoder has to interpret whether the incoming data is header information (from media mapping)
     *  or encoded audio data. In case an unknown or none container is configured all incoming
     *  data has to be interpreted as encoded audio data. Handed over header information may be used
     *  to verify a correct configuration of the decoder (e.g. sample rate, channel count,..). In case
     *  header information was handed over to this method, an unchanged output buffer and a result
     *  reflecting a potentially performed header information verification is returned.
     *
     *  The calling component takes care to clear the provided output buffer,
     *  before calling this method if that is needed. Decoded data shall be appended only.
     *
     *  Encoded audio data is fully decoded to the provided output buffer
     *  The output buffer is resized implicitly if needed.
     *  The audio data of the output buffer is in the following format:
     *
     *  - interleaved 16-bit raw PCM
     *  - sample rate = getSampleRate()
     *  - channel count = getChannelCount()
     *
     *  In case the encoded audio data is not sufficient to complete a decoding operation, this method
     *  returns OK but an output buffer with empty size.
     *
     *  @param[in,out] instance       The instance pointer
     *  @param[in]     inputBuffer    Input buffer containing either header information or encoded audio data to be decoded.
     *  @param[in]     ninputBuffer   Number of elements in inputBuffer
     *  @param[in]     finalData      marker that this is the final data buffer.
     *  @param[out]    outputBuffer   Output buffer the decoded audio data will be written to.
     *
     */
    FUNC_nuance_audio_IDecoder_decode decode;

    /**
     *  Resets this decoder instance to initial state.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IDecoder_reset reset;

    /**
     *  Release this instance of the decoder.
     *  No further calls to the interface of this decoder will be done after that call.
     *  The audio module has removed that decoder handle from its internal registry.
     *
     *  The implementation of that handle can be destroyed.
     *
     *  Since the audio module calls this releaseDecoder method in the context of its destructor,
     *  the deletion of the instance is probably the best solution in the majority of the use cases.
     *
     *  @param[in,out] instance The instance pointer
     */
    FUNC_nuance_audio_IDecoder_destroyDecoder destroyDecoder;

};
/**
 *  @brief  Interface of an audio decoder. <p>
 */
typedef struct _vtable_nuance_audio_IDecoder vtable_nuance_audio_IDecoder;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IDecoder *nuance_audio_IDecoder_create
(
    const vtable_nuance_audio_IDecoder *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IDecoder_destroy(nuance_audio_IDecoder *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IDECODER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
