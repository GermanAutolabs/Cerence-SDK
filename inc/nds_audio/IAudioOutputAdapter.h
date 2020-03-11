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
 *  Declaration of nuance_audio_IAudioOutputAdapter class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioOutputAdapter
 *  @{
 *  @file IAudioOutputAdapter.h
 *
 *  @brief  Audio output adapter interface. <p>
 *
 *  The implementation of this interface is responsible to realize the adaptation of the SDK's audio framework
 *  to a specific audio data sink (e.g. audio device, pipe, ..) used in a project.
 *
 *  The adapter implementation is used by the AudioOutput audio module to play back audio data via a
 *  specific audio data sink. Therefor the AudioOutput module uses the IAudioOutputAdapter interface to
 *  control the audio data sink and implements the corresponding IAudioOutputAdapterListener interface to
 *  retrieve the information when an audio package was played out by the adapter. The general procedure is
 *  described in the following:
 *
 *  1) The user provides the specific adapter implementation via one of the following options to the
 *  AudioOutput audio module:
 *
 *  1.1) The user creates an instance of the specific adapter implementation and passes it to the AudioOutput
 *  module at creation time. After the AudioOutput module was destroyed the user also has to destroy the corresponding
 *  adapter instance.
 *
 *  1.2) The user registers a specific adapter factory at the AudioManager and configures the identifier
 *  of this factory as adapter type in the AudioOutput module .json configuration. The AudioOutput module
 *  uses then the provided adapter factory to create and destroy an instance of this specific adapter.
 *
 *  2) With a call to IAudioOutputAdapter::configure() an adapter instance is configured right after its creation
 *  and in case a configuration has changed dynamically, right before calling IAudioOutputAdapter::open(). The
 *  configuration of an adapter (e.g. audio format, etc.) is set in the configuration of the AudioOutput module.
 *  It is also possible to set adapter specific configuration parameters (e.g. device name, pipe name, etc.) that
 *  are passed as a configuration string in json format to the specific adapter.
 *
 *  3) With a call to the IAudioOutputAdapter::open() the audio data sink represented by the adapter is opened
 *  with the parameters via the last IAudioOutputAdapter::configure(). Depending on the AudioOutput module's
 *  json configuration, the open is called when the module becomes connected or whenever an audio stream is
 *  started (e.g. with each begin of stream indication of a prompt). Whereas the latter option is used only to
 *  enable alternating playback and capturing when an adapter representing a half-duplex audio device is used.
 *
 *  4) A playback session is started with the first call to the IAudioOutputAdapter::write() method, followed by
 *  subsequent write() calls and ending with a call to IAudioOutputAdapter::endOfData() resp. IAudioOutputAdapter::
 *  abort(). Each audio packet written to the adapter is confirmed to the AudioOuput module as soon as it is
 *  played out resp. when the playback process is aborted.
 *
 *  5) With a call to the IAudioOutputAdapter::close() the audio data sink represented by the adapter is closed.
 *  Depending on the AudioOutput module's .json configuration, this happens either when the module becomes
 *  disconnected or whenever an audio stream is finished (e.g. with each end of stream indication of a prompt).
 *  Whereas the latter option is used only to enable alternating playback and capturing when an adapter representing
 *  a half-duplex audio device is used.
 *
 *  The audio data delivered by the audio adapter have to be 8bit encoded or 16bit little endian PCM in the format
 *  determined by the parameter given to the IAudioOutputAdapter::configure() method (interleavedFormat, channelCount,
 *  sampleRate, samplesPerChannel, audioDataType).
 */

