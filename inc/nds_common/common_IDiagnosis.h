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
 *  Declaration of nuance_common_IDiagnosis class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IDiagnosis
 *  @{
 *  @file common_IDiagnosis.h
 *
 *  @brief Interface for DragonDrive common diagnosis calls  <p>
 *
 *  This interface is intended for DragonDriveFramework use only.
 */

#ifndef NUANCE_COMMON_IDIAGNOSIS_H
#define NUANCE_COMMON_IDIAGNOSIS_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief Interface for DragonDrive common diagnosis calls  <p>
 *
 *  This interface is intended for DragonDriveFramework use only.
 */
struct _nuance_common_IDiagnosis;
/**
 *  @brief Interface for DragonDrive common diagnosis calls  <p>
 *
 *  This interface is intended for DragonDriveFramework use only.
 */
typedef struct _nuance_common_IDiagnosis nuance_common_IDiagnosis;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "IKeyValuePool.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Returns the version labels of the common component release.
 *
 *  @param[out]    ddVersion    returns the DragonDrive release label.
 *  @param[out]    palVersion   returns the PAL module release label.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_getVersion
(
    nuance_common_String **ddVersion,
    nuance_common_String **palVersion
);


/**
 *  This API call allows applications (GDML dialogs and/or
 *  external diagnosis programs) to store general information
 *  for diagnosis purposes (For setting config params use API
 *  storeConfigKeyValue() instead). Writes the value for the
 *  given key to the DDFW KeyValuePool
 *  "dd_diag_key_value_pool". Possible keys need to be defined
 *  in application-specific configurations. If the key or the
 *  value cannot be validated against the configuration an
 *  error will be signalled if the validation fails (as result
 *  and by a call to the onError method if a listener was
 *  provided on creation).
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_diag_key_value_pool).
 *  @param[in]     key            The name of the general key for which the value should be set.
 *  @param[in]     paramValue     The new value to be set.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_storeKeyValue
(
    nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key,
    const LH_CHAR *paramValue
);


/**
 *  This API call allows applications (GDML dialogs and/or
 *  external diagnosis programs) to retrieve information that
 *  was stored for general diagnosis purposes (For reading
 *  config params use API readConfigKeyValue()
 *  instead). Retrieves the value for the given key from the
 *  DDFW KeyValuePool "dd_diag_key_value_pool".  Possible keys
 *  need to be defined in application-specific
 *  configurations. If the key cannot be validated against the
 *  configuration an error will be signalled if the validation
 *  fails (as result and by a call to the onError method if a
 *  listener was provided on creation).
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_diag_key_value_pool).
 *  @param[in]     key            The name of the general key for which the value should be retrieved.
 *  @param[out]    paramValue     The value of the key.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_readKeyValue
(
    const nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key,
    nuance_common_String **paramValue
);


/**
 *  Register for notifications on the given key. The
 *  notification will happen via the listener's onChange and
 *  onRemove methods. If the key cannot be validated against
 *  the configuration an error will be signalled if the
 *  validation fails (as result and by a call to the onError
 *  method if a listener was provided on creation).
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_diag_key_value_pool).
 *  @param[in]     key            The name of the config key for the onChanged event.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_registerNotification
(
    nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key
);


/**
 *  Release notification for the given key. If the key cannot
 *  be validated against the configuration an error will be
 *  signalled if the validation fails (as result and by a call
 *  to the onError method if a listener was provided on
 *  creation).
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_diag_key_value_pool).
 *  @param[in]     key            The name of the config key for the onChanged event.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_releaseNotification
(
    nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key
);


/**
 *  Reset the value for the given key to its default value. If the key cannot be
 *  validated against the configuration an error will be
 *  signalled if the validation fails (as result and by a call
 *  to the onError method if a listener was provided on
 *  creation).
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_diag_key_value_pool).
 *  @param[in]     key            The name of the general key for which the value should be removed.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_removeKeyValue
(
    nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key
);


/**
 *  Reset the diagnosis keyValuePool to the initial state.
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_diag_key_value_pool).
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_resetKeyValuePool(nuance_common_IKeyValuePool *keyValuePool);


/**
 *  This API call allows diagnosis programs to change the value
 *  of dynamic configuration parameters (defined as vh_callback
 *  in JSON configs).  Writes the value for the given key to
 *  the DDFW KeyValuePool "dd_common_key_value_pool".  Possible
 *  keys are vh_callback parameters from the JSON
 *  configuration.  Values will be read from
 *  "dd_common_key_value_pool" next time a DDFW application
 *  accesses the vh_callback parameter.
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_common_key_value_pool).
 *  @param[in]     key            The name of the config key for which the value should be set.
 *  @param[in]     paramValue     The new value to be set.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_storeConfigKeyValue
(
    nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key,
    const LH_CHAR *paramValue
);


/**
 *  This API call allows diagnosis programs to read the current
 *  value of dynamic configuration parameters (defined as
 *  vh_callback in JSON configs).  Retrieves the value for the
 *  given key from the DDFW KeyValuePool
 *  "dd_common_key_value_pool".  Possible keys are vh_callback
 *  parameters from the JSON configuration.
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_common_key_value_pool).
 *  @param[in]     key            The name of the config key for which the value should be retrieved.
 *  @param[out]    paramValue     The value of the key.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_readConfigKeyValue
(
    const nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key,
    nuance_common_String **paramValue
);


/**
 *  Register for notifications for the given key. The
 *  notification will happen via the listener's onChange and
 *  onRemove methods.
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_common_key_value_pool).
 *  @param[in]     key            The name of the config key for the onChanged event.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_registerConfigNotification
(
    nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key
);


/**
 *  Release notification for the given key.
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_common_key_value_pool).
 *  @param[in]     key            The name of the config key for the onChanged event.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_releaseConfigNotification
(
    nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key
);


/**
 *  Remove the stored value for the given configuration key.
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_common_key_value_pool).
 *  @param[in]     key            The name of the general key for which the value should be removed.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_removeConfigKeyValue
(
    nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key
);


/**
 *  Reset the configuration keyValuePool to the initial state.
 *
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object (dd_common_key_value_pool).
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDiagnosis_resetConfigKeyValuePool(nuance_common_IKeyValuePool *keyValuePool);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IDIAGNOSIS_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
