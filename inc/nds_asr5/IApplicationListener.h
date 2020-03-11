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
 *  Declaration of nuance_asr5_IApplicationListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5  nuance_asr5
 *  @{
 *  @addtogroup IApplicationListener
 *  @{
 *  @file IApplicationListener.h
 *
 *  @brief  Provides callback methods to receive errors from the application object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a application error occurs. An implementation of this interface can be passed to IApplication::create()
 */

#ifndef NUANCE_ASR5_IAPPLICATIONLISTENER_H
#define NUANCE_ASR5_IAPPLICATIONLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Provides callback methods to receive errors from the application object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a application error occurs. An implementation of this interface can be passed to IApplication::create()
 */
struct _nuance_asr5_IApplicationListener;
/**
 *  @brief  Provides callback methods to receive errors from the application object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a application error occurs. An implementation of this interface can be passed to IApplication::create()
 */
typedef struct _nuance_asr5_IApplicationListener nuance_asr5_IApplicationListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "asr5_api_defs.h"

/* API types */
#include "ApplicationError.h"
#include "ApplicationEvent.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief This function is called each time an error occurs in the application object.<p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     error     The type of error that occurred
 *  @param[in]     message   String describing the error
 */
typedef void (*FUNC_nuance_asr5_IApplicationListener_onError)
(
    void *instance,
    nuance_asr5_ApplicationError error,
    const LH_CHAR *message
);

/**
 *  @brief This function is called each time a warning occurs in the application object.<p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     warning   The type of warning that occurred
 *  @param[in]     message   String describing the warning
 */
typedef void (*FUNC_nuance_asr5_IApplicationListener_onWarning)
(
    void *instance,
    nuance_asr5_ApplicationError warning,
    const LH_CHAR *message
);

/**
 *  Called each time an event is emitted by the application.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     event     The application event
 *  @param[in]     message   String that contains additional information on the result. The documentation              on the event describes the content of this string. The string is empty if the event has no additional information.
 */
typedef void (*FUNC_nuance_asr5_IApplicationListener_onEvent)
(
    void *instance,
    nuance_asr5_ApplicationEvent event,
    const LH_CHAR *message
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Provides callback methods to receive errors from the application object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a application error occurs. An implementation of this interface can be passed to IApplication::create()
 */
struct _vtable_nuance_asr5_IApplicationListener
{
    /**
     *  @brief This function is called each time an error occurs in the application object.<p>
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     error     The type of error that occurred
     *  @param[in]     message   String describing the error
     */
    FUNC_nuance_asr5_IApplicationListener_onError onError;

    /**
     *  @brief This function is called each time a warning occurs in the application object.<p>
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     warning   The type of warning that occurred
     *  @param[in]     message   String describing the warning
     */
    FUNC_nuance_asr5_IApplicationListener_onWarning onWarning;

    /**
     *  Called each time an event is emitted by the application.
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     event     The application event
     *  @param[in]     message   String that contains additional information on the result. The documentation              on the event describes the content of this string. The string is empty if the event has no additional information.
     */
    FUNC_nuance_asr5_IApplicationListener_onEvent onEvent;

};
/**
 *  @brief  Provides callback methods to receive errors from the application object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a application error occurs. An implementation of this interface can be passed to IApplication::create()
 */
typedef struct _vtable_nuance_asr5_IApplicationListener vtable_nuance_asr5_IApplicationListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
ASR5_C_EXPORT nuance_asr5_IApplicationListener *nuance_asr5_IApplicationListener_create
(
    const vtable_nuance_asr5_IApplicationListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
ASR5_C_EXPORT void nuance_asr5_IApplicationListener_destroy(nuance_asr5_IApplicationListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_IAPPLICATIONLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
