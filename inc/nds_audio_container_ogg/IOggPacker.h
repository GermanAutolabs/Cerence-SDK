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
 *  Declaration of nuance_audio_IOggPacker class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IOggPacker
 *  @{
 *  @file IOggPacker.h
 *
 *  @brief  Interface of the 'OGG' container. <p>
 *
 *  This implementation of the OGG container is able to pack opus encoded data into the OGG container.
 */

#ifndef NUANCE_AUDIO_IOGGPACKER_H
#define NUANCE_AUDIO_IOGGPACKER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'OGG' container. <p>
 *
 *  This implementation of the OGG container is able to pack opus encoded data into the OGG container.
 */
struct _nuance_audio_IOggPacker;
/**
 *  @brief  Interface of the 'OGG' container. <p>
 *
 *  This implementation of the OGG container is able to pack opus encoded data into the OGG container.
 */
typedef struct _nuance_audio_IOggPacker nuance_audio_IOggPacker;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IAudioManager.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  Enables the implicit creation feature for this container. <p>
 *
 *  This method enables the implicit creation feature for this container at the handed audio manager instance.
 *  It takes care of all necessary internal steps to do that, including the creation of the needed factory
 *  as well as the registration of that factory object at the audio manager.
 *
 *  The ownership of the factory object is handed to the audio manager by calling this method.
 *  It will be destroyed once the audio manager is destroyed.
 *
 *  This feature can be activated only once and stays active as long as the handed audio manager instance is available.
 *  Trying to activate that feature a second time will result in an error.
 *
 *  @param[in]     audioManager   Audio manager instance.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IOggPacker_registerFactory(nuance_audio_IAudioManager *audioManager);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IOGGPACKER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
