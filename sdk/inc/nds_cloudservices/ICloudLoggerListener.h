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
 *  Declaration of nuance_cloudservices_ICloudLoggerListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudLoggerListener
 *  @{
 *  @file ICloudLoggerListener.h
 *
 *  @brief  Listener interface of 'CloudLogger'. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDLOGGERLISTENER_H
#define NUANCE_CLOUDSERVICES_ICLOUDLOGGERLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Listener interface of 'CloudLogger'. <p>
 */
struct _nuance_cloudservices_ICloudLoggerListener;
/**
 *  @brief  Listener interface of 'CloudLogger'. <p>
 */
typedef struct _nuance_cloudservices_ICloudLoggerListener nuance_cloudservices_ICloudLoggerListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "ICloudLoggerError.h"
#include "ICloudLoggerResult.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief  The cloud logger announces completion of the operation. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     result   Cloud logger result.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudLoggerListener_onCloudLoggingComplete)
(
    void *instance,
    nuance_cloudservices_ICloudLoggerResult *result
);

/**
 *  @brief  The cloud logger announces error of the operation. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     error   Cloud logger error.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudLoggerListener_onCloudLoggingError)
(
    void *instance,
    nuance_cloudservices_ICloudLoggerError *error
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Listener interface of 'CloudLogger'. <p>
 */
struct _vtable_nuance_cloudservices_ICloudLoggerListener
{
    /**
     *  @brief  The cloud logger announces completion of the operation. <p>
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     result   Cloud logger result.
     */
    FUNC_nuance_cloudservices_ICloudLoggerListener_onCloudLoggingComplete onCloudLoggingComplete;

    /**
     *  @brief  The cloud logger announces error of the operation. <p>
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     error   Cloud logger error.
     */
    FUNC_nuance_cloudservices_ICloudLoggerListener_onCloudLoggingError onCloudLoggingError;

};
/**
 *  @brief  Listener interface of 'CloudLogger'. <p>
 */
typedef struct _vtable_nuance_cloudservices_ICloudLoggerListener vtable_nuance_cloudservices_ICloudLoggerListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
CLOUDSERVICES_C_EXPORT nuance_cloudservices_ICloudLoggerListener *nuance_cloudservices_ICloudLoggerListener_create
(
    const vtable_nuance_cloudservices_ICloudLoggerListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudLoggerListener_destroy(nuance_cloudservices_ICloudLoggerListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDLOGGERLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
