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
 *  Declaration of nuance_audio_IAudioInputAdapter class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioInputAdapter
 *  @{
 *  @file IAudioInputAdapter.h
 *
 *  @brief  Audio input adapter interface. <p>
 *
 *  The implementation of this interface is responsible to realize the adaptation of the SDK's audio framework
 *  to a specific audio data source (e.g. audio device, pipe, ..) used in a project.
 *
 *  The adapter implementation is used by the AudioInput audio module to capture audio data from a specific
 *  audio data source to the audio framework of the SDK. Therefor the AudioInput uses the IAudioInputAdapter
 *  interface to control the audio data source and implements the corresponding IAudioInputAdapterListener
 *  interface to retrieve the captured audio data from the adapter. The general procedure is described in
 *  the following:
 *
 *  1) The user provides the specific adapter implementation via one of the following options to the
 *  AudioInput audio module:
 *
 *  1.1) The user creates an instance of the specific adapter implementation and passes it to the AudioInput
 *  module at creation time. After the AudioInput module was destroyed the user also has to destroy the corresponding
 *  adapter instance.
 *
 *  1.2) The user registers a specific adapter factory at the AudioManager and configures the identifier
 *  of this factory as adapter type in the AudioInput module .json configuration. The AudioInput module
 *  uses then the provided adapter factory to create and destroy an instance of this specific adapter.
 *
 *  2) With a call to IAudioInputAdapter::configure() an adapter instance is configured right after its creation
 *  and in case a configuration has changed dynamically, right before calling IAudioInputAdapter::open(). The
 *  configuration of an adapter (e.g. audio format, etc.) is set in the configuration of the AudioInput module.
 *  It is also possible to set adapter specific configuration parameters (e.g. device name, pipe name, etc.) that
 *  are passed as a configuration string in json format to the specific adapter.
 *
 *  3) With a call to the IAudioInputAdapter::open() the audio data source represented by the adapter is opened
 *  with the parameters configured via the last IAudioInputAdapter::configure(). Depending on the AudioInput module's
 *  json configuration, the open is called either when the module becomes connected or whenever a new audio session
 *  is started (e.g. when the recognizer is started). Whereas the latter option should be used only to enable alternating
 *  playback and capturing when an adapter representing a half-duplex audio device is used.
 *
 *  4) A capturing session is started at the adapter with a call to the IAudioInputAdapter::start() method. This
 *  is done by the AudioInput module whenever a new audio session is started (e.g. when the recognizer is started).
 *  From now on each captured audio packet in the configured audio format is announced by the adapter
 *  to the AudioInput module with a call to its IAudioInputAdapterListener::onAudioDataCaptured() method.
 *
 *  5)  In case the adapter does not represent a real audio device, a flow control mechanism has to be implemented by
 *  the adapter. Each announcement of a captured audio packet via a call to IAudioInputAdapterListener::onAudioDataCaptured()
 *  returns the current flow state of audio framework. In case this state corresponds to WILL_DROP, which means, that the next
 *  audio packet would be dropped, the adapter has to pause the announcement of new audio packets until
 *  IAudioInputAdapterListener::resume() is called. PLEASE BE AWARE that due to the scheduler it may be that the resume()
 *  is called before the adapter has evaluated that the onAudioDataCaptured() has returned flow state WILL_DROP. For that
 *  reason the flow control should be realized in the adapter by usage of a semaphore like shown in following example
 *  pseudo code:
 *
 *  start():
 *  - create resume sema (to guarantee that resume sema has the correct state with each started session)
 *  stop():
 *  - signal resume sema to unblock capturing thread that potentially waits on blocked resume sema
 *  - destroy resume sema
 *  resume():
 *  - signal resume semaphore to unblock capturing thread
 *  capturing thread function():
 *  - if onAudioDataCaptured() returned flow state WILL_DROP wait on resume semaphore
 *
 *  In case the adapter accesses a real audio device a flow control mechanism should not be implemented, as pausing
 *  a real audio device is neither intended nor necessary. So the IAudioInputAdapterListener::resume() method has to
 *  return OK immediately.
 *
 *  6) A capturing session is stopped at the adapter with a call to the IAudioInputAdapter::stop() method. This is
 *  done by the AudioInput module whenever an audio session is stopped (e.g. when the recognizer is stopped).
 *  As of now it is no longer allowed to call the IAudioInputAdapterListener::onAudioDataCaptured() method. Hereinafter,
 *  either a capturing session is started anew (see 4.) or the adapter is closed (see 7.).
 *
 *  7) With a call to the IAudioInputAdapter::close() the audio data source represented by the adapter is closed.
 *  Depending on the AudioInput module's .json configuration, this happens either when the module becomes
 *  disconnected or whenever an audio session is stopped (e.g. when the recognizer is stopped). Whereas
 *  the latter option should be used only to enable alternating playback and capturing when an adapter representing a
 *  half-duplex audio device is used.
 *
 *  The audio data delivered by the audio adapter have to be 16bit little endian PCM in the format determined by
 *  the parameter given to the IAudioInputAdapter::configure() method (interleavedFormat, channelCount, sampleRate,
 *  samplesPerChannel).
 */

