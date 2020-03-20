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
 *  Declaration of nuance_prompter_TextFormat enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup TextFormat
 *  @{
 *  @file TextFormat.h
 * @brief Defines enumeration TextFormat
 */

#ifndef NUANCE_PROMPTER_TEXTFORMAT_H
#define NUANCE_PROMPTER_TEXTFORMAT_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration describes the format of the input text that has to be read out with the prompter.
 *  Depending on the format, the prompter component may preprocess given input text and convert it
 *  to the form most appropriate for the audio synthesis.
 */
typedef enum
{
    NUANCE_PROMPTER_FORMAT_PLAIN,  /**< @brief The plain text input format.<p> */
    /**<  */
    /**< Defines plain input text that requires no special preprocessing by the prompter. */
    NUANCE_PROMPTER_FORMAT_EMAIL,  /**< @brief The email text input format.<p> */
    /**<  */
    /**< This format is intended for CDFW applications only. */
    /**<  */
    /**< Defines input text formatted as an email content. This input text must be in the required email format. */
    NUANCE_PROMPTER_FORMAT_SSML    /**< @brief The SSML (Speech Synthesis Markup Language) text input format.<p> */
    /**<  */
    /**< Defines input text formatted as SSML content. */
} nuance_prompter_TextFormat;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_TextFormat_toString(nuance_prompter_TextFormat enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_TEXTFORMAT_H */

/** @} */
/** @} */

