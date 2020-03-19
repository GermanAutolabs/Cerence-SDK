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
 *  Declaration of nuance_common_ILogging class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup ILogging
 *  @{
 *  @file ILogging.h
 *
 *  @brief Interface to access exposed methods of the logger object.<p>
 */

#ifndef NUANCE_COMMON_ILOGGING_H
#define NUANCE_COMMON_ILOGGING_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief Interface to access exposed methods of the logger object.<p>
 */
struct _nuance_common_ILogging;
/**
 *  @brief Interface to access exposed methods of the logger object.<p>
 */
typedef struct _nuance_common_ILogging nuance_common_ILogging;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "ILogConsumer.h"
#include "ILogModule.h"
#include "LogZone.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  Returns a pointer to the ILogging object of the framework.
 *  This interface can be used to register user-specific log message consumers.
 *
 */
COMMON_C_EXPORT nuance_common_ILogging *nuance_common_ILogging_getInstance();


/**
 *  Use this function to gracefully shutdown the logging thread and destroy the ILogging object.
 *  It should be called only when the logging is no longer needed, for example, when the application is
 *  about to end. When this function returns the logging queue will be flushed to the configured consumers,
 *  logger thread finished and all the memory used by this object will be released. Note that calling
 *  nuance_common_ILogging_getInstance() or generally trying to log any content afterwards will create a new
 *  logger object which may result in the previous log files to be overwritten. It is therefore important
 *  for the application to ensure that none of the active threads try to log messages once
 *  nuance_common_ILogging_deleteInstance() has been executed.
 */
COMMON_C_EXPORT void nuance_common_ILogging_deleteInstance();


/**
 *  Registers a new log message consumer.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     consumerName   name of the consumer
 *  @param[in]     consumer       an implementation of the ILogConsumer interface
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ILogging_addConsumer
(
    nuance_common_ILogging *instance,
    const LH_CHAR *consumerName,
    nuance_common_ILogConsumer *consumer
);


/**
 *  Unregisters a log message consumer.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     consumerName   name of the consumer
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ILogging_removeConsumer
(
    nuance_common_ILogging *instance,
    const LH_CHAR *consumerName
);


/**
 *  @brief  Configures / Reconfigures a log message consumer at runtime. <p>
 *
 *  If this method is called before the json configuration is loaded it is expected
 *  that the consumer named with parameter \a consumerName was added before using the
 *  \a addConsumer method. Than it is no longer possible to configure this specific
 *  consumer via json, but it is still possible to update its configuration by calling
 *  this method again.
 *
 *  If this method is called after the json configuration is loaded a pre-configuration
 *  of a log consumer done in the json file can be updated.
 *
 *  Consumers which are not present can not be configured.
 *
 *  Please provide \a LH_NULL for the parameters you don't want to change. Content of the
 *  parameters passed-on is interpreted in the same manner as in the json configuration
 *  file and it will overwrite the previous settings for the parameter.
 *
 *  F.i. if \a zones was set to: \a "LOG_INFO" and this calls new value is \a "LOG_ERROR|LOG_FATAL"
 *  only the messages for those two new zones will be redirected after changing the configuration
 *  to the \a consumerName. The \a "LOG_INFO" messages will be skipped for this consumer then.
 *
 *  The output parameter for the consumers added externally with the \a addConsumer function
 *  cannot be changed. If this is attempted then error will be returned in the result code.
 *
 *  DISCLAIMER: In the DDFW context the \a "DDCOMMON_LOGGER_VALUE_UNCHANGED" string constant
 *  has to be used for the parameters that shall not be changed. In addition, the above mentioned
 *  \a addConsumer function is not available in the DDFW. Furthermore, a description of possible
 *  values of the \a configureConsumer function parameters can be found in the \a ILoggingConsumerConfig
 *  section of the \a DDFW_CommonService_UserGuide document.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     consumerName   The name of the consumer. Parameter is required.
 *  @param[in]     output         The place to store the log output.
 *  @param[in]     modules        The modules to log.
 *  @param[in]     not_modules    The modules not to log.
 *  @param[in]     zones          The logging zones for which log output should be collected.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ILogging_configureConsumer
(
    nuance_common_ILogging *instance,
    const LH_CHAR *consumerName,
    const LH_CHAR *output,
    const LH_CHAR *modules,
    const LH_CHAR *not_modules,
    const LH_CHAR *zones
);


/**
 *  Registers a user-defined log consumer object that implements \a ILogConsumer interface that will be used only in
 *  the context when the configuration failed and the logging is not yet initialized or if no consumers are configured.
 *  For example, \a nuance_common_IConfiguration_create() may fail if non-existing configuration folder is
 *  passed as an argument, if application doesn't have required privileges to the given folder, if there are syntax
 *  error(s) in JSON files, etc. When the call to \a nuance_common_IConfiguration_create() fails it may be the case that
 *  the logger is not yet configured or it will never be configured. To enable diagnostics in such cases \a ILogging object
 *  will use this fall-back consumer and flush the messages to it with the zones configured as:
 *  \a "LOG_FATAL|LOG_ERROR|LOG_WARNING|LOG_PERFORMANCE_WARNING" to keep the log output concise. If the fall-back consumer
 *  is not at all registered (meaning this function is never called) then \a ILogging object will use built-in log consumer
 *  that writes the messages to the standard-error console. Only one fall-back consumer can be registered by the application.
 *  This function should be called before any \a nuance_common_IConfiguration_create() calls.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     consumer   an implementation of the ILogConsumer interface
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ILogging_addFallbackConsumer
(
    nuance_common_ILogging *instance,
    nuance_common_ILogConsumer *consumer
);


/**
 *  Creates log module with the given name as identifier.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     moduleName   The name of the logging module. Parameter is required.
 *  @param[out]    logModule    Instance of the created log module object.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ILogging_createLogModule
(
    nuance_common_ILogging *instance,
    const LH_CHAR *moduleName,
    nuance_common_ILogModule **logModule
);


/**
 *  Logs plain text messages inside DD SDK logging system.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     logModule   Log module object previously created with createLogModule() function.
 *  @param[in]     zone        The logging zone this log content belongs to.
 *  @param[in]     text        Text to log.
 *  @param[in]     fileName    Source code file name. Pass 0 if not used.
 *  @param[in]     fileLine    Source code line number. Pass 0 if not used.
 */
COMMON_C_EXPORT void nuance_common_ILogging_logText
(
    nuance_common_ILogging *instance,
    const nuance_common_ILogModule *logModule,
    nuance_common_LogZone zone,
    const LH_CHAR *text,
    const LH_CHAR *fileName,
    LH_S32 fileLine
);


/**
 *  Logs binary data messages inside DD SDK logging system.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     logModule   Log module object previously created with createLogModule() function.
 *  @param[in]     zone        The logging zone this log content belongs to.
 *  @param[in]     data        Binary data to log.
 *  @param[in]     size        Binary data size in bytes.
 *  @param[in]     lastBlock   This flag is used to indicate the end of a log unit, e.g. audio data of one recognition.
 */
COMMON_C_EXPORT void nuance_common_ILogging_logData
(
    nuance_common_ILogging *instance,
    const nuance_common_ILogModule *logModule,
    nuance_common_LogZone zone,
    const LH_CHAR *data,
    LH_S32 size,
    LH_BOOL lastBlock
);


/**
 *  This function blocks until all text and data log messages prior to this call are dispatched to the corresponding consumers.
 *
 *  @param[in,out] instance The instance pointer
 */
COMMON_C_EXPORT void nuance_common_ILogging_flush(nuance_common_ILogging *instance);


/**
 *  @brief Initialize a named counter with the given limit.
 *
 *  Used for supporting the "counted" log macros, which will
 *  limit the number of messages in the log to a fixed number.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     counter   Unique counter name.
 *  @param[in]     limit     Log message limit for this counter.
 */
COMMON_C_EXPORT void nuance_common_ILogging_createCounter
(
    nuance_common_ILogging *instance,
    const LH_CHAR *counter,
    LH_S32 limit
);


/**
 *  @brief Increase the named counter by one, return true if
 *  still under limit.
 *
 *  Used for supporting the "counted" log macros, which will
 *  limit the number of messges in the log to a fixed number.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     counter   Counter name.
 *
 */
COMMON_C_EXPORT LH_BOOL nuance_common_ILogging_count
(
    nuance_common_ILogging *instance,
    const LH_CHAR *counter
);


/**
 *  @brief Finalize a named counter.
 *
 *  this will remove the counter from the internal data
 *  strctures and if the limit was exceeded a log entry will be
 *  printed showing how many messages where suppressed.
 *
 *  Used for supoprting the "counted" log macros, which will
 *  limit the number of messges in the log to a fixed number.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     counter   Counter name.
 *
 */
COMMON_C_EXPORT LH_S32 nuance_common_ILogging_finalizeCounter
(
    nuance_common_ILogging *instance,
    const LH_CHAR *counter
);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_ILOGGING_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
