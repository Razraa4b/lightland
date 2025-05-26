cmake_minimum_required(VERSION 3.28)

project(WingetsTests)

# recursively collect all files with source code
file(GLOB_RECURSE SOURCES *.cc)

include(FetchContent)
# declare gtest library
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} ${SOURCES})

# include the header files of the project
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${TESTS_PROJECT_PATH}
)

# link wingets library for testing
target_link_libraries(${PROJECT_NAME}
    GTest::gtest
    GTest::gmock
    WingetsLibrary
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME tests
)
