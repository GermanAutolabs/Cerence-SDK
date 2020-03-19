/* ----------------------------------------------------------------------------------+
 | Module        : audioin                                                           |
 | File name     : audioin.c                                                         |
 | Description   : This module contains the open source audio input implementation   |
 |                 for Linux                                                          |
 | Reference(s)  : Linux interface reference documentation:                          |
 |                 https://www.alsa-project.org/alsa-doc/alsa-lib/pcm.html           |
 + ----------------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------+
 |   HEADER (INCLUDE) SECTION                                               |
 + -------------------------------------------------------------------------*/

#include "audioin.h"

/*+++++++++++++++++++++++++++++++++++++++++++++++++
 * Static functions local to this file
 ++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   This function checks the handed user
 *           audio version.
 *
 *  @param   uUserVersion
 *             [in] User  audio version.
 *
 *  @param   pLogModule
 *             [in] logging module instance.
 *
 *  @retval  AudioIn_TRUE
 *              No error occurred.
 *           AUDIOIN_FALSE
 *              An error occurred.
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static AudioIn_Bool AudioIn_CheckAudioVersion
(
  AudioIn_UInt32  uUserVersion,
  nuance_common_ILogModule *pLogModule
)
{
  AudioIn_Bool bResult = AUDIOIN_FALSE;

  /* check for valid parameter */
  if (0 == uUserVersion)
  {
    AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "ERROR:- audioin::AudioIn_CheckAudioVersion(): invalid parameter \'uUserVersion = 0\'.");
  }

  /* check for valid AUDIO version */
  /*disable lint error 778: (Info -- Constant expression evaluates to 0 in operation '&')*/
  else if ((((uUserVersion >> 16) & 0xff) != ((AUDIOIN_AUDIO_VERSION >> 16) & 0xff)) || (((uUserVersion >>  8) & 0xff)  > ((AUDIOIN_AUDIO_VERSION >>  8) & 0xff))) /*lint !e778*/
  {
    AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_CheckAudioVersion(): user main != main version or user sub != sub version.");
  }

  else
  {
    bResult = AUDIOIN_TRUE;
  }
  return bResult;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
