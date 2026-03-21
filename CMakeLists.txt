cmake_minimum_required(VERSION 4.3)

project(mthierman VERSION 0.0.0)

include(GNUInstallDirs)

add_library(log)
add_library(mthierman::log ALIAS log)

target_compile_features(log PUBLIC cxx_std_23)

target_compile_definitions(
    log
    PRIVATE UNICODE WIN32_LEAN_AND_MEAN NOMINMAX GDIPVER=0x0110
)

target_compile_options(
    log
    PRIVATE
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

target_sources(
    log
    PUBLIC FILE_SET HEADERS TYPE HEADERS BASE_DIRS "include" FILES "include/mthierman/log.hpp"
    PRIVATE "src/log.cpp"
)

install(TARGETS log EXPORT log FILE_SET HEADERS)
install(PACKAGE_INFO log EXPORT log VERSION "${PROJECT_VERSION}")
export(PACKAGE_INFO log EXPORT log VERSION "${PROJECT_VERSION}")

if(PROJECT_IS_TOP_LEVEL)
    add_executable(log_example)

    target_compile_definitions(
        log_example
        PRIVATE UNICODE WIN32_LEAN_AND_MEAN NOMINMAX GDIPVER=0x0110
    )

    target_sources(
        log_example
        PRIVATE "src/example.cpp" "data/app.rc" "data/app.manifest"
    )

    target_link_libraries(log_example PRIVATE mthierman::log)

    target_compile_options(
        log_example
        PRIVATE
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
endif()
