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
 *  Declaration of nuance_cloudservices_ICloudDataResetListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudDataResetListener
 *  @{
 *  @file ICloudDataResetListener.h
 *
 *  @brief  Listener interface of 'CloudDataReset'. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDDATARESETLISTENER_H
#define NUANCE_CLOUDSERVICES_ICLOUDDATARESETLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Listener interface of 'CloudDataReset'. <p>
 */
struct _nuance_cloudservices_ICloudDataResetListener;
/**
 *  @brief  Listener interface of 'CloudDataReset'. <p>
 */
typedef struct _nuance_cloudservices_ICloudDataResetListener nuance_cloudservices_ICloudDataResetListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "ICloudDataResetError.h"
#include "ICloudDataResetResult.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief  The cloud data reset announces success of the reset. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     result   Data reset result.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudDataResetListener_onDataResetSuccess)
(
    void *instance,
    nuance_cloudservices_ICloudDataResetResult *result
);

/**
 *  @brief  The cloud data reset announces error of the reset. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     error   Data reset error.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudDataResetListener_onDataResetError)
(
    void *instance,
    nuance_cloudservices_ICloudDataResetError *error
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Listener interface of 'CloudDataReset'. <p>
 */
struct _vtable_nuance_cloudservices_ICloudDataResetListener
{
    /**
     *  @brief  The cloud data reset announces success of the reset. <p>
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     result   Data reset result.
     */
    FUNC_nuance_cloudservices_ICloudDataResetListener_onDataResetSuccess onDataResetSuccess;

    /**
     *  @brief  The cloud data reset announces error of the reset. <p>
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     error   Data reset error.
     */
    FUNC_nuance_cloudservices_ICloudDataResetListener_onDataResetError onDataResetError;

};
/**
 *  @brief  Listener interface of 'CloudDataReset'. <p>
 */
typedef struct _vtable_nuance_cloudservices_ICloudDataResetListener vtable_nuance_cloudservices_ICloudDataResetListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
CLOUDSERVICES_C_EXPORT nuance_cloudservices_ICloudDataResetListener *nuance_cloudservices_ICloudDataResetListener_create
(
    const vtable_nuance_cloudservices_ICloudDataResetListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudDataResetListener_destroy(nuance_cloudservices_ICloudDataResetListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDDATARESETLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
