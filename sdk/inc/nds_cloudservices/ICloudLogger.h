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
 *  Declaration of nuance_cloudservices_ICloudLogger class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudLogger
 *  @{
 *  @file ICloudLogger.h
 *
 *  @brief  Interface of the 'CloudLogger' module.<p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDLOGGER_H
#define NUANCE_CLOUDSERVICES_ICLOUDLOGGER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'CloudLogger' module.<p>
 */
struct _nuance_cloudservices_ICloudLogger;
/**
 *  @brief  Interface of the 'CloudLogger' module.<p>
 */
typedef struct _nuance_cloudservices_ICloudLogger nuance_cloudservices_ICloudLogger;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "ICloudLoggerListener.h"
#include "ICloudManager.h"
#include "IConfiguration.h"
#include "IDictionary.h"
#include "IModule.h"
#include "IModuleListener.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates a 'CloudLogger' module instance.
 *
 *  @param[in]     name               Name of the module instance to be created.
 *  @param[in]     cloudManager       Cloud manager instance
 *  @param[in]     config             Configuration object.
 *  @param[in]     moduleListener     Listener that is informed about module changes (e.g creation finished)
 *  @param[in]     registerConsumer   Register a log consumer at the common::Logger to receive log messages.
 *  @param[out]    cloudLogger        User interface of the created cloud logger module.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudLogger_create
(
    const LH_CHAR *name,
    nuance_cloudservices_ICloudManager *cloudManager,
    const nuance_common_IConfiguration *config,
    nuance_common_IModuleListener *moduleListener,
    LH_BOOL registerConsumer,
    nuance_cloudservices_ICloudLogger **cloudLogger
);


/**
 *  @brief  Queue a string log into the CloudLogger. <p>
 *  This function allows the user to queue a log into the CloudLogger.
 *  The log is created from the String parameter and will be held in a queue until the user calls the send function.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     text   A string to log to the server
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudLogger_log
(
    nuance_cloudservices_ICloudLogger *instance,
    const LH_CHAR *text
);


/**
 *  @brief  Sends the queued logs to the server. <p>
 *  This function allows the user to start sending logs to the server. All logs currently contained
 *  in the queue will be matched with the same application session id.
 *  Once the command is completed, a callback in the ICloudLoggerListener will be triggered if there is a success or error.
 *
 *  @param[in,out] instance           The instance pointer
 *  @param[in]     listener           The cloud logger listener.
 *  @param[in]     optionalSettings   The optional settings dictionary.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudLogger_send
(
    nuance_cloudservices_ICloudLogger *instance,
    nuance_cloudservices_ICloudLoggerListener *listener,
    nuance_common_IDictionary *optionalSettings
);


/**
 *  @brief  Discards all queued logs. <p>
 *  This function allows the user to discard all the logs in the CloudLogger queue.
 *  All the logs will be deleted and not sent to the server.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudLogger_discard(nuance_cloudservices_ICloudLogger *instance);


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
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudLogger_getName(const nuance_cloudservices_ICloudLogger *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudLogger_getStatus
(
    nuance_cloudservices_ICloudLogger *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudLogger_waitForCompletionWithTimeout
(
    nuance_cloudservices_ICloudLogger *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudLogger_waitForCompletion
(
    nuance_cloudservices_ICloudLogger *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudLogger_waitForCompletionAsync
(
    nuance_cloudservices_ICloudLogger *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudLogger_waitForCompletionWithTimeoutAsync
(
    nuance_cloudservices_ICloudLogger *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudLogger_abortOperation(nuance_cloudservices_ICloudLogger *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudLogger_destroy(nuance_cloudservices_ICloudLogger *);


CLOUDSERVICES_C_EXPORT nuance_common_IModule *nuance_cloudservices_ICloudLogger_as_nuance_common_IModule(nuance_cloudservices_ICloudLogger *obj);

CLOUDSERVICES_C_EXPORT nuance_common_IBackgroundOperation *nuance_cloudservices_ICloudLogger_as_nuance_common_IBackgroundOperation(nuance_cloudservices_ICloudLogger *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDLOGGER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
