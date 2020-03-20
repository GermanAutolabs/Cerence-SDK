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
 *  Declaration of nuance_asr5_IDynamicContentConsumer class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5  nuance_asr5
 *  @{
 *  @addtogroup IDynamicContentConsumer
 *  @{
 *  @file IDynamicContentConsumer.h
 *
 *  @brief  Provides a consumer for complex, connected, and dynamic data used for ASR. <p>
 *
 *  The DynamicContentConsumer can be used to
 *  - load a precompiled database (e.g. with POIs)
 *  - upload data to a remote server
 *  - hold dynamic vocabulary entries, and create transcriptions using an automatic grapheme to phoneme
 *  engine (e.g. clc)
 */

#ifndef NUANCE_ASR5_IDYNAMICCONTENTCONSUMER_H
#define NUANCE_ASR5_IDYNAMICCONTENTCONSUMER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Provides a consumer for complex, connected, and dynamic data used for ASR. <p>
 *
 *  The DynamicContentConsumer can be used to
 *  - load a precompiled database (e.g. with POIs)
 *  - upload data to a remote server
 *  - hold dynamic vocabulary entries, and create transcriptions using an automatic grapheme to phoneme
 *  engine (e.g. clc)
 */
struct _nuance_asr5_IDynamicContentConsumer;
/**
 *  @brief  Provides a consumer for complex, connected, and dynamic data used for ASR. <p>
 *
 *  The DynamicContentConsumer can be used to
 *  - load a precompiled database (e.g. with POIs)
 *  - upload data to a remote server
 *  - hold dynamic vocabulary entries, and create transcriptions using an automatic grapheme to phoneme
 *  engine (e.g. clc)
 */
typedef struct _nuance_asr5_IDynamicContentConsumer nuance_asr5_IDynamicContentConsumer;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "asr5_api_defs.h"

/* API types */
#include "IAsrManager.h"
#include "IBackgroundListener.h"
#include "IBackgroundOperation.h"
#include "IContentValuesIterator.h"
#include "IDynamicContentConsumerListener.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief create a DynamicContentConsumer<p>
 *  Creates a new DynamicContentConsumer instance. Each consumer gets an unique name.
 *
 *  @param[in]     asr5Manager              the asr manager object
 *  @param[in]     name                     name of the DynamicContentConsumer
 *  @param[in]     listener                 an \ref IDynamicContentConsumerListener implementation which is used to report errors and warnings of the DynamicContentConsumer object.
 *  @param[out]    dynamicContentConsumer   the new \ref IDynamicContentConsumer object
 *
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_create
(
    nuance_asr5_IAsrManager *asr5Manager,
    const LH_CHAR *name,
    nuance_asr5_IDynamicContentConsumerListener *listener,
    nuance_asr5_IDynamicContentConsumer **dynamicContentConsumer
);


/**
 *  @brief create a DynamicContentConsumer<p>
 *  Creates a new DynamicContentConsumer instance. Each consumer gets an unique name.
 *
 *  @param[in]     asr5Manager              the asr manager object
 *  @param[in]     name                     name of the DynamicContentConsumer
 *  @param[in]     fromSource               source of the DynamicContentConsumer
 *  @param[in]     listener                 an \ref IDynamicContentConsumerListener implementation which is used to report errors and warnings of the DynamicContentConsumer object.
 *  @param[out]    dynamicContentConsumer   the new \ref IDynamicContentConsumer object
 *
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_createFromSource
(
    nuance_asr5_IAsrManager *asr5Manager,
    const LH_CHAR *name,
    const LH_CHAR *fromSource,
    nuance_asr5_IDynamicContentConsumerListener *listener,
    nuance_asr5_IDynamicContentConsumer **dynamicContentConsumer
);


/**
 *  @brief  Start data preperation<p>
 *
 *  Starts data preparation in a worker thread. Each dynamic content consumer uses a separate
 *  worker thread.
 *
 *  All applications that use data from this dynamic content consumer will only finish to be created
 *  when the dynamic content consumer is finished preparing its data. This synchronization
 *  happens inside vocon high, there is no need to explicitly call IDynamicContentConsumer::waitForCompletion().
 *
 *  Keep in mind that the online grapheme to phoneme conversion might take a lot of time to complete, especially on
 *  a large number of entries.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     iterator   A set of callbacks that vocon high uses to retrieve all content.
 *
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_startDataPreparation
(
    nuance_asr5_IDynamicContentConsumer *instance,
    nuance_asr5_IContentValuesIterator *iterator
);


/**
 *  @brief  Start data preperation from cop file<p>
 *
 *  Starts data preparation in a worker thread. Each dynamic content consumer uses a separate
 *  worker thread.
 *  \n
 *  All applications that use data from this dynamic content consumer will only finish to be created
 *  when the dynamic content consumer is finished preparing its data. This synchronization
 *  happens inside vocon high, there is no need to explicitly call IDynamicContentConsumer::waitForCompletion().
 *
 *  \n
 *  Keep in mind that the online grapheme to phoneme conversion might take a lot of time to complete, especially on
 *  a large number of entries.
 *
 *  @param[in,out] instance      The instance pointer
 *  @param[in]     cOPFilePath   path to the COP file
 *
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_startDataPreparationFromCopFile
(
    nuance_asr5_IDynamicContentConsumer *instance,
    const LH_CHAR *cOPFilePath
);


/**
 *  @brief  Start data preperation from iterator implemented by 3rd party dll<p>
 *
 *  Starts data preparation in a worker thread. Each dynamic content consumer uses a separate
 *  worker thread.
 *
 *  All applications that use data from this dynamic content consumer will only finish to be created
 *  when the dynamic content consumer is finished preparing its data. This synchronization
 *  happens inside vocon high, there is no need to explicitly call IDynamicContentConsumer::waitForCompletion().
 *
 *  Keep in mind that the online grapheme to phoneme conversion might take a lot of time to complete, especially on
 *  a large number of entries.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     pluginName   plugin dll name
 *
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_startDataPreparationFromPlugin
(
    nuance_asr5_IDynamicContentConsumer *instance,
    const LH_CHAR *pluginName
);


/**
 *  Delete all content from this dynamic content consumer
 *
 *  Note: for the remote
 *  case it will delete all content for the list with the name of this content
 *  provider (i.e. passed when calling IRecognizer::createDynamicContentConsumer().
 *  A checksum will be forwarded to the application through the DCC_DATA_ID event.
 *  This checksum has to be passed to the iterator during the next data upload operation.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_deleteAll(nuance_asr5_IDynamicContentConsumer *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_getStatus
(
    nuance_asr5_IDynamicContentConsumer *instance,
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
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_waitForCompletionWithTimeout
(
    nuance_asr5_IDynamicContentConsumer *instance,
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
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_waitForCompletion
(
    nuance_asr5_IDynamicContentConsumer *instance,
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
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_waitForCompletionAsync
(
    nuance_asr5_IDynamicContentConsumer *instance,
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
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_waitForCompletionWithTimeoutAsync
(
    nuance_asr5_IDynamicContentConsumer *instance,
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
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IDynamicContentConsumer_abortOperation(nuance_asr5_IDynamicContentConsumer *instance);


/**
 *  Destructor
 */
ASR5_C_EXPORT void nuance_asr5_IDynamicContentConsumer_destroy(nuance_asr5_IDynamicContentConsumer *);


ASR5_C_EXPORT nuance_common_IBackgroundOperation *nuance_asr5_IDynamicContentConsumer_as_nuance_common_IBackgroundOperation(nuance_asr5_IDynamicContentConsumer *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_IDYNAMICCONTENTCONSUMER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
