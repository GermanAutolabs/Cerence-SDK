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
 *  Declaration of nuance_prompter_LanguageInfoType enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup LanguageInfoType
 *  @{
 *  @file LanguageInfoType.h
 * @brief Defines enumeration LanguageInfoType
 */

#ifndef NUANCE_PROMPTER_LANGUAGEINFOTYPE_H
#define NUANCE_PROMPTER_LANGUAGEINFOTYPE_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration describes language information types.
 */
typedef enum
{
    NUANCE_PROMPTER_CLM_VERSION_INFO,  /**< Describes the language info type used to request CLM (Cross-language mapping) version information. */
    NUANCE_PROMPTER_NTS_VERSION_INFO   /**< Describes the language info type used to request NTS (NT-SAMPA) version information. */
} nuance_prompter_LanguageInfoType;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_LanguageInfoType_toString(nuance_prompter_LanguageInfoType enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_LANGUAGEINFOTYPE_H */

/** @} */
/** @} */

