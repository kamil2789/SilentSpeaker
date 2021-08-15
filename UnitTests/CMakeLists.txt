cmake_minimum_required(VERSION 3.18)

project(UnitTests VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/mainUT.cpp
    src/TestMessage.cpp
    ${CMAKE_SOURCE_DIR}/SilentSpeaker/src/Message.cpp
)

add_dependencies(${PROJECT_NAME} gtest)

if (MSVC)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/lib/Debug/gtestd.lib)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/lib/Debug/gmockd.lib)
elseif (MINGW)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/lib/libgtest.a)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/lib/libgmock.a)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/Externals/googletest/googletest/include
    ${CMAKE_SOURCE_DIR}/Externals/googletest/googlemock/include
    ${CMAKE_SOURCE_DIR}/SilentSpeaker/include
)