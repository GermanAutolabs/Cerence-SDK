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
 *  Declaration of nuance_audio_IAudioToFileListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioToFileListener
 *  @{
 *  @file IAudioToFileListener.h
 *
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of IAudioFrom file are finished.
 */

#ifndef NUANCE_AUDIO_IAUDIOTOFILELISTENER_H
#define NUANCE_AUDIO_IAUDIOTOFILELISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of IAudioFrom file are finished.
 */
struct _nuance_audio_IAudioToFileListener;
/**
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of IAudioFrom file are finished.
 */
typedef struct _nuance_audio_IAudioToFileListener nuance_audio_IAudioToFileListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IModuleListener.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  This function is called when the recording to file has started. It is the asynchronous response to the
 *  IAudioToFile::start call or a signal that the recording was started implicitly on connect.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the asynchronous start.
 */
typedef void (*FUNC_nuance_audio_IAudioToFileListener_onStarted)
(
    void *instance,
    nuance_common_ResultCode resultCode
);

/**
 *  This function is called when the recording to file has stopped. It is the asynchronous response to the
 *  IAudioToFile::stop call or a signal that the recording was stopped implicitly on disconnect.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the asynchronous stop.
 */
typedef void (*FUNC_nuance_audio_IAudioToFileListener_onStopped)
(
    void *instance,
    nuance_common_ResultCode resultCode
);

/**
 *  This function is called when the creation of a new module instance has finished.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the async create.
 */
typedef void (*FUNC_nuance_audio_IAudioToFileListener_onCreated)
(
    void *instance,
    nuance_common_ResultCode resultCode
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of IAudioFrom file are finished.
 */
struct _vtable_nuance_audio_IAudioToFileListener
{
    /**
     *  This function is called when the recording to file has started. It is the asynchronous response to the
     *  IAudioToFile::start call or a signal that the recording was started implicitly on connect.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the asynchronous start.
     */
    FUNC_nuance_audio_IAudioToFileListener_onStarted onStarted;

    /**
     *  This function is called when the recording to file has stopped. It is the asynchronous response to the
     *  IAudioToFile::stop call or a signal that the recording was stopped implicitly on disconnect.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the asynchronous stop.
     */
    FUNC_nuance_audio_IAudioToFileListener_onStopped onStopped;

    /**
     *  This function is called when the creation of a new module instance has finished.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the async create.
     */
    FUNC_nuance_audio_IAudioToFileListener_onCreated onCreated;

};
/**
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of IAudioFrom file are finished.
 */
typedef struct _vtable_nuance_audio_IAudioToFileListener vtable_nuance_audio_IAudioToFileListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IAudioToFileListener *nuance_audio_IAudioToFileListener_create
(
    const vtable_nuance_audio_IAudioToFileListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IAudioToFileListener_destroy(nuance_audio_IAudioToFileListener *);


AUDIO_C_EXPORT nuance_common_IModuleListener *nuance_audio_IAudioToFileListener_as_nuance_common_IModuleListener(nuance_audio_IAudioToFileListener *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOTOFILELISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
