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
 *  Declaration of nuance_audio_StopMode enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio nuance_audio
 * @{
 *  @addtogroup StopMode
 *  @{
 *  @file StopMode.h
 * @brief Defines enumeration StopMode
 */

#ifndef NUANCE_AUDIO_STOPMODE_H
#define NUANCE_AUDIO_STOPMODE_H

#include "lh_types.h"
#include "audio_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  Define the mode when to stop. <p>
 *
 *  This enumeration represents the mode when a stop() call should return.
 */
typedef enum
{
    NUANCE_AUDIO_SM_NOW,              /**< stop immediately */
    NUANCE_AUDIO_SM_STREAM_FINISHED   /**< stop after the current stream is finished */
} nuance_audio_StopMode;

AUDIO_C_EXPORT const LH_CHAR *nuance_audio_StopMode_toString(nuance_audio_StopMode enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_STOPMODE_H */

/** @} */
/** @} */

