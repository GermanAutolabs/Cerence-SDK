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
 *  Declaration of nuance_asr5_ResultType enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5 nuance_asr5
 * @{
 *  @addtogroup ResultType
 *  @{
 *  @file ResultType.h
 * @brief Defines enumeration ResultType
 */

#ifndef NUANCE_ASR5_RESULTTYPE_H
#define NUANCE_ASR5_RESULTTYPE_H

#include "lh_types.h"
#include "asr5_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  This enumeration type describes the types of results available in the Result API. <p>
 */
typedef enum
{
    NUANCE_ASR5_RESULT_TYPE_ASR,                /**< ASR result. */
    NUANCE_ASR5_RESULT_TYPE_EXTERNAL,           /**< ASR External result. */
    NUANCE_ASR5_RESULT_TYPE_SEMANTIC,           /**< A Semantic result. */
    NUANCE_ASR5_RESULT_TYPE_POST_PROCESSOR,     /**< A Post processor result. */
    NUANCE_ASR5_RESULT_TYPE_EXTERNAL_PROVIDER   /**< A result from an external result provider plugin. */
} nuance_asr5_ResultType;

ASR5_C_EXPORT const LH_CHAR *nuance_asr5_ResultType_toString(nuance_asr5_ResultType enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_RESULTTYPE_H */

/** @} */
/** @} */

