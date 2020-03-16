/**
 * @file asr_cerence_api.c
 * @author your name (vaibhav.pandey@germanautolabs.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "asr_cerence_api.h"

/* -------------------------------------------------------------------------+
 |   LOCAL DATA STRUCTURES                                                  |
 + -------------------------------------------------------------------------*/
typedef enum
{
  ASLEEP,
  AWAKE,
  STOPPED
}ASR_STATE;

typedef enum
{
  UNQUALIFIED_RESULT,
  WUW_RESULT,
  COMMAND_RESULT,
  INITIAL_TIMEOUT
}ASR_EVENT;

typedef struct EVENTNODE
{
  ASR_EVENT eventType;
  struct EVENTNODE *next;
}EVENTNODE_T;

typedef struct
{
  LH_CHAR*    startRule;
  LH_S32      confidence;
  LH_S32      endTime;
} TopResult;

typedef struct
{
  const char* name;
  const char* source;
  const char* cop;
  LH_BOOL persistExistingContext;
} sDccConfig;

typedef struct
{
  const char* configDir;
  const char* audioConfigDir;
  const char* audioList[MAX_NR_AUDIOSCENARIOS];
  const char* asrManagerNames;
  const char* applicationNames[MAX_NR_APPLICATIONS];
  const char* recognizerNames[MAX_NR_RECOGNIZERS];
  sDccConfig dccConfigs[MAX_NR_DYNAMIC_CONTENT_CONSUMERS];
  size_t nrAudioScenarios;
  size_t nbrConfiguredApplications;
  size_t nbrConfiguredRecognizers;
  size_t nbrConfiguredDCCs;
} sConfigParameters;

typedef struct
{
  const char* name;
  const char* startRule;
  LH_S32 confidenceThreshold;
}ApplicationObject;

/* -------------------------------------------------------------------------+
 | APPLICATION SETTINGS                                                     |
 + -------------------------------------------------------------------------*/
static const LH_CHAR* START_RULE = "startRule";
static const LH_CHAR* HYPOTHESES = "hypotheses";
static const LH_CHAR* END_TIME = "endTime";
static const LH_CHAR* CONFIDENCE = "confidence";
static const LH_CHAR* AUDIO_SCENARIO_NAME = "mic";
static const LH_CHAR* WUW_APPLICATION_NAME = "WUW";
static const LH_CHAR* COMMAND_APPLICATION_NAME = "MUSIC_SIMPLE";
static const LH_CHAR* RECOGNIZER_NAME = "rec";
static const LH_CHAR* ASR_NAME = "asr";
static const LH_CHAR* DCC_NAME = "DCC_LOCAL_TITLE";
static const LH_CHAR* COPFILE_NAME = "songs.cop";
static const LH_CHAR* ORTHOGRAPHY = "orthography";
static const LH_CHAR* ANYSPEECH = "<...>";
static const LH_CHAR* ITEMS = "items";
static const LH_CHAR* TYPE = "type";
static const LH_CHAR* TAG = "tag";
static nuance_asr5_IDynamicContentConsumer* g_dcc[MAX_NR_DYNAMIC_CONTENT_CONSUMERS];
static char* g_callbackKeysFilename;
static nuance_asr5_IApplication *g_applications[MAX_NR_APPLICATIONS] = {0};
static MT_SEMAPHORE g_sem;
static MT_MUTEX g_mutex;
static LH_BOOL g_silenceDetected;
static LH_BOOL g_speechDetected;
static ASR_STATE g_state;
static TopResult g_topResult;
static LH_S32 g_timeoutMs = 2000;
ApplicationObject g_wuwApplication = {"WUW", "wuw_anyspeech#_main_", 6000};
static EVENTNODE_T *g_eventListHead, *g_eventListTail;
sConfigParameters g_config;
sConfigParameters* config;

/* -------------------------------------------------------------------------+
 |   LOCAL FUNCTION PROTOTYPES                                              |
 + -------------------------------------------------------------------------*/
static void disableErrorReportingPopups() {}
//static void init_configuration(void);
static void printUsage();
static void pushEvent(ASR_EVENT event);
static void popEvent(ASR_EVENT *event);
static void emptyEventList();
static void IRecognizerListener_onEvent(void *instance,
                                        nuance_asr5_RecogEvent event,
                                        LH_S32 timeMarker,
                                        const LH_CHAR *message);
