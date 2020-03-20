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
 *  Declaration of nuance_cloudservices_ICloudDataUpload class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudDataUpload
 *  @{
 *  @file ICloudDataUpload.h
 *
 *  @brief  Interface of 'CloudDataUpload'. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOAD_H
#define NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOAD_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of 'CloudDataUpload'. <p>
 */
struct _nuance_cloudservices_ICloudDataUpload;
/**
 *  @brief  Interface of 'CloudDataUpload'. <p>
 */
typedef struct _nuance_cloudservices_ICloudDataUpload nuance_cloudservices_ICloudDataUpload;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "IBackgroundListener.h"
#include "IBackgroundOperation.h"
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUpload_getStatus
(
    nuance_cloudservices_ICloudDataUpload *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUpload_waitForCompletionWithTimeout
(
    nuance_cloudservices_ICloudDataUpload *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUpload_waitForCompletion
(
    nuance_cloudservices_ICloudDataUpload *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUpload_waitForCompletionAsync
(
    nuance_cloudservices_ICloudDataUpload *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUpload_waitForCompletionWithTimeoutAsync
(
    nuance_cloudservices_ICloudDataUpload *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUpload_abortOperation(nuance_cloudservices_ICloudDataUpload *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudDataUpload_destroy(nuance_cloudservices_ICloudDataUpload *);


CLOUDSERVICES_C_EXPORT nuance_common_IBackgroundOperation *nuance_cloudservices_ICloudDataUpload_as_nuance_common_IBackgroundOperation(nuance_cloudservices_ICloudDataUpload *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOAD_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
