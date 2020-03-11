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
 *  Declaration of nuance_asr5_IApplication class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5  nuance_asr5
 *  @{
 *  @addtogroup IApplication
 *  @{
 *  @file IApplication.h
 *
 */

#ifndef NUANCE_ASR5_IAPPLICATION_H
#define NUANCE_ASR5_IAPPLICATION_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

struct _nuance_asr5_IApplication;
typedef struct _nuance_asr5_IApplication nuance_asr5_IApplication;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "asr5_api_defs.h"

/* API types */
#include "IApplicationListener.h"
#include "IAsrManager.h"
#include "ResultCode.h"
#include "StringList.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief create a application<p>
 *  Creates a new application instance. Each application gets an unique name.
 *  \n
 *
 *  @param[in]     asr5Manager   the asr manager object
 *  @param[in]     name          name of the application
 *  @param[in]     listener      an \ref IApplicationListener implementation which is used to report errors and warnings of the application object.
 *  @param[out]    application   the new \ref IApplication object
 *
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IApplication_create
(
    nuance_asr5_IAsrManager *asr5Manager,
    const LH_CHAR *name,
    nuance_asr5_IApplicationListener *listener,
    nuance_asr5_IApplication **application
);


/**
 *  @brief  Adds a named configuration object to the application. <p>
 *
 *  <p>Allows the application to add or update a named configuration at run-time.</p>
 *
 *  <p>
 *  It is possible to add or update a configuration by providing its type ("input", etc.) and name ("INPUT_NAME", etc.).
 *  The configuration with 'config' parameter by passing JSON configuration string.
 *  The JSON structure shall follow the VoConHigh JSON configuration schema. refer to
 *  - "post_processor": IPostProcessorConfig
 *  - "input": IBaseInputConfig, currently only support "asr" type.
 *  </p>
 *
 *  <p>
 *  NOTE: Currently supports "post_processor", "input" types,
 *  and for "input", only support adding "asr" type at run-time.
 *  </p>
 *  </p>
 *
 *  @param[in,out] instance      The instance pointer
 *  @param[in]     type          the type of the configuration element to add.
 *  @param[in]     namesList     the name of the configuration element to add.
 *  @param[in]     nnamesList    Number of elements in namesList
 *  @param[in]     configsList   the new configurations to be added/updated.
 *  @param[in]     nconfigsList  Number of elements in configsList
 *
 *  @return Result code
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IApplication_add
(
    nuance_asr5_IApplication *instance,
    const LH_CHAR *type,
    const LH_CHAR * const *namesList, LH_S32 nnamesList,
    const LH_CHAR * const *configsList, LH_S32 nconfigsList
);


/**
 *  @brief  Adds multiple named configuration objects to the defined locations in the configuration. <p>
 *
 *  <p>Allows the application to add multiple named configuration objects at run-time with the paths which define the positions of these objects.</p>
 *
 *  <p>
 *  It is possible to add multiple configuration objects by providing the type ("search", etc.), the list of names and the list of paths.
 *  The configurations need to be added to the configuration directory.
 *  </p>
 *
 *  <p>
 *  Optionally, it is also possible to add or update the configuration of the objects with 'config' parameter by passing JSON configuration string.
 *  The JSON structure shall follow the VoConHigh JSON configuration schema.refer to
 *  - "search": IBaseSearchConfig
 *  - "search_filter": ISearchFilterConfig
 *  - "sem3_data": ISem3AdditionalDataConfig
 *  - "sem3_data_configuration": ISem3AdditionalDataConfigurationConfig
 *  - "sem3_filter": ISem3FilterConfig
 *  </p>
 *
 *  <p>NOTE: Currently supports only "search", "search_filter", "sem3_data", "sem3_data_configuration", "sem3_filter" types</p>
 *
 *  @param[in,out] instance      The instance pointer
 *  @param[in]     type          the type of the configuration element to add.
 *  @param[in]     namesList     the name of the configuration element to add.
 *  @param[in]     nnamesList    Number of elements in namesList
 *  @param[in]     pathsList     the paths where the elements should be added.
 *  @param[in]     npathsList    Number of elements in pathsList
 *  @param[in]     configsList   the configurations to be added/updated.
 *  @param[in]     nconfigsList  Number of elements in configsList
 *
 *  @return Result code
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IApplication_addWithPath
(
    nuance_asr5_IApplication *instance,
    const LH_CHAR *type,
    const LH_CHAR * const *namesList, LH_S32 nnamesList,
    const LH_CHAR * const *pathsList, LH_S32 npathsList,
    const LH_CHAR * const *configsList, LH_S32 nconfigsList
);


/**
 *  @brief  Generates multiple configuration objects and adds them to the defined locations in the configuration. <p>
 *
 *  <p>Allows the application to add multiple objects based on the files only at run-time.</p>
 *
 *  <p>
 *  It is possible to add multiple objects by providing the type ("search", etc.) and a file names or paths.
 *  The top level configurations will be generated and added internally.
 *  </p>
 *
 *  <p>NOTE: Currently supports only "search" and "sem3_data" types</p>
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     type         the type of the configuration element to add.
 *  @param[in]     namesList    the file names or file paths of the configuration elements to add.
 *  @param[in]     nnamesList   Number of elements in namesList
 *  @param[in]     isFilePath   file name or file path is used
 *  @param[in]     pathsList    the paths where the elements should be added.
 *  @param[in]     npathsList   Number of elements in pathsList
 *
 *  @return Result code
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IApplication_addFilesWithPath
(
    nuance_asr5_IApplication *instance,
    const LH_CHAR *type,
    const LH_CHAR * const *namesList, LH_S32 nnamesList,
    LH_BOOL isFilePath,
    const LH_CHAR * const *pathsList, LH_S32 npathsList
);


/**
 *  @brief  Removes multiple named configuration objects from the configuration. <p>
 *
 *  <p>Allows the application to remove multiple named configuration objects at run-time.</p>
 *
 *  <p>
 *  It is possible to remove multiple configuration objects by providing their type ("domain", etc.) and name list ("MUSIC", etc.).
 *  The configuration objects will be removed from memory.
 *  </p>
 *
 *  <p>NOTE: Currently supports only "search", "data" and "search_filter" types</p>
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     type        the type of the configuration element to remove.
 *  @param[in]     namesList   the names list of the configuration elements to be removed.
 *  @param[in]     nnamesList  Number of elements in namesList
 *
 *  @return Result code
 */
ASR5_C_EXPORT nuance_common_ResultCode nuance_asr5_IApplication_remove
(
    nuance_asr5_IApplication *instance,
    const LH_CHAR *type,
    const LH_CHAR * const *namesList, LH_S32 nnamesList
);


/**
 *  Destructor
 */
ASR5_C_EXPORT void nuance_asr5_IApplication_destroy(nuance_asr5_IApplication *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_IAPPLICATION_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
