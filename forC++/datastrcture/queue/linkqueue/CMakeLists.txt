cmake_minimum_required(VERSION 3.10)

project(LinkqueueProject)

# Set the source files
set(SOURCES
    main.c
    code/linkqueue.c
)

# Create the executable
add_executable(linkqueue_project ${SOURCES})

# Add include directories
target_include_directories(linkqueue_project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/code)

# Add the -g flag for debugging symbols
target_compile_options(linkqueue_project PRIVATE -g)

# Set the output directory for the binary
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Optionally, set C standard
set_property(TARGET linkqueue_project PROPERTY C_STANDARD 11)
