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
 *  Declaration of nuance_audio_SegmentationState enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio nuance_audio
 * @{
 *  @addtogroup SegmentationState
 *  @{
 *  @file SegmentationState.h
 * @brief Defines enumeration SegmentationState
 */

#ifndef NUANCE_AUDIO_SEGMENTATIONSTATE_H
#define NUANCE_AUDIO_SEGMENTATIONSTATE_H

#include "lh_types.h"
#include "audio_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  This enumeration type describes the status which can occur during a audio segmentation run. <p>
 *
 *  Used at the "onSegmentation" method of the IAudioManagerListener.
 *  This method is triggered by the segmentation module if added to the audio path.
 *  This module is only available at the DDFW.
 */
typedef enum
{
    NUANCE_AUDIO_BEGIN_OF_SPEECH,  /**< Begin Of Speech */
    NUANCE_AUDIO_END_OF_SPEECH,    /**< End Of Speech */
    NUANCE_AUDIO_INITIAL_TIMEOUT   /**< Initial Timeout */
} nuance_audio_SegmentationState;

AUDIO_C_EXPORT const LH_CHAR *nuance_audio_SegmentationState_toString(nuance_audio_SegmentationState enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_SEGMENTATIONSTATE_H */

/** @} */
/** @} */