static void IRecognizerListener_onResult(void *instance,
                                         const LH_CHAR *result,
                                         nuance_asr5_ResultType resultType,
                                         LH_BOOL isFinal);
static void IRecognizerListener_onError(void *instance,
                                        nuance_asr5_RecognizerError error,
                                        const LH_CHAR *message);
static void IRecognizerListener_onWarning(void *instance,
                                          nuance_asr5_RecognizerError warning,
                                          const LH_CHAR *message);


/* Start Linux system Specific APIS*/
static timer_t timerid;

void initialTimeoutCallback() {
  /* when initial timeout happens, terminate the recognition */
  printf("Command should be within %dms after wake-up word for one-shot wuw case!\n", g_timeoutMs);
  pushEvent(INITIAL_TIMEOUT);
}

nuance_common_ResultCode initTimer()
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  struct sigaction sa;
  struct sigevent sev;
  sigset_t mask;
  
  /* Establish handler for timer signal */
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = initialTimeoutCallback;
  sigemptyset(&sa.sa_mask);
  sigaction(SIG, &sa, NULL);

  /* Create the timer */
  sev.sigev_notify = SIGEV_SIGNAL;
  sev.sigev_signo = SIG;
  sev.sigev_value.sival_ptr = &timerid;

  if (timer_create(CLOCK_REALTIME, &sev, &timerid) == -1)
  {
    printf("ERROR: initTimer failed.\n");
    rc = NUANCE_COMMON_ERROR;
  }

  return rc;
}

nuance_common_ResultCode startTimer(LH_S32 timeoutMs)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  struct itimerspec its;
  its.it_value.tv_sec = timeoutMs / 1000;
  its.it_value.tv_nsec = ((long int)timeoutMs * 1000000 ) % 1000000000;
  its.it_interval.tv_sec = 0;
  its.it_interval.tv_nsec = 0;
  
  if (timer_settime(timerid, 0, &its, NULL) == -1)
  {
    printf("ERROR: startTimer failed.\n");
    rc = NUANCE_COMMON_ERROR;
  }

  return rc;
}

nuance_common_ResultCode stopTimer()
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  struct itimerspec its;
  its.it_value.tv_sec = 0;
  its.it_value.tv_nsec = 0;
  its.it_interval.tv_sec = 0;
  its.it_interval.tv_nsec = 0;
  
  if (timer_settime(timerid, 0, &its, NULL) == -1)
  {
    printf("ERROR: stopTimer failed.\n");
    rc = NUANCE_COMMON_ERROR;
  }

  return rc;
}

nuance_common_ResultCode deleteTimer()
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;

  return rc;
}
/* End Linux Specific */
static vtable_nuance_asr5_IRecognizerListener SampleRecognizerListener_Callbacks = { IRecognizerListener_onEvent,
                                                                                     IRecognizerListener_onResult,
                                                                                     IRecognizerListener_onError,
                                                                                     IRecognizerListener_onWarning };

static void printUsage()
{
  printf("Usage: \n"
         "  c_one_shot_wuw_sample.exe <options>\n"
         "\n"
         "Options: \n"
         "--configDir=<directory>\n"
         "--audioScenario=<mic>\n"
         "--application=<wuwAppName>,<commandAppName1>,<commandAppName2>,...\n"
         "--asrManager=<asr>\n"
         "--recognizer=<rec>\n"
         "--wuwStartRule=<wuw_anyspeech#_main_>\n"
         "--confidenceThreshold=<6000>\n"
         "--initialTimeout=<2000>\n"
         "--dcc=\"<name1>,<copfile1>;<name2>,<copfile2>;...\"\n"
         );
}


