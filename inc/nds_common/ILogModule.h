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
 *  Declaration of nuance_common_ILogModule class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup ILogModule
 *  @{
 *  @file ILogModule.h
 *
 *  @brief  Log module that defines the producer of external log messages.<p>
 *  The log module can be used to filter log messages via the Logger JSON configuration.
 */

#ifndef NUANCE_COMMON_ILOGMODULE_H
#define NUANCE_COMMON_ILOGMODULE_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Log module that defines the producer of external log messages.<p>
 *  The log module can be used to filter log messages via the Logger JSON configuration.
 */
struct _nuance_common_ILogModule;
/**
 *  @brief  Log module that defines the producer of external log messages.<p>
 *  The log module can be used to filter log messages via the Logger JSON configuration.
 */
typedef struct _nuance_common_ILogModule nuance_common_ILogModule;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Returns the associated name of this log module object.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[out]    moduleName   The name of the log module.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ILogModule_getName
(
    const nuance_common_ILogModule *instance,
    nuance_common_String **moduleName
);


/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_ILogModule_destroy(nuance_common_ILogModule *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_ILOGMODULE_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
