cmake_minimum_required(VERSION 3.28)

project(AeroDesk)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(DEPENDENCIES_PATH  ${CMAKE_SOURCE_DIR}/deps)
set(LIB_PROJECT_PATH   ${CMAKE_SOURCE_DIR}/lib)
set(TESTS_PROJECT_PATH ${CMAKE_SOURCE_DIR}/tests)
set(CLI_PROJECT_PATH   ${CMAKE_SOURCE_DIR}/cli)

add_subdirectory(lib)
add_subdirectory(tests)
add_subdirectory(cli)
