Copyright by Cerence Inc.

Transmittal, reproduction, dissemination and/or editing of this
source code as well as utilization of its contents and communication
thereof to others without express authorization are prohibited.
Offenders will be held liable for payment of damages.  All rights
created by patent grant or registration of a utility model or design
patent are reserved.



#################################
CSDK README
#################################

Build Contents:
./doc/api_reference/**
./doc/open_source_license/CDFW_OpenSourceDeclaration.pdf
./doc/system_requirements/**
./doc/user_guide/**
./doc/readme.txt
./inc/**/*.h
./lib/*.so
./sample/data/**
./sample/linux/**
./sample/utils/**
./sample/prompter_sample/**
./sample/one_shot_wuw_sample/**
./sample/cloud_asr_sample/**
./tools/recog_test/**
./tools/cbatch/**

Build Specifications:
compiler      gcc 4.9
architecture  x86_64

How to run the samples:
1. Make sure gcc 4.9 or later is installed
2. In a terminal, navigate to the sample app's folder location (for example, one_shot_wuw_sample/),
   and call:
   'make clean' to clean
   'make build' to build
   'make run' to run
   'make all' to clean, build, and run

prompter_sample:
* Simply follow the steps above to run

one_shot_wuw_sample:
* The one_shot_wuw_sample performs a wuw recognition for "Hello Auto" followed by a recognition for one of 3 phrases:
  - "Shuffle Nevermind", "Shuffle Beat It", or "Shuffle Yesterday"
* By default, the run command performs a recognition from mic. To perform a recognition based on a file input, edit
  the Makefile in the run command to use "--audioScenario=file" instead of "--audioScenario=mic".
  The example audio file provided is found in ./sample/date/asr/data/sound/enu_f16/hello_auto_shuffle_nevermind.wav
* for more detailed instructions please consult the user guide:
    ./doc/user_guide/asr/user_guide/sdk_samples/c_one_shot_wuw_sample.html

cloud_asr_sample:
* the cloud_asr_sample performs a wuw recognition for "Hello Auto" followed by a cloud recognition
* To run the application, the user must obtain cloud credentials from a Cerence representative and add them into the 
  ./sample/data/cloud_asr/config/cloud_services.json file
* The user must also copy the certificate bundle file to ./sample/data/cloud_asr/config/
* By default, the run command performs a recognition from mic. To perform asr based on a file input, edit the cloud_asr's 
  main.c file by setting the AUDIO_SCENARIO_NAME to "file" instead of "mic". The example audio file provided is found in 
  ./sample/date/cloud_asr/data/sound/enu_f16/hello_auto_shuffle_nevermind.wav

Additional tools:
cbatch:
To run, in a command prompt navigate to ./tools/cbatch/, and run run_cbatch.sh
For more information, please consult the user guide:
    ./doc/user_guide/asr/tools/cbatch.html

recog_test:
To run, in a command prompt navigate to ./tools/recog_test/, and run run_recog_test.sh
For more information, please consult the user guide:
    ./doc/user_guide/asr/tools/recog_test_sample.html
