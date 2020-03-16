/**
 * @file linux_wrapper_cerence.h
 * @author your name (vaibhav.pandey@germanautolabs.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */


/**
 *  @brief  This enumeration type describes the events which can occur during a recognizer run. <p>
 */
typedef enum
{ 
    LI_ASR5_RECOGNIZER_AUDIOSTREAM_RECEIVED,        /**< recognizer received the audio stream */
    LI_ASR5_RECOGNIZER_SPEECH_DETECTED,             /**< recognizer detected speech */
    LI_ASR5_RECOGNIZER_SILENCE_DETECTED,            /**< recognizer detected silence */
    LI_ASR5_RECOGNIZER_AUDIO_STOPPED,               /**< recognizer detected audio stopped */
    LI_ASR5_RECOGNIZER_AUDIO_FINISHED,              /**< recognizer detected audio finished */
    LI_ASR5_RECOGNIZER_ABNORMCOND_BADSNR,           /**< The signal to noise ratio is too low. */
    LI_ASR5_RECOGNIZER_ABNORMCOND_OVERLOAD,         /**< The speech level is too loud. */
    LI_ASR5_RECOGNIZER_ABNORMCOND_TOOQUIET,         /**< The speech level is too weak. */
    LI_ASR5_RECOGNIZER_ABNORMCOND_NOSIGNAL,         /**< No or very low input signal. */
    LI_ASR5_RECOGNIZER_EXTERNAL_PROVIDER_STARTED,   /**< external provider started to work. */
    LI_ASR5_RECOGNIZER_EXTERNAL_PROVIDER_FINISHED   /**< external provider finished processing audio. */
} li_asr5_RecogEvent;

/**
 * @brief Initalize and pass the configuration  to Cerence API
 * 
 */

int liwr_initConfig(void);


/**
 * @brief Initalize and pass the configuration  to Cerence API
 * 
 */

int liwr_startRecogniser(void);


/**
 * @brief Result of Recogniser from Cerence and passes to Application
 * 
 */

void liwr_recogResult(const char *result);

/**
 * @brief Event of Recogniser state 
 * 
 */

void liwr_recogEvent(li_asr5_RecogEvent event);

void liwr_executeCommands(const char *CommandStr);
