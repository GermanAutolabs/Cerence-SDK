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
 *  Declaration of nuance_audio_IAudioFromFileListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioFromFileListener
 *  @{
 *  @file IAudioFromFileListener.h
 *
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of IAudioFrom file are finished.
 */

#ifndef NUANCE_AUDIO_IAUDIOFROMFILELISTENER_H
#define NUANCE_AUDIO_IAUDIOFROMFILELISTENER_H

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
struct _nuance_audio_IAudioFromFileListener;
/**
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of IAudioFrom file are finished.
 */
typedef struct _nuance_audio_IAudioFromFileListener nuance_audio_IAudioFromFileListener;


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
 *  This function is called when setting of a file is finished.
 *  It is the asynchronous response to the IAudioFromFile::setFile call.
 *  When this is called the file was opened and the 1rst 30 chunks were buffered into memory.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the asynchronous create.
 */
typedef void (*FUNC_nuance_audio_IAudioFromFileListener_onFileSet)
(
    void *instance,
    nuance_common_ResultCode resultCode
);

/**
 *  This function is called when setting of a file list is finished.
 *  It is the asynchronous response to the IAudioFromFile::setFileList call.
 *  When this is called the 1rst file was opened and the 1rst 30 chunks of it were buffered into memory.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the asynchronous create.
 */
typedef void (*FUNC_nuance_audio_IAudioFromFileListener_onFileListSet)
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
typedef void (*FUNC_nuance_audio_IAudioFromFileListener_onCreated)
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
struct _vtable_nuance_audio_IAudioFromFileListener
{
    /**
     *  This function is called when setting of a file is finished.
     *  It is the asynchronous response to the IAudioFromFile::setFile call.
     *  When this is called the file was opened and the 1rst 30 chunks were buffered into memory.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the asynchronous create.
     */
    FUNC_nuance_audio_IAudioFromFileListener_onFileSet onFileSet;

    /**
     *  This function is called when setting of a file list is finished.
     *  It is the asynchronous response to the IAudioFromFile::setFileList call.
     *  When this is called the 1rst file was opened and the 1rst 30 chunks of it were buffered into memory.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the asynchronous create.
     */
    FUNC_nuance_audio_IAudioFromFileListener_onFileListSet onFileListSet;

    /**
     *  This function is called when the creation of a new module instance has finished.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the async create.
     */
    FUNC_nuance_audio_IAudioFromFileListener_onCreated onCreated;

};
/**
 *  @brief  Callback interface to get notified about the completion of asynchronous interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asynchronous interface functions of IAudioFrom file are finished.
 */
typedef struct _vtable_nuance_audio_IAudioFromFileListener vtable_nuance_audio_IAudioFromFileListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IAudioFromFileListener *nuance_audio_IAudioFromFileListener_create
(
    const vtable_nuance_audio_IAudioFromFileListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IAudioFromFileListener_destroy(nuance_audio_IAudioFromFileListener *);


AUDIO_C_EXPORT nuance_common_IModuleListener *nuance_audio_IAudioFromFileListener_as_nuance_common_IModuleListener(nuance_audio_IAudioFromFileListener *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOFROMFILELISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