#ifndef NUANCE_AUDIO_IAUDIOINPUTADAPTER_H
#define NUANCE_AUDIO_IAUDIOINPUTADAPTER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Audio input adapter interface. <p>
 *
 *  The implementation of this interface is responsible to realize the adaptation of the SDK's audio framework
 *  to a specific audio data source (e.g. audio device, pipe, ..) used in a project.
 *
 *  The adapter implementation is used by the AudioInput audio module to capture audio data from a specific
 *  audio data source to the audio framework of the SDK. Therefor the AudioInput uses the IAudioInputAdapter
 *  interface to control the audio data source and implements the corresponding IAudioInputAdapterListener
 *  interface to retrieve the captured audio data from the adapter. The general procedure is described in
 *  the following:
 *
 *  1) The user provides the specific adapter implementation via one of the following options to the
 *  AudioInput audio module:
 *
 *  1.1) The user creates an instance of the specific adapter implementation and passes it to the AudioInput
 *  module at creation time. After the AudioInput module was destroyed the user also has to destroy the corresponding
 *  adapter instance.
 *
 *  1.2) The user registers a specific adapter factory at the AudioManager and configures the identifier
 *  of this factory as adapter type in the AudioInput module .json configuration. The AudioInput module
 *  uses then the provided adapter factory to create and destroy an instance of this specific adapter.
 *
 *  2) With a call to IAudioInputAdapter::configure() an adapter instance is configured right after its creation
 *  and in case a configuration has changed dynamically, right before calling IAudioInputAdapter::open(). The
 *  configuration of an adapter (e.g. audio format, etc.) is set in the configuration of the AudioInput module.
 *  It is also possible to set adapter specific configuration parameters (e.g. device name, pipe name, etc.) that
 *  are passed as a configuration string in json format to the specific adapter.
 *
 *  3) With a call to the IAudioInputAdapter::open() the audio data source represented by the adapter is opened
 *  with the parameters configured via the last IAudioInputAdapter::configure(). Depending on the AudioInput module's
 *  json configuration, the open is called either when the module becomes connected or whenever a new audio session
 *  is started (e.g. when the recognizer is started). Whereas the latter option should be used only to enable alternating
 *  playback and capturing when an adapter representing a half-duplex audio device is used.
 *
 *  4) A capturing session is started at the adapter with a call to the IAudioInputAdapter::start() method. This
 *  is done by the AudioInput module whenever a new audio session is started (e.g. when the recognizer is started).
 *  From now on each captured audio packet in the configured audio format is announced by the adapter
 *  to the AudioInput module with a call to its IAudioInputAdapterListener::onAudioDataCaptured() method.
 *
 *  5)  In case the adapter does not represent a real audio device, a flow control mechanism has to be implemented by
 *  the adapter. Each announcement of a captured audio packet via a call to IAudioInputAdapterListener::onAudioDataCaptured()
 *  returns the current flow state of audio framework. In case this state corresponds to WILL_DROP, which means, that the next
 *  audio packet would be dropped, the adapter has to pause the announcement of new audio packets until
 *  IAudioInputAdapterListener::resume() is called. PLEASE BE AWARE that due to the scheduler it may be that the resume()
 *  is called before the adapter has evaluated that the onAudioDataCaptured() has returned flow state WILL_DROP. For that
 *  reason the flow control should be realized in the adapter by usage of a semaphore like shown in following example
 *  pseudo code:
 *
 *  start():
 *  - create resume sema (to guarantee that resume sema has the correct state with each started session)
 *  stop():
 *  - signal resume sema to unblock capturing thread that potentially waits on blocked resume sema
 *  - destroy resume sema
 *  resume():
 *  - signal resume semaphore to unblock capturing thread
 *  capturing thread function():
 *  - if onAudioDataCaptured() returned flow state WILL_DROP wait on resume semaphore
 *
 *  In case the adapter accesses a real audio device a flow control mechanism should not be implemented, as pausing
 *  a real audio device is neither intended nor necessary. So the IAudioInputAdapterListener::resume() method has to
 *  return OK immediately.
 *
 *  6) A capturing session is stopped at the adapter with a call to the IAudioInputAdapter::stop() method. This is
 *  done by the AudioInput module whenever an audio session is stopped (e.g. when the recognizer is stopped).
 *  As of now it is no longer allowed to call the IAudioInputAdapterListener::onAudioDataCaptured() method. Hereinafter,
 *  either a capturing session is started anew (see 4.) or the adapter is closed (see 7.).
 *
 *  7) With a call to the IAudioInputAdapter::close() the audio data source represented by the adapter is closed.
 *  Depending on the AudioInput module's .json configuration, this happens either when the module becomes
 *  disconnected or whenever an audio session is stopped (e.g. when the recognizer is stopped). Whereas
 *  the latter option should be used only to enable alternating playback and capturing when an adapter representing a
 *  half-duplex audio device is used.
 *
 *  The audio data delivered by the audio adapter have to be 16bit little endian PCM in the format determined by
 *  the parameter given to the IAudioInputAdapter::configure() method (interleavedFormat, channelCount, sampleRate,
 *  samplesPerChannel).
 */