#ifndef NUANCE_AUDIO_IAUDIOOUTPUTADAPTER_H
#define NUANCE_AUDIO_IAUDIOOUTPUTADAPTER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Audio output adapter interface. <p>
 *
 *  The implementation of this interface is responsible to realize the adaptation of the SDK's audio framework
 *  to a specific audio data sink (e.g. audio device, pipe, ..) used in a project.
 *
 *  The adapter implementation is used by the AudioOutput audio module to play back audio data via a
 *  specific audio data sink. Therefor the AudioOutput module uses the IAudioOutputAdapter interface to
 *  control the audio data sink and implements the corresponding IAudioOutputAdapterListener interface to
 *  retrieve the information when an audio package was played out by the adapter. The general procedure is
 *  described in the following:
 *
 *  1) The user provides the specific adapter implementation via one of the following options to the
 *  AudioOutput audio module:
 *
 *  1.1) The user creates an instance of the specific adapter implementation and passes it to the AudioOutput
 *  module at creation time. After the AudioOutput module was destroyed the user also has to destroy the corresponding
 *  adapter instance.
 *
 *  1.2) The user registers a specific adapter factory at the AudioManager and configures the identifier
 *  of this factory as adapter type in the AudioOutput module .json configuration. The AudioOutput module
 *  uses then the provided adapter factory to create and destroy an instance of this specific adapter.
 *
 *  2) With a call to IAudioOutputAdapter::configure() an adapter instance is configured right after its creation
 *  and in case a configuration has changed dynamically, right before calling IAudioOutputAdapter::open(). The
 *  configuration of an adapter (e.g. audio format, etc.) is set in the configuration of the AudioOutput module.
 *  It is also possible to set adapter specific configuration parameters (e.g. device name, pipe name, etc.) that
 *  are passed as a configuration string in json format to the specific adapter.
 *
 *  3) With a call to the IAudioOutputAdapter::open() the audio data sink represented by the adapter is opened
 *  with the parameters via the last IAudioOutputAdapter::configure(). Depending on the AudioOutput module's
 *  json configuration, the open is called when the module becomes connected or whenever an audio stream is
 *  started (e.g. with each begin of stream indication of a prompt). Whereas the latter option is used only to
 *  enable alternating playback and capturing when an adapter representing a half-duplex audio device is used.
 *
 *  4) A playback session is started with the first call to the IAudioOutputAdapter::write() method, followed by
 *  subsequent write() calls and ending with a call to IAudioOutputAdapter::endOfData() resp. IAudioOutputAdapter::
 *  abort(). Each audio packet written to the adapter is confirmed to the AudioOuput module as soon as it is
 *  played out resp. when the playback process is aborted.
 *
 *  5) With a call to the IAudioOutputAdapter::close() the audio data sink represented by the adapter is closed.
 *  Depending on the AudioOutput module's .json configuration, this happens either when the module becomes
 *  disconnected or whenever an audio stream is finished (e.g. with each end of stream indication of a prompt).
 *  Whereas the latter option is used only to enable alternating playback and capturing when an adapter representing
 *  a half-duplex audio device is used.
 *
 *  The audio data delivered by the audio adapter have to be 8bit encoded or 16bit little endian PCM in the format
 *  determined by the parameter given to the IAudioOutputAdapter::configure() method (interleavedFormat, channelCount,
 *  sampleRate, samplesPerChannel, audioDataType).
 */
