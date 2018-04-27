cmake_minimum_required(VERSION 3.0.0)


project(bgl-toy VERSION 0.1.0)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")


file(
    GLOB
    source_files
    ${PROJECT_SOURCE_DIR}/*.cpp
)

add_executable(main ${source_files} )

