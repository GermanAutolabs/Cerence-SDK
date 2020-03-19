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


#ifndef IG_NUANCE_DRAGONDRIVE_SDK_VERSION_DEFS_H
#define IG_NUANCE_DRAGONDRIVE_SDK_VERSION_DEFS_H

/* This mechanism is used to define a label at compile time, without
 * affecting the source code:
 *
 * sbuild (_sb_vars.py) checks the environment variable
 * VHP_DRAGONDRIVEFRAMEWORK_LABEL and provides its value as -D to
 * compiler when building the objects that include this header. (These
 * are only a few to avoid large unnecessary rebuilds). In case this
 * environment variable is not set, the current date and time is used
 * to create a label marking the build as "Engineering Build
 * (date/time)". So to avoid recurring rebuilds one needs to set the
 * environment variable to some value, which must _NOT_ be a valid
 * label, to avoid confusion.
 *
 * Jenkins gets the environment variable injected as parameter of the
 * build jobs. This enables the release engineer to build an formally
 * unchanged source code multiple times with different labels (which
 * would be formally necessary if this happens on different weekdays)
 */
#ifndef VHP_DRAGONDRIVEFRAMEWORK_LABEL
#  error "Please define VHP_DRAGONDRIVEFRAMEWORK_LABEL in your build script"
#else
#  undef DRAGONDRIVE_SDK_VERSION
#  define DRAGONDRIVE_SDK_VERSION VHP_DRAGONDRIVEFRAMEWORK_LABEL
#endif 

#endif // IG_NUANCE_DRAGONDRIVE_SDK_VERSION_DEFS_H

/**********************************************************************************************************************/
