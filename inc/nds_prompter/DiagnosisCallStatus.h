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
 *  Declaration of nuance_prompter_DiagnosisCallStatus enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup DiagnosisCallStatus
 *  @{
 *  @file DiagnosisCallStatus.h
 * @brief Defines enumeration DiagnosisCallStatus
 */

#ifndef NUANCE_PROMPTER_DIAGNOSISCALLSTATUS_H
#define NUANCE_PROMPTER_DIAGNOSISCALLSTATUS_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration type describes diagnosis call status codes.
 */
typedef enum
{
    NUANCE_PROMPTER_SUCCESS,                              /**< The diagnosis call completed with success. */
    NUANCE_PROMPTER_FAILED_ARGUMENT_INVALID,              /**< The diagnosis call failed because of an invalid argument. */
    NUANCE_PROMPTER_FAILED_STATE_INVALID,                 /**< The diagnosis call failed because of an unexpected state. */
    NUANCE_PROMPTER_FAILED_ALLOCATION_ERROR,              /**< The diagnosis call failed because a memory allocation failed. */
    NUANCE_PROMPTER_FAILED_TUNINGFILE_NOT_FOUND,          /**< The diagnosis call failed because a configured tuning file could not be opened. */
    NUANCE_PROMPTER_FAILED_DICTIONARY_INVALID,            /**< The diagnosis call failed because an error occurred while reading a dictionary file. */
    NUANCE_PROMPTER_FAILED_RULESET_INVALID,               /**< The diagnosis call failed because an error occurred while reading a ruleset file. */
    NUANCE_PROMPTER_FAILED_ACTIVEPROMPTDATABASE_INVALID,  /**< The diagnosis call failed because an error occurred while reading an active prompt database. */
    NUANCE_PROMPTER_FAILED_PROMPT_TEMPLATE_INVALID,       /**< The diagnosis call failed because an error occurred while reading a prompt template file. */
    NUANCE_PROMPTER_FAILED_EMAILPARSERCONFIG_NOT_FOUND,   /**< The diagnosis call failed because the configured email-parser configuration file could not be opened. */
    NUANCE_PROMPTER_FAILED_EMAILPARSERCONFIG_INVALID,     /**< The diagnosis call failed because an error occurred while reading the email-parser configuration file. */
    NUANCE_PROMPTER_FAILED_SPEECHCONFIG_NOT_FOUND,        /**< The diagnosis call failed because the requested speech configuration (language/voice/operating-point) is not supported. */
    NUANCE_PROMPTER_FAILED_SPEECHPARAMETER_INVALID,       /**< The diagnosis call failed because a requested speech parameter contains an invalid or unsupported value. */
    NUANCE_PROMPTER_FAILED_JSON_CONFIGURATION_INVALID,    /**< The diagnosis call failed because of an invalid JSON configuration. */
    NUANCE_PROMPTER_FAILED_OTD_FILE_NOT_FOUND,            /**< The diagnosis call failed because a configured OTD file could not be opened. */
    NUANCE_PROMPTER_FAILED_OTD_FILE_INVALID,              /**< The diagnosis call failed because an error occurred while reading the OTD file. */
    NUANCE_PROMPTER_FAILED_PROMPT_FILE_NOT_FOUND,         /**< The diagnosis call failed because the file to prompt could not be opened. */
    NUANCE_PROMPTER_FAILED_INPUT_INVALID,                 /**< The diagnosis call failed because an invalid input (string/file) was passed to the prompt. */
    NUANCE_PROMPTER_FAILED_EMAILPARSER_ERROR,             /**< The diagnosis call failed because an error occurred while running the email preprocessor. */
    NUANCE_PROMPTER_FAILED_CLOUD_CONNECTION_ERROR,        /**< The diagnosis call failed because the cloud connection failed during prompting */
    NUANCE_PROMPTER_FAILED_CLOUD_CONNECTION_LOST          /**< The diagnosis call failed because the cloud connection was lost during prompting */
} nuance_prompter_DiagnosisCallStatus;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_DiagnosisCallStatus_toString(nuance_prompter_DiagnosisCallStatus enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_DIAGNOSISCALLSTATUS_H */

/** @} */
/** @} */

