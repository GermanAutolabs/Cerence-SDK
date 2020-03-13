#include "customOutputAudioAdapter.h"
#include "cJSON.h"

static void customAudioOutputAdapter_packagePlayedWrapper_
(
  void *userData,
  const AudioOut_Int16 *audioBuffer
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioOutputAdapter *instance = LH_NULL;
  AUDIOOUT_LOG(((customAudioOutputAdapter *) userData)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customOutputAudioAdapter::customAudioOutputAdapter_packagePlayedWrapper_()");

  /* check for valid instance pointer */
  if (LH_NULL != userData)
  {
    instance = (customAudioOutputAdapter *)userData;
    
    /* call IAudioOutputAdapterListener's method to announce played audio data */
    nuance_audio_IAudioOutputAdapterListener_onAudioDataPlayed(instance->plistener, rc);
  }
  
  else
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_packagePlayedWrapper_()- Invalid pointer for userdata");
  }
}


nuance_common_ResultCode customAudioOutputAdapter_configure
(
  void *instance,
  nuance_audio_IAudioOutputAdapterListener *listener,
  const LH_CHAR *adapterParams,
  LH_BOOL interleavedFormat,
  LH_S32 channelCount,
  LH_S32 sampleRate,
  LH_S32 samplesPerChannel,
  LH_S32 bufferCount,
  const LH_CHAR *audioDataType
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioOutputAdapter *userdata = LH_NULL;
  AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC, "Starting customOutputAudioAdapter::customAudioOutputAdapter_configure()");

  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioOutputAdapter *)instance))
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_configure()- Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid IAudioOutputAdapterListener pointer */
  else if (LH_NULL == listener)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_configure()- Invalid pointer for nuance_audio_IAudioOutputAdapterListener");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid number of channels */
  else if (0 >= channelCount)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_configure()- Invalid value for channelCount");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_CH_CNT;
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid sampleRate */
  else if (0 >= sampleRate)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_configure()- Invalid value for sampleRate");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_SAMPLE_RATE;
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid samplesPerChannel */
  else if (0 >= samplesPerChannel)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_configure()- Invalid value for samplesPerChannel");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid buffer count */
  else if (0 >= bufferCount)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_configure()- Invalid Maximum number of frames");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_SIZE_DEV_BUF;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for supported type*/
  else if (LH_NULL == audioDataType)
  { 
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR,"ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_configure()- Invalid pointer for audioDataType");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }

  else if (strlen(audioDataType) != strlen("PCM16") || 0 != strcmp(audioDataType, "PCM16"))
  {
    
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_configure()- Invalid parameter audioDataType");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for NULL audio output device handle */
  else if (LH_NULL != userdata->pAudioOutHandle)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_configure()- Invalid AudioOut handle");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }

  else
  {
    /* parsing JSON string if adapter_params key is provided in *.json file containing audiopaths */
    if (LH_NULL != adapterParams)
    {
      /* creating cJSON object from the received json string */
      cJSON *padapterParams = cJSON_Parse(adapterParams);
      
      if (LH_NULL != padapterParams)
      {
        /* get 'device_name': REQ[no] MIN[n/a] MAX[n/a] DEF["plughw"] */
        if (cJSON_GetObjectItem(padapterParams, "device_name"))
        {
          userdata->deviceName = cJSON_GetObjectItem(padapterParams, "device_name")->valuestring;
          AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "Using device -> %s", userdata->deviceName);
          userdata->pAudioOutParam.pDevIdentifier = calloc(strlen(userdata->deviceName)+1, sizeof(LH_CHAR));
          strcpy(userdata->pAudioOutParam.pDevIdentifier, userdata->deviceName);
        }

        else
        {
          AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "No device_name provided in JSON. Using default -> plughw");
          userdata->pAudioOutParam.pDevIdentifier = "plughw";
        }

        /* get 'platform_config': REQ[no] MIN[n/s] MAX[n/s] DEF[""] */
        if (cJSON_GetObjectItem(padapterParams, "platform_config"))
        {
          userdata->platformConfig = cJSON_GetObjectItem(padapterParams, "platform_config")->valuestring;
          AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "Audio Platform Specific Configurations -> %s", userdata->platformConfig);
          userdata->pAudioOutParam.uPlatformSpecificConf = calloc(strlen(userdata->platformConfig)+1, sizeof(LH_CHAR));
          strcpy(userdata->pAudioOutParam.uPlatformSpecificConf, userdata->platformConfig);
        }

        else
        {
          AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "No Audio Platform Specific Configurations provided in JSON. Using default -> \"\" ");
          userdata->pAudioOutParam.uPlatformSpecificConf = "";
        }  
      }

      else
      {
        AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_configure()- Failed to parse adapterParams\n");
        userdata->audioout_err = AUDIO_OUTPUT_ERR_INTERNAL;
        rc = NUANCE_COMMON_ERROR;
      }
      /* destroying the cJSON object */
      cJSON_Delete(padapterParams);
    }
    
    else
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "No device_name provided in JSON. Using default -> plughw");
      userdata->pAudioOutParam.pDevIdentifier = "plughw";
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "No Audio Platform Specific Configurations provided in JSON. Using default -> \"\" ");
      userdata->pAudioOutParam.uPlatformSpecificConf = "";
    }
    if(NUANCE_COMMON_OK == rc)
    {
      userdata->plistener = listener;
      userdata->pAudioOutParam.uNumChannels = channelCount;
      userdata->pAudioOutParam.uSampleRate = sampleRate;
      userdata->pAudioOutParam.uMaxNumberFrames = bufferCount;
      userdata->pAudioOutParam.uMaxSizeFrame = samplesPerChannel;
      userdata->pAudioOutParam.uVersionNum = AUDIOOUT_AUDIO_VERSION;
      userdata->pAudioOutParam.bFrameMuxFlag = 0;
      userdata->pAudioOutParam.pLogModule = ((customAudioOutputAdapter *) instance)->pLogModule;
    }
  }
  return rc;
}

