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
 *  Declaration of nuance_asr5_IContentValuesIterator class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_asr5  nuance_asr5
 *  @{
 *  @addtogroup IContentValuesIterator
 *  @{
 *  @file IContentValuesIterator.h
 *
 *  @brief  Abstract interface which the dynamic content consumer uses to pull the information.  <p>
 *
 *  This class declares an interface which can be implemented by the customer to
 *  pass the dynamic content to the dynamic content consumer.
 *
 *  \b
 *  Note: Each dynamic content consumer operates in its own worker thread. These functions will be called
 *  from within this thread.
 *  \sa ICOPFileReader, IContentValues, IContentFormat
 *  \sa IDynamicContentConsumer
 */

#ifndef NUANCE_ASR5_ICONTENTVALUESITERATOR_H
#define NUANCE_ASR5_ICONTENTVALUESITERATOR_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Abstract interface which the dynamic content consumer uses to pull the information.  <p>
 *
 *  This class declares an interface which can be implemented by the customer to
 *  pass the dynamic content to the dynamic content consumer.
 *
 *  \b
 *  Note: Each dynamic content consumer operates in its own worker thread. These functions will be called
 *  from within this thread.
 *  \sa ICOPFileReader, IContentValues, IContentFormat
 *  \sa IDynamicContentConsumer
 */
struct _nuance_asr5_IContentValuesIterator;
/**
 *  @brief  Abstract interface which the dynamic content consumer uses to pull the information.  <p>
 *
 *  This class declares an interface which can be implemented by the customer to
 *  pass the dynamic content to the dynamic content consumer.
 *
 *  \b
 *  Note: Each dynamic content consumer operates in its own worker thread. These functions will be called
 *  from within this thread.
 *  \sa ICOPFileReader, IContentValues, IContentFormat
 *  \sa IDynamicContentConsumer
 */
typedef struct _nuance_asr5_IContentValuesIterator nuance_asr5_IContentValuesIterator;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "asr5_api_defs.h"

/* API types */
#include "IContentFormat.h"
#include "IContentValues.h"
#include "ModificationType.h"
#include "ResultCode.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/* Function pointers for pure virtual methods */
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
typedef nuance_common_ResultCode (*FUNC_nuance_asr5_IContentValuesIterator_start)
(
    void *instance,
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
typedef nuance_common_ResultCode (*FUNC_nuance_asr5_IContentValuesIterator_next)
(
    void *instance,
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
typedef nuance_common_ResultCode (*FUNC_nuance_asr5_IContentValuesIterator_get)
(
    void *instance,
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
typedef nuance_common_ResultCode (*FUNC_nuance_asr5_IContentValuesIterator_finish)(void *instance);


/** Vtable for providing overridden class functions. **/
/**
 *  @brief  Abstract interface which the dynamic content consumer uses to pull the information.  <p>
 *
 *  This class declares an interface which can be implemented by the customer to
 *  pass the dynamic content to the dynamic content consumer.
 *
 *  \b
 *  Note: Each dynamic content consumer operates in its own worker thread. These functions will be called
 *  from within this thread.
 *  \sa ICOPFileReader, IContentValues, IContentFormat
 *  \sa IDynamicContentConsumer
 */
struct _vtable_nuance_asr5_IContentValuesIterator
{
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
    FUNC_nuance_asr5_IContentValuesIterator_start start;

    /**
     *  Checks whether or not there is a next entry.
     *  Advances to the next entry if available.
     *
     *  @param[in,out] instance  The instance pointer
     *  @param[out]    hasNext   Boolean indicating whether or not there is a next entry
     *
     */
    FUNC_nuance_asr5_IContentValuesIterator_next next;

    /**
     *  Get the value at the current position.
     *  The implementor should fill the contentValues with the keys for which it has a value.
     *  For example, if an address book contains for one of the content values a last_name,
     *  then the first_name key does not need to be passed.
     *
     *  @param[in,out] instance           The instance pointer
     *
     */
    FUNC_nuance_asr5_IContentValuesIterator_get get;

    /**
     *  Terminate the iteration.
     *  Used to free resources that are no longer needed (e.g. close open streams).
     *
     *  @param[in,out] instance The instance pointer
     *
     */
    FUNC_nuance_asr5_IContentValuesIterator_finish finish;

};
/**
 *  @brief  Abstract interface which the dynamic content consumer uses to pull the information.  <p>
 *
 *  This class declares an interface which can be implemented by the customer to
 *  pass the dynamic content to the dynamic content consumer.
 *
 *  \b
 *  Note: Each dynamic content consumer operates in its own worker thread. These functions will be called
 *  from within this thread.
 *  \sa ICOPFileReader, IContentValues, IContentFormat
 *  \sa IDynamicContentConsumer
 */
typedef struct _vtable_nuance_asr5_IContentValuesIterator vtable_nuance_asr5_IContentValuesIterator;


/**
 *  Constructor
 *
 *  @param[in]  cb_interface struct containing callback functions implemented by the user
 *  @param[in]  userData    user data which is passed to each callback function as first parameter
 */
ASR5_C_EXPORT nuance_asr5_IContentValuesIterator *nuance_asr5_IContentValuesIterator_create
(
    const vtable_nuance_asr5_IContentValuesIterator *cb_interface,
    void *userData
);

/**
 *  Destructor
 */
ASR5_C_EXPORT void nuance_asr5_IContentValuesIterator_destroy(nuance_asr5_IContentValuesIterator *);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_ASR5_ICONTENTVALUESITERATOR_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
