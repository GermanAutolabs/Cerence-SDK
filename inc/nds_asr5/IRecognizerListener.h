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
 *  Declaration of nuance_asr5_IRecognizerListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5  nuance_asr5
 *  @{
 *  @addtogroup IRecognizerListener
 *  @{
 *  @file IRecognizerListener.h
 *
 *  @brief  Provides callback methods to receive events, results and errors from the recognizer object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a recognizer event, result or error occurs. An implementation of this interface can be passed to IRecognizer::create()
 */

#ifndef NUANCE_ASR5_IRECOGNIZERLISTENER_H
#define NUANCE_ASR5_IRECOGNIZERLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Provides callback methods to receive events, results and errors from the recognizer object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a recognizer event, result or error occurs. An implementation of this interface can be passed to IRecognizer::create()
 */
struct _nuance_asr5_IRecognizerListener;
/**
 *  @brief  Provides callback methods to receive events, results and errors from the recognizer object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a recognizer event, result or error occurs. An implementation of this interface can be passed to IRecognizer::create()
 */
typedef struct _nuance_asr5_IRecognizerListener nuance_asr5_IRecognizerListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "asr5_api_defs.h"

/* API types */
#include "RecogEvent.h"
#include "RecognizerError.h"
#include "ResultType.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  Called each time an event is emitted by the recognizer.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     event        The recognizer event
 *  @param[in]     timeMarker   The time (in milliseconds) when the event was triggered; counting starts at start of recognizer
 *  @param[in]     message      String that contains additional information on the result. The documentation              on the event describes the content of this string. The string is empty if the event has no additional information.
 */
typedef void (*FUNC_nuance_asr5_IRecognizerListener_onEvent)
(
    void *instance,
    nuance_asr5_RecogEvent event,
    LH_S32 timeMarker,
    const LH_CHAR *message
);

/**
 *  Called every time a result is available from the recognizer.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     result       The result string
 *  @param[in]     resultType   The result type
 *  @param[in]     isFinal      Indicate whether the Result is final or intermediate.
 */
typedef void (*FUNC_nuance_asr5_IRecognizerListener_onResult)
(
    void *instance,
    const LH_CHAR *result,
    nuance_asr5_ResultType resultType,
    LH_BOOL isFinal
);

/**
 *  @brief This function is called each time an error occurs in the recognizer object.<p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     error     The type of error that occurred
 *  @param[in]     message   String describing the error
 */
typedef void (*FUNC_nuance_asr5_IRecognizerListener_onError)
(
    void *instance,
    nuance_asr5_RecognizerError error,
    const LH_CHAR *message
);

/**
 *  @brief This function is called each time a warning occurs in the recognizer object.<p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     warning   The type of warning that occurred
 *  @param[in]     message   String describing the warning
 */
typedef void (*FUNC_nuance_asr5_IRecognizerListener_onWarning)
(
    void *instance,
    nuance_asr5_RecognizerError warning,
    const LH_CHAR *message
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Provides callback methods to receive events, results and errors from the recognizer object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a recognizer event, result or error occurs. An implementation of this interface can be passed to IRecognizer::create()
 */
struct _vtable_nuance_asr5_IRecognizerListener
{
    /**
     *  Called each time an event is emitted by the recognizer.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     event        The recognizer event
     *  @param[in]     timeMarker   The time (in milliseconds) when the event was triggered; counting starts at start of recognizer
     *  @param[in]     message      String that contains additional information on the result. The documentation              on the event describes the content of this string. The string is empty if the event has no additional information.
     */
    FUNC_nuance_asr5_IRecognizerListener_onEvent onEvent;

    /**
     *  Called every time a result is available from the recognizer.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     result       The result string
     *  @param[in]     resultType   The result type
     *  @param[in]     isFinal      Indicate whether the Result is final or intermediate.
     */
    FUNC_nuance_asr5_IRecognizerListener_onResult onResult;

    /**
     *  @brief This function is called each time an error occurs in the recognizer object.<p>
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     error     The type of error that occurred
     *  @param[in]     message   String describing the error
     */
    FUNC_nuance_asr5_IRecognizerListener_onError onError;

    /**
     *  @brief This function is called each time a warning occurs in the recognizer object.<p>
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     warning   The type of warning that occurred
     *  @param[in]     message   String describing the warning
     */
    FUNC_nuance_asr5_IRecognizerListener_onWarning onWarning;

};
/**
 *  @brief  Provides callback methods to receive events, results and errors from the recognizer object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a recognizer event, result or error occurs. An implementation of this interface can be passed to IRecognizer::create()
 */
typedef struct _vtable_nuance_asr5_IRecognizerListener vtable_nuance_asr5_IRecognizerListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
ASR5_C_EXPORT nuance_asr5_IRecognizerListener *nuance_asr5_IRecognizerListener_create
(
    const vtable_nuance_asr5_IRecognizerListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
ASR5_C_EXPORT void nuance_asr5_IRecognizerListener_destroy(nuance_asr5_IRecognizerListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_IRECOGNIZERLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
