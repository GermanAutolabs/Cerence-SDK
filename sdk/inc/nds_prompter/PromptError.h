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
 *  Declaration of nuance_prompter_PromptError enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup PromptError
 *  @{
 *  @file PromptError.h
 * @brief Defines enumeration PromptError
 */

#ifndef NUANCE_PROMPTER_PROMPTERROR_H
#define NUANCE_PROMPTER_PROMPTERROR_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration type describes the errors which can occur during execution of prompt methods.
 */
typedef enum
{
    NUANCE_PROMPTER_PROMPT_ARGUMENT_INVALID,    /**< Indicates that an invalid argument was passed. */
    NUANCE_PROMPTER_PROMPT_STATE_INVALID,       /**< Indicates that the prompt is in an invalid state for the requested action. */
    NUANCE_PROMPTER_PROMPT_ALLOCATION_FAILURE,  /**< Indicates that the memory allocation failed. */
    NUANCE_PROMPTER_PROMPT_FILE_NOT_FOUND,      /**< Indicates that the file to prompt could not be opened. */
    NUANCE_PROMPTER_INPUT_INVALID,              /**< Indicates that an invalid input (string/file) was passed to the prompt. */
    NUANCE_PROMPTER_EMAILPARSER_ERROR,          /**< Indicates that an error occurred while running the email preprocessor. */
    NUANCE_PROMPTER_CLOUD_CONNECTION_FAILED,    /**< Indicates that a cloud connection failed during prompting */
    NUANCE_PROMPTER_CLOUD_CONNECTION_LOST       /**< Indicates that a cloud connection lost during prompting */
} nuance_prompter_PromptError;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_PromptError_toString(nuance_prompter_PromptError enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_PROMPTERROR_H */

/** @} */
/** @} */

