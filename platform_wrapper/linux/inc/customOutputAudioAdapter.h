#ifndef IG_CUSTOMOUTPUTAUDIOADAPTER_H
#define IG_CUSTOMOUTPUTAUDIOADAPTER_H

#include "IAudioOutputAdapter.h"
#include "lh_types.h"
#include "IAudioManager.h"
#include "ResultCode.h"
#include "audioout.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct _customAudioOutputAdapter
{
  nuance_audio_IAudioOutputAdapterListener *plistener;
  AudioOut_Params pAudioOutParam;
  AudioOut *pAudioOutHandle;
  AudioOut_Error audioout_err ;
  LH_CHAR *deviceName;
  LH_CHAR *platformConfig;
  nuance_audio_IAudioOutputAdapter *customAdapterInstance;
  nuance_common_ILogModule *pLogModule;
} customAudioOutputAdapter;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioOutputAdapter
 *  Caller:         AudioOutput
 *  @brief          Configures the audio output adapter.
 *                  For detailed description see IAudioOutputAdapter.h
 *
 *  @param          instance
 *                        [in,out] The instance pointer
 *                  listener
 *                        [in] Listener of this audio output adapter object.
 *                  adapterParams
 *                        [in] Adapter specific configuration parameter json string.
 *                  interleavedFormat
 *                        [in] Flag indicating whether audio data shall be in interleaved or non-interleaved format.
 *                  channelCount
 *                        [in] Channel count.
 *                  sampleRate
 *                        [in] Sample rate in hertz.
 *                  samplesPerChannel
 *                        [in] Number of samples per channel.
 *                  bufferCount
 *                        [in] Number of audio buffers.
 *
 *  @return         Result code
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

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
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioOutputAdapter
 *  Caller:         AudioOutput
 *  @brief          Opens the audio output adapter
 *                  For detailed description see IAudioOutputAdapter.h
 *
 *  @param          instance
 *                        [in,out] The instance pointer
 *
 *  @return         Result code
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioOutputAdapter_open
(
  void *instance
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioOutputAdapter
 *  Caller:         AudioOutput
 *  @brief          Writes audio data for playback to the audio output adapter.
 *                  For detailed description see IAudioOutputAdapter.h
 *
 *  @param          instance
 *                        [in,out] The instance pointer
 *                  audioData
 *                        [in] AudioData object containing audio data for playback.
 *                  naudioData
 *                        [in] Number of elements in audioData.
 *
 *  @return         Result code
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioOutputAdapter_write
(
  void *instance,
  LH_S16  const *audioData,
  LH_S32 naudioData
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioOutputAdapter
 *  Caller:         AudioOutput
 *  @brief          Writes audio data for playback to the audio output adapter.
 *                  This method is called only if the audioDataType is not PCM16
 *                  For detailed description see IAudioOutputAdapter.h
 *
 *  @param          instance
 *                        [in,out] The instance pointer
 *                  audioData
 *                        [in] AudioData object containing audio data for playback.
 *                  byteCount
 *                        [in] Number of elements in audioData.
 *
 *  @return         Result code
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

 nuance_common_ResultCode customAudioOutputAdapter_writeEncoded
 (
  void *instance,
  LH_S8  const *audioData,
  LH_S32 byteCount
 );

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioOutputAdapter
 *  Caller:         AudioOutput
 *  @brief          Indicates the end of stream to the audio output adapter.
 *                  For detailed description see IAudioOutputAdapter.h
 *
 *  @param          instance
 *                        [in,out] The instance pointer
 *
 *  @return         Result code
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioOutputAdapter_endOfStream
(
  void *instance
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioOutputAdapter
 *  Caller:         AudioOutput
 *  @brief          Aborts the playback of the audio output adapter.
 *                  For detailed description see IAudioOutputAdapter.h
 *
 *  @param          instance
 *                        [in,out] The instance pointer
 *
 *  @return         Result code
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioOutputAdapter_abort
(
  void *instance
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioOutputAdapter
 *  Caller:         AudioOutput
 *  @brief          Closes the audio output adapter.
 *                  For detailed description see IAudioOutputAdapter.h
 *
 *  @param          instance
 *                         [in,out] The instance pointer
 *
 *  @return         Result code
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioOutputAdapter_close
(
  void *instance
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioOutputAdapter
 *  Caller:         AudioOutput
 *  @brief          Returns a textual description of the last audio
 *                  output adapter error.
 *                  For detailed description see IAudioOutputAdapter.h
 *
 *  @param          instance
 *                         [in,out] The instance pointer
 *
 *  @return         Textual description of the provided error code
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_String* customAudioOutputAdapter_getErrorText
(
  const void *instance
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioOutputAdapter
 *  Caller:         AudioOutput
 *  @brief          Destroys this audio output adapter instance.
 *                  For detailed description see IAudioOutputAdapter.h
 *
 *  @param          instance
 *                         [in,out] The instance pointer
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void customAudioOutputAdapter_destroyAdapter
(
  void *instance
);

#if defined( __cplusplus )
}
#endif
#endif // IG_CUSTOMOUTPUTAUDIOADAPTER_H