nuance_common_ResultCode customAudioOutputAdapter_open
(
  void *instance
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioOutputAdapter *userdata = LH_NULL;
  AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC, "Starting customOutputAudioAdapter::customAudioOutputAdapter_open()");
  
  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioOutputAdapter *)instance))
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_open() - Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid IAudioOutputAdapterListener pointer */
  else if (LH_NULL == userdata->plistener)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_open()- Invalid pointer for IAudioOutputAdapterListener");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;;
  }
  
  /* check for NULL audio output device handle */
  else if (LH_NULL != userdata->pAudioOutHandle)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_open() - Invalid AudioOut handle");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }
  
  else
  {
    /* open audio output device */
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Calling audioout::AudioOut_Open_Device()");
    userdata->audioout_err = AudioOut_Open_Device(&(userdata->pAudioOutHandle), &(userdata->pAudioOutParam));
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Returned from audioout::AudioOut_Open_Device()");
    
    if (AUDIO_OUTPUT_OK != userdata->audioout_err)
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device() failed with error : %s ", AudioOut_GetErrorText(userdata->audioout_err));
      rc = NUANCE_COMMON_ERROR;
    }
    
    else if (LH_NULL == userdata->pAudioOutHandle)
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device() returned an invalid handle");
      userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
      rc = NUANCE_COMMON_ERROR;
    }
      
    else
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO,"customOutputAudioAdapter::customAudioOutputAdapter_open() - Audio output device opened successfully.");
    }
  }
  return rc;
};

nuance_common_ResultCode customAudioOutputAdapter_write
(
  void *instance,
  LH_S16  const *audioData,
  LH_S32 naudioData
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioOutputAdapter *userdata = LH_NULL;
  AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customOutputAudioAdapter::customAudioOutputAdapter_write()");
  
  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioOutputAdapter *)instance))
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_write() - Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid audio data chunk */
  else if (LH_NULL == audioData)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_write() - Invalid audio data");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid number of audio data */
  else if (0 >= naudioData)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_write() - Invalid number of audio data");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_SIZE_PACK;
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid audio output device handle */
  else if (LH_NULL == userdata->pAudioOutHandle)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_write() - Invalid AudioOut handle");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid size of audio data chunk */
  else if (sizeof(audioData)/sizeof(LH_S16) > (userdata->pAudioOutParam.uNumChannels * userdata->pAudioOutParam.uMaxSizeFrame))
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_write() - Number of packages received has reached its max value ");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_MAX_NUM_PACK;
    rc = NUANCE_COMMON_ERROR;
  }
  
  else
  {
    /* write audio data to audio device */
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Calling audioout::AudioOut_Write()");
    userdata->audioout_err = AudioOut_Write(userdata->pAudioOutHandle, audioData, naudioData, customAudioOutputAdapter_packagePlayedWrapper_, userdata);
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Returned from audioout::AudioOut_Write()");
    
    if (AUDIO_OUTPUT_OK != userdata->audioout_err)
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Write() failed with error : %s ", AudioOut_GetErrorText(userdata->audioout_err));
      rc = NUANCE_COMMON_ERROR;
    }

    else
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_TIMING_ANALYSIS, "customOutputAudioAdapter::customAudioOutputAdapter_write() - Audio data written to output device .");
    }
  }
  return rc;
};

nuance_common_ResultCode customAudioOutputAdapter_writeEncoded
(
  void *instance,
  LH_S8 const *audioData,
  LH_S32 byteCount
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_ERROR;
  AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customOutputAudioAdapter::customAudioOutputAdapter_writeEncoded()");

  return rc;
};


