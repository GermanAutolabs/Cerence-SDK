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
 *  Declaration of nuance_prompter_SkipMode enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup SkipMode
 *  @{
 *  @file SkipMode.h
 * @brief Defines enumeration SkipMode
 */

#ifndef NUANCE_PROMPTER_SKIPMODE_H
#define NUANCE_PROMPTER_SKIPMODE_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration describes skip modes.
 */
typedef enum
{
    NUANCE_PROMPTER_TEXTUNIT_ABSOLUTE,  /**< Defines to skip to a text unit counted from the beginning of a prompt */
    NUANCE_PROMPTER_TEXTUNIT_RELATIVE,  /**< Defines to skip to a text unit counted relatively from the currently playing text unit */
    NUANCE_PROMPTER_BOOKMARK_ID,        /**< Defines to skip to a bookmark a with certain bookmark id */
    NUANCE_PROMPTER_BOOKMARK_RELATIVE   /**< Defines to skip to a bookmark counted relatively from the currently playing text unit */
} nuance_prompter_SkipMode;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_SkipMode_toString(nuance_prompter_SkipMode enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_SKIPMODE_H */

/** @} */
/** @} */

