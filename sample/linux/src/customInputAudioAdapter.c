#include "customInputAudioAdapter.h"
#include "cJSON.h"
#include "stdbool.h"
void customAudioInputAdapter_packageCapturedWrapper_
(
  void *userData,
  const AudioIn_Int16 *audioBuffer,
  AudioIn_UInt32 sampleCount,
  AudioIn_Error  eErrorCode
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioInputAdapter *instance = LH_NULL;
  nuance_audio_IAudioInputAdapterListener_FlowState flowstate;
  AUDIOIN_LOG(((customAudioInputAdapter *) userData)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC,"Starting customInputAudioAdapter::customAudioInputAdapter_packageCapturedWrapper_()");

  /* check for valid error code */
  if (AUDIO_INPUT_OK != eErrorCode)
  {
    rc = NUANCE_COMMON_ERROR;
    AUDIOIN_LOG(((customAudioInputAdapter *) userData)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_packageCapturedWrapper_()- eErrorCode is not equal to AUDIO_INPUT_OK");
  }

  /* check for valid instance pointer */
  if (LH_NULL != userData)
  {
    instance = (customAudioInputAdapter *)userData;
    flowstate = NUANCE_AUDIO_IAUDIOINPUTADAPTERLISTENER_NORMAL;

    /* call IAudioInputAdapterListener's method to announce processed data */
    nuance_audio_IAudioInputAdapterListener_onAudioDataCaptured(instance->plistener, audioBuffer, sampleCount, AUDIOIN_FALSE, rc, &flowstate);
  }

  else
  {
   AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_packageCapturedWrapper_()- Invalid pointer for userdata");
  }
}

const LH_CHAR* customAudioInputAdapter_State_to_String
(
  enum State state
)
{
  switch(state)
  {
  case STATE_CLOSED:  return "STATE_CLOSED";
  case STATE_STOPPED: return "STATE_STOPPED";
  case STATE_STARTED: return "STATE_STARTED";
  default:            return "\"unknown state\"";
  }
}

nuance_common_ResultCode customAudioInputAdapter_configure
(
  void *instance,
  nuance_audio_IAudioInputAdapterListener *listener,
  const LH_CHAR *adapterParams,
  LH_BOOL interleavedFormat,
  LH_S32 channelCount,
  LH_S32 sampleRate,
  LH_S32 samplesPerChannel
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioInputAdapter *userdata = LH_NULL;
  AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC, "Starting customInputAudioAdapter::customAudioInputAdapter_configure()");

  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioInputAdapter *)instance))
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_configure()- Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for valid IAudioInputAdapterListener pointer */
  else if (LH_NULL == listener)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_configure()- Invalid pointer for nuance_audio_IAudioInputAdapterListener");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for valid number of channels */
  else if (0 >= channelCount)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_configure()- Invalid value for channelCount");
    userdata->audioin_err = AUDIO_INPUT_ERR_CH_CNT;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for valid sampleRate */
  else if (0 >= sampleRate)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_configure()- Invalid value for sampleRate");
    userdata->audioin_err = AUDIO_INPUT_ERR_SAMPLE_RATE;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for valid samplesPerChannel */
  else if (0 >= samplesPerChannel)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_configure()- Invalid value for samplesPerChannel");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for NULL audio input device handle */
  else if (LH_NULL != userdata->pAudioInHandle)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_configure()- Invalid AudioIn handle");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for closed state of adapter */
  else if (STATE_CLOSED != userdata->state_)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_configure()- State is not closed");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_STATE;
    rc = NUANCE_COMMON_ERROR;
  }

  else
  {
    /* parsing JSON string if adapter_params key is provided in *.json file containing audiopaths */
    if (LH_NULL != adapterParams)
    {
      /* creating cJSON object from the received json string */
      cJSON *padapterParams = cJSON_Parse(adapterParams);

      if (padapterParams != LH_NULL)
      {
        /* get 'device_name': REQ[no] MIN[n/a] MAX[n/a] DEF["plughw"] */
        if (cJSON_GetObjectItem(padapterParams, "device_name"))
        {
          userdata->deviceName = cJSON_GetObjectItem(padapterParams, "device_name")->valuestring;
          AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO,"Using device -> %s", userdata->deviceName);
          userdata->pAudioInParam.pDevIdentifier = calloc(strlen(userdata->deviceName)+1, sizeof(LH_CHAR));
          strcpy(userdata->pAudioInParam.pDevIdentifier, userdata->deviceName);
        }

        else
        {
          AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "No device_name provided in JSON. Using default -> plughw");
          userdata->pAudioInParam.pDevIdentifier = "plughw";
        }

        /* get 'platform_config': REQ[no] MIN[n/s] MAX[n/s] DEF[""] */
        if (cJSON_GetObjectItem(padapterParams, "platform_config"))
        {
          userdata->platformConfig = cJSON_GetObjectItem(padapterParams, "platform_config")->valuestring;
          AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO,"Audio Platform Specific Configurations -> %s", userdata->platformConfig);
          userdata->pAudioInParam.uPlatformSpecificConf = calloc(strlen(userdata->platformConfig)+1, sizeof(LH_CHAR));
          strcpy(userdata->pAudioInParam.uPlatformSpecificConf, userdata->platformConfig);
        }

        else
        {
          AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO,"No Audio Platform Specific Configurations provided in JSON. Using default -> \"\"");
          userdata->pAudioInParam.uPlatformSpecificConf = "";
        }
      }

      else
      {
        AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_configure()- Failed to parse adapterParams\n");
        userdata->audioin_err = AUDIO_INPUT_ERR_INTERNAL;
        rc = NUANCE_COMMON_ERROR;
      }
      /* destroying the cJSON object */
      cJSON_Delete(padapterParams);
    }

    else
    {
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "No device_name provided in JSON. Using default -> plughw");
      userdata->pAudioInParam.pDevIdentifier = "plughw";
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "No Audio Platform Specific Configurations provided in JSON. Using default -> \"\" ");
      userdata->pAudioInParam.uPlatformSpecificConf = "";
    }

    if(NUANCE_COMMON_OK == rc)
    {
      userdata->plistener = listener;
      userdata->pAudioInParam.uNumChannels = channelCount;
      userdata->pAudioInParam.uSampleRate = sampleRate;
      userdata->pAudioInParam.uSizeOfFrame = samplesPerChannel;
      userdata->pAudioInParam.uSizeOfFrameBuffer = samplesPerChannel;
      userdata->pAudioInParam.uVersionNum = AUDIOIN_AUDIO_VERSION;
      userdata->pAudioInParam.bFrameMuxFlag = 0;
      userdata->pAudioInParam.fpPackageCaptured = customAudioInputAdapter_packageCapturedWrapper_;
      userdata->pAudioInParam.udPackageCaptured = userdata;
      userdata->pAudioInParam.pLogModule = ((customAudioInputAdapter *) instance)->pLogModule;
    }
  }
  return rc;
}

