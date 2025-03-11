add_library(${PROJECT_NAME})

add_library(
    ${PROJECT_NAME}::${PROJECT_NAME}
    ALIAS
    ${PROJECT_NAME}
    )

target_sources(
    ${PROJECT_NAME}
    PUBLIC FILE_SET
           ${PROJECT_NAME}_headers
           TYPE
           HEADERS
           BASE_DIRS
           "include"
           FILES
           "include/lib/lib.hxx"
    PRIVATE "lib.cxx"
    )

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}::config)

# https://stackoverflow.com/a/71066174
install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    FILE_SET
    ${PROJECT_NAME}_headers
    )

install(EXPORT ${PROJECT_NAME}Targets DESTINATION "share/cmake/lib" NAMESPACE lib2::)

install(FILES "../cmake/libConfig.cmake" DESTINATION "share/cmake/lib")
