EXECUTABLE_NAME = one_shot_wuw_sample
DIR_SRC = src
DIR_UTILS_SRC = ../utils/src
DIR_LINUX_SRC = ../linux/src
DIR_LIB_INCLUDE = ../../inc
DIR_UTILS_INCLUDE = ../utils/inc
DIR_LINUX_INCLUDE = ../linux/inc
DIR_BIN = bin
DIR_LIB_BIN = ../../lib

SRC_FILES= \
	$(DIR_SRC)/main.c \
	$(DIR_UTILS_SRC)/cJSON.c \
	$(DIR_LINUX_SRC)/customInputAdapterFactory.c \
	$(DIR_LINUX_SRC)/customInputAudioAdapter.c \
	$(DIR_LINUX_SRC)/audioin.c \
	$(DIR_LINUX_SRC)/mt_mutex.c \
	$(DIR_LINUX_SRC)/mt_semaphore.c

INCLUDES = \
			-I$(DIR_LIB_INCLUDE)/nds_asr5 \
			-I$(DIR_LIB_INCLUDE)/nds_asr5_cop_file_reader \
			-I$(DIR_LIB_INCLUDE)/nds_audio \
			-I$(DIR_LIB_INCLUDE)/nds_audio_module_from_file \
			-I$(DIR_LIB_INCLUDE)/nds_audio_module_input \
			-I$(DIR_LIB_INCLUDE)/nds_cloudservices \
			-I$(DIR_LIB_INCLUDE)/nds_common \
			-I$(DIR_LIB_INCLUDE)/pal \
			-I$(DIR_UTILS_INCLUDE) \
			-I$(DIR_LINUX_INCLUDE)

LIB_FILES = \
			-lnds_asr5_cop_file_reader \
			-lnds_asr5_cop_file_reader_c \
			-lnds_asr5 \
			-lnds_asr5_c \
			-lvocon_asr2 \
			-lvocon_base \
			-lvocon_gram2 \
			-lvocon_pron \
			-lvocon_sem3 \
			-lvocon_spellpp \
			-lvocvoc_core \
			-lvocvoc_fst \
			-lvocvoc_lua \
			-lvocvoc_neuralnetwork \
			-lvocvoc_ooc \
			-lvocvoc_platform \
			-lnds_audio \
			-lnds_audio_c \
			-lnds_audio_module_from_file \
			-lnds_audio_module_from_file_c \
			-lvocon_curl \
			-lvocon_ssl \
			-lnds_cloudservices \
			-lnds_cloudservices_c \
			-lnds_audio_module_input \
			-lnds_audio_module_input_c \
			-ldd_common \
			-ldd_common_c \
			-lpal_core \
			-lasound

build: create_dirs
	gcc -o $(DIR_BIN)/$(EXECUTABLE_NAME) $(INCLUDES) $(SRC_FILES) -L$(DIR_LIB_BIN) $(LIB_FILES) -lm -lpthread -lrt 

run:
	@cd $(DIR_BIN) && export LD_LIBRARY_PATH=../$(DIR_LIB_BIN):${LD_LIBRARY_PATH} && ./$(EXECUTABLE_NAME) --configDir=../../data/asr/config --audioScenario=mic --dcc="DCC_LOCAL_TITLE,../../data/asr/config/songs.cop"

create_dirs:
	@if [ ! -d "$(DIR_BIN)" ]; then mkdir -p $(DIR_BIN); fi

clean:
	@if [ -d "$(DIR_BIN)" ]; then rm -rf $(DIR_BIN); fi

all: clean build run
