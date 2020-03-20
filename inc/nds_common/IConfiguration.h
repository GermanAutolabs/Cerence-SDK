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
 *  Declaration of nuance_common_IConfiguration class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IConfiguration
 *  @{
 *  @file IConfiguration.h
 *
 *  @brief  Class for exchanging configuration data <p>
 *  This class is used to read a set of JSON files which contain the configuration of DragonDrive framework / Companion SDK
 *  components. The JSON files are expected to have format UTF-8 (with or without byte order marker (BOM)).The IConfiguration object can be passed to the constructor methods of IRecognizer, IPrompter,
 *  IBiometry and can be used to configure the ISystemManager, IAudioManager or ICloudManager.
 */

#ifndef NUANCE_COMMON_ICONFIGURATION_H
#define NUANCE_COMMON_ICONFIGURATION_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Class for exchanging configuration data <p>
 *  This class is used to read a set of JSON files which contain the configuration of DragonDrive framework / Companion SDK
 *  components. The JSON files are expected to have format UTF-8 (with or without byte order marker (BOM)).The IConfiguration object can be passed to the constructor methods of IRecognizer, IPrompter,
 *  IBiometry and can be used to configure the ISystemManager, IAudioManager or ICloudManager.
 */
struct _nuance_common_IConfiguration;
/**
 *  @brief  Class for exchanging configuration data <p>
 *  This class is used to read a set of JSON files which contain the configuration of DragonDrive framework / Companion SDK
 *  components. The JSON files are expected to have format UTF-8 (with or without byte order marker (BOM)).The IConfiguration object can be passed to the constructor methods of IRecognizer, IPrompter,
 *  IBiometry and can be used to configure the ISystemManager, IAudioManager or ICloudManager.
 */
typedef struct _nuance_common_IConfiguration nuance_common_IConfiguration;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "IApplicationCallback.h"
#include "ResultCode.h"
#include "StringList.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Create a new IConfiguration object
 *
 *  @param[in]     configDir   a directory from which the JSON configuration files are loaded
 *  @param[in]     appCb       interface implemented by the application, used to lookup dynamic parts of the configuration
 *  @param[out]    config      The IConfiguration instance created
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IConfiguration_create
(
    const LH_CHAR *configDir,
    nuance_common_IApplicationCallback *appCb,
    nuance_common_IConfiguration **config
);


/**
 *  Create a new IConfiguration object
 *
 *  @param[in]     configDir   a directory from which the JSON configuration files are loaded
 *  @param[in]     appCb       interface implemented by the application, used to lookup dynamic parts of the configuration
 *  @param[in]     validate    If true validation will be done and problems will be reported in the log. Result will not be affected by semantic part of validation.
 *  @param[out]    config      The IConfiguration instance created
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IConfiguration_createWithValidation
(
    const LH_CHAR *configDir,
    nuance_common_IApplicationCallback *appCb,
    LH_BOOL validate,
    nuance_common_IConfiguration **config
);


/**
 *  Create a new IConfiguration object out of a list of JSON strings
 *
 *  @param[in]     configStrings   a list of JSON formated configuration strings
 *  @param[in]     nconfigStrings  Number of elements in configStrings
 *  @param[in]     appCb           interface implemented by the application, used to lookup dynamic parts of the configuration
 *  @param[in]     baseDir         the base directory used for all file operations of the configured modules
 *  @param[out]    config          the created IConfiguration instance
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IConfiguration_createFromString
(
    const LH_CHAR * const *configStrings, LH_S32 nconfigStrings,
    nuance_common_IApplicationCallback *appCb,
    const LH_CHAR *baseDir,
    nuance_common_IConfiguration **config
);


/**
 *  Create a new IConfiguration object out of a list of JSON strings
 *
 *  @param[in]     configStrings   a list of JSON formated configuration strings
 *  @param[in]     nconfigStrings  Number of elements in configStrings
 *  @param[in]     appCb           interface implemented by the application, used to lookup dynamic parts of the configuration
 *  @param[in]     baseDir         the base directory used for all file operations of the configured modules
 *  @param[in]     validate        If true validation will be done and problems will be reported in the log. Result will not be affected by semantic part of validation.
 *  @param[out]    config          the created IConfiguration instance
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IConfiguration_createFromStringWithValidation
(
    const LH_CHAR * const *configStrings, LH_S32 nconfigStrings,
    nuance_common_IApplicationCallback *appCb,
    const LH_CHAR *baseDir,
    LH_BOOL validate,
    nuance_common_IConfiguration **config
);


/**
 *  Create a new IConfiguration object from a list of files given by name, files may be in text or binary format. The file type is independent of the name, but detected during read.
 *
 *  @param[in]     baseDir       the path used  as base directory for all relative path operations (I.e. all paths mentioned in the JSON files, and for the relative file names provided to this method.)
 *  @param[in]     configFiles   a list of filenames (can be absolute (i.e. starting with / or [A-Za-z]:[/\] ) or relative to baseDir) containing the JSON configuration.
 *  @param[in]     nconfigFiles  Number of elements in configFiles
 *  @param[in]     appCb         interface implemented by the application, used to lookup dynamic parts of the configuration
 *  @param[out]    config        the created IConfiguration instance
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IConfiguration_createFromFiles
(
    const LH_CHAR *baseDir,
    const LH_CHAR * const *configFiles, LH_S32 nconfigFiles,
    nuance_common_IApplicationCallback *appCb,
    nuance_common_IConfiguration **config
);


/**
 *  Create a new IConfiguration object from a list of files given by name, files may be in text or binary format. The file type is independent of the name, but detected during read.
 *
 *  @param[in]     baseDir       the path used  as base directory for all relative path operations (I.e. all paths mentioned in the JSON files, and for the relative file names provided to this method.)
 *  @param[in]     configFiles   a list of filenames (can be absolute (i.e. starting with / or [A-Za-z]:[/\] ) or relative to baseDir) containing the JSON configuration.
 *  @param[in]     nconfigFiles  Number of elements in configFiles
 *  @param[in]     appCb         interface implemented by the application, used to lookup dynamic parts of the configuration
 *  @param[in]     validate      If true validation will be done and problems will be reported in the log. Result will not be affected by semantic part of validation.
 *  @param[out]    config        The IConfiguration instance created
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IConfiguration_createFromFilesWithValidation
(
    const LH_CHAR *baseDir,
    const LH_CHAR * const *configFiles, LH_S32 nconfigFiles,
    nuance_common_IApplicationCallback *appCb,
    LH_BOOL validate,
    nuance_common_IConfiguration **config
);


/**
 *  @brief  Returns the versions for the common component. <p>
 *  Note: The underlying PAL component module does not support version providing yet. Temporarily this versions is reported as "unknown".
 *
 *  @param[out]    version          The product version the common component is part of.
 *  @param[out]    moduleVersions   Versions of the common modules [PAL].                           Index 0 = PAL.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IConfiguration_getVersions
(
    nuance_common_String **version,
    nuance_common_StringList **moduleVersions
);


/**
 *  Set status of validation flag, default is false, returns previous value.
 *
 *  @param[in]     validate   true if JSON should be validated semantically
 *
 */
COMMON_C_EXPORT LH_BOOL nuance_common_IConfiguration_setValidation(LH_BOOL validate);


/**
 *  Retrieve status of validation flag.
 *
 */
COMMON_C_EXPORT LH_BOOL nuance_common_IConfiguration_getValidation();


/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_IConfiguration_destroy(nuance_common_IConfiguration *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_ICONFIGURATION_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
