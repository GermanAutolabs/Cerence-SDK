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
 *  Declaration of nuance_common_ILogConsumer class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup ILogConsumer
 *  @{
 *  @file ILogConsumer.h
 *
 *  @brief  Abstract interface implemented by the customer to receive log messages. <p>
 */

#ifndef NUANCE_COMMON_ILOGCONSUMER_H
#define NUANCE_COMMON_ILOGCONSUMER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Abstract interface implemented by the customer to receive log messages. <p>
 */
struct _nuance_common_ILogConsumer;
/**
 *  @brief  Abstract interface implemented by the customer to receive log messages. <p>
 */
typedef struct _nuance_common_ILogConsumer nuance_common_ILogConsumer;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "LogZone.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief  Configures this consumer. <p>
 *
 *  This method configures a consumer with a specific configuration string in JSON format.
 *  The possible content of the JSON string depends on the configuration parameters this
 *  consumer supports. The JSON configuration string passed to this method can be set with
 *  the \a params parameter of the \a ILoggingConsumerConfig in the logger JSON configuration
 *  file. In case the \a params parameter is not set or empty this method is called anyway.
 *  This method is called before any other method of this interface.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     params   consumer specific configuration parameter json string.
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_common_ILogConsumer_configure)
(
    void *instance,
    const LH_CHAR *params
);

/**
 *  Called by the framework to dispatch log message of text type to this consumer.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     timestamp   time when log message was created in ms
 *  @param[in]     thread      name or ID of the thread which created the message
 *  @param[in]     module      name of the module which created the log message
 *  @param[in]     zone        the message type, e.g. ERROR, INFO, EXTERNAL_FUNC
 *  @param[in]     msg         the log message
 */
typedef void (*FUNC_nuance_common_ILogConsumer_logText)
(
    void *instance,
    LH_S64 timestamp,
    const LH_CHAR *thread,
    const LH_CHAR *module,
    nuance_common_LogZone zone,
    const LH_CHAR *msg
);

/**
 *  Called by the framework to dispatch binary data to this consumer.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     timestamp   time when log data was created in ms
 *  @param[in]     module      name of the module which created the log data
 *  @param[in]     zone        the message type, e.g. ERROR, INFO, EXTERNAL_FUNC
 *  @param[in]     data        Binary data to log.
 *  @param[in]     size        Binary data size in bytes.
 *  @param[in]     lastBlock   this flag is used to indicate the end of a log unit,                                                           e.g. audio data of one recognition
 */
typedef void (*FUNC_nuance_common_ILogConsumer_logData)
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
 *  Called by the framework to perform flush action. It can be used f.i. to flush received log content to the
 *  desired output.
 *
 *  @param[in,out] instance The instance pointer
 */
typedef void (*FUNC_nuance_common_ILogConsumer_flush)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Abstract interface implemented by the customer to receive log messages. <p>
 */
struct _vtable_nuance_common_ILogConsumer
{
    /**
     *  @brief  Configures this consumer. <p>
     *
     *  This method configures a consumer with a specific configuration string in JSON format.
     *  The possible content of the JSON string depends on the configuration parameters this
     *  consumer supports. The JSON configuration string passed to this method can be set with
     *  the \a params parameter of the \a ILoggingConsumerConfig in the logger JSON configuration
     *  file. In case the \a params parameter is not set or empty this method is called anyway.
     *  This method is called before any other method of this interface.
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     params   consumer specific configuration parameter json string.
     *
     */
    FUNC_nuance_common_ILogConsumer_configure configure;

    /**
     *  Called by the framework to dispatch log message of text type to this consumer.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     timestamp   time when log message was created in ms
     *  @param[in]     thread      name or ID of the thread which created the message
     *  @param[in]     module      name of the module which created the log message
     *  @param[in]     zone        the message type, e.g. ERROR, INFO, EXTERNAL_FUNC
     *  @param[in]     msg         the log message
     */
    FUNC_nuance_common_ILogConsumer_logText logText;

    /**
     *  Called by the framework to dispatch binary data to this consumer.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     timestamp   time when log data was created in ms
     *  @param[in]     module      name of the module which created the log data
     *  @param[in]     zone        the message type, e.g. ERROR, INFO, EXTERNAL_FUNC
     *  @param[in]     data        Binary data to log.
     *  @param[in]     size        Binary data size in bytes.
     *  @param[in]     lastBlock   this flag is used to indicate the end of a log unit,                                                           e.g. audio data of one recognition
     */
    FUNC_nuance_common_ILogConsumer_logData logData;

    /**
     *  Called by the framework to perform flush action. It can be used f.i. to flush received log content to the
     *  desired output.
     *
     *  @param[in,out] instance The instance pointer
     */
    FUNC_nuance_common_ILogConsumer_flush flush;

};
/**
 *  @brief  Abstract interface implemented by the customer to receive log messages. <p>
 */
typedef struct _vtable_nuance_common_ILogConsumer vtable_nuance_common_ILogConsumer;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
COMMON_C_EXPORT nuance_common_ILogConsumer *nuance_common_ILogConsumer_create
(
    const vtable_nuance_common_ILogConsumer *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_ILogConsumer_destroy(nuance_common_ILogConsumer *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_ILOGCONSUMER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
