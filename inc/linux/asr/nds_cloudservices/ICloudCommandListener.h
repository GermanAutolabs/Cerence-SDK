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
 *  Declaration of nuance_cloudservices_ICloudCommandListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cloudservices  nuance_cloudservices
 *  @{
 *  @addtogroup ICloudCommandListener
 *  @{
 *  @file ICloudCommandListener.h
 *
 *  @brief  Interface of ICloudCommandListener. <p>
 */

#ifndef NUANCE_CLOUDSERVICES_ICLOUDCOMMANDLISTENER_H
#define NUANCE_CLOUDSERVICES_ICLOUDCOMMANDLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of ICloudCommandListener. <p>
 */
struct _nuance_cloudservices_ICloudCommandListener;
/**
 *  @brief  Interface of ICloudCommandListener. <p>
 */
typedef struct _nuance_cloudservices_ICloudCommandListener nuance_cloudservices_ICloudCommandListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cloudservices_api_defs.h"

/* API types */
#include "ICloudCommand.h"
#include "ICloudCommandError.h"
#include "ICloudCommandResult.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  @brief  Indicates that the command has started. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     cmd   Reference to the command instance.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudCommandListener_onCommandStarted)
(
    void *instance,
    const nuance_cloudservices_ICloudCommand *cmd
);

/**
 *  @brief  Indicates that the command is finished and can be destroyed. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     cmd   Reference to the command instance.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudCommandListener_onCommandFinished)
(
    void *instance,
    const nuance_cloudservices_ICloudCommand *cmd
);

/**
 *  @brief  Indicates that a result was received from the server. The 'isComplete' parameter lets the listener know if more results are coming from the server. <p>
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[in]     result       Command result.
 *  @param[in]     isComplete   Indicates whether more results to be expected for this command.
 *  @param[in]     cmd          Reference to command instance.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudCommandListener_onCommandResult)
(
    void *instance,
    nuance_cloudservices_ICloudCommandResult *result,
    LH_BOOL isComplete,
    const nuance_cloudservices_ICloudCommand *cmd
);

/**
 *  @brief  Indicates that an error was received from the server and the command was stopped. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     error   Command error.
 *  @param[in]     cmd     Reference to command instance.
 */
typedef void (*FUNC_nuance_cloudservices_ICloudCommandListener_onCommandError)
(
    void *instance,
    nuance_cloudservices_ICloudCommandError *error,
    const nuance_cloudservices_ICloudCommand *cmd
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Interface of ICloudCommandListener. <p>
 */
struct _vtable_nuance_cloudservices_ICloudCommandListener
{
    /**
     *  @brief  Indicates that the command has started. <p>
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     cmd   Reference to the command instance.
     */
    FUNC_nuance_cloudservices_ICloudCommandListener_onCommandStarted onCommandStarted;

    /**
     *  @brief  Indicates that the command is finished and can be destroyed. <p>
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     cmd   Reference to the command instance.
     */
    FUNC_nuance_cloudservices_ICloudCommandListener_onCommandFinished onCommandFinished;

    /**
     *  @brief  Indicates that a result was received from the server. The 'isComplete' parameter lets the listener know if more results are coming from the server. <p>
     *
     *  @param[in,out] instance     The instance pointer
     *  @param[in]     result       Command result.
     *  @param[in]     isComplete   Indicates whether more results to be expected for this command.
     *  @param[in]     cmd          Reference to command instance.
     */
    FUNC_nuance_cloudservices_ICloudCommandListener_onCommandResult onCommandResult;

    /**
     *  @brief  Indicates that an error was received from the server and the command was stopped. <p>
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     error   Command error.
     *  @param[in]     cmd     Reference to command instance.
     */
    FUNC_nuance_cloudservices_ICloudCommandListener_onCommandError onCommandError;

};
/**
 *  @brief  Interface of ICloudCommandListener. <p>
 */
typedef struct _vtable_nuance_cloudservices_ICloudCommandListener vtable_nuance_cloudservices_ICloudCommandListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
CLOUDSERVICES_C_EXPORT nuance_cloudservices_ICloudCommandListener *nuance_cloudservices_ICloudCommandListener_create
(
    const vtable_nuance_cloudservices_ICloudCommandListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
CLOUDSERVICES_C_EXPORT void nuance_cloudservices_ICloudCommandListener_destroy(nuance_cloudservices_ICloudCommandListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CLOUDSERVICES_ICLOUDCOMMANDLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