nuance_common_ResultCode customAudioInputAdapter_open
(
  void *instance
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioInputAdapter *userdata = LH_NULL;
  AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC, "Starting customInputAudioAdapter::customAudioInputAdapter_open()");

  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioInputAdapter *)instance))
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_open() - Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for valid IAudioInputAdapterListener pointer */
  else if (LH_NULL == userdata->plistener)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_open() -Invalid pointer for IAudioInputAdapterListener");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;;
  }

  /* check for valid number of channels */
  else if (0 >= userdata->pAudioInParam.uNumChannels)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_open()- Invalid value for channelCount");
    userdata->audioin_err = AUDIO_INPUT_ERR_CH_CNT;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for valid sample rate */
  else if (0 >= userdata->pAudioInParam.uSampleRate)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_open()- Invalid value for sampleRate");
    userdata->audioin_err = AUDIO_INPUT_ERR_SAMPLE_RATE;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for valid size of a input frame */
  else if (0 >= userdata->pAudioInParam.uSizeOfFrame)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_open()- Invalid size of frame");
    userdata->audioin_err = AUDIO_INPUT_ERR_SIZE_PACK;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for NULL audio input device handle */
  else if (LH_NULL != userdata->pAudioInHandle)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_open()- Invalid AudioIn handle");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for closed state of the adapter */
  else if (STATE_CLOSED != userdata->state_)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_open()- State is not closed");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_STATE;
    rc = NUANCE_COMMON_ERROR;
  }

  else
  {
    /* open audio input device */
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Calling audioin::AudioIn_Open_Device()");
    userdata->audioin_err = AudioIn_Open_Device(&(userdata->pAudioInHandle), &(userdata->pAudioInParam));
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Returned from audioin::AudioIn_Open_Device()");

    if (AUDIO_INPUT_OK != userdata->audioin_err)
    {
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device() failed with error : %s ", audioin_ErrorGetString(userdata->audioin_err));
      rc = NUANCE_COMMON_ERROR;
    }

    else if (LH_NULL == userdata->pAudioInHandle)
    {
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device() returned an invalid handle");
      userdata->audioin_err = AUDIO_INPUT_ERR_INV_PARAM;
      rc = NUANCE_COMMON_ERROR;
    }

    else
    {
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO,"customInputAudioAdapter::customAudioInputAdapter_open()- Audio input device opened successfully.");
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "state transition: %s -> STATE_STOPPED.", customAudioInputAdapter_State_to_String(userdata->state_));

      /* state of adapter changed if open device is successful */
      userdata->state_ = STATE_STOPPED;
    }
  }
  return rc;
}

