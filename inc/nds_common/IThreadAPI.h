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
 *  Declaration of nuance_common_IThreadAPI class
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IThreadAPI
 *  @{
 *  @file IThreadAPI.h
 *
 *  @brief
 *  Provides an interface for the customer to implement and install external thread management functions.
 *  <p>
 */

#ifndef NUANCE_COMMON_ITHREADAPI_H
#define NUANCE_COMMON_ITHREADAPI_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief
 *  Provides interface for the customer to implement and install external thread management functions.
 *  <p>
 *
 *  This header file defines interface types that have to be used by the customer when installing and using
 *  external thread management functions. Currently framework supports user defined functions to crate new
 *  threads and to wait for specified threads to complete their work (join functionallity).
 */

/* Forward declaration for the interface */
struct _nuance_common_IThreadAPI;

/**
 *  @brief
 *  Provides interface for the customer to implement and install external thread management functions.
 *  <p>
 *
 *  This structure is the interface to the framework class that implements API for external thread management.
 */
typedef struct _nuance_common_IThreadAPI nuance_common_IThreadAPI;

/*** Declare types for external thread management**********************************************************************/

/**
 *  Thread id type for platforms using POSIX pthread lib
 */
typedef unsigned long posix_t;

/**
 * Thread id type for Windows platforms
 */
typedef void * windows_t;

/**
 * WIN32: External thread identifier and parameters.
 */
typedef struct
{
  windows_t     thread_id;
} nuance_common_IThreadAPI_External_Win32;

/**
 * WINCE: External thread identifier and parameters.
 */
typedef struct
{
  windows_t     thread_id;
} nuance_common_IThreadAPI_External_Wince;

/**
 * QNX: External thread identifier and parameters.
 */
typedef struct
{
  posix_t       thread_id;
  int           low_priority;
  int           max_repl;
  int           repl_perios;
  int           init_budget;
  int           partition;
  int           markCritical;
  const char   *partName;
  void         *exit_code;
} nuance_common_IThreadAPI_External_Qnx;

/**
 * LINUX: External thread identifier and parameters.
 */
typedef struct
{
  posix_t       thread_id;
  int           cpumask;
  void         *exit_code;
} nuance_common_IThreadAPI_External_Linux;

/**
 * ANDROID: External thread identifier and parameters.
 */
typedef struct
{
  posix_t       thread_id;
} nuance_common_IThreadAPI_External_Android;

/**
 * IOS: External thread identifier and parameters.
 */
typedef struct
{
  posix_t       thread_id;
} nuance_common_IThreadAPI_External_Ios;

/**
 * Platform specific union type for parameters and data to be used for data exchange between
 * external thread management functions and DD SDK if they are installed.
 */
typedef union  {
  nuance_common_IThreadAPI_External_Win32   win32;
  nuance_common_IThreadAPI_External_Wince   wince;
  nuance_common_IThreadAPI_External_Qnx     qnx;
  nuance_common_IThreadAPI_External_Linux   linux32;
  nuance_common_IThreadAPI_External_Android android;
  nuance_common_IThreadAPI_External_Ios     ios;
} nuance_common_IThreadAPI_External;

/**
 * @brief User defined external function that creates new thread according to the parameters defined by the framework.
 *
 * External function is responsible to create thread using the arguments provided. It can set its own priority level
 * and other parameters for the thread or use parameters handed over by 'pIntThreadData' argument. After thread
 * is successfully created it should initialize 'pExtThreadData' with the corresponding thread identifier. Please
 * see the definitions above for the exact type of the thread_id field on specific platforms.
 *
 * @param[in]      pIntFunc        Pointer to the internal function prepared by the framework to be called from the new
 *                                 thread that this function creates
 * @param[in]      pIntThreadData  Pointer to the thread parameters prepared by the framework
 * @param[in, out] pExtThreadData  Pointer to the structure to be filled with extrenally created thread data. User
 *                                 function must supply identifier for the new thread in the 'thread id' field.
 *
 * @return         0 if no errors happened, non zero value otherwise
 */
typedef int (*nuance_common_IThreadAPI_CreateFunc)
(
    void *pIntFunc,
    void *pIntThreadData,
    nuance_common_IThreadAPI_External *pExtThreadData
);

/**
 * @brief User defined external function that waits for the thread to complete (join).
 *
 * External function is responsible to cleanup resources allocated during the external create thread call.
 * Thread identifier to be used for wait is provided by the framework in the structure pointed by 'pExtThreadData'
 * argument.
 *
 * @param[in]      pExtThreadData   Pointer to the structure containing thread identifier to join.
 *
 * @return         0 if no errors happened, non zero value otherwise
 */
typedef int (*nuance_common_IThreadAPI_JoinFunc)(nuance_common_IThreadAPI_External *pExtThreadData);

/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


 /**
  *  @brief Creates instance of IThreadAPI object that provides external thread management functions.<p>
  *
  *  @param[out] threadAPI     The new instance of IThreadAPI object
  *
  *  @return     The result code of the execution
  */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IThreadAPI_create(nuance_common_IThreadAPI **threadAPI);

/**
 *  @brief Installs external (user defined) functions for thread management.
 *
 *  Install external thread management functions before using the API functions that actually create threads.
 *  Once installed it is not recommended to uninstall external thread management functions except as a cleanup
 *  sequence after all created threads have been completed and external functions are not needed anymore.
 *
 *  @param[in]      instance                Pointer to the instance of the IThreadAPI object.
 *  @param[in]      customThreadCreateFunc  Pointer to external thread create function.
 *  @param[in]      customThreadJoinFunc    Pointer to external function to join the thread.
 *
 *  @return         The result code of the execution
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IThreadAPI_installCustomThreadFuncs
(
    nuance_common_IThreadAPI *instance,
    nuance_common_IThreadAPI_CreateFunc customThreadCreateFunc,
    nuance_common_IThreadAPI_JoinFunc customThreadJoinFunc
);

/**
 *  @brief Uninstalls external (userd defined) functions for thread management.<p>
 *
 *  It is not recommended to uninstall external thread management functions except as a cleanup sequence after all
 *  created threads have been completed and external functions are not needed anymore.
 *
 *  @return The result code of the execution
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IThreadAPI_uninstallCustomThreadFuncs
(
    nuance_common_IThreadAPI *instance
);


/**
 *  Destroys the instance of the IThreadAPI object.
 */
COMMON_C_EXPORT void nuance_common_IThreadAPI_destroy(nuance_common_IThreadAPI *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_ITHREADAPI_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
