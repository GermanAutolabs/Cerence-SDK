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
 *  Declaration of nuance_audio_AudioContainer enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio nuance_audio
 * @{
 *  @addtogroup AudioContainer
 *  @{
 *  @file AudioContainer.h
 * @brief Defines enumeration AudioContainer
 */

#ifndef NUANCE_AUDIO_AUDIOCONTAINER_H
#define NUANCE_AUDIO_AUDIOCONTAINER_H

#include "lh_types.h"
#include "audio_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  Define the audio container type we have to deal with. <p>
 *
 *  This enumeration represents the type of the supported container for the audio data.
 */
typedef enum
{
    NUANCE_AUDIO_CONTAINER_UNDEFINED,  /**< undefined container, please set valid format */
    NUANCE_AUDIO_CONTAINER_USER,       /**< user specific container type */
    NUANCE_AUDIO_CONTAINER_NONE,       /**< No container used/desired */
    NUANCE_AUDIO_CONTAINER_OGG         /**< OGG container */
} nuance_audio_AudioContainer;

AUDIO_C_EXPORT const LH_CHAR *nuance_audio_AudioContainer_toString(nuance_audio_AudioContainer enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_AUDIOCONTAINER_H */

/** @} */
/** @} */

