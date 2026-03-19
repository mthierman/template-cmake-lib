cmake_minimum_required(VERSION 4.2)
project(template-cmake-lib)
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} INTERFACE c_std_17 cxx_std_23)
target_compile_definitions(
    ${PROJECT_NAME}
    INTERFACE UNICODE WIN32_LEAN_AND_MEAN NOMINMAX GDIPVER=0x0110
)
target_compile_options(
    ${PROJECT_NAME}
    INTERFACE
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
    INTERFACE
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
install(TARGETS config EXPORT ${PROJECT_NAME}-targets)

target_sources(
    ${PROJECT_NAME}
    PUBLIC FILE_SET headers TYPE HEADERS BASE_DIRS "include"
    PRIVATE "src/lib.cxx"
)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}::config)
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-targets FILE_SET headers)
install(EXPORT ${PROJECT_NAME}-targets DESTINATION "cmake" NAMESPACE lib::)
install(FILES "../cmake/lib-config.cmake" DESTINATION "cmake")


if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory(examples)
endif()