static void parseItems(cJSON *items, LH_BOOL needSetConfidence)
{
  int size = 0;
  int idx = 0;
  cJSON *pTmpItem = 0;
  cJSON *pCurrentItem = 0;
  cJSON *internalItems = 0;
  LH_CHAR* type = NULL;
  LH_CHAR* ortho = NULL;

  size = cJSON_GetArraySize(items);
  for(idx = size-1; idx >= 0; idx--)
  {
    pCurrentItem = cJSON_GetArrayItem(items, idx);
    if (LH_NULL == pCurrentItem)  return;

    pTmpItem = cJSON_GetObjectItem(pCurrentItem, TYPE);
    if (LH_NULL == pTmpItem)  return;
    type = pTmpItem->valuestring;

    if (0 == strcmp(type, TAG))
    {
      
      if (needSetConfidence)
      {
        pTmpItem = cJSON_GetObjectItem(pCurrentItem, CONFIDENCE);
        if (LH_NULL == pTmpItem)  return;
        g_topResult.confidence = pTmpItem->valueint;
        needSetConfidence = LH_FALSE;
      }

      internalItems = cJSON_GetObjectItem(pCurrentItem, ITEMS);
      if (LH_NULL == internalItems)  return;
      parseItems(internalItems, needSetConfidence);
    }
    else
    {

      pTmpItem = cJSON_GetObjectItem(pCurrentItem, ORTHOGRAPHY);
      if (LH_NULL == pTmpItem)  return;
      ortho = pTmpItem->valuestring;
      if (0 == strcmp(ortho, ANYSPEECH))
      {
        continue;
      }

      pTmpItem = cJSON_GetObjectItem(pCurrentItem, END_TIME);
      if (LH_NULL == pTmpItem) return;
      g_topResult.endTime = pTmpItem->valueint;
      break;
    }
  }
}


static void parseWUWEndTimeAndConfidence(cJSON *hypothese)
{
  cJSON *pHypotheseItems = 0;
  pHypotheseItems = cJSON_GetObjectItem(hypothese, ITEMS);
  if (LH_NULL == pHypotheseItems)  return;

  parseItems(pHypotheseItems, LH_TRUE);
}

static void parseResult(const LH_CHAR *result)
{
  int size = 0;
  cJSON *hypotheses = 0;
  cJSON *hypothese = 0;
  cJSON *pItem = 0;
  cJSON *cJson = cJSON_Parse(result);
  ASR_EVENT event = UNQUALIFIED_RESULT;

  if (!cJson)
  {
    printf("Failed to parse result\n");
    return;
  }

  pItem = cJSON_GetObjectItem(cJson, END_TIME);
  if (LH_NULL == pItem) return;
  g_topResult.endTime = pItem->valueint;

  hypotheses = cJSON_GetObjectItem(cJson, HYPOTHESES);
  if (LH_NULL == hypotheses)
  {
    return;
  }

  size = cJSON_GetArraySize(hypotheses);
  if(size)
  {
    hypothese = cJSON_GetArrayItem(hypotheses, 0);
    if (LH_NULL != hypothese)
    {
      pItem = cJSON_GetObjectItem(hypothese, START_RULE);
      if (LH_NULL == pItem)
      {
        return;
      }
      if (g_topResult.startRule)
      {
        free(g_topResult.startRule);
        g_topResult.startRule = 0;
      }
      g_topResult.startRule = malloc(strlen(pItem->valuestring) + 1);
      memcpy(g_topResult.startRule, pItem->valuestring, strlen(pItem->valuestring) + 1);

      parseWUWEndTimeAndConfidence(hypothese);
    }
    else
      return;

  }

  if(ASLEEP == g_state)
  {
    if(0 == strcmp(g_wuwApplication.startRule,g_topResult.startRule)
        && g_topResult.confidence >= g_wuwApplication.confidenceThreshold)
    {
      event = WUW_RESULT;
    }
    pushEvent(event);
  }


  cJSON_Delete(cJson);
}

static void IRecognizerListener_onEvent(void *instance,
                                        nuance_asr5_RecogEvent event,
                                        LH_S32 timeMarker,
                                        const LH_CHAR *message)
{
  if (event == NUANCE_ASR5_RECOGNIZER_SILENCE_DETECTED && !g_silenceDetected)
  {
    printf("\nEVENT :%s Event message: %s\n", nuance_asr5_RecogEvent_toString(event),
                            (NULL == message) ? "null" : message);
    g_silenceDetected = LH_TRUE;
    g_speechDetected = LH_FALSE;
  }
  if (event == NUANCE_ASR5_RECOGNIZER_SPEECH_DETECTED && !g_speechDetected)
  {
    printf("\nEVENT :%s Event message: %s\n", nuance_asr5_RecogEvent_toString(event),
                            (NULL == message) ? "null" : message);
    g_silenceDetected = LH_FALSE;
    g_speechDetected = LH_TRUE;
    if(AWAKE == g_state)
    {
      stopTimer();
    }
  }
  //Below Events needs to be handled, statemachine shall be extended to cover these events
  if (event != NUANCE_ASR5_RECOGNIZER_SILENCE_DETECTED && event != NUANCE_ASR5_RECOGNIZER_SPEECH_DETECTED)
  {

  	if ((NUANCE_ASR5_RECOGNIZER_AUDIO_FINISHED == event) && (AWAKE == g_state))
  	{
        printf("\nEVENT :%s Event message: %s\n", nuance_asr5_RecogEvent_toString(event),
            (NULL == message) ? "null" : message);
  	}
  	else if ((NUANCE_ASR5_RECOGNIZER_AUDIO_STOPPED == event) && (AWAKE == g_state))
  	{
        printf("\nEVENT :%s Event message: %s\n", nuance_asr5_RecogEvent_toString(event),
            (NULL == message) ? "null" : message);
  	}
  	else
    {
        printf("\nEVENT :%s Event message: %s\n", nuance_asr5_RecogEvent_toString(event),
            (NULL == message) ? "null" : message);
    }
  }
}