*  @brief   This static function will open the handed device.
*
*  @param   phAudioDevice
*              [in] pointer to an audio device handle which has to be filled.
*
*  @param   pDevIdentifier
*              [in] ID of the device which has to be opened.
*
*  @param   iDevOperationMode
*              [in] operation mode of the device.
*
*  @param   pLogModule
*              [in] logging module instance.
*
*  @retval   0
*              No error occurred.
*           -1
*              An error occurred.
*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static AudioIn_Int AudioIn_Audio_OpenDevInternal
(
  snd_pcm_t **phAudioDevice,
  AudioIn_Char *pDevIdentifier,
  int iDevOperationMode,
  nuance_common_ILogModule *pLogModule
)
{
  AudioIn_Int iResult = 0;
  AudioIn_Int iASoundRes = 0;
  AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting audioin::AudioIn_Audio_OpenDevInternal ");

  /* check params */
  if (AUDIOIN_NULL == phAudioDevice || (SND_PCM_STREAM_PLAYBACK != iDevOperationMode && SND_PCM_STREAM_CAPTURE != iDevOperationMode))
  {
    AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_OpenDevInternal(): one or more parameter to the function are invalid.");
    iResult = -1;
  }

  else
  {
    AudioIn_Char *pDevName = AUDIOIN_NULL;
    AudioIn_Char *pWork = AUDIOIN_NULL;
    AudioIn_Char tmpDevName[AUDIO_DEV_STRING_SIZE];
    AudioIn_Bool bHandleAsName = AUDIOIN_FALSE;

    /* do we have a number */
    pWork = pDevIdentifier;
    while(('\0' != *pWork) && (AUDIOIN_FALSE == bHandleAsName))
    {
      if (('0' > *pWork) || ('9' < *pWork))
      {
        bHandleAsName = AUDIOIN_TRUE;
      }
      pWork++;
    }

    /* handle a number */
    if (AUDIOIN_FALSE == bHandleAsName)
    {
      AudioIn_Int32  iDevIdentifier = -1;

      /* get the handed number */
      iDevIdentifier = atol(pDevIdentifier);

      /* a returned value of 0 indicates an error if the handed string is unequal to the character '0' */
      if (0 == iDevIdentifier && '0' != *pDevIdentifier)
      {
        AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_OpenDevInternal(): atol() failed.");
        iResult = -1;
      }

      else
      {
        AudioIn_UInt32 uCardID = 0u;
        AudioIn_UInt32 uDevID = 0u;

        /* map id to card and device */
        if (10 > iDevIdentifier)
        {
          uCardID = 0x0u;
          uDevID  = (AudioIn_UInt32)iDevIdentifier;
        }

        else if (20 > iDevIdentifier)
        {
          uCardID = 0x1u;
          uDevID  = (AudioIn_UInt32)(iDevIdentifier - 10);
        }

        else if (30 > iDevIdentifier)
        {
          uCardID = 0x2u;
          uDevID  = (AudioIn_UInt32)(iDevIdentifier - 20);
        }

        else if (40 > iDevIdentifier)
        {
          uCardID = 0x3u;
          uDevID  = (AudioIn_UInt32)(iDevIdentifier - 30);
        }

        else
        {
          AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_OpenDevInternal(): invalid device identifier (%s).",pDevIdentifier);
          iResult = -1;
        }

        /* check for error */
        if (0 == iResult)
        {
          /* build the dev name */
          if (1 > snprintf((char*)tmpDevName,AUDIO_DEV_STRING_SIZE, AUDIO_DEV_STRING_MASK,uCardID,uDevID))
          {
            AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_OpenDevInternal(): snprintf() failed.");
            iResult = -1;
          }

          else
          {   /* return it */
            pDevName = &tmpDevName[0];
          }
        }
      } /* else of if (0 == iDevIdentifier && ... */
    }

    /* handle the string */
    else
    {
      const AudioIn_Char *pDevPrefix = (const AudioIn_Char *) "ADN_";

      /* check for audio device name prefix and cut it if necessary */
      if (0 == strncmp(pDevIdentifier, pDevPrefix, strlen(pDevPrefix)))
      {
        pDevName = pDevIdentifier + strlen(pDevPrefix);
      }

      /* just use the handed string */
      else
      {
        pDevName = pDevIdentifier;
      }
    }

    /* check for error */
    if (0 == iResult)
    {
      /* open the alsa device */
      AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Audio_OpenDevInternal(): snd_pcm_open(device=%s mode=%d)",  pDevName, iDevOperationMode);
      iASoundRes = snd_pcm_open(phAudioDevice, (char*)pDevName, iDevOperationMode,0);

      if (0 > iASoundRes)
      {
        AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_OpenDevInternal(): snd_pcm_open() failed with error = %i: %s",iASoundRes,snd_strerror(iASoundRes));
        iResult = -1;
      }
    }
  }
  return iResult;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
*  @brief   This static function reprepare the device if necessary.
*
*  @param   hAudioDevice
*              [in] pointer to an audio device handle
*
*  @param   iDevOperationMode
*              [in] operation mode of the device.
*
*  @param   pLogModule
*              [in] logging module instance.
*
*  @retval   0
*              No error occurred.
*           -1/-2
*              An error occurred.
*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static AudioIn_Int AudioIn_Audio_Prepare_Device
(
  snd_pcm_t *hAudioDevice,
  AudioIn_Int iDevOperationMode,
  nuance_common_ILogModule *pLogModule
)
{
  AudioIn_Int iResult = 0;
	AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting audioout::AudioOut_Audio_Prepare_Device ");

  /* check params */
  if (AUDIOIN_NULL == hAudioDevice)
  {
    AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_Prepare_Device(): invalid device handle \'hAudioDevice = NULL\'.");
    iResult = -1;
  }

  else
  {
    AudioIn_Int iASoundRes = 0;

    switch(snd_pcm_state(hAudioDevice))
    {
    case SND_PCM_STATE_SETUP: /*prepare*/
      iASoundRes = snd_pcm_prepare(hAudioDevice);

      if (0 > iASoundRes)
      {
        AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_Prepare_Device(): SND_PCM_STATE_SETUP: snd_pcm_prepare() failed with error = %i: %s",iASoundRes,snd_strerror(iASoundRes));
        iResult = -2;
      }

      else
      {
        AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Audio_Prepare_Device(SND_PCM_STATE_SETUP)");
      }

      break;

    case SND_PCM_STATE_XRUN: /* recover or prepare */
      iASoundRes = snd_pcm_prepare(hAudioDevice);

      if (0 > iASoundRes)
      {
        AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_Prepare_Device(): SND_PCM_STATE_XRUN: snd_pcm_prepare() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
        iResult = -2;
      }

      else
      {
        AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Audio_Prepare_Device(SND_PCM_STATE_XRUN)");
      }
      break;

    case SND_PCM_STATE_SUSPENDED: /* resume if possible or prepare */
      iASoundRes = snd_pcm_prepare(hAudioDevice);

      if (0 > iASoundRes)
      {
        AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_Prepare_Device(): SND_PCM_STATE_SUSPENDED: snd_pcm_prepare() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
        iResult = -2;
      }

      else
      {
        AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Audio_Prepare_Device(SND_PCM_STATE_SUSPENDED)");
      }
      break;

    case SND_PCM_STATE_PREPARED: /*nothing to do we are already prepared */
      AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Audio_Prepare_Device(SND_PCM_STATE_PREPARED)");
      break;

    case SND_PCM_STATE_RUNNING: /*nothing to do we are not prepared but already running so do not change that*/
      AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Audio_Prepare_Device(SND_PCM_STATE_RUNNING)");
      break;

    case SND_PCM_STATE_OPEN: /* error should not occur */
      AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_Prepare_Device(): SND_PCM_STATE_OPEN: unsupported device state, set hw parameter first.");
      iResult = -2;
      break;

    case SND_PCM_STATE_DRAINING: /* error should not occur, snd_pcm:drain is not used for input and blocking for output */
      AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_Prepare_Device(): SND_PCM_STATE_DRAINING: unsupported device state.");
      iResult = -2;
      break;

    case SND_PCM_STATE_PAUSED: /* error should not occur */
      AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_Prepare_Device(): SND_PCM_STATE_PAUSED: somebody paused the device.");
      iResult = -2;
      break;

    case SND_PCM_STATE_DISCONNECTED:  /* error should not occur */
      AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_Prepare_Device(): SND_PCM_STATE_DISCONNECTED: the device is not available.");
      iResult = -2;
      break;

    default: /* error should not occur */
      AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Audio_Prepare_Device(): unknown device state.");
      iResult = -2;
      break;
    } /* switch(snd_pcm_state(hAudioDevice)) */
  }
  return iResult;
}

/**********************************************************************/
/* internal thread functions                                         */
/**********************************************************************/

/**
* Reads the audio input data from the input device and
*   calls the callback function CbPackageCaptured() to send
*   the audio input data.
*
* @param  param
*          [in,out]  pointer to AudioIn
* @return No return value
*/

static void* ThAudioIn
(
 void *param
)
{
  AudioIn_Error eResult = AUDIO_INPUT_OK;
  AudioIn *pAudioIn = (AudioIn *)param;

  /* check params */
  if (AUDIOIN_NULL != pAudioIn)
  {
    AudioIn_Int  iASoundRes = 0;
    AudioIn_Bool bFinished = AUDIOIN_FALSE;
    AudioIn_Bool bProcessRequest = AUDIOIN_FALSE;
    EWaitResult eWaitResult = E_WAIT_OK;

    snd_pcm_sframes_t sFramesRead = 0;
    AudioIn_Bool bDeviceNotifications = AUDIOIN_FALSE;

    #ifdef DBGPRINTF
      snd_pcm_state_t prevAlsaState  = -1;
    #endif

    AudioIn_Int32 readPackageCnt = 0;

    AudioIn_Int16 *ppReadnBuffer[pAudioIn->uiChannelCount];

    /* prepare the data buffer */
    if (AUDIOIN_TRUE == pAudioIn->bNonInterleavedStream)
    {
      AudioIn_Int iChannelIndex;
      AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO: preparing non interleaved buffer");
      for (iChannelIndex=0;iChannelIndex<pAudioIn->uiChannelCount;iChannelIndex++)
      {
        ppReadnBuffer[iChannelIndex] = &(pAudioIn->pAudioWorkBuffer[iChannelIndex*pAudioIn->sFrameCountAudioWB]);
        AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "\t ppReadnBuffer[%d]-> pAudioWorkBuffer[%lu]",iChannelIndex, iChannelIndex*pAudioIn->sFrameCountAudioWB);
      }
    }

    /* thread main loop
    ----------------------*/

    while (AUDIOIN_FALSE == bFinished)
    {
      eResult = AUDIO_INPUT_OK;
      eWaitResult = E_WAIT_OK;
      /* wait for messages
      ----------------------*/

      /* NOTE: use an extra flag to prevent race conditions with the eState variable
      --------------------------------------------------------------------------------*/
      if (AUDIOIN_FALSE == bDeviceNotifications)
      {
        /* wait for interface
        -----------------------*/
        AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO: waiting for interface ... ");
        AudioIn_SemaWait(pAudioIn->pThreadCtrlSema, pAudioIn->pLogModule);
        AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "done");
        bProcessRequest = AUDIOIN_TRUE;
      }

      else
      {
        /* wait for driver
        -----------------------*/
        AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO: waiting for device ... ");
        if (AUDIOIN_NULL != pAudioIn->hAudioIn)
        {
          iASoundRes = snd_pcm_wait(pAudioIn->hAudioIn, pAudioIn->iWaitTimeout);
        }

        AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO: done");

        if (0 >= iASoundRes) /* error / timeout */
        {
          AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn()[%s]: snd_pcm_wait() failed with %s = %i: %s", pAudioIn->pDevName, (0 == iASoundRes) ? "timeout" : "error", iASoundRes, snd_strerror(iASoundRes));
          eWaitResult = E_WAIT_ERROR;
        }

        /* process even in case of an error or timeout to recover correctly
          ---------------------------------------------------------------------------------*/
        bProcessRequest = AUDIOIN_TRUE;
      }

      AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "************************");
      /* enter only if necessary */
      if (AUDIOIN_TRUE == bProcessRequest)
      {
        /* get the mutex */
        if (0 != pthread_mutex_lock(&(pAudioIn->pMutex->hMutex)))
        {
          AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn(): pthread_mutex_lock() failed");
        }

        else
        {
          if (AUDIOIN_NULL == pAudioIn->hAudioIn)
          {
            AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn(): invalid audio handle - \"AUDIOIN_NULL == pAudioIn->hAudioIn\" !");
            bProcessRequest = AUDIOIN_FALSE;
            bDeviceNotifications = AUDIOIN_FALSE;
          }

          else
          {
            #ifdef DBGPRINTF
              /* --------------------------------------------------------------------------------------------------
               * - begin debug section
               * --------------------------------------------------------------------------------------------------*/
              snd_pcm_state_t currentAlsaState = snd_pcm_state(pAudioIn->hAudioIn);

              /* get the device state and print it if changed */
              if (prevAlsaState != currentAlsaState)
              {
                AudioIn_Char *stateName = AUDIOIN_NULL;

                switch(currentAlsaState)
                {
                case SND_PCM_STATE_OPEN:         stateName = (AudioIn_Char*)"SND_PCM_STATE_OPEN";         break;
                case SND_PCM_STATE_SETUP:        stateName = (AudioIn_Char*)"SND_PCM_STATE_SETUP";        break;
                case SND_PCM_STATE_PREPARED:     stateName = (AudioIn_Char*)"SND_PCM_STATE_PREPARED";     break;
                case SND_PCM_STATE_RUNNING:      stateName = (AudioIn_Char*)"SND_PCM_STATE_RUNNING";      break;
                case SND_PCM_STATE_XRUN:         stateName = (AudioIn_Char*)"SND_PCM_STATE_XRUN";         break;
                case SND_PCM_STATE_DRAINING:     stateName = (AudioIn_Char*)"SND_PCM_STATE_DRAINING";     break;
                case SND_PCM_STATE_PAUSED:       stateName = (AudioIn_Char*)"SND_PCM_STATE_PAUSED";       break;
                case SND_PCM_STATE_SUSPENDED:    stateName = (AudioIn_Char*)"SND_PCM_STATE_SUSPENDED";    break;
                case SND_PCM_STATE_DISCONNECTED: stateName = (AudioIn_Char*)"SND_PCM_STATE_DISCONNECTED"; break;
                default:                         stateName = (AudioIn_Char*)"SND_PCM_STATE UNKNOWN !!!";  break;
                }

                AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO (%s): DevState changed to: %s",pAudioIn->pDevName, stateName);
                prevAlsaState = currentAlsaState;
              }

              /* --------------------------------------------------------------------------------------------------
               * - end debug section
               * --------------------------------------------------------------------------------------------------*/
            #endif

            /* check current eState and perform appropriate action
            --------------------------------------------------------*/

            switch (pAudioIn->eState)
            {
            case E_WAVE_STATE_CAPTURING: /* capture data */

              /* wait returned successfully
              -------------------------------*/
              if (E_WAIT_OK == eWaitResult)
              {
                AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO: AudioState: E_WAVE_STATE_CAPTURING: reading expecting frames (%lu) ... ", pAudioIn->sFrameCountAudioWB);

                if (pAudioIn->bNonInterleavedStream == AUDIOIN_TRUE)
                {
                  sFramesRead = snd_pcm_readn(pAudioIn->hAudioIn, (void **) ppReadnBuffer, pAudioIn->sFrameCountAudioWB);
                }

                else
                {
                  sFramesRead = snd_pcm_readi(pAudioIn->hAudioIn, pAudioIn->pAudioWorkBuffer, pAudioIn->sFrameCountAudioWB);
                }

                if (AUDIO_DEV_DEBUG_INTERVAL <= ++readPackageCnt)
                {
                  AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO (%s): processed %d packages",pAudioIn->pDevName, readPackageCnt);
                  readPackageCnt=0;
                }
                AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "done. got %lu frames", sFramesRead);
              }

              /* set the read result variable equal the wait error value and do the common error handling.
              --------------------------------------------------------------------------------------------------*/
              else
              {
                AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO: AudioState: Handle Wait Error ... ");
                sFramesRead = iASoundRes;
              }

              /* error handling of read and wait.
               * in case sFramesRead = 0 check eWaitResult
              ----------------------------------------------*/
              if ((0 > sFramesRead) || (E_WAIT_OK != eWaitResult))
              {
                iASoundRes = sFramesRead;

                /* timeout error will not be handled further.
                -----------------------------------------------*/
                if (0 == sFramesRead)
                {
                  AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn()[%s]: snd_pcm_wait() wait timeout error.", pAudioIn->pDevName);
                  eResult = AUDIO_INPUT_ERR_READ_DEV;
                }

                else
                {
                  AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn()[%s]: %s failed with error = %i: %s. Try to recover.", pAudioIn->pDevName, (E_WAIT_OK != eWaitResult) ? "snd_pcm_wait()" : "snd_pcm_read()", iASoundRes, snd_strerror(iASoundRes));
                  eResult = AUDIO_INPUT_ERR_READ_DEV;
                  sFramesRead = 0;

                  /* try silent recovery */
                  iASoundRes = snd_pcm_recover(pAudioIn->hAudioIn, iASoundRes, 1);

                  if (0 > iASoundRes)
                  {
                    AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn()[%s]: snd_pcm_recover() failed with error = %i: %s", pAudioIn->pDevName, iASoundRes, snd_strerror(iASoundRes));
                  }

                  else
                  {
                    /* restart capturing after successful recovery */
                    iASoundRes = snd_pcm_start(pAudioIn->hAudioIn);

                    if (0 > iASoundRes)
                    {
                      AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn()[%s]: snd_pcm_start() failed with error = %i: %s", pAudioIn->pDevName, iASoundRes, snd_strerror(iASoundRes));
                    }
                  }
                }
              }

              /* OK: handle the valid data
              --------------------------*/
              else
              {
                /* check amount of data currently read
                -----------------------------------------*/
                if (sFramesRead < (AudioIn_Int)pAudioIn->sFrameCountAudioWB)
                {
                  AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn()[%s]:", pAudioIn->pDevName);
                  eResult = AUDIO_INPUT_ERR_READ_DEV;
                }
              }

              if (AUDIOIN_NULL != pAudioIn->fpPackageCaptured)
              {
                /* call user callback */
                pAudioIn->fpPackageCaptured(pAudioIn->udPackageCaptured, pAudioIn->pAudioWorkBuffer, (sFramesRead*pAudioIn->uiChannelCount), eResult);
              }
              break;

            case E_WAVE_STATE_STARTING: /* prepare for capturing */
              AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO: current AudioState: EWavwStateStarting");
              pAudioIn->eState = E_WAVE_STATE_CAPTURING;
              bDeviceNotifications = AUDIOIN_TRUE;
              iASoundRes = snd_pcm_start(pAudioIn->hAudioIn);

              if (0 > iASoundRes)
              {
                AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn()[%s]: snd_pcm_start() failed with error = %i: %s", pAudioIn->pDevName, iASoundRes, snd_strerror(iASoundRes));
              }
              break;

            case E_WAVE_STATE_STOPPING:  /* stop capturing */
              /* handle stopping eState */
              AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO: current AudioState: EWavwStateStopping");
              pAudioIn->eState = E_WAVE_STATE_WAITING;
              bDeviceNotifications = AUDIOIN_FALSE;

              /* clean the buffers */
              iASoundRes = snd_pcm_drop(pAudioIn->hAudioIn);

              if (0 > iASoundRes)
              {
                AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn()[%s]: snd_pcm_drop() failed with error = %i: %s", pAudioIn->pDevName, iASoundRes, snd_strerror(iASoundRes));
              }

              /* prepare for next use */
              if (0 != AudioIn_Audio_Prepare_Device(pAudioIn->hAudioIn, SND_PCM_STREAM_CAPTURE, pAudioIn->pLogModule))
              {
                AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn()[%s]: AudioIn_Audio_Prepare_Device() failed.", pAudioIn->pDevName);
              }

              /* notify caller that thread is stopped */
              AudioIn_SemaSignal(pAudioIn->pFeedbackSema, pAudioIn->pLogModule);
              break;

            case E_WAVE_STATE_IDLE: /* notify caller that thread is started */
              AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO: current  AudioState: EWavwStateIdle");
              bDeviceNotifications = AUDIOIN_FALSE;
              AudioIn_SemaSignal(pAudioIn->pFeedbackSema, pAudioIn->pLogModule);
              break;

            case E_WAVE_STATE_CLOSING: /* exit thread loop */
              /* clean the buffers, just in case ... */
              AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO: current  AudioState: E_WAVE_STATE_CLOSING");

              iASoundRes = snd_pcm_drop(pAudioIn->hAudioIn);

              if (0 > iASoundRes)
              {
                AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn()[%s]: snd_pcm_drop() failed with error = %i: %s", pAudioIn->pDevName, iASoundRes, snd_strerror(iASoundRes));
              }

              /* exit thread loop */
              bFinished = AUDIOIN_TRUE;
              break;

            default: /* nothing to do */
              AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_INFO, "AIT INFO: current  AudioState: default (%d)", pAudioIn->eState);
              bDeviceNotifications = AUDIOIN_FALSE;
              break;

            } /* switch(pAudioIn->eState)*/
          } /* else of if (AUDIOIN_NULL == pAudioIn->hAudioIn) */

          if (0 != pthread_mutex_unlock(&(pAudioIn->pMutex->hMutex)))
          {
            AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::ThAudioIn(): pthread_mutex_lock() failed");
            eResult = AUDIO_INPUT_ERR_INTERNAL;
          }
        } /* else of if (0 != AudioIn_MutexWait(pAudioIn->pMutex)) */
      } /* if (AUDIOIN_TRUE == bProcessRequest) */
    } /* while (AUDIOIN_FALSE == bFinished)*/
  }
  return 0;
}

