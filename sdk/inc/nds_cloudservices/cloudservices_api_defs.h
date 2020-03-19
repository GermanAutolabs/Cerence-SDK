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

#ifndef IG_NUANCE_CLOUDSERVICES_CLOUDSERVICES_API_DEFS_H
#define IG_NUANCE_CLOUDSERVICES_CLOUDSERVICES_API_DEFS_H

#include "global_api_defs.h"

#if defined(BUILD_CLOUDSERVICES_DLL)
  #define CLOUDSERVICES_EXPORT DECL_EXPORT
#else
  #define CLOUDSERVICES_EXPORT /* DECL_IMPORT */
  #define CLOUDSERVICES_EXTERN_TEMPLATE
#endif

#if defined(BUILD_CLOUDSERVICES_C_DLL)
  #define CLOUDSERVICES_C_EXPORT DECL_EXPORT
#else
  #define CLOUDSERVICES_C_EXPORT /* DECL_IMPORT */
  #define CLOUDSERVICES_C_EXTERN_TEMPLATE
#endif

#endif // IG_NUANCE_CLOUDSERVICES_CLOUDSERVICES_API_DEFS_H

/**********************************************************************************************************************/
