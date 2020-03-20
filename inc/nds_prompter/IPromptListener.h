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
 *  Declaration of nuance_prompter_IPromptListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter  nuance_prompter
 *  @{
 *  @addtogroup IPromptListener
 *  @{
 *  @file IPromptListener.h
 *
 *  @brief Listener to receive error, event and text marker notifications while a prompt is running.<p>
 *
 *  A prompt is initiated by invoking one of these calls:
 *  <tt>nuance_prompter_IPrompter_playString</tt>, <tt>nuance_prompter_IPrompter_playStringByFormat</tt>,
 *  <tt>nuance_prompter_IPrompter_playFile</tt> or <tt>nuance_prompter_IPrompter_playFileByFormat</tt>.
 *
 *  While the prompt runs, the application gets information about the prompt progress
 *  as <tt>nuance_prompter_IPromptListener_onEvent</tt> notifications. The prompt progress is described
 *  with <tt>nuance_prompter_PromptEvent</tt> enumeration values. The prompt events typically occur
 *  in the following sequence:
 *
 *  <ul>
 *  <li>1. <tt>START_GENERATION_EVENT</tt>: The Prompter starts to convert text into speech.</li>
 *  <li>2. <tt>START_PLAY_EVENT</tt>: The first audio chunk of the generated speech has been played at the output device.</li>
 *  <li>3. <tt>END_GENERATION_EVENT</tt>: The Prompter ended speech generation (Ends also if the prompt is aborted/interrupted).</li>
 *  <li>4. <tt>END_PLAY_EVENT</tt>: The last audio chunk of the generated speech has been played at the output device (Can be also the last chunk of an aborted/interrupted prompt).</li>
 *  <li>5. <tt>FINISH_PROMPT_EVENT</tt>: The prompt is fully processed and can be destroyed.</li>
 *  </ul>
 *
 *  Do not rely on the order of <tt>START_PLAY_EVENT</tt> and <tt>END_GENERATION_EVENT</tt>.
 *  In some cases the speech generation ends before <tt>START_PLAY_EVENT</tt> occurs (happens usually
 *  when the overall play time of the generated speech is very short).
 *
 *  NOTE: The output device has played already the first audio chunk at the point,
 *  when <tt>START_PLAY_EVENT</tt> occurs.
 *  Thus, the overall play time of a prompt matches the time period between <tt>START_PLAY_EVENT</tt>
 *  and <tt>END_PLAY_EVENT</tt> plus the play time of one audio chunk.
 *  And the time elapsing from the moment <tt>nuance_prompter_IPrompter_play*</tt> was called,
 *  until playback starts at the output device, matches the time period between the call
 *  and <tt>START_PLAY_EVENT</tt> minus the play time of one audio chunk.
 *
 *  A prompt can be aborted with a call to <tt>nuance_prompter_IPrompt_abortOperation</tt>.
 *  In this case, an <tt>ABORTED_PROMPT_EVENT</tt> notification is sent to the application right before the final event <tt>FINISH_PROMPT_EVENT</tt> to confirm that the prompt has been aborted.
 *  If <tt>nuance_prompter_IPrompt_abortOperation</tt> is called after the <tt>FINISH_PROMPT_EVENT</tt> notification, no <tt>ABORTED_PROMPT_EVENT</tt> notification can be expected.
 *
 *  Applications using <tt>local</tt> <tt>IPrompter</tt> instances can optionally receive marker event
 *  notifications. The notifications <tt>nuance_prompter_IPromptListener_onTextUnitMarker</tt>,
 *  <tt>nuance_prompter_IPromptListener_onWordMarker</tt>, <tt>nuance_prompter_IPromptListener_onBookmark</tt>,
 *  <tt>nuance_prompter_IPromptListener_onLipInfoMarker</tt> can be indiviually
 *  enabled in the <tt>local</tt> usecase configuration. For example to enable all kinds of marker
 *  event notifications, the relevant usecase definition must contain:
 *  <tt>"enabled_markers": "textunit,word,bookmark,lipinfo"</tt>.
 *
 *  To avoid overfloading of the application with notifications, it is recommended to
 *  reduce the enabled marker notifications to the ones really needed.
 *
 *  NOTE: Loaded user rulesets cause the Prompter to rewrite the input text according to the given
 *  rules. This may change the amount of text units and phonemes. All marker notifications
 *  relate to the rewritten text and not the original input text.
 *
 *
 *  With <tt>nuance_prompter_IPromptListener_onError</tt> notifications, the application
 *  gets informed about errors that occur during prompting. Besides an error enumeration value
 *  an error notification contains also a string parameter describing the error more detailed.
 */

#ifndef NUANCE_PROMPTER_IPROMPTLISTENER_H
#define NUANCE_PROMPTER_IPROMPTLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief Listener to receive error, event and text marker notifications while a prompt is running.<p>
 *
 *  A prompt is initiated by invoking one of these calls:
 *  <tt>nuance_prompter_IPrompter_playString</tt>, <tt>nuance_prompter_IPrompter_playStringByFormat</tt>,
 *  <tt>nuance_prompter_IPrompter_playFile</tt> or <tt>nuance_prompter_IPrompter_playFileByFormat</tt>.
 *
 *  While the prompt runs, the application gets information about the prompt progress
 *  as <tt>nuance_prompter_IPromptListener_onEvent</tt> notifications. The prompt progress is described
 *  with <tt>nuance_prompter_PromptEvent</tt> enumeration values. The prompt events typically occur
 *  in the following sequence:
 *
 *  <ul>
 *  <li>1. <tt>START_GENERATION_EVENT</tt>: The Prompter starts to convert text into speech.</li>
 *  <li>2. <tt>START_PLAY_EVENT</tt>: The first audio chunk of the generated speech has been played at the output device.</li>
 *  <li>3. <tt>END_GENERATION_EVENT</tt>: The Prompter ended speech generation (Ends also if the prompt is aborted/interrupted).</li>
 *  <li>4. <tt>END_PLAY_EVENT</tt>: The last audio chunk of the generated speech has been played at the output device (Can be also the last chunk of an aborted/interrupted prompt).</li>
 *  <li>5. <tt>FINISH_PROMPT_EVENT</tt>: The prompt is fully processed and can be destroyed.</li>
 *  </ul>
 *
 *  Do not rely on the order of <tt>START_PLAY_EVENT</tt> and <tt>END_GENERATION_EVENT</tt>.
 *  In some cases the speech generation ends before <tt>START_PLAY_EVENT</tt> occurs (happens usually
 *  when the overall play time of the generated speech is very short).
 *
 *  NOTE: The output device has played already the first audio chunk at the point,
 *  when <tt>START_PLAY_EVENT</tt> occurs.
 *  Thus, the overall play time of a prompt matches the time period between <tt>START_PLAY_EVENT</tt>
 *  and <tt>END_PLAY_EVENT</tt> plus the play time of one audio chunk.
 *  And the time elapsing from the moment <tt>nuance_prompter_IPrompter_play*</tt> was called,
 *  until playback starts at the output device, matches the time period between the call
 *  and <tt>START_PLAY_EVENT</tt> minus the play time of one audio chunk.
 *
 *  A prompt can be aborted with a call to <tt>nuance_prompter_IPrompt_abortOperation</tt>.
 *  In this case, an <tt>ABORTED_PROMPT_EVENT</tt> notification is sent to the application right before the final event <tt>FINISH_PROMPT_EVENT</tt> to confirm that the prompt has been aborted.
 *  If <tt>nuance_prompter_IPrompt_abortOperation</tt> is called after the <tt>FINISH_PROMPT_EVENT</tt> notification, no <tt>ABORTED_PROMPT_EVENT</tt> notification can be expected.
 *
 *  Applications using <tt>local</tt> <tt>IPrompter</tt> instances can optionally receive marker event
 *  notifications. The notifications <tt>nuance_prompter_IPromptListener_onTextUnitMarker</tt>,
 *  <tt>nuance_prompter_IPromptListener_onWordMarker</tt>, <tt>nuance_prompter_IPromptListener_onBookmark</tt>,
 *  <tt>nuance_prompter_IPromptListener_onLipInfoMarker</tt> can be indiviually
 *  enabled in the <tt>local</tt> usecase configuration. For example to enable all kinds of marker
 *  event notifications, the relevant usecase definition must contain:
 *  <tt>"enabled_markers": "textunit,word,bookmark,lipinfo"</tt>.
 *
 *  To avoid overfloading of the application with notifications, it is recommended to
 *  reduce the enabled marker notifications to the ones really needed.
 *
 *  NOTE: Loaded user rulesets cause the Prompter to rewrite the input text according to the given
 *  rules. This may change the amount of text units and phonemes. All marker notifications
 *  relate to the rewritten text and not the original input text.
 *
 *
 *  With <tt>nuance_prompter_IPromptListener_onError</tt> notifications, the application
 *  gets informed about errors that occur during prompting. Besides an error enumeration value
 *  an error notification contains also a string parameter describing the error more detailed.
 */
struct _nuance_prompter_IPromptListener;
/**
 *  @brief Listener to receive error, event and text marker notifications while a prompt is running.<p>
 *
 *  A prompt is initiated by invoking one of these calls:
 *  <tt>nuance_prompter_IPrompter_playString</tt>, <tt>nuance_prompter_IPrompter_playStringByFormat</tt>,
 *  <tt>nuance_prompter_IPrompter_playFile</tt> or <tt>nuance_prompter_IPrompter_playFileByFormat</tt>.
 *
 *  While the prompt runs, the application gets information about the prompt progress
 *  as <tt>nuance_prompter_IPromptListener_onEvent</tt> notifications. The prompt progress is described
 *  with <tt>nuance_prompter_PromptEvent</tt> enumeration values. The prompt events typically occur
 *  in the following sequence:
 *
 *  <ul>
 *  <li>1. <tt>START_GENERATION_EVENT</tt>: The Prompter starts to convert text into speech.</li>
 *  <li>2. <tt>START_PLAY_EVENT</tt>: The first audio chunk of the generated speech has been played at the output device.</li>
 *  <li>3. <tt>END_GENERATION_EVENT</tt>: The Prompter ended speech generation (Ends also if the prompt is aborted/interrupted).</li>
 *  <li>4. <tt>END_PLAY_EVENT</tt>: The last audio chunk of the generated speech has been played at the output device (Can be also the last chunk of an aborted/interrupted prompt).</li>
 *  <li>5. <tt>FINISH_PROMPT_EVENT</tt>: The prompt is fully processed and can be destroyed.</li>
 *  </ul>
 *
 *  Do not rely on the order of <tt>START_PLAY_EVENT</tt> and <tt>END_GENERATION_EVENT</tt>.
 *  In some cases the speech generation ends before <tt>START_PLAY_EVENT</tt> occurs (happens usually
 *  when the overall play time of the generated speech is very short).
 *
 *  NOTE: The output device has played already the first audio chunk at the point,
 *  when <tt>START_PLAY_EVENT</tt> occurs.
 *  Thus, the overall play time of a prompt matches the time period between <tt>START_PLAY_EVENT</tt>
 *  and <tt>END_PLAY_EVENT</tt> plus the play time of one audio chunk.
 *  And the time elapsing from the moment <tt>nuance_prompter_IPrompter_play*</tt> was called,
 *  until playback starts at the output device, matches the time period between the call
 *  and <tt>START_PLAY_EVENT</tt> minus the play time of one audio chunk.
 *
 *  A prompt can be aborted with a call to <tt>nuance_prompter_IPrompt_abortOperation</tt>.
 *  In this case, an <tt>ABORTED_PROMPT_EVENT</tt> notification is sent to the application right before the final event <tt>FINISH_PROMPT_EVENT</tt> to confirm that the prompt has been aborted.
 *  If <tt>nuance_prompter_IPrompt_abortOperation</tt> is called after the <tt>FINISH_PROMPT_EVENT</tt> notification, no <tt>ABORTED_PROMPT_EVENT</tt> notification can be expected.
 *
 *  Applications using <tt>local</tt> <tt>IPrompter</tt> instances can optionally receive marker event
 *  notifications. The notifications <tt>nuance_prompter_IPromptListener_onTextUnitMarker</tt>,
 *  <tt>nuance_prompter_IPromptListener_onWordMarker</tt>, <tt>nuance_prompter_IPromptListener_onBookmark</tt>,
 *  <tt>nuance_prompter_IPromptListener_onLipInfoMarker</tt> can be indiviually
 *  enabled in the <tt>local</tt> usecase configuration. For example to enable all kinds of marker
 *  event notifications, the relevant usecase definition must contain:
 *  <tt>"enabled_markers": "textunit,word,bookmark,lipinfo"</tt>.
 *
 *  To avoid overfloading of the application with notifications, it is recommended to
 *  reduce the enabled marker notifications to the ones really needed.
 *
 *  NOTE: Loaded user rulesets cause the Prompter to rewrite the input text according to the given
 *  rules. This may change the amount of text units and phonemes. All marker notifications
 *  relate to the rewritten text and not the original input text.
 *
 *
 *  With <tt>nuance_prompter_IPromptListener_onError</tt> notifications, the application
 *  gets informed about errors that occur during prompting. Besides an error enumeration value
 *  an error notification contains also a string parameter describing the error more detailed.
 */
typedef struct _nuance_prompter_IPromptListener nuance_prompter_IPromptListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "prompter_api_defs.h"

/* API types */
#include "LipInfo.h"
#include "PromptError.h"
#include "PromptEvent.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief The notification is sent to inform an application about the prompt progress.<p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     event   The event type of the notification
 */
typedef void (*FUNC_nuance_prompter_IPromptListener_onEvent)
(
    void *instance,
    nuance_prompter_PromptEvent event
);

/**
 *  @brief The notification is sent each time a text unit marker event occurs.<p>
 *
 *  The type of the text unit the marker notification relates to, depends on the read mode set on the TTS engine.
 *  By default the read mode is set to read text sentence by sentence. Thus, a text unit nofication is sent
 *  at the beginning of each sentence.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     count        The current count of played text units. Counting starts with 1.
 *  @param[in]     totalCount   The total count of text units to play.
 *  @param[in]     timestamp    The time (in milliseconds) when the event was triggered. Counting starts at the beginning of a prompt.
 */
typedef void (*FUNC_nuance_prompter_IPromptListener_onTextUnitMarker)
(
    void *instance,
    LH_S32 count,
    LH_S32 totalCount,
    LH_S32 timestamp
);

/**
 *  @brief The notification is sent each time a word marker event occurs.<p>
 *
 *  The work marker notification is sent the beginning of each word.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     timestamp   The time (in milliseconds) when the event was triggered. Counting starts at the beginning of a prompt.
 */
typedef void (*FUNC_nuance_prompter_IPromptListener_onWordMarker)
(
    void *instance,
    LH_S32 timestamp
);

/**
 *  @brief The notification is sent each time a bookmark event occurs.<p>
 *
 *  It marks the occurrence of a bookmark control sequence \<ESC\>\\mrk=\<id\>\\ in the input text.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     id          The bookmark id.
 *  @param[in]     timestamp   The time (in milliseconds) when the event was triggered. Counting starts at the beginning of a prompt.
 */
typedef void (*FUNC_nuance_prompter_IPromptListener_onBookmark)
(
    void *instance,
    LH_S32 id,
    LH_S32 timestamp
);

/**
 *  @brief The notification is sent each time a lipinfo marker event occurs.<p>
 *
 *  It passes an array of int elements describing the lip positions:
 *
 *  lipInfo[0]: Opening angle of the jaw on a 0 to 255 linear scale, where 0 = fully closed, and 255 = completely open.
 *
 *  lipInfo[1]: Indicates if upper teeth are visible on a 0 to 255 linear scale, where 0 = upper teeth are completely hidden,
 *  128 = only the teeth are visible, and 255 = upper teeth and gums are completely exposed.
 *
 *  lipInfo[2]: Indicates if lower teeth are visible on a 0 to 255 linear scale, where 0 = lower teeth are completely hidden,
 *  128 = only the teeth are visible, and 255 = lower teeth and gums are completely exposed.
 *
 *  lipInfo[3]: Mouth height on a 0 to 255 linear scale, where 0 = minimum height (mouth and lips are closed)
 *  and 255 = maximum possible height for the mouth.
 *
 *  lipInfo[4]: Mouth or lips width on a 0 to 255 linear scale, where 0 = minimum width (mouth and lips are puckered)
 *  and 255 = maximum possible width for the mouth.
 *
 *  lipInfo[5]: Indicates how much the mouth is turned up at the corners on a 0 to 255 linear scale,
 *  where 0 = mouth corners turning down, 128 = neutral, and 255 = mouth is fully upturned.
 *
 *  lipInfo[6]: Indicates the tongue position relative to the upper teeth on a 0 to 255 linear scale,
 *  where 0 = tongue is completely relaxed, and 255 = tongue is against the upper teeth.
 *
 *  lipInfo[7]: Lip tension on a 0 to 255 linear scale, where 0 = lips are completely relaxed,
 *  and 255 = lips are very tense.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     lipInfo     An array of int elements describing the lip positions
 *  @param[in]     nlipInfo    Number of elements in lipInfo
 *  @param[in]     timestamp   The time (in milliseconds) when the event was triggered. Counting starts at the beginning of a prompt.
 */
typedef void (*FUNC_nuance_prompter_IPromptListener_onLipInfoMarker)
(
    void *instance,
    LH_S32  const *lipInfo, LH_S32 nlipInfo,
    LH_S32 timestamp
);

/**
 *  @brief The notification is sent when an error occurs while a prompt is running.<p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     error     The type of error that occurred
 *  @param[in]     message   String describing the error
 */
typedef void (*FUNC_nuance_prompter_IPromptListener_onError)
(
    void *instance,
    nuance_prompter_PromptError error,
    const LH_CHAR *message
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief Listener to receive error, event and text marker notifications while a prompt is running.<p>
 *
 *  A prompt is initiated by invoking one of these calls:
 *  <tt>nuance_prompter_IPrompter_playString</tt>, <tt>nuance_prompter_IPrompter_playStringByFormat</tt>,
 *  <tt>nuance_prompter_IPrompter_playFile</tt> or <tt>nuance_prompter_IPrompter_playFileByFormat</tt>.
 *
 *  While the prompt runs, the application gets information about the prompt progress
 *  as <tt>nuance_prompter_IPromptListener_onEvent</tt> notifications. The prompt progress is described
 *  with <tt>nuance_prompter_PromptEvent</tt> enumeration values. The prompt events typically occur
 *  in the following sequence:
 *
 *  <ul>
 *  <li>1. <tt>START_GENERATION_EVENT</tt>: The Prompter starts to convert text into speech.</li>
 *  <li>2. <tt>START_PLAY_EVENT</tt>: The first audio chunk of the generated speech has been played at the output device.</li>
 *  <li>3. <tt>END_GENERATION_EVENT</tt>: The Prompter ended speech generation (Ends also if the prompt is aborted/interrupted).</li>
 *  <li>4. <tt>END_PLAY_EVENT</tt>: The last audio chunk of the generated speech has been played at the output device (Can be also the last chunk of an aborted/interrupted prompt).</li>
 *  <li>5. <tt>FINISH_PROMPT_EVENT</tt>: The prompt is fully processed and can be destroyed.</li>
 *  </ul>
 *
 *  Do not rely on the order of <tt>START_PLAY_EVENT</tt> and <tt>END_GENERATION_EVENT</tt>.
 *  In some cases the speech generation ends before <tt>START_PLAY_EVENT</tt> occurs (happens usually
 *  when the overall play time of the generated speech is very short).
 *
 *  NOTE: The output device has played already the first audio chunk at the point,
 *  when <tt>START_PLAY_EVENT</tt> occurs.
 *  Thus, the overall play time of a prompt matches the time period between <tt>START_PLAY_EVENT</tt>
 *  and <tt>END_PLAY_EVENT</tt> plus the play time of one audio chunk.
 *  And the time elapsing from the moment <tt>nuance_prompter_IPrompter_play*</tt> was called,
 *  until playback starts at the output device, matches the time period between the call
 *  and <tt>START_PLAY_EVENT</tt> minus the play time of one audio chunk.
 *
 *  A prompt can be aborted with a call to <tt>nuance_prompter_IPrompt_abortOperation</tt>.
 *  In this case, an <tt>ABORTED_PROMPT_EVENT</tt> notification is sent to the application right before the final event <tt>FINISH_PROMPT_EVENT</tt> to confirm that the prompt has been aborted.
 *  If <tt>nuance_prompter_IPrompt_abortOperation</tt> is called after the <tt>FINISH_PROMPT_EVENT</tt> notification, no <tt>ABORTED_PROMPT_EVENT</tt> notification can be expected.
 *
 *  Applications using <tt>local</tt> <tt>IPrompter</tt> instances can optionally receive marker event
 *  notifications. The notifications <tt>nuance_prompter_IPromptListener_onTextUnitMarker</tt>,
 *  <tt>nuance_prompter_IPromptListener_onWordMarker</tt>, <tt>nuance_prompter_IPromptListener_onBookmark</tt>,
 *  <tt>nuance_prompter_IPromptListener_onLipInfoMarker</tt> can be indiviually
 *  enabled in the <tt>local</tt> usecase configuration. For example to enable all kinds of marker
 *  event notifications, the relevant usecase definition must contain:
 *  <tt>"enabled_markers": "textunit,word,bookmark,lipinfo"</tt>.
 *
 *  To avoid overfloading of the application with notifications, it is recommended to
 *  reduce the enabled marker notifications to the ones really needed.
 *
 *  NOTE: Loaded user rulesets cause the Prompter to rewrite the input text according to the given
 *  rules. This may change the amount of text units and phonemes. All marker notifications
 *  relate to the rewritten text and not the original input text.
 *
 *
 *  With <tt>nuance_prompter_IPromptListener_onError</tt> notifications, the application
 *  gets informed about errors that occur during prompting. Besides an error enumeration value
 *  an error notification contains also a string parameter describing the error more detailed.
 */
struct _vtable_nuance_prompter_IPromptListener
{
    /**
     *  @brief The notification is sent to inform an application about the prompt progress.<p>
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     event   The event type of the notification
     */
    FUNC_nuance_prompter_IPromptListener_onEvent onEvent;

    /**
     *  @brief The notification is sent each time a text unit marker event occurs.<p>
     *
     *  The type of the text unit the marker notification relates to, depends on the read mode set on the TTS engine.
     *  By default the read mode is set to read text sentence by sentence. Thus, a text unit nofication is sent
     *  at the beginning of each sentence.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     count        The current count of played text units. Counting starts with 1.
     *  @param[in]     totalCount   The total count of text units to play.
     *  @param[in]     timestamp    The time (in milliseconds) when the event was triggered. Counting starts at the beginning of a prompt.
     */
    FUNC_nuance_prompter_IPromptListener_onTextUnitMarker onTextUnitMarker;

    /**
     *  @brief The notification is sent each time a word marker event occurs.<p>
     *
     *  The work marker notification is sent the beginning of each word.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     timestamp   The time (in milliseconds) when the event was triggered. Counting starts at the beginning of a prompt.
     */
    FUNC_nuance_prompter_IPromptListener_onWordMarker onWordMarker;

    /**
     *  @brief The notification is sent each time a bookmark event occurs.<p>
     *
     *  It marks the occurrence of a bookmark control sequence \<ESC\>\\mrk=\<id\>\\ in the input text.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     id          The bookmark id.
     *  @param[in]     timestamp   The time (in milliseconds) when the event was triggered. Counting starts at the beginning of a prompt.
     */
    FUNC_nuance_prompter_IPromptListener_onBookmark onBookmark;

    /**
     *  @brief The notification is sent each time a lipinfo marker event occurs.<p>
     *
     *  It passes an array of int elements describing the lip positions:
     *
     *  lipInfo[0]: Opening angle of the jaw on a 0 to 255 linear scale, where 0 = fully closed, and 255 = completely open.
     *
     *  lipInfo[1]: Indicates if upper teeth are visible on a 0 to 255 linear scale, where 0 = upper teeth are completely hidden,
     *  128 = only the teeth are visible, and 255 = upper teeth and gums are completely exposed.
     *
     *  lipInfo[2]: Indicates if lower teeth are visible on a 0 to 255 linear scale, where 0 = lower teeth are completely hidden,
     *  128 = only the teeth are visible, and 255 = lower teeth and gums are completely exposed.
     *
     *  lipInfo[3]: Mouth height on a 0 to 255 linear scale, where 0 = minimum height (mouth and lips are closed)
     *  and 255 = maximum possible height for the mouth.
     *
     *  lipInfo[4]: Mouth or lips width on a 0 to 255 linear scale, where 0 = minimum width (mouth and lips are puckered)
     *  and 255 = maximum possible width for the mouth.
     *
     *  lipInfo[5]: Indicates how much the mouth is turned up at the corners on a 0 to 255 linear scale,
     *  where 0 = mouth corners turning down, 128 = neutral, and 255 = mouth is fully upturned.
     *
     *  lipInfo[6]: Indicates the tongue position relative to the upper teeth on a 0 to 255 linear scale,
     *  where 0 = tongue is completely relaxed, and 255 = tongue is against the upper teeth.
     *
     *  lipInfo[7]: Lip tension on a 0 to 255 linear scale, where 0 = lips are completely relaxed,
     *  and 255 = lips are very tense.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     lipInfo     An array of int elements describing the lip positions
     *  @param[in]     nlipInfo    Number of elements in lipInfo
     *  @param[in]     timestamp   The time (in milliseconds) when the event was triggered. Counting starts at the beginning of a prompt.
     */
    FUNC_nuance_prompter_IPromptListener_onLipInfoMarker onLipInfoMarker;

    /**
     *  @brief The notification is sent when an error occurs while a prompt is running.<p>
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     error     The type of error that occurred
     *  @param[in]     message   String describing the error
     */
    FUNC_nuance_prompter_IPromptListener_onError onError;

};
/**
 *  @brief Listener to receive error, event and text marker notifications while a prompt is running.<p>
 *
 *  A prompt is initiated by invoking one of these calls:
 *  <tt>nuance_prompter_IPrompter_playString</tt>, <tt>nuance_prompter_IPrompter_playStringByFormat</tt>,
 *  <tt>nuance_prompter_IPrompter_playFile</tt> or <tt>nuance_prompter_IPrompter_playFileByFormat</tt>.
 *
 *  While the prompt runs, the application gets information about the prompt progress
 *  as <tt>nuance_prompter_IPromptListener_onEvent</tt> notifications. The prompt progress is described
 *  with <tt>nuance_prompter_PromptEvent</tt> enumeration values. The prompt events typically occur
 *  in the following sequence:
 *
 *  <ul>
 *  <li>1. <tt>START_GENERATION_EVENT</tt>: The Prompter starts to convert text into speech.</li>
 *  <li>2. <tt>START_PLAY_EVENT</tt>: The first audio chunk of the generated speech has been played at the output device.</li>
 *  <li>3. <tt>END_GENERATION_EVENT</tt>: The Prompter ended speech generation (Ends also if the prompt is aborted/interrupted).</li>
 *  <li>4. <tt>END_PLAY_EVENT</tt>: The last audio chunk of the generated speech has been played at the output device (Can be also the last chunk of an aborted/interrupted prompt).</li>
 *  <li>5. <tt>FINISH_PROMPT_EVENT</tt>: The prompt is fully processed and can be destroyed.</li>
 *  </ul>
 *
 *  Do not rely on the order of <tt>START_PLAY_EVENT</tt> and <tt>END_GENERATION_EVENT</tt>.
 *  In some cases the speech generation ends before <tt>START_PLAY_EVENT</tt> occurs (happens usually
 *  when the overall play time of the generated speech is very short).
 *
 *  NOTE: The output device has played already the first audio chunk at the point,
 *  when <tt>START_PLAY_EVENT</tt> occurs.
 *  Thus, the overall play time of a prompt matches the time period between <tt>START_PLAY_EVENT</tt>
 *  and <tt>END_PLAY_EVENT</tt> plus the play time of one audio chunk.
 *  And the time elapsing from the moment <tt>nuance_prompter_IPrompter_play*</tt> was called,
 *  until playback starts at the output device, matches the time period between the call
 *  and <tt>START_PLAY_EVENT</tt> minus the play time of one audio chunk.
 *
 *  A prompt can be aborted with a call to <tt>nuance_prompter_IPrompt_abortOperation</tt>.
 *  In this case, an <tt>ABORTED_PROMPT_EVENT</tt> notification is sent to the application right before the final event <tt>FINISH_PROMPT_EVENT</tt> to confirm that the prompt has been aborted.
 *  If <tt>nuance_prompter_IPrompt_abortOperation</tt> is called after the <tt>FINISH_PROMPT_EVENT</tt> notification, no <tt>ABORTED_PROMPT_EVENT</tt> notification can be expected.
 *
 *  Applications using <tt>local</tt> <tt>IPrompter</tt> instances can optionally receive marker event
 *  notifications. The notifications <tt>nuance_prompter_IPromptListener_onTextUnitMarker</tt>,
 *  <tt>nuance_prompter_IPromptListener_onWordMarker</tt>, <tt>nuance_prompter_IPromptListener_onBookmark</tt>,
 *  <tt>nuance_prompter_IPromptListener_onLipInfoMarker</tt> can be indiviually
 *  enabled in the <tt>local</tt> usecase configuration. For example to enable all kinds of marker
 *  event notifications, the relevant usecase definition must contain:
 *  <tt>"enabled_markers": "textunit,word,bookmark,lipinfo"</tt>.
 *
 *  To avoid overfloading of the application with notifications, it is recommended to
 *  reduce the enabled marker notifications to the ones really needed.
 *
 *  NOTE: Loaded user rulesets cause the Prompter to rewrite the input text according to the given
 *  rules. This may change the amount of text units and phonemes. All marker notifications
 *  relate to the rewritten text and not the original input text.
 *
 *
 *  With <tt>nuance_prompter_IPromptListener_onError</tt> notifications, the application
 *  gets informed about errors that occur during prompting. Besides an error enumeration value
 *  an error notification contains also a string parameter describing the error more detailed.
 */
typedef struct _vtable_nuance_prompter_IPromptListener vtable_nuance_prompter_IPromptListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
PROMPTER_C_EXPORT nuance_prompter_IPromptListener *nuance_prompter_IPromptListener_create
(
    const vtable_nuance_prompter_IPromptListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
PROMPTER_C_EXPORT void nuance_prompter_IPromptListener_destroy(nuance_prompter_IPromptListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_IPROMPTLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