static void IRecognizerListener_onResult(void *instance,
                                         const LH_CHAR *result,
                                         nuance_asr5_ResultType resultType,
                                         LH_BOOL isFinal)
{
  printf("\nRESULT :%s \n%s\n", (NULL == result) ? "null" : result,
                      isFinal ? "FINAL RESULT" : "PARTIAL RESULT");

  if (resultType == NUANCE_ASR5_RESULT_TYPE_ASR)
  {
    liwr_recogResult(result, resultType);
    parseResult(result);
  }
  else if (resultType == NUANCE_ASR5_RESULT_TYPE_SEMANTIC)
  {
    pushEvent(COMMAND_RESULT);
  }
}

static void IRecognizerListener_onError(void *instance,
                                        nuance_asr5_RecognizerError error,
                                        const LH_CHAR *message)
{
  printf("\nERROR :%s Error message: %s\n", nuance_asr5_RecognizerError_toString(error),
                      (NULL == message) ? "null" : message);
}

static void IRecognizerListener_onWarning(void *instance,
                                          nuance_asr5_RecognizerError warning,
                                          const LH_CHAR *message)
{
  printf("\nWARNING :%s Warning message: %s\n", nuance_asr5_RecognizerError_toString(warning),
                      (NULL == message) ? "null" : message);
}

static nuance_common_ResultCode createConfiguration(const LH_CHAR *configDir, nuance_common_IConfiguration **configuration)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  /* Load configuration */
  rc = nuance_common_IConfiguration_createWithValidation(configDir, 0, LH_FALSE, configuration);

  if (NUANCE_COMMON_OK != rc)
  {
    printf("Could not create IConfiguration object for '%s'\n", configDir);
  }
  return rc;
}

static nuance_common_ResultCode setupAudioAndCloud(sConfigParameters *config, nuance_common_IConfiguration **audioConfiguration,
                                                    nuance_common_ISystemManager **systemMgr, nuance_audio_IAudioManager **audioMgr,
                                                    nuance_cloudservices_ICloudManager **cloudMgr,
                                                    nuance_audio_IAudioInputAdapterFactory **factory)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;

  rc = createConfiguration(config->audioConfigDir, audioConfiguration);
  if (rc != NUANCE_COMMON_OK)
  {
    return rc;
  }

  rc = nuance_common_ISystemManager_create("MAIN", *audioConfiguration, systemMgr);
  if (NUANCE_COMMON_OK != rc || *systemMgr == 0)
  {
    printf("Could not create system manager\n");
    return rc;
  }

  rc = nuance_cloudservices_ICloudManager_create("MAIN", *systemMgr, *audioConfiguration, cloudMgr);
  if (NUANCE_COMMON_OK != rc || *cloudMgr == 0)
  {
    printf("Could not create cloudMgr manager\n");
    return rc;
  }

  rc = nuance_audio_IAudioManager_create("MAIN", *systemMgr, *audioConfiguration, 0, audioMgr);
  if (NUANCE_COMMON_OK != rc || *audioMgr == 0)
  {
    printf("Could not create audio manager\n");
    return rc;
  }

  /* trigger implicit creation feature for the file IO modules */
  if (NUANCE_COMMON_OK != nuance_audio_IAudioFromFile_registerFactory(*audioMgr))
  {
    printf("Error: nuance_audio_IAudioFromFile_registerFactory failed\n");
    return rc;
  }

  /* trigger implicit creation feature for custom based input adapters */
  if (LH_NULL == (*factory = customAudioInputAdapterFactory_create()))
  {
    printf("ERROR: nuance_audio_IAudioInputAdapterFactory_create() failed");
    rc = NUANCE_COMMON_ERROR;
    return rc;
  }

  if (NUANCE_COMMON_OK != (rc = nuance_audio_IAudioManager_registerAudioInputAdapterFactory(*audioMgr, *factory)))
  {
    printf("registerFactory for Custom AudioInputAdapter failed\n");
    return rc;
  }

  /* trigger implicit creation feature for the audio IO modules */
  if (NUANCE_COMMON_OK !=nuance_audio_IAudioInput_registerFactory(*audioMgr))
  {
    printf("registerFactory for IAudioInput failed\n");
    return rc;
  }

  return rc;
}