struct _nuance_audio_IAudioOutputAdapter;
/**
 *  @brief  Audio output adapter interface. <p>
 *
 *  The implementation of this interface is responsible to realize the adaptation of the SDK's audio framework
 *  to a specific audio data sink (e.g. audio device, pipe, ..) used in a project.
 *
 *  The adapter implementation is used by the AudioOutput audio module to play back audio data via a
 *  specific audio data sink. Therefor the AudioOutput module uses the IAudioOutputAdapter interface to
 *  control the audio data sink and implements the corresponding IAudioOutputAdapterListener interface to
 *  retrieve the information when an audio package was played out by the adapter. The general procedure is
 *  described in the following:
 *
 *  1) The user provides the specific adapter implementation via one of the following options to the
 *  AudioOutput audio module:
 *
 *  1.1) The user creates an instance of the specific adapter implementation and passes it to the AudioOutput
 *  module at creation time. After the AudioOutput module was destroyed the user also has to destroy the corresponding
 *  adapter instance.
 *
 *  1.2) The user registers a specific adapter factory at the AudioManager and configures the identifier
 *  of this factory as adapter type in the AudioOutput module .json configuration. The AudioOutput module
 *  uses then the provided adapter factory to create and destroy an instance of this specific adapter.
 *
 *  2) With a call to IAudioOutputAdapter::configure() an adapter instance is configured right after its creation
 *  and in case a configuration has changed dynamically, right before calling IAudioOutputAdapter::open(). The
 *  configuration of an adapter (e.g. audio format, etc.) is set in the configuration of the AudioOutput module.
 *  It is also possible to set adapter specific configuration parameters (e.g. device name, pipe name, etc.) that
 *  are passed as a configuration string in json format to the specific adapter.
 *
 *  3) With a call to the IAudioOutputAdapter::open() the audio data sink represented by the adapter is opened
 *  with the parameters via the last IAudioOutputAdapter::configure(). Depending on the AudioOutput module's
 *  json configuration, the open is called when the module becomes connected or whenever an audio stream is
 *  started (e.g. with each begin of stream indication of a prompt). Whereas the latter option is used only to
 *  enable alternating playback and capturing when an adapter representing a half-duplex audio device is used.
 *
 *  4) A playback session is started with the first call to the IAudioOutputAdapter::write() method, followed by
 *  subsequent write() calls and ending with a call to IAudioOutputAdapter::endOfData() resp. IAudioOutputAdapter::
 *  abort(). Each audio packet written to the adapter is confirmed to the AudioOuput module as soon as it is
 *  played out resp. when the playback process is aborted.
 *
 *  5) With a call to the IAudioOutputAdapter::close() the audio data sink represented by the adapter is closed.
 *  Depending on the AudioOutput module's .json configuration, this happens either when the module becomes
 *  disconnected or whenever an audio stream is finished (e.g. with each end of stream indication of a prompt).
 *  Whereas the latter option is used only to enable alternating playback and capturing when an adapter representing
 *  a half-duplex audio device is used.
 *
 *  The audio data delivered by the audio adapter have to be 8bit encoded or 16bit little endian PCM in the format
 *  determined by the parameter given to the IAudioOutputAdapter::configure() method (interleavedFormat, channelCount,
 *  sampleRate, samplesPerChannel, audioDataType).
 */
typedef struct _nuance_audio_IAudioOutputAdapter nuance_audio_IAudioOutputAdapter;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "AudioData.h"
#include "AudioData_8Bit.h"
#include "IAudioOutputAdapterListener.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief  Configures the audio output adapter. <p>
 *
 *  This method configures the adapter with:
 *
 *  - a listener to confirm each played out resp. aborted audio packet to the SDK's audio framework
 *  - an adapter specific configuration string parameter in json format
 *  - the audio format and buffer count the adapter shall be opened with
 *
 *  This method is called right after an adapter is created and in case a configuration has changed dynamically,
 *  right before an adapter open call.
 *
 *  This method may be only called in closed state of the adapter, otherwise an error has to be returned. Also in
 *  case a given configuration is not supported an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance            The instance pointer
 *  @param[in]     listener            Listener of this audio output adapter object.
 *  @param[in]     adapterParams       Adapter specific configuration parameter json string.
 *  @param[in]     interleavedFormat   Flag indicating whether audio data shall be in interleaved or non-interleaved format.
 *  @param[in]     channelCount        Channel count.
 *  @param[in]     sampleRate          Sample rate in hertz.
 *  @param[in]     samplesPerChannel   Number of samples per channel.
 *  @param[in]     bufferCount         Number of audio buffers.
 *  @param[in]     audioDataType       Type of the audio data shall be 8bit encoded or 16bit PCM.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioOutputAdapter_configure)
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

