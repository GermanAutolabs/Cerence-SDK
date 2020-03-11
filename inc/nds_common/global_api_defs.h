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

#ifndef IG_NUANCE_GLOBAL_API_DEFS_H
#define IG_NUANCE_GLOBAL_API_DEFS_H


#if defined(WIN32) || defined(_WIN32_WCE)
  #pragma warning(disable: 4231) /* nonstandard extension used : 'extern' before template explicit instantiation */
  #pragma warning(disable: 4251) /* class 'X' needs to have dll-interface to be used by clients of class 'Y' */
  #pragma warning(disable: 4275) /* non dll-interface class 'X' used as base for dll-interface class 'Y' */
#endif

#ifndef DECL_EXPORT
  #if defined(WIN32) || defined(_WIN32_WCE)
    #define DECL_EXPORT __declspec(dllexport)
  #else
    #define DECL_EXPORT __attribute__((visibility("default")))
  #endif
#endif

#ifndef DECL_IMPORT
  #if defined(WIN32) || defined(_WIN32_WCE)
    #define DECL_IMPORT __declspec(dllimport)
  #else
    #define DECL_IMPORT
  #endif
#endif

#endif // IG_NUANCE_GLOBAL_API_DEFS_H

/**********************************************************************************************************************/
