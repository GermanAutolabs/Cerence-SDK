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
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup ILogConsumerPlugin
 *  @{
 *  @file ILogConsumerPlugin.h
 *  
 *  @brief  Logging consumer plugin interface. <p>
 *
 */

#ifndef NUANCE_COMMON_ILOGCONSUMERPLUGIN_H
#define NUANCE_COMMON_ILOGCONSUMERPLUGIN_H

#ifdef __cplusplus
extern "C" {
#endif

/*** Includes *********************************************************************************************************/

#include "lh_types.h"
#include "ResultCode.h"
#include "LogZone.h"

/*** Defines **********************************************************************************************************/

// plugin API version definition
#define NUANCE_COMMON_ILOGCONSUMERPLUGIN_VERSION "1.0.0"

// plugin export symbol name definitions
#define NUANCE_COMMON_ILOGCONSUMERPLUGIN_GET_API_VERSION "pluginGetApiVersion"
#define NUANCE_COMMON_ILOGCONSUMERPLUGIN_API_FCT_PTRS "pluginApiFctPtrs"

/*** Functions ********************************************************************************************************/

/**
 *  @brief  Returns the version of this interface. <p>
 *
 *  This function has to return the \a NUANCE_COMMON_ILOGCONSUMERPLUGIN_VERSION version string
 *  defined in this header file. This version information is used for compatibility verification.
 *
 *  This function doesn't have to be thread safe.
 *  
 *  This function has to be exported as a symbol under the name defined in
 *  \a NUANCE_COMMON_ILOGCONSUMERPLUGIN_GET_API_VERSION.
 */
typedef const LH_CHAR *(*FUNC_nuance_common_ILogConsumerPlugin_getApiVersion)(void);

/**
 *  @brief  Initializes a logging consumer instance. <p>
 *  
 *  This function has to create a new instance of this logging consumer.
 *  
 *  This function doesn't have to be thread safe.
 *  
 *  This function shall not be exported as a symbol, \sa nuance_common_ILogConsumerPlugin_ApiFctPtrs.
 *
 *  @param[in]     instanceName  A name for this logging consumer instance. Can be used f.i.
 *                               to log consumer internal errors.
 *  @param[in/out] instance      A reference to the instance pointer of this logging consumer.
 */
typedef nuance_common_ResultCode (*FUNC_nuance_common_ILogConsumerPlugin_init)(const LH_CHAR *instanceName, void **instance);

/**
 *  @brief  Configures a logging consumer instance. <p>
 *  
 *  This function configures a logging consumer instance with a specific configuration string parameter
 *  in JSON format. The possible content of the JSON string depends on the configuration parameters this
 *  specific logging consumer supports.
 *
 *  This function is called right after a call to \a init().
 *
 *  This function doesn't have to be thread safe.
 *  
 *  This function shall not be exported as a symbol, \sa nuance_common_ILogConsumerPlugin_ApiFctPtrs.
 *  
 *  @param[in] instance  The instance pointer of this logging consumer.
 *  @param[in] params    Logging consumer specific configuration parameter json string (may be a null pointer).
 */
typedef nuance_common_ResultCode (*FUNC_nuance_common_ILogConsumerPlugin_configure)(void *instance, const LH_CHAR *params);

/**
 *  @brief  Writes a logging message of text type to this logging consumer instance. <p>
 *
 *  This function may be only called in configured state of the logging consumer, otherwise an error has
 *  to be returned.
 *
 *  This function doesn't have to be thread safe.
 *
 *  This function shall not be exported as a symbol, \sa nuance_common_ILogConsumerPlugin_ApiFctPtrs.
 *
 *  @param[in] instance   The instance pointer of this logging consumer.
 *  @param[in] timestamp  Time when the log message was created in ms.
 *  @param[in] thread     Name or ID of the thread which created the message.
 *  @param[in] module     Name of the module which created the log message.
 *  @param[in] zone       The message type, e.g. ERROR, INFO, EXTERNAL_FUNC.
 *  @param[in] msg        The log message.
 */
typedef nuance_common_ResultCode (*FUNC_nuance_common_ILogConsumerPlugin_logText)
(
  void *instance,
  LH_S64 timestamp,
  const LH_CHAR *thread,
  const LH_CHAR *module,
  nuance_common_LogZone zone,
  const LH_CHAR *msg
);

/**
 *  @brief  Writes a logging message of data type to this logging consumer instance. <p>
 *
 *  This function may be only called in configured state of the logging consumer, otherwise an error has
 *  to be returned.
 *
 *  This function doesn't have to be thread safe.
 *
 *  This function shall not be exported as a symbol, \sa nuance_common_ILogConsumerPlugin_ApiFctPtrs.
 *
 *  @param[in] instance    The instance pointer of this logging consumer.
 *  @param[in] timestamp   Time when the log data was created in ms.
 *  @param[in] module      Name of the module which created the log data.
 *  @param[in] zone        The message type, e.g. ERROR, INFO, EXTERNAL_FUNC
 *  @param[in] data        Binary data to log.
 *  @param[in] size        Binary data size in bytes.
 *  @param[in] lastBlock   This flag is used to indicate the end of a log unit,
 *                         e.g. audio data of a recognition.
 */
typedef nuance_common_ResultCode (*FUNC_nuance_common_ILogConsumerPlugin_logData)
(
  void *instance,
  LH_S64 timestamp,
  const LH_CHAR *module,
  nuance_common_LogZone zone,
  const LH_CHAR *data,
  LH_S32 size,
  LH_BOOL lastBlock
);

/**
 *  @brief  Performs a flush action at this logging consumer instance. <p>
 *
 *  This function is called when the logging content received by this logging consumer shall be
 *  flushed to the corresponding destination.
 *
 *  This function may be only called in configured state of the logging consumer, otherwise an error has
 *  to be returned.
 *
 *  This function doesn't have to be thread safe.
 *  
 *  This function shall not be exported as a symbol, \sa nuance_common_ILogConsumerPlugin_ApiFctPtrs.
 *
 *  @param[in] instance The instance pointer of this logging consumer.
 */
typedef nuance_common_ResultCode (*FUNC_nuance_common_ILogConsumerPlugin_flush)(void *instance);

/**
 *  @brief  Returns a textual description of the last logging consumer instance error occurred. <p>
 *
 *  In case no last error is available an empty string shall be returned.
 *
 *  This function may be called in any state of the logging consumer.
 *  
 *  This function doesn't have to be thread safe.
 *
 *  This function shall not be exported as a symbol, \sa nuance_common_ILogConsumerPlugin_ApiFctPtrs.
 *
 *  @param[in] instance The instance pointer of this logging consumer.
 *
 */
typedef const LH_CHAR *(*FUNC_nuance_common_ILogConsumerPlugin_getErrorText)(const void *instance);

/**
 *  @brief  De-initializes a logging consumer instance. <p>
 * 
 *  This function has to free all resources occupied by this logging consumer instance. After successful
 *  de-initialization the instance pointer parameter has to be set to null. This function is the last call
 *  to a specific instance.
 * 
 *  This function doesn't have to be thread safe.
 *  
 *  This function shall not be exported as a symbol, \sa nuance_common_ILogConsumerPlugin_ApiFctPtrs.
 *
 *  @param[in/out] instance  A reference to the instance pointer of this logging consumer.
 */
typedef nuance_common_ResultCode (*FUNC_nuance_common_ILogConsumerPlugin_deInit)(void **instance);

/*** Data Types *******************************************************************************************************/

/**
 *  @brief  Logging consumer plugin interface function pointer data structure. <p>
 *  
 *  A global variable of this data type has to be exported as a symbol under the name defined in
 *  \a NUANCE_COMMON_ILOGCONSUMERPLUGIN_API_FCT_PTRS. The variable has to be initialized with the
 *  function pointers of the functions implementing this logging consumer plugin interface.
 */
struct _nuance_common_ILogConsumerPlugin_ApiFctPtrs{
  FUNC_nuance_common_ILogConsumerPlugin_init init;
  FUNC_nuance_common_ILogConsumerPlugin_configure configure;
  FUNC_nuance_common_ILogConsumerPlugin_logText logText;
  FUNC_nuance_common_ILogConsumerPlugin_logData logData;
  FUNC_nuance_common_ILogConsumerPlugin_flush flush;
  FUNC_nuance_common_ILogConsumerPlugin_getErrorText getErrorText;
  FUNC_nuance_common_ILogConsumerPlugin_deInit deInit;
};
typedef struct _nuance_common_ILogConsumerPlugin_ApiFctPtrs nuance_common_ILogConsumerPlugin_ApiFctPtrs;

#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_ILOGCONSUMERPLUGIN_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
