add_executable(${PROJECT_NAME}_example)

target_sources(${PROJECT_NAME}_example PRIVATE "example.cxx")

target_link_libraries(
    ${PROJECT_NAME}_example
    PRIVATE ${PROJECT_NAME}::lib
            ${PROJECT_NAME}::config
    )
