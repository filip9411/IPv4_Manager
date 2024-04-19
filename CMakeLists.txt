cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_STANDARD 11)

set(PROJECT_NAME IPV4_MANAGER)

add_executable(${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/app/main.c
    )
