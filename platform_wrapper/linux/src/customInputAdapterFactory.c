#include "customInputAdapterFactory.h"
#include "customInputAudioAdapter.h"

typedef struct _customAudioInputAdapterFactory
{
  nuance_audio_IAudioInputAdapterFactory *factory;
  nuance_common_ILogModule *pLogModule;
} customAudioInputAdapterFactory;

nuance_common_String* customAudioInputAdapterFactory_getAdapterType
(
  const void *instance
)
{
  const LH_CHAR str[] = "CUSTOM_AUDIO";
  AUDIOIN_LOG(((customAudioInputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC,"Starting customInputAdapterFactory::customAudioInputAdapterFactory_getAdapterType()");
  return nuance_common_String_create(str);
}

nuance_common_ResultCode customAudioInputAdapterFactory_createAudioInputAdapter
(
  const void *instance,
  nuance_audio_IAudioInputAdapterFactoryListener *instanceHandleReceiver
)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  AUDIOIN_LOG(((customAudioInputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC,"Starting customInputAdapterFactory::customAudioInputAdapterFactory_createAudioInputAdapter()");

  /* check for valid nuance_audio_IAudioInputAdapterFactoryListener */
  if (LH_NULL == instanceHandleReceiver)
  {
    AUDIOIN_LOG(((customAudioInputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR,"ERROR:- customInputAdapterFactory::customAudioInputAdapterFactory_createAudioInputAdapter(): Invalid pointer for nuance_audio_IAudioInputAdapterFactoryListener");
    rc = NUANCE_COMMON_ERROR;
  }

  else
  {
    /* initializing the vtable_nuance_audio_IAudioInputAdapter structure */
    vtable_nuance_audio_IAudioInputAdapter nuance_audio_customAudioInputAdapterInterface = { customAudioInputAdapter_configure, customAudioInputAdapter_open, customAudioInputAdapter_start, customAudioInputAdapter_stop, customAudioInputAdapter_resume, customAudioInputAdapter_close, customAudioInputAdapter_getErrorText , customAudioInputAdapter_destroyAdapter };

    customAudioInputAdapter *instance_customAudioInputAdapter = LH_NULL;

    /* allocating memory to customAudioInputAdapter instance */
    instance_customAudioInputAdapter = (customAudioInputAdapter *)malloc(sizeof(customAudioInputAdapter));

    if (LH_NULL == instance_customAudioInputAdapter)
    {
      AUDIOIN_LOG(((customAudioInputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR,"ERROR:- customInputAdapterFactory::customAudioInputAdapterFactory_createAudioInputAdapter(): allocate memory for instance_customAudioInputAdapter. No memory available");
      rc = NUANCE_COMMON_ERROR;
    }
    else
    {
      /* Initializing the customAudioInputAdapter structure */
      instance_customAudioInputAdapter->pAudioInHandle = LH_NULL;
      instance_customAudioInputAdapter->plistener = LH_NULL;
      instance_customAudioInputAdapter->state_ = STATE_CLOSED;
      instance_customAudioInputAdapter->audioin_err = AUDIO_INPUT_OK;
      instance_customAudioInputAdapter->deviceName = LH_NULL;
      instance_customAudioInputAdapter->platformConfig = LH_NULL;
      instance_customAudioInputAdapter->customAdapterInstance = LH_NULL;
      instance_customAudioInputAdapter->pLogModule = ((customAudioInputAdapterFactory*) instance)->pLogModule;

      /* constructor call to populate instance_customAudioInputAdapter->customAdapterInstance */
      instance_customAudioInputAdapter->customAdapterInstance = nuance_audio_IAudioInputAdapter_create(&nuance_audio_customAudioInputAdapterInterface, (void *)instance_customAudioInputAdapter);

      if (LH_NULL == instance_customAudioInputAdapter->customAdapterInstance)
      {
        AUDIOIN_LOG(((customAudioInputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_ERROR,"ERROR:- customInputAdapterFactory::customAudioInputAdapterFactory_createAudioInputAdapter(): allocate memory for instance_customAudioInputAdapter->customAdapterInstance. No memory available");
        rc = NUANCE_COMMON_ERROR;
      }

      else
      {
        /* gets the handle of a freshly created IAudioInputAdapter object. */
        nuance_audio_IAudioInputAdapterFactoryListener_onInputAdapterCreated(instanceHandleReceiver, instance_customAudioInputAdapter->customAdapterInstance);
      }
    }
  }
  return rc;
}

nuance_audio_IAudioInputAdapterFactory* customAudioInputAdapterFactory_create()
{
  customAudioInputAdapterFactory *instance = LH_NULL;
  nuance_common_ILogModule *_local_logModule;
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;

  /* initializing the vtable_nuance_audio_IAudioInputAdapterFactory structure */
  vtable_nuance_audio_IAudioInputAdapterFactory customAudioInputAdapterFactoryInterface = {customAudioInputAdapterFactory_getAdapterType, customAudioInputAdapterFactory_createAudioInputAdapter, customAudioInputAdapterFactory_releaseFactory };

  rc = nuance_common_ILogging_createLogModule(nuance_common_ILogging_getInstance(), "nuance.custom.AUDIO", &_local_logModule);

  if (NUANCE_COMMON_OK != rc)
  {
    return LH_NULL; /* Returning null since pLogModule was not created successfully */
  }

  AUDIOIN_LOG(_local_logModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC, "Starting customInputAdapterFactory::customAudioInputAdapterFactory_create()");

  instance = (customAudioInputAdapterFactory*) calloc(1, sizeof(customAudioInputAdapterFactory));

  if (LH_NULL == instance)
  {
    AUDIOIN_LOG(_local_logModule, NUANCE_COMMON_LOG_ERROR, "ERROR:- customInputAdapterFactory::customAudioInputAdapterFactory_create(): cannot allocate memory for instance failed");
    return LH_NULL;
  }

  else
  {
    instance->pLogModule = _local_logModule;
    /* constructor call to populate instance->factory */
    instance->factory = nuance_audio_IAudioInputAdapterFactory_create(&customAudioInputAdapterFactoryInterface, instance);
  }
  return instance->factory;
}

void customAudioInputAdapterFactory_releaseFactory
(
  void *instance
)
{
  AUDIOIN_LOG(((customAudioInputAdapterFactory*) instance)->pLogModule, NUANCE_COMMON_LOG_EXTERNAL_FUNC,"Starting customInputAdapterFactory::customAudioInputAdapterFactory_releaseFactory()");

  /* destructor call */
  nuance_audio_IAudioInputAdapterFactory_destroy(((customAudioInputAdapterFactory*) instance)->factory);
  nuance_common_ILogModule_destroy(((customAudioInputAdapterFactory*) instance)->pLogModule);
  AUDIOIN_FREESETNULL(instance);
}