AudioIn_Error AudioIn_SemaInit
(
  AudioIn_Sema **ppSema,
  AudioIn_UInt32 initCount,
  nuance_common_ILogModule *pLogModule
)
{
  AudioIn_Sema *pSema = AUDIOIN_NULL;
  AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting AudioIn::AudioIn_SemaInit \n");

  /* check parameters */

  if (AUDIOIN_NULL == ppSema)
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  (*ppSema) = AUDIOIN_NULL;

  /* create an unnamed semaphore */

  pSema = (AudioIn_Sema*)calloc(1U, sizeof(AudioIn_Sema));

  if (pSema == AUDIOIN_NULL)
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  /* set sema parameters */
  pSema->n = initCount;

  /* init the internal mutex */
  if (pthread_mutex_init(&pSema->mutex, AUDIOIN_NULL))
  {
    free(pSema);
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  /* init the internal wait condition */
  if (pthread_cond_init(&pSema->cond, AUDIOIN_NULL))
  {
    if (pthread_mutex_destroy(&pSema->mutex))
    {
      return  AUDIO_INPUT_ERR_INTERNAL;
    }

    free(pSema);
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  /* set the result value */
  *ppSema = pSema;
  return  AUDIO_INPUT_OK;
}

AudioIn_Error AudioIn_SemaDeInit
(
  AudioIn_Sema **ppSema,
  nuance_common_ILogModule *pLogModule
)
{
  AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting AudioIn::AudioIn_SemaDeInit \n");
  AudioIn_Sema *pSema = AUDIOIN_NULL;
  AudioIn_Int32 rc = 0;

  /* check parameters */

  if (AUDIOIN_NULL == ppSema)
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  if (AUDIOIN_NULL == *ppSema)
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  pSema = *ppSema;

  /* remove the wait condition */
  rc = pthread_cond_destroy(&pSema->cond);
  if ((0 != rc) && (EBUSY != rc))
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  while (EBUSY == rc)
  {
    pthread_cond_signal(&pSema->cond);
    rc = pthread_cond_destroy(&pSema->cond);
    AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INFO,"Required extra signal");
  }

  /* remove sema's mutex */
  if (pthread_mutex_destroy(&pSema->mutex))
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  AUDIOIN_FREESETNULL(*ppSema);
  return  AUDIO_INPUT_OK;
}

AudioIn_Error AudioIn_SemaSignal
(
  AudioIn_Sema *pSema,
  nuance_common_ILogModule *pLogModule
)
{
  AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting AudioIn::AudioIn_SemaSignal \n");
  /* check parameters */

  if (AUDIOIN_NULL == pSema)
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  /* lock the mutex for semaphore access */
  if (pthread_mutex_lock(&pSema->mutex))
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  /* increment */
  ++(pSema->n);

  /* wakeup one waiting thread */
  if (pthread_cond_signal(&pSema->cond))
  {
    pthread_mutex_unlock(&pSema->mutex);
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  /* unlock the mutex */
  if (pthread_mutex_unlock(&pSema->mutex))
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }
  return  AUDIO_INPUT_OK;
}

AudioIn_Error AudioIn_SemaWait
(
  AudioIn_Sema *pSema,
  nuance_common_ILogModule *pLogModule
)
{
  AUDIOIN_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting AudioIn::AudioIn_SemaWait \n");
  /* check parameters */
  if (AUDIOIN_NULL == pSema)
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  /* lock the mutex */
  if (pthread_mutex_lock(&pSema->mutex))
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }

  /* wait until sema's count is at least 1 */
  /* the loop is required because all waiting threads will wake up on */
  /* the wait condition */
  while (pSema->n < 1)
  {
    /* wait condition waits until it is signaled by Signal */
    if (pthread_cond_wait(&pSema->cond, &pSema->mutex))
    {
      pthread_mutex_unlock(&pSema->mutex);
      return  AUDIO_INPUT_ERR_INTERNAL;
    }
  }

  /* decrement the count */
  --(pSema->n);

  /* release the mutex */
  if (pthread_mutex_unlock(&pSema->mutex))
  {
    return  AUDIO_INPUT_ERR_INTERNAL;
  }
  return  AUDIO_INPUT_OK;
}

