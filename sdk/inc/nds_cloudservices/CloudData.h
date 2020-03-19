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
 *  Declaration of nuance_cloudservices_CloudData list type
 *  Automatically generated source code! Do not edit manually!
 *
 */


/**
 *  @addtogroup nuance_cloudservices nuance_cloudservices
 *  @{
 *  @addtogroup CloudData
 *  @{
 *  @file CloudData.h
 *  @brief Defines CloudData as list of nuance_common_IDictionary
 */


#ifndef NUANCE_CLOUDSERVICES_CLOUDDATA_H
#define NUANCE_CLOUDSERVICES_CLOUDDATA_H


#include "lh_types.h"
#include "cloudservices_api_defs.h"
#include "IDictionary.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * The nuance_cloudservices_CloudData data structure.
 */
struct _nuance_cloudservices_CloudData;

typedef struct _nuance_cloudservices_CloudData nuance_cloudservices_CloudData;

/**
 *  @brief Create a list object.
 *
 *  On creation of the list objects the passed C list is copied.
 *
 *  @param[in] list    An array of nuance_common_IDictionary * pointers to copy into the list
 *  @param[in] length  The number of elements in the list
 *  @returns           The list instance pointer
 */
CLOUDSERVICES_C_EXPORT nuance_cloudservices_CloudData *nuance_cloudservices_CloudData_create(nuance_common_IDictionary **list, LH_S32 length);

/**
 *  @brief Number of elements.
 *
 *  Get the number of elements contained in this list.
 *
 *  @param[in] list    The list instance pointer
 *  @returns           The number of elements
 */
CLOUDSERVICES_C_EXPORT LH_S32 nuance_cloudservices_CloudData_count(const nuance_cloudservices_CloudData *list);

/**
 * @brief Get the element at index (zero-based).
 *
 * Getter for accessing the content of the list.
 * Behavior is undefined for out-of-range accesses.
 *
 *  @param[in] list    The list instance pointer
 *  @param[in] index   The index of the requested element
 *  @returns           The nuance_common_IDictionary * element
 */
CLOUDSERVICES_C_EXPORT nuance_common_IDictionary *nuance_cloudservices_CloudData_get(const nuance_cloudservices_CloudData *list, LH_S32 index);

/**
 *  @brief Release this list object.
 *
 *  Subsequent calls to this object result in undefined behavior.
 *
 *  @param[in] list    The list instance pointer
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_CloudData_destroy(nuance_cloudservices_CloudData *list);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_CLOUDDATA_H */


/** @} */
/** @} */

