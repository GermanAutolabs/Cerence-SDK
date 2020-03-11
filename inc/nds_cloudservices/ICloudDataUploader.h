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
 *  Declaration of nuance_cloudservices_ICloudDataUploader class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudDataUploader
 *  @{
 *  @file ICloudDataUploader.h
 *
 *  @brief  Interface of the 'CloudDataUploader' module.<p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADER_H
#define NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare inner types of class ************************************************************************************/

/**
 *  @brief  Defines data upload action. <p>
 *
 *  This enumeration represents the actions which are passed into 'uploadData' as parameter.
 */
typedef enum
{
    NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADER_UPLOAD_ACTION_ADD,             /**< Adds all data content to server. */
    NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADER_UPLOAD_ACTION_REMOVE,          /**< Removes all specified data content from server */
    NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADER_UPLOAD_ACTION_UPDATE,          /**< Update the content corresponding to content id, only available when type is 'structured_content' */
    NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADER_UPLOAD_ACTION_CLEAR_THEN_ADD,  /**< Clears the content server already has for that data type and grammar Id then adds all data content to server. This enum should be used when the server asks the device to re-upload data because of checksum mismatch. */
    NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADER_UPLOAD_ACTION_CLEAR_ID         /**< Clears the content of a specific grammar ID. */
} nuance_cloudservices_ICloudDataUploader_DataUploadAction;


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'CloudDataUploader' module.<p>
 */
struct _nuance_cloudservices_ICloudDataUploader;
/**
 *  @brief  Interface of the 'CloudDataUploader' module.<p>
 */
typedef struct _nuance_cloudservices_ICloudDataUploader nuance_cloudservices_ICloudDataUploader;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "CloudData.h"
#include "ICloudDataReset.h"
#include "ICloudDataResetListener.h"
#include "ICloudDataUpload.h"
#include "ICloudDataUploadListener.h"
#include "ICloudManager.h"
#include "IConfiguration.h"
#include "IDictionary.h"
#include "IModule.h"
#include "IModuleListener.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates a 'CloudDataUploader' module instance.
 *
 *  @param[in]     name                Name of the module instance to be created.
 *  @param[in]     cloudManager        Cloud manager instance
 *  @param[in]     config              Configuration object.
 *  @param[in]     moduleListener      Listener that is informed about module changes (e.g creation finished)
 *  @param[out]    cloudDataUploader   User interface of the created cloud data uploader module.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUploader_create
(
    const LH_CHAR *name,
    nuance_cloudservices_ICloudManager *cloudManager,
    const nuance_common_IConfiguration *config,
    nuance_common_IModuleListener *moduleListener,
    nuance_cloudservices_ICloudDataUploader **cloudDataUploader
);


/**
 *  @brief  Uploads data to server. <p>
 *  It would create NVC or NCS 'CloudDataUpload' instance according to configuration first.
 *  It is used to upload specific client data for instance contacts, custom words, preferences etc. to server.
 *  The server will save the data and, for most grammar types, it will create a grammar from this data.
 *  The grammar could subsequently be used by the client to enhance speech recognition.
 *
 *  @param[in,out] instance           The instance pointer
 *  @param[in]     optionalSettings   the optional settings, it could be NULL.
 *  @param[in]     dataToUpload       The data to be uploaded
 *  @param[in]     ndataToUpload      Number of elements in dataToUpload
 *  @param[in]     dataAction         The action to be performed for the data content, e.g. 'add', 'remove' or 'clear_all'
 *  @param[in]     currentChecksum    The checksum from the previous data upload, which is currently on server.
 *  @param[in]     grammarId          The grammar ID relates to the data array.
 *  @param[in]     type               The type of the content, e.g. 'contacts', 'custom_words', 'history' or 'structured_content'
 *  @param[in]     category           It is necessary to give this parameter when type is 'structured_content'. For other type of data upload this parameter is ignored
 *  @param[in]     listener           The cloud data upload listener.
 *  @param[out]    cloudDataUpload    The created NVC/NCS cloud data upload instance.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUploader_uploadData
(
    nuance_cloudservices_ICloudDataUploader *instance,
    const nuance_common_IDictionary *optionalSettings,
    nuance_common_IDictionary * const *dataToUpload, LH_S32 ndataToUpload,
    nuance_cloudservices_ICloudDataUploader_DataUploadAction dataAction,
    const LH_CHAR *currentChecksum,
    const LH_CHAR *grammarId,
    const LH_CHAR *type,
    const LH_CHAR *category,
    nuance_cloudservices_ICloudDataUploadListener *listener,
    nuance_cloudservices_ICloudDataUpload **cloudDataUpload
);


/**
 *  @brief  Uploads data to server. <p>
 *  It would create a NDSP 'CloudDataUpload' instance according to configuration first.
 *  It is used to upload specific client data for instance literals and their canonical value.
 *  The server will save the data and the grammar could subsequently be used by the client to enhance speech recognition.
 *
 *  @param[in,out] instance           The instance pointer
 *  @param[in]     optionalSettings   the optional settings, it could be NULL.
 *  @param[in]     dataToUpload       The data to be uploaded
 *  @param[in]     ndataToUpload      Number of elements in dataToUpload
 *  @param[in]     dataAction         The action to be performed for the data content, e.g. 'add' or 'remove'
 *  @param[in]     listener           The cloud data upload listener.
 *  @param[out]    cloudDataUpload    The created NDSP cloud data upload instance.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUploader_uploadDataNdsp
(
    nuance_cloudservices_ICloudDataUploader *instance,
    const nuance_common_IDictionary *optionalSettings,
    nuance_common_IDictionary * const *dataToUpload, LH_S32 ndataToUpload,
    nuance_cloudservices_ICloudDataUploader_DataUploadAction dataAction,
    nuance_cloudservices_ICloudDataUploadListener *listener,
    nuance_cloudservices_ICloudDataUpload **cloudDataUpload
);


/**
 *  @brief  Uploads data to server. <p>
 *  It would create NVC or NCS 'CloudDataUpload' instance according to configuration first.
 *  It is used to upload specific client data for instance contacts, custom words, preferences etc. to server.
 *  The server will save the data and, for most grammar types, it will create a grammar from this data.
 *  The grammar could subsequently be used by the client to enhance speech recognition.
 *  This method requires a Options dictionary which requires the following keys:
 *  - currentChecksum : (String) The checksum from the previous data upload, which is currently on server.
 *  - grammarId : (String) The grammar ID relates to the data array.
 *  - type : (String) The type of the content, e.g. 'contacts', 'custom_words', 'history' or 'structured_content'.
 *  - category : (String) It is necessary to give this parameter when type is 'structured_content'. For other type of data upload this parameter is ignored.
 *  And the following optional key:
 *  - options : (Dictionary) A dictionary to add optional keys according to the NVC or NCS commands spec.
 *
 *  @param[in,out] instance           The instance pointer
 *  @param[in]     optionalSettings   the optional settings, it could be NULL.
 *  @param[in]     dataToUpload       The data to be uploaded
 *  @param[in]     ndataToUpload      Number of elements in dataToUpload
 *  @param[in]     dataAction         The action to be performed for the data content, e.g. 'add', 'remove' or 'clear_all'
 *  @param[in]     options            A dictionary containing options keys.
 *  @param[in]     listener           The cloud data upload listener.
 *  @param[out]    cloudDataUpload    The created NVC/NCS cloud data upload instance.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUploader_uploadDataUsingOptions
(
    nuance_cloudservices_ICloudDataUploader *instance,
    const nuance_common_IDictionary *optionalSettings,
    nuance_common_IDictionary * const *dataToUpload, LH_S32 ndataToUpload,
    nuance_cloudservices_ICloudDataUploader_DataUploadAction dataAction,
    const nuance_common_IDictionary *options,
    nuance_cloudservices_ICloudDataUploadListener *listener,
    nuance_cloudservices_ICloudDataUpload **cloudDataUpload
);


/**
 *  @brief  Wipes out entire user information (including uploaded data, generated grammars, etc.) from server. <p>
 *  It would create NVC or NCS 'CloudDataReset' instance according to configuration first.
 *
 *  @param[in,out] instance           The instance pointer
 *  @param[in]     optionalSettings   the optional settings, it could be NULL.
 *  @param[in]     listener           The cloud data reset listener.
 *  @param[out]    cloudDataReset     The created NVC/NCS cloud data reset instance.
 *
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUploader_resetUserInfo
(
    nuance_cloudservices_ICloudDataUploader *instance,
    const nuance_common_IDictionary *optionalSettings,
    nuance_cloudservices_ICloudDataResetListener *listener,
    nuance_cloudservices_ICloudDataReset **cloudDataReset
);


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
CLOUDSERVICES_C_EXPORT nuance_common_String *nuance_cloudservices_ICloudDataUploader_getName(const nuance_cloudservices_ICloudDataUploader *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUploader_getStatus
(
    nuance_cloudservices_ICloudDataUploader *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUploader_waitForCompletionWithTimeout
(
    nuance_cloudservices_ICloudDataUploader *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUploader_waitForCompletion
(
    nuance_cloudservices_ICloudDataUploader *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUploader_waitForCompletionAsync
(
    nuance_cloudservices_ICloudDataUploader *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUploader_waitForCompletionWithTimeoutAsync
(
    nuance_cloudservices_ICloudDataUploader *instance,
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
CLOUDSERVICES_C_EXPORT nuance_common_ResultCode nuance_cloudservices_ICloudDataUploader_abortOperation(nuance_cloudservices_ICloudDataUploader *instance);


/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudDataUploader_destroy(nuance_cloudservices_ICloudDataUploader *);


CLOUDSERVICES_C_EXPORT nuance_common_IModule *nuance_cloudservices_ICloudDataUploader_as_nuance_common_IModule(nuance_cloudservices_ICloudDataUploader *obj);

CLOUDSERVICES_C_EXPORT nuance_common_IBackgroundOperation *nuance_cloudservices_ICloudDataUploader_as_nuance_common_IBackgroundOperation(nuance_cloudservices_ICloudDataUploader *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
