cmake_minimum_required(VERSION 3.10)

project(LinkhashProject)

# Set the source files
set(SOURCES
    main.c
    code/source/linkhash.c
)

# Include directories
include_directories(code/lib)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add the -g flag for debugging symbols
target_compile_options(${PROJECT_NAME} PRIVATE -g)

# Set the output directory for the binary
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Optionally, set C standard
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)