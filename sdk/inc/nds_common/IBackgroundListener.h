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
 *  Declaration of nuance_common_IBackgroundListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IBackgroundListener
 *  @{
 *  @file IBackgroundListener.h
 *
 *  @brief  Callback interface of a background operation. <p>
 */

#ifndef NUANCE_COMMON_IBACKGROUNDLISTENER_H
#define NUANCE_COMMON_IBACKGROUNDLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Callback interface of a background operation. <p>
 */
struct _nuance_common_IBackgroundListener;
/**
 *  @brief  Callback interface of a background operation. <p>
 */
typedef struct _nuance_common_IBackgroundListener nuance_common_IBackgroundListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "IBackgroundOperation.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  This function is called when an asynchronous waitForCompletion at the
 *  IBackgroundOperation interface is finished. This can be either due to
 *  all operations are completed or due to a timeout.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     status   The state of the background operation, either RUNNING (if returned due to timeout), COMPLETED (on success), FAILED (on error) or FAILED_FATAL (on fatal error)
 */
typedef void (*FUNC_nuance_common_IBackgroundListener_onWaitFinished)
(
    void *instance,
    nuance_common_IBackgroundOperation_Status status
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Callback interface of a background operation. <p>
 */
struct _vtable_nuance_common_IBackgroundListener
{
    /**
     *  This function is called when an asynchronous waitForCompletion at the
     *  IBackgroundOperation interface is finished. This can be either due to
     *  all operations are completed or due to a timeout.
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     status   The state of the background operation, either RUNNING (if returned due to timeout), COMPLETED (on success), FAILED (on error) or FAILED_FATAL (on fatal error)
     */
    FUNC_nuance_common_IBackgroundListener_onWaitFinished onWaitFinished;

};
/**
 *  @brief  Callback interface of a background operation. <p>
 */
typedef struct _vtable_nuance_common_IBackgroundListener vtable_nuance_common_IBackgroundListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
COMMON_C_EXPORT nuance_common_IBackgroundListener *nuance_common_IBackgroundListener_create
(
    const vtable_nuance_common_IBackgroundListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_IBackgroundListener_destroy(nuance_common_IBackgroundListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IBACKGROUNDLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
