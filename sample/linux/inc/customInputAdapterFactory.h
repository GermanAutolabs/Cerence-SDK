#ifndef IG_CUSTOMINPUTADAPTERFACTORY_H
#define IG_CUSTOMINPUTADAPTERFACTORY_H

#include "IAudioInputAdapterFactory.h"

#if defined( __cplusplus )
extern "C"
{
#endif

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioInputAdapterFactory
 *  Caller:         User application context, via the audio manager.
 *  @brief          Returns the type identifier of the audio adapters created, for instance "CUSTOM_AUDIO".
 *                  This is the value which needs to be set at the "adapter_type" property of the audio input
 *                  module to trigger the creation of such an adapter.
 *
 *  @param          instance
 *                      [in,out] The instance pointer
 *
 *  @return         type identifier of the adapters this factory is creating.
 *
 *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_String* customAudioInputAdapterFactory_getAdapterType
(
  const void *instance
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioInputAdapterFactory
 *  Caller:         User application context, via the audio manager.
 *  @brief          Creates an audio input adapter instance.
 *                  This method will be called by the audio manager to create
 *                  an instance of the required adapter type.
 *
 *  @param          instance
 *                      [in,out] The instance pointer
 *                  instanceHandleReceiver
 *                      [in] listener object handle which receives the created adapter instance.
 *
 *  @return         Result code
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_common_ResultCode customAudioInputAdapterFactory_createAudioInputAdapter
(
  const void *instance,
  nuance_audio_IAudioInputAdapterFactoryListener *instanceHandleReceiver
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Base class:     IAudioInputAdapterFactory
 *  Caller:         Audio manager destructor.
 *  @brief          Release this instance of the factory.The audio manager
 *                  has removed that factory handle from its internal registry.
 *
 *  @param          instance
 *                      [in,out] The instance pointer
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void customAudioInputAdapterFactory_releaseFactory
(
  void *instance
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  Caller:         User application.
 *  @brief          Creates the instance of the needed adapter factory.
 *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nuance_audio_IAudioInputAdapterFactory *customAudioInputAdapterFactory_create();

#if defined( __cplusplus )
}
#endif
#endif /* IG_CUSTOMINPUTADAPTERFACTORY_H */