struct _nuance_audio_IAudioInputAdapter;
/**
 *  @brief  Audio input adapter interface. <p>
 *
 *  The implementation of this interface is responsible to realize the adaptation of the SDK's audio framework
 *  to a specific audio data source (e.g. audio device, pipe, ..) used in a project.
 *
 *  The adapter implementation is used by the AudioInput audio module to capture audio data from a specific
 *  audio data source to the audio framework of the SDK. Therefor the AudioInput uses the IAudioInputAdapter
 *  interface to control the audio data source and implements the corresponding IAudioInputAdapterListener
 *  interface to retrieve the captured audio data from the adapter. The general procedure is described in
 *  the following:
 *
 *  1) The user provides the specific adapter implementation via one of the following options to the
 *  AudioInput audio module:
 *
 *  1.1) The user creates an instance of the specific adapter implementation and passes it to the AudioInput
 *  module at creation time. After the AudioInput module was destroyed the user also has to destroy the corresponding
 *  adapter instance.
 *
 *  1.2) The user registers a specific adapter factory at the AudioManager and configures the identifier
 *  of this factory as adapter type in the AudioInput module .json configuration. The AudioInput module
 *  uses then the provided adapter factory to create and destroy an instance of this specific adapter.
 *
 *  2) With a call to IAudioInputAdapter::configure() an adapter instance is configured right after its creation
 *  and in case a configuration has changed dynamically, right before calling IAudioInputAdapter::open(). The
 *  configuration of an adapter (e.g. audio format, etc.) is set in the configuration of the AudioInput module.
 *  It is also possible to set adapter specific configuration parameters (e.g. device name, pipe name, etc.) that
 *  are passed as a configuration string in json format to the specific adapter.
 *
 *  3) With a call to the IAudioInputAdapter::open() the audio data source represented by the adapter is opened
 *  with the parameters configured via the last IAudioInputAdapter::configure(). Depending on the AudioInput module's
 *  json configuration, the open is called either when the module becomes connected or whenever a new audio session
 *  is started (e.g. when the recognizer is started). Whereas the latter option should be used only to enable alternating
 *  playback and capturing when an adapter representing a half-duplex audio device is used.
 *
 *  4) A capturing session is started at the adapter with a call to the IAudioInputAdapter::start() method. This
 *  is done by the AudioInput module whenever a new audio session is started (e.g. when the recognizer is started).
 *  From now on each captured audio packet in the configured audio format is announced by the adapter
 *  to the AudioInput module with a call to its IAudioInputAdapterListener::onAudioDataCaptured() method.
 *
 *  5)  In case the adapter does not represent a real audio device, a flow control mechanism has to be implemented by
 *  the adapter. Each announcement of a captured audio packet via a call to IAudioInputAdapterListener::onAudioDataCaptured()
 *  returns the current flow state of audio framework. In case this state corresponds to WILL_DROP, which means, that the next
 *  audio packet would be dropped, the adapter has to pause the announcement of new audio packets until
 *  IAudioInputAdapterListener::resume() is called. PLEASE BE AWARE that due to the scheduler it may be that the resume()
 *  is called before the adapter has evaluated that the onAudioDataCaptured() has returned flow state WILL_DROP. For that
 *  reason the flow control should be realized in the adapter by usage of a semaphore like shown in following example
 *  pseudo code:
 *
 *  start():
 *  - create resume sema (to guarantee that resume sema has the correct state with each started session)
 *  stop():
 *  - signal resume sema to unblock capturing thread that potentially waits on blocked resume sema
 *  - destroy resume sema
 *  resume():
 *  - signal resume semaphore to unblock capturing thread
 *  capturing thread function():
 *  - if onAudioDataCaptured() returned flow state WILL_DROP wait on resume semaphore
 *
 *  In case the adapter accesses a real audio device a flow control mechanism should not be implemented, as pausing
 *  a real audio device is neither intended nor necessary. So the IAudioInputAdapterListener::resume() method has to
 *  return OK immediately.
 *
 *  6) A capturing session is stopped at the adapter with a call to the IAudioInputAdapter::stop() method. This is
 *  done by the AudioInput module whenever an audio session is stopped (e.g. when the recognizer is stopped).
 *  As of now it is no longer allowed to call the IAudioInputAdapterListener::onAudioDataCaptured() method. Hereinafter,
 *  either a capturing session is started anew (see 4.) or the adapter is closed (see 7.).
 *
 *  7) With a call to the IAudioInputAdapter::close() the audio data source represented by the adapter is closed.
 *  Depending on the AudioInput module's .json configuration, this happens either when the module becomes
 *  disconnected or whenever an audio session is stopped (e.g. when the recognizer is stopped). Whereas
 *  the latter option should be used only to enable alternating playback and capturing when an adapter representing a
 *  half-duplex audio device is used.
 *
 *  The audio data delivered by the audio adapter have to be 16bit little endian PCM in the format determined by
 *  the parameter given to the IAudioInputAdapter::configure() method (interleavedFormat, channelCount, sampleRate,
 *  samplesPerChannel).
 */
