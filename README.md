
## Setup Environment

To setup the build environment, simply clone the repository into a Debian-based Linux distribution.

*NB: This has only been tested for Ubuntu 18.04.*

## Build

To build and run the application for ASR, simply create a `build` directory in the platform-wrappers/linux/ and run CMake from there:
```
mkdir build
cd build
cmake ..
make
sudo ./test_application
```

To build and run for debugging (with [gdb](https://www.gnu.org/software/gdb/)):



### Directory Structure

The file structure of the repository reflects the application's modular architecture.

**/.github** contains automated workflow configurations

**/data** contains precomplied rules and wakeup word.

**/utils** contains Jason.c  directly used by the application.

**/inc** contains the modules' public (exposed to core) and private (exposed only within the module) header files

**/libs** contains external libraries based on the platforms that are exposed globally for any wrappers code.

**/src** contains api refernce.

**/platform_wrapper** contains specific code based on the platform(linux,android..etc),which interacts with the API. 
