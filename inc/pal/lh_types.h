/* -------------------------------------------------------------------------+
 |                               Cerence, Inc.                              |
 + -------------------------------------------------------------------------*/

/* --------------------------- COPYRIGHT INFORMATION -----------------------+
 |                                                                          |
 | This program contains proprietary information that is a trade secret     |
 | of Cerence, Inc. and also is protected as an unpublished                 |
 | work under applicable Copyright laws. Recipient is to retain this        |
 | program in confidence and is not permitted to use or make copies         |
 | thereof other than as permitted in a prior written agreement with        |
 | Cerence, Inc. or its affiliates.                                         |
 |                                                                          |
 | Copyright (c) 2020 Cerence, Inc.                                         |
 | All rights reserved. Company confidential.                               |
 |                                                                          |
 +--------------------------------------------------------------------------*/


/**
 *  Declaration of basic types
 */
 
#ifndef LH_TYPES_H
#define LH_TYPES_H

#include "lh_ct_assert.h"
#include "starrec_pal_limits.h"

#ifdef __cplusplus

/**
 * gcc >= 4.6 requires the following for using size_t without namespace in c++.
 * see test /pal/sw/unittest/tests/test_compiler.cpp
 */
#if  (__GNUC__ >= 5) && defined(__QNX__)
/* armv7_qnx700 and aarch64_qnx700 has gcc 5.4, but nds compilation failes if cstddef is included */
#elif  (__GNUC__ == 4 && __GNUC_MINOR__ >= 6) || (__GNUC__ >= 5)
#include <cstddef>
using std::size_t;
#endif

extern "C" {
#endif

typedef unsigned char   LH_U8;
#define LH_U8_MIN       0
#define LH_U8_MAX       UCHAR_MAX

typedef signed char     LH_S8;
#define LH_S8_MIN       SCHAR_MIN
#define LH_S8_MAX       SCHAR_MAX

typedef unsigned short  LH_U16;
#define LH_U16_MIN      0
#define LH_U16_MAX      USHRT_MAX

typedef signed short    LH_S16;
#define LH_S16_MIN      SHRT_MIN
#define LH_S16_MAX      SHRT_MAX

typedef unsigned int    LH_U32;
#define LH_U32_MIN      0
#define LH_U32_MAX      UINT_MAX

typedef signed int      LH_S32;
#define LH_S32_MIN      INT_MIN
#define LH_S32_MAX      INT_MAX

#ifndef LH_S64_MAX
#define LH_S64_MAX      9223372036854775807LL
#endif

#ifndef LH_S64_MIN
#define LH_S64_MIN      (-LH_S64_MAX - 1LL)
#endif

#ifndef LH_U64_MAX
#define LH_U64_MAX      18446744073709551615ULL
#endif

#ifndef LH_U64_MIN
#define LH_U64_MIN      0ULL
#endif


/* Stolen from starrec_pal_stddef.h */
#if defined(_WIN32)
typedef __int64         LH_S64;
#else
typedef long long int   LH_S64;
#endif

#if defined(_WIN32)
typedef unsigned __int64       LH_U64;
#else
typedef unsigned long long int LH_U64;
#endif

#if defined(_WIN32)
#if !defined(_W64)
#if !defined(__midl) && (defined(_X86_) || defined(_M_IX86)) && _MSC_VER >= 1300 && _MSC_VER <= 1800
#define _W64 __w64
#else
#define _W64
#endif
#endif
#endif

#if defined(_WIN64)
typedef unsigned __int64 LH_SIZE_T;
#else
#  if defined(_WIN32)
typedef unsigned int _W64 LH_SIZE_T;
#  else
#    if defined(__LP64__)
typedef unsigned long LH_SIZE_T;
#    else
typedef unsigned int LH_SIZE_T;
#    endif
#  endif
#endif


/*   Unfortunately SIZE_MAX is not defined for all platforms,
 *   hence max(size_t) similar to the typedef above:
 */
#if defined(SIZE_MAX)
#   define LH_SIZE_T_MAX  SIZE_MAX
#else
#  if defined(__LP64__)
#       define LH_SIZE_T_MAX  LH_U64_MAX
#  else
#       define LH_SIZE_T_MAX  UINT_MAX
#  endif
#endif

#define LH_SIZE_T_MIN  0


#if !defined( LH_SIZE_T_MAX )
#error "LH_SIZE_T_MAX define is missing"
#endif


/**
 *  @attention if SIGNED_STARREC_CHAR is defined, this type is defined
 *  as signed char, which may lead to a lot of warnings on some
 *  platforms. The clear recommendation is not to define
 *  SIGNED_STARREC_CHAR, which will remove the need for many casts and
 *  thus improve the compile time type checking that can be done.
 */
#if defined(SIGNED_STARREC_CHAR)
typedef signed char     LH_CHAR;
#else
typedef char            LH_CHAR;
#endif

typedef unsigned short  LH_WCHAR;


/*
 *   Pal's typedef of LH_BOOL as an int  is the pure and preferred solution.
 *   Projects may use LH_BOOL_DEFINED to overwrite it - at their own risk, though.
 */
#ifndef LH_BOOL_DEFINED

typedef int             LH_BOOL;
#define LH_FALSE        0
#define LH_TRUE         1

#define LH_BOOL_DEFINED

#endif

/*
 *   Null pointer
 */
#define LH_NULL         NULL

/*
 *  Generic Mapping of float datatypes to LH_xxx ones
 *  Notice that we avoid including starrec_pal_float.h  
 *  as only LH_xxx types shall be exposed via lh_types.h
 */
typedef float           LH_FLOAT;
typedef double          LH_DOUBLE;



/* check our assumptions about data type sizes */
PAL_CT_ASSERT_FS(sizeof(LH_BOOL)  ==  4);
PAL_CT_ASSERT_FS(sizeof(LH_WCHAR) ==  2);
PAL_CT_ASSERT_FS(sizeof(LH_CHAR)  ==  1);
PAL_CT_ASSERT_FS(sizeof(LH_S32)   ==  4);
PAL_CT_ASSERT_FS(sizeof(LH_U32)   ==  4);
PAL_CT_ASSERT_FS(sizeof(LH_S16)   ==  2);
PAL_CT_ASSERT_FS(sizeof(LH_U16)   ==  2);
PAL_CT_ASSERT_FS(sizeof(LH_S8)    ==  1);
PAL_CT_ASSERT_FS(sizeof(LH_U8)    ==  1);
PAL_CT_ASSERT_FS(sizeof(LH_S64)   ==  8);

#ifdef __cplusplus
}
#endif

#endif /* LH_TYPES_H */
