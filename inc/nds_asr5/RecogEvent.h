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
 *  Declaration of nuance_asr5_RecogEvent enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5 nuance_asr5
 * @{
 *  @addtogroup RecogEvent
 *  @{
 *  @file RecogEvent.h
 * @brief Defines enumeration RecogEvent
 */

#ifndef NUANCE_ASR5_RECOGEVENT_H
#define NUANCE_ASR5_RECOGEVENT_H

#include "lh_types.h"
#include "asr5_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  This enumeration type describes the events which can occur during a recognizer run. <p>
 */
typedef enum
{
    NUANCE_ASR5_RECOGNIZER_AUDIOSTREAM_RECEIVED,        /**< recognizer received the audio stream */
    NUANCE_ASR5_RECOGNIZER_SPEECH_DETECTED,             /**< recognizer detected speech */
    NUANCE_ASR5_RECOGNIZER_SILENCE_DETECTED,            /**< recognizer detected silence */
    NUANCE_ASR5_RECOGNIZER_AUDIO_STOPPED,               /**< recognizer detected audio stopped */
    NUANCE_ASR5_RECOGNIZER_AUDIO_FINISHED,              /**< recognizer detected audio finished */
    NUANCE_ASR5_RECOGNIZER_ABNORMCOND_BADSNR,           /**< The signal to noise ratio is too low. */
    NUANCE_ASR5_RECOGNIZER_ABNORMCOND_OVERLOAD,         /**< The speech level is too loud. */
    NUANCE_ASR5_RECOGNIZER_ABNORMCOND_TOOQUIET,         /**< The speech level is too weak. */
    NUANCE_ASR5_RECOGNIZER_ABNORMCOND_NOSIGNAL,         /**< No or very low input signal. */
    NUANCE_ASR5_RECOGNIZER_EXTERNAL_PROVIDER_STARTED,   /**< external provider started to work. */
    NUANCE_ASR5_RECOGNIZER_EXTERNAL_PROVIDER_FINISHED   /**< external provider finished processing audio. */
} nuance_asr5_RecogEvent;

ASR5_C_EXPORT const LH_CHAR *nuance_asr5_RecogEvent_toString(nuance_asr5_RecogEvent enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_RECOGEVENT_H */

/** @} */
/** @} */

