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
 *  Declaration of nuance_common_IntList list type
 *  Automatically generated source code! Do not edit manually!
 *
 */


/**
 *  @addtogroup nuance_common nuance_common
 *  @{
 *  @addtogroup IntList
 *  @{
 *  @file IntList.h
 *  @brief Defines IntList as list of LH_S32
 */


#ifndef NUANCE_COMMON_INTLIST_H
#define NUANCE_COMMON_INTLIST_H


#include "lh_types.h"
#include "common_api_defs.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * The nuance_common_IntList data structure.
 */
struct _nuance_common_IntList;

/**
 *  @brief  A one-dimensional list of integer values.<p> Used for handling lists of integers on the API
 */
typedef struct _nuance_common_IntList nuance_common_IntList;

/**
 *  @brief Create a list object.
 *
 *  On creation of the list objects the passed C list is copied.
 *
 *  @param[in] list    An array of LH_S32 values to copy into the list
 *  @param[in] length  The number of elements in the list
 *  @returns           The list instance pointer
 */
COMMON_C_EXPORT nuance_common_IntList *nuance_common_IntList_create(LH_S32 *list, LH_S32 length);

/**
 *  @brief Number of elements.
 *
 *  Get the number of elements contained in this list.
 *
 *  @param[in] list    The list instance pointer
 *  @returns           The number of elements
 */
COMMON_C_EXPORT LH_S32 nuance_common_IntList_count(const nuance_common_IntList *list);

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
COMMON_C_EXPORT LH_S32 nuance_common_IntList_get(const nuance_common_IntList *list, LH_S32 index);

/**
 *  @brief Release this list object.
 *
 *  Subsequent calls to this object result in undefined behavior.
 *
 *  @param[in] list    The list instance pointer
 */
COMMON_C_EXPORT void nuance_common_IntList_destroy(nuance_common_IntList *list);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_INTLIST_H */


/** @} */
/** @} */

