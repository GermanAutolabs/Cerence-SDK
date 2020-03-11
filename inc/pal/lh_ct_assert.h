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


#ifndef LH_CT_ASSERT_H
#define LH_CT_ASSERT_H


#ifdef __cplusplus
extern "C" {
#endif

/* stuff below is a copy from a_ct_assert.h from vocon.  PAL must be
   usable standalone, so we need to copy the code. It needed to be
   changed to avoid complications when pal headers and vocon headers
   are used at the same time. 

   But we obey to the same external define that controls whether we
   want this enabled or not: LH_DISABLE_CT_ASSERT, default is of
   course have it enabled 

   Stefan Sablatnög
*/


#define PAL_ENABLE_CT_ASSERT

/* making sure we can disable it for poor compilers (that crash on divide by  zero) */
#ifdef LH_DISABLE_CT_ASSERT
  #undef PAL_ENABLE_CT_ASSERT
#endif

/* compile-time assertions */
#ifdef PAL_ENABLE_CT_ASSERT

  #define PAL_UNIQUE_NAME_               PAL_MAKE_NAME(__LINE__)
  #define PAL_MAKE_NAME(line)            PAL_MAKE_NAME2(line)
  #define PAL_MAKE_NAME2(line)           my_unique_id_ ## line

  /*lint -e753 */
  /* 753 reports unused enum (and cannot be reactivated: +e753) => not compatible with CT_ASSERT() */

  /*PRQA S 4105 ++  */ /* Right hand operand of arithmetic or bitwise operator is a "boolean" expression */

  /* compile-time assert to be used at the file scope */
  #define PAL_CT_ASSERT_FS( expr )                         \
    /*lint -save -e414 -e514 */                        \
    /*lint -esym(749, my_unique_id_*) */               \
    enum {PAL_UNIQUE_NAME_ = 1/( (int) (expr) )}             \
    /*lint -restore */

  /* compile-time assert to be used inside functions */
  #define PAL_CT_ASSERT( expr )                            \
    /*lint -save -e414  -e514 -e717 */                 \
    /*lint -esym(749, my_assert_) */                   \
    do { enum {my_assert_ = 1/( (int) (expr) )}; } while(0)    \
    /*lint -restore */

  /*PRQA S 4105 --  */

#else  /* PAL_ENABLE_CT_ASSERT */
  #define PAL_CT_ASSERT_FS( expr )
  #define PAL_CT_ASSERT( expr )
#endif /* PAL_ENABLE_CT_ASSERT */

/*
    When a compile-time assert fails, you'll see a syntax error, since the C language itself doesn't have compile-time assertions
    You will see the following error:
    For Microsoft compilers:
      error C2057: expected constant expression
    For Gnu compilers:
      error: enumerator value for '...' not integer constant
*/
/*
    The comments above /lint -.../ and /PRQA S .../ are meant for Gimpel PC Lint and PRQA QAC respectively
    They serve here as documentation (to know what rules of good C programming we have to infringe in order to implement a feature that the language should have provided).
    They don't pretend to shut off absolutely all Lint or QAC messages. The best way for a clean checking with Lint or QAC is
      still to define LH_DISABLE_CT_ASSERT in the build scripts
*/

#ifdef __cplusplus
}
#endif

#endif /* LH_CT_ASSERT_H */
