/**
 * @file linux_wrapper_cerence.c
 * @author your name (vaibhav.pandey@germanautolabs.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "linux_wrapper.h"
#include <signal.h>
#include <time.h>




#define LINUX_PLATFORM
extern "C"{
#include "ResultCode.h"
#include "lh_types.h"
#ifdef LINUX_PLATFORM
 #include "mt_mutex.h"
 #include "mt_semaphore.h"
/*static MT_SEMAPHORE g_sem;
static MT_MUTEX g_mutex;
size_t mt_semaphore_getinstancesize(void);
int mt_mutex_init(MT_MUTEX mutex);
int mt_mutex_destroy(MT_MUTEX mutex);
int mt_mutex_lock(MT_MUTEX mutex);
int mt_mutex_unlock(MT_MUTEX mutex);
size_t mt_mutex_getinstancesize(void);*/




#endif	
nuance_common_ResultCode cerence_initconfig(sConfigParameters g_config);



}

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

/* -------------------------------------------------------------------------+
 | Local Application Settings for Linux|
 + -------------------------------------------------------------------------*/
static MT_SEMAPHORE g_sem;
static MT_MUTEX g_mutex;
static timer_t timerid;
static LH_S32 g_timeoutMs = 2000;
/* -------------------------------------------------------------------------+
 | Local Functions
 + -------------------------------------------------------------------------*/
static void liwr_threadInit(void);

int main(int argc, char *argv[])
{
   int result = 0;
   result = liwr_initConfig();
   std::cout<<"Result of liwr_initconig"<<result<<"\n";
   if(result != 0)
   {
       liwr_initConfig();
   }
  return 0;
}

int liwr_initConfig(void)
{
    
    int result = 1 ;
    size_t nrElements = 0;
    size_t nrDccConfigs = 0;
    sLinuxConfigParameters* config;
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
    config->configDir = "../Cerence-V2-SDK/sample/data/asr/config";
    config->audioConfigDir = "../Cerence-V2-SDK/sample/data/asr/config";
    config->audioList[nrElements] = "mic";
    config->dccConfigs[nrDccConfigs].name = "DCC_LOCAL_TITLE";
    config->dccConfigs[nrDccConfigs].source = NULL;
    config->dccConfigs[nrDccConfigs].cop = "../Cerence-V2-SDK/sample/data/asr/config/songs.cop";
    config->dccConfigs[nrDccConfigs].persistExistingContext = LH_FALSE;
    g_wuwApplication.name = config->applicationNames[0];
    std::cout<<"Init Configuration\n";
    result = cerence_initconfig(&config);
    if(result != 0)
    {
      result = liwr_threadInit(void);
    }

    return result;
}


int liwr_startRecogniser(void)
{
    int result = 0;
    result = initTimer();
    if(rc != NUANCE_COMMON_OK)
    {
      return rc;
    }
    result = cerence_Start_Recognizer();
    liwr_threadDestroy();
    return result;
}


static void liwr_threadInit(void)
{
    cout<<"Thread Initialize\n";
    g_sem = malloc(mt_semaphore_getinstancesize());
    mt_semaphore_create(g_sem, 0, 5);
    g_mutex = malloc(mt_mutex_getinstancesize());
    mt_mutex_init(g_mutex);
   
}

static void liwr_threadDestroy(void)
{
    cout<<"Thread Destroy\n";
    mt_mutex_destroy(g_mutex);
    free(g_mutex);
    mt_semaphore_close(g_sem);
    free(g_sem);
}



void initialTimeoutCallback() {
  /* when initial timeout happens, terminate the recognition */
    std::cout<<"Command should be within %dms after wake-up word for one-shot wuw case!"<< g_timeoutMs<<"\";
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
       std::cout<<"ERROR: initTimer failed.\n";
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
        std::cout<<"ERROR: startTimer failed.\n";
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
	std::cout<<"ERROR: stopTimer failed.\n";
        rc = NUANCE_COMMON_ERROR;
     }

     return rc;
}

nuance_common_ResultCode deleteTimer()
{
     nuance_common_ResultCode rc = NUANCE_COMMON_OK;

     return rc;
}

