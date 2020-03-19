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

#ifndef IG_NUANCE_CVI_API_DEFS_H
#define IG_NUANCE_CVI_API_DEFS_H

#include "global_api_defs.h"

// Note: This macro is based on the namespace of the component.
//       See ../../../../../../nds_common/components/common/build/Component.py # self.ccpp_defines_cpp
#if defined(BUILD_CVI_DLL)
  #define CVI_EXPORT DECL_EXPORT
#else
  #define CVI_EXPORT /* DECL_IMPORT */
  #define CVI_EXTERN_ASR
#endif

#if defined(BUILD_CVI_C_DLL)
  #define CVI_C_EXPORT DECL_EXPORT
#else
  #define CVI_C_EXPORT /* DECL_IMPORT */
  #define CVI_C_EXTERN_ASR
#endif

#endif // IG_NUANCE_CVI_API_DEFS_H

/**********************************************************************************************************************/
