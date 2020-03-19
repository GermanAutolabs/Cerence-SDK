/* ----------------------------------------------------------------------------------+
 | Module        : audioout                                                          |
 | File name     : audioout.c                                                        |
 | Description   : This module contains the open source audio output implementation  |
 |                 for Linux                                                         |
 | Reference(s)  : Linux interface reference documentation:                          |
 |                 https://www.alsa-project.org/alsa-doc/alsa-lib/pcm.html           |
 + ----------------------------------------------------------------------------------*/

#include "audioout.h"

/*+++++++++++++++++++++++++++++++++++++++++++++++++
 * Static functions local to this file
 ++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   This static function checks the handed user
 *           audio version.
 *
 *
 *  @param   uUserVersion
 *               [in] User audio version.
 *
 *  @param   pLogModule
 *               [in] Logging module instance.
 *
 *  @retval  AUDIOOUT_TRUE
 *              No error occurred.
 *           AUDIOOUT_FALSE
 *              An error occurred.
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static AudioOut_Bool AudioOut_CheckAudioVersion
(
  AudioOut_UInt32 uUserVersion,
  nuance_common_ILogModule *pLogModule
)
{
  AudioOut_Bool bResult = AUDIOOUT_FALSE;
  AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting audioout::AudioOut_CheckAudioVersion ");

  /* check for valid parameter */
  if (0 == uUserVersion)
  {
    AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_CheckAudioVersion(): invalid parameter\'uUserVersion = 0\'");
    bResult = AUDIOOUT_FALSE;
  }

  /* check for valid AUDIO version */
  else if ((((uUserVersion >> 16) & 0xff) != ((AUDIOOUT_AUDIO_VERSION >> 16) & 0xff)) ||  (((uUserVersion >>  8) & 0xff)  > ((AUDIOOUT_AUDIO_VERSION >>  8) & 0xff)))
  {
    AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_CheckAudioVersion(): user main != main version or user sub != sub version");
    bResult = AUDIOOUT_FALSE;
  }

  else
  {
    bResult = AUDIOOUT_TRUE;
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

static AudioOut_Int AudioOut_Audio_OpenDevInternal
(
  snd_pcm_t **phAudioDevice,
  AudioOut_Char *pDevIdentifier,
  int iDevOperationMode,
  nuance_common_ILogModule *pLogModule
)
{
  AudioOut_Int iResult = 0;
  AudioOut_Int iASoundRes = 0;
  AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting audioout::AudioOut_Audio_OpenDevInternal ");

  /* check params */
  if (AUDIOOUT_NULL == phAudioDevice || (SND_PCM_STREAM_PLAYBACK != iDevOperationMode && SND_PCM_STREAM_CAPTURE != iDevOperationMode))
  {
    AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_OpenDevInternal(): one or more parameter to the function are invalid.");
    iResult = -1;
  }

  else
  {
    AudioOut_Char  *pDevName = AUDIOOUT_NULL;
    AudioOut_Char  *pWork = AUDIOOUT_NULL;
    AudioOut_Char  tmpDevName[AUDIO_DEV_STRING_SIZE];
    AudioOut_Bool  bHandleAsName = AUDIOOUT_FALSE;

    /* do we have a number */
    pWork = pDevIdentifier;
    while(('\0' != *pWork) && (AUDIOOUT_FALSE == bHandleAsName))
    {
      if (('0' > *pWork) || ('9' < *pWork))
      {
        bHandleAsName = AUDIOOUT_TRUE;
      }
      pWork++;
    }

    /* handle a number */
    if (AUDIOOUT_FALSE == bHandleAsName)
    {
      AudioOut_Int32  iDevIdentifier = -1;

      /* get the handed number */
      iDevIdentifier = atol(pDevIdentifier);

      /* a returned value of 0 indicates an error if the handed string is unequal to the character '0' */
      if (0 == iDevIdentifier && '0' != *pDevIdentifier)
      {
        AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_OpenDevInternal(): atol() failed.");
        iResult = -1;
      }

      else
      {
        AudioOut_UInt32 uCardID = 0u;
        AudioOut_UInt32 uDevID = 0u;

        /* map id to card and device */
        if (10 > iDevIdentifier)
        {
          uCardID = 0x0u;
          uDevID  = (AudioOut_UInt32)iDevIdentifier;
        }

        else if (20 > iDevIdentifier)
        {
          uCardID = 0x1u;
          uDevID  = (AudioOut_UInt32)(iDevIdentifier - 10);
        }

        else if (30 > iDevIdentifier)
        {
          uCardID = 0x2u;
          uDevID  = (AudioOut_UInt32)(iDevIdentifier - 20);
        }

        else if (40 > iDevIdentifier)
        {
          uCardID = 0x3u;
          uDevID  = (AudioOut_UInt32)(iDevIdentifier - 30);
        }

        else
        {
          AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_OpenDevInternal(): invalid device identifier (%s).",pDevIdentifier);
          iResult = -1;
        }

        /* check for error */
        if (0 == iResult)
        {
          /* build the dev name */
          if (1 > snprintf((char*)tmpDevName, AUDIO_DEV_STRING_SIZE, AUDIO_DEV_STRING_MASK, uCardID, uDevID))
          {
            AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_OpenDevInternal(): snprintf() failed.");
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
      const AudioOut_Char *pDevPrefix = (const AudioOut_Char *) "ADN_";

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
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioOut_Audio_OpenDevInternal(): snd_pcm_open(device=%s mode=%d)",  pDevName, iDevOperationMode);

      iASoundRes = snd_pcm_open(phAudioDevice, (char*)pDevName, iDevOperationMode,0);

      if (0 > iASoundRes)
      {
        AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_OpenDevInternal(): snd_pcm_open() failed with error = %i: %s",iASoundRes,snd_strerror(iASoundRes));
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

static AudioOut_Int AudioOut_Audio_Prepare_Device
(
  snd_pcm_t *hAudioDevice,
  AudioOut_Int iDevOperationMode,
  nuance_common_ILogModule *pLogModule
)
{
  AudioOut_Int iResult = 0;
  AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting audioout::AudioOut_Audio_Prepare_Device ");

  /* check params */
  if (AUDIOOUT_NULL == hAudioDevice)
  {
    AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_Prepare_Device(): invalid device handle \'hAudioDevice = AUDIOOUT_NULL\'.");
    iResult = -1;
  }

  else
  {
    AudioOut_Int iASoundRes = 0;

    switch(snd_pcm_state(hAudioDevice))
    {
    case SND_PCM_STATE_SETUP: /*prepare*/

      iASoundRes = snd_pcm_prepare(hAudioDevice);
      if (0 > iASoundRes)
      {
        AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_Prepare_Device(): SND_PCM_STATE_SETUP: snd_pcm_prepare() failed with error = %i: %s",iASoundRes,snd_strerror(iASoundRes));
        iResult = -2;
      }

      else
      {
        AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioOut_Audio_Prepare_Device(SND_PCM_STATE_SETUP)");
      }
      break;

    case SND_PCM_STATE_XRUN: /* recover or prepare */

      iASoundRes = snd_pcm_prepare(hAudioDevice);
      if (0 > iASoundRes)
      {
        AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_Prepare_Device(): SND_PCM_STATE_XRUN: snd_pcm_prepare() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
        iResult = -2;
      }

      else
      {
        AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioOut_Audio_Prepare_Device(SND_PCM_STATE_XRUN)");
      }
      break;

    case SND_PCM_STATE_SUSPENDED: /* resume if possible or prepare */

      iASoundRes = snd_pcm_prepare(hAudioDevice);

      if (0 > iASoundRes)
      {
        AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_Prepare_Device(): SND_PCM_STATE_SUSPENDED: snd_pcm_prepare() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
        iResult = -2;
      }

      else
      {
        AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioOut_Audio_Prepare_Device(SND_PCM_STATE_SUSPENDED)");
      }
      break;

    case SND_PCM_STATE_PREPARED: /*nothing to do we are already prepared */
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioOut_Audio_Prepare_Device(SND_PCM_STATE_PREPARED)");
      break;

    case SND_PCM_STATE_RUNNING: /*nothing to do we are not prepared but already running so do not change that*/
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioOut_Audio_Prepare_Device(SND_PCM_STATE_RUNNING)");
      break;

    case SND_PCM_STATE_OPEN: /* error should not occur */
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_Prepare_Device(): SND_PCM_STATE_OPEN: unsupported device state, set hw parameter first.");
      iResult = -2;
      break;

    case SND_PCM_STATE_DRAINING: /* error should not occur, snd_pcm:drain is not used for input and blocking for output */
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_Prepare_Device(): SND_PCM_STATE_DRAINING: unsupported device state.");
      iResult = -2;
      break;

    case SND_PCM_STATE_PAUSED: /* error should not occur */
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_Prepare_Device(): SND_PCM_STATE_PAUSED: somebody paused the device.");
      iResult = -2;
      break;

    case SND_PCM_STATE_DISCONNECTED:  /* error should not occur */
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_Prepare_Device(): SND_PCM_STATE_DISCONNECTED: the device is not available.");
      iResult = -2;
      break;

    default: /* error should not occur */
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Audio_Prepare_Device(): unknown device state.");
      iResult = -2;
      break;
    }
  }
  return iResult;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
*  @brief   This static function plays the package written to the audio
*           device buffer.
*
*  @param   pAudioOut
*              [in] pointer to an audio device handle.
*
*  @param   pLogModule
*              [in] logging module instance.
*
*  @return  Upon successful completion, the function returns
*           AUDIO_OUTPUT_OK. Otherwise it returns an error
*           code to indicate the error.
*
*  @retval  AUDIO_OUTPUT_OK
*             No error occurred.
*  @retval  AUDIO_OUTPUT_ERR_INV_PARAM
*             One or more parameter to the function are
*             invalid.
*  @retval  AUDIO_OUTPUT_ERR_WRITE_DEV
*             An error occurred while writing to the audio
*             device buffer
*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static AudioOut_Error AudioOut_PlayPackage
(
  AudioOut *pAudioOut,
  nuance_common_ILogModule *pLogModule
)
{
  AudioOut_Error eResult = AUDIO_OUTPUT_OK;
  AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting audioout::AudioOut_PlayPackage ");

  /* check param */
  if (AUDIOOUT_NULL == pAudioOut)
  {
    AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_PlayPackage(): invalid handle \'pAudioOut = NULL\'.");
    eResult =  AUDIO_OUTPUT_ERR_INV_PARAM;
  }

  else
  {
    snd_pcm_sframes_t sFramesWritten = 0;
    const AudioOut_Int16  *ppWritenBuffer[pAudioOut->uiChannelCount];
    AudioOut_Int iChannelIndex;

    /* send the next package to the driver */
    AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO: AudioOut_PlayPackage(), write %lu frames ... \n",pAudioOut->pTailPlay->sSizeAudioPackageUser/pAudioOut->uiChannelCount);
    if (AUDIOOUT_TRUE == pAudioOut->bNonInterleavedStream)
    {
      for (iChannelIndex=0;iChannelIndex<pAudioOut->uiChannelCount;++iChannelIndex)
      {
        ppWritenBuffer[iChannelIndex]= &(pAudioOut->pTailPlay->pAudioPackageUser[iChannelIndex*(pAudioOut->pTailPlay->sSizeAudioPackageUser/pAudioOut->uiChannelCount)]);
      }

      sFramesWritten = snd_pcm_writen(pAudioOut->hAudioOut,
                                      (void**)ppWritenBuffer,
                                      ((snd_pcm_uframes_t)(pAudioOut->pTailPlay->sSizeAudioPackageUser/pAudioOut->uiChannelCount)));
    }

    else
    {
      sFramesWritten = snd_pcm_writei(pAudioOut->hAudioOut,
                                      pAudioOut->pTailPlay->pAudioPackageUser,
                                      ((snd_pcm_uframes_t)(pAudioOut->pTailPlay->sSizeAudioPackageUser/pAudioOut->uiChannelCount)));
    }
    AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "done. wrote %lu frames\n", sFramesWritten);

    /* check for an error */
    if (0 > sFramesWritten)
    {
      AudioOut_Int iASoundRes = sFramesWritten;
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_PlayPackage():[%s]: snd_pcm_write*() failed with error = %i, try to recover: %s", pAudioOut->pDevName, iASoundRes, snd_strerror(iASoundRes));

      /* try silent recovery */
      iASoundRes = snd_pcm_recover(pAudioOut->hAudioOut, iASoundRes, 1);

      if (0 > iASoundRes)
      {
        AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_PlayPackage():[%s]: snd_pcm_recover() failed with error = %i: %s", pAudioOut->pDevName, iASoundRes, snd_strerror(iASoundRes));
        eResult = AUDIO_OUTPUT_ERR_WRITE_DEV;
      }
      sFramesWritten = 0; /* set to 0 to trigger a correct retry */
    }

    /* check amount of data currently written and try to play the remaining data */
    if (sFramesWritten < pAudioOut->pTailPlay->sSizeAudioPackageUser/pAudioOut->uiChannelCount)
    {
      snd_pcm_uframes_t sFramesNotWritten = (pAudioOut->pTailPlay->sSizeAudioPackageUser/pAudioOut->uiChannelCount) - sFramesWritten;

      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO: AudioOut_PlayPackage(), write %lu frames ... \n",sFramesNotWritten);
      if (pAudioOut->bNonInterleavedStream == AUDIOOUT_TRUE)
      {
        for (iChannelIndex=0;iChannelIndex<pAudioOut->uiChannelCount;++iChannelIndex)
        {
          ppWritenBuffer[iChannelIndex]= &(pAudioOut->pTailPlay->pAudioPackageUser[iChannelIndex*(pAudioOut->pTailPlay->sSizeAudioPackageUser/pAudioOut->uiChannelCount)+sFramesWritten]);
        }

        sFramesWritten += snd_pcm_writen(pAudioOut->hAudioOut, (void**)ppWritenBuffer, sFramesNotWritten);
      }

      else
      {
        sFramesWritten += snd_pcm_writei(pAudioOut->hAudioOut,
                                         pAudioOut->pTailPlay->pAudioPackageUser + (sFramesWritten*pAudioOut->uiChannelCount),
                                         sFramesNotWritten);
      }

      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "done. wrote %lu frames\n", sFramesWritten);

      if (sFramesWritten < pAudioOut->pTailPlay->sSizeAudioPackageUser/pAudioOut->uiChannelCount)
      {
        AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_PlayPackage():[%s]: snd_pcm_write*() failed.", pAudioOut->pDevName);
        eResult = AUDIO_OUTPUT_ERR_WRITE_DEV;
      }
    }
  }
  return eResult;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
*  @brief   This static function process the release package here
*           we might get a new one.
*
*  @param   pAudioOut
*              [in] pointer to an audio device handle.
*
*  @param   pLogModule
*              [in] logging module instance.
*
*  @retval  none
*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static void AudioOut_ReleasePackage
(
  AudioOut *pAudioOut,
  nuance_common_ILogModule *pLogModule
)
{
  AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting audioout::AudioOut_ReleasePackage");
  if (AUDIOOUT_NULL != pAudioOut)
  {
    CbPackagePlayed      fpPackagePlayed = pAudioOut->pTailRelease->fpPackagePlayed;
    const AudioOut_Int16 *pAudioData     = pAudioOut->pTailRelease->pAudioPackageUser;
    void                *pUserData       = pAudioOut->pTailRelease->udPackagePlayed;

    /* clean up internally before notifying the user */
    pAudioOut->pTailRelease->eState = E_PACKAGE_STATE_UNUSED;
    pAudioOut->pTailRelease->fpPackagePlayed   = AUDIOOUT_NULL;
    pAudioOut->pTailRelease->pAudioPackageUser = AUDIOOUT_NULL;
    pAudioOut->pTailRelease->udPackagePlayed   = AUDIOOUT_NULL;

    /* inc working variables */
    pAudioOut->uiFreeBuffers++;
    if (pAudioOut->pTailRelease == pAudioOut->pPlayList + (pAudioOut->uiNumberOfBuffers - 1))
    {
      pAudioOut->pTailRelease = pAudioOut->pPlayList;
    }

    else
    {
      pAudioOut->pTailRelease++;
    }

    /* check callback pointer */
    if (AUDIOOUT_NULL != fpPackagePlayed)
    {
      /* release mutex */
      /*NOTE: it is allowed that interface functions are called within the callback */
      pthread_mutex_unlock(&(pAudioOut->pMutex->hMutex));

      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioOut_ReleasePackage(): calling user callback: udata %p.\n",pUserData);

      /* call the registered callback */
      fpPackagePlayed(pUserData, pAudioData);

      /* get the mutex */
      pthread_mutex_lock(&(pAudioOut->pMutex->hMutex));
    }
  }
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
*  @brief   This static function performs the clean up.
*
*  @param   pAudioOut
*             [in] pointer to an audio device handle.
*
*  @param   eCallingState
*             [in] current state of the audio device.
*
*  @param   pLogModule
*             [in] logging module instance.
*
*  @retval  none
*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static void AudioOut_CleanUpPlayList
(
  AudioOut *pAudioOut,
  EWaveState eCallingState,
  nuance_common_ILogModule *pLogModule
)
{
  AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INTERNAL_FUNC, "Starting audioout::AudioOut_CleanUpPlayList");
  /* check params */
  if (AUDIOOUT_NULL == pAudioOut)
  {
    AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_CleanUpPlayList(): invalid handle \'pAudioOut = NULL\'.");
  }

  else
  {
    /* ensure to release only as much packages as there are in now
     * the user might write new ones if the call back is called, due to the open mutex */
    AudioOut_UInt32 uiPackagesToRelease = pAudioOut->uiNumberOfBuffers - pAudioOut->uiFreeBuffers;

    /* call remaining user callback */
    while ((0 < uiPackagesToRelease) && (E_PACKAGE_STATE_UNUSED != pAudioOut->pTailRelease->eState))
    {
      /* HINT : Mutex is released and acquired again after the user call back */
      AudioOut_ReleasePackage(pAudioOut, pLogModule);
      --uiPackagesToRelease;
    } /* while (E_PACKAGE_STATE_UNUSED != pAudioOut->pTailRelease->eState && ... */

    /* Now the RELEASE pointer is right at the some address as the HEAD pointer
     * The state of all ring buffer elements are now set to "E_PACKAGE_STATE_UNUSED" (0)
     * The TAIL pointer is left behind !!!
     * Now the TAIL pointer should get the address of the RELEASE pointer.
     * The HEAD pointer could be increased cause of an write occurred right now. */

    pAudioOut->pTailPlay = pAudioOut->pTailRelease;

    /* plausibility check */
    if (0 != uiPackagesToRelease)
    {
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_CleanUpPlayList():[%s]: plausibility check failed!!! all used buffers should bave been freed.", pAudioOut->pDevName);
    }

    /* what happened */
    if (pAudioOut->uiFreeBuffers != pAudioOut->uiNumberOfBuffers)
    {
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioOut_CleanUpPlayList(): write of %d packages during cleanup detected.\n",pAudioOut->uiNumberOfBuffers-pAudioOut->uiFreeBuffers);
    }

    /* since the mutex was open we have to check the state */
    if (eCallingState != pAudioOut->eState)
    {
      /* HINT : could happen if an abort call occurred with releasing all user call backs */
      AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "INFO AudioOut_CleanUpPlayList(): state changed (from %d, to %d).\n", eCallingState, pAudioOut->eState);
    }
  }
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++
 * internal thread function
 ++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   Writes the audio data to the output device and
 *           calls the callback function CbPackageCaptured()
 *
 *  @param   param
 *             [in,out] handle to the audio output device.
 *
 *
 *  @retval  none
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static void* ThAudioOut
(
  void *param
)
{
  AudioOut_Bool bFinished = AUDIOOUT_FALSE;
  AudioOut_Bool bProcessRequest = AUDIOOUT_FALSE;

  AudioOut *pAudioOut = (AudioOut *)param;
  AudioOut_Bool bDeviceNotifications = AUDIOOUT_FALSE;

  AudioOut_Int32 writePackageCnt = 0;

  #ifdef DBGPRINTF
    snd_pcm_state_t prevAlsaState = -1;
  #endif

  /* check params */
  if (AUDIOOUT_NULL != pAudioOut)
  {
    /* thread main loop */
    while (AUDIOOUT_FALSE == bFinished)
    {
      /* wait for messages */
      /* NOTE: use an extra flag to prevent race conditions with the eState variable */
      if (AUDIOOUT_FALSE == bDeviceNotifications)
      {
        /* wait for interface */
        AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO: waiting for interface ... \n");
        AudioOut_SemaWait(pAudioOut->pThreadCtrlSema, pAudioOut->pLogModule);
        AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO: done\n");
        bProcessRequest = AUDIOOUT_TRUE;
      }

      else
      {
        AudioOut_Int iASoundRes = 0;

        AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO: waiting for device ... \n");

        iASoundRes = snd_pcm_wait(pAudioOut->hAudioOut, pAudioOut->iWaitTimeout);

        AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "done\n");

        /* snd_pcm_wait() errors:
         * 0         : wait TIMEOUT
         * -EPIPE    : xrun (underrun for playback or overrun for capture)
         * -ESTRPIPE : suspended driver
         ----------------------------------------------------*/
        if (0 >= iASoundRes) /* error / timeout */
        {
          if (0 != pthread_mutex_lock(&(pAudioOut->pMutex->hMutex)))
          {
            AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():  pthread_mutex_lock() failed.");
          }

          else
          {
            if (0 == iASoundRes)
            {
              AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: snd_pcm_wait() failed with timeout. ", pAudioOut->pDevName);
              pAudioOut->bSndPcmError = AUDIOOUT_TRUE;
            }

            else
            {
              AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():  [%s]: snd_pcm_wait() failed with error = %i: %s (timeout %d)", pAudioOut->pDevName, iASoundRes, snd_strerror(iASoundRes), pAudioOut->iWaitTimeout);

              /* snd_pcm_recover()
               * This functions handles -EINTR (interrupted system call), -EPIPE (overrun or underrun) and -ESTRPIPE (stream is suspended) error codes
               * trying to prepare given stream for next I/O.
               * Note that this function returns the original error code when it is not handled inside this function.
               -------------------------------------------------------------------------------------------------------------*/

              /* try silent recovery */
              iASoundRes = snd_pcm_recover(pAudioOut->hAudioOut, iASoundRes, 1);

              if (0 > iASoundRes)
              {
                AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: snd_pcm_recover() failed with error = %i: %s", pAudioOut->pDevName, iASoundRes, snd_strerror(iASoundRes));
                pAudioOut->bSndPcmError = AUDIOOUT_TRUE;
              }

              else
              {
                AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: snd_pcm_recover() recovery was successfull! ", pAudioOut->pDevName);
                pAudioOut->bSndPcmError = AUDIOOUT_FALSE;
              }
            }

            /* rest error handling
            ------------------------------------------------*/
            if (AUDIOOUT_TRUE == pAudioOut->bSndPcmError)
            {
              /* check if we stuck in aborting. if so, let the abort state signal the waiting semaphore */
              if (pAudioOut->eState == E_WAVE_STATE_STOPPING)
              {
                AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: audio device error during ABORT is in process. check process state: should be active (%d) \n", pAudioOut->pDevName, bProcessRequest);
                /* temporary active process state during abort handling. */
                bProcessRequest = AUDIOOUT_TRUE;
              }

              else
              {
                /* reset states */
                pAudioOut->eState = E_WAVE_STATE_WAITING;
                bDeviceNotifications = AUDIOOUT_FALSE;
                pAudioOut->uiPendingBuffers = DEVICE_PLAY_BUFFER_COUNT;
                pAudioOut->startBurstPackageCount = 0;
                bProcessRequest = AUDIOOUT_FALSE;
              }

              /* clean up */
              AudioOut_CleanUpPlayList(pAudioOut, E_WAVE_STATE_WAITING, pAudioOut->pLogModule);
            }

            if (0 != pthread_mutex_unlock(&(pAudioOut->pMutex->hMutex)))
            {
              AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():  pthread_mutex_unlock() failed.");
            }
          }
        }

        else /* OK */
        {
          bProcessRequest = AUDIOOUT_TRUE;
          pAudioOut->bSndPcmError = AUDIOOUT_FALSE;
        }
      }

      /* enter only if necessary */
      if (AUDIOOUT_TRUE == bProcessRequest)
      {
        /* get the mutex */
        if (0 != pthread_mutex_lock(&(pAudioOut->pMutex->hMutex)))
        {
          AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():  pthread_mutex_lock() failed.");
        }

        else
        {
          AudioOut_Int iASoundRes;

          #ifdef DBGPRINTF
            snd_pcm_state_t currentAlsaState = snd_pcm_state(pAudioOut->hAudioOut);

            /* get the device state and print it if changed */
            if (prevAlsaState != currentAlsaState)
            {
              AudioOut_Char *stateName = AUDIOOUT_NULL;

              switch(currentAlsaState)
              {
              case SND_PCM_STATE_OPEN:         stateName = (AudioOut_Char*)"SND_PCM_STATE_OPEN";         break;
              case SND_PCM_STATE_SETUP:        stateName = (AudioOut_Char*)"SND_PCM_STATE_SETUP";        break;
              case SND_PCM_STATE_PREPARED:     stateName = (AudioOut_Char*)"SND_PCM_STATE_PREPARED";     break;
              case SND_PCM_STATE_RUNNING:      stateName = (AudioOut_Char*)"SND_PCM_STATE_RUNNING";      break;
              case SND_PCM_STATE_XRUN:         stateName = (AudioOut_Char*)"SND_PCM_STATE_XRUN";         break;
              case SND_PCM_STATE_DRAINING:     stateName = (AudioOut_Char*)"SND_PCM_STATE_DRAINING";     break;
              case SND_PCM_STATE_PAUSED:       stateName = (AudioOut_Char*)"SND_PCM_STATE_PAUSED";       break;
              case SND_PCM_STATE_SUSPENDED:    stateName = (AudioOut_Char*)"SND_PCM_STATE_SUSPENDED";    break;
              case SND_PCM_STATE_DISCONNECTED: stateName = (AudioOut_Char*)"SND_PCM_STATE_DISCONNECTED"; break;
              default:                         stateName = (AudioOut_Char*)"SND_PCM_STATE UNKNOWN !!!";  break;
              }

              AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO (%s): DevState changed to: %s\n",pAudioOut->pDevName, stateName);

              prevAlsaState = currentAlsaState;
            }
          #endif

          /* check current eState and perform appropriate action */
          switch (pAudioOut->eState)
          {
          case E_WAVE_STATE_PLAYING: /* play one package */
            AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO: current AudioState: E_WAVE_STATE_PLAYING\n");

            /* start acknowledging right before the third write since then the first package was processed by io-audio */
            if (0 < pAudioOut->uiPendingBuffers)
            {
              pAudioOut->uiPendingBuffers--;
            }

            /* check callback_pointer and process the release package here we might get a new one*/
            else if (E_PACKAGE_STATE_RELEASE == pAudioOut->pTailRelease->eState)
            {
              AudioOut_ReleasePackage(pAudioOut, pAudioOut->pLogModule);
            }

            /* since the mutex was open we have to check the state */
            if (E_WAVE_STATE_PLAYING == pAudioOut->eState)
            {
              /* check for empty queue */
              if (E_PACKAGE_STATE_UNUSED == pAudioOut->pTailPlay->eState)
              {
                AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO (%s): queue empty: underrun detected\n",pAudioOut->pDevName);

                /* drain the driver */
                iASoundRes = snd_pcm_drain(pAudioOut->hAudioOut);

                if (0 > iASoundRes)
                {
                  AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: snd_pcm_drain() failed with error = %i: %s", pAudioOut->pDevName, iASoundRes, snd_strerror(iASoundRes));
                }

                /* prepare for next use */
                if (0 != AudioOut_Audio_Prepare_Device(pAudioOut->hAudioOut, SND_PCM_STREAM_PLAYBACK, pAudioOut->pLogModule))
                {
                  AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: AudioOut_Audio_Prepare_Device() failed.", pAudioOut->pDevName);
                }

                /* reset states */
                pAudioOut->eState = E_WAVE_STATE_WAITING;
                bDeviceNotifications = AUDIOOUT_FALSE;
                pAudioOut->uiPendingBuffers = DEVICE_PLAY_BUFFER_COUNT;
                pAudioOut->startBurstPackageCount = 0;

                /* clean up */
                AudioOut_CleanUpPlayList(pAudioOut, E_WAVE_STATE_WAITING, pAudioOut->pLogModule);
              }

              else
              {
                /* check for data */
                if (E_PACKAGE_STATE_PLAY == pAudioOut->pTailPlay->eState)
                {
                  /* check for end of stream marker --> none */
                  if (0 != pAudioOut->pTailPlay->sSizeAudioPackageUser)
                  {
                    /* play the package */
                    AudioOut_PlayPackage(pAudioOut, pAudioOut->pLogModule);

                    if (AUDIO_DEV_DEBUG_INTERVAL <= ++writePackageCnt)
                    {
                      AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO (%s): processed %d packages\n",pAudioOut->pDevName, writePackageCnt);
                      writePackageCnt=0;
                    }

                    pAudioOut->pTailPlay->eState = E_PACKAGE_STATE_RELEASE;

                    /* inc working variables */
                    if (++pAudioOut->pTailPlay == pAudioOut->pPlayList + pAudioOut->uiNumberOfBuffers)
                    {
                      pAudioOut->pTailPlay = pAudioOut->pPlayList;
                    }
                  }

                  /* end-of-stream detected */
                  else
                  {
                    AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO (%s): EndOfStream\n",pAudioOut->pDevName);

                    /* drain the driver */
                    iASoundRes = snd_pcm_drain(pAudioOut->hAudioOut);

                    if (0 > iASoundRes)
                    {
                      AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: snd_pcm_drain() failed with error = %i: %s", pAudioOut->pDevName, iASoundRes, snd_strerror(iASoundRes));
                    }

                    pAudioOut->pTailPlay->eState = E_PACKAGE_STATE_RELEASE;

                    /* inc working variables */
                    if (++pAudioOut->pTailPlay == pAudioOut->pPlayList + pAudioOut->uiNumberOfBuffers)
                    {
                      pAudioOut->pTailPlay = pAudioOut->pPlayList;
                    }

                    /* prepare for next use */
                    if (0 != AudioOut_Audio_Prepare_Device(pAudioOut->hAudioOut, SND_PCM_STREAM_PLAYBACK, pAudioOut->pLogModule))
                    {
                      AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: AudioOut_Audio_Prepare_Device() failed.", pAudioOut->pDevName);
                    }

                    /* reset states and variables */
                    pAudioOut->eState = E_WAVE_STATE_WAITING;
                    bDeviceNotifications = AUDIOOUT_FALSE;
                    pAudioOut->uiPendingBuffers = DEVICE_PLAY_BUFFER_COUNT;
                    pAudioOut->startBurstPackageCount = 0;

                    /* clean up */
                    AudioOut_CleanUpPlayList(pAudioOut, E_WAVE_STATE_WAITING, pAudioOut->pLogModule);

                  } /* else of if (0 != pAudioOut->pTailPlay->sSizeAudioPackageUser) */
                } /* if (E_PACKAGE_STATE_PLAY == pAudioOut->pTailPlay->eState) */
              } /* else of if (E_PACKAGE_STATE_UNUSED == pAudioOut->pTailPlay->eState) */
            } /* if (E_WAVE_STATE_PLAYING == pAudioOut->eState) */
            break;

          case E_WAVE_STATE_STARTING: /* prepare for playing */
            AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO: current AudioState: E_WAVE_STATE_STARTING\n");
            AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO (%s): StartOfStream\n",pAudioOut->pDevName);

            pAudioOut->eState    = E_WAVE_STATE_PLAYING;
            bDeviceNotifications = AUDIOOUT_TRUE;
            break;

          case E_WAVE_STATE_STOPPING: /* abort playing */
            AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO: current AudioState: E_WAVE_STATE_STOPPING\n");
            AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO (%s): AbortOfStream\n",pAudioOut->pDevName);

            /* clean up */
            iASoundRes = snd_pcm_drop(pAudioOut->hAudioOut);

            if (0 > iASoundRes)
            {
              AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: snd_pcm_drop() failed with error = %i: %s", pAudioOut->pDevName, iASoundRes, snd_strerror(iASoundRes));
            }

            /* prepare for next use */
            if (0 != AudioOut_Audio_Prepare_Device(pAudioOut->hAudioOut, SND_PCM_STREAM_PLAYBACK, pAudioOut->pLogModule))
            {
              AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: AudioOut_Audio_Prepare_Device() failed.", pAudioOut->pDevName);
            }

            /* reset states */
            pAudioOut->eState = E_WAVE_STATE_WAITING;
            bDeviceNotifications = AUDIOOUT_FALSE;
            pAudioOut->uiPendingBuffers = DEVICE_PLAY_BUFFER_COUNT;
            pAudioOut->startBurstPackageCount = 0;

            /* clean up */
            AudioOut_CleanUpPlayList(pAudioOut, E_WAVE_STATE_WAITING, pAudioOut->pLogModule);

            /* notify abort */
            AudioOut_SemaSignal(pAudioOut->pFeedbackSema, pAudioOut->pLogModule);
            break;

          case E_WAVE_STATE_IDLE: /* notify caller that thread is started */
            AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO: current AudioState: E_WAVE_STATE_IDLE\n");
            bDeviceNotifications = AUDIOOUT_FALSE;
            AudioOut_SemaSignal(pAudioOut->pFeedbackSema, pAudioOut->pLogModule);
            break;

          case E_WAVE_STATE_CLOSING: /* exit thread loop */
            AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO: current AudioState: E_WAVE_STATE_CLOSING\n");
            AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO (%s) -> (%s): shutdown\n",pAudioOut->pDevName, (AUDIOOUT_TRUE == pAudioOut->bAbortMissing) ? "ABORT/CLOSE" : "CLOSE");

            /* clean the buffers */
            iASoundRes = snd_pcm_drop(pAudioOut->hAudioOut);

            if (0 > iASoundRes)
            {
              AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: snd_pcm_drop() failed with error = %i: %s", pAudioOut->pDevName, iASoundRes, snd_strerror(iASoundRes));
            }

            if (AUDIOOUT_TRUE == pAudioOut->bAbortMissing)
            {
              /* prepare for next use */
              if (0 != AudioOut_Audio_Prepare_Device(pAudioOut->hAudioOut, SND_PCM_STREAM_PLAYBACK, pAudioOut->pLogModule))
              {
                AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::ThAudioOut():[%s]: AudioOut_Audio_Prepare_Device() failed.", pAudioOut->pDevName);
              }

              /* reset states */
              pAudioOut->eState = E_WAVE_STATE_WAITING;
              bDeviceNotifications = AUDIOOUT_FALSE;
              pAudioOut->uiPendingBuffers = DEVICE_PLAY_BUFFER_COUNT;
              pAudioOut->startBurstPackageCount = 0;

              /* clean up */
              AudioOut_CleanUpPlayList(pAudioOut, E_WAVE_STATE_WAITING, pAudioOut->pLogModule);
            }

            /* exit thread loop */
            bFinished = AUDIOOUT_TRUE;
            break;

          default: /* nothing to do */
            AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "AOT INFO: current AudioState: default (%d)\n",pAudioOut->eState);
            bDeviceNotifications = AUDIOOUT_FALSE;
            break;
          } /* switch(pAudioOut->eState)*/

          pthread_mutex_unlock(&(pAudioOut->pMutex->hMutex));
        } /* else of if (MUTEX_OK != pthread_mutex_lock(&(pAudioOut->pMutex->hMutex))) */
      } /* if (AUDIOOUT_TRUE == bProcessRequest) */
    } /* while (AUDIOOUT_FALSE == bFinished)*/
  }
  return 0;
}

AudioOut_Error AudioOut_SemaDeInit
(
  AudioOut_Sema **ppSema,
  nuance_common_ILogModule *pLogModule
)
{
  AudioOut_Sema *pSema = AUDIOOUT_NULL;
  AudioOut_Int32 rc = 0;
  AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "Starting AudioOut::AudioOut_SemaDeInit");

  /* check parameters */

  if (AUDIOOUT_NULL == ppSema)
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  if (AUDIOOUT_NULL == *ppSema)
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  pSema = *ppSema;

  /* remove the wait condition */
  rc = pthread_cond_destroy(&pSema->cond);
  if ((0 != rc) && (EBUSY != rc))
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  while (EBUSY == rc)
  {
    pthread_cond_signal(&pSema->cond);
    rc = pthread_cond_destroy(&pSema->cond);
    AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "Required extra signal");
  }

  /* remove sema's mutex */
  if (pthread_mutex_destroy(&pSema->mutex))
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  AUDIOOUT_FREE_SET_NULL(*ppSema);
  return AUDIO_OUTPUT_OK;
}

AudioOut_Error AudioOut_SemaInit
(
  AudioOut_Sema **ppSema,
  AudioOut_UInt32 initCount,
  nuance_common_ILogModule *pLogModule
)
{
  AudioOut_Sema *pSema = AUDIOOUT_NULL;
  AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "Starting AudioOut::AudioOut_SemaInit \n");

  /* check parameters */

  if (AUDIOOUT_NULL == ppSema)
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  (*ppSema) = AUDIOOUT_NULL;

  /* create an unnamed semaphore */

  pSema = (AudioOut_Sema*) calloc(1U, sizeof(AudioOut_Sema));

  if (AUDIOOUT_NULL == pSema)
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  /* set sema parameters */
  pSema->n = initCount;

  /* init the internal mutex */
  if (pthread_mutex_init(&pSema->mutex, AUDIOOUT_NULL))
  {
    free(pSema);
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  /* init the internal wait condition */
  if (pthread_cond_init(&pSema->cond, AUDIOOUT_NULL))
  {
    if (pthread_mutex_destroy(&pSema->mutex))
    {
      return AUDIO_OUTPUT_ERR_INTERNAL;
    }

    free(pSema);
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  /* set the result value */
  *ppSema = pSema;
  return AUDIO_OUTPUT_OK;
}

AudioOut_Error AudioOut_SemaSignal
(
    AudioOut_Sema *pSema,
  nuance_common_ILogModule *pLogModule
)
{
  AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "Starting AudioOut::AudioOut_SemaSignal \n");
  /* check parameters */
  if (AUDIOOUT_NULL == pSema)
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  /* lock the mutex for semaphore access */
  if (pthread_mutex_lock(&pSema->mutex))
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  /* increment */
  ++(pSema->n);

  /* wakeup one waiting thread */
  if (pthread_cond_signal(&pSema->cond))
  {
    pthread_mutex_unlock(&pSema->mutex);
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  /* unlock the mutex */
  if (pthread_mutex_unlock(&pSema->mutex))
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }
  return AUDIO_OUTPUT_OK;
}

AudioOut_Error AudioOut_SemaWait
(
  AudioOut_Sema *pSema,
  nuance_common_ILogModule *pLogModule
)
{
  AUDIOOUT_LOG(pLogModule, NUANCE_COMMON_LOG_INFO, "Starting AudioOut::AudioOut_SemaWait \n");
  /* check parameters */
  if (AUDIOOUT_NULL == pSema)
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  /* lock the mutex */
  if (pthread_mutex_lock(&pSema->mutex))
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }

  /* wait unlil sema's count is at least 1 */
  /* the loop is required because all waiting threads will wake up on */
  /* the wait condition */
  while (pSema->n < 1)
  {
    /* wait condition waits until it is signaled by Signal */
    if (pthread_cond_wait(&pSema->cond, &pSema->mutex))
    {
      pthread_mutex_unlock(&pSema->mutex);
      return AUDIO_OUTPUT_ERR_INTERNAL;
    }
  }

  /* decrement the count */
  --(pSema->n) ;

  /* release the mutex */
  if (pthread_mutex_unlock(&pSema->mutex))
  {
    return AUDIO_OUTPUT_ERR_INTERNAL;
  }
  return AUDIO_OUTPUT_OK;
}

const AudioOut_Char* AudioOut_GetErrorText
(
  AudioOut_Int errorCode
)
{
  const AudioOut_Char *string = AUDIOOUT_NULL;

  switch (errorCode)
  {
  case AUDIO_OUTPUT_OK:               string = AUDIOOUT_STRLIT2CSTR("No error occurred.");break;
  case AUDIO_OUTPUT_ERR_INV_PARAM:    string = AUDIOOUT_STRLIT2CSTR("One or more parameter to the function are invalid.");break;
  case AUDIO_OUTPUT_ERR_INTERNAL:     string = AUDIOOUT_STRLIT2CSTR("An internal error occurred.");break;
  case AUDIO_OUTPUT_ERR_INV_DEV_ID:   string = AUDIOOUT_STRLIT2CSTR("The device identifier of the audio device is invalid.");break;
  case AUDIO_OUTPUT_ERR_SAMPLE_RATE:  string = AUDIOOUT_STRLIT2CSTR("The sample rate is not supported from audio device.");break;
  case AUDIO_OUTPUT_ERR_SIZE_DEV_BUF: string = AUDIOOUT_STRLIT2CSTR("The size of audio device buffer (maxNumberPackages * maxSizePackages) is not supported.");break;
  case AUDIO_OUTPUT_ERR_OPEN_DEV:     string = AUDIOOUT_STRLIT2CSTR("An error occurred while opening the audio device.");break;
  case AUDIO_OUTPUT_ERR_WRITE_DEV:    string = AUDIOOUT_STRLIT2CSTR("An error occurred while writing to the audio device buffer.");break;
  case AUDIO_OUTPUT_ERR_SIZE_PACK:    string = AUDIOOUT_STRLIT2CSTR("The size of the audio package is invalid.");break;
  case AUDIO_OUTPUT_ERR_ABORT_DEV:    string = AUDIOOUT_STRLIT2CSTR("An error occurred while stopping the audio device.");break;
  case AUDIO_OUTPUT_ERR_CLEAR_DEV_BUF:string = AUDIOOUT_STRLIT2CSTR("An error occurred while clearing the audio device buffer.");break;
  case AUDIO_OUTPUT_ERR_CLOSE_DEV:    string = AUDIOOUT_STRLIT2CSTR("An error occurred while closing the audio device.");break;
  case AUDIO_OUTPUT_ERR_MAX_NUM_PACK: string = AUDIOOUT_STRLIT2CSTR("An error occurred because maximum number packages reached.");break;
  case AUDIO_OUTPUT_ERR_VERSION:      string = AUDIOOUT_STRLIT2CSTR("An error occurred because of incompatible  versions.");break;
  case AUDIO_OUTPUT_ERR_CH_CNT:       string = AUDIOOUT_STRLIT2CSTR("An error occurred because of invalid channel count.");break;
  default:                            string = AUDIOOUT_STRLIT2CSTR("Invalid error code.");break;
  }
  return string;
}

AudioOut_Error AudioOut_Open_Device
(
 AudioOut       **ppAudioOut,
 AudioOut_Params *pAudioOutParams
)
{
  AudioOut_Error eResult = AUDIO_OUTPUT_OK;

  /* check param */
  if (AUDIOOUT_NULL == pAudioOutParams)
  {
    eResult = AUDIO_OUTPUT_ERR_INV_PARAM;
  }

  else if (AUDIOOUT_NULL == ppAudioOut)
  {
    AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): invalid handle \'ppAudioOut = NULL\' (must not be NULL).");
    eResult = AUDIO_OUTPUT_ERR_INV_PARAM;
  }

  else if (AUDIOOUT_NULL != *ppAudioOut)
  {
    AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): invalid parameter \'*ppAudioOut = NULL\' (has to be NULL).");
    eResult = AUDIO_OUTPUT_ERR_INV_PARAM;
  }

  /* check version */
  else if (AUDIOOUT_TRUE != AudioOut_CheckAudioVersion(pAudioOutParams->uVersionNum, pAudioOutParams->pLogModule))
  {
    AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): invalid pal audio version \'pAudioOutParams->uVersionNum = %u\'.", pAudioOutParams->uVersionNum);
    eResult = AUDIO_OUTPUT_ERR_VERSION;
  }

  /* number of supported output channels */
  else if (1 > pAudioOutParams->uNumChannels || SUPPORTED_CHANNELS < pAudioOutParams->uNumChannels)
  {
    AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): invalid number of channels \'pAudioOutParams->uNumChannels = %u\'.", pAudioOutParams->uNumChannels);
    eResult = AUDIO_OUTPUT_ERR_CH_CNT;
  }

  /* maximum number of frames  */
  else if (0u == pAudioOutParams->uMaxNumberFrames)
  {
    AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): invalid max number of frames \'pAudioOutParams->uMaxNumberFrames = 0\'.");
    eResult = AUDIO_OUTPUT_ERR_SIZE_DEV_BUF;
  }

  /* maximum size of frames  */
  else if (0u == pAudioOutParams->uMaxSizeFrame)
  {
    AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): invalid maximum size of frames \'pAudioOutParams->uMaxSizeFrame = 0\'.");
    eResult = AUDIO_OUTPUT_ERR_SIZE_DEV_BUF;
  }

  else if (0u == pAudioOutParams->uSampleRate)
  {
    AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): invalid sample rate \'pAudioOutParams->uSampleRate = 0\'.");
    eResult = AUDIO_OUTPUT_ERR_SAMPLE_RATE;
  }

  else if (AUDIOOUT_NULL == pAudioOutParams->pDevIdentifier)
  {
    AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): invalid device identifier \'pAudioOutParams->pDevIdentifier = NULL\'.");
    eResult = AUDIO_OUTPUT_ERR_INV_DEV_ID;
  }

  else
  {
    AudioOut *pTmpAudioOut = AUDIOOUT_NULL;
    /* Allocates memory for the AudioOut structure */
    pTmpAudioOut = (AudioOut*) calloc(1, sizeof(AudioOut));
    pTmpAudioOut->pDevName = calloc(strlen(pAudioOutParams->pDevIdentifier)+1, sizeof(AudioOut_Char));

    if (AUDIOOUT_NULL == pTmpAudioOut)
    {
      AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): calloc() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }

    else if (AUDIOOUT_NULL == pTmpAudioOut->pDevName)
    {
      AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): calloc() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }

    /* init the needed semaphores */
    else if (0 != AudioOut_SemaInit(&pTmpAudioOut->pThreadCtrlSema, 1u, pAudioOutParams->pLogModule))
    {
      AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): AudioOut_SemaInit() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }

    else if (0 != AudioOut_SemaInit(&pTmpAudioOut->pFeedbackSema, 0u, pAudioOutParams->pLogModule))
    {
      AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): AudioOut_SemaInit() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }

    pTmpAudioOut->pMutex = (AudioOut_Mutex*) calloc(1U, sizeof(AudioOut_Mutex));

    if (pTmpAudioOut->pMutex == AUDIOOUT_NULL)
    {
      return AUDIO_OUTPUT_ERR_INTERNAL;
    }

    /* init the needed mutex */
    else if (0 != pthread_mutex_init(&(pTmpAudioOut->pMutex->hMutex), AUDIOOUT_NULL))
    {
      AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): pthread_mutex_init() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }

    else
    {
      /* Set the default values */
      pTmpAudioOut->uiNumberOfBuffers = pAudioOutParams->uMaxNumberFrames + 1u;
      pTmpAudioOut->uiFrameCount      = pAudioOutParams->uMaxSizeFrame;
      pTmpAudioOut->uiChannelCount    = pAudioOutParams->uNumChannels;
      pTmpAudioOut->uiPendingBuffers  = DEVICE_PLAY_BUFFER_COUNT;
      pTmpAudioOut->iWaitTimeout      = PACKAGE_TIMEOUT * pTmpAudioOut->uiFrameCount * 1000u / pAudioOutParams->uSampleRate;
      pTmpAudioOut->bNonInterleavedStream = pAudioOutParams->bFrameMuxFlag;
      pTmpAudioOut->bSndPcmError      = AUDIOOUT_FALSE;
      pTmpAudioOut->bAbortMissing     = AUDIOOUT_FALSE;
      pTmpAudioOut->startBurstPackageCount = 0;
      pTmpAudioOut->pLogModule = pAudioOutParams->pLogModule;

      /* copy the dev name */
      strncpy(pTmpAudioOut->pDevName,pAudioOutParams->pDevIdentifier, strlen(pAudioOutParams->pDevIdentifier));

      /* setting the eState */
      pthread_mutex_lock(&(pTmpAudioOut->pMutex->hMutex));
      pTmpAudioOut->eState = E_WAVE_STATE_IDLE;
      pthread_mutex_unlock(&(pTmpAudioOut->pMutex->hMutex));

      /* open the device */
      if (0 != AudioOut_Audio_OpenDevInternal(&(pTmpAudioOut->hAudioOut), pAudioOutParams->pDevIdentifier, SND_PCM_STREAM_PLAYBACK, pAudioOutParams->pLogModule))
      {
        AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device():[%s]: AudioOut_Audio_OpenDevInternal() failed.", pTmpAudioOut->pDevName);
        eResult = AUDIO_OUTPUT_ERR_INTERNAL;
      }

      else
      {
        AudioOut_Int32 iASoundRes = 0;
        snd_pcm_hw_params_t *hw_params = AUDIOOUT_NULL;
        snd_pcm_sw_params_t *sw_params = AUDIOOUT_NULL; /*software params*/

        snd_pcm_access_t aSoundAccess;
        snd_pcm_uframes_t size = 0;
        snd_pcm_sframes_t period_size = 0;
        snd_pcm_uframes_t buffer_size = 0;

        AudioOut_UInt32 uSampleRate = pAudioOutParams->uSampleRate;
        AudioOut_UInt32 uBufferTimeDesired = 0;
        AudioOut_UInt32 uBufferTimeGot     = 0;

        /* HW PARAMS SETTINGS */

        /* init param struct */
        if (0 > (iASoundRes = snd_pcm_hw_params_malloc(&hw_params)))
        {
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_hw_params_malloc() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
          eResult = AUDIO_OUTPUT_ERR_INTERNAL;
        }

        if (0 > (iASoundRes = snd_pcm_hw_params_any(pTmpAudioOut->hAudioOut, hw_params)))
        {
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_hw_params_any() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
          eResult = AUDIO_OUTPUT_ERR_INTERNAL;
        }

        aSoundAccess = (AUDIOOUT_TRUE==pTmpAudioOut->bNonInterleavedStream)?SND_PCM_ACCESS_RW_NONINTERLEAVED:SND_PCM_ACCESS_RW_INTERLEAVED;
        if (0 > (iASoundRes = snd_pcm_hw_params_set_access(pTmpAudioOut->hAudioOut, hw_params, aSoundAccess)))
        {
          /* for one channel devices try the other one, since it does not matter at all */
          if (1 == pAudioOutParams->uNumChannels)
          {
            AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Open_Device(): snd_pcm_hw_params_set_access() failed (%s). Single Channel Device trying other access method ...\n",snd_strerror (iASoundRes));

            pTmpAudioOut->bNonInterleavedStream = (AUDIOOUT_TRUE==pAudioOutParams->bFrameMuxFlag)?AUDIOOUT_FALSE:AUDIOOUT_TRUE;
            aSoundAccess = (AUDIOOUT_TRUE==pTmpAudioOut->bNonInterleavedStream)?SND_PCM_ACCESS_RW_NONINTERLEAVED:SND_PCM_ACCESS_RW_INTERLEAVED;

            if (0 > (iASoundRes = snd_pcm_hw_params_set_access(pTmpAudioOut->hAudioOut, hw_params, aSoundAccess)))
            {
              AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_hw_params_set_access() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
              eResult = AUDIO_OUTPUT_ERR_INTERNAL;
            }

            else
            {
              AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Open_Device(): other access method supported, so return silently.\n");
            }
          }

          else
          {
            AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_hw_params_set_access() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
            eResult = AUDIO_OUTPUT_ERR_INTERNAL;
          }
        }

        if (0 > (iASoundRes = snd_pcm_hw_params_set_format(pTmpAudioOut->hAudioOut, hw_params, SND_PCM_FORMAT_S16_LE)))
        {
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_hw_params_set_format() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
          eResult = AUDIO_OUTPUT_ERR_INTERNAL;
        }

        if (0 > (iASoundRes = snd_pcm_hw_params_set_rate_near(pTmpAudioOut->hAudioOut, hw_params, &uSampleRate, 0)))
        {
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_hw_params_set_rate_near() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
          eResult = AUDIO_OUTPUT_ERR_INTERNAL;
        }

        else
        {
          if (uSampleRate != pAudioOutParams->uSampleRate)
          {
            AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): sample rate = %d Hz is not supported, device recommends %d Hz.",pAudioOutParams->uSampleRate, uSampleRate);
            eResult = AUDIO_OUTPUT_ERR_INTERNAL;
          }
        }

        if (0 > (iASoundRes = snd_pcm_hw_params_set_channels(pTmpAudioOut->hAudioOut, hw_params, pAudioOutParams->uNumChannels)))
        {
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_hw_params_set_channels() failed with error = %i: %s.", iASoundRes, snd_strerror(iASoundRes));
          eResult = AUDIO_OUTPUT_ERR_INTERNAL;
        }

        if (0 > (iASoundRes = snd_pcm_hw_params_set_period_size(pTmpAudioOut->hAudioOut, hw_params, pAudioOutParams->uMaxSizeFrame, 0)))
        {
          snd_pcm_uframes_t uTmpFrameSize=0;
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Open_Device(): snd_pcm_hw_params_set_period_size() failed: (%s). Will try to get size from device...\n",snd_strerror(iASoundRes));

          if (0 > (iASoundRes = snd_pcm_hw_params_get_period_size(hw_params, &uTmpFrameSize, 0)))
          {
            AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_hw_params_get_period_size() also failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
            eResult = AUDIO_OUTPUT_ERR_INTERNAL;
          }

          else if (uTmpFrameSize != pAudioOutParams->uMaxSizeFrame)
          {
            AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): :snd_pcm_hw_params_get_period_size() != uMaxSizeFrame: (%lu != %d).",uTmpFrameSize, pAudioOutParams->uMaxSizeFrame);
            eResult = AUDIO_OUTPUT_ERR_INTERNAL;
          }
          else
          {
            AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Open_Device(): snd_pcm_hw_params_get_period_size(): == uMaxSizeFrame: (%lu == %d), so return silently.\n",uTmpFrameSize, pAudioOutParams->uMaxSizeFrame);
            period_size = uTmpFrameSize;
          }
        }

        else
        {
          period_size = pAudioOutParams->uMaxSizeFrame;
        }

        /* set the drivers internal ring buffer size */
        uBufferTimeDesired = (AudioOut_UInt32) DEVICE_PLAY_BUFFER_COUNT * pTmpAudioOut->uiFrameCount * 1000.0f / pAudioOutParams->uSampleRate * 1000.0f;
        uBufferTimeGot     = uBufferTimeDesired;

        AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Open_Device(): set btime %dus (bcount %d)\n",uBufferTimeDesired, DEVICE_PLAY_BUFFER_COUNT);

        if (0 > (iASoundRes = snd_pcm_hw_params_set_buffer_time_near(pTmpAudioOut->hAudioOut, hw_params, &uBufferTimeGot, 0)))
        {
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_hw_params_set_buffer_time_near() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
          eResult = AUDIO_OUTPUT_ERR_INTERNAL;
        }

        else
        {
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Open_Device(): got btime %dus wanted %dus\n",uBufferTimeGot, uBufferTimeDesired);

          if (uBufferTimeGot != uBufferTimeDesired)
          {
            AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): buffer time = %d us is not supported, device recommends %d us.", uBufferTimeDesired, uBufferTimeGot);
            eResult = AUDIO_OUTPUT_ERR_INTERNAL;
          }

          else
          {
            if (0 > (iASoundRes = snd_pcm_hw_params_get_buffer_size(hw_params, &buffer_size)))
            {
              AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): buffer size not available.");
              eResult = AUDIO_OUTPUT_ERR_INTERNAL;
            }
          }
        }

        iASoundRes = snd_pcm_hw_params(pTmpAudioOut->hAudioOut, hw_params);

        if (0 > iASoundRes)
        {
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_hw_params() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
          eResult = AUDIO_OUTPUT_ERR_INTERNAL;
        }

        /* clean up */
        snd_pcm_hw_params_free(hw_params);

        /* SW PARAMS SETTINGS */

        if (AUDIO_OUTPUT_OK != eResult)
        {
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device():[%s]: error occurred during hw parameter setting. step over the setting of sw parameters.", pTmpAudioOut->pDevName);
        }

        else
        {
          if (0 > (iASoundRes =  snd_pcm_sw_params_malloc(&sw_params)))
          {
            AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_sw_params_malloc() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
            eResult = AUDIO_OUTPUT_ERR_INTERNAL;
          }

          else
          {
            iASoundRes = snd_pcm_sw_params_current(pTmpAudioOut->hAudioOut, sw_params);

            if (0 > iASoundRes)
            {
              AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_sw_params_current() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
              eResult = AUDIO_OUTPUT_ERR_INTERNAL;
            }
          }

          if (AUDIO_OUTPUT_OK == eResult)
          {
            /* set avail min to period size */
            if (0 > (iASoundRes = snd_pcm_sw_params_get_avail_min(sw_params, &size)))
            {
              AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_sw_params_get_avail_min() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
              eResult = AUDIO_OUTPUT_ERR_INTERNAL;
            }

            else if (period_size != size)
            {
              if (0 > (iASoundRes = snd_pcm_sw_params_set_avail_min(pTmpAudioOut->hAudioOut, sw_params, period_size)))
              {
                AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_sw_params_set_avail_min() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                eResult = AUDIO_OUTPUT_ERR_INTERNAL;
              }
            }

            AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Open_Device(): Current period_size %u, defined period_size %u\n", (unsigned int) size, (unsigned int) period_size);

            if (AUDIO_OUTPUT_OK == eResult)
            {
              /* set PLAYBACK start threshold to buffer size */
              if (0 > (iASoundRes = snd_pcm_sw_params_get_start_threshold(sw_params, &size)))
              {
                AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_sw_params_get_start_threshold() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                eResult = AUDIO_OUTPUT_ERR_INTERNAL;
              }

              else if (1u != size)
              {
                if (0 > (iASoundRes = snd_pcm_sw_params_set_start_threshold(pTmpAudioOut->hAudioOut, sw_params, 1u)))
                {
                  AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_sw_params_set_start_threshold() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                  eResult = AUDIO_OUTPUT_ERR_INTERNAL;
                }
              }

              AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Open_Device(): Current start threshold %u derived from buffer size %u\n", (unsigned int) size, (unsigned int) buffer_size);

              /* Set period event (1) when avail min should be deactivated */
            }

            if (AUDIO_OUTPUT_OK == eResult)
            {
              iASoundRes = snd_pcm_sw_params(pTmpAudioOut->hAudioOut, sw_params);

              if (0 > iASoundRes)
              {
                AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): snd_pcm_sw_params() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
                eResult = AUDIO_OUTPUT_ERR_INTERNAL;
              }
            }
          }

          /* clean up */
          snd_pcm_sw_params_free(sw_params);
        }

        /* make dev ready to start */
        if (0 != AudioOut_Audio_Prepare_Device(pTmpAudioOut->hAudioOut, SND_PCM_STREAM_PLAYBACK, pAudioOutParams->pLogModule))
        {
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): AudioOut_Audio_Prepare_Device() failed.");
          eResult = AUDIO_OUTPUT_ERR_INTERNAL;
        }
      }

      /* check errorcode */
      if (AUDIO_OUTPUT_OK != eResult)
      {
        AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): [%s]: Activating audio device failed.", pTmpAudioOut->pDevName);
      }

      else
      {
        /* create callback ring_buffer */
        pTmpAudioOut->pPlayList = (TPlayFrame*)calloc(pTmpAudioOut->uiNumberOfBuffers, sizeof(TPlayFrame));
        if (AUDIOOUT_NULL == pTmpAudioOut->pPlayList)
        {
          AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): calloc() failed.");
          eResult = AUDIO_OUTPUT_ERR_INTERNAL;
        }

        else
        {
          /* init working variables */
          pTmpAudioOut->pHead         = pTmpAudioOut->pPlayList;
          pTmpAudioOut->pTailPlay     = pTmpAudioOut->pPlayList;
          pTmpAudioOut->pTailRelease  = pTmpAudioOut->pPlayList;
          pTmpAudioOut->uiFreeBuffers = pTmpAudioOut->uiNumberOfBuffers;
          pTmpAudioOut->pLogModule     = pAudioOutParams->pLogModule;

          /* create worker_thread and start worker_thread */
          if (0 != pthread_create(&(pTmpAudioOut->threadIdentifier), AUDIOOUT_NULL, ThAudioOut, pTmpAudioOut))
          {
            AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Open_Device(): pthread_create() failed.");
            eResult = AUDIO_OUTPUT_ERR_INTERNAL;
          }

          else
          {
            /* wait for worker_thread */
            AudioOut_SemaWait(pTmpAudioOut->pFeedbackSema, pAudioOutParams->pLogModule);

            /* init done set eState */
            pthread_mutex_lock(&(pTmpAudioOut->pMutex->hMutex));
            pTmpAudioOut->eState = E_WAVE_STATE_WAITING;
            pthread_mutex_unlock(&(pTmpAudioOut->pMutex->hMutex));

            /* return valid handle */
            (*ppAudioOut) = pTmpAudioOut;
            pTmpAudioOut = AUDIOOUT_NULL;
          } /* else of pthread_create */
        } /* else of if (AUDIOOUT_NULL == pTmpAudioOut->pPlayList) */
      } /* if (AUDIO_OUTPUT_OK == eResult) */
    } /* else of if (AUDIOOUT_NULL == pTmpAudioOut) */

    /* clean up if necessary */
    if (AUDIOOUT_NULL != pTmpAudioOut)
    {
      AUDIOOUT_LOG(pAudioOutParams->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Open_Device(): cleaning up partly initialized handle.\n");
      AudioOut_Close(&pTmpAudioOut);
    }
  } /* else of check params */
  return eResult;
}

