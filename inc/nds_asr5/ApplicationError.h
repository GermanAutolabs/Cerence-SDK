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
 *  Declaration of nuance_asr5_ApplicationError enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5 nuance_asr5
 * @{
 *  @addtogroup ApplicationError
 *  @{
 *  @file ApplicationError.h
 * @brief Defines enumeration ApplicationError
 */

#ifndef NUANCE_ASR5_APPLICATIONERROR_H
#define NUANCE_ASR5_APPLICATIONERROR_H

#include "lh_types.h"
#include "asr5_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration type describes the errors which can occur during execution of application methods.
 */
typedef enum
{
    NUANCE_ASR5_APPLICATION_ALLOCATION_FAILURE,                               /**< Indicates that an error occurred during memory allocation. */
    NUANCE_ASR5_APPLICATION_SEARCH_SPACE_NOT_FOUND,                           /**< Indicates that a SEARCH_SPACE used by the application is not found */
    NUANCE_ASR5_APPLICATION_SEARCH_SPACE_INVALID,                             /**< Indicates that a SEARCH_SPACE used by the application is invalid */
    NUANCE_ASR5_APPLICATION_ACMOD_NOT_FOUND,                                  /**< Indicates that an acmod used by the application is not found */
    NUANCE_ASR5_APPLICATION_ACMOD_INVALID,                                    /**< Indicates that an acmod used by the application is invalid */
    NUANCE_ASR5_APPLICATION_SEARCH_SPACE_INVALID_WITH_ACMOD_NOT_FOUND,        /**< Indicates that a SEARCH_SPACE used by the application is invalid due to the acmod was not found */
    NUANCE_ASR5_APPLICATION_SEARCH_SPACE_INVALID_WITH_ACMOD_INVALID,          /**< Indicates that a SEARCH_SPACE used by the application is invalid due to the acmod is invalid */
    NUANCE_ASR5_APPLICATION_SEM3_CTX_NOT_FOUND,                               /**< Indicates that a sem3 context used by the application is not found */
    NUANCE_ASR5_APPLICATION_SEM3_CTX_INVALID,                                 /**< Indicates that a sem3 context used by the application is invalid */
    NUANCE_ASR5_APPLICATION_SEM3_DATA_INVALID,                                /**< Indicates that a sem3 data used by the application is invalid */
    NUANCE_ASR5_APPLICATION_SEM3_DATA_NOT_FOUND,                              /**< Indicates that a sem3 data added to the application was not found */
    NUANCE_ASR5_APPLICATION_CANNOT_SET_GUEST_SEARCH_SPACE_EXPECTED_FORWARD,   /**< Indicates that a host has forward and guest has backward strategies */
    NUANCE_ASR5_APPLICATION_CANNOT_SET_GUEST_SEARCH_SPACE_EXPECTED_BACKWARD,  /**< Indicates that a host has backward and guest has forward strategies */
    NUANCE_ASR5_APPLICATION_CANNOT_SET_GUEST_SEARCH_SPACE,                    /**< Indicates that a guest cannot be set but we have no additional info */
    NUANCE_ASR5_APPLICATION_STATIC_SEARCH_SPACE_NOT_CONSOLIDATED,             /**< Indicates that a consolidated buffer was not merged to the SEARCH_SPACE */
    NUANCE_ASR5_APPLICATION_ERROR,                                            /**< Indicates that a generic error has occurred. */
    NUANCE_ASR5_APPLICATION_FATAL                                             /**< Indicates that a fatal error has occurred. */
} nuance_asr5_ApplicationError;

ASR5_C_EXPORT const LH_CHAR *nuance_asr5_ApplicationError_toString(nuance_asr5_ApplicationError enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_APPLICATIONERROR_H */

/** @} */
/** @} */

