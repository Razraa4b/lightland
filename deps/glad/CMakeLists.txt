cmake_minimum_required(VERSION 3.28)

project(GLAD)

set(SOURCES src/glad.c)

include_directories(include)

add_library(glad ${SOURCES})

