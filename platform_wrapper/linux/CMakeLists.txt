cmake_minimum_required(VERSION 3.12.0)
project(test_application_linux VERSION 0.1.0)

# *** VARIABLES ***

# paths
set(DIR_UTILS_SRC ${PROJECT_SOURCE_DIR}/../../utils/src)
set(DIR_LINUX_SRC ${PROJECT_SOURCE_DIR}/src)
set(DIR_LIB_INCLUDE ${PROJECT_SOURCE_DIR}/../../inc/linux/asr)
set(DIR_UTILS_INCLUDE ${PROJECT_SOURCE_DIR}/../../utils/inc)
set(DIR_LINUX_INCLUDE ${PROJECT_SOURCE_DIR}/inc)
set(DIR_LIB_BIN ${PROJECT_SOURCE_DIR}/../../lib/linux/asr)

# targets
set(APP_TARGET test_application_linux)


# includes
set(APP_INCLUDES ${PROJECT_SOURCE_DIR}/inc
                 ${PROJECT_SOURCE_DIR}/../../inc/linux
                 ${DIR_LIB_INCLUDE}/nds_asr5  
		 ${DIR_LIB_INCLUDE}/nds_asr5_cop_file_reader 
                 ${DIR_LIB_INCLUDE}/nds_audio
                 ${DIR_LIB_INCLUDE}/nds_audio_module_from_file
                 ${DIR_LIB_INCLUDE}/nds_audio_module_input
                 ${DIR_LIB_INCLUDE}/nds_cloudservices
                 ${DIR_LIB_INCLUDE}/nds_common     
                 ${DIR_LIB_INCLUDE}/pal
                 ${DIR_UTILS_INCLUDE}
                 ${DIR_LINUX_INCLUDE})

# sources
set(APP_SRCS ${PROJECT_SOURCE_DIR}/src/linux_wrapper_cerence.c
	     ${PROJECT_SOURCE_DIR}/../../src/asr_cerence_api.c 
             ${DIR_UTILS_SRC}/cJSON.c
             ${DIR_LINUX_SRC}/customInputAdapterFactory.c
             ${DIR_LINUX_SRC}/customInputAudioAdapter.c
             ${DIR_LINUX_SRC}/audioin.c
             ${DIR_LINUX_SRC}/mt_mutex.c
             ${DIR_LINUX_SRC}/mt_semaphore.c)

# libs
file(GLOB LIB_TARGETS ${DIR_LIB_BIN}/*.so)



# *** BUILD & LINK ***

# add sources
add_executable(${APP_TARGET} ${APP_SRCS})

# add includes
target_include_directories(${APP_TARGET} PUBLIC ${APP_INCLUDES})

# add libraries 
target_link_libraries(${APP_TARGET} ${LIB_TARGETS})

# add system libraries
target_link_libraries(${APP_TARGET} m pthread rt asound)
