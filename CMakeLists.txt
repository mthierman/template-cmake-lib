cmake_minimum_required(VERSION 4.3)
project(lib VERSION 0.0.0 DESCRIPTION "C++ library template")
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
    PUBLIC FILE_SET headers TYPE HEADERS BASE_DIRS "include" FILES "include/lib/lib.hpp"
    PRIVATE "src/lib.cxx"
)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}
    FILE_SET headers DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(
    PACKAGE_INFO ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cps"
    VERSION "${PROJECT_VERSION}"
    DESCRIPTION "${PROJECT_DESCRIPTION}"
    DEFAULT_TARGETS ${PROJECT_NAME}
)

if(PROJECT_IS_TOP_LEVEL)
    add_executable(${PROJECT_NAME}_example)
    target_sources(${PROJECT_NAME}_example PRIVATE "src/example.cxx")
    target_link_libraries(${PROJECT_NAME}_example PRIVATE ${PROJECT_NAME})
endif()
