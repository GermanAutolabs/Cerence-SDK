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
 *  Declaration of nuance_common_ISequence class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup ISequence
 *  @{
 *  @file ISequence.h
 *
 *  @brief  ISequence storage class. <p>
 *
 *  This class allows to store a sequence of data values of different type.
 */

#ifndef NUANCE_COMMON_ISEQUENCE_H
#define NUANCE_COMMON_ISEQUENCE_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  ISequence storage class. <p>
 *
 *  This class allows to store a sequence of data values of different type.
 */
struct _nuance_common_ISequence;
/**
 *  @brief  ISequence storage class. <p>
 *
 *  This class allows to store a sequence of data values of different type.
 */
typedef struct _nuance_common_ISequence nuance_common_ISequence;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "ByteArray.h"
#include "DataType.h"
#include "IDictionary.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates an ISequence instance.
 *
 *  @param[out]    instance   Instance of Sequence data
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_create(nuance_common_ISequence **instance);


/**
 *  Creates a new reference to an already existing sequence.
 *
 *  @param[in]     origin     Already existing ISequence instance.
 *  @param[out]    instance   New ISequence instance.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_createFromSequence
(
    const nuance_common_ISequence *origin,
    nuance_common_ISequence **instance
);


/**
 *  @brief  Add a data element of type IDictionary. <p>
 *
 *  This mehtod adds an IDictionary instance to this Sequence. The Sequence internally increases
 *  the reference count of the Dictionary, which can be deleted directly after the put call.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     data   IDictionary instance to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_putDictionary
(
    nuance_common_ISequence *instance,
    const nuance_common_IDictionary *data
);


/**
 *  @brief  Add a data element of type ISequence. <p>
 *
 *  This mehtod adds an ISequence instance to this Sequence. The hosting Sequence internally increases
 *  the reference count of the "Guest-Sequence", which can be deleted directly after the put call.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     data   ISequence instance to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_putSequence
(
    nuance_common_ISequence *instance,
    const nuance_common_ISequence *data
);


/**
 *  @brief  Add a data element of type Integer. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     data   Integer to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_putInteger
(
    nuance_common_ISequence *instance,
    LH_S32 data
);


/**
 *  @brief  Add a data element of type String. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     data   String to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_putString
(
    nuance_common_ISequence *instance,
    const LH_CHAR *data
);


/**
 *  @brief  Add a data element of type ByteArray. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     data   ByteArray to store.
 *  @param[in]     ndata  Number of elements in data
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_putBytes
(
    nuance_common_ISequence *instance,
    LH_S8  const *data, LH_S32 ndata
);


/**
 *  @brief  Add a data element of type Boolean. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     data   Boolean to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_putBoolean
(
    nuance_common_ISequence *instance,
    LH_BOOL data
);


/**
 *  @brief  Add a data element of type Double. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     data   Double to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_putDouble
(
    nuance_common_ISequence *instance,
    LH_DOUBLE data
);


/**
 *  @brief  Add a data element of type NULL. <p>
 *
 *  @param[in,out] instance The instance pointer
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_putNull(nuance_common_ISequence *instance);


/**
 *  @brief  Get an IDictionary element. <p>
 *
 *  This mehtod returns the IDictionary instance stored in the Sequence at the given index.
 *  If the index is invalid or the element stored at that index is not of type Dictionary, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   Index position in the sequence.
 *  @param[out]    data    IDictionary instance.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_getDictionary
(
    const nuance_common_ISequence *instance,
    LH_S32 index,
    nuance_common_IDictionary **data
);


/**
 *  @brief  Get an ISequence element. <p>
 *
 *  This mehtod returns the ISequence instance stored in the Sequence at the given index.
 *  If the index is invalid or the element stored at that index is not of type Sequence, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   Index position in the sequence.
 *  @param[out]    data    ISequence instance.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_getSequence
(
    const nuance_common_ISequence *instance,
    LH_S32 index,
    nuance_common_ISequence **data
);


/**
 *  @brief  Get an Integer element. <p>
 *
 *  This mehtod returns the Integer stored in the Sequence at the given index.
 *  If the index is invalid or the element stored at that index is not of type Integer, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   Index position in the sequence.
 *  @param[out]    data    Integer element.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_getInteger
(
    const nuance_common_ISequence *instance,
    LH_S32 index,
    LH_S32 *data
);


/**
 *  @brief  Get an String element. <p>
 *
 *  This mehtod returns the Integer stored in the Sequence at the given index.
 *  If the index is invalid or the element stored at that index is not of type String, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   Index position in the sequence.
 *  @param[out]    data    String element.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_getString
(
    const nuance_common_ISequence *instance,
    LH_S32 index,
    nuance_common_String **data
);


/**
 *  @brief  Get an ByteArray element. <p>
 *
 *  This mehtod returns the ByteArray stored in the Sequence at the given index.
 *  If the index is invalid or the element stored at that index is not of type Bytes, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   Index position in the sequence.
 *  @param[out]    data    DataArray element.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_getBytes
(
    const nuance_common_ISequence *instance,
    LH_S32 index,
    nuance_common_ByteArray **data
);


/**
 *  @brief  Get an Boolean element. <p>
 *
 *  This mehtod returns the Boolean stored in the Sequence at the given index.
 *  If the index is invalid or the element stored at that index is not of type Bytes, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   Index position in the sequence.
 *  @param[out]    data    Boolean element.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_getBoolean
(
    const nuance_common_ISequence *instance,
    LH_S32 index,
    LH_BOOL *data
);


/**
 *  @brief  Get an Double element. <p>
 *
 *  This mehtod returns the Double stored in the Sequence at the given index.
 *  If the index is invalid or the element stored at that index is not of type Bytes, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   Index position in the sequence.
 *  @param[out]    data    Double element.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_getDouble
(
    const nuance_common_ISequence *instance,
    LH_S32 index,
    LH_DOUBLE *data
);


/**
 *  @brief  Get the number of sequence entries. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    count   Number of entries in the sequence.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_getCount
(
    const nuance_common_ISequence *instance,
    LH_S32 *count
);


/**
 *  @brief  Get the type of the data element stored at the given index. <p>
 *
 *  The received data type can be used to choose the correct getter method for this type.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   Index position in the sequence.
 *  @param[out]    type    Data type of the sequence element.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_getType
(
    const nuance_common_ISequence *instance,
    LH_S32 index,
    nuance_common_DataType *type
);


/**
 *  @brief  Retuns the content of the sequence in JSON notation. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    json   JSON formated string.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_toJson
(
    const nuance_common_ISequence *instance,
    nuance_common_String **json
);


/**
 *  @brief  This method removes an element at index position of this sequence.  <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   The position of the element to be removed.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_removeAt
(
    nuance_common_ISequence *instance,
    LH_S32 index
);


/**
 *  @brief  Replace a data element of type IDict at a given position. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   The position of the element to be replaced.
 *  @param[in]     data    IDictionary instance to replace.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_replaceDictionary
(
    nuance_common_ISequence *instance,
    LH_S32 index,
    const nuance_common_IDictionary *data
);


/**
 *  @brief  Replace a data element of type ISequence at a given position. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   The position of the element to be replaced.
 *  @param[in]     data    ISequence instance to replace.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_replaceSequence
(
    nuance_common_ISequence *instance,
    LH_S32 index,
    const nuance_common_ISequence *data
);


/**
 *  @brief  Replace a data element of type Integer at a given position. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   The position of the element to be replaced.
 *  @param[in]     data    Integer to replace.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_replaceInteger
(
    nuance_common_ISequence *instance,
    LH_S32 index,
    LH_S32 data
);


/**
 *  @brief  Replace a data element of type String at a given position. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   The position of the element to be replaced.
 *  @param[in]     data    String to replace.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_replaceString
(
    nuance_common_ISequence *instance,
    LH_S32 index,
    const LH_CHAR *data
);


/**
 *  @brief  Replace a data element of type ByteArray at a given position. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   The position of the element to be replaced.
 *  @param[in]     data    ByteArray to replace.
 *  @param[in]     ndata   Number of elements in data
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_replaceBytes
(
    nuance_common_ISequence *instance,
    LH_S32 index,
    LH_S8  const *data, LH_S32 ndata
);


/**
 *  @brief  Replace a data element of type Boolean at a given position. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   The position of the element to be replaced.
 *  @param[in]     data    Boolean to replace.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_replaceBoolean
(
    nuance_common_ISequence *instance,
    LH_S32 index,
    LH_BOOL data
);


/**
 *  @brief  Replace a data element of type Double at a given position. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   The position of the element to be replaced.
 *  @param[in]     data    Double to replace.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_replaceDouble
(
    nuance_common_ISequence *instance,
    LH_S32 index,
    LH_DOUBLE data
);


/**
 *  @brief  Replace a data element of type NULL at a given position. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     index   The position of the element to be replaced.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISequence_replaceNull
(
    nuance_common_ISequence *instance,
    LH_S32 index
);


/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_ISequence_destroy(nuance_common_ISequence *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_ISEQUENCE_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
