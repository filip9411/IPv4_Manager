cmake_minimum_required(VERSION 3.20)

include (${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

set(CMAKE_C_STANDARD 11)

set(PROJECT_NAME IPV4_MANAGER)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
${CMAKE_CURRENT_SOURCE_DIR}/app/main.c
)

add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} PUBLIC
    ip_manager
)