cmake_minimum_required(VERSION 3.10)

project(BiTreeProject)

# Set the source files
set(SOURCES
    main.c
    code/source/bitree/bitree.c
    code/source/linkqueue/linkqueue.c
    code/source/linkstack/linkstack.c
)

# Create the executable
add_executable(bitree_project ${SOURCES})

# Add include directories
target_include_directories(bitree_project PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/code/lib/bitree
${CMAKE_CURRENT_SOURCE_DIR}/code/lib/linkqueue
${CMAKE_CURRENT_SOURCE_DIR}/code/lib/linkstack)

# Add the -g flag for debugging symbols
target_compile_options(bitree_project PRIVATE -g)

# Set the output directory for the binary
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Optionally, set C standard
set_property(TARGET bitree_project PROPERTY C_STANDARD 11)
