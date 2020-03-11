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
 *  Declaration of nuance_asr5_AsrManagerError enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5 nuance_asr5
 * @{
 *  @addtogroup AsrManagerError
 *  @{
 *  @file AsrManagerError.h
 * @brief Defines enumeration AsrManagerError
 */

#ifndef NUANCE_ASR5_ASRMANAGERERROR_H
#define NUANCE_ASR5_ASRMANAGERERROR_H

#include "lh_types.h"
#include "asr5_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration type describes the errors which can occur in the AsrManager (incl. VoCon5 errors)
 */
typedef enum
{
    NUANCE_ASR5_ASRMANAGER_VOCON_ALLOCATION_FAILURE,   /**< Indicates that an error occurred during memory allocation. */
    NUANCE_ASR5_ASRMANAGER_VOCON_INVALID_STATE,        /**< Indicates that a vocon object is not in a porper state. */
    NUANCE_ASR5_ASRMANAGER_VOCON_INVALID_ARGUMENT,     /**< Indicates that an invalid argument was passed to a function. */
    NUANCE_ASR5_ASRMANAGER_VOCON_INVALID_DATA,         /**< Inidcates that a stream contains invalid data. */
    NUANCE_ASR5_ASRMANAGER_VOCON_INVALID_VERSION,      /**< Inidcates that the givin data has the wrong version. */
    NUANCE_ASR5_ASRMANAGER_VOCON_CALLBACK_ERROR,       /**< Indicates that a callback returns an error. */
    NUANCE_ASR5_ASRMANAGER_VOCON_LIMIT,                /**< Indicates that an internal varialbe has exceeded its maximun value. */
    NUANCE_ASR5_ASRMANAGER_VOCON_NOTSUPPORTED,         /**< Indicates that a requested feature is not supported. */
    NUANCE_ASR5_ASRMANAGER_VOCON_ERROR,                /**< Indicates that an internal vocon error occured. */
    NUANCE_ASR5_ASRMANAGER_VOCON_STREAMCONFIGBUILDER   /**< Inidcates that a StreamConfigBuilder could not be set correctly */
} nuance_asr5_AsrManagerError;

ASR5_C_EXPORT const LH_CHAR *nuance_asr5_AsrManagerError_toString(nuance_asr5_AsrManagerError enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_ASRMANAGERERROR_H */

/** @} */
/** @} */