/**
 *  @brief  Opens the audio output adapter. <p>
 *
 *  This method opens the audio data sink (e.g. audio device) represented by the audio output adapter with the
 *  configuration that was given to the last call of the configure() method.
 *
 *  This method may be only called in closed state of the adapter, otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioOutputAdapter_open)(void *instance);

/**
 *  @brief  Writes audio data for playback to the audio output adapter. <p>
 *
 *  PLEASE NOTE that it is a severe requirement to implement this function in a non-blocking and short-running
 *  manner. It is not allowed to perform any time consuming actions like for instance writing the audio data to
 *  a file system or calling a blocking write function of an audio device driver in this context. This means,
 *  that the processing of the audio data must be decoupled to not block the caller of this function. This can
 *  be reached by enqueuing the given audio packet to a playback buffer queue on which another thread context
 *  performs the processing. Thereby the playback queue must be able to hold at maximum bufferCount audio packets,
 *  each with a maximum sample size of channelCount multiplied with the samplesPerChannel value. In case the maximum
 *  number of audio packets resp. the maximum audio packet size exceeds, this method may not block but has to return
 *  an error.
 *
 *  The audio format of the audio data is determined by the configured audio format.
 *  This method is called only if the audioDataType is PCM16, then the SDK's audio framework provides audio data
 *  in 16 bit little endian PCM format.
 *
 *  Mandatorily each audio data package given to this method has to be confirmed with calling the
 *  IAudioOutputAdapterListener::onAudioDataPlayed() as soon as the package is played out resp. when the playback
 *  is aborted. Thereby the order of confirmations has to correspond the order the audio packages were written to
 *  the adapter. The confirmation mechanism is used by the AudioOutput module to implement a flow control to
 *  not exceed the playback buffer queue of the adapter.
 *
 *  Each given audio package is valid until it is confirmed to the AudioOutput module and thus should not be
 *  copied without a need.
 *
 *  This method may be only called in opened state of the adapter, otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     audioData   AudioData object containing audio data for playback.
 *  @param[in]     naudioData  Number of elements in audioData
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioOutputAdapter_write)
(
    void *instance,
    LH_S16  const *audioData, LH_S32 naudioData
);

/**
 *  @brief  Writes audio data for playback to the audio output adapter. <p>
 *
 *  PLEASE NOTE that it is a severe requirement to implement this function in a non-blocking and short-running
 *  manner. It is not allowed to perform any time consuming actions like for instance writing the audio data to
 *  a file system or calling a blocking write function of an audio device driver in this context. This means,
 *  that the processing of the audio data must be decoupled to not block the caller of this function. This can
 *  be reached by enqueuing the given audio packet to a playback buffer queue on which another thread context
 *  performs the processing. Thereby the playback queue must be able to hold at maximum bufferCount audio packets,
 *  each with a maximum sample size of channelCount multiplied with the samplesPerChannel value. In case the maximum
 *  number of audio packets resp. the maximum audio packet size exceeds, this method may not block but has to return
 *  an error.
 *
 *  The audio format of the audio data is determined by the configured audio format.
 *  This method is called only if the audioDataType is not PCM16.
 *
 *  Mandatorily each audio data package given to this method has to be confirmed with calling the
 *  IAudioOutputAdapterListener::onAudioDataPlayed() as soon as the package is played out resp. when the playback
 *  is aborted. Thereby the order of confirmations has to correspond the order the audio packages were written to
 *  the adapter. The confirmation mechanism is used by the AudioOutput module to implement a flow control to
 *  not exceed the playback buffer queue of the adapter.
 *
 *  Each given audio package is valid until it is confirmed to the AudioOutput module and thus should not be
 *  copied without a need.
 *
 *  This method may be only called in opened state of the adapter, otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     audioData   AudioData object containing audio data for playback.
 *  @param[in]     naudioData  Number of elements in audioData
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioOutputAdapter_writeEncoded)
(
    void *instance,
    LH_S8  const *audioData, LH_S32 naudioData
);

/**
 *  @brief  Indicates the end of stream to the audio output adapter. <p>
 *
 *  This method is called after writing the last audio data of an audio stream to the audio output adapter. This
 *  means that all enqueued audio data packages have to be played out and confirmed at the AudioOutput module
 *  with calling the IAudioOutputAdapterListener::onAudioDataPlayed().
 *
 *  PLEASE NOTE that it is a severe requirement to implement this function in a non-blocking and short-running
 *  manner. It is not allowed to perform any time consuming actions like for instance waiting until all enqueued
 *  audio packets are played out.
 *
 *  This method may be only called after at least one audio packet was written to the audio output adapter,
 *  otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioOutputAdapter_endOfStream)(void *instance);

/**
 *  @brief  Aborts the playback of the audio output adapter. <p>
 *
 *  Within this method a running playback session must be stopped immediately at the represented audio data sink
 *  (e.g. audio output device). The playback buffer of the audio output device has to be cleared and all audio
 *  packets handed so far to the adapter must be confirmed at the AudioOutput module with calling the
 *  IAudioOutputAdapterListener::onAudioDataPlayed() before this method returns.
 *
 *  This method may be called in any state. In case currently no playback is running or the playback is already
 *  finished the method may not return an error.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioOutputAdapter_abort)(void *instance);

/**
 *  @brief  Closes the audio output adapter. <p>
 *
 *  This method closes the audio data sink (e.g. audio device) represented by the audio output adapter
 *
 *  This method may be only called in opened state of the adapter, otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioOutputAdapter_close)(void *instance);

/**
 *  @brief  Returns a textual description of the last audio output adapter error. <p>
 *
 *  If applicable the error description of the audio data sink represented by the adapter (e.g. audio device)
 *  shall be returned.
 *
 *  In case no last error is available an empty string shall be returned.
 *
 *  It is allowed to call this method in context of the IAudioOutputAdapterListener::onAudioDataPlayed() method.
 *
 *  This method may be called in any state of the adapter.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_String *(*FUNC_nuance_audio_IAudioOutputAdapter_getErrorText)(const void *instance);

/**
 *  @brief  Destroys this audio output adapter instance. <p>
 *
 *  This method is called in context of the destructor of the AudioOutput module and indicates that this audio
 *  output adapter instance is no longer required. In case this adapter instance was created via the adapter factory
 *  approach it has to be deleted in this context. In case the user has created this instance and passed it to the
 *  AudioOutput module as parameter at creation time, it may be deleted either directly in this context or by the
 *  user after the corresponding AudioOutput instance was destroyed. In the latter case this method can be implemented
 *  empty.
 *
 *  This method may be only called in closed state of the adapter, otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 */
