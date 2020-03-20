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
 *  Declaration of nuance_common_IApplicationCallback class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IApplicationCallback
 *  @{
 *  @file IApplicationCallback.h
 *
 *  @brief  Provides callback methods to receive requests from the SDK. <p>
 *
 *  This class declares an interface which can be implemented by the customer to feed the SDK with new required data.
 *  An implementation of this interface can be passed to IConfiguration.create().
 */

#ifndef NUANCE_COMMON_IAPPLICATIONCALLBACK_H
#define NUANCE_COMMON_IAPPLICATIONCALLBACK_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare inner types of class ************************************************************************************/

/**
 *  The names of the supported functions (requests) for which client should provide implementation.
 */
typedef enum
{
    NUANCE_COMMON_IAPPLICATIONCALLBACK_DATA_REQUEST,   /**< Request from server to send back needed data. */
    NUANCE_COMMON_IAPPLICATIONCALLBACK_GET_KEY_VALUE   /**< Request dynamic configuration value by JSON key. */
} nuance_common_IApplicationCallback_FunctionName;


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Provides callback methods to receive requests from the SDK. <p>
 *
 *  This class declares an interface which can be implemented by the customer to feed the SDK with new required data.
 *  An implementation of this interface can be passed to IConfiguration.create().
 */
struct _nuance_common_IApplicationCallback;
/**
 *  @brief  Provides callback methods to receive requests from the SDK. <p>
 *
 *  This class declares an interface which can be implemented by the customer to feed the SDK with new required data.
 *  An implementation of this interface can be passed to IConfiguration.create().
 */
typedef struct _nuance_common_IApplicationCallback nuance_common_IApplicationCallback;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
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
typedef nuance_common_ResultCode (*FUNC_nuance_common_IApplicationCallback_execute)
(
    void *instance,
    nuance_common_IApplicationCallback_FunctionName functionName,
    const LH_CHAR *args,
    nuance_common_String **results
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Provides callback methods to receive requests from the SDK. <p>
 *
 *  This class declares an interface which can be implemented by the customer to feed the SDK with new required data.
 *  An implementation of this interface can be passed to IConfiguration.create().
 */
struct _vtable_nuance_common_IApplicationCallback
{
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
    FUNC_nuance_common_IApplicationCallback_execute execute;

};
/**
 *  @brief  Provides callback methods to receive requests from the SDK. <p>
 *
 *  This class declares an interface which can be implemented by the customer to feed the SDK with new required data.
 *  An implementation of this interface can be passed to IConfiguration.create().
 */
typedef struct _vtable_nuance_common_IApplicationCallback vtable_nuance_common_IApplicationCallback;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
COMMON_C_EXPORT nuance_common_IApplicationCallback *nuance_common_IApplicationCallback_create
(
    const vtable_nuance_common_IApplicationCallback *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_IApplicationCallback_destroy(nuance_common_IApplicationCallback *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IAPPLICATIONCALLBACK_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
