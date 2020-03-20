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
 *  @addtogroup nuance_common nuance_common
 *  @{
 *  @addtogroup StringList
 *  @{
 *  @file StringList.h
 *  @brief Defines StringList as list of nuance_common_String
 */


#ifndef NUANCE_COMMON_STRINGLIST_H
#define NUANCE_COMMON_STRINGLIST_H


#include "lh_types.h"
#include "common_api_defs.h"
#include "nuance_String.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * The nuance_common_StringList data structure.
 */
struct _nuance_common_StringList;

/**
 *  @brief  A one-dimensional list of Strings. <p> Used for handling lists of strings on the API
 */
typedef struct _nuance_common_StringList nuance_common_StringList;

/**
 * @brief Create a list object.
 *
 * On creation of the list objects the passed C list is copied.
 *
 *  @param[in] list    An array of char pointers to copy into the list
 *  @param[in] length  The number of elements in the list of char pointers
 *  @returns           The list instance pointer
 */
COMMON_C_EXPORT nuance_common_StringList *nuance_common_StringList_create(const LH_CHAR *const*list, LH_S32 length);

/**
 * @brief Number of elements.
 *
 * Get the number of elements contained in this list.
 *
 *  @param[in] list    The list instance pointer
 *  @returns           The number of elements
 */
COMMON_C_EXPORT LH_S32 nuance_common_StringList_count(const nuance_common_StringList *list);

/**
 * @brief Get the element at index (zero-based).
 *
 * Getter for accessing the content of the list.
 * Behavior is undefined for out-of-range accesses.
 *
 *  @param[in] list    The list instance pointer
 *  @param[in] index   The index of the requested element
 *  @returns           Pointer to the char string
 */
COMMON_C_EXPORT const LH_CHAR *nuance_common_StringList_get(const nuance_common_StringList *list, LH_S32 index);

/**
 * @brief Release this list object.
 *
 * Subsequent calls to this object result in undefined behavior.
 *
 *  @param[in] list    The list instance pointer
 */
COMMON_C_EXPORT void nuance_common_StringList_destroy(nuance_common_StringList *list);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_STRINGLIST_H */


/** @} */
/** @} */

