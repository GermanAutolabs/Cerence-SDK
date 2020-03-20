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
 *  Declaration of nuance_prompter_IPrompt class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter  nuance_prompter
 *  @{
 *  @addtogroup IPrompt
 *  @{
 *  @file IPrompt.h
 *
 *  @brief  This class represents an interface to a running speech prompt. <p>
 *
 *  Classes implementing this interface are derived from
 *  background operations and will enable the user to wait for
 *  completion or abort the prompt.
 */

#ifndef NUANCE_PROMPTER_IPROMPT_H
#define NUANCE_PROMPTER_IPROMPT_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  This class represents an interface to a running speech prompt. <p>
 *
 *  Classes implementing this interface are derived from
 *  background operations and will enable the user to wait for
 *  completion or abort the prompt.
 */
struct _nuance_prompter_IPrompt;
/**
 *  @brief  This class represents an interface to a running speech prompt. <p>
 *
 *  Classes implementing this interface are derived from
 *  background operations and will enable the user to wait for
 *  completion or abort the prompt.
 */
typedef struct _nuance_prompter_IPrompt nuance_prompter_IPrompt;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "prompter_api_defs.h"

/* API types */
#include "IBackgroundListener.h"
#include "IBackgroundOperation.h"
#include "ResultCode.h"
#include "SkipMode.h"


/*** Methods **********************************************************************************************************/


/**
 *  Restarts the playing prompt at the marker position described by \a position and \a mode.
 *
 *  Skipping affects the prompt only if it is playing, means within the time period defined
 *  by the <tt>nuance_prompter_IPromptListener_onEvent</tt> notifications
 *  <tt>START_PLAY_EVENT</tt> and <tt>END_PLAY_EVENT</tt>.
 *
 *  Supported markers are text units and bookmarks. The type of the text units this
 *  function relates to, depends on how the prompter has configured its readmode.
 *
 *  The function allows skipping in the following modes:
 *
 *  <ul>
 *  <li>1. <tt>TEXTUNIT_ABSOLUTE</tt>: Skips to the text unit at given \a position. The value correspondents to the text unit number counted from the beginning of the prompt. The first text unit of the prompt has the position 1.</li>
 *  <li>2. <tt>TEXTUNIT_RELATIVE</tt>: Skips to the text unit at \a position counted relatively from the currently playing text unit. The given position defines how many text units to skip and in which direction. The position -1 means to skip one text unit back. The position 1 means to skip one text unit forward. And position 0 means to skip to the beginning of the currently playing text unit.</li>
 *  <li>3. <tt>BOOKMARK_ID</tt>: Skips to the bookmark at given \a position, whereas the position contains the bookmark ID used in the text to play.</li>
 *  <li>4. <tt>BOOKMARK_RELATIVE</tt>: Analogically to the mode <tt>TEXTUNIT_RELATIVE</tt> it skips to the bookmark at \a position counted relatively from the currently playing bookmark.</li>
 *  </ul>
 *
 *  The function returns an error result if marker referred by \a position does not exist
 *  or if the prompt is not playing.
 *
 *  The method returns an error result if the method is not supported by the underlying
 *  TTS engine, e.g. if using a cloud <tt>IPrompter</tt> instance.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     position   the value defining the marker position to skip to
 *  @param[in]     mode       the skip mode
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompt_skipToMarker
(
    nuance_prompter_IPrompt *instance,
    LH_S32 position,
    nuance_prompter_SkipMode mode
);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompt_getStatus
(
    nuance_prompter_IPrompt *instance,
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
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompt_waitForCompletionWithTimeout
(
    nuance_prompter_IPrompt *instance,
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
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompt_waitForCompletion
(
    nuance_prompter_IPrompt *instance,
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
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompt_waitForCompletionAsync
(
    nuance_prompter_IPrompt *instance,
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
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompt_waitForCompletionWithTimeoutAsync
(
    nuance_prompter_IPrompt *instance,
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
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompt_abortOperation(nuance_prompter_IPrompt *instance);


/**
 *  Destructor
 */
PROMPTER_C_EXPORT void nuance_prompter_IPrompt_destroy(nuance_prompter_IPrompt *);


PROMPTER_C_EXPORT nuance_common_IBackgroundOperation *nuance_prompter_IPrompt_as_nuance_common_IBackgroundOperation(nuance_prompter_IPrompt *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_IPROMPT_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
