cmake_minimum_required(VERSION 4.3)

project(library VERSION 0.0.0)

include(GNUInstallDirs)

add_library(${PROJECT_NAME})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)

target_compile_definitions(
    ${PROJECT_NAME}
    PRIVATE UNICODE WIN32_LEAN_AND_MEAN NOMINMAX GDIPVER=0x0110
)

target_compile_options(
    ${PROJECT_NAME}
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
    ${PROJECT_NAME}
    PUBLIC FILE_SET HEADERS TYPE HEADERS BASE_DIRS "include" FILES "include/lib/lib.hpp"
    PRIVATE "src/lib.cpp"
)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} FILE_SET HEADERS)
install(PACKAGE_INFO ${PROJECT_NAME} EXPORT ${PROJECT_NAME} VERSION "${PROJECT_VERSION}")
export(PACKAGE_INFO ${PROJECT_NAME} EXPORT ${PROJECT_NAME} VERSION "${PROJECT_VERSION}")

if(PROJECT_IS_TOP_LEVEL)
    add_executable(${PROJECT_NAME}_example)

    target_compile_definitions(
        ${PROJECT_NAME}_example
        PRIVATE UNICODE WIN32_LEAN_AND_MEAN NOMINMAX GDIPVER=0x0110
    )

    target_sources(
        ${PROJECT_NAME}_example
        PRIVATE "src/example.cpp" "data/app.rc" "data/app.manifest"
    )

    target_link_libraries(${PROJECT_NAME}_example PRIVATE ${PROJECT_NAME}::${PROJECT_NAME})

    target_compile_options(
        ${PROJECT_NAME}_example
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
