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
 *  Declaration of nuance_audio_IAudioSegmentationListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioSegmentationListener
 *  @{
 *  @file IAudioSegmentationListener.h
 *
 *  @brief  Callback interface to get notified about the completion of async interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asyncronous interface functions of IAudioSegmentation module are finished.
 */

#ifndef NUANCE_AUDIO_IAUDIOSEGMENTATIONLISTENER_H
#define NUANCE_AUDIO_IAUDIOSEGMENTATIONLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Callback interface to get notified about the completion of async interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asyncronous interface functions of IAudioSegmentation module are finished.
 */
struct _nuance_audio_IAudioSegmentationListener;
/**
 *  @brief  Callback interface to get notified about the completion of async interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asyncronous interface functions of IAudioSegmentation module are finished.
 */
typedef struct _nuance_audio_IAudioSegmentationListener nuance_audio_IAudioSegmentationListener;


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
 *  This function is called when no speech is detected by the AudioSegmentation module for a defined time.
 *  From this time on capturing and analysing data is stopped.
 *
 *  @param[in,out] instance The instance pointer
 */
typedef void (*FUNC_nuance_audio_IAudioSegmentationListener_onInitialTimeout)(void *instance);

/**
 *  This function is called when speech is detected by the AudioSegmentation module.
 *  From this time on the segmentation module starts streaming audio to the subsequent module.
 *
 *  @param[in,out] instance The instance pointer
 */
typedef void (*FUNC_nuance_audio_IAudioSegmentationListener_onSpeech)(void *instance);

/**
 *  This function is called when end of speech is detected by the AudioSegmentation module.
 *  From this time on the segmentation module stops streaming audio to the subsequent module.
 *
 *  @param[in,out] instance The instance pointer
 */
typedef void (*FUNC_nuance_audio_IAudioSegmentationListener_onEndOfSpeech)(void *instance);

/**
 *  This function is called when the creation of a new module instance has finished.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the async create.
 */
typedef void (*FUNC_nuance_audio_IAudioSegmentationListener_onCreated)
(
    void *instance,
    nuance_common_ResultCode resultCode
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Callback interface to get notified about the completion of async interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asyncronous interface functions of IAudioSegmentation module are finished.
 */
struct _vtable_nuance_audio_IAudioSegmentationListener
{
    /**
     *  This function is called when no speech is detected by the AudioSegmentation module for a defined time.
     *  From this time on capturing and analysing data is stopped.
     *
     *  @param[in,out] instance The instance pointer
     */
    FUNC_nuance_audio_IAudioSegmentationListener_onInitialTimeout onInitialTimeout;

    /**
     *  This function is called when speech is detected by the AudioSegmentation module.
     *  From this time on the segmentation module starts streaming audio to the subsequent module.
     *
     *  @param[in,out] instance The instance pointer
     */
    FUNC_nuance_audio_IAudioSegmentationListener_onSpeech onSpeech;

    /**
     *  This function is called when end of speech is detected by the AudioSegmentation module.
     *  From this time on the segmentation module stops streaming audio to the subsequent module.
     *
     *  @param[in,out] instance The instance pointer
     */
    FUNC_nuance_audio_IAudioSegmentationListener_onEndOfSpeech onEndOfSpeech;

    /**
     *  This function is called when the creation of a new module instance has finished.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the async create.
     */
    FUNC_nuance_audio_IAudioSegmentationListener_onCreated onCreated;

};
/**
 *  @brief  Callback interface to get notified about the completion of async interface functions. <p>
 *
 *  This class declares an interface which can be implemented by the customer to get
 *  notified when different asyncronous interface functions of IAudioSegmentation module are finished.
 */
typedef struct _vtable_nuance_audio_IAudioSegmentationListener vtable_nuance_audio_IAudioSegmentationListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IAudioSegmentationListener *nuance_audio_IAudioSegmentationListener_create
(
    const vtable_nuance_audio_IAudioSegmentationListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IAudioSegmentationListener_destroy(nuance_audio_IAudioSegmentationListener *);


AUDIO_C_EXPORT nuance_common_IModuleListener *nuance_audio_IAudioSegmentationListener_as_nuance_common_IModuleListener(nuance_audio_IAudioSegmentationListener *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOSEGMENTATIONLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
