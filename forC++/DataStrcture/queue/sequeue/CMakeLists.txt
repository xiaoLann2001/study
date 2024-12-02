cmake_minimum_required(VERSION 3.10)

project(SequeueProject)

# Set the source files
set(SOURCES
    main.c
    code/sequeue.c
)

# Create the executable
add_executable(sequeue_project ${SOURCES})

# Add include directories
target_include_directories(sequeue_project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/code)

# Add the -g flag for debugging symbols
target_compile_options(sequeue_project PRIVATE -g)

# Set the output directory for the binary
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Optionally, set C standard
set_property(TARGET sequeue_project PROPERTY C_STANDARD 11)