nuance_common_ResultCode setupAsrManager(sConfigParameters *config, nuance_cloudservices_ICloudManager *cloudMgr, nuance_audio_IAudioManager *audioMgr, nuance_common_IConfiguration **asrConfiguration, nuance_asr5_IAsrManager **asrMgr)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;

  rc = createConfiguration(config->configDir, asrConfiguration);
  if (rc != NUANCE_COMMON_OK)
  {
    return rc;
  }

  rc = nuance_asr5_IAsrManager_create(config->asrManagerNames, *asrConfiguration, cloudMgr, audioMgr, 0, asrMgr);
  if (rc != NUANCE_COMMON_OK || *asrMgr == 0) {
    printf("ERROR: AsrManager creation failed.\n");
    return rc;
  }

  return rc;
}

nuance_common_ResultCode setupRecognizer(nuance_asr5_IAsrManager *asrMgr,
                                         nuance_asr5_IRecognizerListener *listener,
                                         nuance_asr5_IRecognizer **recognizer)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;

  rc = nuance_asr5_IRecognizer_create(RECOGNIZER_NAME,
                                      asrMgr,
                                      listener,
                                      recognizer);
  if (rc != NUANCE_COMMON_OK || *recognizer == 0) {
    printf("ERROR: Recognizer creation failed.\n");
    return rc;
  }

  return rc;
}

static void pushEvent(ASR_EVENT event)
{
  EVENTNODE_T *newEvent = 0;
  mt_mutex_lock(g_mutex);

  newEvent = malloc(sizeof(EVENTNODE_T));
  newEvent->eventType = event;
  newEvent->next = NULL;
  if(NULL == g_eventListHead)
  {
    g_eventListHead = newEvent;
  }

  if(NULL == g_eventListTail)
  {
    g_eventListTail = newEvent;
  }
  else
  {
    g_eventListTail->next = newEvent;
    g_eventListTail = newEvent;
  }
  mt_mutex_unlock(g_mutex);
  mt_semaphore_release(g_sem);
}

static void popEvent(ASR_EVENT *event)
{
  mt_semaphore_acquire(g_sem);
  mt_mutex_lock(g_mutex);
  if(g_eventListHead != NULL)
  {
    EVENTNODE_T *eventNode = g_eventListHead;
    *event = eventNode->eventType;

    g_eventListHead = g_eventListHead->next;
    if(NULL == g_eventListHead)
    {
      g_eventListTail = NULL;
    }
    free(eventNode);
  }
  mt_mutex_unlock(g_mutex);
  return;
}

static void emptyEventList()
{
  mt_mutex_lock(g_mutex);
  while(g_eventListHead != NULL)
  {
    EVENTNODE_T *eventNode = g_eventListHead;
    g_eventListHead = g_eventListHead->next;
    free(eventNode);
  }
  mt_mutex_unlock(g_mutex);
}

nuance_common_ResultCode initApplications(sConfigParameters *config, nuance_asr5_IAsrManager *asrMgr)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  size_t i = 0;
  for(i = 0; i < config->nbrConfiguredApplications; i++)
  {
    if(NULL == config->applicationNames[i])
    {
      continue;
    }
    rc = nuance_asr5_IApplication_create(asrMgr, config->applicationNames[i], 0, &g_applications[i]);
    if (rc != NUANCE_COMMON_OK || !g_applications[i]) {
      printf("ERROR: Application[%d] creation failed.\n", (int)i);
      return rc;
    }
  }

  return rc;
}

