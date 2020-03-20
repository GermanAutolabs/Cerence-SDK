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
 *  Declaration of nuance_audio_IMp3Decoder class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IMp3Decoder
 *  @{
 *  @file IMp3Decoder.h
 *
 *  @brief  Interface of the 'MP3' decoder. <p>
 *
 *  This implementation of the mp3 decoder is able to decode mp3 encoded audio data to 16bit PCM audio data.
 */

#ifndef NUANCE_AUDIO_IMP3DECODER_H
#define NUANCE_AUDIO_IMP3DECODER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'MP3' decoder. <p>
 *
 *  This implementation of the mp3 decoder is able to decode mp3 encoded audio data to 16bit PCM audio data.
 */
struct _nuance_audio_IMp3Decoder;
/**
 *  @brief  Interface of the 'MP3' decoder. <p>
 *
 *  This implementation of the mp3 decoder is able to decode mp3 encoded audio data to 16bit PCM audio data.
 */
typedef struct _nuance_audio_IMp3Decoder nuance_audio_IMp3Decoder;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IAudioManager.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  enables the implicit creation feature for this codec at the handed audio manager instance. <p>
 *
 *  This method enables the implicit creation feature for this codec at the handed audio manager instance.
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
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_IMp3Decoder_registerFactory(nuance_audio_IAudioManager *audioManager);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IMP3DECODER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
