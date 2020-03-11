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
 *  Declaration of nuance_cloudservices_ICloudCommand class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudCommand
 *  @{
 *  @file ICloudCommand.h
 *
 *  @brief  Interface of ICloudCommand. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDCOMMAND_H
#define NUANCE_CLOUDSERVICES_ICLOUDCOMMAND_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of ICloudCommand. <p>
 */
struct _nuance_cloudservices_ICloudCommand;
/**
 *  @brief  Interface of ICloudCommand. <p>
 */
typedef struct _nuance_cloudservices_ICloudCommand nuance_cloudservices_ICloudCommand;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "ByteArray.h"
#include "IBackgroundListener.h"
#include "IBackgroundOperation.h"
#include "IDictionary.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  Adds a Bytes parameter to the command. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Parameter key, cannot be empty.
 *  @param[in]     data   The byte array data.
 *  @param[in]     ndata  Number of elements in data
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_addBytesParam
(
    nuance_cloudservices_ICloudCommand *instance,
    const LH_CHAR *key,
    LH_S8  const *data, LH_S32 ndata
);


/**
 *  @brief  Adds a String parameter to the command. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Parameter key, cannot be empty.
 *  @param[in]     data   The string.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_addStringParam
(
    nuance_cloudservices_ICloudCommand *instance,
    const LH_CHAR *key,
    const LH_CHAR *data
);


/**
 *  @brief  Adds a Dictionary parameter to the command. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Parameter key, cannot be empty.
 *  @param[in]     data   The dictionary.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_addDictionaryParam
(
    nuance_cloudservices_ICloudCommand *instance,
    const LH_CHAR *key,
    const nuance_common_IDictionary *data
);


/**
 *  @brief  Adds a Sequence Start parameter to the command. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Parameter key, cannot be empty.
 *  @param[in]     data   The sequence data.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_addSequenceStartParam
(
    nuance_cloudservices_ICloudCommand *instance,
    const LH_CHAR *key,
    const nuance_common_IDictionary *data
);


/**
 *  @brief  Adds a Sequence Chunk parameter to the command. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Parameter key, cannot be empty.
 *  @param[in]     data   The sequence data.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_addSequenceChunkParam
(
    nuance_cloudservices_ICloudCommand *instance,
    const LH_CHAR *key,
    const nuance_common_IDictionary *data
);


/**
 *  @brief  Adds a Sequence End parameter to the command. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Parameter key, cannot be empty.
 *  @param[in]     data   The sequence data.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_addSequenceEndParam
(
    nuance_cloudservices_ICloudCommand *instance,
    const LH_CHAR *key,
    const nuance_common_IDictionary *data
);


/**
 *  @brief  Adds a Audio parameter to the command. <p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     key       Parameter key, cannot be empty.
 *  @param[in]     padName   The name of the audio pad.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_addAudioParam
(
    nuance_cloudservices_ICloudCommand *instance,
    const LH_CHAR *key,
    const LH_CHAR *padName
);


/**
 *  @brief  Adds a TTS parameter to the command. <p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     key       Parameter key, cannot be empty.
 *  @param[in]     padName   String defining the pad-name.
 *  @param[in]     data      The Dictionary describing the TTS-request.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_addTtsParam
(
    nuance_cloudservices_ICloudCommand *instance,
    const LH_CHAR *key,
    const LH_CHAR *padName,
    const nuance_common_IDictionary *data
);


/**
 *  @brief  Finishes the command. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_finish(nuance_cloudservices_ICloudCommand *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_getStatus
(
    nuance_cloudservices_ICloudCommand *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_waitForCompletionWithTimeout
(
    nuance_cloudservices_ICloudCommand *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_waitForCompletion
(
    nuance_cloudservices_ICloudCommand *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_waitForCompletionAsync
(
    nuance_cloudservices_ICloudCommand *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_waitForCompletionWithTimeoutAsync
(
    nuance_cloudservices_ICloudCommand *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudCommand_abortOperation(nuance_cloudservices_ICloudCommand *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudCommand_destroy(nuance_cloudservices_ICloudCommand *);


CLOUDSERVICES_C_EXPORT nuance_common_IBackgroundOperation *nuance_cloudservices_ICloudCommand_as_nuance_common_IBackgroundOperation(nuance_cloudservices_ICloudCommand *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDCOMMAND_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
