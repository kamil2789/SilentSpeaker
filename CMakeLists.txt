cmake_minimum_required(VERSION 3.18)

project(SilentSpeaker VERSION 1.0)

add_subdirectory(Externals/googletest)
add_subdirectory(SilentSpeaker)
add_subdirectory(UnitTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)