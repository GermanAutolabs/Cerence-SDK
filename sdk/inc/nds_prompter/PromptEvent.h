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
 *  Declaration of nuance_prompter_PromptEvent enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup PromptEvent
 *  @{
 *  @file PromptEvent.h
 * @brief Defines enumeration PromptEvent
 */

#ifndef NUANCE_PROMPTER_PROMPTEVENT_H
#define NUANCE_PROMPTER_PROMPTEVENT_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief This enumeration type describes the events that occur when a prompt is being processed.<p>
 */
typedef enum
{
    NUANCE_PROMPTER_START_PLAY_EVENT,        /**< Indicates that a prompt has started playback at the output device. NOTE: At the point when this event occurs, the output device has played already the first audio chunk! */
    NUANCE_PROMPTER_END_PLAY_EVENT,          /**< Indicates that a prompt has ended playback at the output device. */
    NUANCE_PROMPTER_FINISH_PROMPT_EVENT,     /**< Indicates that a prompt is finished (generation and playback) and can be destroyed. */
    NUANCE_PROMPTER_START_GENERATION_EVENT,  /**< Indicates that the prompter starts to synthesize a prompt text. */
    NUANCE_PROMPTER_END_GENERATION_EVENT,    /**< Indicates that the prompter ends to synthesize a prompt text. */
    NUANCE_PROMPTER_ABORTED_PROMPT_EVENT     /**< Indicates that a prompt has been aborted during the execution. */
} nuance_prompter_PromptEvent;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_PromptEvent_toString(nuance_prompter_PromptEvent enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_PROMPTEVENT_H */

/** @} */
/** @} */

