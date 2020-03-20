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
 *  Declaration of nuance_prompter_PromptState enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup PromptState
 *  @{
 *  @file PromptState.h
 * @brief Defines enumeration PromptState
 */

#ifndef NUANCE_PROMPTER_PROMPTSTATE_H
#define NUANCE_PROMPTER_PROMPTSTATE_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration describes the state of a prompt.
 */
typedef enum
{
    NUANCE_PROMPTER_PROMPT_RUNNING,    /**< Indicates that the prompt is running, i.e. the prompt is pending in the background or is being executed. */
    NUANCE_PROMPTER_PROMPT_COMPLETED,  /**< Indicates that the prompt is completed successfully. */
    NUANCE_PROMPTER_PROMPT_FAILED,     /**< Indicates that the prompt completed with a failure. */
    NUANCE_PROMPTER_PROMPT_ABORTED     /**< Indicates that the prompt is aborted. */
} nuance_prompter_PromptState;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_PromptState_toString(nuance_prompter_PromptState enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_PROMPTSTATE_H */

/** @} */
/** @} */

