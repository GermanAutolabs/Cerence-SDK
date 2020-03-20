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
 *  Declaration of nuance_prompter_IPrompter class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter  nuance_prompter
 *  @{
 *  @addtogroup IPrompter
 *  @{
 *  @file IPrompter.h
 *
 *  @brief  This class represents a speech Prompter. <p>
 *
 *  Instances of this class are able to create objects with an
 *  <tt>IPrompt</tt> interface. These represent the prompts during
 *  playback and give control over the playback operation.
 *
 *  Background operations initiated with asynchronous method calls
 *  are queued in the background and executed according to the
 *  order of the method call sequence.
 *
 *  Before destruction of an instance of this class it must be
 *  ensured that all its created <tt>IPrompt</tt> objects are destroyed.
 */

#ifndef NUANCE_PROMPTER_IPROMPTER_H
#define NUANCE_PROMPTER_IPROMPTER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  This class represents a speech Prompter. <p>
 *
 *  Instances of this class are able to create objects with an
 *  <tt>IPrompt</tt> interface. These represent the prompts during
 *  playback and give control over the playback operation.
 *
 *  Background operations initiated with asynchronous method calls
 *  are queued in the background and executed according to the
 *  order of the method call sequence.
 *
 *  Before destruction of an instance of this class it must be
 *  ensured that all its created <tt>IPrompt</tt> objects are destroyed.
 */
struct _nuance_prompter_IPrompter;
/**
 *  @brief  This class represents a speech Prompter. <p>
 *
 *  Instances of this class are able to create objects with an
 *  <tt>IPrompt</tt> interface. These represent the prompts during
 *  playback and give control over the playback operation.
 *
 *  Background operations initiated with asynchronous method calls
 *  are queued in the background and executed according to the
 *  order of the method call sequence.
 *
 *  Before destruction of an instance of this class it must be
 *  ensured that all its created <tt>IPrompt</tt> objects are destroyed.
 */
typedef struct _nuance_prompter_IPrompter nuance_prompter_IPrompter;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "prompter_api_defs.h"

/* API types */
#include "IAudioManager.h"
#include "IAudioModule.h"
#include "ICloudManager.h"
#include "IConfiguration.h"
#include "IPrompt.h"
#include "IPromptListener.h"
#include "IPrompterListener.h"
#include "LanguageInfoType.h"
#include "ParameterType.h"
#include "ResultCode.h"
#include "StringList.h"
#include "StringListList.h"
#include "StringParameterType.h"
#include "TextFormat.h"
#include "UserLevel.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates an <tt>IPrompter</tt> instance with \a name and based on the given \a config.
 *
 *  This method is asynchronous and returns instantly after starting the instance creation
 *  in the background. Warnings and errors that may occur during creation are reported to
 *  the listener <tt>nuance_prompter_IPrompterListener</tt>.
 *  After successful creation, the instance continues to use this listener to report
 *  report warnings, errors, or various results or states during subsequent operations.
 *
 *  The method <tt>nuance_prompter_IPrompter_waitForCompletion</tt> can be utilized to wait for the
 *  creation to complete.
 *
 *  @param[in]     name           the name of the IPrompter instance (must be the same name as in the corresponding configuration)
 *  @param[in]     audioManager   an audio manager instance
 *  @param[in]     cloudManager   a cloud manager instance; NOTE: It is mandatory to pass a valid ICloudManager instance to create an IPrompter instance of type cloud! To create local IPrompter instances it is sufficient to pass a null pointer.
 *  @param[in]     config         a configuration instance that holds the Prompter's configuration
 *  @param[in]     listener       a listener that receives notifications from the IPrompter instance
 *  @param[out]    prompter       freshly created instance
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_create
(
    const LH_CHAR *name,
    nuance_audio_IAudioManager *audioManager,
    nuance_cloudservices_ICloudManager *cloudManager,
    const nuance_common_IConfiguration *config,
    nuance_prompter_IPrompterListener *listener,
    nuance_prompter_IPrompter **prompter
);


/**
 *  @brief  Returns the versions for the Prompter component. <p>
 *
 *  Note: The underlying EPP component module does not support version providing yet. Temporarily this version is reported as "unknown".
 *
 *  @param[out]    version          The product version the Prompter component is part of.
 *  @param[out]    moduleVersions   Versions of the Prompter modules [vocalizer, EPP].                           Index 0 = vocalizer, index 1 = EPP.
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_getVersions
(
    nuance_common_String **version,
    nuance_common_StringList **moduleVersions
);


/**
 *  @brief  Returns the names of all configured <tt>IPrompter</tt> instances found in the given \a config. <p>
 *
 *  @param[in]     config   an IConfiguration instance that holds the Prompter's JSON configuration
 *  @param[out]    names    a list of Prompter instance names
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_getInstanceNames
(
    const nuance_common_IConfiguration *config,
    nuance_common_StringList **names
);


/**
 *  @brief  Obtains available speech configurations. <p>
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
 *  @param[in,out] instance          The instance pointer
 *  @param[out]    languageCodes     list of 3-letter language codes, e.g. enu, iti, ged
 *  @param[out]    voiceNames        list of voice names
 *  @param[out]    operatingPoints   list of voice operating points
 *  @param[out]    mlLanguageSets    list of ML language sets, a language set consists of one or more language codes
 *  @param[out]    useCaseNames      list of usecase names
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_getAvailableSpeechConfigurations
(
    const nuance_prompter_IPrompter *instance,
    nuance_common_StringList **languageCodes,
    nuance_common_StringList **voiceNames,
    nuance_common_StringList **operatingPoints,
    nuance_common_StringListList **mlLanguageSets,
    nuance_common_StringList **useCaseNames
);


/**
 *  @brief  Returns information about the language with the given \a languageCode. <p>
 *
 *  This method returns information about the language with the given \a languageCode. The type of information
 *  has to be specified with the \a infoType argument. The information is returned as a list
 *  of strings. The returned content of the string list varies depending on the given \a infoType.
 *
 *  <ul>
 *  <li>The \a infoType \em CLM_VERSION_INFO causes the function to return a list with these strings:
 *  <ul>
 *  <li><tt>list index 0:</tt> Version info of the CLM data file.</li>
 *  <li><tt>list index 1:</tt> Version info of the source language.</li>
 *  <li><tt>list index 2:</tt> Version info of the target language.</li>
 *  </ul>
 *  </li>
 *
 *  <li>The \a infoType \em NTS_VERSION_INFO causes the function to return a list with these strings:
 *  <ul>
 *  <li><tt>list index 0:</tt> NT-SAMPA version info. Tells the L&H+ version and the NT-SAMPA version.</li>
 *  </ul>
 *  </li>
 *  </ul>
 *
 *  Returns an error result if the requested information cannot be obtained.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     languageCode   3-letter language code of the target language for which the info needs to be obtained, e.g. enu, iti, ged
 *  @param[in]     infoType       defines the type of the language info to be obtained
 *  @param[out]    info           list containing the requested information
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_getLanguageInfo
(
    const nuance_prompter_IPrompter *instance,
    const LH_CHAR *languageCode,
    nuance_prompter_LanguageInfoType infoType,
    nuance_common_StringList **info
);


/**
 *  @brief  Obtains a Prompter concept as a string from a concepts database (OTD-file). <p>
 *
 *  Concept database OTD files are only supported by CDFW applications.
 *
 *  The returned concept string can be played as a prompt by passing it to <tt>nuance_prompter_IPrompter_playString</tt>.
 *  The loading of a certain OTD-file is configurable via JSON in the
 *  usecase configuration of the <tt>IPrompter</tt> instance. The un-/loading of the concepts database happens during
 *  activation of the corresponding usecase. Therefore it is required to have the corresponding
 *  usecase activated before calling this method.
 *
 *  This method allows to pass parameter values as a list of string elements. Note that the mapping
 *  of the list elements to the parameters within a concept is done based on the
 *  list indices of the elements. It is crucial to fill the parameter value list in the correct order.
 *
 *  If the requested concept is not found or not retrievable of any reason, an error result
 *  will be returned.
 *
 *  @param[in,out] instance        The instance pointer
 *  @param[in]     conceptName     name identifying the concept to be obtained
 *  @param[in]     level           the user level to filter for concepts categorized into a certain level
 *  @param[in]     randomize       indicates to fetch a concept string randomly if there are alternative concept strings available
 *  @param[in]     paramValues     list containing parameter values required for the requested concept
 *  @param[in]     nparamValues    Number of elements in paramValues
 *  @param[out]    conceptString   the returned concept string
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_getConceptString
(
    const nuance_prompter_IPrompter *instance,
    const LH_CHAR *conceptName,
    nuance_prompter_UserLevel level,
    LH_BOOL randomize,
    const LH_CHAR * const *paramValues, LH_S32 nparamValues,
    nuance_common_String **conceptString
);


/**
 *  @brief  Plays the given \a text from a String. <p>
 *
 *  This method is asynchronous and starts TTS conversion and playback as a background operation. An <tt>IPrompt</tt>
 *  instance is returned that gives control over the background operation.
 *
 *  The listener <tt>nuance_prompter_IPromptListener</tt> is used to report errors that may occur during TTS conversion
 *  and playback. In addition, the <tt>IPrompt</tt> instance uses the listener to report its progress and
 *  (if enabled in the activated usecase) to inform when certain position markers in the input text are
 *  reached.
 *
 *  The method <tt>nuance_prompter_IPrompt_waitForCompletion</tt> can be utilized to wait for the
 *  playback operation to complete.
 *
 *  As a necessary precondition the <tt>IPrompter</tt> instance must have activated a valid usecase.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     text       the text to play back
 *  @param[in]     listener   listener that receives prompt errors and prompt events like markers
 *  @param[out]    prompt     freshly created prompt instance
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_playString
(
    nuance_prompter_IPrompter *instance,
    const LH_CHAR *text,
    nuance_prompter_IPromptListener *listener,
    nuance_prompter_IPrompt **prompt
);


/**
 *  @brief  Plays the given \a text which is in the specified \a textFormat from a String. <p>
 *
 *  This method is asynchronous and starts TTS conversion and playback as a background operation. An <tt>IPrompt</tt>
 *  instance is returned that gives control over the background operation.
 *
 *  The listener <tt>nuance_prompter_IPromptListener</tt> is used to report errors that may occur during TTS conversion
 *  and playback. In addition, the <tt>IPrompt</tt> instance uses the listener to report its progress and
 *  (if enabled in the activated usecase) to inform when certain position markers in the input text are
 *  reached.
 *
 *  The method <tt>nuance_prompter_IPrompt_waitForCompletion</tt> can be utilized to wait for the
 *  playback operation to complete.
 *
 *  As a necessary precondition the <tt>IPrompter</tt> instance must have activated a valid usecase.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     text         the text to play back
 *  @param[in]     textFormat   the format of the text to play back
 *  @param[in]     listener     listener that receives prompt errors and prompt events like markers
 *  @param[out]    prompt       freshly created prompt instance
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_playStringByFormat
(
    nuance_prompter_IPrompter *instance,
    const LH_CHAR *text,
    nuance_prompter_TextFormat textFormat,
    nuance_prompter_IPromptListener *listener,
    nuance_prompter_IPrompt **prompt
);


/**
 *  @brief  Plays the UTF8-encoded text from the file with given the \a filePath. <p>
 *
 *  The Prompter reads and plays the entire content of the UTF8-encoded text file.
 *
 *  This method is asynchronous and starts TTS conversion and playback as a background operation. An <tt>IPrompt</tt>
 *  instance is returned that gives control over the background operation.
 *
 *  The listener <tt>nuance_prompter_IPromptListener</tt> is used to report errors that may occur during TTS conversion
 *  and playback. In addition, the <tt>IPrompt</tt> instance uses the listener to report its progress and
 *  (if enabled in the activated usecase) to inform when certain position markers in the input text are
 *  reached.
 *
 *  The method <tt>nuance_prompter_IPrompt_waitForCompletion</tt> can be utilized to wait for the
 *  playback operation to complete.
 *
 *  As a necessary precondition the <tt>IPrompter</tt> instance must have activated a valid usecase.
 *
 *  Note: The Prompter passes the whole file content to the underlying TTS engine. The Prompter does not limit
 *  the file size nor divides a large file into smaller pieces to process them in multiple synthesis steps.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     filePath   filePath the path to the text file to play, the path is either relative to the JSON configuration directory or absolute
 *  @param[in]     listener   listener that receives prompt errors and prompt events like markers
 *  @param[out]    prompt     freshly created prompt instance
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_playFile
(
    nuance_prompter_IPrompter *instance,
    const LH_CHAR *filePath,
    nuance_prompter_IPromptListener *listener,
    nuance_prompter_IPrompt **prompt
);


/**
 *  @brief  Plays the UTF8-encoded text which is in the specified \a textFormat from the file with the given \a filePath. <p>
 *
 *  The Prompter reads and plays the entire content of the UTF8-encoded text file.
 *
 *  This method is asynchronous and starts TTS conversion and playback as a background operation. An <tt>IPrompt</tt>
 *  instance is returned that gives control over the background operation.
 *
 *  The listener <tt>nuance_prompter_IPromptListener</tt> is used to report errors that may occur during TTS conversion
 *  and playback. In addition, the <tt>IPrompt</tt> instance uses the listener to report its progress and
 *  (if enabled in the activated usecase) to inform when certain position markers in the input text are
 *  reached.
 *
 *  The method <tt>nuance_prompter_IPrompt_waitForCompletion</tt> can be utilized to wait for the
 *  playback operation to complete.
 *
 *  As a necessary precondition the <tt>IPrompter</tt> instance must have activated a valid usecase.
 *
 *  Note: The Prompter passes the whole file content to the underlying TTS engine. The Prompter does not limit
 *  the file size nor divides a large file into smaller pieces to process them in multiple synthesis steps.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     filePath     filePath the path to the text file to play, the path is either relative to the JSON configuration directory or absolute
 *  @param[in]     textFormat   the format of the text to play back
 *  @param[in]     listener     listener that receives prompt errors and prompt events like markers
 *  @param[out]    prompt       freshly created prompt instance
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_playFileByFormat
(
    nuance_prompter_IPrompter *instance,
    const LH_CHAR *filePath,
    nuance_prompter_TextFormat textFormat,
    nuance_prompter_IPromptListener *listener,
    nuance_prompter_IPrompt **prompt
);


/**
 *  @brief  Activates the usecase with the given \a name. <p>
 *
 *  This method is asynchronous and starts the usecase activation as a
 *  background operation. This Prompter-related operation can be controlled
 *  via the <tt>nuance_common_IBackgroundOperation</tt> interface the
 *  <tt>IPrompter</tt> instance provides.
 *
 *  Warnings and errors that may occur during this operation are reported to
 *  the listener <tt>nuance_prompter_IPrompterListener</tt>.
 *
 *  The method <tt>nuance_prompter_IPrompter_waitForCompletion</tt> can be utilized
 *  to wait for the operation to complete.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     name   the name of the usecase to activate
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_activateUseCase
(
    nuance_prompter_IPrompter *instance,
    const LH_CHAR *name
);


/**
 *  @brief  Sets the given \a parameter to the given \a parameterValue. <p>
 *
 *  This method is asynchronous and starts the changing of the parameter as a
 *  background operation. This Prompter-related operation can be controlled
 *  via the <tt>nuance_common_IBackgroundOperation</tt> interface the
 *  <tt>IPrompter</tt> instance provides.
 *
 *  Warnings and errors that may occur during this operation are reported to
 *  the listener <tt>nuance_prompter_IPrompterListener</tt>.
 *
 *  This method causes the Prompter to overrule the value of the \a parameter of the currently
 *  activated usecase with the new \a parameterValue. A subsequent call to
 *  <tt>nuance_prompter_IPrompter_activateUseCase</tt> resets the parameter value according to the value
 *  configured in the usecase. As a precondition for this method the <tt>IPrompter</tt> instance must have
 *  a valid usecase activated, otherwise the parameter value is not changed and
 *  <tt>nuance_prompter_IPrompterListener</tt> reports an error.
 *
 *  The method <tt>nuance_prompter_IPrompter_waitForCompletion</tt> can be utilized
 *  to wait for the operation to complete.
 *
 *  The possible value range of \a parameterValue depends on the given \a parameter type:
 *
 *  <ul>
 *  <li><tt>VOLUME</tt>: (0..100)</li>
 *  <li><tt>SPEECH_RATE</tt>: (50%..400%)</li>
 *  <li><tt>PITCH</tt>: (50%..200%, pitch=50%: one octave lower, pitch=200%: one octave higher)</li>
 *  <li><tt>TIMBRE</tt>: (50%..200%, for values > 100% the voice sounds younger, values < 100% make the voice sound older.)</li>
 *  </ul>
 *
 *  The method returns an error result if the method is not supported by the underlying
 *  TTS engine, e.g. if using a cloud <tt>IPrompter</tt> instance.
 *
 *  @param[in,out] instance         The instance pointer
 *  @param[in]     parameter        the parameter type
 *  @param[in]     parameterValue   the value to set
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_setParameter
(
    nuance_prompter_IPrompter *instance,
    nuance_prompter_ParameterType parameter,
    LH_S32 parameterValue
);


/**
 *  @brief  Sets the given \a parameter to the given \a parameterValue of String type. <p>
 *
 *  This method is asynchronous and starts the changing of the parameter as a
 *  background operation. This Prompter-related operation can be controlled
 *  via the <tt>nuance_common_IBackgroundOperation</tt> interface the
 *  <tt>IPrompter</tt> instance provides.
 *
 *  Warnings and errors that may occur during this operation are reported to
 *  the listener <tt>nuance_prompter_IPrompterListener</tt>.
 *
 *  This method causes the Prompter to overrule the value of the \a parameter of the currently
 *  activated usecase with the new string type \a parameterValue. A subsequent call to
 *  <tt>nuance_prompter_IPrompter_activateUseCase</tt> resets the parameter value according to the value
 *  configured in the usecase. As a precondition for this method the <tt>IPrompter</tt> instance must have
 *  a valid usecase activated, otherwise the parameter value is not changed and
 *  <tt>nuance_prompter_IPrompterListener</tt> reports an error.
 *
 *  The method <tt>nuance_prompter_IPrompter_waitForCompletion</tt> can be utilized
 *  to wait for the operation to complete.
 *
 *  The possible value range of \a parameterValue depends on the given \a parameter type:
 *
 *  <ul>
 *  <li><tt>TEXT_NORMALIZATION_TYPE</tt>: It configures the TTS engine to normalize the text to prompt with given TN type. There are basic TN types like "spell", "address" or "sms" as described in the Cerence TTS Embedded documentation (chapter "Guiding text normalization"). The loading of tuning files that define additional user specific TN types can be achieved with the "tuning_files" key in the usecase Json configuration. Passing an empty string as \a parameterValue disables the TN type.</li>
 *  </ul>
 *
 *  The method returns an error result if the method is not supported by the underlying
 *  TTS engine, e.g. if using a cloud <tt>IPrompter</tt> instance.
 *
 *  @param[in,out] instance         The instance pointer
 *  @param[in]     parameter        the parameter type
 *  @param[in]     parameterValue   the value to set
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_setStringParameter
(
    nuance_prompter_IPrompter *instance,
    nuance_prompter_StringParameterType parameter,
    const LH_CHAR *parameterValue
);


/**
 *  @brief  Switches the <tt>IPrompter</tt> instance to paused state. <p>
 *
 *  During pausing an ongoing play operation is interrupted immediately (synthesis and audio output are stopped). Even if there
 *  is no ongoing play operation the <tt>IPrompter</tt> instance will enter the paused state. All asynchronous operations (e.g. <tt>nuance_prompter_IPrompter_playString</tt>,
 *  <tt>nuance_prompter_IPrompter_activateUseCase</tt>, ...) are queued but not executed until the <tt>IPrompter</tt> instance leaves paused state again.
 *  The paused state is left with call to <tt>nuance_prompter_IPrompter_resume</tt>.
 *
 *  Note: A call to <tt>nuance_prompter_IPrompter_pause</tt> with a subsequent call to <tt>nuance_prompter_IPrompt_waitForCompletion</tt>
 *  within the same application thread causes a deadlock. The recommended way is to make calls to
 *  <tt>nuance_prompter_IPrompter_pause</tt> and <tt>nuance_prompter_IPrompter_resume</tt> from a separate application thread.
 *
 *  The method returns an error result if the method is not supported by the underlying
 *  TTS engine, e.g. if using a cloud <tt>IPrompter</tt> instance.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Returns OK if paused successfully, ERROR otherwise. Returns OK if pause() called in already paused state.
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_pause(nuance_prompter_IPrompter *instance);


/**
 *  @brief  Causes the <tt>IPrompter</tt> instance to leave the paused state. <p>
 *
 *  A previously interrupted play operation is continued again. The instance continues
 *  to process queued asynchronous operations (e.g. <tt>nuance_prompter_IPrompter_playString</tt>,
 *  <tt>nuance_prompter_IPrompter_activateUseCase</tt>, ...).
 *
 *  The method returns an error result if the method is not supported by the underlying
 *  TTS engine, e.g. if using a cloud <tt>IPrompter</tt> instance.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Returns OK if resumed successfully, ERROR otherwise. Returns OK if resume() called in not paused state.
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_resume(nuance_prompter_IPrompter *instance);


/**
 *  @brief  Sets an <tt>nuance_prompter_IPromptListener</tt> \a listener to receive Prompter-related notifications. <p>
 *
 *  When a listener is set with this method, all Prompter notifications
 *  are sent exclusively to that listener. A listener previously set with this method
 *  listener is overwritten. To unset the listener again a null-pointer must be passed as
 *  listener argument.
 *
 *  Note:
 *  A listener registered already during creation of the <tt>IPrompter</tt> instance
 *  is muted as long as a listener is set and unmuted again when a listener is unset.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     listener   a listener that receives prompter notifications
 *
 *  @return Returns OK if set successfully, ERROR otherwise
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_setListener
(
    nuance_prompter_IPrompter *instance,
    nuance_prompter_IPrompterListener *listener
);


/**
 *  @brief  Analyzes the given \a text. <p>
 *
 *  This method splits the passed UTF8-encoded \a text block into segments using the underlying Cerence TTS Embedded API <tt>ve_ttsAnalyzeText</tt>.
 *  This may include rewriting of the input \a text according to loaded user rules.
 *  To be able to start text analysis a valid usecase must have been activated on the <tt>IPrompter</tt> instance.
 *
 *  This method is asynchronous and starts the text analysis as a
 *  background operation. This Prompter-related operation can be controlled
 *  via the <tt>nuance_common_IBackgroundOperation</tt> interface the
 *  <tt>IPrompter</tt> instance provides.
 *
 *  During the text analysis operation results and progress information are reported to the listener <tt>nuance_prompter_IPrompterListener</tt>.
 *  Each segmented text unit is sent to the application with <tt>nuance_prompter_IPrompterListener_onAnalyzeTextResult</tt>.
 *  The end of the text analysis operation is signaled with <tt>nuance_prompter_IPrompterListener_onAnalyzeTextFinished</tt>.
 *
 *  Warnings and errors that may occur during this operation are reported to
 *  the listener <tt>nuance_prompter_IPrompterListener</tt>.
 *
 *  The method returns an error result if the method is not supported by the underlying
 *  TTS engine, e.g. if using a cloud <tt>IPrompter</tt> instance.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     text   UTF8-encoded text block to analyze.
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_analyzeText
(
    nuance_prompter_IPrompter *instance,
    const LH_CHAR *text
);


/**
 *  @brief  Aborts all operations running or queued in the background. <p>
 *
 *  This method aborts all background operations that are running (or queued), and were previously
 *  initiated by any of the asynchronous calls:
 *  <tt>nuance_prompter_IPrompter_playString</tt>, <tt>nuance_prompter_IPrompter_playStringByFormat</tt>,
 *  <tt>nuance_prompter_IPrompter_playFile</tt>, <tt>nuance_prompter_IPrompter_playFileByFormat</tt>,
 *  <tt>nuance_prompter_IPrompter_activateUseCase</tt>, <tt>nuance_prompter_IPrompter_setParameter</tt>
 *  or <tt>nuance_prompter_IPrompter_setStringParameter</tt>, <tt>nuance_prompter_IPrompter_analyzeText</tt>.
 *  If a play operation of an <tt>IPrompt</tt> instance is being performed, the playback is stopped.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Returns OK if all commands are aborted successfully, ERROR otherwise.
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_abortAllOperations(nuance_prompter_IPrompter *instance);


/**
 *  @brief  Returns the sink and source pad name(s) of this SDK audio module. <p>
 *
 *  The pad names are given in the configuration of this audio module.
 *  In case this audio module does only have one single sink respectively source pad the pad name is equal to the instance name of this module.
 *  The pad names have to be unambiguous as they are used as identifier of a specific pad.
 *  They are used in conjunction with the instance name to establish/abolish pad connections.
 *  The pad name order in the list corresponds the descending order of the sink resp. source pads of this audio module.
 *
 *  This method is thread safe.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[out]    sinkPads     Sink pad name list of this audio module.
 *  @param[out]    sourcePads   Source pad name list of this audio module.
 *
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_getPadNames
(
    const nuance_prompter_IPrompter *instance,
    nuance_common_StringList **sinkPads,
    nuance_common_StringList **sourcePads
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
PROMPTER_C_EXPORT nuance_common_String *nuance_prompter_IPrompter_getName(const nuance_prompter_IPrompter *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_getStatus
(
    nuance_prompter_IPrompter *instance,
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
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_waitForCompletionWithTimeout
(
    nuance_prompter_IPrompter *instance,
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
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_waitForCompletion
(
    nuance_prompter_IPrompter *instance,
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
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_waitForCompletionAsync
(
    nuance_prompter_IPrompter *instance,
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
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_waitForCompletionWithTimeoutAsync
(
    nuance_prompter_IPrompter *instance,
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
PROMPTER_C_EXPORT nuance_common_ResultCode nuance_prompter_IPrompter_abortOperation(nuance_prompter_IPrompter *instance);


/**
 *  Destructor
 */
PROMPTER_C_EXPORT void nuance_prompter_IPrompter_destroy(nuance_prompter_IPrompter *);


PROMPTER_C_EXPORT nuance_audio_IAudioModule *nuance_prompter_IPrompter_as_nuance_audio_IAudioModule(nuance_prompter_IPrompter *obj);

PROMPTER_C_EXPORT nuance_common_IModule *nuance_prompter_IPrompter_as_nuance_common_IModule(nuance_prompter_IPrompter *obj);

PROMPTER_C_EXPORT nuance_common_IBackgroundOperation *nuance_prompter_IPrompter_as_nuance_common_IBackgroundOperation(nuance_prompter_IPrompter *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_IPROMPTER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
