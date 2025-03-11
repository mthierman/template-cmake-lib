cmake_minimum_required(VERSION 3.30)

project(lib)

list(
    APPEND
    CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
    )

include("true")

add_subdirectory("config")
add_subdirectory("lib")

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory("examples")
endif()
