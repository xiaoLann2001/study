cmake_minimum_required(VERSION 3.10)

project(SqlistProject)

# Set the source files
set(SOURCES
    main.c
    code/sqlist/sqlist.c
)

# Create the executable
add_executable(sqlist_project ${SOURCES})

# Add include directories
target_include_directories(sqlist_project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/code/sqlist)

# Add the -g flag for debugging symbols
target_compile_options(sqlist_project PRIVATE -g)

# Set the output directory for the binary
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Optionally, set C standard
set_property(TARGET sqlist_project PROPERTY C_STANDARD 11)
