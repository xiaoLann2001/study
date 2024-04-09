cmake_minimum_required(VERSION 3.10)

project(LinkhashProject)

# Set the source files
set(SOURCES
    main.c
    code/source/linkhash.c
)

# Create the executable
add_executable(linkhash_project ${SOURCES})

# Add include directories
target_include_directories(linkhash_project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/code/lib)

# Add the -g flag for debugging symbols
target_compile_options(linkhash_project PRIVATE -g)

# Set the output directory for the binary
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Optionally, set C standard
set_property(TARGET linkhash_project PROPERTY C_STANDARD 11)
