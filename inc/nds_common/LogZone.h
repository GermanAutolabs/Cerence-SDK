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
 *  Declaration of nuance_common_LogZone enumeration type
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common nuance_common
 * @{
 *  @addtogroup LogZone
 *  @{
 *  @file LogZone.h
 * @brief Defines enumeration LogZone
 */

#ifndef NUANCE_COMMON_LOGZONE_H
#define NUANCE_COMMON_LOGZONE_H

#include "lh_types.h"
#include "common_api_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief The enumeration is used to indicate the severity / type of a log message.<p>
 *
 *  Log zones are used to select a certain type of logger output.
 *  Multiple log zones can be combined in the logger configuration, e.g. a consumer can set <tt>zones=LOG_ERROR|LOG_INFO</tt> to receive ERROR as well as INFO messages.
 *
 *  In the logging configuration, a special zone <tt>LOG_ALL_TEXT</tt> can be used.
 *  It is defined as <tt>LOG_FATAL|LOG_ERROR|LOG_WARNING|LOG_PERFORMANCE_WARNING|LOG_INFO|LOG_EXTERNAL_FUNC|LOG_EXTERNAL_PARAM|LOG_INTERNAL_FUNC|LOG_INTERNAL_PARAM</tt>.
 *
 *  Note that the binary data log zone <tt>LOG_DATA</tt> cannot be combined with other log zones.
 */
typedef enum
{
    NUANCE_COMMON_LOG_FATAL,                /**< All events that are a show stopper for the running application */
    NUANCE_COMMON_LOG_ERROR,                /**< All events that are error conditions but recoverable */
    NUANCE_COMMON_LOG_WARNING,              /**< Information that is useful to check the correct functionality */
    NUANCE_COMMON_LOG_PERFORMANCE_WARNING,  /**< Information that the system performance is worse than expected */
    NUANCE_COMMON_LOG_INFO,                 /**< More information that is useful to check the correct functionality */
    NUANCE_COMMON_LOG_CORE_INFO,            /**< Specific core information. Emitted on dedicated requirement only. */
    /**< This zone is not part of the LOG_ALL_TEXT configuration parameter. */
    NUANCE_COMMON_LOG_TIMING_ANALYSIS,      /**< Log timing of audio chunks in the whole backbone for detailed offline analysis. */
    /**< This zone is not part of the LOG_ALL_TEXT configuration parameter. */
    NUANCE_COMMON_LOG_EXTERNAL_FUNC,        /**< Trace entry and exit of external functions */
    NUANCE_COMMON_LOG_EXTERNAL_PARAM,       /**< Trace parameters of external functions */
    NUANCE_COMMON_LOG_INTERNAL_FUNC,        /**< Trace entry and exit of internal functions */
    NUANCE_COMMON_LOG_INTERNAL_PARAM,       /**< Trace parameters of internal functions */
    NUANCE_COMMON_LOG_DEBUG,                /**< Use for logging of detailed information required for the debugging purposes. */
    /**< This zone is not part of the LOG_ALL_TEXT configuration parameter. */
    NUANCE_COMMON_LOG_DEBUG_FUNC,           /**< Use for logging entry and exit points of the functions that gets called very frequently so they can be analyzed and */
    /**< traced separately from other debug traces. This zone is not part of the LOG_ALL_TEXT configuration parameter. */
    NUANCE_COMMON_LOG_DATA,                 /**< Trace binary data. */
    NUANCE_COMMON_LOG_CLOUD                 /**< Use for logging text to cloud. */
} nuance_common_LogZone;

COMMON_C_EXPORT const LH_CHAR *nuance_common_LogZone_toString(nuance_common_LogZone enumValue);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_LOGZONE_H */

/** @} */
/** @} */

