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

typedef struct
{
  const char* name;
  const char* source;
  const char* cop;
  LH_BOOL persistExistingContext;
} sLinuxDccConfig;

typedef struct
{
  const char* configDir;
  const char* audioConfigDir;
  const char* audioList[MAX_NR_AUDIOSCENARIOS];
  const char* asrManagerNames;
  const char* applicationNames[MAX_NR_APPLICATIONS];
  const char* recognizerNames[MAX_NR_RECOGNIZERS];
  sLinuxDccConfig dccConfigs[MAX_NR_DYNAMIC_CONTENT_CONSUMERS];
  size_t nrAudioScenarios;
  size_t nbrConfiguredApplications;
  size_t nbrConfiguredRecognizers;
  size_t nbrConfiguredDCCs;
} sLinuxConfigParameters;


