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
 *  Declaration of nuance_audio_AudioData list type
 *  Automatically generated source code! Do not edit manually!
 *
 */


/**
 *  @addtogroup nuance_audio nuance_audio
 *  @{
 *  @addtogroup AudioData
 *  @{
 *  @file AudioData.h
 *  @brief Defines AudioData as list of LH_S16
 */


#ifndef NUANCE_AUDIO_AUDIODATA_H
#define NUANCE_AUDIO_AUDIODATA_H


#include "lh_types.h"
#include "audio_api_defs.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * The nuance_audio_AudioData data structure.
 */
struct _nuance_audio_AudioData;

typedef struct _nuance_audio_AudioData nuance_audio_AudioData;

/**
 *  @brief Create a list object.
 *
 *  On creation of the list objects the passed C list is copied.
 *
 *  @param[in] list    An array of LH_S16 values to copy into the list
 *  @param[in] length  The number of elements in the list
 *  @returns           The list instance pointer
 */
AUDIO_C_EXPORT nuance_audio_AudioData *nuance_audio_AudioData_create(LH_S16 *list, LH_S32 length);

/**
 *  @brief Number of elements.
 *
 *  Get the number of elements contained in this list.
 *
 *  @param[in] list    The list instance pointer
 *  @returns           The number of elements
 */
AUDIO_C_EXPORT LH_S32 nuance_audio_AudioData_count(const nuance_audio_AudioData *list);

/**
 * @brief Get the element at index (zero-based).
 *
 * Getter for accessing the content of the list.
 * Behavior is undefined for out-of-range accesses.
 *
 *  @param[in] list    The list instance pointer
 *  @param[in] index   The index of the requested element
 *  @returns           The LH_S16  element
 */
AUDIO_C_EXPORT LH_S16 nuance_audio_AudioData_get(const nuance_audio_AudioData *list, LH_S32 index);

/**
 *  @brief Release this list object.
 *
 *  Subsequent calls to this object result in undefined behavior.
 *
 *  @param[in] list    The list instance pointer
 */
AUDIO_C_EXPORT void nuance_audio_AudioData_destroy(nuance_audio_AudioData *list);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_AUDIODATA_H */


/** @} */
/** @} */

