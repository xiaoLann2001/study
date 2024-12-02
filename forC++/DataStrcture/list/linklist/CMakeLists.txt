cmake_minimum_required(VERSION 3.10)

project(LinklistProject)

# Set the source files
set(SOURCES
    main.c
    code/linklist/linklist.c
)

# Create the executable
add_executable(linklist_project ${SOURCES})

# Add include directories
target_include_directories(linklist_project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/code/linklist)

# Add the -g flag for debugging symbols
target_compile_options(linklist_project PRIVATE -g)

# Set the output directory for the binary
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Optionally, set C standard
set_property(TARGET linklist_project PROPERTY C_STANDARD 11)