AudioOut_Error AudioOut_Close
(
  AudioOut **ppAudioOut
)
{
  AudioOut_Error eResult = AUDIO_OUTPUT_OK;

  AudioOut *pTmpAudioOut = AUDIOOUT_NULL;
  void *pThreadExitCode = AUDIOOUT_NULL;

  /* check params */
  if (AUDIOOUT_NULL == ppAudioOut)
  {
    eResult = AUDIO_OUTPUT_ERR_INV_PARAM;
  }

  else if (AUDIOOUT_NULL == *ppAudioOut)
  {
    eResult = AUDIO_OUTPUT_ERR_INV_PARAM;
  }

  /* get the mutex if possible */
  else if (0 != pthread_mutex_lock(&((*ppAudioOut)->pMutex->hMutex)))
  {
    AUDIOOUT_LOG((*ppAudioOut)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Close(): pthread_mutex_lock() failed.");
    eResult = AUDIO_OUTPUT_ERR_INTERNAL;
  }

  else
  {
    AudioOut_Int iASoundRes;

    /* check eState */
    if (E_WAVE_STATE_IDLE != (*ppAudioOut)->eState && E_WAVE_STATE_WAITING != (*ppAudioOut)->eState)
    {
      AUDIOOUT_LOG((*ppAudioOut)->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Close(): ABORT/CLOSE state=%d\n", (*ppAudioOut)->eState);
      (*ppAudioOut)->bAbortMissing = AUDIOOUT_TRUE;
    }

    else
    {
      AUDIOOUT_LOG((*ppAudioOut)->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Close(): CLOSE state=%d\n", (*ppAudioOut)->eState);
    }

    /* invalidate handle */
    pTmpAudioOut  = (*ppAudioOut);
    (*ppAudioOut) = AUDIOOUT_NULL;

    pTmpAudioOut->eState = E_WAVE_STATE_CLOSING;

    /* wake the thread */
    if (0 != AudioOut_SemaSignal(pTmpAudioOut->pThreadCtrlSema, pTmpAudioOut->pLogModule))
    {
      AUDIOOUT_LOG(pTmpAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Close():AudioOut_SemaSignal() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }

    /* signal the mutex */
    if (0 != pthread_mutex_unlock(&(pTmpAudioOut->pMutex->hMutex)))
    {
      AUDIOOUT_LOG(pTmpAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Close(): pthread_mutex_unlock() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }

    /* wait for the thread termination */
    if (0 != pthread_join(pTmpAudioOut->threadIdentifier, &pThreadExitCode))
    {
      AUDIOOUT_LOG(pTmpAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Close(): pthread_join() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }

    /* get the mutex if possible */
    if (0 != pthread_mutex_lock(&(pTmpAudioOut->pMutex->hMutex)))
    {
      AUDIOOUT_LOG(pTmpAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Close(): pthread_mutex_lock() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }

    /* close device */
    if (AUDIOOUT_NULL != pTmpAudioOut->hAudioOut)
    {
      iASoundRes = snd_pcm_close(pTmpAudioOut->hAudioOut);

      if (0 > iASoundRes)
      {
        AUDIOOUT_LOG(pTmpAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:-audioout::AudioOut_Close(): snd_pcm_close() failed with error = %i: %s", iASoundRes, snd_strerror(iASoundRes));
      }
    }

    /* delete ring_buffer */
    if (AUDIOOUT_NULL != pTmpAudioOut->pPlayList)
    {
      AUDIOOUT_FREE_SET_NULL(pTmpAudioOut->pPlayList);
    }

    /* deinit the needed semaphores */
    if (AUDIOOUT_NULL != pTmpAudioOut->pThreadCtrlSema)
    {
      AudioOut_SemaDeInit(&pTmpAudioOut->pThreadCtrlSema, pTmpAudioOut->pLogModule);
    }

    if (AUDIOOUT_NULL != pTmpAudioOut->pFeedbackSema)
    {
      AudioOut_SemaDeInit(&pTmpAudioOut->pFeedbackSema, pTmpAudioOut->pLogModule);
    }

    /* deinit mutex */
    if (AUDIOOUT_NULL != pTmpAudioOut->pMutex)
    {
      pthread_mutex_destroy(&(pTmpAudioOut->pMutex->hMutex));
    }

    /* clean up the dev name */
    if (AUDIOOUT_NULL != pTmpAudioOut->pDevName)
    {
      AUDIOOUT_FREE_SET_NULL(pTmpAudioOut->pDevName);
    }

    /* delete handle */
    AUDIOOUT_FREE_SET_NULL(pTmpAudioOut);
  }
  return eResult;
}

AudioOut_Error AudioOut_Write
(
  AudioOut *pAudioOut,
  const AudioOut_Int16  *audioPackage,
  AudioOut_UInt32 sizeAudioPackage,
  CbPackagePlayed fpPackagePlayed,
  void *udPackagePlayed
)
{
  AudioOut_Error eResult = AUDIO_OUTPUT_OK;

  /* check params */
  if (AUDIOOUT_NULL == pAudioOut)
  {
    eResult =  AUDIO_OUTPUT_ERR_INV_PARAM;
  }

  else if (AUDIOOUT_NULL == audioPackage)
  {
    AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Write(): invalid parameter \'audioPackage = NULL\'.");
    eResult = AUDIO_OUTPUT_ERR_INV_PARAM;
  }

  else if (AUDIOOUT_NULL == fpPackagePlayed)
  {
    AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Write(): invalid parameter \'fpPackagePlayed = NULL\'.");
    eResult = AUDIO_OUTPUT_ERR_INV_PARAM;
  }

  /* check size */
  else if ((0 == sizeAudioPackage) || ((pAudioOut->uiFrameCount * pAudioOut->uiChannelCount) < sizeAudioPackage))
  {
    AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Write(): invalid parameter \'sizeAudioPackage = %u\'.", sizeAudioPackage);
    eResult = AUDIO_OUTPUT_ERR_SIZE_PACK;
  }

  /* get mutex */
  else if (0 != pthread_mutex_lock(&(pAudioOut->pMutex->hMutex)))
  {
    AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Write(): pthread_mutex_lock() failed.");
    eResult = AUDIO_OUTPUT_ERR_INTERNAL;
  }

  else
  {
     /* check for available play buffers */
    if (1u == pAudioOut->uiFreeBuffers)
    {
      AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Write(): no free buffers available.");
      eResult = AUDIO_OUTPUT_ERR_MAX_NUM_PACK;
    }

    else
    {
      /* check current eState */
      if ((E_WAVE_STATE_PLAYING  == pAudioOut->eState) || (E_WAVE_STATE_WAITING == pAudioOut->eState) || (E_WAVE_STATE_STARTING == pAudioOut->eState))
      {
        /* store cb data and package pointer */
        pAudioOut->pHead->eState = E_PACKAGE_STATE_PLAY;
        pAudioOut->pHead->pAudioPackageUser = audioPackage;
        pAudioOut->pHead->sSizeAudioPackageUser = sizeAudioPackage;
        pAudioOut->pHead->fpPackagePlayed = fpPackagePlayed;
        pAudioOut->pHead->udPackagePlayed = udPackagePlayed;

        /* inc working variables */
        pAudioOut->uiFreeBuffers--;
        if (pAudioOut->pHead == pAudioOut->pPlayList + (pAudioOut->uiNumberOfBuffers - 1))
        {
          pAudioOut->pHead = pAudioOut->pPlayList;
        }

        else
        {
          pAudioOut->pHead++;
        }

        /* wake the thread if necessary */
        if (E_WAVE_STATE_WAITING == pAudioOut->eState)
        {
          ++pAudioOut->startBurstPackageCount;
          if (DEVICE_PLAY_BUFFER_COUNT <= pAudioOut->startBurstPackageCount)
          {
            pAudioOut->eState = E_WAVE_STATE_STARTING;
            if (0 != AudioOut_SemaSignal(pAudioOut->pThreadCtrlSema, pAudioOut->pLogModule))
            {
              AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Write(): AudioOut_SemaSignal() failed.");
              eResult = AUDIO_OUTPUT_ERR_INTERNAL;
            }
          }
        }

        if (AUDIOOUT_FALSE != pAudioOut->bSndPcmError)
        {
          AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Write(): device error occurred.");
          eResult = AUDIO_OUTPUT_ERR_WRITE_DEV;
        }
      }

      else
      {
        AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_Write(): wrong internal state (%d)\n", pAudioOut->eState);
        eResult = AUDIO_OUTPUT_ERR_WRITE_DEV;
      }
    }

    /* release mutex */
    if (0 != pthread_mutex_unlock(&(pAudioOut->pMutex->hMutex)))
    {
      AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Write():pthread_mutex_unlock() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }
  }
  return eResult;
}

AudioOut_Error AudioOut_EndOfStream
(
  AudioOut *pAudioOut
)
{
  AudioOut_Error eResult = AUDIO_OUTPUT_OK;

  if (AUDIOOUT_NULL == pAudioOut)
  {
    eResult = AUDIO_OUTPUT_ERR_INV_PARAM;
  }

  else if (0 != pthread_mutex_lock(&(pAudioOut->pMutex->hMutex)))
  {
    AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_EndOfStream(): pthread_mutex_lock() failed.");
    eResult = AUDIO_OUTPUT_ERR_INTERNAL;
  }

  else
  {
    /* check for available play buffers */
    if (0u == pAudioOut->uiFreeBuffers)
    {
      AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_EndOfStream(): internal queue is full.");
      eResult = AUDIO_OUTPUT_ERR_MAX_NUM_PACK;
    }

    else
    {
      /* check current eState */
      if ((E_WAVE_STATE_PLAYING == pAudioOut->eState) || (E_WAVE_STATE_WAITING == pAudioOut->eState) || (E_WAVE_STATE_STARTING == pAudioOut->eState))
      {
        /* store empty package as EOS marker */
        pAudioOut->pHead->eState = E_PACKAGE_STATE_PLAY;
        pAudioOut->pHead->pAudioPackageUser = AUDIOOUT_NULL;
        pAudioOut->pHead->sSizeAudioPackageUser = 0;
        pAudioOut->pHead->fpPackagePlayed = AUDIOOUT_NULL;
        pAudioOut->pHead->udPackagePlayed = AUDIOOUT_NULL;

        /* inc working variables */
        pAudioOut->uiFreeBuffers--;
        if (++pAudioOut->pHead == pAudioOut->pPlayList + pAudioOut->uiNumberOfBuffers)
        {
          pAudioOut->pHead = pAudioOut->pPlayList;
        }

        /* wake the thread if necessary */
        if (E_WAVE_STATE_WAITING == pAudioOut->eState)
        {
          pAudioOut->eState = E_WAVE_STATE_STARTING;
          if (0 != AudioOut_SemaSignal(pAudioOut->pThreadCtrlSema, pAudioOut->pLogModule))
          {
            AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_EndOfStream(): AudioOut_SemaSignal() failed.");
            eResult = AUDIO_OUTPUT_ERR_INTERNAL;
          }
        }
      }

      else
      {
        AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_INFO, "INFO audioout::AudioOut_EndOfStream(): wrong internal state (%d)\n", pAudioOut->eState);
        eResult = AUDIO_OUTPUT_ERR_WRITE_DEV;
      }
    }

    /* release mutex */
    if (0 != pthread_mutex_unlock(&(pAudioOut->pMutex->hMutex)))
    {
      AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_EndOfStream(): pthread_mutex_unlock() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }
  }
  return eResult;
}

AudioOut_Error AudioOut_Abort
(
  AudioOut *pAudioOut
)
{
  AudioOut_Error eResult = AUDIO_OUTPUT_OK;

  if (AUDIOOUT_NULL == pAudioOut)
  {
    AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Abort(): invalid handle \'pAudioOut = NULL\'.");
    eResult = AUDIO_OUTPUT_ERR_INV_PARAM;
  }

  /* get mutex */
  else if (0 != pthread_mutex_lock(&(pAudioOut->pMutex->hMutex)))
  {
    AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Abort(): pthread_mutex_lock() failed.");
    eResult = AUDIO_OUTPUT_ERR_INTERNAL;
  }

  else
  {
    /* check the current eState */
    if (0 == pAudioOut->startBurstPackageCount && pAudioOut->eState == E_WAVE_STATE_WAITING)
    {
      eResult = AUDIO_OUTPUT_OK;
    }

    else
    {
      /* stop output on audio output device */
      pAudioOut->eState = E_WAVE_STATE_STOPPING;

      /* wake thread */
      if (0 != AudioOut_SemaSignal(pAudioOut->pThreadCtrlSema, pAudioOut->pLogModule))
      {
        AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Abort():  AudioOut_SemaSignal() failed.");
        eResult = AUDIO_OUTPUT_ERR_INTERNAL;
      }

      /* release mutex */
      if (0 != pthread_mutex_unlock(&(pAudioOut->pMutex->hMutex)))
      {
        AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Abort():  pthread_mutex_unlock() failed.");
        eResult = AUDIO_OUTPUT_ERR_INTERNAL;
      }

      /* and wait for response */
      if (0 != AudioOut_SemaWait(pAudioOut->pFeedbackSema, pAudioOut->pLogModule))
      {
        AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Abort():  AudioOut_SemaWait() failed.");
        eResult = AUDIO_OUTPUT_ERR_INTERNAL;
      }

      /* get mutex */
      if (0 != pthread_mutex_lock(&(pAudioOut->pMutex->hMutex)))
      {
        AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Abort():  pthread_mutex_lock() failed.");
        eResult = AUDIO_OUTPUT_ERR_INTERNAL;
      }

      /* check eState */
      if (pAudioOut->eState != E_WAVE_STATE_WAITING)
      {
        AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Abort():  invalid state = %d.", pAudioOut->eState);
        eResult = AUDIO_OUTPUT_ERR_INTERNAL;
      }
    }

    /* release mutex */
    if (0 != pthread_mutex_unlock(&(pAudioOut->pMutex->hMutex)))
    {
      AUDIOOUT_LOG(pAudioOut->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- audioout::AudioOut_Abort():  pthread_mutex_unlock() failed.");
      eResult = AUDIO_OUTPUT_ERR_INTERNAL;
    }
  }
  return eResult;
}
