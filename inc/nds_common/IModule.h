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
 *  Declaration of nuance_common_IModule class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IModule
 *  @{
 *  @file IModule.h
 *
 *  @brief
 *  Common user interface of all SDK modules.
 *
 *  It contains all interface methods that have to be supported by all SDK modules.
 *
 *  The specific module user interface returned at creation of a specific SDK module
 *  has to be derived from this common user interface.
 *
 *  <p>
 */

#ifndef NUANCE_COMMON_IMODULE_H
#define NUANCE_COMMON_IMODULE_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief
 *  Common user interface of all SDK modules.
 *
 *  It contains all interface methods that have to be supported by all SDK modules.
 *
 *  The specific module user interface returned at creation of a specific SDK module
 *  has to be derived from this common user interface.
 *
 *  <p>
 */
struct _nuance_common_IModule;
/**
 *  @brief
 *  Common user interface of all SDK modules.
 *
 *  It contains all interface methods that have to be supported by all SDK modules.
 *
 *  The specific module user interface returned at creation of a specific SDK module
 *  has to be derived from this common user interface.
 *
 *  <p>
 */
typedef struct _nuance_common_IModule nuance_common_IModule;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "IBackgroundListener.h"
#include "IBackgroundOperation.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  Returns the instance name of this SDK module. <p>
 *
 *  The instance name is given as parameter to the create call of this SDK module.
 *  The name has to be unambiguous as it is used as identifier of this SDK module instance.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Name of this SDK module instance.
 */
COMMON_C_EXPORT nuance_common_String *nuance_common_IModule_getName(const nuance_common_IModule *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IModule_getStatus
(
    nuance_common_IModule *instance,
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
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IModule_waitForCompletionWithTimeout
(
    nuance_common_IModule *instance,
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
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IModule_waitForCompletion
(
    nuance_common_IModule *instance,
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
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IModule_waitForCompletionAsync
(
    nuance_common_IModule *instance,
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
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IModule_waitForCompletionWithTimeoutAsync
(
    nuance_common_IModule *instance,
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
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IModule_abortOperation(nuance_common_IModule *instance);


/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_IModule_destroy(nuance_common_IModule *);


COMMON_C_EXPORT nuance_common_IBackgroundOperation *nuance_common_IModule_as_nuance_common_IBackgroundOperation(nuance_common_IModule *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IMODULE_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
