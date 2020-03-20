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
 *  Declaration of nuance_prompter_TextSourceList list type
 *  Automatically generated source code! Do not edit manually!
 *
 */


/**
 *  @addtogroup nuance_prompter nuance_prompter
 *  @{
 *  @addtogroup TextSourceList
 *  @{
 *  @file TextSourceList.h
 *  @brief Defines TextSourceList as list of nuance_prompter_TextSource
 */


#ifndef NUANCE_PROMPTER_TEXTSOURCELIST_H
#define NUANCE_PROMPTER_TEXTSOURCELIST_H


#include "lh_types.h"
#include "prompter_api_defs.h"
#include "TextSource.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * The nuance_prompter_TextSourceList data structure.
 */
struct _nuance_prompter_TextSourceList;

/**
 *  @brief  A list of text sources. <p> The list can hold enumeration elements describing a text source.
 */
typedef struct _nuance_prompter_TextSourceList nuance_prompter_TextSourceList;

/**
 *  @brief Create a list object.
 *
 *  On creation of the list objects the passed C list is copied.
 *
 *  @param[in] list    An array of nuance_prompter_TextSource values to copy into the list
 *  @param[in] length  The number of elements in the list
 *  @returns           The list instance pointer
 */
PROMPTER_C_EXPORT nuance_prompter_TextSourceList *nuance_prompter_TextSourceList_create(nuance_prompter_TextSource *list, LH_S32 length);

/**
 *  @brief Number of elements.
 *
 *  Get the number of elements contained in this list.
 *
 *  @param[in] list    The list instance pointer
 *  @returns           The number of elements
 */
PROMPTER_C_EXPORT LH_S32 nuance_prompter_TextSourceList_count(const nuance_prompter_TextSourceList *list);

/**
 * @brief Get the element at index (zero-based).
 *
 * Getter for accessing the content of the list.
 * Behavior is undefined for out-of-range accesses.
 *
 *  @param[in] list    The list instance pointer
 *  @param[in] index   The index of the requested element
 *  @returns           The nuance_prompter_TextSource  element
 */
PROMPTER_C_EXPORT nuance_prompter_TextSource nuance_prompter_TextSourceList_get(const nuance_prompter_TextSourceList *list, LH_S32 index);

/**
 *  @brief Release this list object.
 *
 *  Subsequent calls to this object result in undefined behavior.
 *
 *  @param[in] list    The list instance pointer
 */
PROMPTER_C_EXPORT void nuance_prompter_TextSourceList_destroy(nuance_prompter_TextSourceList *list);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_TEXTSOURCELIST_H */


/** @} */
/** @} */

