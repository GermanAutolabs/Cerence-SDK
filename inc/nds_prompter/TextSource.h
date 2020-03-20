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
 *  Declaration of nuance_prompter_TextSource enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup TextSource
 *  @{
 *  @file TextSource.h
 * @brief Defines enumeration TextSource
 */

#ifndef NUANCE_PROMPTER_TEXTSOURCE_H
#define NUANCE_PROMPTER_TEXTSOURCE_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration describes the source of a text to prompt.
 */
typedef enum
{
    NUANCE_PROMPTER_TEXT_FROM_STRING,  /**< This text source type describes a text to prompt that originates from a text string. */
    NUANCE_PROMPTER_TEXT_FROM_FILE     /**< This text source type describes a text to prompt that originates from a text file. */
} nuance_prompter_TextSource;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_TextSource_toString(nuance_prompter_TextSource enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_TEXTSOURCE_H */

/** @} */
/** @} */

