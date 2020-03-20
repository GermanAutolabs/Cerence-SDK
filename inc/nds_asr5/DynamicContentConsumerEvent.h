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
 *  Declaration of nuance_asr5_DynamicContentConsumerEvent enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5 nuance_asr5
 * @{
 *  @addtogroup DynamicContentConsumerEvent
 *  @{
 *  @file DynamicContentConsumerEvent.h
 * @brief Defines enumeration DynamicContentConsumerEvent
 */

#ifndef NUANCE_ASR5_DYNAMICCONTENTCONSUMEREVENT_H
#define NUANCE_ASR5_DYNAMICCONTENTCONSUMEREVENT_H

#include "lh_types.h"
#include "asr5_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  This enumeration type describes the events which can occur on a dynamic content consumer (dcc). <p>
 */
typedef enum
{
    NUANCE_ASR5_DCC_DATA_PREPARATION_STARTED,   /**< Raised when the dcc data preparation is started. */
    NUANCE_ASR5_DCC_DATA_PREPARATION_FINISHED,  /**< Raised when the dcc has finished creating its dynamic data. The message contains the current total number of entries, and number of added, removed, failed entries */
    NUANCE_ASR5_DCC_CREATION_STARTED,           /**< Raised when the dcc creation is started. */
    NUANCE_ASR5_DCC_CREATION_FINISHED,          /**< Raised when the dcc creation has finished. */
    NUANCE_ASR5_DCC_CREATION_FAILED,            /**< Raised when the dcc creation failed. Look into the log file for the details of the failure. */
    NUANCE_ASR5_DCC_WITH_N_ENTRIES,             /**< Raised with the DCC entries count after the dcc creation succeeded. */
    NUANCE_ASR5_DCC_DATA_ID,                    /**< Raised with the DCC data id after the dcc creation succeeded. */
    NUANCE_ASR5_DCC_N_ENTRIES_PROCESSED         /**< Raised every time  a configured amount (progress_increment) of entries has been processed. */
} nuance_asr5_DynamicContentConsumerEvent;

ASR5_C_EXPORT const LH_CHAR *nuance_asr5_DynamicContentConsumerEvent_toString(nuance_asr5_DynamicContentConsumerEvent enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_DYNAMICCONTENTCONSUMEREVENT_H */

/** @} */
/** @} */