LH_S32 initDCCs(sConfigParameters *config, nuance_asr5_IAsrManager *asrMgr)
{
  LH_S32 returnCode = 0;
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  size_t i = 0;
  for(i = 0; i < config->nbrConfiguredDCCs; i++)
  {
    rc = nuance_asr5_IDynamicContentConsumer_createFromSource(asrMgr, config->dccConfigs[i].name, config->dccConfigs[i].source, 0, &g_dcc[i]);
    if (rc != NUANCE_COMMON_OK || !g_dcc[i]) {
      printf("ERROR: DCC creation failed.\n");
      return rc;
    }
  }

  return returnCode;
}

LH_S32 getCommandApps(sConfigParameters* config,
               LH_CHAR *addedApplications,
               const LH_CHAR **applications)
{
  LH_S32 i;
  LH_S32 nbrAddedApplications = 0;
  LH_S32 nbrConfiguredApplications = config->nbrConfiguredApplications;

  /* The 1st one is WUW application */
  for (i = 1; i < nbrConfiguredApplications; ++i)
  {
    strcat(addedApplications, config->applicationNames[i]);
    strcat(addedApplications, " ");
    applications[nbrAddedApplications] = config->applicationNames[i];
    nbrAddedApplications++;
  }

  return nbrAddedApplications;
}

nuance_common_ResultCode addApplications(sConfigParameters *config, nuance_asr5_IAsrManager *asrMgr, const TopResult *result)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  LH_S32 startTimeMs = result->endTime;
  const LH_CHAR* applications[MAX_NR_APPLICATIONS] = {0};

  LH_CHAR addedApplications[100] = {0};
  LH_S32 nbrAddedApplications = 0;

  if(g_state == ASLEEP)
  {
    applications[0] = config->applicationNames[0];
    nbrAddedApplications = 1;
    strcat(addedApplications, config->applicationNames[0]);
  }
  else if(g_state == AWAKE)
  {
    nbrAddedApplications = getCommandApps(config, addedApplications, applications);
  }

  rc = nuance_asr5_IAsrManager_setApplications(asrMgr, applications, nbrAddedApplications, config->recognizerNames[0], startTimeMs);
  if (rc != NUANCE_COMMON_OK) {
    printf("ERROR: Failed to add applications\n");
  }
  else
  {
    printf("Added applications: %s to time %d\n", addedApplications, startTimeMs);
  }

  return rc;
}

LH_S32 startDataPreparations(sConfigParameters *config)
{
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;
  size_t i = 0;
  //for (i = 0; i < config->nbrConfiguredDCCs; ++i)
  for (i = 0; i < 1; ++i)
  {
    sDccConfig* dccConfig = &config->dccConfigs[i];

    if (NULL != dccConfig->cop && NULL != g_dcc[i])
    {
      rc = nuance_asr5_IDynamicContentConsumer_startDataPreparationFromCopFile(g_dcc[i], dccConfig->cop);
      if (rc != NUANCE_COMMON_OK) {
        printf("ERROR: Failed to start data preparation from cop file %s for DCC %s\n",
                           dccConfig->cop,
                           dccConfig->name);
        return rc;
      }
    }
    else
    {
      printf("ERROR: No COP file was provided for DCC %s and DCC cop %s, skipping.\n",
                           dccConfig->name,dccConfig->cop);
      continue;
    }

    printf("Started data preparations for: %s and Cop %s\n", dccConfig->name,dccConfig->cop);
  }
  return rc;
}

