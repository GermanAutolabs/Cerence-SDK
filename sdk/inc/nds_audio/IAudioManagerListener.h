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
 *  Declaration of nuance_audio_IAudioManagerListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IAudioManagerListener
 *  @{
 *  @file IAudioManagerListener.h
 *
 *  @brief  Listener interface of the 'AudioManager' component. <p>
 *
 *  The AudioManager component is one of the central elements of the audio backbone and will
 *  act as a proxy to collect audio related events of the audio backbone,
 *  offering those via its listener interface.
 */

#ifndef NUANCE_AUDIO_IAUDIOMANAGERLISTENER_H
#define NUANCE_AUDIO_IAUDIOMANAGERLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Listener interface of the 'AudioManager' component. <p>
 *
 *  The AudioManager component is one of the central elements of the audio backbone and will
 *  act as a proxy to collect audio related events of the audio backbone,
 *  offering those via its listener interface.
 */
struct _nuance_audio_IAudioManagerListener;
/**
 *  @brief  Listener interface of the 'AudioManager' component. <p>
 *
 *  The AudioManager component is one of the central elements of the audio backbone and will
 *  act as a proxy to collect audio related events of the audio backbone,
 *  offering those via its listener interface.
 */
typedef struct _nuance_audio_IAudioManagerListener nuance_audio_IAudioManagerListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IntListList.h"
#include "SegmentationState.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  This event listener method is called via the audio manager component in the interval the specific instance was configured for.
 *
 *  This method is triggered by the speech signal enhancement module if the parameter "signal_statistics_interval" is configured.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     instName    who is emitting this event
 *  @param[in]     eventData   data container holding several properties for each channel of a stream
 */
typedef void (*FUNC_nuance_audio_IAudioManagerListener_onSseSignalStatistic)
(
    void *instance,
    const LH_CHAR *instName,
    const nuance_common_IntListList *eventData
);

/**
 *  This event listener method is called via the audio manager component in the interval the specific instance was configured for.
 *
 *  This method is triggered by the signal analysis module if added to the audio path.
 *  This module is only available at the DDFW.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     instName    who is emitting this event
 *  @param[in]     eventData   data container holding several properties for each channel of a stream
 */
typedef void (*FUNC_nuance_audio_IAudioManagerListener_onSignalAnalysis)
(
    void *instance,
    const LH_CHAR *instName,
    const nuance_common_IntListList *eventData
);

/**
 *  This event listener method is called via the audio manager component if the specified event happened.
 *
 *  This method is triggered by the segmentation module if added to the audio path.
 *  This module is only available at the DDFW.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     instName    who is emitting this event
 *  @param[in]     eventData   data for this event
 */
typedef void (*FUNC_nuance_audio_IAudioManagerListener_onSegmentation)
(
    void *instance,
    const LH_CHAR *instName,
    nuance_audio_SegmentationState eventData
);

/**
 *  This event listener method is called via the audio manager component if the specified event happened.
 *
 *  This method is triggered by the speech signal enhancement module if the zone indicator feature is activated in the SCD file.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     instName    who is emitting this event
 *  @param[in]     eventData   data for this event
 */
typedef void (*FUNC_nuance_audio_IAudioManagerListener_onZoneIndicator)
(
    void *instance,
    const LH_CHAR *instName,
    LH_S32 eventData
);

/**
 *  This event listener method is called via the audio manager component if the specified event happened.
 *
 *  This method is triggered by the audio input or audio output module if timeout happened at the audio adapter interface.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     instName   who is emitting this event
 */
typedef void (*FUNC_nuance_audio_IAudioManagerListener_onFatalAudioError)
(
    void *instance,
    const LH_CHAR *instName
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Listener interface of the 'AudioManager' component. <p>
 *
 *  The AudioManager component is one of the central elements of the audio backbone and will
 *  act as a proxy to collect audio related events of the audio backbone,
 *  offering those via its listener interface.
 */
struct _vtable_nuance_audio_IAudioManagerListener
{
    /**
     *  This event listener method is called via the audio manager component in the interval the specific instance was configured for.
     *
     *  This method is triggered by the speech signal enhancement module if the parameter "signal_statistics_interval" is configured.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     instName    who is emitting this event
     *  @param[in]     eventData   data container holding several properties for each channel of a stream
     */
    FUNC_nuance_audio_IAudioManagerListener_onSseSignalStatistic onSseSignalStatistic;

    /**
     *  This event listener method is called via the audio manager component in the interval the specific instance was configured for.
     *
     *  This method is triggered by the signal analysis module if added to the audio path.
     *  This module is only available at the DDFW.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     instName    who is emitting this event
     *  @param[in]     eventData   data container holding several properties for each channel of a stream
     */
    FUNC_nuance_audio_IAudioManagerListener_onSignalAnalysis onSignalAnalysis;

    /**
     *  This event listener method is called via the audio manager component if the specified event happened.
     *
     *  This method is triggered by the segmentation module if added to the audio path.
     *  This module is only available at the DDFW.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     instName    who is emitting this event
     *  @param[in]     eventData   data for this event
     */
    FUNC_nuance_audio_IAudioManagerListener_onSegmentation onSegmentation;

    /**
     *  This event listener method is called via the audio manager component if the specified event happened.
     *
     *  This method is triggered by the speech signal enhancement module if the zone indicator feature is activated in the SCD file.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     instName    who is emitting this event
     *  @param[in]     eventData   data for this event
     */
    FUNC_nuance_audio_IAudioManagerListener_onZoneIndicator onZoneIndicator;

    /**
     *  This event listener method is called via the audio manager component if the specified event happened.
     *
     *  This method is triggered by the audio input or audio output module if timeout happened at the audio adapter interface.
     *
     *  @param[in,out] instance   The instance pointer
     *  @param[in]     instName   who is emitting this event
     */
    FUNC_nuance_audio_IAudioManagerListener_onFatalAudioError onFatalAudioError;

};
/**
 *  @brief  Listener interface of the 'AudioManager' component. <p>
 *
 *  The AudioManager component is one of the central elements of the audio backbone and will
 *  act as a proxy to collect audio related events of the audio backbone,
 *  offering those via its listener interface.
 */
typedef struct _vtable_nuance_audio_IAudioManagerListener vtable_nuance_audio_IAudioManagerListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IAudioManagerListener *nuance_audio_IAudioManagerListener_create
(
    const vtable_nuance_audio_IAudioManagerListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IAudioManagerListener_destroy(nuance_audio_IAudioManagerListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IAUDIOMANAGERLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
