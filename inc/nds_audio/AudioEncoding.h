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
 *  Declaration of nuance_audio_AudioEncoding enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio nuance_audio
 * @{
 *  @addtogroup AudioEncoding
 *  @{
 *  @file AudioEncoding.h
 * @brief Defines enumeration AudioEncoding
 */

#ifndef NUANCE_AUDIO_AUDIOENCODING_H
#define NUANCE_AUDIO_AUDIOENCODING_H

#include "lh_types.h"
#include "audio_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  Define the audio encoding type we have to deal with. <p>
 *
 *  This enumeration represents the type of the supported encodings for the audio data.
 */
typedef enum
{
    NUANCE_AUDIO_ENCODING_UNDEFINED,  /**< undefined encoding, please set valid format */
    NUANCE_AUDIO_ENCODING_USER,       /**< user specific encoding type */
    NUANCE_AUDIO_ENCODING_PCM_16BIT,  /**< Signed 16Bit PCM raw data */
    NUANCE_AUDIO_ENCODING_OPUS,       /**< OPUS encoding */
    NUANCE_AUDIO_ENCODING_MP3         /**< MP3 encoding */
} nuance_audio_AudioEncoding;

AUDIO_C_EXPORT const LH_CHAR *nuance_audio_AudioEncoding_toString(nuance_audio_AudioEncoding enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_AUDIOENCODING_H */

/** @} */
/** @} */

