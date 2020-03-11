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
 * @addtogroup nuance_common nuance_common
 * @{
 * @addtogroup String
 * @{
 * @file nuance_String.h
 *
 * @brief Defines String
 *
 */

#ifndef NUANCE_COMMON_STRING_H
#define NUANCE_COMMON_STRING_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

struct _nuance_common_String;
typedef struct _nuance_common_String nuance_common_String;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"


/*** Methods **********************************************************************************************************/


/**
 *  \brief Construct a String object
 *
 *  Creates a new String object.
 *
 *  @param[in]     str   Pointer to the C string
 *
 *  @return The String object or 0 if memory allocation fails
 */
COMMON_C_EXPORT nuance_common_String *nuance_common_String_create(const LH_CHAR *str);


/**
 *  \brief Get pointer to C string.
 *
 *  Returns a pointer to the C string contained in String object
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return The C string; may not be modified or freed; pointer is valid until another String method is called
 */
COMMON_C_EXPORT const LH_CHAR *nuance_common_String_c_str(const nuance_common_String *instance);


/**
 *  \brief Release the String object.
 *
 *  Releases the String object
 *
 *  @param[in,out] instance The instance pointer
 */
COMMON_C_EXPORT void nuance_common_String_destroy(nuance_common_String *instance);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_STRING_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
