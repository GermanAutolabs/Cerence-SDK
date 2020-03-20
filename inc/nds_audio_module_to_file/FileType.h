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
 *  Declaration of nuance_audio_FileType enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio nuance_audio
 * @{
 *  @addtogroup FileType
 *  @{
 *  @file FileType.h
 * @brief Defines enumeration FileType
 */

#ifndef NUANCE_AUDIO_FILETYPE_H
#define NUANCE_AUDIO_FILETYPE_H

#include "lh_types.h"
#include "audio_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  Define the content type of the audio file. <p>
 *
 *  This enumeration lists supported content types of the audio file.
 */
typedef enum
{
    NUANCE_AUDIO_FT_RAW,  /**< Raw audio data (either signed 16Bit PCM or encoded) */
    NUANCE_AUDIO_FT_WAV   /**< Signed 16Bit pcm raw data with WAV header */
} nuance_audio_FileType;

AUDIO_C_EXPORT const LH_CHAR *nuance_audio_FileType_toString(nuance_audio_FileType enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_FILETYPE_H */

/** @} */
/** @} */