typedef void (*FUNC_nuance_audio_IAudioOutputAdapter_destroyAdapter)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Audio output adapter interface. <p>
 *
 *  The implementation of this interface is responsible to realize the adaptation of the SDK's audio framework
 *  to a specific audio data sink (e.g. audio device, pipe, ..) used in a project.
 *
 *  The adapter implementation is used by the AudioOutput audio module to play back audio data via a
 *  specific audio data sink. Therefor the AudioOutput module uses the IAudioOutputAdapter interface to
 *  control the audio data sink and implements the corresponding IAudioOutputAdapterListener interface to
 *  retrieve the information when an audio package was played out by the adapter. The general procedure is
 *  described in the following:
 *
 *  1) The user provides the specific adapter implementation via one of the following options to the
 *  AudioOutput audio module:
 *
 *  1.1) The user creates an instance of the specific adapter implementation and passes it to the AudioOutput
 *  module at creation time. After the AudioOutput module was destroyed the user also has to destroy the corresponding
 *  adapter instance.
 *
 *  1.2) The user registers a specific adapter factory at the AudioManager and configures the identifier
 *  of this factory as adapter type in the AudioOutput module .json configuration. The AudioOutput module
 *  uses then the provided adapter factory to create and destroy an instance of this specific adapter.
 *
 *  2) With a call to IAudioOutputAdapter::configure() an adapter instance is configured right after its creation
 *  and in case a configuration has changed dynamically, right before calling IAudioOutputAdapter::open(). The
 *  configuration of an adapter (e.g. audio format, etc.) is set in the configuration of the AudioOutput module.
 *  It is also possible to set adapter specific configuration parameters (e.g. device name, pipe name, etc.) that
 *  are passed as a configuration string in json format to the specific adapter.
 *
 *  3) With a call to the IAudioOutputAdapter::open() the audio data sink represented by the adapter is opened
 *  with the parameters via the last IAudioOutputAdapter::configure(). Depending on the AudioOutput module's
 *  json configuration, the open is called when the module becomes connected or whenever an audio stream is
 *  started (e.g. with each begin of stream indication of a prompt). Whereas the latter option is used only to
 *  enable alternating playback and capturing when an adapter representing a half-duplex audio device is used.
 *
 *  4) A playback session is started with the first call to the IAudioOutputAdapter::write() method, followed by
 *  subsequent write() calls and ending with a call to IAudioOutputAdapter::endOfData() resp. IAudioOutputAdapter::
 *  abort(). Each audio packet written to the adapter is confirmed to the AudioOuput module as soon as it is
 *  played out resp. when the playback process is aborted.
 *
 *  5) With a call to the IAudioOutputAdapter::close() the audio data sink represented by the adapter is closed.
 *  Depending on the AudioOutput module's .json configuration, this happens either when the module becomes
 *  disconnected or whenever an audio stream is finished (e.g. with each end of stream indication of a prompt).
 *  Whereas the latter option is used only to enable alternating playback and capturing when an adapter representing
 *  a half-duplex audio device is used.
 *
 *  The audio data delivered by the audio adapter have to be 8bit encoded or 16bit little endian PCM in the format
 *  determined by the parameter given to the IAudioOutputAdapter::configure() method (interleavedFormat, channelCount,
 *  sampleRate, samplesPerChannel, audioDataType).
 */