nuance_common_ResultCode customAudioInputAdapter_start
(
  void *instance
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioInputAdapter *userdata = LH_NULL;
  AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customInputAudioAdapter::customAudioInputAdapter_start()");

  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioInputAdapter *)instance))
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_start()- Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for valid audio input device handle */
  else if (LH_NULL == userdata->pAudioInHandle)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_start()- Invalid AudioIn handle");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for stopped but opened state of the adapter */
  else if (STATE_STOPPED != userdata->state_)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_start()- State is not stopped");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_STATE;
    rc = NUANCE_COMMON_ERROR;
  }

  else
  {
    /* start the capturing of audio data */
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "state transition: %s -> STATE_STARTED.", customAudioInputAdapter_State_to_String(userdata->state_));
    userdata->state_ = STATE_STARTED;

    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Calling audioin::AudioIn_Start()");
    userdata->audioin_err = AudioIn_Start(userdata->pAudioInHandle);
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Returned from audioin::AudioIn_Start()");

    if (AUDIO_INPUT_OK != userdata->audioin_err)
    {
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Start() failed with error: %s", audioin_ErrorGetString(userdata->audioin_err));
      rc = NUANCE_COMMON_ERROR;
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "state transition: %s -> STATE_STOPPED.", customAudioInputAdapter_State_to_String(userdata->state_));

      /* state of adapter changed if device cannot be started successfully */
      userdata->state_ = STATE_STOPPED;
    }

    else
    {
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "customInputAudioAdapter::customAudioInputAdapter_start() - Audio input device started successfully.");
    }
  }
  return rc;
}

nuance_common_ResultCode customAudioInputAdapter_stop
(
  void *instance
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioInputAdapter *userdata = LH_NULL;
  AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customInputAudioAdapter::customAudioInputAdapter_stop()");

  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioInputAdapter *)instance))
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_stop()- Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for valid audio input device handle */
  else if (LH_NULL == userdata->pAudioInHandle)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_stop()- Invalid AudioIn handle");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for started state of adapter */
  else if (STATE_STARTED != userdata->state_)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_stop()- State is not started");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_STATE;
    rc = NUANCE_COMMON_ERROR;
  }

  else
  {
    /* stop the capturing of audio data */
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Calling audioin::AudioIn_Stop()");
    userdata->audioin_err = AudioIn_Stop(userdata->pAudioInHandle);
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Returned from audioin::AudioIn_Stop()");

    if (AUDIO_INPUT_OK != userdata->audioin_err)
    {
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Stop() failed with error:  %s", audioin_ErrorGetString(userdata->audioin_err));
      rc = NUANCE_COMMON_ERROR;
    }

    else
    {
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "customInputAudioAdapter::customAudioInputAdapter_stop() - Audio input device stopped successfully.");
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "state transition: %s -> STATE_STOPPED.", customAudioInputAdapter_State_to_String(userdata->state_));

      /* state of adapter changed if capturing of audio has stopped successfully */
      userdata->state_ = STATE_STOPPED;
    }
  }
  return rc;
}

