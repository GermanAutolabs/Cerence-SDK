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
 *  Declaration of nuance_prompter_PrompterError enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup PrompterError
 *  @{
 *  @file PrompterError.h
 * @brief Defines enumeration PrompterError
 */

#ifndef NUANCE_PROMPTER_PROMPTERERROR_H
#define NUANCE_PROMPTER_PROMPTERERROR_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration type describes the errors which can occur during execution of prompter methods.
 */
typedef enum
{
    NUANCE_PROMPTER_PROMPTER_ARGUMENT_INVALID,     /**< Indicates that an invalid argument was passed. */
    NUANCE_PROMPTER_PROMPTER_STATE_INVALID,        /**< Indicates that the prompter is in an invalid state for the requested action. */
    NUANCE_PROMPTER_PROMPTER_ALLOCATION_FAILURE,   /**< Indicates that the memory allocation failed. */
    NUANCE_PROMPTER_TUNINGFILE_NOT_FOUND,          /**< Indicates that a configured tuning file could not be opened. */
    NUANCE_PROMPTER_DICTIONARY_INVALID,            /**< Indicates that an error occurred while reading a dictionary file. */
    NUANCE_PROMPTER_RULESET_INVALID,               /**< Indicates that an error occurred while reading a ruleset file. */
    NUANCE_PROMPTER_PROMPT_TEMPLATE_INVALID,       /**< Indicates that an error occurred while reading a prompt template file. */
    NUANCE_PROMPTER_ACTIVEPROMPTDATABASE_INVALID,  /**< Indicates that an error occurred while reading a active prompt database. */
    NUANCE_PROMPTER_SCANRESULT_WRITE_ERROR,        /**< Indicates that an error occurred while writing the scanresult file. */
    NUANCE_PROMPTER_SCANRESULT_READ_ERROR,         /**< Indicates that an error occurred while reading the scanresult file. */
    NUANCE_PROMPTER_EMAILPARSERCONFIG_NOT_FOUND,   /**< Indicates that the configured email-parser configuration file could not be opened. */
    NUANCE_PROMPTER_EMAILPARSERCONFIG_INVALID,     /**< Indicates that an error occurred while reading the email-parser configuration file. */
    NUANCE_PROMPTER_SPEECHCONFIG_NOT_FOUND,        /**< Indicates that the requested speech configuration (language/voice/voice-model) is not supported. */
    NUANCE_PROMPTER_SPEECHPARAMETER_INVALID,       /**< Indicates that a requested speech parameter contains an invalid or unsupported value. */
    NUANCE_PROMPTER_JSON_CONFIGURATION_INVALID,    /**< Indicates an invalid JSON configuration. */
    NUANCE_PROMPTER_OTD_FILE_NOT_FOUND,            /**< Indicates that a configured OTD file could not be opened. */
    NUANCE_PROMPTER_OTD_FILE_INVALID,              /**< Indicates that an error occurred while reading the OTD file. */
    NUANCE_PROMPTER_TEXT_ANALYSIS_ERROR            /**< Indicates that an error occurred while analyzing a text with nuance_prompter_IPrompter_analyzeText. */
} nuance_prompter_PrompterError;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_PrompterError_toString(nuance_prompter_PrompterError enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_PROMPTERERROR_H */

/** @} */
/** @} */