LH_S32 startRecognition(sConfigParameters *config)
{
  /* Return codes */
  nuance_common_ResultCode rc = NUANCE_COMMON_OK;

  /* Nuance instances */
  nuance_common_ILogging* loggerInstance = nuance_common_ILogging_getInstance();
  nuance_common_IConfiguration *audioConfiguration = 0;
  nuance_audio_IAudioManager *audioMgr = 0;
  nuance_cloudservices_ICloudManager *cloudMgr = 0;
  nuance_common_ISystemManager *systemMgr = 0;
  nuance_common_IConfiguration *asrConfiguration = 0;
  nuance_asr5_IAsrManager *asrManager = 0;
  nuance_asr5_IRecognizer *recognizer = 0;
  nuance_asr5_IRecognizerListener* recognizerListener = 0;
  nuance_audio_IAudioInputAdapterFactory *factory = LH_NULL;
  /* only one audio scenario is supported, which simulates continuous speech */
  const LH_CHAR *audioScenarioName = config->audioList[0];
  TopResult *topResult = 0;
  LH_S32 i = 0;
  ASR_EVENT asrEvent = UNQUALIFIED_RESULT;

  rc = setupAudioAndCloud(config, &audioConfiguration, &systemMgr, &audioMgr, &cloudMgr, &factory);
  if (rc != NUANCE_COMMON_OK)
  {
    return rc;
  }

  rc = setupAsrManager(config, cloudMgr, audioMgr, &asrConfiguration, &asrManager);
  if (rc != NUANCE_COMMON_OK)
  {
    return rc;
  }

  /* setup listeners */
  recognizerListener = nuance_asr5_IRecognizerListener_create(&SampleRecognizerListener_Callbacks, NULL);
  if (NULL == recognizerListener)
  {
    printf("Error: Could not create recognizerListener");
    return NUANCE_COMMON_ERROR;
  }
  rc = setupRecognizer(asrManager, recognizerListener, &recognizer);
  if (rc != NUANCE_COMMON_OK)
  {
    return rc;
  }

  rc = initApplications(config, asrManager);
  if (rc != NUANCE_COMMON_OK)
  {
    return rc;
  }

  rc = initDCCs(config, asrManager);
  if (rc != NUANCE_COMMON_OK)
  {
    return rc;
  }

  rc = startDataPreparations(config);
  if (rc != NUANCE_COMMON_OK)
  {
	  return rc;
  }

  printf("Selecting audio configuration %s\n", audioScenarioName);
  rc = nuance_audio_IAudioManager_activateScenario(audioMgr, audioScenarioName);
  if (NUANCE_COMMON_OK != rc) {
	  printf("Audio scenario activation failed: %d\n", rc);
	  return rc;
  }

  topResult = &g_topResult;
  rc = addApplications(config, asrManager, topResult);
  if (rc != NUANCE_COMMON_OK)
  {
	  return rc;
  }
  nuance_asr5_IRecognizer_start(recognizer);
  printf("Waiting for the Recognizer\n");
  while(1)
  {
    popEvent(&asrEvent);
    printf("While Loop\n");
    if (COMMAND_RESULT == asrEvent)
    {
      stopTimer();
      printf("Recognition stopped\n");
      break;
    }
    else if(WUW_RESULT == asrEvent)
    {
      printf("ASR EVENT\n");
      g_state = AWAKE;
      startTimer(g_timeoutMs);
    }
    else if(INITIAL_TIMEOUT == asrEvent)
    {
      printf("Initial timeout, recognition stopped!\n");
      g_state = ASLEEP;
      break;
    }

    rc = addApplications(config, asrManager, topResult);
    if (rc != NUANCE_COMMON_OK)
    {
      return rc;
    }
  }

  printf("Delete the timer\n");
  /* Clean-up  and Print the Result*/
  deleteTimer();
  nuance_asr5_IRecognizer_stop(recognizer);
  emptyEventList();
  rc = nuance_audio_IAudioManager_deActivateScenario(audioMgr, audioScenarioName);
  if (NUANCE_COMMON_OK != rc) {
    printf("Audio scenario deactivation failed: %d\n", rc);
  }

  if(g_topResult.startRule)
  {
    free(g_topResult.startRule);
    g_topResult.startRule = 0;
  }

  nuance_common_ILogging_flush(loggerInstance);

  if (recognizer)
  {
  nuance_asr5_IRecognizer_destroy(recognizer);
  }
  if (asrConfiguration)
  {
    nuance_common_IConfiguration_destroy(asrConfiguration);
  }
  if (audioConfiguration)
  {
    nuance_common_IConfiguration_destroy(audioConfiguration);
  }
  for(i = 0; i < MAX_NR_APPLICATIONS; i++)
  {
    nuance_asr5_IApplication_destroy(g_applications[i]);
  }
  for(i = 0; i < MAX_NR_DYNAMIC_CONTENT_CONSUMERS; i++)
  {
    nuance_asr5_IDynamicContentConsumer_destroy(g_dcc[i]);
  }
  if (asrManager)
  {
    nuance_asr5_IAsrManager_destroy(asrManager);
  }
  if (audioMgr)
  {
    nuance_audio_IAudioManager_destroy(audioMgr);
  }
  if (cloudMgr)
  {
    nuance_cloudservices_ICloudManager_destroy(cloudMgr);
  }
  if (systemMgr)
  {
    nuance_common_ISystemManager_destroy(systemMgr);
  }

  if(recognizerListener)
  {
    nuance_asr5_IRecognizerListener_destroy(recognizerListener);
  }

  return rc;
}

