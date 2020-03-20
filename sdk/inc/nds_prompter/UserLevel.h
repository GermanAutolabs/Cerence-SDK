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
 *  Declaration of nuance_prompter_UserLevel enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter nuance_prompter
 * @{
 *  @addtogroup UserLevel
 *  @{
 *  @file UserLevel.h
 * @brief Defines enumeration UserLevel
 */

#ifndef NUANCE_PROMPTER_USERLEVEL_H
#define NUANCE_PROMPTER_USERLEVEL_H

#include "lh_types.h"
#include "prompter_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  This enumeration describes possible user levels passed when looking up a prompter concept.
 *  A lower user level indicates a less experienced user (e.g. novice). A higher user
 *  level indicates a more experienced user (e.g. expert).
 */
typedef enum
{
    NUANCE_PROMPTER_USER_LEVEL_1,   /**< Describes the level that allows to access prompter concepts with user level 1 */
    NUANCE_PROMPTER_USER_LEVEL_2,   /**< Describes the level that allows to access prompter concepts with user level 2 */
    NUANCE_PROMPTER_USER_LEVEL_3,   /**< Describes the level that allows to access prompter concepts with user level 3 */
    NUANCE_PROMPTER_USER_LEVEL_4,   /**< Describes the level that allows to access prompter concepts with user level 4 */
    NUANCE_PROMPTER_USER_LEVEL_5,   /**< Describes the level that allows to access prompter concepts with user level 5 */
    NUANCE_PROMPTER_USER_LEVEL_6,   /**< Describes the level that allows to access prompter concepts with user level 6 */
    NUANCE_PROMPTER_USER_LEVEL_7,   /**< Describes the level that allows to access prompter concepts with user level 7 */
    NUANCE_PROMPTER_USER_LEVEL_8,   /**< Describes the level that allows to access prompter concepts with user level 8 */
    NUANCE_PROMPTER_USER_LEVEL_9,   /**< Describes the level that allows to access prompter concepts with user level 9 */
    NUANCE_PROMPTER_USER_LEVEL_10,  /**< Describes the level that allows to access prompter concepts with user level 10 */
    NUANCE_PROMPTER_USER_LEVEL_11,  /**< Describes the level that allows to access prompter concepts with user level 11 */
    NUANCE_PROMPTER_USER_LEVEL_12,  /**< Describes the level that allows to access prompter concepts with user level 12 */
    NUANCE_PROMPTER_USER_LEVEL_13,  /**< Describes the level that allows to access prompter concepts with user level 13 */
    NUANCE_PROMPTER_USER_LEVEL_14,  /**< Describes the level that allows to access prompter concepts with user level 14 */
    NUANCE_PROMPTER_USER_LEVEL_15,  /**< Describes the level that allows to access prompter concepts with user level 15 */
    NUANCE_PROMPTER_USER_LEVEL_16   /**< Describes the level that allows to access prompter concepts with user level 16 */
} nuance_prompter_UserLevel;

PROMPTER_C_EXPORT const LH_CHAR *nuance_prompter_UserLevel_toString(nuance_prompter_UserLevel enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_USERLEVEL_H */

/** @} */
/** @} */