typedef struct _nuance_audio_IAudioInputAdapter nuance_audio_IAudioInputAdapter;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IAudioInputAdapterListener.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief  Configures the audio input adapter. <p>
 *
 *  This method configures the adapter with:
 *
 *  - a listener to announce captured audio packets to the audio framework of the SDK
 *  - an adapter specific configuration string parameter in json format
 *  - the audio format the adapter shall be opened with
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
 *  @param[in]     listener            Listener of this audio input adapter object.
 *  @param[in]     adapterParams       Adapter specific configuration parameter json string.
 *  @param[in]     interleavedFormat   Flag indicating whether audio data shall be in interleaved or non-interleaved format.
 *  @param[in]     channelCount        Channel count.
 *  @param[in]     sampleRate          Sample rate in hertz.
 *  @param[in]     samplesPerChannel   Number of samples per channel.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioInputAdapter_configure)
(
    void *instance,
    nuance_audio_IAudioInputAdapterListener *listener,
    const LH_CHAR *adapterParams,
    LH_BOOL interleavedFormat,
    LH_S32 channelCount,
    LH_S32 sampleRate,
    LH_S32 samplesPerChannel
);

/**
 *  @brief  Opens the audio input adapter. <p>
 *
 *  This method opens the audio data source (e.g. audio device) represented by the audio input adapter with the
 *  configuration that was given to the last call of the configure() method.
 *
 *  This method may be only called in closed state of the adapter, otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioInputAdapter_open)(void *instance);

/**
 *  @brief  Starts capturing via the audio input adapter. <p>
 *
 *  Within this method a capturing session has to be started.
 *
 *  From now on each captured audio packet has to be announced in the proper audio format to the listener by calling
 *  its IAudioInputAdapterListener::onAudioDataCaptured() method. The captured audio data must be valid until the
 *  onAudioDataCaptured() method returns. Audio data of a previous capturing session must not be delivered.
 *
 *  The proper audio format of the audio packet announced is determined by the configured audio format and the fact
 *  that the SDK requires audio data in 16 bit little endian PCM format.
 *
 *  This method may be only called to an opened, but stopped adapter, otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioInputAdapter_start)(void *instance);

/**
 *  @brief  Stops capturing via the audio input adapter. <p>
 *
 *  Within this method a started capturing session has to be stopped.
 *
 *  After this method is left it is no longer allowed to announce audio data to the listener by calling its
 *  IAudioInputAdapterListener::onAudioDataCaptured() method.
 *
 *  This method may be only called in started state of the adapter, otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioInputAdapter_stop)(void *instance);

/**
 *  @brief  Resumes capturing via the audio input adapter. <p>
 *
 *  This method resumes a started capturing session that was stopped due to flow control.
 *
 *  In case the adapter does not represent a real audio device, a flow control mechanism has to be implemented by
 *  the adapter. Each announcement of a captured audio packet via a call to IAudioInputAdapterListener::onAudioDataCaptured()
 *  returns the current flow state of the audio framework. In case this state corresponds to WILL_DROP, which means, that the next
 *  audio packet would be dropped, the adapter has to pause the announcement of new audio packets until this method
 *  is called. PLEASE BE AWARE that due to the scheduler it may be that the resume() is called before the adapter has
 *  evaluated that the onAudioDataCaptured() has returned flow state WILL_DROP. For that reason the flow control should
 *  be realized in the adapter by usage of a semaphore like shown in following example pseudo code:
 *
 *  start():
 *  - create resume sema (to guarantee that resume sema has the correct state with each started session)
 *  stop():
 *  - signal resume sema to unblock capturing thread that potentially waits on blocked resume sema
 *  - destroy resume sema
 *  resume():
 *  - signal resume semaphore to unblock capturing thread
 *  capturing thread function():
 *  - if onAudioDataCaptured() returned flow state WILL_DROP wait on resume semaphore
 *
 *  In case the adapter accesses a real audio device a flow control mechanism should not be implemented, as pausing
 *  a real audio device is neither intended nor necessary. So this method has to return OK immediately.
 *
 *  This method may be only called in started state of the adapter, otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioInputAdapter_resume)(void *instance);

/**
 *  @brief  Closes the audio input adapter. <p>
 *
 *  This method closes the audio data source (e.g. audio device) represented by the audio input adapter
 *
 *  This method may be only called in opened, but stopped state of the adapter, otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_audio_IAudioInputAdapter_close)(void *instance);

/**
 *  @brief  Returns a textual description of the last audio input adapter error. <p>
 *
 *  If applicable the error description of the audio data source represented by the adapter (e.g. audio device)
 *  shall be returned.
 *
 *  In case no last error is available an empty string shall be returned.
 *
 *  It is allowed to call this method in context of the IAudioInputAdapterListener::onAudioDataCaptured() method.
 *
 *  This method may be called in any state of the adapter.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
typedef nuance_common_String *(*FUNC_nuance_audio_IAudioInputAdapter_getErrorText)(const void *instance);

/**
 *  @brief  Destroys this audio input adapter instance. <p>
 *
 *  This method is called in context of the destructor of the AudioInput module and indicates that this audio
 *  input adapter instance is no longer required. In case this adapter instance was created via the adapter factory
 *  approach it has to be deleted in this context. In case the user has created this instance and passed it to the
 *  AudioInput module as parameter at creation time, it may be deleted either directly in this context or by the
 *  user after the corresponding AudioInput instance was destroyed. In the latter case this method can be implemented
 *  empty.
 *
 *  This method may be only called in closed state of the adapter, otherwise an error has to be returned.
 *
 *  This method doesn't have to be thread safe.
 *
 *  @param[in,out] instance The instance pointer
 */
