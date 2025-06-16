cmake_minimum_required(VERSION 3.28)

project(AeroDeskCLI)

# recursively collect all files with source code
file(GLOB_RECURSE SOURCES *.cpp *.c)

add_executable(${PROJECT_NAME} ${SOURCES})

# include the header files of the project
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CLI_PROJECT_PATH}
)

# link AeroDesk library
target_link_libraries(${PROJECT_NAME}
    AeroDeskLibrary
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME aerodesk
)
