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
 *  Declaration of nuance_prompter_StringParameterType enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup StringParameterType
 *  @{
 *  @file StringParameterType.h
 * @brief Defines enumeration StringParameterType
 */

#ifndef NUANCE_PROMPTER_STRINGPARAMETERTYPE_H
#define NUANCE_PROMPTER_STRINGPARAMETERTYPE_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration describes String parameter types of the prompter.
 */
typedef enum
{
    NUANCE_PROMPTER_TEXT_NORMALIZATION_TYPE   /**< Describes the text normalization type (TN type). It overrules the value of the "text_normalization_type" key defined in the currently activated usecase. */
} nuance_prompter_StringParameterType;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_StringParameterType_toString(nuance_prompter_StringParameterType enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_STRINGPARAMETERTYPE_H */

/** @} */
/** @} */

