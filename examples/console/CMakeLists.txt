add_executable(example_console)

target_sources(example_console PRIVATE "src/main.cxx")

target_link_libraries(
    example_console
    PRIVATE ${PROJECT_NAME}::${PROJECT_NAME}
            ${PROJECT_NAME}::config
    )
