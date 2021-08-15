cmake_minimum_required(VERSION 3.18)

project(SilentSpeaker VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/initRepo.cpp
    src/AsioServer.cpp
)

target_link_libraries(${PROJECT_NAME} ws2_32)
target_link_libraries(${PROJECT_NAME} wsock32)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/Externals/ASIO
    ${PROJECT_SOURCE_DIR}/include
)