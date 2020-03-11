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
 *  Declaration of nuance_asr5_RecognizerError enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5 nuance_asr5
 * @{
 *  @addtogroup RecognizerError
 *  @{
 *  @file RecognizerError.h
 * @brief Defines enumeration RecognizerError
 */

#ifndef NUANCE_ASR5_RECOGNIZERERROR_H
#define NUANCE_ASR5_RECOGNIZERERROR_H

#include "lh_types.h"
#include "asr5_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration type describes the errors which can occur during execution of recognizer methods.
 */
typedef enum
{
    NUANCE_ASR5_RECOGNIZER_ALLOCATION_FAILURE,                                    /**< Indicates that an error occurred during memory allocation. */
    NUANCE_ASR5_RECOGNIZER_CONFIG_INVALID,                                        /**< Indicates that an error occurred while parsing the configuration file. */
    NUANCE_ASR5_RECOGNIZER_FILE_NOT_FOUND,                                        /**< Indicates that a file could not be found. */
    NUANCE_ASR5_RECOGNIZER_FILE_INVALID,                                          /**< Indicates that a file is not a valid stream. */
    NUANCE_ASR5_RECOGNIZER_ERROR,                                                 /**< Indicates that a generic error occurred */
    NUANCE_ASR5_RECOGNIZER_FATAL,                                                 /**< Indicates that a FATAL error occurred */
    NUANCE_ASR5_RECOGNIZER_AUDIOCONFIGBUILDER_MISSING_SAMPLEFREQUENCY,            /**< Indicates that lh_AudioConfigBuilderBuild called but there was no prior call to set the sampling frequency or the SSEInfoBuffer */
    NUANCE_ASR5_RECOGNIZER_AUDIOCONFIGBUILDER_INCOMPATIBLE_SAMPLEFREQUENCY,       /**< Indicates that lh_AudioConfigBuilderBuild called but the sampling frequency was set to a different value than what is specified in the SSEInfo */
    NUANCE_ASR5_RECOGNIZER_AUDIOCONFIGBUILDER_INVALID_SSE_DATA_BUFFER,            /**< Indicates that lh_AudioConfigBuilderSetSSEInfo was called with an invalid SSEInfo data buffer */
    NUANCE_ASR5_RECOGNIZER_ENGINECONFIGBUILDER_LANGUAGECONFIGPOOL_ALREADY_SET,    /**< Indicates that lh_EngineConfigBuilderSetLanguageConfigPool called multiple times. */
    NUANCE_ASR5_RECOGNIZER_ENGINECONFIGBUILDER_SPEAKERCONFIGBUILDER_ALREADY_SET,  /**< Indicates that lh_EngineConfigBuilderSetSpeakerConfigBuilder called multiple times. */
    NUANCE_ASR5_RECOGNIZER_EXTERNAL_PROVIDER_ERROR,                               /**< Indicates that an error occurred from the external result provider plugin */
    NUANCE_ASR5_RECOGNIZER_SEM3STREAMINGCONFIGBUILDER_LUA_RUNTIME_ERROR,          /**< Indicates that an error occurred during LUA Runtime */
    NUANCE_ASR5_RECOGNIZER_SEM3STREAMINGCONFIGBUILDER_MISSING_UNFOLD_FUNCTION     /**< Indicates that the unfold function is missing from the LUA script */
} nuance_asr5_RecognizerError;

ASR5_C_EXPORT const LH_CHAR *nuance_asr5_RecognizerError_toString(nuance_asr5_RecognizerError enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_RECOGNIZERERROR_H */

/** @} */
/** @} */

