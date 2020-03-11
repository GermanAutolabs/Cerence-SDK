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
 *  Declaration of nuance_common_IAllocator interface
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IHeap
 *  @{
 *  @file HeapAllocator.h
 *
 *  @brief  Interface for installing an external heap management<p>
 *
 *  This interface is used to install a customer implementation of the heap management. The heap interface
 *  must be installed before calling any other interface function of the DragonDrive SDK.
 */

#ifndef NUANCE_COMMON_HEAPALLOCATOR_H
#define NUANCE_COMMON_HEAPALLOCATOR_H


/*** Includes *********************************************************************************************************/

#include "lh_types.h"
#include "common_api_defs.h"
#include "ResultCode.h"

#ifdef __cplusplus
extern "C" {
#endif


/*** Methods **********************************************************************************************************/

/* Function pointers for pure virtual methods */
/**
 *  Prototype for external malloc function.
 *
 *  @param[in]     size        nuber of bytes to allocate
 */
typedef void* (*FUNC_nuance_common_IHeap_extMalloc) (LH_SIZE_T size);

/**
 *  Prototype for external calloc function.
 *
 *  @param[in]     num         nuber of elements to allocate
 *  @param[in]     size        size of one element
 */
typedef void* (*FUNC_nuance_common_IHeap_extCalloc) (LH_SIZE_T num, LH_SIZE_T size);

/**
 *  Prototype for external realloc function.
 *
 *  @param[in]     ptr         pointer to the original buffer
 *  @param[in]     size        size of the new buffer
 */
typedef void* (*FUNC_nuance_common_IHeap_extRealloc) (void* ptr, LH_SIZE_T size);

/**
 *  Prototype for external free function.
 *
 *  @param[in]     ptr         pointer to the buffer to free
 */
typedef void  (*FUNC_nuance_common_IHeap_extFree) (void* ptr);


/**
 *  @brief  Function to install the external memory allocator.<p>
 *
 *  This function has to be called directly after the initialisation
 *  of the heap and before any other function of the Companion SDK.
 *  If this function is called after the SDK has already allocated
 *  some memory, an error will be returned and the internal default
 *  allocator will be used. 
 *
 *  @param[in]     extMalloc   external malloc function
 *  @param[in]     extCalloc   external calloc function
 *  @param[in]     extRealloc  external realloc function
 *  @param[in]     extFree     external free function
 *
 *  @return The result code of the execution
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IHeap_installAllocator(
  FUNC_nuance_common_IHeap_extMalloc extMalloc,
  FUNC_nuance_common_IHeap_extCalloc extCalloc,
  FUNC_nuance_common_IHeap_extRealloc extRealloc,
  FUNC_nuance_common_IHeap_extFree extFree
);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_HEAPALLOCATOR_H */


/** @} */
/** @} */

