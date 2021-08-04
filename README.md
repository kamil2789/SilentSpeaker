# SilentSpeaker
Simple, encrypted messenger for multiple users, written in C++

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)
## General info
This project is simple practise of C++ skills, including ASIO library
	
## Technologies
Technologies used in the project:
* C++17
* Cmake
* GoogleTest
	
## Setup
To run the project, please go through the following steps:

### 1. Download ASIO library
Donwload library from: https://think-async.com/Asio/
Unpack and copy to the directory Externals/ASIO following elements:
```
asio-<version>/include/asio.hpp
asio-<version>/include/asio
```

### 2. Setup googletest
```
$ git submodule init
$ git submodule update
```

### 3. Create build folder
In the root directory:
```
$ mkdir build
$ cd build
```

### 4.1 Build with MINGW
From build directory:

```
$ cmake .. -G "MinGW Makefiles"
$ make
```

### 4.2 Build with MSVC
From build directory:

#### Debug build
```
$ cmake ..
$ cmake --build .
```

#### Release build
```
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ cmake --build . --config Release
```