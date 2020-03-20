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
 *  Declaration of nuance_common_IDictionary class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup IDictionary
 *  @{
 *  @file IDictionary.h
 *
 *  @brief  IDictionary storage class. <p>
 *
 *  This class allows to store key-value pairs of different data type.
 */

#ifndef NUANCE_COMMON_IDICTIONARY_H
#define NUANCE_COMMON_IDICTIONARY_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  IDictionary storage class. <p>
 *
 *  This class allows to store key-value pairs of different data type.
 */
struct _nuance_common_IDictionary;
/**
 *  @brief  IDictionary storage class. <p>
 *
 *  This class allows to store key-value pairs of different data type.
 */
typedef struct _nuance_common_IDictionary nuance_common_IDictionary;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "ByteArray.h"
#include "DataType.h"
#include "ISequence.h"
#include "ResultCode.h"
#include "StringList.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  Creates an empty IDictionary instance.
 *
 *  @param[out]    instance   IDictionary instance.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_create(nuance_common_IDictionary **instance);


/**
 *  Creates a new reference to an already existing dictionary.
 *
 *  @param[in]     origin     Already existing IDictionary instance.
 *  @param[out]    instance   New IDictionary instance.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_createFromDictionary
(
    const nuance_common_IDictionary *origin,
    nuance_common_IDictionary **instance
);


/**
 *  Creates an IDictionary instance from an JSON string.
 *
 *  @param[in]     json       JSON formated string.
 *  @param[out]    instance   IDictionary instance.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_createFromJson
(
    const LH_CHAR *json,
    nuance_common_IDictionary **instance
);


/**
 *  @brief  Add a key/data pair of type IDictionary. <p>
 *
 *  This mehtod adds an IDictionary instance to this Dictionary. The hosting Dictionary internally increases
 *  the reference count of the "Guest-Dictionary", which can be deleted or modified directly after the put call.
 *  Put of an already existing key, will replace the old dictionary through the new one.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key under which the data should be inserted.
 *  @param[in]     data   IDictionary instance to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_putDictionary
(
    nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    const nuance_common_IDictionary *data
);


/**
 *  @brief  Add a key/data pair of type ISequence. <p>
 *
 *  This mehtod adds an ISequence instance to this Dictionary. The hosting Dictionary internally increases
 *  the reference count of the Sequence, which can be deleted or modified directly after the put call.
 *  Put of an already existing key, will replace the old sequence through the new one.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key under which the data should be inserted.
 *  @param[in]     data   ISequence instance to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_putSequence
(
    nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    const nuance_common_ISequence *data
);


/**
 *  @brief  Add an key/data pair of type Integer. <p>
 *
 *  This mehtod adds an Integer to this Dictionary.
 *  Put of an already existing key, will replace the old data through the new one.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key under which the data should be inserted.
 *  @param[in]     data   Integer to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_putInteger
(
    nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    LH_S32 data
);


/**
 *  @brief  Add an key/data pair of type String. <p>
 *
 *  This mehtod adds a String to this Dictionary.
 *  Put of an already existing key, will replace the old data through the new one.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key under which the data should be inserted.
 *  @param[in]     data   String to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_putString
(
    nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    const LH_CHAR *data
);


/**
 *  @brief  Add an key/data pair of type ByteArray. <p>
 *
 *  This mehtod adds a ByteArray to this Dictionary.
 *  Put of an already existing key, will replace the old data through the new one.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key under which the data should be inserted.
 *  @param[in]     data   ByteArray to store.
 *  @param[in]     ndata  Number of elements in data
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_putBytes
(
    nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    LH_S8  const *data, LH_S32 ndata
);


/**
 *  @brief  Add an key/data pair of type Boolean. <p>
 *
 *  This method adds a Boolean to this Dictionary.
 *  Put of an already existing key, will replace the old data through the new one.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key under which the data should be inserted.
 *  @param[in]     data   Boolean to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_putBoolean
(
    nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    LH_BOOL data
);


/**
 *  @brief  Add an key/data pair of type Double. <p>
 *
 *  This method adds a Double to this Dictionary.
 *  Put of an already existing key, will replace the old data through the new one.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key under which the data should be inserted.
 *  @param[in]     data   Double to store.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_putDouble
(
    nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    LH_DOUBLE data
);


/**
 *  @brief  Add an key/data pair of type NULL. <p>
 *
 *  This mehtod adds a NULL data to this Dictionary.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key   Key under which the data should be inserted.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_putNull
(
    nuance_common_IDictionary *instance,
    const LH_CHAR *key
);


/**
 *  @brief  Returns the IDictionary instance that matches the specified key. <p>
 *
 *  If the key does not exist or is not of type Dictionary, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key to find in the Dictionary.
 *  @param[out]    data   IDictionary instance that matches the key.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_getDictionary
(
    const nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    nuance_common_IDictionary **data
);


/**
 *  @brief  Returns the ISequence instance that matches the specified key. <p>
 *
 *  If the key does not exist or is not of type Sequence, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key to find in the Dictionary.
 *  @param[out]    data   ISequence instance that matches the key.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_getSequence
(
    const nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    nuance_common_ISequence **data
);


/**
 *  @brief  Returns the Integer that matches the specified key. <p>
 *
 *  If the key does not exist or is not of type Integer, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key to find in the Dictionary.
 *  @param[out]    data   Integer that matches the key.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_getInteger
(
    const nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    LH_S32 *data
);


/**
 *  @brief  Returns the String that matches the specified key. <p>
 *
 *  If the key does not exist or is not of type String, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key to find in the Dictionary.
 *  @param[out]    data   String that matches the key.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_getString
(
    const nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    nuance_common_String **data
);


/**
 *  @brief  Returns the ByteArray that matches the specified key. <p>
 *
 *  If the key does not exist or is not of type Bytes, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key to find in the Dictionary.
 *  @param[out]    data   ByteArray that matches the key.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_getBytes
(
    const nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    nuance_common_ByteArray **data
);


/**
 *  @brief  Returns the Boolean that matches the specified key. <p>
 *
 *  If the key does not exist or is not of type Boolean, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key to find in the Dictionary.
 *  @param[out]    data   Boolean that matches the key.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_getBoolean
(
    const nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    LH_BOOL *data
);


/**
 *  @brief  Returns the Double that matches the specified key. <p>
 *
 *  If the key does not exist or is not of type Double, ERROR is returned.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key to find in the Dictionary.
 *  @param[out]    data   Double that matches the key.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_getDouble
(
    const nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    LH_DOUBLE *data
);


/**
 *  @brief  Returns all keys stored in the Dictionary. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    keys   List of all keys stored in the Dictionary.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_getKeys
(
    const nuance_common_IDictionary *instance,
    nuance_common_StringList **keys
);


/**
 *  @brief  Returns the data type of a given key. <p>
 *
 *  The received data type can be used to choose the correct getter method for this type.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key    Key to find in the Dictionary.
 *  @param[out]    type   Data type of the Sequence element.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_getType
(
    const nuance_common_IDictionary *instance,
    const LH_CHAR *key,
    nuance_common_DataType *type
);


/**
 *  @brief  Retuns the content of the dictionary in JSON notation. <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    json   JSON formated string.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_toJson
(
    const nuance_common_IDictionary *instance,
    nuance_common_String **json
);


/**
 *  @brief  Returns the hash code of the given instance.  <p>
 *
 *  The hashCode method returns the same value for the two Dictionary instances which include exact the same underlining objects,
 *  on different platforms.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[out]    hashCode   Calculated hash code for this instance.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_getHashCode
(
    const nuance_common_IDictionary *instance,
    LH_S32 *hashCode
);


/**
 *  @brief  This method removes a key from this Dictionary.  <p>
 *
 *  @param[in,out] instance The instance pointer
 *  @param[in]     key   Key which needs to be removed.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_IDictionary_remove
(
    nuance_common_IDictionary *instance,
    const LH_CHAR *key
);


/**
 *  Destructor
 */
COMMON_C_EXPORT void nuance_common_IDictionary_destroy(nuance_common_IDictionary *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_IDICTIONARY_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
