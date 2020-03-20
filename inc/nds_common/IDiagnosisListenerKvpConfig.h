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
 *  Declaration of nuance_common_IDiagnosisListenerKvpConfig class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IDiagnosisListenerKvpConfig
 *  @{
 *  @file IDiagnosisListenerKvpConfig.h
 *
 *  @brief  Provides callback methods to receive onChange, onRemove events for fixed "dd_common_key_value_pool" instance. <p>
 *
 *  This listener is intended for DragonDriveFramework use only.
 */

#ifndef NUANCE_COMMON_IDIAGNOSISLISTENERKVPCONFIG_H
#define NUANCE_COMMON_IDIAGNOSISLISTENERKVPCONFIG_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Provides callback methods to receive onChange, onRemove events for fixed "dd_common_key_value_pool" instance. <p>
 *
 *  This listener is intended for DragonDriveFramework use only.
 */
struct _nuance_common_IDiagnosisListenerKvpConfig;
/**
 *  @brief  Provides callback methods to receive onChange, onRemove events for fixed "dd_common_key_value_pool" instance. <p>
 *
 *  This listener is intended for DragonDriveFramework use only.
 */
typedef struct _nuance_common_IDiagnosisListenerKvpConfig nuance_common_IDiagnosisListenerKvpConfig;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "IKeyValuePool.h"
#include "IKeyValuePoolListener.h"
#include "KeyValuePoolError.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief This function returns the changed value for the given key.<p>
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object.
 *  @param[in]     key            Key for which notification was requested, that was just changed.
 *  @param[in]     paramValue     New value stored for key.
 */
typedef void (*FUNC_nuance_common_IDiagnosisListenerKvpConfig_onChange)
(
    void *instance,
    nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key,
    const LH_CHAR *paramValue
);

/**
 *  @brief This function notifies that the registered key was removed.<p>
 *
 *  @param[in,out] instance       The instance pointer
 *  @param[in]     keyValuePool   Instance of the KeyValuePool object.
 *  @param[in]     key            Key for which notification was requested, that was just removed.
 */
typedef void (*FUNC_nuance_common_IDiagnosisListenerKvpConfig_onRemove)
(
    void *instance,
    nuance_common_IKeyValuePool *keyValuePool,
    const LH_CHAR *key
);

/**
 *  This function is called each time an error occurs in
 *  the KeyValuePool object. This will only happen if the
 *  KeyValuePool was created with a configuration. Every
 *  failure of validating requests against the possible keys
 *  and value ranges will result in a call to this method.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     error     The type of error that occurred
 *  @param[in]     message   String describing the error
 */
typedef void (*FUNC_nuance_common_IDiagnosisListenerKvpConfig_onError)
(
    void *instance,
    nuance_common_KeyValuePoolError error,
    const LH_CHAR *message
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Provides callback methods to receive onChange, onRemove events for fixed "dd_common_key_value_pool" instance. <p>
 *
 *  This listener is intended for DragonDriveFramework use only.
 */
struct _vtable_nuance_common_IDiagnosisListenerKvpConfig
{
    /**
     *  @brief This function returns the changed value for the given key.<p>
     *
     *  @param[in,out] instance       The instance pointer
     *  @param[in]     keyValuePool   Instance of the KeyValuePool object.
     *  @param[in]     key            Key for which notification was requested, that was just changed.
     *  @param[in]     paramValue     New value stored for key.
     */
    FUNC_nuance_common_IDiagnosisListenerKvpConfig_onChange onChange;

    /**
     *  @brief This function notifies that the registered key was removed.<p>
     *
     *  @param[in,out] instance       The instance pointer
     *  @param[in]     keyValuePool   Instance of the KeyValuePool object.
     *  @param[in]     key            Key for which notification was requested, that was just removed.
     */
    FUNC_nuance_common_IDiagnosisListenerKvpConfig_onRemove onRemove;

    /**
     *  This function is called each time an error occurs in
     *  the KeyValuePool object. This will only happen if the
     *  KeyValuePool was created with a configuration. Every
     *  failure of validating requests against the possible keys
     *  and value ranges will result in a call to this method.
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     error     The type of error that occurred
     *  @param[in]     message   String describing the error
     */
    FUNC_nuance_common_IDiagnosisListenerKvpConfig_onError onError;

};
/**
 *  @brief  Provides callback methods to receive onChange, onRemove events for fixed "dd_common_key_value_pool" instance. <p>
 *
 *  This listener is intended for DragonDriveFramework use only.
 */
typedef struct _vtable_nuance_common_IDiagnosisListenerKvpConfig vtable_nuance_common_IDiagnosisListenerKvpConfig;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
COMMON_C_EXPORT nuance_common_IDiagnosisListenerKvpConfig *nuance_common_IDiagnosisListenerKvpConfig_create
(
    const vtable_nuance_common_IDiagnosisListenerKvpConfig *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_IDiagnosisListenerKvpConfig_destroy(nuance_common_IDiagnosisListenerKvpConfig *);


COMMON_C_EXPORT nuance_common_IKeyValuePoolListener *nuance_common_IDiagnosisListenerKvpConfig_as_nuance_common_IKeyValuePoolListener(nuance_common_IDiagnosisListenerKvpConfig *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IDIAGNOSISLISTENERKVPCONFIG_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
