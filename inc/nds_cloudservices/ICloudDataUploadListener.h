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
 *  Declaration of nuance_cloudservices_ICloudDataUploadListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudDataUploadListener
 *  @{
 *  @file ICloudDataUploadListener.h
 *
 *  @brief  Listener interface of 'CloudDataUpload'. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADLISTENER_H
#define NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Listener interface of 'CloudDataUpload'. <p>
 */
struct _nuance_cloudservices_ICloudDataUploadListener;
/**
 *  @brief  Listener interface of 'CloudDataUpload'. <p>
 */
typedef struct _nuance_cloudservices_ICloudDataUploadListener nuance_cloudservices_ICloudDataUploadListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "ICloudDataUploadError.h"
#include "ICloudDataUploadResult.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief  The cloud data upload announces completion of the operation. <p>
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     grammarId   The grammar Id was uploaded.
 *  @param[in]     result      Data upload result.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudDataUploadListener_onDataUploadComplete)
(
    void *instance,
    const LH_CHAR *grammarId,
    nuance_cloudservices_ICloudDataUploadResult *result
);

/**
 *  @brief  The cloud data upload announces error of the operation. <p>
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     grammarId   The grammar Id was uploaded.
 *  @param[in]     error       Data upload error.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudDataUploadListener_onDataUploadError)
(
    void *instance,
    const LH_CHAR *grammarId,
    nuance_cloudservices_ICloudDataUploadError *error
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Listener interface of 'CloudDataUpload'. <p>
 */
struct _vtable_nuance_cloudservices_ICloudDataUploadListener
{
    /**
     *  @brief  The cloud data upload announces completion of the operation. <p>
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     grammarId   The grammar Id was uploaded.
     *  @param[in]     result      Data upload result.
     */
    FUNC_nuance_cloudservices_ICloudDataUploadListener_onDataUploadComplete onDataUploadComplete;

    /**
     *  @brief  The cloud data upload announces error of the operation. <p>
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     grammarId   The grammar Id was uploaded.
     *  @param[in]     error       Data upload error.
     */
    FUNC_nuance_cloudservices_ICloudDataUploadListener_onDataUploadError onDataUploadError;

};
/**
 *  @brief  Listener interface of 'CloudDataUpload'. <p>
 */
typedef struct _vtable_nuance_cloudservices_ICloudDataUploadListener vtable_nuance_cloudservices_ICloudDataUploadListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
CLOUDSERVICES_C_EXPORT nuance_cloudservices_ICloudDataUploadListener *nuance_cloudservices_ICloudDataUploadListener_create
(
    const vtable_nuance_cloudservices_ICloudDataUploadListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudDataUploadListener_destroy(nuance_cloudservices_ICloudDataUploadListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDDATAUPLOADLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
