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
 *  Declaration of nuance_audio_AudioData_8Bit list type
 *  Automatically generated source code! Do not edit manually!
 *
 */


/**
 *  @addtogroup nuance_audio nuance_audio
 *  @{
 *  @addtogroup AudioData_8Bit
 *  @{
 *  @file AudioData_8Bit.h
 *  @brief Defines AudioData_8Bit as list of LH_S8
 */


#ifndef NUANCE_AUDIO_AUDIODATA_8BIT_H
#define NUANCE_AUDIO_AUDIODATA_8BIT_H


#include "lh_types.h"
#include "audio_api_defs.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * The nuance_audio_AudioData_8Bit data structure.
 */
struct _nuance_audio_AudioData_8Bit;

typedef struct _nuance_audio_AudioData_8Bit nuance_audio_AudioData_8Bit;

/**
 *  @brief Create a list object.
 *
 *  On creation of the list objects the passed C list is copied.
 *
 *  @param[in] list    An array of LH_S8 values to copy into the list
 *  @param[in] length  The number of elements in the list
 *  @returns           The list instance pointer
 */
AUDIO_C_EXPORT nuance_audio_AudioData_8Bit *nuance_audio_AudioData_8Bit_create(LH_S8 *list, LH_S32 length);

/**
 *  @brief Number of elements.
 *
 *  Get the number of elements contained in this list.
 *
 *  @param[in] list    The list instance pointer
 *  @returns           The number of elements
 */
AUDIO_C_EXPORT LH_S32 nuance_audio_AudioData_8Bit_count(const nuance_audio_AudioData_8Bit *list);

/**
 * @brief Get the element at index (zero-based).
 *
 * Getter for accessing the content of the list.
 * Behavior is undefined for out-of-range accesses.
 *
 *  @param[in] list    The list instance pointer
 *  @param[in] index   The index of the requested element
 *  @returns           The LH_S8  element
 */
AUDIO_C_EXPORT LH_S8 nuance_audio_AudioData_8Bit_get(const nuance_audio_AudioData_8Bit *list, LH_S32 index);

/**
 *  @brief Release this list object.
 *
 *  Subsequent calls to this object result in undefined behavior.
 *
 *  @param[in] list    The list instance pointer
 */
AUDIO_C_EXPORT void nuance_audio_AudioData_8Bit_destroy(nuance_audio_AudioData_8Bit *list);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_AUDIODATA_8BIT_H */


/** @} */
/** @} */