const AudioIn_Char* audioin_ErrorGetString
(
  AudioIn_Int32 errorCode    /**< [in] The Error code.*/
)
{
  const AudioIn_Char *string;

  switch (errorCode)
  {
  case AUDIO_INPUT_OK:               string = AUDIOIN_STRLIT2CSTR("No Error.");break;
  case AUDIO_INPUT_ERR_INV_PARAM:    string = AUDIOIN_STRLIT2CSTR("One or more parameter to the function are invalid.");break;
  case AUDIO_INPUT_ERR_INTERNAL:     string = AUDIOIN_STRLIT2CSTR("An internal error occurred.");break;
  case AUDIO_INPUT_ERR_INV_DEV_ID:   string = AUDIOIN_STRLIT2CSTR("The device identifier of the audio device is invalid.");break;
  case AUDIO_INPUT_ERR_SAMPLE_RATE:  string = AUDIOIN_STRLIT2CSTR("The sample rate is not supported from audio device.");break;
  case AUDIO_INPUT_ERR_SIZE_DEV_BUF: string = AUDIOIN_STRLIT2CSTR("The audio device buffer size is not supported.");break;
  case AUDIO_INPUT_ERR_SIZE_PACK:    string = AUDIOIN_STRLIT2CSTR("The audio package size is not valid.");break;
  case AUDIO_INPUT_ERR_OPEN_DEV:     string = AUDIOIN_STRLIT2CSTR("An error occurred while opening the audio device.");break;
  case AUDIO_INPUT_ERR_CLEAR_DEV_BUF:string = AUDIOIN_STRLIT2CSTR("An error occurred while clearing the audio device buffer.");break;
  case AUDIO_INPUT_ERR_START_DEV:    string = AUDIOIN_STRLIT2CSTR("An error occurred while starting the audio device.");break;
  case AUDIO_INPUT_ERR_READ_DEV:     string = AUDIOIN_STRLIT2CSTR("An error occurred while reading from the audio device.");break;
  case AUDIO_INPUT_ERR_STOP_DEV:     string = AUDIOIN_STRLIT2CSTR("An error occurred while stopping the audio device.");break;
  case AUDIO_INPUT_ERR_CLOSE_DEV:    string = AUDIOIN_STRLIT2CSTR("An error occurred while closing the audio device.");break;
  case AUDIO_INPUT_ERR_VERSION:      string = AUDIOIN_STRLIT2CSTR("An error occurred because of incompatible  versions.");break;
  case AUDIO_INPUT_ERR_CH_CNT:       string = AUDIOIN_STRLIT2CSTR("An error occurred because of invalid channel count.");break;
  case AUDIO_INPUT_ERR_INV_STATE:    string = AUDIOIN_STRLIT2CSTR("An error occurred because of invalid state.");break;
  default:                           string = AUDIOIN_STRLIT2CSTR("Invalid error code.");break;
  }
  return string;
} /* audioin_ErrorGetString */

