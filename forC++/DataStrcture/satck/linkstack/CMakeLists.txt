cmake_minimum_required(VERSION 3.10)

project(LinkstackProject)

# Set the source files
set(SOURCES
    main.c
    code/linkstack.c
)

# Create the executable
add_executable(linkstack_project ${SOURCES})

# Add include directories
target_include_directories(linkstack_project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/code)

# Add the -g flag for debugging symbols
target_compile_options(linkstack_project PRIVATE -g)

# Set the output directory for the binary
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Optionally, set C standard
set_property(TARGET linkstack_project PROPERTY C_STANDARD 11)
