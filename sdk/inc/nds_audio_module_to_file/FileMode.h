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
 *  Declaration of nuance_audio_FileMode enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio nuance_audio
 * @{
 *  @addtogroup FileMode
 *  @{
 *  @file FileMode.h
 * @brief Defines enumeration FileMode
 */

#ifndef NUANCE_AUDIO_FILEMODE_H
#define NUANCE_AUDIO_FILEMODE_H

#include "lh_types.h"
#include "audio_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  Define the file open mode. <p>
 *
 *  This enumeration represents the mode in which the file is opened.
 */
typedef enum
{
    NUANCE_AUDIO_FM_OVERWRITE,  /**< will create a new file if not present or overwrite the file if it already exists */
    NUANCE_AUDIO_FM_APPEND      /**< will append the new data to an already existing file */
} nuance_audio_FileMode;

AUDIO_C_EXPORT const LH_CHAR *nuance_audio_FileMode_toString(nuance_audio_FileMode enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_FILEMODE_H */

/** @} */
/** @} */

