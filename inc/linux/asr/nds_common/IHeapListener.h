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
 *  Declaration of nuance_common_IHeapListener class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IHeapListener
 *  @{
 *  @file IHeapListener.h
 *
 *  @brief  Callback interface to get notified when the heap limit is reached. <p>
 */

#ifndef NUANCE_COMMON_IHEAPLISTENER_H
#define NUANCE_COMMON_IHEAPLISTENER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Callback interface to get notified when the heap limit is reached. <p>
 */
struct _nuance_common_IHeapListener;
/**
 *  @brief  Callback interface to get notified when the heap limit is reached. <p>
 */
typedef struct _nuance_common_IHeapListener nuance_common_IHeapListener;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "HeapLevel.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  This function is called each time the fill level of the heap changes.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     level   The fill-level of the heap
 */
typedef void (*FUNC_nuance_common_IHeapListener_onLevelChanged)
(
    void *instance,
    nuance_common_HeapLevel level
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Callback interface to get notified when the heap limit is reached. <p>
 */
struct _vtable_nuance_common_IHeapListener
{
    /**
     *  This function is called each time the fill level of the heap changes.
     *
     *  @param[in,out] instance The instance pointer
     *  @param[in]     level   The fill-level of the heap
     */
    FUNC_nuance_common_IHeapListener_onLevelChanged onLevelChanged;

};
/**
 *  @brief  Callback interface to get notified when the heap limit is reached. <p>
 */
typedef struct _vtable_nuance_common_IHeapListener vtable_nuance_common_IHeapListener;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
COMMON_C_EXPORT nuance_common_IHeapListener *nuance_common_IHeapListener_create
(
    const vtable_nuance_common_IHeapListener *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_IHeapListener_destroy(nuance_common_IHeapListener *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IHEAPLISTENER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
