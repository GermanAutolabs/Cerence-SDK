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
 *  Declaration of nuance_asr5_IAsrManagerListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5  nuance_asr5
 *  @{
 *  @addtogroup IAsrManagerListener
 *  @{
 *  @file IAsrManagerListener.h
 *
 *  @brief  Provides callback methods to receive errors from the recognizer object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a recognizer error occurs. An implementation of this interface can be passed to IRecognizer::create()
 */

#ifndef NUANCE_ASR5_IASRMANAGERLISTENER_H
#define NUANCE_ASR5_IASRMANAGERLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Provides callback methods to receive errors from the recognizer object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a recognizer error occurs. An implementation of this interface can be passed to IRecognizer::create()
 */
struct _nuance_asr5_IAsrManagerListener;
/**
 *  @brief  Provides callback methods to receive errors from the recognizer object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a recognizer error occurs. An implementation of this interface can be passed to IRecognizer::create()
 */
typedef struct _nuance_asr5_IAsrManagerListener nuance_asr5_IAsrManagerListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "asr5_api_defs.h"

/* API types */
#include "RecognizerError.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief This function is called each time an error occurs in the recognizer object.<p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     error     The type of error that occurred
 *  @param[in]     message   String describing the error
 */
typedef void (*FUNC_nuance_asr5_IAsrManagerListener_onError)
(
    void *instance,
    nuance_asr5_RecognizerError error,
    const LH_CHAR *message
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Provides callback methods to receive errors from the recognizer object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a recognizer error occurs. An implementation of this interface can be passed to IRecognizer::create()
 */
struct _vtable_nuance_asr5_IAsrManagerListener
{
    /**
     *  @brief This function is called each time an error occurs in the recognizer object.<p>
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     error     The type of error that occurred
     *  @param[in]     message   String describing the error
     */
    FUNC_nuance_asr5_IAsrManagerListener_onError onError;

};
/**
 *  @brief  Provides callback methods to receive errors from the recognizer object. <p>
 *
 *  This class declares an interface which can be implemented by the customer to receive a notification
 *  if a recognizer error occurs. An implementation of this interface can be passed to IRecognizer::create()
 */
typedef struct _vtable_nuance_asr5_IAsrManagerListener vtable_nuance_asr5_IAsrManagerListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
ASR5_C_EXPORT nuance_asr5_IAsrManagerListener *nuance_asr5_IAsrManagerListener_create
(
    const vtable_nuance_asr5_IAsrManagerListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
ASR5_C_EXPORT void nuance_asr5_IAsrManagerListener_destroy(nuance_asr5_IAsrManagerListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_IASRMANAGERLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
