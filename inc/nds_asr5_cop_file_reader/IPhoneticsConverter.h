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
 *  Declaration of nuance_cvi_IPhoneticsConverter class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cvi  nuance_cvi
 *  @{
 *  @addtogroup IPhoneticsConverter
 *  @{
 *  @file IPhoneticsConverter.h
 *
 *  @brief  Interface to convert phonetics to LH+. <p>
 */

#ifndef NUANCE_CVI_IPHONETICSCONVERTER_H
#define NUANCE_CVI_IPHONETICSCONVERTER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface to convert phonetics to LH+. <p>
 */
struct _nuance_cvi_IPhoneticsConverter;
/**
 *  @brief  Interface to convert phonetics to LH+. <p>
 */
typedef struct _nuance_cvi_IPhoneticsConverter nuance_cvi_IPhoneticsConverter;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cvi_api_defs.h"

/* API types */
#include "ResultCode.h"
#include "StringList.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
/**
 *  return the list of names in the content in the content value
 *  This function returns a copy of the list of names, any modification done on this list has no impact on the
 *  dynamic content consumer.
 *
 *  @param[in,out] instance          The instance pointer
 *  @param[in]     token             The phonetics read from cop file
 *  @param[out]    lhPlusPhonetics   The phnetics in LH+ format
 *
 */
typedef nuance_common_ResultCode (*FUNC_nuance_cvi_IPhoneticsConverter_convertToLhPlus)
(
    void *instance,
    const LH_CHAR *token,
    nuance_common_StringList **lhPlusPhonetics
);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Interface to convert phonetics to LH+. <p>
 */
struct _vtable_nuance_cvi_IPhoneticsConverter
{
    /**
     *  return the list of names in the content in the content value
     *  This function returns a copy of the list of names, any modification done on this list has no impact on the
     *  dynamic content consumer.
     *
     *  @param[in,out] instance          The instance pointer
     *  @param[in]     token             The phonetics read from cop file
     *  @param[out]    lhPlusPhonetics   The phnetics in LH+ format
     *
     */
    FUNC_nuance_cvi_IPhoneticsConverter_convertToLhPlus convertToLhPlus;

};
/**
 *  @brief  Interface to convert phonetics to LH+. <p>
 */
typedef struct _vtable_nuance_cvi_IPhoneticsConverter vtable_nuance_cvi_IPhoneticsConverter;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
CVI_C_EXPORT nuance_cvi_IPhoneticsConverter *nuance_cvi_IPhoneticsConverter_create
(
    const vtable_nuance_cvi_IPhoneticsConverter *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
CVI_C_EXPORT void nuance_cvi_IPhoneticsConverter_destroy(nuance_cvi_IPhoneticsConverter *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CVI_IPHONETICSCONVERTER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