typedef void (*FUNC_nuance_audio_IAudioInputAdapter_destroyAdapter)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Audio input adapter interface. <p>
 *
 *  The implementation of this interface is responsible to realize the adaptation of the SDK's audio framework
 *  to a specific audio data source (e.g. audio device, pipe, ..) used in a project.
 *
 *  The adapter implementation is used by the AudioInput audio module to capture audio data from a specific
 *  audio data source to the audio framework of the SDK. Therefor the AudioInput uses the IAudioInputAdapter
 *  interface to control the audio data source and implements the corresponding IAudioInputAdapterListener
 *  interface to retrieve the captured audio data from the adapter. The general procedure is described in
 *  the following:
 *
 *  1) The user provides the specific adapter implementation via one of the following options to the
 *  AudioInput audio module:
 *
 *  1.1) The user creates an instance of the specific adapter implementation and passes it to the AudioInput
 *  module at creation time. After the AudioInput module was destroyed the user also has to destroy the corresponding
 *  adapter instance.
 *
 *  1.2) The user registers a specific adapter factory at the AudioManager and configures the identifier
 *  of this factory as adapter type in the AudioInput module .json configuration. The AudioInput module
 *  uses then the provided adapter factory to create and destroy an instance of this specific adapter.
 *
 *  2) With a call to IAudioInputAdapter::configure() an adapter instance is configured right after its creation
 *  and in case a configuration has changed dynamically, right before calling IAudioInputAdapter::open(). The
 *  configuration of an adapter (e.g. audio format, etc.) is set in the configuration of the AudioInput module.
 *  It is also possible to set adapter specific configuration parameters (e.g. device name, pipe name, etc.) that
 *  are passed as a configuration string in json format to the specific adapter.
 *
 *  3) With a call to the IAudioInputAdapter::open() the audio data source represented by the adapter is opened
 *  with the parameters configured via the last IAudioInputAdapter::configure(). Depending on the AudioInput module's
 *  json configuration, the open is called either when the module becomes connected or whenever a new audio session
 *  is started (e.g. when the recognizer is started). Whereas the latter option should be used only to enable alternating
 *  playback and capturing when an adapter representing a half-duplex audio device is used.
 *
 *  4) A capturing session is started at the adapter with a call to the IAudioInputAdapter::start() method. This
 *  is done by the AudioInput module whenever a new audio session is started (e.g. when the recognizer is started).
 *  From now on each captured audio packet in the configured audio format is announced by the adapter
 *  to the AudioInput module with a call to its IAudioInputAdapterListener::onAudioDataCaptured() method.
 *
 *  5)  In case the adapter does not represent a real audio device, a flow control mechanism has to be implemented by
 *  the adapter. Each announcement of a captured audio packet via a call to IAudioInputAdapterListener::onAudioDataCaptured()
 *  returns the current flow state of audio framework. In case this state corresponds to WILL_DROP, which means, that the next
 *  audio packet would be dropped, the adapter has to pause the announcement of new audio packets until
 *  IAudioInputAdapterListener::resume() is called. PLEASE BE AWARE that due to the scheduler it may be that the resume()
 *  is called before the adapter has evaluated that the onAudioDataCaptured() has returned flow state WILL_DROP. For that
 *  reason the flow control should be realized in the adapter by usage of a semaphore like shown in following example
 *  pseudo code:
 *
 *  start():
 *  - create resume sema (to guarantee that resume sema has the correct state with each started session)
 *  stop():
 *  - signal resume sema to unblock capturing thread that potentially waits on blocked resume sema
 *  - destroy resume sema
 *  resume():
 *  - signal resume semaphore to unblock capturing thread
 *  capturing thread function():
 *  - if onAudioDataCaptured() returned flow state WILL_DROP wait on resume semaphore
 *
 *  In case the adapter accesses a real audio device a flow control mechanism should not be implemented, as pausing
 *  a real audio device is neither intended nor necessary. So the IAudioInputAdapterListener::resume() method has to
 *  return OK immediately.
 *
 *  6) A capturing session is stopped at the adapter with a call to the IAudioInputAdapter::stop() method. This is
 *  done by the AudioInput module whenever an audio session is stopped (e.g. when the recognizer is stopped).
 *  As of now it is no longer allowed to call the IAudioInputAdapterListener::onAudioDataCaptured() method. Hereinafter,
 *  either a capturing session is started anew (see 4.) or the adapter is closed (see 7.).
 *
 *  7) With a call to the IAudioInputAdapter::close() the audio data source represented by the adapter is closed.
 *  Depending on the AudioInput module's .json configuration, this happens either when the module becomes
 *  disconnected or whenever an audio session is stopped (e.g. when the recognizer is stopped). Whereas
 *  the latter option should be used only to enable alternating playback and capturing when an adapter representing a
 *  half-duplex audio device is used.
 *
 *  The audio data delivered by the audio adapter have to be 16bit little endian PCM in the format determined by
 *  the parameter given to the IAudioInputAdapter::configure() method (interleavedFormat, channelCount, sampleRate,
 *  samplesPerChannel).
 */
