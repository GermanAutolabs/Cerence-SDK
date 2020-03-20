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
 *  Declaration of nuance_prompter_IDiagnosis class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter  nuance_prompter
 *  @{
 *  @addtogroup IDiagnosis
 *  @{
 *  @file prompter_IDiagnosis.h
 *
 *  @brief  The Prompter diagnosis interface. <p>
 *
 *  This interface is intended for CDFW applications only.
 */

#ifndef NUANCE_PROMPTER_IDIAGNOSIS_H
#define NUANCE_PROMPTER_IDIAGNOSIS_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  The Prompter diagnosis interface. <p>
 *
 *  This interface is intended for CDFW applications only.
 */
struct _nuance_prompter_IDiagnosis;
/**
 *  @brief  The Prompter diagnosis interface. <p>
 *
 *  This interface is intended for CDFW applications only.
 */
typedef struct _nuance_prompter_IDiagnosis nuance_prompter_IDiagnosis;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "prompter_api_defs.h"

/* API types */
#include "DiagnosisCallStatus.h"
#include "IConfiguration.h"
#include "IPrompter.h"
#include "PromptStateList.h"
#include "ResultCode.h"
#include "StringList.h"
#include "StringListList.h"
#include "TextFormat.h"
#include "TextFormatList.h"
#include "TextSourceList.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  Returns the Version of the Prompter component. <p>
 *
 *  This method is only intended for CDFW applications.
 *
 *  @param[out]    vocalizerVersion   Version of the Vocalizer module.
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IDiagnosis_getVersion(nuance_common_String **vocalizerVersion);


/**
 *  @brief  Returns the names of all Prompter instances. <p>
 *
 *  This method is intended for CDFW applications only.
 *
 *  @param[in]     config   an IConfiguration object that holds the Prompter's JSON configuration
 *  @param[out]    names    a list of Prompter instance names
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IDiagnosis_getInstanceNames
(
    const nuance_common_IConfiguration *config,
    nuance_common_StringList **names
);


/**
 *  @brief  Obtains available speech configurations of the given \a prompter instance. <p>
 *
 *  This method is intended for CDFW applications only.
 *
 *  The output arguments are (unsorted) lists of strings describing available speech configurations. All lists have
 *  the same length and each list represents a column of the speech configuration table. All elements having
 *  the same list index describe one speech configuration.
 *
 *  On a "local" type of the <tt>IPrompter</tt> instance a speech configuration is identified via a set of speech parameters
 *  (language code, voice name, voice operating point, multi-lingual language set, e.g.: "enu", "ava-ml", "embedded-high", ["enu", "spm"])
 *  and a usecase name (e.g.: "MyJsonUseCaseName"). The usecase name refers to a usecase JSON configuration located under the Prompter's
 *  JSON configuration path. The usecase name is required to activate a usecase on the <tt>IPrompter</tt> instance.
 *
 *  A speech parameter set describes a certain voice available under the configured "vocalizer_path". A certain
 *  voice is considered "available" when its corresponding "broker header file" is found during creation of the <tt>IPrompter</tt> instance.
 *  Important to mention is that there is no detection if the data components (stored in *.dat files) belonging to the voice are incomplete.
 *  Thus this method relies on correctly deployed voice data under the given "vocalizer_path".
 *
 *  The returned lists are reduced to names of usecases having a configuration matching to available speech parameters.
 *  Contrariwise speech parameters not used in any of the usecase configurations are not listed, too.
 *
 *  The multi-lingual (ML) sets include the voice's native language and optionally the list of languages for which a ML voice
 *  can read text using the foreign phoneme set supported by foreign units in its speechbase. This list is read from the <tt>noclmset</tt> param
 *  in the voice's broker header file (*.hdr).
 *
 *  On a "cloud" type of the <tt>IPrompter</tt> instance a speech configuration looks different. It does not contain information about voice operating point
 *  or ML language sets and may contain either a language code or a voice name or both. Typically a speech configuration of the cloud may
 *  look like following: "eng-USA", "ava-ml", "", [], "MyJsonCloudUseCase". The returned lists contain only usecases that have at least
 *  defined a language or a voice name. All other usecase are considered as invalid and are not activatable.
 *  Important to note is that the returned table of speech configurations does not reflect the actual voices and languages
 *  available on the cloud service, i.e. the configured speech configurations are not validated against the voices
 *  the cloud actually provides. Further note: During the life-time of a <tt>IPrompter</tt> instance, dynamic modifications of the
 *  voice names or language codes with the <tt>"vh_callback"</tt> mechanism are not reflected in the returned speech configurations.
 *
 *  @param[in]     prompter          the prompter instance from where the speech configurations are obtained
 *  @param[out]    languageCodes     list language codes
 *  @param[out]    voiceNames        list of voice names
 *  @param[out]    operatingPoints   list of voice operating points
 *  @param[out]    mlLanguageSets    list of ML language sets, a language set consists of one or more language codes
 *  @param[out]    useCaseNames      list of usecase names
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IDiagnosis_getAvailableSpeechConfigurations
(
    const nuance_prompter_IPrompter *prompter,
    nuance_common_StringList **languageCodes,
    nuance_common_StringList **voiceNames,
    nuance_common_StringList **operatingPoints,
    nuance_common_StringListList **mlLanguageSets,
    nuance_common_StringList **useCaseNames
);


/**
 *  @brief  Obtains details of last prompts sorted by time. <p>
 *
 *  This method is intended for CDFW applications only.
 *
 *  All <tt>IPrompter</tt> instances store various details (like input texts, text formats, activated use cases, etc ..)
 *  of lately played prompts in a prompt history. Each item of the history contains the details
 *  of one prompt. The maximum count of history items is limited. The limit is configurable in
 *  the JSON configuration with the key <tt>prompt_history_max_count</tt>.
 *  This method returns the content of the prompt history. The outputs are lists holding the
 *  details of the last prompts. All lists have the same length. List elements having
 *  the same list index describe one prompt. The elements with index 0 describe the most recent
 *  played prompt. The maximum length of stored texts can be defined in the JSON configuration
 *  with the key <tt>prompt_history_text_max_length</tt>.
 *
 *  @param[out]    prompterNames   the names of the Prompter instances the prompts belong to
 *  @param[out]    useCaseNames    the names of the activated use cases
 *  @param[out]    texts           the played texts, that may either be text strings or text file paths
 *  @param[out]    textFormats     the formats of the played texts
 *  @param[out]    textSources     the sources of the texts
 *  @param[out]    promptStates    the states of the prompts
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IDiagnosis_getLastPrompts
(
    nuance_common_StringList **prompterNames,
    nuance_common_StringList **useCaseNames,
    nuance_common_StringList **texts,
    nuance_prompter_TextFormatList **textFormats,
    nuance_prompter_TextSourceList **textSources,
    nuance_prompter_PromptStateList **promptStates
);


/**
 *  @brief  Plays a text string on the given \a prompter instance. <p>
 *
 *  This method is intended for CDFW applications only.
 *
 *  The method plays on the passed \a prompter instance the given
 *  \a text string. Before the Prompter starts playing the text string, it activates
 *  the use case with the passed \a useCaseName. For playback it uses the audio scenario
 *  which is defined as default_audio_scenario in the JSON configuration of the given
 *  \a prompter instance. The method returns after completion of the playback or, if a
 *  problem occurred while activating the use case or playing the text string. The \a status
 *  argument must be checked to understand if the play operation succeeded.
 *
 *  An error is returned as result code only, if the system is not able to run
 *  this diagnosis method at all.
 *
 *  @param[in]     prompter        the Prompter instance to play the text string
 *  @param[in]     useCaseName     the name of use case that is activated before start playing the text string
 *  @param[in]     text            the text string to play
 *  @param[in]     textFormat      the format of the text
 *  @param[out]    status          the status of the diagnosis call
 *  @param[out]    statusMessage   a message that describes the returned diagnosis call status more detailed
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IDiagnosis_playString
(
    nuance_prompter_IPrompter *prompter,
    const LH_CHAR *useCaseName,
    const LH_CHAR *text,
    nuance_prompter_TextFormat textFormat,
    nuance_prompter_DiagnosisCallStatus *status,
    nuance_common_String **statusMessage
);


/**
 *  @brief  Plays a text file on the given \a prompter instance. <p>
 *
 *  This method is intended for CDFW applications only.
 *
 *  The method plays on the passed \a prompter instance the content of the text file
 *  located at the given \a filePath. The text file must be UTF8-encoded.
 *  Before the Prompter starts playing the text file, it activates the use case with
 *  the passed \a useCaseName. For playback it uses the audio scenario which
 *  is defined as default_audio_scenario in the JSON configuration of the given
 *  \a prompter instance. The method returns after completion of the playback or, if a
 *  problem occurred while activating the use case or playing the text file. The \a status
 *  argument must be checked to understand if the play operation succeeded.
 *
 *  An error is returned as result code only, if the system is not able to run
 *  this diagnosis method at all.
 *
 *  @param[in]     prompter        the Prompter instance to play the text file
 *  @param[in]     useCaseName     the name of use case that is activated before start playing the text file
 *  @param[in]     filePath        the file path to the text file to play, the path is either relative to the JSON configuration directory or absolute
 *  @param[in]     textFormat      the format of the text
 *  @param[out]    status          the status of the diagnosis call
 *  @param[out]    statusMessage   a message that describes the returned diagnosis call status more detailed
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IDiagnosis_playFile
(
    nuance_prompter_IPrompter *prompter,
    const LH_CHAR *useCaseName,
    const LH_CHAR *filePath,
    nuance_prompter_TextFormat textFormat,
    nuance_prompter_DiagnosisCallStatus *status,
    nuance_common_String **statusMessage
);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_IDIAGNOSIS_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
