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
 *  Declaration of nuance_prompter_IPrompterListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_prompter  nuance_prompter
 *  @{
 *  @addtogroup IPrompterListener
 *  @{
 *  @file IPrompterListener.h
 *
 *  @brief  Listener interface to get notified when Prompter events, warnings or errors occur. <p>
 */

#ifndef NUANCE_PROMPTER_IPROMPTERLISTENER_H
#define NUANCE_PROMPTER_IPROMPTERLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Listener interface to get notified when Prompter events, warnings or errors occur. <p>
 */
struct _nuance_prompter_IPrompterListener;
/**
 *  @brief  Listener interface to get notified when Prompter events, warnings or errors occur. <p>
 */
typedef struct _nuance_prompter_IPrompterListener nuance_prompter_IPrompterListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "prompter_api_defs.h"

/* API types */
#include "IModuleListener.h"
#include "PrompterError.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief  Called each time an error occurs in the <tt>IPrompter</tt> instance. <p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     error     The type of error that occurred
 *  @param[in]     message   String describing the error
 */
typedef void (*FUNC_nuance_prompter_IPrompterListener_onError)
(
    void *instance,
    nuance_prompter_PrompterError error,
    const LH_CHAR *message
);

/**
 *  @brief  Called each time an warning occurs in the <tt>IPrompter</tt> instance. <p>
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     warning   The type of warning that occurred
 *  @param[in]     message   String describing the warning
 */
typedef void (*FUNC_nuance_prompter_IPrompterListener_onWarning)
(
    void *instance,
    nuance_prompter_PrompterError warning,
    const LH_CHAR *message
);

/**
 *  @brief  Sent when a single text unit was segmented from the text block handed over to <tt>nuance_prompter_IPrompter_analyzeText</tt>. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     text   The text unit as delivered by the ve_ttsAnalyzeText API.
 */
typedef void (*FUNC_nuance_prompter_IPrompterListener_onTextSegment)
(
    void *instance,
    const LH_CHAR *text
);

/**
 *  @brief  Sent when the text analysis is finished. This notification will also be sent in case that text analysis failed. <p>
 *
 *  @param[in,out] instance The instance pointer
 */
typedef void (*FUNC_nuance_prompter_IPrompterListener_onAnalyzeTextFinished)(void *instance);

/**
 *  This function is called when the creation of a new module instance has finished.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     resultCode   Result code of the async create.
 */
typedef void (*FUNC_nuance_prompter_IPrompterListener_onCreated)
(
    void *instance,
    nuance_common_ResultCode resultCode
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Listener interface to get notified when Prompter events, warnings or errors occur. <p>
 */
struct _vtable_nuance_prompter_IPrompterListener
{
    /**
     *  @brief  Called each time an error occurs in the <tt>IPrompter</tt> instance. <p>
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     error     The type of error that occurred
     *  @param[in]     message   String describing the error
     */
    FUNC_nuance_prompter_IPrompterListener_onError onError;

    /**
     *  @brief  Called each time an warning occurs in the <tt>IPrompter</tt> instance. <p>
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[in]     warning   The type of warning that occurred
     *  @param[in]     message   String describing the warning
     */
    FUNC_nuance_prompter_IPrompterListener_onWarning onWarning;

    /**
     *  @brief  Sent when a single text unit was segmented from the text block handed over to <tt>nuance_prompter_IPrompter_analyzeText</tt>. <p>
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     text   The text unit as delivered by the ve_ttsAnalyzeText API.
     */
    FUNC_nuance_prompter_IPrompterListener_onTextSegment onTextSegment;

    /**
     *  @brief  Sent when the text analysis is finished. This notification will also be sent in case that text analysis failed. <p>
     *
     *  @param[in,out] instance The instance pointer
     */
    FUNC_nuance_prompter_IPrompterListener_onAnalyzeTextFinished onAnalyzeTextFinished;

    /**
     *  This function is called when the creation of a new module instance has finished.
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     resultCode   Result code of the async create.
     */
    FUNC_nuance_prompter_IPrompterListener_onCreated onCreated;

};
/**
 *  @brief  Listener interface to get notified when Prompter events, warnings or errors occur. <p>
 */
typedef struct _vtable_nuance_prompter_IPrompterListener vtable_nuance_prompter_IPrompterListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
PROMPTER_C_EXPORT nuance_prompter_IPrompterListener *nuance_prompter_IPrompterListener_create
(
    const vtable_nuance_prompter_IPrompterListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
PROMPTER_C_EXPORT void nuance_prompter_IPrompterListener_destroy(nuance_prompter_IPrompterListener *);


PROMPTER_C_EXPORT nuance_common_IModuleListener *nuance_prompter_IPrompterListener_as_nuance_common_IModuleListener(nuance_prompter_IPrompterListener *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_PROMPTER_IPROMPTERLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
