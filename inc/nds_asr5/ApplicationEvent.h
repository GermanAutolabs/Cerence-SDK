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
 *  Declaration of nuance_asr5_ApplicationEvent enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5 nuance_asr5
 * @{
 *  @addtogroup ApplicationEvent
 *  @{
 *  @file ApplicationEvent.h
 * @brief Defines enumeration ApplicationEvent
 */

#ifndef NUANCE_ASR5_APPLICATIONEVENT_H
#define NUANCE_ASR5_APPLICATIONEVENT_H

#include "lh_types.h"
#include "asr5_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  This enumeration type describes the events which can occur during an application operation. <p>
 */
typedef enum
{
    NUANCE_ASR5_APPLICATION_CREATE_COMPLETED   /**< application create operation has completed */
} nuance_asr5_ApplicationEvent;

ASR5_C_EXPORT const LH_CHAR *nuance_asr5_ApplicationEvent_toString(nuance_asr5_ApplicationEvent enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_APPLICATIONEVENT_H */

/** @} */
/** @} */