nuance_common_ResultCode customAudioInputAdapter_resume
(
  void *instance
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioInputAdapter *userdata = LH_NULL;
  AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customInputAudioAdapter::customAudioInputAdapter_resume()");

  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioInputAdapter *)instance))
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_resume()- Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for started state of adapter */
  else if (STATE_STARTED != userdata->state_)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_resume()- State is not started");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_STATE;
    rc = NUANCE_COMMON_ERROR;
  }
  return rc;
}

nuance_common_ResultCode customAudioInputAdapter_close
(
  void *instance
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  customAudioInputAdapter *userdata = LH_NULL;
  AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC, "Starting customInputAudioAdapter::customAudioInputAdapter_close()");

  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioInputAdapter *)instance))
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_close()- Invalid pointer for instance");
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for stopped but opened state of adapter */
  else if (STATE_STOPPED != userdata->state_)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_close()- State is not stopped");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_STATE;
    rc = NUANCE_COMMON_ERROR;
  }

  /* check for valid audio input device handle */
  else if (LH_NULL == userdata->pAudioInHandle)
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:-customInputAudioAdapter::customAudioInputAdapter_close()- Invalid AudioIn handle");
    userdata->audioin_err = AUDIO_INPUT_ERR_INV_PARAM;
    rc = NUANCE_COMMON_ERROR;
  }

  else
  {
    /* close the audio input device */
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Calling audioin::AudioIn_Close()");
    userdata->audioin_err = AudioIn_Close(&(userdata->pAudioInHandle));
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Returned from audioin::AudioIn_Close()");

    if (AUDIO_INPUT_OK != userdata->audioin_err)
    {
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Close() failed with error : %s", audioin_ErrorGetString(userdata->audioin_err));
      rc = NUANCE_COMMON_ERROR;
    }

    else if (LH_NULL != userdata->pAudioInHandle)
    {
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Close() returned an invalid handle");
      userdata->audioin_err = AUDIO_INPUT_ERR_INV_PARAM;
      rc = NUANCE_COMMON_ERROR;
    }

    else
    {
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "customInputAudioAdapter::customAudioInputAdapter_close()- Audio input device closed successfully.");
      AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INFO, "state transition: %s -> STATE_CLOSED.", customAudioInputAdapter_State_to_String(userdata->state_));

      /* state of adapter changed if audio device has closed successfully */
      userdata->state_ = STATE_CLOSED;
    }
  }
  return rc;
}

nuance_common_String* customAudioInputAdapter_getErrorText
(
  const void *instance
)
{
  const LH_CHAR *errorString;
  customAudioInputAdapter *userdata = LH_NULL;
  AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customInputAudioAdapter::customAudioInputAdapter_getErrorText()");

  /* check for valid instance pointer */
  if (LH_NULL == (userdata = (customAudioInputAdapter *)instance))
  {
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAudioAdapter::customAudioInputAdapter_getErrorText()- Invalid pointer for instance");
    errorString = "Instance pointer is NULL";
  }

  else
  {
    /* get the error text corresponding to the passed error code */
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Calling audioin::audioin_ErrorGetString()");
    errorString = audioin_ErrorGetString(userdata->audioin_err);
    AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Returned from audioin::audioin_ErrorGetString() ");
  }
  return nuance_common_String_create(errorString);
}

void customAudioInputAdapter_destroyAdapter
(
  void *instance
)
{
  AUDIOIN_LOG(((customAudioInputAdapter *) instance)->pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting customInputAudioAdapter::customAudioInputAdapter_destroyAdapter()");
  /* destructor call */
  nuance_audio_IAudioInputAdapter_destroy(((customAudioInputAdapter*)instance)->customAdapterInstance);
  AUDIOIN_FREESETNULL(instance);
}
