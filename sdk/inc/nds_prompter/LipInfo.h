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
 *  Declaration of nuance_prompter_LipInfo list type
 *  Automatically generated source code! Do not edit manually!
 *
 */


/**
 *  @addtogroup nuance_prompter nuance_prompter
 *  @{
 *  @addtogroup LipInfo
 *  @{
 *  @file LipInfo.h
 *  @brief Defines LipInfo as list of LH_S32
 */


#ifndef NUANCE_PROMPTER_LIPINFO_H
#define NUANCE_PROMPTER_LIPINFO_H


#include "lh_types.h"
#include "prompter_api_defs.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * The nuance_prompter_LipInfo data structure.
 */
struct _nuance_prompter_LipInfo;

typedef struct _nuance_prompter_LipInfo nuance_prompter_LipInfo;

/**
 *  @brief Create a list object.
 *
 *  On creation of the list objects the passed C list is copied.
 *
 *  @param[in] list    An array of LH_S32 values to copy into the list
 *  @param[in] length  The number of elements in the list
 *  @returns           The list instance pointer
 */
PROMPTER_C_EXPORT nuance_prompter_LipInfo *nuance_prompter_LipInfo_create(LH_S32 *list, LH_S32 length);

/**
 *  @brief Number of elements.
 *
 *  Get the number of elements contained in this list.
 *
 *  @param[in] list    The list instance pointer
 *  @returns           The number of elements
 */
PROMPTER_C_EXPORT LH_S32 nuance_prompter_LipInfo_count(const nuance_prompter_LipInfo *list);

/**
 * @brief Get the element at index (zero-based).
 *
 * Getter for accessing the content of the list.
 * Behavior is undefined for out-of-range accesses.
 *
 *  @param[in] list    The list instance pointer
 *  @param[in] index   The index of the requested element
 *  @returns           The LH_S32  element
 */
PROMPTER_C_EXPORT LH_S32 nuance_prompter_LipInfo_get(const nuance_prompter_LipInfo *list, LH_S32 index);

/**
 *  @brief Release this list object.
 *
 *  Subsequent calls to this object result in undefined behavior.
 *
 *  @param[in] list    The list instance pointer
 */
PROMPTER_C_EXPORT void nuance_prompter_LipInfo_destroy(nuance_prompter_LipInfo *list);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_LIPINFO_H */


/** @} */
/** @} */

