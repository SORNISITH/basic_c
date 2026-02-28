# CMake minimum version
cmake_minimum_required(VERSION 3.16)

# Project name and language
project(nz_app C)

# Set C standard

# List all source files
set(SOURCES
    main.c
    quicksort.c
    util.c
)

# Include directories for headers
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}  # for nzlib.h and nzutil.h
)

# Create executable
add_executable(nz_app ${SOURCES})

