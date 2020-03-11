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
 *  Declaration of nuance_asr5_DynamicContentConsumerError enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5 nuance_asr5
 * @{
 *  @addtogroup DynamicContentConsumerError
 *  @{
 *  @file DynamicContentConsumerError.h
 * @brief Defines enumeration DynamicContentConsumerError
 */

#ifndef NUANCE_ASR5_DYNAMICCONTENTCONSUMERERROR_H
#define NUANCE_ASR5_DYNAMICCONTENTCONSUMERERROR_H

#include "lh_types.h"
#include "asr5_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration type describes the errors which can occur during execution of dynamic content consumer methods.
 */
typedef enum
{
    NUANCE_ASR5_DCC_ALLOCATION_FAILURE,            /**< Indicates that an error occurred during memory allocation. */
    NUANCE_ASR5_DCC_CONFIG_INVALID,                /**< Indicates that an error occurred while parsing the configuration file. */
    NUANCE_ASR5_DCC_REMOTE_CONNECTION_FAILED,      /**< Indicates that an error occurred while making a remote connection. */
    NUANCE_ASR5_DCC_REMOTE_CONNECTION_LOST,        /**< Indicates that a remote connection was lost . */
    NUANCE_ASR5_DCC_REMOTE_DATA_UPLOAD_FAILED,     /**< Indicates that an error occurred while uploading data to the server. */
    NUANCE_ASR5_DCC_DICTIONARY_INVALID,            /**< Indicates that a dictionary stream was of invalid type. */
    NUANCE_ASR5_DCC_RULESET_INVALID,               /**< Indicates that a RULESET file is invalid. */
    NUANCE_ASR5_DCC_CLC_INVALID,                   /**< Indicates that a CLC file is invalid. */
    NUANCE_ASR5_DCC_DICTIONARY_NOT_FOUND,          /**< Indicates that a dictionary has not been found. */
    NUANCE_ASR5_DCC_RULESET_NOT_FOUND,             /**< Indicates that a RULESET file has not been found. */
    NUANCE_ASR5_DCC_CLC_NOT_FOUND,                 /**< Indicates that a CLC file has not been found. */
    NUANCE_ASR5_DCC_ACMOD_INVALID,                 /**< Indicates that an ACMOD file is invalid. */
    NUANCE_ASR5_DCC_ACMOD_NOT_FOUND,               /**< Indicates that an acMod file is not found */
    NUANCE_ASR5_DCC_NO_TRANSCRIPTION,              /**< Indicates that no transcription was found for the specified word. */
    NUANCE_ASR5_DCC_PERSISTED_CONTEXT_INVALID,     /**< Indicates that a persisted context is invalid. */
    NUANCE_ASR5_DCC_EWF_NOT_FOUND,                 /**< Indicates that an EWF file has not been found. */
    NUANCE_ASR5_DCC_PERSISTING_CONTEXT_FAILED,     /**< Indicates that an error occurred while persisting a dynamic context. */
    NUANCE_ASR5_DCC_CONTEXT_CREATION_FAILED,       /**< Indicates that an error occurred while creating a context. */
    NUANCE_ASR5_DCC_SPELL_TREE_CREATION_FAILED,    /**< Indicates that an error occurred while creating a spell tree. */
    NUANCE_ASR5_DCC_ERROR,                         /**< Indicates that a generic error is occurred. */
    NUANCE_ASR5_DCC_FATAL,                         /**< Indicates that a fatal error is occurred. */
    NUANCE_ASR5_DCC_PERSISTED_SPELL_TREE_INVALID,  /**< Indicates that the spell tree which was persisted by a spelling DCC is invalid. */
    NUANCE_ASR5_DCC_PERSISTED_CONTEXT_NOT_FOUND,   /**< Indicates that persisted context does not exist for the created DCC. */
    NUANCE_ASR5_DCC_ENTRY_NOT_ADDED,               /**< Indicates that an entry could not be added to a context in the DCC. */
    NUANCE_ASR5_DCC_ENTRY_WUW_SCORE_BAD,           /**< Indicates that an entry is for wake up word but the quality of the word is bad. */
    NUANCE_ASR5_DCC_ENTRY_WUW_SCORE_WEAK,          /**< Indicates that an entry is for wake up word but the quality of the word is not quite good. */
    NUANCE_ASR5_DCC_ENTRY_NOT_REMOVED,             /**< Indicates that an entry could not be removed from a context in the DCC. */
    NUANCE_ASR5_DCC_ENTRY_COUNT_UNKNOWN,           /**< Indicates that the number of entries in the DCC is unknown. */
    NUANCE_ASR5_DCC_COP_INVALID                    /**< Indicates that a cop file is invalid. */
} nuance_asr5_DynamicContentConsumerError;

ASR5_C_EXPORT const LH_CHAR *nuance_asr5_DynamicContentConsumerError_toString(nuance_asr5_DynamicContentConsumerError enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_DYNAMICCONTENTCONSUMERERROR_H */

/** @} */
/** @} */

