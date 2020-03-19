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
 *  Declaration of nuance_common_IBackgroundOperation class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IBackgroundOperation
 *  @{
 *  @file IBackgroundOperation.h
 *
 *  @brief  Interface to control background operations. <p>
 *
 *  All classes which use an internal worker thread to perform long-running
 *  operations implement this interface, for instance:
 *
 *  - nuance::prompter::IPrompt: plays a prompt using the Text to Speech engine
 *  - nuance::cloudservices::ICloudCommand: sends a cloud command to NCS
 *  - nuance::asr::IDynamicContentConsumer: runs a G2P process on dynamic vocabulary
 *
 *  The methods of the IBackgroundOperation interface can be used to control the
 *  background operation, e.g. get its status, abort it, or wait until it is finished.
 */

#ifndef NUANCE_COMMON_IBACKGROUNDOPERATION_H
#define NUANCE_COMMON_IBACKGROUNDOPERATION_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare inner types of class ************************************************************************************/

/**
 *  Status of the background operation
 */
typedef enum
{
    NUANCE_COMMON_IBACKGROUNDOPERATION_RUNNING,       /**< Background operation is running */
    NUANCE_COMMON_IBACKGROUNDOPERATION_ABORTING,      /**< Background operation has been aborted, state will switch to ABORTED soon */
    NUANCE_COMMON_IBACKGROUNDOPERATION_COMPLETED,     /**< Background operation was completed */
    NUANCE_COMMON_IBACKGROUNDOPERATION_ABORTED,       /**< Background operation has been aborted */
    NUANCE_COMMON_IBACKGROUNDOPERATION_FAILED,        /**< Background operation failed */
    NUANCE_COMMON_IBACKGROUNDOPERATION_FAILED_FATAL   /**< Background operation failed with a fatal error. Component has to be restarted. */
} nuance_common_IBackgroundOperation_Status;


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface to control background operations. <p>
 *
 *  All classes which use an internal worker thread to perform long-running
 *  operations implement this interface, for instance:
 *
 *  - nuance::prompter::IPrompt: plays a prompt using the Text to Speech engine
 *  - nuance::cloudservices::ICloudCommand: sends a cloud command to NCS
 *  - nuance::asr::IDynamicContentConsumer: runs a G2P process on dynamic vocabulary
 *
 *  The methods of the IBackgroundOperation interface can be used to control the
 *  background operation, e.g. get its status, abort it, or wait until it is finished.
 */
struct _nuance_common_IBackgroundOperation;
/**
 *  @brief  Interface to control background operations. <p>
 *
 *  All classes which use an internal worker thread to perform long-running
 *  operations implement this interface, for instance:
 *
 *  - nuance::prompter::IPrompt: plays a prompt using the Text to Speech engine
 *  - nuance::cloudservices::ICloudCommand: sends a cloud command to NCS
 *  - nuance::asr::IDynamicContentConsumer: runs a G2P process on dynamic vocabulary
 *
 *  The methods of the IBackgroundOperation interface can be used to control the
 *  background operation, e.g. get its status, abort it, or wait until it is finished.
 */
typedef struct _nuance_common_IBackgroundOperation nuance_common_IBackgroundOperation;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "IBackgroundListener.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IBackgroundOperation_getStatus
(
    nuance_common_IBackgroundOperation *instance,
    nuance_common_IBackgroundOperation_Status *status
);


/**
 *  Waits until the background operation is finished.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), this method waits until all operations which are in the
 *  queue finish or until timeout expires, providing the timeout value is positive. If timeout value is
 *  negative or 0 (undefined) then it waits until all operations finish.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     timeout   Timeout in milliseconds after which the method should return even if the background operation is not yet finished
 *  @param[out]    status    The state of the background operation, either RUNNING (if returned due to timeout), COMPLETED (on success), FAILED (on error) or FAILED_FATAL (on fatal error)
 *
 *  @return The result code of the execution
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IBackgroundOperation_waitForCompletionWithTimeout
(
    nuance_common_IBackgroundOperation *instance,
    LH_S32 timeout,
    nuance_common_IBackgroundOperation_Status *status
);


/**
 *  Waits until the background operation is finished.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), this method waits until all operations are
 *  finished, which are in the queue when waitForCompletion() was called.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   The state of the background operation, either COMPLETED (on success), FAILED (on error) or FAILED_FATAL (on fatal error)
 *
 *  @return Result code
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IBackgroundOperation_waitForCompletion
(
    nuance_common_IBackgroundOperation *instance,
    nuance_common_IBackgroundOperation_Status *status
);


/**
 *  Returns directly and triggers an internal wait for the background operation to finish.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), the listener is called once all operations are finished that were in the
 *  queue when waitForCompletion() was called.
 *
 *  Note: This method is intended for DragonDriveFramework use only.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     listener   An IBackgroundListener instance.
 *
 *  @return Result code
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IBackgroundOperation_waitForCompletionAsync
(
    nuance_common_IBackgroundOperation *instance,
    nuance_common_IBackgroundListener *listener
);


/**
 *  Returns directly and triggers an internal wait for the background operation to finish.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), the listener is called once all operations are finished or the timeout expired.
 *  If the timeout value is negative or 0 (undefined) it waits until all operations are finished.
 *
 *  Note: This method is intended for DragonDriveFramework use only.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     timeout    Timeout in milliseconds after which the method should return even if the background operation is not yet finished
 *  @param[in]     listener   An IBackgroundListener instance.
 *
 *  @return The result code of the execution
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IBackgroundOperation_waitForCompletionWithTimeoutAsync
(
    nuance_common_IBackgroundOperation *instance,
    LH_S32 timeout,
    nuance_common_IBackgroundListener *listener
);


/**
 *  Aborts the current background operation, if other tasks are queued these are removed, too.
 *  The worker thread status is switched to ABORTING and the method returns immediately.
 *  If there's no active background operation, this method does nothing.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Result code
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IBackgroundOperation_abortOperation(nuance_common_IBackgroundOperation *instance);


/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_IBackgroundOperation_destroy(nuance_common_IBackgroundOperation *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IBACKGROUNDOPERATION_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
