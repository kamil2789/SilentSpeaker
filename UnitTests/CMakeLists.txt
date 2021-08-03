cmake_minimum_required(VERSION 3.18)

project(UnitTests VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/mainUT.cpp
    ${CMAKE_SOURCE_DIR}/SilentSpeaker/src/initRepo.cpp
)

# add_dependencies(${PROJECT_NAME} gtest)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/Externals/googletest/googletest/include
    ${CMAKE_SOURCE_DIR}/Externals/googletest/googlemock/include
)