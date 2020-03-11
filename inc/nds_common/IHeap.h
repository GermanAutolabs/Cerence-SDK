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
 *  Declaration of nuance_common_IHeap class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IHeap
 *  @{
 *  @file IHeap.h
 *
 *  @brief  Heap configuration instance. <p>
 */

#ifndef NUANCE_COMMON_IHEAP_H
#define NUANCE_COMMON_IHEAP_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Heap configuration instance. <p>
 */
struct _nuance_common_IHeap;
/**
 *  @brief  Heap configuration instance. <p>
 */
typedef struct _nuance_common_IHeap nuance_common_IHeap;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "IHeapListener.h"
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief Initialize the heap<p>
 *  Initializes the heap. This has to be the first Companion SDK API function to be called and is
 *  necessary to call any other heap-function later on.
 *
 *  @param[in]     global           Specifies whether one global heap is used for all allocations.
 *  @param[in]     mallocRedirect   Specifies whether all calls to malloc and operator new        are redirected to a manged heap instance. This is a precondition for setting a heap limit.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IHeap_init
(
    LH_BOOL global,
    LH_BOOL mallocRedirect
);


/**
 *  @brief Deinitialize the heap<p>
 *  Deinitializes the heap module. This function should be called after the destruction of all components.
 *  In case of a malloc-redirect this will ensure a cleanup of all previous allocated memory.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IHeap_deinit();


/**
 *  @brief Set a upper heap limit<p>
 *  Sets up a upper limit for the used heap. If the limit is reached the provided listener is called.
 *  There is no physical limitation of the heap. It is up to the application to ensure that no more
 *  memory is allocatate (e.g. by aborting the currently running operation).
 *
 *  @param[in]     limit      The upper heap limit in bytes.
 *  @param[in]     listener   an \ref IHeapListener implementation         which is used to report the fill level of the heap.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IHeap_setLimit
(
    LH_S32 limit,
    nuance_common_IHeapListener *listener
);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IHEAP_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
