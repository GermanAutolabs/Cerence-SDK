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
 *  Declaration of nuance_common_IManager class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IManager
 *  @{
 *  @file IManager.h
 *
 *  @brief
 *  Common user interface of all NDS managers.
 *
 *  It contains all interface methods that have to be supported by all NDS managers.
 *
 *  The specific manager user interface returned at creation of a specific NDS manager
 *  has to be derived from this common interface.
 *
 *  <p>
 */

#ifndef NUANCE_COMMON_IMANAGER_H
#define NUANCE_COMMON_IMANAGER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief
 *  Common user interface of all NDS managers.
 *
 *  It contains all interface methods that have to be supported by all NDS managers.
 *
 *  The specific manager user interface returned at creation of a specific NDS manager
 *  has to be derived from this common interface.
 *
 *  <p>
 */
struct _nuance_common_IManager;
/**
 *  @brief
 *  Common user interface of all NDS managers.
 *
 *  It contains all interface methods that have to be supported by all NDS managers.
 *
 *  The specific manager user interface returned at creation of a specific NDS manager
 *  has to be derived from this common interface.
 *
 *  <p>
 */
typedef struct _nuance_common_IManager nuance_common_IManager;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  Returns the type of this NDS manager instance. <p>
 *
 *  Only one manager of a certain type can be registered at the SystemManager at
 *  a time.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Type of this NDS manager instance.
 */
COMMON_C_EXPORT nuance_common_String *nuance_common_IManager_getType(const nuance_common_IManager *instance);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IMANAGER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
