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
 *  Declaration of nuance_common_ITimerListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup ITimerListener
 *  @{
 *  @file ITimerListener.h
 *
 *  @brief  Listener interface to receive events from the timer. <p>
 */

#ifndef NUANCE_COMMON_ITIMERLISTENER_H
#define NUANCE_COMMON_ITIMERLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Listener interface to receive events from the timer. <p>
 */
struct _nuance_common_ITimerListener;
/**
 *  @brief  Listener interface to receive events from the timer. <p>
 */
typedef struct _nuance_common_ITimerListener nuance_common_ITimerListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "ITimer.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief  The timeout of the timer is elapsed. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     timer   The timer object that is elapsed.
 */
typedef void (*FUNC_nuance_common_ITimerListener_onTimeout)
(
    void *instance,
    nuance_common_ITimer *timer
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Listener interface to receive events from the timer. <p>
 */
struct _vtable_nuance_common_ITimerListener
{
    /**
     *  @brief  The timeout of the timer is elapsed. <p>
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     timer   The timer object that is elapsed.
     */
    FUNC_nuance_common_ITimerListener_onTimeout onTimeout;

};
/**
 *  @brief  Listener interface to receive events from the timer. <p>
 */
typedef struct _vtable_nuance_common_ITimerListener vtable_nuance_common_ITimerListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
COMMON_C_EXPORT nuance_common_ITimerListener *nuance_common_ITimerListener_create
(
    const vtable_nuance_common_ITimerListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_ITimerListener_destroy(nuance_common_ITimerListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_ITIMERLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
