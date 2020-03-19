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
 *  Declaration of nuance_audio_ISpeechSignalEnhancementListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup ISpeechSignalEnhancementListener
 *  @{
 *  @file ISpeechSignalEnhancementListener.h
 *
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of ISpeechSignalEnhancement are finished.
 */

#ifndef NUANCE_AUDIO_ISPEECHSIGNALENHANCEMENTLISTENER_H
#define NUANCE_AUDIO_ISPEECHSIGNALENHANCEMENTLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of ISpeechSignalEnhancement are finished.
 */
struct _nuance_audio_ISpeechSignalEnhancementListener;
/**
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of ISpeechSignalEnhancement are finished.
 */
typedef struct _nuance_audio_ISpeechSignalEnhancementListener nuance_audio_ISpeechSignalEnhancementListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IModuleListener.h"
#include "IntList.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  This function is called when the data was set.
 *  It is the asynchronous response to the ISpeechSignalEnhancement::setData call.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the async setData.
 */
typedef void (*FUNC_nuance_audio_ISpeechSignalEnhancementListener_onDataSet)
(
    void *instance,
    nuance_common_ResultCode resultCode
);

/**
 *  This function is called when the data is returned.
 *  It is the asynchronous response to the ISpeechSignalEnhancement::getData call.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     value        integer value which should be got
 *  @param[in]     nvalue       Number of elements in value
 *  @param[in]     resultCode   Result code of the async getData
 */
typedef void (*FUNC_nuance_audio_ISpeechSignalEnhancementListener_onDataGet)
(
    void *instance,
    LH_S32  const *value, LH_S32 nvalue,
    nuance_common_ResultCode resultCode
);

/**
 *  This function is called when the creation of a new module instance has finished.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the async create.
 */
typedef void (*FUNC_nuance_audio_ISpeechSignalEnhancementListener_onCreated)
(
    void *instance,
    nuance_common_ResultCode resultCode
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of ISpeechSignalEnhancement are finished.
 */
struct _vtable_nuance_audio_ISpeechSignalEnhancementListener
{
    /**
     *  This function is called when the data was set.
     *  It is the asynchronous response to the ISpeechSignalEnhancement::setData call.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the async setData.
     */
    FUNC_nuance_audio_ISpeechSignalEnhancementListener_onDataSet onDataSet;

    /**
     *  This function is called when the data is returned.
     *  It is the asynchronous response to the ISpeechSignalEnhancement::getData call.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     value        integer value which should be got
     *  @param[in]     nvalue       Number of elements in value
     *  @param[in]     resultCode   Result code of the async getData
     */
    FUNC_nuance_audio_ISpeechSignalEnhancementListener_onDataGet onDataGet;

    /**
     *  This function is called when the creation of a new module instance has finished.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the async create.
     */
    FUNC_nuance_audio_ISpeechSignalEnhancementListener_onCreated onCreated;

};
/**
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of ISpeechSignalEnhancement are finished.
 */
typedef struct _vtable_nuance_audio_ISpeechSignalEnhancementListener vtable_nuance_audio_ISpeechSignalEnhancementListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_ISpeechSignalEnhancementListener *nuance_audio_ISpeechSignalEnhancementListener_create
(
    const vtable_nuance_audio_ISpeechSignalEnhancementListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_ISpeechSignalEnhancementListener_destroy(nuance_audio_ISpeechSignalEnhancementListener *);


AUDIO_C_EXPORT nuance_common_IModuleListener *nuance_audio_ISpeechSignalEnhancementListener_as_nuance_common_IModuleListener(nuance_audio_ISpeechSignalEnhancementListener *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_ISPEECHSIGNALENHANCEMENTLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
