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
 *  Declaration of nuance_audio_IDiagnosisListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup IDiagnosisListener
 *  @{
 *  @file audio_IDiagnosisListener.h
 *
 *  @brief  Diagnosis listener interface of the 'AudioManager' component. <p>
 *
 *  This listener is meant to be used at the DDFW only.
 *
 *  The AudioManager component is one of the central elements of the audio backbone and will
 *  act as a proxy to collect audio related events of the audio backbone,
 *  offering those via its listener interface.
 */

#ifndef NUANCE_AUDIO_IDIAGNOSISLISTENER_H
#define NUANCE_AUDIO_IDIAGNOSISLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Diagnosis listener interface of the 'AudioManager' component. <p>
 *
 *  This listener is meant to be used at the DDFW only.
 *
 *  The AudioManager component is one of the central elements of the audio backbone and will
 *  act as a proxy to collect audio related events of the audio backbone,
 *  offering those via its listener interface.
 */
struct _nuance_audio_IDiagnosisListener;
/**
 *  @brief  Diagnosis listener interface of the 'AudioManager' component. <p>
 *
 *  This listener is meant to be used at the DDFW only.
 *
 *  The AudioManager component is one of the central elements of the audio backbone and will
 *  act as a proxy to collect audio related events of the audio backbone,
 *  offering those via its listener interface.
 */
typedef struct _nuance_audio_IDiagnosisListener nuance_audio_IDiagnosisListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IntListList.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  This event listener method is called via the audio manager component in the interval the specific instance was configured for.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     instName    who is emitting this event
 *  @param[in]     eventData   data container holding several properties for each channel of a stream
 */
typedef void (*FUNC_nuance_audio_IDiagnosisListener_onSseSignalStatistic)
(
    void *instance,
    const LH_CHAR *instName,
    const nuance_common_IntListList *eventData
);

/**
 *  This event listener method is called via the audio manager component in the interval the specific instance was configured for.
 *
 *  @param[in,out] instance    The instance pointer
 *  @param[in]     instName    who is emitting this event
 *  @param[in]     eventData   data container holding several properties for each channel of a stream
 */
typedef void (*FUNC_nuance_audio_IDiagnosisListener_onSignalAnalysis)
(
    void *instance,
    const LH_CHAR *instName,
    const nuance_common_IntListList *eventData
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Diagnosis listener interface of the 'AudioManager' component. <p>
 *
 *  This listener is meant to be used at the DDFW only.
 *
 *  The AudioManager component is one of the central elements of the audio backbone and will
 *  act as a proxy to collect audio related events of the audio backbone,
 *  offering those via its listener interface.
 */
struct _vtable_nuance_audio_IDiagnosisListener
{
    /**
     *  This event listener method is called via the audio manager component in the interval the specific instance was configured for.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     instName    who is emitting this event
     *  @param[in]     eventData   data container holding several properties for each channel of a stream
     */
    FUNC_nuance_audio_IDiagnosisListener_onSseSignalStatistic onSseSignalStatistic;

    /**
     *  This event listener method is called via the audio manager component in the interval the specific instance was configured for.
     *
     *  @param[in,out] instance    The instance pointer
     *  @param[in]     instName    who is emitting this event
     *  @param[in]     eventData   data container holding several properties for each channel of a stream
     */
    FUNC_nuance_audio_IDiagnosisListener_onSignalAnalysis onSignalAnalysis;

};
/**
 *  @brief  Diagnosis listener interface of the 'AudioManager' component. <p>
 *
 *  This listener is meant to be used at the DDFW only.
 *
 *  The AudioManager component is one of the central elements of the audio backbone and will
 *  act as a proxy to collect audio related events of the audio backbone,
 *  offering those via its listener interface.
 */
typedef struct _vtable_nuance_audio_IDiagnosisListener vtable_nuance_audio_IDiagnosisListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
AUDIO_C_EXPORT nuance_audio_IDiagnosisListener *nuance_audio_IDiagnosisListener_create
(
    const vtable_nuance_audio_IDiagnosisListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_IDiagnosisListener_destroy(nuance_audio_IDiagnosisListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_IDIAGNOSISLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
