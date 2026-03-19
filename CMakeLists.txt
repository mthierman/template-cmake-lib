cmake_minimum_required(VERSION 4.2)
project(lib)
add_library(${PROJECT_NAME})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PUBLIC c_std_17 cxx_std_23)
target_compile_definitions(
    ${PROJECT_NAME}
    PUBLIC UNICODE WIN32_LEAN_AND_MEAN NOMINMAX GDIPVER=0x0110
)
target_compile_options(
    ${PROJECT_NAME}
    PUBLIC
        $<$<CXX_COMPILER_ID:MSVC>:
        /W4
        /utf-8
        /bigobj
        /diagnostics:caret
        /permissive-
        /Zc:__cplusplus,enumTypes,templateScope,throwingNew,preprocessor
        >
        $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_FRONTEND_VARIANT:MSVC>>:
        /W4
        >
        $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_FRONTEND_VARIANT:GNU>>:
        -Wall
        >
)
target_link_options(
    ${PROJECT_NAME}
    PUBLIC
        $<$<CXX_COMPILER_ID:MSVC>:
        /WX
        >
        $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_FRONTEND_VARIANT:MSVC>>:
        /WX
        >
        $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_FRONTEND_VARIANT:GNU>>:
        -Wl,/WX
        >
)
target_sources(
    ${PROJECT_NAME}
    PUBLIC FILE_SET headers TYPE HEADERS BASE_DIRS "include"
    PRIVATE "src/lib.cxx"
)

if(PROJECT_IS_TOP_LEVEL)
    add_executable(${PROJECT_NAME}_example)
    target_sources(${PROJECT_NAME}_example PRIVATE "src/example.cxx")
    target_link_libraries(${PROJECT_NAME}_example PRIVATE ${PROJECT_NAME})
endif()
