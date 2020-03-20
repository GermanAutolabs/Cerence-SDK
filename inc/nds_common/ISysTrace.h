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
 *  Declaration of nuance_common_ISysTrace class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_common  nuance_common
 *  @{
 *  @addtogroup ISysTrace
 *  @{
 *  @file ISysTrace.h
 *
 *  @brief  System tracing interface. <p>
 *
 *  This interface abstracts the system tracing functionality of the Nuance PAL SW layer
 *  which depending on the platform uses either a native system tracer like f.i. "ftrace"
 *  on Linux and Android platforms or a "simulated" system tracer that simply writes trace
 *  events into a file. The latter one is only capable to trace built-in events of the
 *  PAL SW layer (e.g. audio-io via PAL) and user events send via this interface, whereas
 *  the former one additionally is able to trace events of the system outside of the
 *  DragonDrive process.
 *
 *  Finally this interface allows to create a system trace over a specific time period.
 *  The tracing has to be explicitly started and stopped with a call to the 'start'
 *  respectively 'stop' function. Thereby a 'groups' filter determines which groups of
 *  trace events shall be traced. Supported trace groups are:
 *
 *  <ul>
 *  <li> 'TRCGRP_COMMON' </li>
 *  <li> 'TRCGRP_THREAD' </li>
 *  <li> 'TRCGRP_MEMORY' </li>
 *  <li> 'TRCGRP_USER' </li>
 *  <li> 'TRCGRP_FILE' </li>
 *  <li> 'TRCGRP_FILE_IO' </li>
 *  <li> 'TRCGRP_SOCKET' </li>
 *  <li> 'TRCGRP_SOCKET_IO' </li>
 *  <li> 'TRCGRP_AUDIO' </li>
 *  <li> 'TRCGRP_AUDIO_IO' </li>
 *  <li> 'TRCGRP_ERROR' </li>
 *  <li> 'TRCGRP_FATAL' </li>
 *  <li> 'TRCGRP_ALL' (includes all groups) </li>
 *  </ul>
 *
 *  Designated locations in the PAL SW layer are instrumented with built-in trace events
 *  related to specific trace groups (e.g. audio-io via trace group 'TRCGRP_AUDIO'). In
 *  addition to that the user is capable to write own user trace events to the system trace
 *  by calling 'beginUserEvent' respectively 'endUserEvent' which are implicitly related to
 *  the trace group 'TRCGRP_USER'.
 *
 *  DISCLAIMER: In the DDFW context the system tracing functionality has to be explicitly
 *  enabled with setting the configuration parameter 'DragonDriveCommonService.SysTraceEnable'
 *  (see also chapter 'configuration'), otherwise all calls to this interface are effectless.
 *  This means that all calls to the system tracing API will always immediately be answered
 *  with the result 'NUANCE_COMMON_RESULTCODE_OK' and that no system tracing file will be written.
 */

#ifndef NUANCE_COMMON_ISYSTRACE_H
#define NUANCE_COMMON_ISYSTRACE_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  System tracing interface. <p>
 *
 *  This interface abstracts the system tracing functionality of the Nuance PAL SW layer
 *  which depending on the platform uses either a native system tracer like f.i. "ftrace"
 *  on Linux and Android platforms or a "simulated" system tracer that simply writes trace
 *  events into a file. The latter one is only capable to trace built-in events of the
 *  PAL SW layer (e.g. audio-io via PAL) and user events send via this interface, whereas
 *  the former one additionally is able to trace events of the system outside of the
 *  DragonDrive process.
 *
 *  Finally this interface allows to create a system trace over a specific time period.
 *  The tracing has to be explicitly started and stopped with a call to the 'start'
 *  respectively 'stop' function. Thereby a 'groups' filter determines which groups of
 *  trace events shall be traced. Supported trace groups are:
 *
 *  <ul>
 *  <li> 'TRCGRP_COMMON' </li>
 *  <li> 'TRCGRP_THREAD' </li>
 *  <li> 'TRCGRP_MEMORY' </li>
 *  <li> 'TRCGRP_USER' </li>
 *  <li> 'TRCGRP_FILE' </li>
 *  <li> 'TRCGRP_FILE_IO' </li>
 *  <li> 'TRCGRP_SOCKET' </li>
 *  <li> 'TRCGRP_SOCKET_IO' </li>
 *  <li> 'TRCGRP_AUDIO' </li>
 *  <li> 'TRCGRP_AUDIO_IO' </li>
 *  <li> 'TRCGRP_ERROR' </li>
 *  <li> 'TRCGRP_FATAL' </li>
 *  <li> 'TRCGRP_ALL' (includes all groups) </li>
 *  </ul>
 *
 *  Designated locations in the PAL SW layer are instrumented with built-in trace events
 *  related to specific trace groups (e.g. audio-io via trace group 'TRCGRP_AUDIO'). In
 *  addition to that the user is capable to write own user trace events to the system trace
 *  by calling 'beginUserEvent' respectively 'endUserEvent' which are implicitly related to
 *  the trace group 'TRCGRP_USER'.
 *
 *  DISCLAIMER: In the DDFW context the system tracing functionality has to be explicitly
 *  enabled with setting the configuration parameter 'DragonDriveCommonService.SysTraceEnable'
 *  (see also chapter 'configuration'), otherwise all calls to this interface are effectless.
 *  This means that all calls to the system tracing API will always immediately be answered
 *  with the result 'NUANCE_COMMON_RESULTCODE_OK' and that no system tracing file will be written.
 */
struct _nuance_common_ISysTrace;
/**
 *  @brief  System tracing interface. <p>
 *
 *  This interface abstracts the system tracing functionality of the Nuance PAL SW layer
 *  which depending on the platform uses either a native system tracer like f.i. "ftrace"
 *  on Linux and Android platforms or a "simulated" system tracer that simply writes trace
 *  events into a file. The latter one is only capable to trace built-in events of the
 *  PAL SW layer (e.g. audio-io via PAL) and user events send via this interface, whereas
 *  the former one additionally is able to trace events of the system outside of the
 *  DragonDrive process.
 *
 *  Finally this interface allows to create a system trace over a specific time period.
 *  The tracing has to be explicitly started and stopped with a call to the 'start'
 *  respectively 'stop' function. Thereby a 'groups' filter determines which groups of
 *  trace events shall be traced. Supported trace groups are:
 *
 *  <ul>
 *  <li> 'TRCGRP_COMMON' </li>
 *  <li> 'TRCGRP_THREAD' </li>
 *  <li> 'TRCGRP_MEMORY' </li>
 *  <li> 'TRCGRP_USER' </li>
 *  <li> 'TRCGRP_FILE' </li>
 *  <li> 'TRCGRP_FILE_IO' </li>
 *  <li> 'TRCGRP_SOCKET' </li>
 *  <li> 'TRCGRP_SOCKET_IO' </li>
 *  <li> 'TRCGRP_AUDIO' </li>
 *  <li> 'TRCGRP_AUDIO_IO' </li>
 *  <li> 'TRCGRP_ERROR' </li>
 *  <li> 'TRCGRP_FATAL' </li>
 *  <li> 'TRCGRP_ALL' (includes all groups) </li>
 *  </ul>
 *
 *  Designated locations in the PAL SW layer are instrumented with built-in trace events
 *  related to specific trace groups (e.g. audio-io via trace group 'TRCGRP_AUDIO'). In
 *  addition to that the user is capable to write own user trace events to the system trace
 *  by calling 'beginUserEvent' respectively 'endUserEvent' which are implicitly related to
 *  the trace group 'TRCGRP_USER'.
 *
 *  DISCLAIMER: In the DDFW context the system tracing functionality has to be explicitly
 *  enabled with setting the configuration parameter 'DragonDriveCommonService.SysTraceEnable'
 *  (see also chapter 'configuration'), otherwise all calls to this interface are effectless.
 *  This means that all calls to the system tracing API will always immediately be answered
 *  with the result 'NUANCE_COMMON_RESULTCODE_OK' and that no system tracing file will be written.
 */
typedef struct _nuance_common_ISysTrace nuance_common_ISysTrace;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "common_api_defs.h"

/* API types */
#include "ResultCode.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  Starts a system tracing session. <p>
 *
 *  Returns an error in case a system tracing session is already started.
 *
 *  The groups that shall be traced have to be set with parameter 'groups' in a '|'-delimited
 *  group list string (e.g. "TRCGRP_USER|TRCGRP_FILE_IO"). See above for a list of supported
 *  trace groups.
 *
 *  The resulting trace file is created in the directory (absolute or relative to working
 *  directory) given with the 'fileDir' parameter. An already existing file with same name
 *  is overwritten. The trace file name depends on the usage of a native system tracer and
 *  of the given 'fileSuffix' and the 'fileTimestamp' parameter:
 *
 *  file name :: [\<timestamp\>] tracelog | simtracelog  [\<suffix\>]
 *
 *  With 'fileTimestamp' parameter set to true the current timestamp is prepended to the
 *  fixed trace file name. With parameter 'fileSuffix' an arbitrary file name suffix can
 *  be set. This parameter may be set to NULL or an empty string in case no file suffix
 *  is desired.
 *
 *  In addition the 'fileDir' directory may contain an optional system trace configuration
 *  file with the fixed name 'systrace.cfg'. This allows experts to configure the scope of
 *  the system tracing more in detail in case a native system tracer (e.g. "ftrace" on Linux)
 *  is used. As this is an expert configuration it may be set only agreed with the Nuance PAL
 *  system trace experts.
 *
 *  A started system tracing session has to be stopped with a call to 'stop'.
 *
 *  DISCLAIMER: In the DDFW the above mentioned parameters are available only in the form
 *  of the following 'DragonDriveCommonService.SysTrace*' configuration parameters (see also
 *  chapter 'configuration'):
 *  <ul>
 *  <li> 'groups' => DragonDriveCommonService.SysTraceGroups </li>
 *  <li> 'fileDir' => DragonDriveCommonService.SysTraceFileDir </li>
 *  <li> 'fileSuffix' => DragonDriveCommonService.SysTraceFileSuffix </li>
 *  <li> 'fileTimestamp' => DragonDriveCommonService.SysTraceFileTimestamp </li>
 *  </ul>
 *
 *  @param[in]     groups          Groups to be traced delimited with a '|' character.
 *  @param[in]     fileDir         Trace file and optional expert configuration file directory.
 *  @param[in]     fileSuffix      Trace file suffix, may be set to NULL or an empty string.
 *  @param[in]     fileTimestamp   Indicates whether a trace file timestamp suffix shall be used or not.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISysTrace_start
(
    const LH_CHAR *groups,
    const LH_CHAR *fileDir,
    const LH_CHAR *fileSuffix,
    LH_BOOL fileTimestamp
);


/**
 *  @brief  Begins an user trace event period in the system trace. <p>
 *
 *  Without effect in case the system tracing session is not started or the trace group
 *  'TRCGRP_USER', each user event is implicitly related to, is filtered out (see 'groups'
 *  parameter in 'start' description).
 *
 *  The 'name' of the user event has to be unique over all current user events. In addition
 *  the same name has to be used to end the corresponding user trace period with a call to
 *  'endUserEvent'.
 *
 *  Optionally it is possible to set with parameter 'argKey' and 'argVal' a key value pair
 *  that is shown at this user trace event.
 *
 *  @param[in]     name     Name of the trace event.
 *  @param[in]     argKey   Argument key to be traced, may be set to NULL.
 *  @param[in]     argVal   Argument value to be traced, may be set to NULL in case 'argKey' is NULL.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISysTrace_beginUserEvent
(
    const LH_CHAR *name,
    const LH_CHAR *argKey,
    const LH_CHAR *argVal
);


/**
 *  @brief  Ends an user trace event period in the system trace. <p>
 *
 *  Without effect in case the system tracing session is not started or the trace group
 *  'TRCGRP_USER', each user event is implicitly related to, is filtered out (see 'groups'
 *  parameter in 'start' description).
 *
 *  The name parameter 'name' has to correspond to the name used in the corresponding
 *  'beginUserEvent' function call.
 *
 *  @param[in]     name   Name of the trace event.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISysTrace_endUserEvent(const LH_CHAR *name);


/**
 *  @brief  Stops a system tracing session. <p>
 *
 *  Returns an error in case no system tracing session is started.
 *
 *  With stopping the system tracing session the trace file is available at the location
 *  set with the 'fileDir' parameter handed to the 'start' function.
 *
 */
COMMON_C_EXPORT nuance_common_ResultCode nuance_common_ISysTrace_stop();


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_COMMON_ISYSTRACE_H */

/** @} */
/** @} */

/**********************************************************************************************************************/
