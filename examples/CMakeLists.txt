add_executable(${PROJECT_NAME}_example)

target_sources(${PROJECT_NAME}_example PRIVATE "example.cxx")

# find_package(lib)

target_link_libraries(
    ${PROJECT_NAME}_example
    PRIVATE 
    # ${PROJECT_NAME}::${PROJECT_NAME}
            # ${PROJECT_NAME}::config
        #     lib2::lib
        #     lib2::lib_config
            # lib::config
    )
