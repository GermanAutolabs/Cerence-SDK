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
 *  Declaration of nuance_cloudservices_ICloudCommanderListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudCommanderListener
 *  @{
 *  @file ICloudCommanderListener.h
 *
 *  @brief  Callback interface to get notified about the completion of async interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asyncronous interface functions of ICloudCommander are finished.
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERLISTENER_H
#define NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Callback interface to get notified about the completion of async interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asyncronous interface functions of ICloudCommander are finished.
 */
struct _nuance_cloudservices_ICloudCommanderListener;
/**
 *  @brief  Callback interface to get notified about the completion of async interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asyncronous interface functions of ICloudCommander are finished.
 */
typedef struct _nuance_cloudservices_ICloudCommanderListener nuance_cloudservices_ICloudCommanderListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "IModuleListener.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  This function is called when the ICloudCommander::start call has finished.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the async start.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudCommanderListener_onStarted)
(
    void *instance,
    nuance_common_ResultCode resultCode
);

/**
 *  This function is called when the ICloudCommander::stop call has finished.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the async stop.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudCommanderListener_onStopped)
(
    void *instance,
    nuance_common_ResultCode resultCode
);

/**
 *  This function is called when the TTS stream starts to flow on backbone
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     padName   the pad name of cloud output audio, such as TTS
 */
typedef void (*FUNC_nuance_cloudservices_ICloudCommanderListener_onStreamStarted)
(
    void *instance,
    const LH_CHAR *padName
);

/**
 *  This function is called when the end of TTS stream or chunk with EOS flag is received
 *  on audio backbone.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     padName   the pad name of cloud output audio, such as TTS
 */
typedef void (*FUNC_nuance_cloudservices_ICloudCommanderListener_onStreamStopped)
(
    void *instance,
    const LH_CHAR *padName
);

/**
 *  This function is called when the creation of a new module instance has finished.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the async create.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudCommanderListener_onCreated)
(
    void *instance,
    nuance_common_ResultCode resultCode
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Callback interface to get notified about the completion of async interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asyncronous interface functions of ICloudCommander are finished.
 */
struct _vtable_nuance_cloudservices_ICloudCommanderListener
{
    /**
     *  This function is called when the ICloudCommander::start call has finished.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the async start.
     */
    FUNC_nuance_cloudservices_ICloudCommanderListener_onStarted onStarted;

    /**
     *  This function is called when the ICloudCommander::stop call has finished.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the async stop.
     */
    FUNC_nuance_cloudservices_ICloudCommanderListener_onStopped onStopped;

    /**
     *  This function is called when the TTS stream starts to flow on backbone
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     padName   the pad name of cloud output audio, such as TTS
     */
    FUNC_nuance_cloudservices_ICloudCommanderListener_onStreamStarted onStreamStarted;

    /**
     *  This function is called when the end of TTS stream or chunk with EOS flag is received
     *  on audio backbone.
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     padName   the pad name of cloud output audio, such as TTS
     */
    FUNC_nuance_cloudservices_ICloudCommanderListener_onStreamStopped onStreamStopped;

    /**
     *  This function is called when the creation of a new module instance has finished.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the async create.
     */
    FUNC_nuance_cloudservices_ICloudCommanderListener_onCreated onCreated;

};
/**
 *  @brief  Callback interface to get notified about the completion of async interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asyncronous interface functions of ICloudCommander are finished.
 */
typedef struct _vtable_nuance_cloudservices_ICloudCommanderListener vtable_nuance_cloudservices_ICloudCommanderListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
CLOUDSERVICES_C_EXPORT nuance_cloudservices_ICloudCommanderListener *nuance_cloudservices_ICloudCommanderListener_create
(
    const vtable_nuance_cloudservices_ICloudCommanderListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudCommanderListener_destroy(nuance_cloudservices_ICloudCommanderListener *);


CLOUDSERVICES_C_EXPORT nuance_common_IModuleListener *nuance_cloudservices_ICloudCommanderListener_as_nuance_common_IModuleListener(nuance_cloudservices_ICloudCommanderListener *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDCOMMANDERLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