struct _vtable_nuance_audio_IAudioOutputAdapter
{
    /**
     *  @brief  Configures the audio output adapter. <p>
     *
     *  This method configures the adapter with:
     *
     *  - a listener to confirm each played out resp. aborted audio packet to the SDK's audio framework
     *  - an adapter specific configuration string parameter in json format
     *  - the audio format and buffer count the adapter shall be opened with
     *
     *  This method is called right after an adapter is created and in case a configuration has changed dynamically,
     *  right before an adapter open call.
     *
     *  This method may be only called in closed state of the adapter, otherwise an error has to be returned. Also in
     *  case a given configuration is not supported an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance            The instance pointer
     *  @param[in]     listener            Listener of this audio output adapter object.
     *  @param[in]     adapterParams       Adapter specific configuration parameter json string.
     *  @param[in]     interleavedFormat   Flag indicating whether audio data shall be in interleaved or non-interleaved format.
     *  @param[in]     channelCount        Channel count.
     *  @param[in]     sampleRate          Sample rate in hertz.
     *  @param[in]     samplesPerChannel   Number of samples per channel.
     *  @param[in]     bufferCount         Number of audio buffers.
     *  @param[in]     audioDataType       Type of the audio data shall be 8bit encoded or 16bit PCM.
     *
     */
    FUNC_nuance_audio_IAudioOutputAdapter_configure configure;

    /**
     *  @brief  Opens the audio output adapter. <p>
     *
     *  This method opens the audio data sink (e.g. audio device) represented by the audio output adapter with the
     *  configuration that was given to the last call of the configure() method.
     *
     *  This method may be only called in closed state of the adapter, otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IAudioOutputAdapter_open open;

    /**
     *  @brief  Writes audio data for playback to the audio output adapter. <p>
     *
     *  PLEASE NOTE that it is a severe requirement to implement this function in a non-blocking and short-running
     *  manner. It is not allowed to perform any time consuming actions like for instance writing the audio data to
     *  a file system or calling a blocking write function of an audio device driver in this context. This means,
     *  that the processing of the audio data must be decoupled to not block the caller of this function. This can
     *  be reached by enqueuing the given audio packet to a playback buffer queue on which another thread context
     *  performs the processing. Thereby the playback queue must be able to hold at maximum bufferCount audio packets,
     *  each with a maximum sample size of channelCount multiplied with the samplesPerChannel value. In case the maximum
     *  number of audio packets resp. the maximum audio packet size exceeds, this method may not block but has to return
     *  an error.
     *
     *  The audio format of the audio data is determined by the configured audio format.
     *  This method is called only if the audioDataType is PCM16, then the SDK's audio framework provides audio data
     *  in 16 bit little endian PCM format.
     *
     *  Mandatorily each audio data package given to this method has to be confirmed with calling the
     *  IAudioOutputAdapterListener::onAudioDataPlayed() as soon as the package is played out resp. when the playback
     *  is aborted. Thereby the order of confirmations has to correspond the order the audio packages were written to
     *  the adapter. The confirmation mechanism is used by the AudioOutput module to implement a flow control to
     *  not exceed the playback buffer queue of the adapter.
     *
     *  Each given audio package is valid until it is confirmed to the AudioOutput module and thus should not be
     *  copied without a need.
     *
     *  This method may be only called in opened state of the adapter, otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     audioData   AudioData object containing audio data for playback.
     *  @param[in]     naudioData  Number of elements in audioData
     *
     */
    FUNC_nuance_audio_IAudioOutputAdapter_write write;

