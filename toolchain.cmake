# Set the CMake minimum version
cmake_minimum_required(VERSION 3.20)

# Define the toolchain file
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Let linux choose compilers paths. 

# Set compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
