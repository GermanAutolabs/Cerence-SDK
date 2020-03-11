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
 *  Declaration of nuance_common_ITimer class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup ITimer
 *  @{
 *  @file ITimer.h
 *
 *  @brief  This class provides an interface to start and stop a timer. <p>
 */

#ifndef NUANCE_COMMON_ITIMER_H
#define NUANCE_COMMON_ITIMER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  This class provides an interface to start and stop a timer. <p>
 */
struct _nuance_common_ITimer;
/**
 *  @brief  This class provides an interface to start and stop a timer. <p>
 */
typedef struct _nuance_common_ITimer nuance_common_ITimer;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "ITimerListener.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  Start the timer. <p>
 *
 *  This method starts the timer with the given timeout (in milliseconds).
 *  After the timeout is elapsed, the onTimeout event of the ITimerListener will be called.
 *  If a timer was already started on this ITimer instance then ERROR will be returned.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     timeout    Timeout value of the timer.
 *  @param[in]     listener   a \ref ITimerListener object
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ITimer_start
(
    nuance_common_ITimer *instance,
    LH_S32 timeout,
    nuance_common_ITimerListener *listener
);


/**
 *  @brief  Stop the timer. <p>
 *
 *  This method stops the timer.
 *  Applications can stop the timer with this method if waiting for the onTimeout event is no longer needed,
 *  because another event occured before the timer elapsed.
 *  If no timer was started on this ITimer instance then ERROR will be returned.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ITimer_stop(nuance_common_ITimer *instance);


/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_ITimer_destroy(nuance_common_ITimer *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_ITIMER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