    /**
     *  @brief  Writes audio data for playback to the audio output adapter. <p>
     *
     *  PLEASE NOTE that it is a severe requirement to implement this function in a non-blocking and short-running
     *  manner. It is not allowed to perform any time consuming actions like for instance writing the audio data to
     *  a file system or calling a blocking write function of an audio device driver in this context. This means,
     *  that the processing of the audio data must be decoupled to not block the caller of this function. This can
     *  be reached by enqueuing the given audio packet to a playback buffer queue on which another thread context
     *  performs the processing. Thereby the playback queue must be able to hold at maximum bufferCount audio packets,
     *  each with a maximum sample size of channelCount multiplied with the samplesPerChannel value. In case the maximum
     *  number of audio packets resp. the maximum audio packet size exceeds, this method may not block but has to return
     *  an error.
     *
     *  The audio format of the audio data is determined by the configured audio format.
     *  This method is called only if the audioDataType is not PCM16.
     *
     *  Mandatorily each audio data package given to this method has to be confirmed with calling the
     *  IAudioOutputAdapterListener::onAudioDataPlayed() as soon as the package is played out resp. when the playback
     *  is aborted. Thereby the order of confirmations has to correspond the order the audio packages were written to
     *  the adapter. The confirmation mechanism is used by the AudioOutput module to implement a flow control to
     *  not exceed the playback buffer queue of the adapter.
     *
     *  Each given audio package is valid until it is confirmed to the AudioOutput module and thus should not be
     *  copied without a need.
     *
     *  This method may be only called in opened state of the adapter, otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     audioData   AudioData object containing audio data for playback.
     *  @param[in]     naudioData  Number of elements in audioData
     *
     */
    FUNC_nuance_audio_IAudioOutputAdapter_writeEncoded writeEncoded;