AudioIn_Error AudioIn_Close
(
 AudioIn **ppAudioIn
)
{
  AudioIn_Error eResult = AUDIO_INPUT_OK;
  AudioIn  *pTmpAudioIn = AUDIOIN_NULL;
  void *pThreadExitCode = AUDIOIN_NULL;
  AudioIn_Int32     rc    = 0;

  /* check params */
  if (AUDIOIN_NULL == ppAudioIn)
  {
    eResult = AUDIO_INPUT_ERR_INV_PARAM;
  }

  else if (AUDIOIN_NULL == *ppAudioIn)
  {
    eResult = AUDIO_INPUT_ERR_INV_PARAM;
  }

  else
  {
    /* get the mutex if possible */
    if (AUDIOIN_NULL != (*ppAudioIn)->pMutex)
    {
      pthread_mutex_lock(&((*ppAudioIn)->pMutex->hMutex));
    }

    /* check eState */
    if (E_WAVE_STATE_IDLE != (*ppAudioIn)->eState  && E_WAVE_STATE_WAITING != (*ppAudioIn)->eState)
    {
      AUDIOIN_LOG((*ppAudioIn)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Close(): invalid state = %d.", (*ppAudioIn)->eState);
      eResult = AUDIO_INPUT_ERR_CLOSE_DEV;

      /* signale the mutex if possible */
      if (AUDIOIN_NULL != (*ppAudioIn)->pMutex)
      pthread_mutex_unlock(&((*ppAudioIn)->pMutex->hMutex));
    }

    else
    {
      AudioIn_Int iASoundRes;

      /* invalidate handle */
      pTmpAudioIn  = (*ppAudioIn);
      (*ppAudioIn) = AUDIOIN_NULL;

      pTmpAudioIn->eState = E_WAVE_STATE_CLOSING;

      /* wake the thread */
      if (AUDIOIN_NULL != pTmpAudioIn->pThreadCtrlSema)
      {
        AudioIn_SemaSignal(pTmpAudioIn->pThreadCtrlSema, pTmpAudioIn->pLogModule);
      }

      if (AUDIOIN_NULL != pTmpAudioIn->pMutex)
      {
        pthread_mutex_unlock(&(pTmpAudioIn->pMutex->hMutex));
      }

      /* wait for the thread */
      pthread_join(pTmpAudioIn->threadIdentifier, AUDIOIN_NULL);

      if (AUDIOIN_NULL != pTmpAudioIn->pMutex)
      {
        pthread_mutex_lock(&(pTmpAudioIn->pMutex->hMutex));
      }

      /* close the device */
      if (AUDIOIN_NULL != pTmpAudioIn->hAudioIn)
      {
        iASoundRes = snd_pcm_close(pTmpAudioIn->hAudioIn);

        if (0 > iASoundRes)
        {
          AUDIOIN_LOG(pTmpAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Close():snd_pcm_close() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
        }
      }

      /* clean up the dev name */
      if (AUDIOIN_NULL != pTmpAudioIn->pDevName)
      {
        AUDIOIN_FREESETNULL(pTmpAudioIn->pDevName);
      }

      /* clean up the work buffer */
      if (AUDIOIN_NULL != pTmpAudioIn->pAudioWorkBuffer)
      {
        AUDIOIN_FREESETNULL(pTmpAudioIn->pAudioWorkBuffer);
      }

      /* deinit the needed semaphores */
      if (AUDIOIN_NULL != pTmpAudioIn->pThreadCtrlSema)
      {
        AudioIn_SemaDeInit(&pTmpAudioIn->pThreadCtrlSema, pTmpAudioIn->pLogModule);
      }

      if (AUDIOIN_NULL != pTmpAudioIn->pFeedbackSema)
      {
        AudioIn_SemaDeInit(&pTmpAudioIn->pFeedbackSema, pTmpAudioIn->pLogModule);
      }

      if (AUDIOIN_NULL != pTmpAudioIn->pMutex)
      {
        pthread_mutex_destroy(&((pTmpAudioIn->pMutex)->hMutex));
        if (AUDIOIN_FALSE == (pTmpAudioIn->pMutex)->noAlloc)
        {
          AUDIOIN_FREESETNULL(pTmpAudioIn->pMutex);
        }
      }
      AUDIOIN_FREESETNULL(pTmpAudioIn);
    }
  }
  return eResult;
}

AudioIn_Error AudioIn_Start
(
  AudioIn *pAudioIn
)
{
  AudioIn_Error eResult = AUDIO_INPUT_OK;
  /* check param */
  if (AUDIOIN_NULL == pAudioIn)
  {
    eResult = AUDIO_INPUT_ERR_INV_PARAM;
  }

  /* get mutex */
  else if (0 != pthread_mutex_lock(&(pAudioIn->pMutex->hMutex)))
  {
    AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Start(): pthread_mutex_lock() failed.");
    eResult = AUDIO_INPUT_ERR_INTERNAL;
  }

  else
  {
    /* check eState */
    if (pAudioIn->eState != E_WAVE_STATE_WAITING)
    {
      AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Start(): invalid state = %d.",pAudioIn->eState);
      eResult = AUDIO_INPUT_ERR_START_DEV;
    }

    else
    {
      pAudioIn->eState = E_WAVE_STATE_STARTING;

      /* wake thread */
      if (0 != AudioIn_SemaSignal(pAudioIn->pThreadCtrlSema, pAudioIn->pLogModule))
      {
        AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Start(): AudioIn_SemaSignal() failed.");
        eResult = AUDIO_INPUT_ERR_INTERNAL;
      }
    }

    /* release mutex */
    if (0 != pthread_mutex_unlock(&(pAudioIn->pMutex->hMutex)))
    {
      AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Start(): pthread_mutex_unlock() failed.");
      eResult = AUDIO_INPUT_ERR_INTERNAL;
    }
  }
  return eResult;
}

AudioIn_Error AudioIn_Stop
(
  AudioIn *pAudioIn
)
{
  AudioIn_Error eResult  = AUDIO_INPUT_OK;

  if (AUDIOIN_NULL == pAudioIn)
  {
    eResult = AUDIO_INPUT_ERR_INV_PARAM;
  }

  /* get mutex */
  else if (0 != pthread_mutex_lock(&(pAudioIn->pMutex->hMutex)))
  {
    AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "AudioIn_Stop(): pthread_mutex_lock() failed.");
    eResult = AUDIO_INPUT_ERR_INTERNAL;
  }

  else
  {
    /* check eState */
    if (pAudioIn->eState != E_WAVE_STATE_STARTING && pAudioIn->eState != E_WAVE_STATE_CAPTURING)
    {
      AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "AudioIn_Stop(): invalid state = %d.",pAudioIn->eState);
      eResult = AUDIO_INPUT_ERR_STOP_DEV;
    }

    else
    {
      /* stop input on audio input device */
      pAudioIn->eState = E_WAVE_STATE_STOPPING;

      /* wake the thread */
     if (0 != AudioIn_SemaSignal(pAudioIn->pThreadCtrlSema, pAudioIn->pLogModule))
      {
        AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "AudioIn_Stop(): AudioIn_SemaSignal() failed.");
        eResult = AUDIO_INPUT_ERR_INTERNAL;
      }

      /* release mutex */
      if (0 != pthread_mutex_unlock(&(pAudioIn->pMutex->hMutex)))
      {
        AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "AudioIn_Stop(): pthread_mutex_unlock() failed.");
        eResult = AUDIO_INPUT_ERR_INTERNAL;
      }

      /* and wait for response */
      if (0 != AudioIn_SemaWait(pAudioIn->pFeedbackSema, pAudioIn->pLogModule))
      {
        AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "AudioIn_Stop(): AudioIn_SemaWait() failed.");
        eResult = AUDIO_INPUT_ERR_INTERNAL;
      }

      /* get mutex */
      if (0 != pthread_mutex_lock(&(pAudioIn->pMutex->hMutex)))
      {
        AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "AudioIn_Stop():pthread_mutex_lock() failed.");
        eResult = AUDIO_INPUT_ERR_INTERNAL;
      }

      /* check eState */
      if (pAudioIn->eState != E_WAVE_STATE_WAITING)
      {
        AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "AudioIn_Stop(): invalid state = %d.",pAudioIn->eState);
        eResult = AUDIO_INPUT_ERR_STOP_DEV;
      }
    }

    /* release mutex */
    if (0 != pthread_mutex_unlock(&(pAudioIn->pMutex->hMutex)))
    {
      AUDIOIN_LOG(pAudioIn->pLogModule, NUANCE_COMMON_LOG_ERROR, "AudioIn_Stop(): pthread_mutex_unlock() failed.");
      eResult = AUDIO_INPUT_ERR_INTERNAL;
    }
  }
  return eResult;
}

