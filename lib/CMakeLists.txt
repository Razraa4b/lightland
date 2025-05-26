cmake_minimum_required(VERSION 3.28)

project(WingetsLibrary)

# recursively collect all files with source code
file(GLOB_RECURSE SOURCES *.cpp *.c)

find_package(OpenGL REQUIRED)
find_package(glad REQUIRED)
find_package(glfw REQUIRED)
find_package(glm REQUIRED)

add_library(${PROJECT_NAME} ${SOURCES})

# include lib header files
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${LIB_PROJECT_PATH}
        ${GLM_INCLUDE_PATH}
)

# includes dependencies header files
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${GLAD_INCLUDE_PATH} 
        ${GLFW_INCLUDE_PATH}
)

# link libraries for graphics
target_link_libraries(${PROJECT_NAME}
    PRIVATE 
        ${OPENGL_LIBRARIES}
        ${GLAD_LIBRARY}
        ${GLFW_LIBRARY}
        ${GLM_LIBRARY}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME wingets
)
