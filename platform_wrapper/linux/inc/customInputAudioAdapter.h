#ifndef IG_CUSTOMINPUTAUDIOADAPTER_H
#define IG_CUSTOMINPUTAUDIOADAPTER_H

#include "IAudioInputAdapter.h"
#include "lh_types.h"
#include "IAudioManager.h"
#include "ResultCode.h"
#include "audioin.h"

#if defined( __cplusplus )
extern "C"
{
#endif

enum State
{
  STATE_CLOSED = 0, // audio input adapter is closed
  STATE_STOPPED, // audio input adapter is stopped, but opened
  STATE_STARTED // audio input adapter is started
};

const LH_CHAR* customAudioInputAdapter_State_to_String
(
  enum State state
);

typedef struct _customAudioInputAdapter
{
  AudioIn_Params pAudioInParam;
  AudioIn *pAudioInHandle;
  nuance_audio_IAudioInputAdapterListener *plistener;
  AudioIn_Error audioin_err ;
  enum State state_;
  LH_CHAR *deviceName;
  LH_CHAR *platformConfig;
  nuance_audio_IAudioInputAdapter *customAdapterInstance;
  nuance_common_ILogModule *pLogModule;
} customAudioInputAdapter;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:   IAudioInputAdapter
 *  Caller:       AudioInput
 *  @brief        Configures the audio input adapter.
 *                For detailed description see IAudioInputAdapter.h
 *
 *  @param        instance
 *                  [in,out] The instance pointer
 *                listener
 *                  [in] Listener of this audio input adapter object.
 *                adapterParams
 *                  [in] Adapter specific configuration parameter json string.
 *                interleavedFormat
 *                  [in] Flag indicating whether audio data shall be in
 *                interleaved or non-interleaved format.
 *                channelCount
 *                  [in] Channel count.
 *                sampleRate
 *                  [in] Sample rate in hertz.
 *                samplesPerChannel
 *                  [in] Number of samples per channel.
 *
 *  @return       Result code
 *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioInputAdapter_configure
(
  void *instance,
  nuance_audio_IAudioInputAdapterListener *listener,
  const LH_CHAR *adapterParams,
  LH_BOOL interleavedFormat,
  LH_S32 channelCount,
  LH_S32 sampleRate,
  LH_S32 samplesPerChannel
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioInputAdapter
 *  Caller:         AudioInput
 *  @brief          Opens the audio input adapter
 *                  For detailed description see IAudioInputAdapter.h
 *
 *  @param          instance
 *                    [in,out] The instance pointer
 *
 *  @return         Result code
 *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioInputAdapter_open
(
  void *instance
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioInputAdapter
 *  Caller:         AudioInput
 *  @brief          Starts capturing via the audio input adapter.
 *                  For detailed description see IAudioInputAdapter.h
 *
 *  @param          instance
 *                    [in,out] The instance pointer
 *
 *  @return         Result code
 *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioInputAdapter_start
(
  void *instance
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioInputAdapter
 *  Caller:         AudioInput
 *  @brief          Stops capturing via the audio input adapter
 *                  For detailed description see IAudioInputAdapter.h
 *
 *  @param          instance
 *                    [in,out] The instance pointer
 *
 *  @return         Result code
 *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioInputAdapter_stop
(
  void *instance
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioInputAdapter
 *  Caller:         AudioInput
 *  @brief          Resumes capturing via the audio input adapter.
 *                  For detailed description see IAudioInputAdapter.h
 *
 *  @param          instance
 *                    [in,out] The instance pointer
 *
 *  @return         Result code
 *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioInputAdapter_resume
(
  void *instance
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioInputAdapter
 *  Caller:         AudioInput
 *  @brief          Closes the audio input adapter.
 *                  For detailed description see IAudioInputAdapter.h
 *
 *  @param          instance
 *                    [in,out] The instance pointer
 *
 *  @return         Result code
 *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioInputAdapter_close
(
  void *instance
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioInputAdapter
 *  Caller:         AudioInput
 *  @brief          Returns a textual description of the last audio
 *                  input adapter error. For detailed description see
 *                  IAudioInputAdapter.h
 *
 *  @param          instance
 *                    [in,out] The instance pointer
 *
 *  @return         Textual description of the provided error code
 *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_String* customAudioInputAdapter_getErrorText
(
  const void *instance
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioInputAdapter
 *  Caller:         AudioInput
 *  @brief          Destroys this audio input adapter instance.
 *                  For detailed description see IAudioInputAdapter.h
 *
 *  @param          instance
 *                    [in,out] The instance pointer
 *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void customAudioInputAdapter_destroyAdapter
(
  void *instance
);

#if defined( __cplusplus )
}
#endif
#endif /* IG_CUSTOMINPUTAUDIOADAPTER_H */