AudioIn_Error AudioIn_Open_Device
(
  AudioIn **ppAudioIn,
  AudioIn_Params *pAudioInParams
)
{
  AudioIn_Error eResult = AUDIO_INPUT_OK;

  /* check param */
  if (AUDIOIN_NULL == pAudioInParams)
  {
    eResult = AUDIO_INPUT_ERR_INV_PARAM;
  }

  /* check audioin handle */
  else if (AUDIOIN_NULL == ppAudioIn)
  {
    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): invalid parameter \'ppAudioIn = NULL\' (must not be NULL).");
    eResult = AUDIO_INPUT_ERR_INV_PARAM;
  }

  else if (AUDIOIN_NULL != *ppAudioIn)
  {
    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): invalid parameter \'*ppAudioIn = NULL\' (has to be NULL).");
    eResult = AUDIO_INPUT_ERR_INV_PARAM;
  }

  /* check version */
  else if (AUDIOIN_TRUE != AudioIn_CheckAudioVersion(pAudioInParams->uVersionNum, pAudioInParams->pLogModule))
  {
    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device():  invalid audio version \'pAudioInParams->uVersionNum = %u\'.", pAudioInParams->uVersionNum);
    eResult = AUDIO_INPUT_ERR_VERSION;
  }

  /* number of supported input channels */
  else if (1 > pAudioInParams->uNumChannels || SUPPORTED_CHANNELS < pAudioInParams->uNumChannels)
  {
    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): invalid number of channels \'pAudioInParams->uNumChannels = %u\'.", pAudioInParams->uNumChannels);
    eResult = AUDIO_INPUT_ERR_CH_CNT;
  }

  /* size of input frame buffer (= x *  uSizeOfFrame)  */
  else if (0u == pAudioInParams->uSizeOfFrameBuffer)
  {
    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): invalid size of frame buffer \'pAudioInParams->uSizeOfFrameBuffer = 0\'.");
    eResult = AUDIO_INPUT_ERR_SIZE_DEV_BUF;
  }

  /* size of a input frame  */
  else if (0u == pAudioInParams->uSizeOfFrame)
  {
    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): invalid size of frame \'pAudioInParams->uSizeOfFrame = 0\'.");
    eResult = AUDIO_INPUT_ERR_SIZE_PACK;
  }

  else if (0u == pAudioInParams->uSampleRate)
  {
    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): invalid sample rate \'pAudioInParams->uSampleRate = 0\'.");
    eResult = AUDIO_INPUT_ERR_SAMPLE_RATE;
  }

  else if (AUDIOIN_NULL == pAudioInParams->pDevIdentifier)
  {
    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): invalid device identifier \'pAudioInParams->pDevIdentifier = NULL\'.");
    eResult = AUDIO_INPUT_ERR_INV_DEV_ID;
  }

  /* function pointer to the user callback function */
  else if (AUDIOIN_NULL == pAudioInParams->fpPackageCaptured)
  {
    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device():  invalid package captured callback function \'pAudioInParams->fpPackageCaptured = NULL\'.");
    eResult = AUDIO_INPUT_ERR_INV_PARAM;
  }

  else
  {
    AudioIn *pTmpAudioIn = AUDIOIN_NULL;

    /* Allocates memory for the AudioIn structure */
    pTmpAudioIn = (AudioIn *)calloc(1,sizeof(AudioIn));
    if (AUDIOIN_NULL == pTmpAudioIn)
    {
      AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): calloc() failed.");
      eResult = AUDIO_INPUT_ERR_INTERNAL;
    }

    /* init the needed semaphores */
    else if (0 != AudioIn_SemaInit(&pTmpAudioIn->pThreadCtrlSema, 1u, pAudioInParams->pLogModule))
    {
      AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): AudioIn_SemaInit() failed.");
      eResult = AUDIO_INPUT_ERR_INTERNAL;
    }

    else if (0 != AudioIn_SemaInit(&pTmpAudioIn->pFeedbackSema, 0u, pAudioInParams->pLogModule))
    {
      AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device():AudioIn_SemaInit() failed.");
      eResult = AUDIO_INPUT_ERR_INTERNAL;
    }

    pTmpAudioIn->pMutex = (AudioIn_Mutex*) calloc(1U, sizeof(AudioIn_Mutex));

    if (pTmpAudioIn->pMutex == AUDIOIN_NULL)
    {
      return AUDIO_INPUT_ERR_INTERNAL;
    }

    else if (0 != pthread_mutex_init(&(pTmpAudioIn->pMutex->hMutex), AUDIOIN_NULL))
    {
      AUDIOIN_FREESETNULL(pTmpAudioIn->pMutex);
      return AUDIO_INPUT_ERR_INTERNAL;
    }

    else
    {
      /* get the needed work buffer */
      pTmpAudioIn->sFrameCountAudioWB = pAudioInParams->uSizeOfFrame;
      AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Open_Device(): sizeaudioworkbuffer =%lu", pTmpAudioIn->sFrameCountAudioWB*SUPPORTED_SAMPLESIZE*pAudioInParams->uNumChannels);
      pTmpAudioIn->pAudioWorkBuffer = calloc(pTmpAudioIn->sFrameCountAudioWB,SUPPORTED_SAMPLESIZE*pAudioInParams->uNumChannels);
      AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Open_Device(): calloc %lu %p\n", pTmpAudioIn->sFrameCountAudioWB*SUPPORTED_SAMPLESIZE*pAudioInParams->uNumChannels, pTmpAudioIn->pAudioWorkBuffer);
      pTmpAudioIn->pDevName = calloc(strlen(pAudioInParams->pDevIdentifier)+1,sizeof(AudioIn_Char));

      if (AUDIOIN_NULL == pTmpAudioIn->pAudioWorkBuffer)
      {
        AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): calloc() failed.");
        eResult = AUDIO_INPUT_ERR_INTERNAL;
      }

      else if (AUDIOIN_NULL == pTmpAudioIn->pDevName)
      {
        AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): calloc() failed.");
        eResult = AUDIO_INPUT_ERR_INTERNAL;
      }

      else
      {
        /* Set the default values */
        pTmpAudioIn->hAudioIn = AUDIOIN_NULL;

        pTmpAudioIn->uiFrameCount = pAudioInParams->uSizeOfFrame;
        pTmpAudioIn->uiChannelCount = pAudioInParams->uNumChannels;
        pTmpAudioIn->iWaitTimeout = PACKAGE_TIMEOUT * pTmpAudioIn->uiFrameCount * 1000u / pAudioInParams->uSampleRate;

        pTmpAudioIn->fpPackageCaptured = pAudioInParams->fpPackageCaptured;
        pTmpAudioIn->udPackageCaptured = pAudioInParams->udPackageCaptured;
        pTmpAudioIn->bNonInterleavedStream = pAudioInParams->bFrameMuxFlag;;
        pTmpAudioIn->pLogModule = pAudioInParams->pLogModule;

        /* copy the dev name */
        strncpy(pTmpAudioIn->pDevName, pAudioInParams->pDevIdentifier, strlen(pAudioInParams->pDevIdentifier));

        /* setting the eState */
        pthread_mutex_lock(&(pTmpAudioIn->pMutex->hMutex));
        pTmpAudioIn->eState = E_WAVE_STATE_IDLE;
        pthread_mutex_unlock(&(pTmpAudioIn->pMutex->hMutex));

        /* open the device */
        if (0 != AudioIn_Audio_OpenDevInternal(&(pTmpAudioIn->hAudioIn), pAudioInParams->pDevIdentifier, SND_PCM_STREAM_CAPTURE, pAudioInParams->pLogModule))
        {
          AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- AudioIn_Open_Device()[%s]: AudioIn_Audio_OpenDevInternal() failed.", pAudioInParams->pDevIdentifier);
          eResult = AUDIO_INPUT_ERR_INTERNAL;
        }

        else
        {
          /* for alsa only */
          if (AUDIOIN_NULL != pTmpAudioIn->hAudioIn)
          {
            AudioIn_Int iASoundRes = 0;
            snd_pcm_hw_params_t *hw_params = AUDIOIN_NULL; /*hardware params*/
            snd_pcm_sw_params_t *sw_params = AUDIOIN_NULL; /*software params*/

            snd_pcm_access_t aSoundAccess;
            snd_pcm_uframes_t size = 0;
            snd_pcm_sframes_t period_size = 0;

            AudioIn_UInt32 uSampleRate = pAudioInParams->uSampleRate;
            AudioIn_Int32 iBufferCount = 0;
            AudioIn_UInt32 uBufferTimeDesired = 0;
            AudioIn_UInt32 uBufferTimeGot = 0;

            /* HW PARAMS SETTINGS
            ------------------------------------------------------------------------*/
            /* init param struct */
            if (0 > (iASoundRes = snd_pcm_hw_params_malloc (&hw_params)))
            {
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_hw_params_malloc() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
              eResult = AUDIO_INPUT_ERR_INTERNAL;
            }

            if (0 > (iASoundRes = snd_pcm_hw_params_any (pTmpAudioIn->hAudioIn, hw_params)))
            {
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_hw_params_any() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
              eResult = AUDIO_INPUT_ERR_INTERNAL;
            }

            aSoundAccess = (AUDIOIN_TRUE==pTmpAudioIn->bNonInterleavedStream)?SND_PCM_ACCESS_RW_NONINTERLEAVED:SND_PCM_ACCESS_RW_INTERLEAVED;
            if (0 > (iASoundRes = snd_pcm_hw_params_set_access (pTmpAudioIn->hAudioIn, hw_params, aSoundAccess)))
            {
              /* for one channel devices try the other one, since it does not matter at all */
              if (1 == pAudioInParams->uNumChannels)
              {
                AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Open_Device(): snd_pcm_hw_params_set_access() failed: (%s). Single Channel Device trying other access method ...",snd_strerror (iASoundRes));
                pTmpAudioIn->bNonInterleavedStream = (AUDIOIN_TRUE==pAudioInParams->bFrameMuxFlag)?AUDIOIN_FALSE:AUDIOIN_TRUE;
                aSoundAccess = (AUDIOIN_TRUE==pTmpAudioIn->bNonInterleavedStream)?SND_PCM_ACCESS_RW_NONINTERLEAVED:SND_PCM_ACCESS_RW_INTERLEAVED;
                if (0 > (iASoundRes = snd_pcm_hw_params_set_access (pTmpAudioIn->hAudioIn, hw_params, aSoundAccess)))
                {
                  AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_hw_params_set_access() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                  eResult = AUDIO_INPUT_ERR_INTERNAL;
                }

                else
                {
                  AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Open_Device(): other access method supported, so return silently.");
                }
              }

              else
              {
                AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_hw_params_set_access() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                eResult = AUDIO_INPUT_ERR_INTERNAL;
              }
            }

            if (0 > (iASoundRes = snd_pcm_hw_params_set_format (pTmpAudioIn->hAudioIn, hw_params, SND_PCM_FORMAT_S16_LE)))
            {
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_hw_params_set_format() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
              eResult = AUDIO_INPUT_ERR_INTERNAL;
            }

            if (0 > (iASoundRes = snd_pcm_hw_params_set_rate_near (pTmpAudioIn->hAudioIn, hw_params, &uSampleRate, 0)))
            {
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_hw_params_set_rate_near() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
              eResult = AUDIO_INPUT_ERR_INTERNAL;
            }

            else
            {
              if (uSampleRate != pAudioInParams->uSampleRate)
              {
                AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): sample rate = %u Hz is not supported, device recommends %u Hz.",pAudioInParams->uSampleRate, uSampleRate);
                eResult = AUDIO_INPUT_ERR_INTERNAL;
              }
            }

            if (0 > (iASoundRes = snd_pcm_hw_params_set_channels (pTmpAudioIn->hAudioIn, hw_params, pAudioInParams->uNumChannels)))
            {
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_hw_params_set_channels(%d) failed with error = %i: %s",pAudioInParams->uNumChannels , iASoundRes, snd_strerror(iASoundRes));
              eResult = AUDIO_INPUT_ERR_INTERNAL;
            }

            if (0 > (iASoundRes = snd_pcm_hw_params_set_period_size (pTmpAudioIn->hAudioIn, hw_params, pAudioInParams->uSizeOfFrame, 0)))
            {
              snd_pcm_uframes_t uTmpFrameSize=0;
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Open_Device(): snd_pcm_hw_params_set_period_size() failed: (%s). Will try to get size from device...",snd_strerror(iASoundRes));
              if (0 > (iASoundRes = snd_pcm_hw_params_get_period_size (hw_params, &uTmpFrameSize, 0)))
              {
                AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_hw_params_get_period_size() also failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                eResult = AUDIO_INPUT_ERR_INTERNAL;
              }

              else if (uTmpFrameSize != pAudioInParams->uSizeOfFrame)
              {
                AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_hw_params_get_period_size() != uSizeOfFrame: (%lu != %d).",uTmpFrameSize, pAudioInParams->uSizeOfFrame);
                eResult = AUDIO_INPUT_ERR_INTERNAL;
              }

              else
              {
                AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Open_Device(): snd_pcm_hw_params_get_period_size(): == uSizeOfFrame: (%lu == %d), so return silently.",uTmpFrameSize, pAudioInParams->uSizeOfFrame);
                period_size = uTmpFrameSize;
              }
            }

            else
            {
              period_size = pAudioInParams->uSizeOfFrame;
            }

            /* set the drivers internal ring buffer size */
            iBufferCount = pAudioInParams->uSizeOfFrameBuffer / pAudioInParams->uSizeOfFrame;
            uBufferTimeDesired = (AudioIn_UInt32) iBufferCount * pTmpAudioIn->uiFrameCount * 1000.0f / pAudioInParams->uSampleRate * 1000.0f;
            uBufferTimeGot = uBufferTimeDesired;

            if (2 > iBufferCount)
            {
              iBufferCount = 2u;
            }

            if (DEVICE_MIN_CAPTURE_BUFFER_COUNT > iBufferCount)
            {
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): at least %d buffers are needed.", DEVICE_MIN_CAPTURE_BUFFER_COUNT);
              eResult = AUDIO_INPUT_ERR_INTERNAL;
            }

            else if (0 > (iASoundRes = snd_pcm_hw_params_set_buffer_time_near(pTmpAudioIn->hAudioIn, hw_params, &uBufferTimeGot, 0)))
            {
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_hw_params_set_buffer_time_near() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
              eResult = AUDIO_INPUT_ERR_INTERNAL;
            }

            else
            {
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Open_Device(): got btime %dus wanted %dus",uBufferTimeGot, uBufferTimeDesired);

              if (uBufferTimeGot < uBufferTimeDesired)
              {
                AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device():  buffer time = %d us is not supported, device recommends %d us.",uBufferTimeDesired, uBufferTimeGot);
                eResult = AUDIO_INPUT_ERR_INTERNAL;
              }
            }

            iASoundRes = snd_pcm_hw_params(pTmpAudioIn->hAudioIn, hw_params);

            if (0 > iASoundRes)
            {
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_hw_params() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
              eResult = AUDIO_INPUT_ERR_INTERNAL;
            }

            /* clean up */
            snd_pcm_hw_params_free(hw_params);

            /* SW PARAMS SETTINGS
            ------------------------------------------------------------------------*/

            if (AUDIO_INPUT_OK != eResult)
            {
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): error occurred during hw parameter setting. step over the setting of sw parameters.");
            }

            else
            {
              if (0 > (iASoundRes =  snd_pcm_sw_params_malloc(&sw_params)))
              {
                AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_sw_params_alloca() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                eResult = AUDIO_INPUT_ERR_INTERNAL;
              }
              else
              {
                iASoundRes = snd_pcm_sw_params_current(pTmpAudioIn->hAudioIn, sw_params);

                if (0 > iASoundRes)
                {
                  AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device():  snd_pcm_sw_params_current() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                  eResult = AUDIO_INPUT_ERR_INTERNAL;
                }
              }

              if (AUDIO_INPUT_OK == eResult)
              {
                /* set avail min to period size
                ----------------------------------*/
                if (0 > (iASoundRes = snd_pcm_sw_params_get_avail_min(sw_params, &size)))
                {
                  AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_sw_params_get_avail_min() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                  eResult = AUDIO_INPUT_ERR_INTERNAL;
                }

                else if (period_size != size)
                {
                  if (0 > (iASoundRes = snd_pcm_sw_params_set_avail_min(pTmpAudioIn->hAudioIn, sw_params, period_size)))
                  {
                    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_sw_params_set_avail_min() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                    eResult = AUDIO_INPUT_ERR_INTERNAL;
                  }
                }

                AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Open_Device(): Current period_size %u, defined period_size %u", (unsigned int) size, (unsigned int) period_size);

                if (AUDIO_INPUT_OK == eResult)
                {
                  /* set CAPTURE start threshold to "1"
                  ---------------------------------------*/
                  if (0 > (iASoundRes = snd_pcm_sw_params_get_start_threshold (sw_params, &size)))
                  {
                    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_sw_params_get_start_threshold() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                    eResult = AUDIO_INPUT_ERR_INTERNAL;
                  }

                  else if (1u != size)
                  {
                    if (0 > (iASoundRes = snd_pcm_sw_params_set_start_threshold(pTmpAudioIn->hAudioIn, sw_params, 1u)))
                    {
                      AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_sw_params_set_start_threshold() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                      eResult = AUDIO_INPUT_ERR_INTERNAL;
                    }
                  }

                  AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Open_Device(): Current start threshold %u", (unsigned int) size);

                }

                if (AUDIO_INPUT_OK == eResult)
                {
                  iASoundRes = snd_pcm_sw_params(pTmpAudioIn->hAudioIn, sw_params);

                  if (0 > iASoundRes)
                  {
                    AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): snd_pcm_sw_params() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                    eResult = AUDIO_INPUT_ERR_INTERNAL;
                  }
                }
              }
              /* clean up */
              snd_pcm_sw_params_free(sw_params);
            } /* else of if (AUDIO_INPUT_OK != eResult) */

            /* make dev ready to start */
            if (0 != AudioIn_Audio_Prepare_Device(pTmpAudioIn->hAudioIn, SND_PCM_STREAM_CAPTURE, pAudioInParams->pLogModule))
            {
              AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): AudioIn_Audio_Prepare_Device() failed.");
              eResult = AUDIO_INPUT_ERR_INTERNAL;
            }
          }
        }
      } /* else of if (AUDIOIN_NULL == pTmpAudioIn->pAudioWorkBuffer) */

      /* check errorcode */
      if (AUDIO_INPUT_OK != eResult)
      {
        AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- AudioIn_Open_Device()[%s]: Activating audio device failed.",pTmpAudioIn->pDevName);
      }

      else
      {
        /* create worker_thread and start worker_thread */
        if (0 != pthread_create(&(pTmpAudioIn->threadIdentifier), AUDIOIN_NULL, ThAudioIn, pTmpAudioIn))
        {
          AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioin::AudioIn_Open_Device(): pthread_create() failed.");
          eResult = AUDIO_INPUT_ERR_INTERNAL;
        }

        /* wait for worker thread */
        AudioIn_SemaWait(pTmpAudioIn->pFeedbackSema, pAudioInParams->pLogModule);

        /* init done set eState */
        pthread_mutex_lock(&(pTmpAudioIn->pMutex->hMutex));
        pTmpAudioIn->eState = E_WAVE_STATE_WAITING;
        pthread_mutex_unlock(&(pTmpAudioIn->pMutex->hMutex));

        /* return valid handle */
        (*ppAudioIn) = pTmpAudioIn;
        pTmpAudioIn = AUDIOIN_NULL;

      } /* if (AUDIO_INPUT_OK == eResult) */
    } /* else of if (AUDIOIN_NULL == pTmpAudioIn) */

    /* clean up if necessary */
    if (AUDIOIN_NULL != pTmpAudioIn)
    {
      AUDIOIN_LOG(pAudioInParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioIn_Open_Device(): cleaning up partly initialized handle.");
      AudioIn_Close(&pTmpAudioIn);
    }
  } /* else of check params */
  return eResult;
}