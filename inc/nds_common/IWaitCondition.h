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
 *  Declaration of nuance_common_IWaitCondition class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IWaitCondition
 *  @{
 *  @file IWaitCondition.h
 *
 *  @brief  wait condition which can be used to sync multiple threads to one single event.<p>
 */

#ifndef NUANCE_COMMON_IWAITCONDITION_H
#define NUANCE_COMMON_IWAITCONDITION_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  wait condition which can be used to sync multiple threads to one single event.<p>
 */
struct _nuance_common_IWaitCondition;
/**
 *  @brief  wait condition which can be used to sync multiple threads to one single event.<p>
 */
typedef struct _nuance_common_IWaitCondition nuance_common_IWaitCondition;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  Static method that creates and returns new instance of the object implementing this interface.
 *  The wait condition will be locked after creation.
 *
 *  @param[out]    waitCondition   Output parameter returning the new instance of the object
 *
 *  @return the result code of the execution.
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IWaitCondition_create(nuance_common_IWaitCondition **waitCondition);


/**
 *  If the wait condition is locked, this method blocks until another thread calls the unlock() method.
 *  On a unlocked wait condition this method returns immediately.
 *
 *  @param[in,out] instance The instance pointer
 */
COMMON_C_EXPORT void nuance_common_IWaitCondition_waitWithoutTimeOut(nuance_common_IWaitCondition *instance);


/**
 *  If the wait condition is locked, this method blocks until another thread calls the unlock() method.
 *  On a unlocked wait condition this method returns immediately.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     timeout   timeout if a value > 0 (in milliseconds) is passed to this parameter, the wait unblocks after this time
 *
 *  @return false, if the timeout was reached; true, if wait() was unblocked due to unlock() or wakeAll() call.
 */
COMMON_C_EXPORT LH_BOOL nuance_common_IWaitCondition_waitWithTimeOut
(
    nuance_common_IWaitCondition *instance,
    LH_S32 timeout
);


/**
 *  All threads which are blocked in the wait() method are unblocked.
 *  The wait condition is marked as unlocked, i.e. all further wait() calls will not block.
 *
 *  @param[in,out] instance The instance pointer
 */
COMMON_C_EXPORT void nuance_common_IWaitCondition_unlock(nuance_common_IWaitCondition *instance);


/**
 *  Locks the wait condition. All subsequent wait() calls are blocking.
 *  Calling this method on an already locked WaitCondition has no effect.
 *
 *  @param[in,out] instance The instance pointer
 */
COMMON_C_EXPORT void nuance_common_IWaitCondition_lock(nuance_common_IWaitCondition *instance);


/**
 *  Unblocks all threads which are blocked in the wait() method.
 *  In contrast to unlock() the wait condition remains locked,
 *  all subsequent wait() calls are blocking.
 *
 *  @param[in,out] instance The instance pointer
 */
COMMON_C_EXPORT void nuance_common_IWaitCondition_wakeAll(nuance_common_IWaitCondition *instance);


/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_IWaitCondition_destroy(nuance_common_IWaitCondition *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IWAITCONDITION_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