nuance_common_ResultCode customAudioOutputAdapter_endOfStream
(
  void *instance
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioOutputAdapter *userdata = LH_NULL;
  AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customOutputAudioAdapter::customAudioOutputAdapter_endOfStream()");
  
  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioOutputAdapter *)instance))
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_endOfStream()- Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid audio output device handle */
  else if (LH_NULL == userdata->pAudioOutHandle)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_endOfStream() - Invalid AudioOut handle");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }

  else
  {
    /* send end of stream to audio device*/
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Calling audioout::AudioOut_EndOfStream()");
    userdata->audioout_err = AudioOut_EndOfStream(userdata->pAudioOutHandle);
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Returned from audioout::AudioOut_EndOfStream()");

    if (AUDIO_OUTPUT_OK != userdata->audioout_err)
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_EndOfStream() failed with error : %s ", AudioOut_GetErrorText(userdata->audioout_err));
      rc = NUANCE_COMMON_ERROR;
    }
  }
  return rc;
};

nuance_common_ResultCode customAudioOutputAdapter_abort
(
  void *instance
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioOutputAdapter *userdata = LH_NULL;
  AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customOutputAudioAdapter::customAudioOutputAdapter_abort()");
  
  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioOutputAdapter *)instance))
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_abort()- Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }
  
  /* check for valid audio output device handle */
  else if (LH_NULL == userdata->pAudioOutHandle)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_abort() - Invalid AudioOut handle");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }
  
  else
  {
    /* abort the audio */
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Calling audioout::AudioOut_Abort()");
    userdata->audioout_err = AudioOut_Abort(userdata->pAudioOutHandle);
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Returned from audioout::AudioOut_Abort()");
    
    if (AUDIO_OUTPUT_OK != userdata->audioout_err)
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Abort() failed with error : %s ", AudioOut_GetErrorText(userdata->audioout_err));
      rc = NUANCE_COMMON_ERROR;
    }
    
    else
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "customOutputAudioAdapter::customAudioOutputAdapter_abort()- Audio ouput device aborted successfully.");
    }
  }
  return rc;
};

nuance_common_ResultCode customAudioOutputAdapter_close
(
  void *instance
)
{    
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioOutputAdapter *userdata = LH_NULL;
  AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC, "Starting customOutputAudioAdapter::customAudioOutputAdapter_close()");
  
  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioOutputAdapter *)instance))
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_close()- Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for valid audio output device handle */
  else if (LH_NULL == userdata->pAudioOutHandle)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_close() - Invalid AudioOut handle");
    userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }

  else
  {
    /* close audio output device */
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Calling audioout::AudioOut_Close()");
    userdata->audioout_err = AudioOut_Close(&(userdata->pAudioOutHandle));
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Returned from audioout::AudioOut_Close()");
      
    if (AUDIO_OUTPUT_OK != userdata->audioout_err)
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Close() failed with error : %s ", AudioOut_GetErrorText(userdata->audioout_err));
      rc = NUANCE_COMMON_ERROR;
    }
      
    else if (LH_NULL != userdata->pAudioOutHandle)
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Close() returned an invalid handle");
      userdata->audioout_err = AUDIO_OUTPUT_ERR_INV_PARAM;
      rc = NUANCE_COMMON_ERROR;
    }
      
    else
    {
      AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "customOutputAudioAdapter::customAudioOutputAdapter_close() - Audio output device closed successfully.");
    }
  }
  return rc;
};

nuance_common_String* customAudioOutputAdapter_getErrorText
(
  const void *instance
)
{
  const LH_CHAR *errorString;
  customAudioOutputAdapter *userdata = LH_NULL;
  AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customOutputAudioAdapter::customAudioOutputAdapter_getErrorText()");
  
  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioOutputAdapter *)instance))
  {
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAudioAdapter::customAudioOutputAdapter_getErrorText()- Invalid pointer for instance");
    errorString = "Instance pointer is NULL";
  }
  
  else
  {
    /* get the error text corresponding to the passed error code */
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Calling audioout::AudioOut_GetErrorText()");
    errorString = AudioOut_GetErrorText(userdata->audioout_err);
    AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Returned from audioout::AudioOut_GetErrorText() ");
  }
  return nuance_common_String_create(errorString);
};

void customAudioOutputAdapter_destroyAdapter
(
  void *instance
)
{
  AUDIOOUT_LOG(((customAudioOutputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customOutputAudioAdapter::customAudioOutputAdapter_destroyAdapter()");
  /* destructor call */
  nuance_audio_IAudioOutputAdapter_destroy(((customAudioOutputAdapter*)instance)->customAdapterInstance);
  AUDIOOUT_FREE_SET_NULL(instance);
};
