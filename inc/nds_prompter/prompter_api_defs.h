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

#ifndef IG_NUANCE_PROMPTER_PROMPTER_API_DEFS_H
#define IG_NUANCE_PROMPTER_PROMPTER_API_DEFS_H

#include "global_api_defs.h"

#if defined(BUILD_PROMPTER_DLL)
  #define PROMPTER_EXPORT DECL_EXPORT
#else
  #define PROMPTER_EXPORT /* DECL_IMPORT */
#endif

#if defined(BUILD_PROMPTER_C_DLL)
  #define PROMPTER_C_EXPORT DECL_EXPORT
#else
  #define PROMPTER_C_EXPORT /* DECL_IMPORT */
#endif

#endif // IG_NUANCE_PROMPTER_PROMPTER_API_DEFS_H

/**********************************************************************************************************************/
