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
 *  Declaration of nuance_prompter_ParameterType enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup ParameterType
 *  @{
 *  @file ParameterType.h
 * @brief Defines enumeration ParameterType
 */

#ifndef NUANCE_PROMPTER_PARAMETERTYPE_H
#define NUANCE_PROMPTER_PARAMETERTYPE_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration describes parameter types of the prompter.
 */
typedef enum
{
    NUANCE_PROMPTER_VOLUME,       /**< Describes the volume parameter type */
    NUANCE_PROMPTER_SPEECH_RATE,  /**< Describes the speech rate parameter type */
    NUANCE_PROMPTER_PITCH,        /**< Describes the pitch parameter type */
    NUANCE_PROMPTER_TIMBRE        /**< Describes the timbre parameter type */
} nuance_prompter_ParameterType;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_ParameterType_toString(nuance_prompter_ParameterType enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_PARAMETERTYPE_H */

/** @} */
/** @} */

