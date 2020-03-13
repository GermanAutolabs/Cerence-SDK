#include "customOutputAdapterFactory.h"
#include "customOutputAudioAdapter.h"

typedef struct _customAudioOutputAdapterFactory
{
  nuance_audio_IAudioOutputAdapterFactory *factory;
  nuance_common_ILogModule *pLogModule;
} customAudioOutputAdapterFactory;

nuance_common_String* customAudioOutputAdapterFactory_getAdapterType
(
  const void *instance
)
{
  const LH_CHAR str[] = "CUSTOM_AUDIO";
  AUDIOOUT_LOG(((customAudioOutputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC, "Starting customOutputAdapterFactory::customAudioOutputAdapterFactory_getAdapterType()");
  return nuance_common_String_create(str);
}

nuance_common_ResultCode customAudioOutputAdapterFactory_createAudioOutputAdapter
(
  const void *instance,
  nuance_audio_IAudioOutputAdapterFactoryListener *instanceHandleReceiver
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  AUDIOOUT_LOG(((customAudioOutputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC, "Starting customOutputAdapterFactory::customAudioOutputAdapterFactory_createAudioOutputAdapter()");
  
  /* check for valid nuance_audio_IAudioOutputAdapterFactoryListener */
  if (LH_NULL == instanceHandleReceiver)
  {
    AUDIOOUT_LOG(((customAudioOutputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAdapterFactory::customAudioOutputAdapterFactory_createAudioOutputAdapter(): Invalid pointer for nuance_audio_IAudioOutputAdapterFactoryListener");
    rc = NUANCE_COMMON_ERROR;
  }
  
  else
  {
    /* initializing the vtable_nuance_audio_IAudioOutputAdapter structure */
    vtable_nuance_audio_IAudioOutputAdapter nuance_audio_customAudioOutputAdapterInterface = {customAudioOutputAdapter_configure, customAudioOutputAdapter_open, customAudioOutputAdapter_write, customAudioOutputAdapter_writeEncoded, customAudioOutputAdapter_endOfStream, customAudioOutputAdapter_abort, customAudioOutputAdapter_close, customAudioOutputAdapter_getErrorText, customAudioOutputAdapter_destroyAdapter};
    customAudioOutputAdapter *instance_customAudioOutputAdapter = LH_NULL;
    
    /* allocating memory to customAudioOutputAdapter instance */
    instance_customAudioOutputAdapter = (customAudioOutputAdapter *)malloc(sizeof(customAudioOutputAdapter));
    
    if (LH_NULL == instance_customAudioOutputAdapter)
    {
      AUDIOOUT_LOG(((customAudioOutputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAdapterFactory::customAudioOutputAdapterFactory_createAudioOutputAdapter(): Cannot allocate memory for instance_customAudioOutputAdapter. No memory available. ");
      rc = NUANCE_COMMON_ERROR;
    }

    else
    {
      /* initializing the customAudioOutputAdapter structure */
      instance_customAudioOutputAdapter->pAudioOutHandle = LH_NULL;
      instance_customAudioOutputAdapter->plistener = LH_NULL;
      instance_customAudioOutputAdapter->audioout_err = AUDIO_OUTPUT_OK;
      instance_customAudioOutputAdapter->deviceName = LH_NULL;
      instance_customAudioOutputAdapter->platformConfig = LH_NULL;
      instance_customAudioOutputAdapter->customAdapterInstance = LH_NULL;
      instance_customAudioOutputAdapter->pLogModule = ((customAudioOutputAdapterFactory*) instance)->pLogModule;

      /* constructor call to populate instance_customAudioOutputAdapter->customAdapterInstance */
      instance_customAudioOutputAdapter->customAdapterInstance = nuance_audio_IAudioOutputAdapter_create(&nuance_audio_customAudioOutputAdapterInterface, (void *)instance_customAudioOutputAdapter);

      if (LH_NULL == instance_customAudioOutputAdapter->customAdapterInstance)
      {
        AUDIOOUT_LOG(((customAudioOutputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAdapterFactory::customAudioOutputAdapterFactory_createAudioOutputAdapter(): Cannot allocate memory for instance_customAudioOutputAdapter->customAdapterInstance. No memory available");
        rc = NUANCE_COMMON_ERROR;
      }

      else
      {
        /* gets the handle of a freshly created IAudioOutputAdapter object. */
        nuance_audio_IAudioOutputAdapterFactoryListener_onOutputAdapterCreated(instanceHandleReceiver, instance_customAudioOutputAdapter->customAdapterInstance);
      }
    }
  }
  return rc;
}

nuance_audio_IAudioOutputAdapterFactory* customAudioOutputAdapterFactory_create()
{
  customAudioOutputAdapterFactory *instance = LH_NULL;
  nuance_common_ILogModule *_local_logModule;
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;

  /* initializing the vtable_nuance_audio_IAudioOutputAdapterFactory structure */
  vtable_nuance_audio_IAudioOutputAdapterFactory customAudioOutputAdapterFactoryInterface = { customAudioOutputAdapterFactory_getAdapterType, customAudioOutputAdapterFactory_createAudioOutputAdapter, customAudioOutputAdapterFactory_releaseFactory };
  
  rc = nuance_common_ILogging_createLogModule(nuance_common_ILogging_getInstance(), "nuance.custom.AUDIO", &_local_logModule);
  
  if (NUANCE_COMMON_OK != rc)
  {
    return LH_NULL; /* Returning null since logModule was not created successfully */
  }

  AUDIOOUT_LOG(_local_logModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC, "Starting customOutputAdapterFactory::customAudioOutputAdapterFactory_create()");
  
  instance = (customAudioOutputAdapterFactory*) calloc(1, sizeof(customAudioOutputAdapterFactory));

  if (LH_NULL == instance)
  {
    AUDIOOUT_LOG(_local_logModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customOutputAdapterFactory::customAudioOutputAdapterFactory_create(): cannot allocate memory for instance failed");
    return LH_NULL;
  }

  else
  {
    instance->pLogModule = _local_logModule;
    /* constructor call to populate instance->factory */
    instance->factory = nuance_audio_IAudioOutputAdapterFactory_create(&customAudioOutputAdapterFactoryInterface, instance);
  }
  return instance->factory;
}

void customAudioOutputAdapterFactory_releaseFactory
(
  void *instance
)
{
  AUDIOOUT_LOG(((customAudioOutputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC, "Starting customOutputAdapterFactory::customAudioOutputAdapterFactory_releaseFactory()");
  
  /* destructor calls */
  nuance_audio_IAudioOutputAdapterFactory_destroy(((customAudioOutputAdapterFactory*) instance)->factory);
  nuance_common_ILogModule_destroy(((customAudioOutputAdapterFactory*) instance)->pLogModule);
  AUDIOOUT_FREE_SET_NULL(instance);
}
