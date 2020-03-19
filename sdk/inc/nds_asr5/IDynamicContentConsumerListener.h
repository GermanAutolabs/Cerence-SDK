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
 *  Declaration of nuance_asr5_IDynamicContentConsumerListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5  nuance_asr5
 *  @{
 *  @addtogroup IDynamicContentConsumerListener
 *  @{
 *  @file IDynamicContentConsumerListener.h
 *
 *  @brief  Abstract interface to get notified of dynamic content consumer events and errors. <p>
 *
 *  This class declares an interface which can be implemented by the customer to
 *  get notified of any event or error on the dynamic content consumer.
 *
 *  Note: Each dynamic content consumer runs in a separate thread, therefor the listeners must
 *  be thread safe.
 *
 *  \sa DynamicContentConsumerEvent
 */

#ifndef NUANCE_ASR5_IDYNAMICCONTENTCONSUMERLISTENER_H
#define NUANCE_ASR5_IDYNAMICCONTENTCONSUMERLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Abstract interface to get notified of dynamic content consumer events and errors. <p>
 *
 *  This class declares an interface which can be implemented by the customer to
 *  get notified of any event or error on the dynamic content consumer.
 *
 *  Note: Each dynamic content consumer runs in a separate thread, therefor the listeners must
 *  be thread safe.
 *
 *  \sa DynamicContentConsumerEvent
 */
struct _nuance_asr5_IDynamicContentConsumerListener;
/**
 *  @brief  Abstract interface to get notified of dynamic content consumer events and errors. <p>
 *
 *  This class declares an interface which can be implemented by the customer to
 *  get notified of any event or error on the dynamic content consumer.
 *
 *  Note: Each dynamic content consumer runs in a separate thread, therefor the listeners must
 *  be thread safe.
 *
 *  \sa DynamicContentConsumerEvent
 */
typedef struct _nuance_asr5_IDynamicContentConsumerListener nuance_asr5_IDynamicContentConsumerListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "asr5_api_defs.h"

/* API types */
#include "DynamicContentConsumerError.h"
#include "DynamicContentConsumerEvent.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief Called each time an event is emitted by the dynamic content consumer.<p>
 *
 *  Note that each dynamic content consumer operates in its own worker thread, this means
 *  that each dcc should receive its own listener or else the application needs to
 *  make sure the implementation of the listener is threadsafe.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     event     The event
 *  @param[in]     message   String describing the error
 */
typedef void (*FUNC_nuance_asr5_IDynamicContentConsumerListener_onEvent)
(
    void *instance,
    nuance_asr5_DynamicContentConsumerEvent event,
    const LH_CHAR *message
);

/**
 *  @brief This function is called each time an error occurs in the dynamic content consumer object.<p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     error     The type of error that occurred
 *  @param[in]     message   String describing the error
 */
typedef void (*FUNC_nuance_asr5_IDynamicContentConsumerListener_onError)
(
    void *instance,
    nuance_asr5_DynamicContentConsumerError error,
    const LH_CHAR *message
);

/**
 *  @brief This function is called each time a warning occurs in the dynamic content consumer object.<p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     warning   The type of warning that occurred
 *  @param[in]     message   String describing the warning
 */
typedef void (*FUNC_nuance_asr5_IDynamicContentConsumerListener_onWarning)
(
    void *instance,
    nuance_asr5_DynamicContentConsumerError warning,
    const LH_CHAR *message
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Abstract interface to get notified of dynamic content consumer events and errors. <p>
 *
 *  This class declares an interface which can be implemented by the customer to
 *  get notified of any event or error on the dynamic content consumer.
 *
 *  Note: Each dynamic content consumer runs in a separate thread, therefor the listeners must
 *  be thread safe.
 *
 *  \sa DynamicContentConsumerEvent
 */
struct _vtable_nuance_asr5_IDynamicContentConsumerListener
{
    /**
     *  @brief Called each time an event is emitted by the dynamic content consumer.<p>
     *
     *  Note that each dynamic content consumer operates in its own worker thread, this means
     *  that each dcc should receive its own listener or else the application needs to
     *  make sure the implementation of the listener is threadsafe.
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     event     The event
     *  @param[in]     message   String describing the error
     */
    FUNC_nuance_asr5_IDynamicContentConsumerListener_onEvent onEvent;

    /**
     *  @brief This function is called each time an error occurs in the dynamic content consumer object.<p>
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     error     The type of error that occurred
     *  @param[in]     message   String describing the error
     */
    FUNC_nuance_asr5_IDynamicContentConsumerListener_onError onError;

    /**
     *  @brief This function is called each time a warning occurs in the dynamic content consumer object.<p>
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     warning   The type of warning that occurred
     *  @param[in]     message   String describing the warning
     */
    FUNC_nuance_asr5_IDynamicContentConsumerListener_onWarning onWarning;

};
/**
 *  @brief  Abstract interface to get notified of dynamic content consumer events and errors. <p>
 *
 *  This class declares an interface which can be implemented by the customer to
 *  get notified of any event or error on the dynamic content consumer.
 *
 *  Note: Each dynamic content consumer runs in a separate thread, therefor the listeners must
 *  be thread safe.
 *
 *  \sa DynamicContentConsumerEvent
 */
typedef struct _vtable_nuance_asr5_IDynamicContentConsumerListener vtable_nuance_asr5_IDynamicContentConsumerListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
ASR5_C_EXPORT nuance_asr5_IDynamicContentConsumerListener *nuance_asr5_IDynamicContentConsumerListener_create
(
    const vtable_nuance_asr5_IDynamicContentConsumerListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
ASR5_C_EXPORT void nuance_asr5_IDynamicContentConsumerListener_destroy(nuance_asr5_IDynamicContentConsumerListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_IDYNAMICCONTENTCONSUMERLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
