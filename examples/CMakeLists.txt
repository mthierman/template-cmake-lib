add_executable(${PROJECT_NAME}_example EXCLUDE_FROM_ALL)

target_sources(${PROJECT_NAME}_example PRIVATE "example.cxx")

find_package(lib)

message(STATUS ${CMAKE_MODULE_PATH})

target_link_libraries(
    ${PROJECT_NAME}_example
    PRIVATE 
    # ${PROJECT_NAME}::${PROJECT_NAME}
            # ${PROJECT_NAME}::config
            ${PROJECT_NAME}2::lib
            ${PROJECT_NAME}2::config
            # lib::config
    )
