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
 *  Declaration of nuance_common_IModuleListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IModuleListener
 *  @{
 *  @file IModuleListener.h
 *
 *  @brief  Callback interface to get notified about changes of the module state. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified about different state changes of an IModule object.
 */

#ifndef NUANCE_COMMON_IMODULELISTENER_H
#define NUANCE_COMMON_IMODULELISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Callback interface to get notified about changes of the module state. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified about different state changes of an IModule object.
 */
struct _nuance_common_IModuleListener;
/**
 *  @brief  Callback interface to get notified about changes of the module state. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified about different state changes of an IModule object.
 */
typedef struct _nuance_common_IModuleListener nuance_common_IModuleListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  This function is called when the creation of a new module instance has finished.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the async create.
 */
typedef void (*FUNC_nuance_common_IModuleListener_onCreated)
(
    void *instance,
    nuance_common_ResultCode resultCode
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Callback interface to get notified about changes of the module state. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified about different state changes of an IModule object.
 */
struct _vtable_nuance_common_IModuleListener
{
    /**
     *  This function is called when the creation of a new module instance has finished.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the async create.
     */
    FUNC_nuance_common_IModuleListener_onCreated onCreated;

};
/**
 *  @brief  Callback interface to get notified about changes of the module state. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified about different state changes of an IModule object.
 */
typedef struct _vtable_nuance_common_IModuleListener vtable_nuance_common_IModuleListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
COMMON_C_EXPORT nuance_common_IModuleListener *nuance_common_IModuleListener_create
(
    const vtable_nuance_common_IModuleListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_IModuleListener_destroy(nuance_common_IModuleListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IMODULELISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
