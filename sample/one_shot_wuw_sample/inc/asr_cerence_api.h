/**
 * @file asr_cerence_api.h
 * @author your name (vaibhav.pandey@germanautolabs.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "ILogging.h"
#include "IConfiguration.h"
#include "IAudioManager.h"
#include "ICloudManager.h"
#include "ISystemManager.h"
#include "IAudioInput.h"
#include "IAudioFromFile.h"
#include "customInputAdapterFactory.h"
#include "IAsrManager.h"
#include "IRecognizer.h"
#include "IApplication.h"
#include "IDynamicContentConsumer.h"
#include "ResultCode.h"
#include "cJSON.h"
#include "mt_mutex.h"
#include "mt_semaphore.h"

/*Linux  Platform based */
#include <signal.h>
#include <time.h>


/* -------------------------------------------------------------------------+
 |   DEFINES                                             |
 + -------------------------------------------------------------------------*/
#define CONFIGBASEDIR "../test_data/samples/c_one_shot_wuw_sample"
#define MAX_NR_AUDIOSCENARIOS                1
#define MAX_NR_DYNAMIC_CONTENT_CONSUMERS   40
#define MAX_PATH_LENGTH                    255
#define MAX_NR_APPLICATIONS                10
#define MAX_NR_RECOGNIZERS                 1

/*Linux  Platform based */
#define CLOCKID CLOCK_REALTIME
#define SIG SIGRTMIN

/* -------------------------------------------------------------------------+
 |   Linux Based Functions with Dependecy on Cerence                                             |
 + -------------------------------------------------------------------------*/
nuance_common_ResultCode initTimer();
nuance_common_ResultCode startTimer(LH_S32 timeoutMs);
nuance_common_ResultCode stopTimer();
nuance_common_ResultCode deleteTimer();

/* -------------------------------------------------------------------------+
 |   Global Functions                                             |
 + -------------------------------------------------------------------------*/
nuance_common_ResultCode init_configuration(void);
nuance_common_ResultCode cerence_thread_init(void);
nuance_common_ResultCode cerence_configuration_view(void);
nuance_common_ResultCode cerence_Start_Recognizer(void);

