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
 *  Declaration of nuance_common_IKeyValuePool class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IKeyValuePool
 *  @{
 *  @file IKeyValuePool.h
 *
 *  @brief
 *  This class exposes an interface which enables modifying the content of the JSON variables dynamically
 *  at a post configuration time.
 *  <p>
 *  This interface is intended for DragonDriveFramework use only.
 *
 *  The object of this class manages the map containing key-value pairs (symbol table). It
 *  specializes IApplicationCallback interface so that the user of the interface must provide implementations not
 *  only for the execute() but also for the setKeyValue() methods. By means of this mechanism API user can change
 *  the value for the variable that has already been read from the configuration or it can provide a callback
 *  function that the framework can invoke to add or change JSON variable values based on the processing at the
 *  user application side.
 *  <p>
 *  The execute() method is called by the framework to request the data from the application.
 *  The behavior of the method is determined by the parameter 'functionName' which currently supports the
 *  following two request types:
 *  </p>
 *  <p>
 *  GET_KEY_VALUE - second parameter 'args' is interpreted as a name of the key
 *  contained in the map for which this method retrieves the value and stores it in the 'results' output
 *  parameter.
 *
 *  Usage example (callback not needed):
 *  </p>
 *  \code
 *  nuance.common.IKeyValuePool keyValuePool = nuance.common.IKeyValuePool.create(null);
 *  ...
 *  keyValuePool.setKeyValue("key", "value");
 *  \endcode
 *  <p>
 *  DATA_REQUEST - function is interpreted as a request to fetch data from the user application by utilizing
 *  application callback function which should be in this case provided by the user when creating this object.
 *  Second parameter 'args' is used to provide input for the user callback function, f.i. the name of the JSON
 *  variable. Callback function stores the processed value to the 'results' output parameter.
 *
 *  Usage example (user callback):
 *  </p>
 *
 *  \code
 *  public class DataRequestHandler extends nuance.common.IApplicationCallback
 *  {
 *  void execute(functionName, args, results) {...}
 *  }
 *  DataRequestHandler dataRequestHandler;
 *  nuance.common.IKeyValuePool keyValuePool = nuance.common.IKeyValuePool.create(dataRequestHandler);
 *  \endcode
 */

#ifndef NUANCE_COMMON_IKEYVALUEPOOL_H
#define NUANCE_COMMON_IKEYVALUEPOOL_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief
 *  This class exposes an interface which enables modifying the content of the JSON variables dynamically
 *  at a post configuration time.
 *  <p>
 *  This interface is intended for DragonDriveFramework use only.
 *
 *  The object of this class manages the map containing key-value pairs (symbol table). It
 *  specializes IApplicationCallback interface so that the user of the interface must provide implementations not
 *  only for the execute() but also for the setKeyValue() methods. By means of this mechanism API user can change
 *  the value for the variable that has already been read from the configuration or it can provide a callback
 *  function that the framework can invoke to add or change JSON variable values based on the processing at the
 *  user application side.
 *  <p>
 *  The execute() method is called by the framework to request the data from the application.
 *  The behavior of the method is determined by the parameter 'functionName' which currently supports the
 *  following two request types:
 *  </p>
 *  <p>
 *  GET_KEY_VALUE - second parameter 'args' is interpreted as a name of the key
 *  contained in the map for which this method retrieves the value and stores it in the 'results' output
 *  parameter.
 *
 *  Usage example (callback not needed):
 *  </p>
 *  \code
 *  nuance.common.IKeyValuePool keyValuePool = nuance.common.IKeyValuePool.create(null);
 *  ...
 *  keyValuePool.setKeyValue("key", "value");
 *  \endcode
 *  <p>
 *  DATA_REQUEST - function is interpreted as a request to fetch data from the user application by utilizing
 *  application callback function which should be in this case provided by the user when creating this object.
 *  Second parameter 'args' is used to provide input for the user callback function, f.i. the name of the JSON
 *  variable. Callback function stores the processed value to the 'results' output parameter.
 *
 *  Usage example (user callback):
 *  </p>
 *
 *  \code
 *  public class DataRequestHandler extends nuance.common.IApplicationCallback
 *  {
 *  void execute(functionName, args, results) {...}
 *  }
 *  DataRequestHandler dataRequestHandler;
 *  nuance.common.IKeyValuePool keyValuePool = nuance.common.IKeyValuePool.create(dataRequestHandler);
 *  \endcode
 */
struct _nuance_common_IKeyValuePool;
/**
 *  @brief
 *  This class exposes an interface which enables modifying the content of the JSON variables dynamically
 *  at a post configuration time.
 *  <p>
 *  This interface is intended for DragonDriveFramework use only.
 *
 *  The object of this class manages the map containing key-value pairs (symbol table). It
 *  specializes IApplicationCallback interface so that the user of the interface must provide implementations not
 *  only for the execute() but also for the setKeyValue() methods. By means of this mechanism API user can change
 *  the value for the variable that has already been read from the configuration or it can provide a callback
 *  function that the framework can invoke to add or change JSON variable values based on the processing at the
 *  user application side.
 *  <p>
 *  The execute() method is called by the framework to request the data from the application.
 *  The behavior of the method is determined by the parameter 'functionName' which currently supports the
 *  following two request types:
 *  </p>
 *  <p>
 *  GET_KEY_VALUE - second parameter 'args' is interpreted as a name of the key
 *  contained in the map for which this method retrieves the value and stores it in the 'results' output
 *  parameter.
 *
 *  Usage example (callback not needed):
 *  </p>
 *  \code
 *  nuance.common.IKeyValuePool keyValuePool = nuance.common.IKeyValuePool.create(null);
 *  ...
 *  keyValuePool.setKeyValue("key", "value");
 *  \endcode
 *  <p>
 *  DATA_REQUEST - function is interpreted as a request to fetch data from the user application by utilizing
 *  application callback function which should be in this case provided by the user when creating this object.
 *  Second parameter 'args' is used to provide input for the user callback function, f.i. the name of the JSON
 *  variable. Callback function stores the processed value to the 'results' output parameter.
 *
 *  Usage example (user callback):
 *  </p>
 *
 *  \code
 *  public class DataRequestHandler extends nuance.common.IApplicationCallback
 *  {
 *  void execute(functionName, args, results) {...}
 *  }
 *  DataRequestHandler dataRequestHandler;
 *  nuance.common.IKeyValuePool keyValuePool = nuance.common.IKeyValuePool.create(dataRequestHandler);
 *  \endcode
 */
typedef struct _nuance_common_IKeyValuePool nuance_common_IKeyValuePool;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "IApplicationCallback.h"
#include "IConfiguration.h"
#include "IKeyValuePoolListener.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Static method that creates and returns new instance of the object implementing this interface.
 *
 *  @param[in]     applicationCallback   User provided callback function that implements IApplicationCallback interface and that will be used
 *                                       in context with DATA_REQUEST function, otherwise it is not needed.
 *  @param[in]     listener              an \ref IKeyValuePoolListener signalizes the value status onChange and onRemove.
 *  @param[in]     listener2             an additional \ref IKeyValuePoolListener to generate events of a different type, when necessay.
 *  @param[out]    keyValuePool          Output parameter returning the new instance of the object
 *
 *  @return Returns the result code of the execution.
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IKeyValuePool_create
(
    nuance_common_IApplicationCallback *applicationCallback,
    nuance_common_IKeyValuePoolListener *listener,
    nuance_common_IKeyValuePoolListener *listener2,
    nuance_common_IKeyValuePool **keyValuePool
);


/**
 *  Static method that creates and returns new instance of the
 *  object implementing this interface.  This creation method
 *  gets an IConfiguration object passed in. That is expected
 *  to contain a configuration for that KVP. If this configuration is missing no
 *  keys can be added to this instance.
 *
 *  @param[in]     applicationCallback   User provided callback function that implements IApplicationCallback interface and that will be used
 *                                       in context with DATA_REQUEST function, otherwise it is not needed.
 *  @param[in]     configuration         pass the IConfiguration object.
 *  @param[in]     listener              an \ref IKeyValuePoolListener signalizes the value status onChange and onRemove.
 *  @param[in]     listener2             an additional \ref IKeyValuePoolListener to generate events of a different type, when necessay.
 *  @param[in]     name                  Name to be used for configuration lookup.
 *  @param[out]    keyValuePool          Output parameter returning the new instance of the object
 *
 *  @return Returns the result code of the execution.
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IKeyValuePool_createWithConfig
(
    nuance_common_IApplicationCallback *applicationCallback,
    const nuance_common_IConfiguration *configuration,
    nuance_common_IKeyValuePoolListener *listener,
    nuance_common_IKeyValuePoolListener *listener2,
    const LH_CHAR *name,
    nuance_common_IKeyValuePool **keyValuePool
);


/**
 *  Retrieves the value for the given key. If the KVP was
 *  created with a configuration the key will be validated and
 *  an error will be signalled if the validation fails (as
 *  result and by a call to the onError method if a listener
 *  was provided on creation).
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     key          The name of the key for which the value should be retrieved. It can be used to dynamically get configuration values.
 *  @param[out]    paramValue   The value of the key.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IKeyValuePool_getKeyValue
(
    const nuance_common_IKeyValuePool *instance,
    const LH_CHAR *key,
    nuance_common_String **paramValue
);


/**
 *  Inserts or updates the value for the given key. It can be
 *  used to dynamically sets configuration values. If the KVP
 *  was created with a configuration the key and the value
 *  will be validated and an error will may be signalled if
 *  the validation fails (as result and by a call to the
 *  onError method if a listener was provided on creation).
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     key          The name of the key for which the value should be set.
 *  @param[in]     paramValue   The new value to be set.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IKeyValuePool_setKeyValue
(
    nuance_common_IKeyValuePool *instance,
    const LH_CHAR *key,
    const LH_CHAR *paramValue
);


/**
 *  Register for notification on the given key. The
 *  notification will happen via the listener's onChange and
 *  onRemove methods. If the KVP was created with a
 *  configuration the key will be validated and an error will
 *  be signalled if the validation fails (as result and by a
 *  call to the onError method if a listener was provided on
 *  creation).
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key   The name of the config key for the onChanged event.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IKeyValuePool_registerNotification
(
    nuance_common_IKeyValuePool *instance,
    const LH_CHAR *key
);


/**
 *  Release notification for the given key. If the KVP was
 *  created with a configuration the key will be validated and
 *  an error will be signalled if the validation fails (as
 *  result and by a call to the onError method if a listener
 *  was provided on creation).
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key   The name of the config key for the onChanged event.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IKeyValuePool_releaseNotification
(
    nuance_common_IKeyValuePool *instance,
    const LH_CHAR *key
);


/**
 *  Remove the stored value for the given key. If the KVP was
 *  created with a configuration the key will be validated and
 *  an error will be signalled if the validation fails (as
 *  result and by a call to the onError method if a listener
 *  was provided on creation).
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key   The name of the general key for which the value should be removed.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IKeyValuePool_removeKeyValue
(
    nuance_common_IKeyValuePool *instance,
    const LH_CHAR *key
);


/**
 *  Reset the key value pool to the initial state.
 *
 *  @param[in,out] instance The instance pointer
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IKeyValuePool_reset(nuance_common_IKeyValuePool *instance);


/**
 *  Called by the SDK to request the data from the application.
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     functionName   The name of the function that is requested by the caller. Currently supported function names:
 *                                GET_KEY_VALUE and DATA_REQUEST.
 *  @param[in]     args           The input data passed to the application by the SDK. It could f.i. contain JSON variable name for
 *                                which the value is sought for.
 *  @param[out]    results        The output parameter to get the requested data (results) back from the application to the SDK.
 *
 *  @return Returns the result code of the execution
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IKeyValuePool_execute
(
    nuance_common_IKeyValuePool *instance,
    nuance_common_IApplicationCallback_FunctionName functionName,
    const LH_CHAR *args,
    nuance_common_String **results
);


/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_IKeyValuePool_destroy(nuance_common_IKeyValuePool *);


COMMON_C_EXPORT nuance_common_IApplicationCallback *nuance_common_IKeyValuePool_as_nuance_common_IApplicationCallback(nuance_common_IKeyValuePool *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IKEYVALUEPOOL_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