struct _vtable_nuance_audio_IAudioInputAdapter
{
    /**
     *  @brief  Configures the audio input adapter. <p>
     *
     *  This method configures the adapter with:
     *
     *  - a listener to announce captured audio packets to the audio framework of the SDK
     *  - an adapter specific configuration string parameter in json format
     *  - the audio format the adapter shall be opened with
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
     *  @param[in]     listener            Listener of this audio input adapter object.
     *  @param[in]     adapterParams       Adapter specific configuration parameter json string.
     *  @param[in]     interleavedFormat   Flag indicating whether audio data shall be in interleaved or non-interleaved format.
     *  @param[in]     channelCount        Channel count.
     *  @param[in]     sampleRate          Sample rate in hertz.
     *  @param[in]     samplesPerChannel   Number of samples per channel.
     *
     */
    FUNC_nuance_audio_IAudioInputAdapter_configure configure;

    /**
     *  @brief  Opens the audio input adapter. <p>
     *
     *  This method opens the audio data source (e.g. audio device) represented by the audio input adapter with the
     *  configuration that was given to the last call of the configure() method.
     *
     *  This method may be only called in closed state of the adapter, otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IAudioInputAdapter_open open;

    /**
     *  @brief  Starts capturing via the audio input adapter. <p>
     *
     *  Within this method a capturing session has to be started.
     *
     *  From now on each captured audio packet has to be announced in the proper audio format to the listener by calling
     *  its IAudioInputAdapterListener::onAudioDataCaptured() method. The captured audio data must be valid until the
     *  onAudioDataCaptured() method returns. Audio data of a previous capturing session must not be delivered.
     *
     *  The proper audio format of the audio packet announced is determined by the configured audio format and the fact
     *  that the SDK requires audio data in 16 bit little endian PCM format.
     *
     *  This method may be only called to an opened, but stopped adapter, otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IAudioInputAdapter_start start;

    /**
     *  @brief  Stops capturing via the audio input adapter. <p>
     *
     *  Within this method a started capturing session has to be stopped.
     *
     *  After this method is left it is no longer allowed to announce audio data to the listener by calling its
     *  IAudioInputAdapterListener::onAudioDataCaptured() method.
     *
     *  This method may be only called in started state of the adapter, otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IAudioInputAdapter_stop stop;

    /**
     *  @brief  Resumes capturing via the audio input adapter. <p>
     *
     *  This method resumes a started capturing session that was stopped due to flow control.
     *
     *  In case the adapter does not represent a real audio device, a flow control mechanism has to be implemented by
     *  the adapter. Each announcement of a captured audio packet via a call to IAudioInputAdapterListener::onAudioDataCaptured()
     *  returns the current flow state of the audio framework. In case this state corresponds to WILL_DROP, which means, that the next
     *  audio packet would be dropped, the adapter has to pause the announcement of new audio packets until this method
     *  is called. PLEASE BE AWARE that due to the scheduler it may be that the resume() is called before the adapter has
     *  evaluated that the onAudioDataCaptured() has returned flow state WILL_DROP. For that reason the flow control should
     *  be realized in the adapter by usage of a semaphore like shown in following example pseudo code:
     *
     *  start():
     *  - create resume sema (to guarantee that resume sema has the correct state with each started session)
     *  stop():
     *  - signal resume sema to unblock capturing thread that potentially waits on blocked resume sema
     *  - destroy resume sema
     *  resume():
     *  - signal resume semaphore to unblock capturing thread
     *  capturing thread function():
     *  - if onAudioDataCaptured() returned flow state WILL_DROP wait on resume semaphore
     *
     *  In case the adapter accesses a real audio device a flow control mechanism should not be implemented, as pausing
     *  a real audio device is neither intended nor necessary. So this method has to return OK immediately.
     *
     *  This method may be only called in started state of the adapter, otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IAudioInputAdapter_resume resume;

    /**
     *  @brief  Closes the audio input adapter. <p>
     *
     *  This method closes the audio data source (e.g. audio device) represented by the audio input adapter
     *
     *  This method may be only called in opened, but stopped state of the adapter, otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IAudioInputAdapter_close close;

    /**
     *  @brief  Returns a textual description of the last audio input adapter error. <p>
     *
     *  If applicable the error description of the audio data source represented by the adapter (e.g. audio device)
     *  shall be returned.
     *
     *  In case no last error is available an empty string shall be returned.
     *
     *  It is allowed to call this method in context of the IAudioInputAdapterListener::onAudioDataCaptured() method.
     *
     *  This method may be called in any state of the adapter.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_audio_IAudioInputAdapter_getErrorText getErrorText;

    /**
     *  @brief  Destroys this audio input adapter instance. <p>
     *
     *  This method is called in context of the destructor of the AudioInput module and indicates that this audio
     *  input adapter instance is no longer required. In case this adapter instance was created via the adapter factory
     *  approach it has to be deleted in this context. In case the user has created this instance and passed it to the
     *  AudioInput module as parameter at creation time, it may be deleted either directly in this context or by the
     *  user after the corresponding AudioInput instance was destroyed. In the latter case this method can be implemented
     *  empty.
     *
     *  This method may be only called in closed state of the adapter, otherwise an error has to be returned.
     *
     *  This method doesn't have to be thread safe.
     *
     *  @param[in,out] instance The instance pointer
     */
    FUNC_nuance_audio_IAudioInputAdapter_destroyAdapter destroyAdapter;

};
/**
 *  @brief  Audio input adapter interface. <p>
 *
 *  The implementation of this interface is responsible to realize the adaptation of the SDK's audio framework
 *  to a specific audio data source (e.g. audio device, pipe, ..) used in a project.
 *
 *  The adapter implementation is used by the AudioInput audio module to capture audio data from a specific
 *  audio data source to the audio framework of the SDK. Therefor the AudioInput uses the IAudioInputAdapter
 *  interface to control the audio data source and implements the corresponding IAudioInputAdapterListener
 *  interface to retrieve the captured audio data from the adapter. The general procedure is described in
 *  the following:
 *
 *  1) The user provides the specific adapter implementation via one of the following options to the
 *  AudioInput audio module:
 *
 *  1.1) The user creates an instance of the specific adapter implementation and passes it to the AudioInput
 *  module at creation time. After the AudioInput module was destroyed the user also has to destroy the corresponding
 *  adapter instance.
 *
 *  1.2) The user registers a specific adapter factory at the AudioManager and configures the identifier
 *  of this factory as adapter type in the AudioInput module .json configuration. The AudioInput module
 *  uses then the provided adapter factory to create and destroy an instance of this specific adapter.
 *
 *  2) With a call to IAudioInputAdapter::configure() an adapter instance is configured right after its creation
 *  and in case a configuration has changed dynamically, right before calling IAudioInputAdapter::open(). The
 *  configuration of an adapter (e.g. audio format, etc.) is set in the configuration of the AudioInput module.
 *  It is also possible to set adapter specific configuration parameters (e.g. device name, pipe name, etc.) that
 *  are passed as a configuration string in json format to the specific adapter.
 *
 *  3) With a call to the IAudioInputAdapter::open() the audio data source represented by the adapter is opened
 *  with the parameters configured via the last IAudioInputAdapter::configure(). Depending on the AudioInput module's
 *  json configuration, the open is called either when the module becomes connected or whenever a new audio session
 *  is started (e.g. when the recognizer is started). Whereas the latter option should be used only to enable alternating
 *  playback and capturing when an adapter representing a half-duplex audio device is used.
 *
 *  4) A capturing session is started at the adapter with a call to the IAudioInputAdapter::start() method. This
 *  is done by the AudioInput module whenever a new audio session is started (e.g. when the recognizer is started).
 *  From now on each captured audio packet in the configured audio format is announced by the adapter
 *  to the AudioInput module with a call to its IAudioInputAdapterListener::onAudioDataCaptured() method.
 *
 *  5)  In case the adapter does not represent a real audio device, a flow control mechanism has to be implemented by
 *  the adapter. Each announcement of a captured audio packet via a call to IAudioInputAdapterListener::onAudioDataCaptured()
 *  returns the current flow state of audio framework. In case this state corresponds to WILL_DROP, which means, that the next
 *  audio packet would be dropped, the adapter has to pause the announcement of new audio packets until
 *  IAudioInputAdapterListener::resume() is called. PLEASE BE AWARE that due to the scheduler it may be that the resume()
 *  is called before the adapter has evaluated that the onAudioDataCaptured() has returned flow state WILL_DROP. For that
 *  reason the flow control should be realized in the adapter by usage of a semaphore like shown in following example
 *  pseudo code:
 *
 *  start():
 *  - create resume sema (to guarantee that resume sema has the correct state with each started session)
 *  stop():
 *  - signal resume sema to unblock capturing thread that potentially waits on blocked resume sema
 *  - destroy resume sema
 *  resume():
 *  - signal resume semaphore to unblock capturing thread
 *  capturing thread function():
 *  - if onAudioDataCaptured() returned flow state WILL_DROP wait on resume semaphore
 *
 *  In case the adapter accesses a real audio device a flow control mechanism should not be implemented, as pausing
 *  a real audio device is neither intended nor necessary. So the IAudioInputAdapterListener::resume() method has to
 *  return OK immediately.
 *
 *  6) A capturing session is stopped at the adapter with a call to the IAudioInputAdapter::stop() method. This is
 *  done by the AudioInput module whenever an audio session is stopped (e.g. when the recognizer is stopped).
 *  As of now it is no longer allowed to call the IAudioInputAdapterListener::onAudioDataCaptured() method. Hereinafter,
 *  either a capturing session is started anew (see 4.) or the adapter is closed (see 7.).
 *
 *  7) With a call to the IAudioInputAdapter::close() the audio data source represented by the adapter is closed.
 *  Depending on the AudioInput module's .json configuration, this happens either when the module becomes
 *  disconnected or whenever an audio session is stopped (e.g. when the recognizer is stopped). Whereas
 *  the latter option should be used only to enable alternating playback and capturing when an adapter representing a
 *  half-duplex audio device is used.
 *
 *  The audio data delivered by the audio adapter have to be 16bit little endian PCM in the format determined by
 *  the parameter given to the IAudioInputAdapter::configure() method (interleavedFormat, channelCount, sampleRate,
 *  samplesPerChannel).
 */
typedef struct _vtable_nuance_audio_IAudioInputAdapter vtable_nuance_audio_IAudioInputAdapter;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IAudioInputAdapter *nuance_audio_IAudioInputAdapter_create
(
    const vtable_nuance_audio_IAudioInputAdapter *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IAudioInputAdapter_destroy(nuance_audio_IAudioInputAdapter *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOINPUTADAPTER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