/**************************************************************************************/

nuance_common_ResultCode init_configuration(void)
{
  int result = 1 ;
  size_t nrElements = 0;
  size_t nrDccConfigs = 0;
  config = &g_config;
  printf("Init Configuration\n"); 
  config->configDir = CONFIGBASEDIR;
  config->audioConfigDir = CONFIGBASEDIR;
  config->nrAudioScenarios = 1;
  config->audioList[0] = AUDIO_SCENARIO_NAME;
  config->asrManagerNames = ASR_NAME;
  config->applicationNames[0] = WUW_APPLICATION_NAME;
  config->applicationNames[1] = COMMAND_APPLICATION_NAME;
  config->recognizerNames[0] = RECOGNIZER_NAME;
  config->nbrConfiguredApplications = 2;
  config->nbrConfiguredRecognizers = 1;

  config->dccConfigs[0].name = DCC_NAME;
  config->dccConfigs[0].cop = COPFILE_NAME;
  config->nbrConfiguredDCCs = 1;
  config->configDir = "../csdk_v2/sample/data/asr/config";
  config->audioConfigDir = "../csdk_v2/sample/data/asr/config";
  config->audioList[nrElements] = "mic";
  config->dccConfigs[nrDccConfigs].name = "DCC_LOCAL_TITLE";
  config->dccConfigs[nrDccConfigs].source = NULL;
  config->dccConfigs[nrDccConfigs].cop = "../csdk_v2/sample/data/asr/config/songs.cop";
  config->dccConfigs[nrDccConfigs].persistExistingContext = LH_FALSE;
  g_wuwApplication.name = config->applicationNames[0];
  return result;

}
nuance_common_ResultCode cerence_thread_init(void) 
{
  g_sem = malloc(mt_semaphore_getinstancesize());
  mt_semaphore_create(g_sem, 0, 5);
  g_mutex = malloc(mt_mutex_getinstancesize());
  mt_mutex_init(g_mutex);
//  init_configuration();
  /* disables error reporting popups on platforms that need it */
  disableErrorReportingPopups();

  nuance_common_ILogging_getInstance();
  
}

nuance_common_ResultCode cerence_configuration_view(void)
{
  size_t i = 0;
  printf(":: Running with parameters:\n");
  printf("    configDir:        %s\n", config->configDir);
  printf("    callbackKeys:     %s\n", g_callbackKeysFilename);
  printf("    dynamicContentConsumer: \n");
  for(i = 0; i < config->nbrConfiguredDCCs; i++)
  {
    if(NULL != config->dccConfigs[i].cop)
    {
      printf("     %s : %s\n", config->dccConfigs[i].name, config->dccConfigs[i].cop);
    }
  }
  for (i = 0; i < config->nrAudioScenarios; i++)
  {
    printf("    audioScenario:  %s\n", config->audioList[i]);
  }
  printf("    asr manager:    %s\n", config->asrManagerNames);
  for (i = 0; i < config->nbrConfiguredApplications; ++i)
  {
    printf("    application[%d]: %s\n", (int)i, config->applicationNames[i]);
  }
  for (i = 0; i < config->nbrConfiguredRecognizers; ++i)
  {
    printf("    recognizer[%d] : %s\n", (int)i, config->recognizerNames[i]);
  }
  printf("    wuwStartRule:        %s\n", g_wuwApplication.startRule);
  printf("    confidenceThreshold: %d\n", g_wuwApplication.confidenceThreshold);
  printf("    initial timeout:     %dms\n", g_timeoutMs);

}

nuance_common_ResultCode cerence_Start_Recognizer(void)
{ 
  int rc = 0;
  cerence_thread_init();
  cerence_configuration_view();
  rc = initTimer();
  if(rc != NUANCE_COMMON_OK)
  {
    return rc;
  }
  rc = startRecognition(config);

  mt_mutex_destroy(g_mutex);
  free(g_mutex);
  mt_semaphore_close(g_sem);
  free(g_sem);
  nuance_common_ILogging_deleteInstance();
  return rc;
}
