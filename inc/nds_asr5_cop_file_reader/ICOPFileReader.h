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
 *  Declaration of nuance_cvi_ICOPFileReader class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_cvi  nuance_cvi
 *  @{
 *  @addtogroup ICOPFileReader
 *  @{
 *  @file ICOPFileReader.h
 *
 *  @brief  The class implements the interface reading from Categorized Orthographic Phonetic (COP) files. <p>
 */

#ifndef NUANCE_CVI_ICOPFILEREADER_H
#define NUANCE_CVI_ICOPFILEREADER_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  The class implements the interface reading from Categorized Orthographic Phonetic (COP) files. <p>
 */
struct _nuance_cvi_ICOPFileReader;
/**
 *  @brief  The class implements the interface reading from Categorized Orthographic Phonetic (COP) files. <p>
 */
typedef struct _nuance_cvi_ICOPFileReader nuance_cvi_ICOPFileReader;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "cvi_api_defs.h"

/* API types */
#include "IContentFormat.h"
#include "IContentValues.h"
#include "IPhoneticsConverter.h"
#include "ModificationType.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates a new COPFileReader instance.
 *
 *  @param[in]     cOPFilePath     path to the COP file
 *  @param[out]    cOPFileReader   the new object
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_ICOPFileReader_create
(
    const LH_CHAR *cOPFilePath,
    nuance_cvi_ICOPFileReader **cOPFileReader
);


/**
 *  get the EDB table id of the cop file (EDBTableID)
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_String *nuance_cvi_ICOPFileReader_getEDBTableID(const nuance_cvi_ICOPFileReader *instance);


/**
 *  get the EDB table update type of the cop file (EDBTableUpdateType)
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_String *nuance_cvi_ICOPFileReader_getEDBTableUpdateType(const nuance_cvi_ICOPFileReader *instance);


/**
 *  get the EDB table update mode of the cop file (EDBTableUpdateMode)
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_String *nuance_cvi_ICOPFileReader_getEDBTableUpdateMode(const nuance_cvi_ICOPFileReader *instance);


/**
 *  get the EDB table update id of the cop file (EDBTableUpdateID)
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_String *nuance_cvi_ICOPFileReader_getEDBTableUpdateID(const nuance_cvi_ICOPFileReader *instance);


/**
 *  get the EDB database id of the cop file (EDBDatabaseID)
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_String *nuance_cvi_ICOPFileReader_getEDBDatabaseID(const nuance_cvi_ICOPFileReader *instance);


/**
 *  get the EDB previous table update id of the cop file (EDBPreviousTableUpdateID)
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_String *nuance_cvi_ICOPFileReader_getEDBPreviousTableUpdateID(const nuance_cvi_ICOPFileReader *instance);


/**
 *  set the phonetics converter for cop files doesn't use LH+ phonetics
 *
 *  @param[in,out] instance             The instance pointer
 *  @param[in]     phoneticsConverter   The phonetics converter
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_ICOPFileReader_setPhoneticsConverter
(
    nuance_cvi_ICOPFileReader *instance,
    nuance_cvi_IPhoneticsConverter *phoneticsConverter
);


/**
 *  Called once at the start of the iteration.
 *  After this call the current position is invalid. Use 'next' to go to the first entry.
 *  The application can use the \p contentFormat (map with expected key/value pairs) for validation,
 *  i.e. to make sure the data includes at least all the required fields specified in the configuration
 *  and can avoid processing those fields which are not wanted.
 *
 *  \n
 *
 *  The data ID allows the application to deduce the state of the dynamic content consumer.
 *  This data ID is provided to Dynamic Content Consumer and stored together with persistent context.
 *  Next time when the context is loaded application is notified with the last data ID.
 *  Based on this data ID the application can know whether this data has already been added to Dynamic Content Consumer.
 *
 *  @param[in,out] instance        The instance pointer
 *  @param[in]     contentFormat   Describes the format of the content
 *  @param[out]    dataId          The output parameter to get the data ID back from the application to the framework.
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_ICOPFileReader_start
(
    nuance_cvi_ICOPFileReader *instance,
    const nuance_cvi_IContentFormat *contentFormat,
    nuance_common_String **dataId
);


/**
 *  Checks whether or not there is a next entry.
 *  Advances to the next entry if available.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[out]    hasNext   Boolean indicating whether or not there is a next entry
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_ICOPFileReader_next
(
    nuance_cvi_ICOPFileReader *instance,
    LH_BOOL *hasNext
);


/**
 *  Get the value at the current position.
 *  The implementor should fill the contentValues with the keys for which it has a value.
 *  For example, if an address book contains for one of the content values a last_name,
 *  then the first_name key does not need to be passed.
 *
 *  @param[in,out] instance           The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_ICOPFileReader_get
(
    nuance_cvi_ICOPFileReader *instance,
    nuance_cvi_IContentValues *contentValues,
    nuance_cvi_ModificationType *modificationType
);


/**
 *  Terminate the iteration.
 *  Used to free resources that are no longer needed (e.g. close open streams).
 *
 *  @param[in,out] instance The instance pointer
 *
 */
CVI_C_EXPORT nuance_common_ResultCode nuance_cvi_ICOPFileReader_finish(nuance_cvi_ICOPFileReader *instance);


/**
 *  Destructor
 */
CVI_C_EXPORT void nuance_cvi_ICOPFileReader_destroy(nuance_cvi_ICOPFileReader *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_CVI_ICOPFILEREADER_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