    /**
     *  @brief  Indicates the end of stream to the audio output adapter. <p>
     *
     *  This method is called after writing the last audio data of an audio stream to the audio output adapter. This
     *  means that all enqueued audio data packages have to be played out and confirmed at the AudioOutput module
     *  with calling the IAudioOutputAdapterListener::onAudioDataPlayed().
     *
     *  PLEASE NOTE that it is a severe requirement to implement this function in a non-blocking and short-running
     *  manner. It is not allowed to perform any time consuming actions like for instance waiting until all enqueued
     *  audio packets are played out.
     *
     *  This method may be only called after at least one audio packet was written to the audio output adapter,
     *  otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IAudioOutputAdapter_endOfStream endOfStream;

    /**
     *  @brief  Aborts the playback of the audio output adapter. <p>
     *
     *  Within this method a running playback session must be stopped immediately at the represented audio data sink
     *  (e.g. audio output device). The playback buffer of the audio output device has to be cleared and all audio
     *  packets handed so far to the adapter must be confirmed at the AudioOutput module with calling the
     *  IAudioOutputAdapterListener::onAudioDataPlayed() before this method returns.
     *
     *  This method may be called in any state. In case currently no playback is running or the playback is already
     *  finished the method may not return an error.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IAudioOutputAdapter_abort abort;

    /**
     *  @brief  Closes the audio output adapter. <p>
     *
     *  This method closes the audio data sink (e.g. audio device) represented by the audio output adapter
     *
     *  This method may be only called in opened state of the adapter, otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IAudioOutputAdapter_close close;

    /**
     *  @brief  Returns a textual description of the last audio output adapter error. <p>
     *
     *  If applicable the error description of the audio data sink represented by the adapter (e.g. audio device)
     *  shall be returned.
     *
     *  In case no last error is available an empty string shall be returned.
     *
     *  It is allowed to call this method in context of the IAudioOutputAdapterListener::onAudioDataPlayed() method.
     *
     *  This method may be called in any state of the adapter.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IAudioOutputAdapter_getErrorText getErrorText;

    /**
     *  @brief  Destroys this audio output adapter instance. <p>
     *
     *  This method is called in context of the destructor of the AudioOutput module and indicates that this audio
     *  output adapter instance is no longer required. In case this adapter instance was created via the adapter factory
     *  approach it has to be deleted in this context. In case the user has created this instance and passed it to the
     *  AudioOutput module as parameter at creation time, it may be deleted either directly in this context or by the
     *  user after the corresponding AudioOutput instance was destroyed. In the latter case this method can be implemented
     *  empty.
     *
     *  This method may be only called in closed state of the adapter, otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     */
    FUNC_nuance_audio_IAudioOutputAdapter_destroyAdapter destroyAdapter;

};
/**
 *  @brief  Audio output adapter interface. <p>
 *
 *  The implementation of this interface is responsible to realize the adaptation of the SDK's audio framework
 *  to a specific audio data sink (e.g. audio device, pipe, ..) used in a project.
 *
 *  The adapter implementation is used by the AudioOutput audio module to play back audio data via a
 *  specific audio data sink. Therefor the AudioOutput module uses the IAudioOutputAdapter interface to
 *  control the audio data sink and implements the corresponding IAudioOutputAdapterListener interface to
 *  retrieve the information when an audio package was played out by the adapter. The general procedure is
 *  described in the following:
 *
 *  1) The user provides the specific adapter implementation via one of the following options to the
 *  AudioOutput audio module:
 *
 *  1.1) The user creates an instance of the specific adapter implementation and passes it to the AudioOutput
 *  module at creation time. After the AudioOutput module was destroyed the user also has to destroy the corresponding
 *  adapter instance.
 *
 *  1.2) The user registers a specific adapter factory at the AudioManager and configures the identifier
 *  of this factory as adapter type in the AudioOutput module .json configuration. The AudioOutput module
 *  uses then the provided adapter factory to create and destroy an instance of this specific adapter.
 *
 *  2) With a call to IAudioOutputAdapter::configure() an adapter instance is configured right after its creation
 *  and in case a configuration has changed dynamically, right before calling IAudioOutputAdapter::open(). The
 *  configuration of an adapter (e.g. audio format, etc.) is set in the configuration of the AudioOutput module.
 *  It is also possible to set adapter specific configuration parameters (e.g. device name, pipe name, etc.) that
 *  are passed as a configuration string in json format to the specific adapter.
 *
 *  3) With a call to the IAudioOutputAdapter::open() the audio data sink represented by the adapter is opened
 *  with the parameters via the last IAudioOutputAdapter::configure(). Depending on the AudioOutput module's
 *  json configuration, the open is called when the module becomes connected or whenever an audio stream is
 *  started (e.g. with each begin of stream indication of a prompt). Whereas the latter option is used only to
 *  enable alternating playback and capturing when an adapter representing a half-duplex audio device is used.
 *
 *  4) A playback session is started with the first call to the IAudioOutputAdapter::write() method, followed by
 *  subsequent write() calls and ending with a call to IAudioOutputAdapter::endOfData() resp. IAudioOutputAdapter::
 *  abort(). Each audio packet written to the adapter is confirmed to the AudioOuput module as soon as it is
 *  played out resp. when the playback process is aborted.
 *
 *  5) With a call to the IAudioOutputAdapter::close() the audio data sink represented by the adapter is closed.
 *  Depending on the AudioOutput module's .json configuration, this happens either when the module becomes
 *  disconnected or whenever an audio stream is finished (e.g. with each end of stream indication of a prompt).
 *  Whereas the latter option is used only to enable alternating playback and capturing when an adapter representing
 *  a half-duplex audio device is used.
 *
 *  The audio data delivered by the audio adapter have to be 8bit encoded or 16bit little endian PCM in the format
 *  determined by the parameter given to the IAudioOutputAdapter::configure() method (interleavedFormat, channelCount,
 *  sampleRate, samplesPerChannel, audioDataType).
 */
typedef struct _vtable_nuance_audio_IAudioOutputAdapter vtable_nuance_audio_IAudioOutputAdapter;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IAudioOutputAdapter *nuance_audio_IAudioOutputAdapter_create
(
    const vtable_nuance_audio_IAudioOutputAdapter *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IAudioOutputAdapter_destroy(nuance_audio_IAudioOutputAdapter *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOOUTPUTADAPTER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
