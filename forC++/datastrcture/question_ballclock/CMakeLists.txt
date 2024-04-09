cmake_minimum_required(VERSION 3.10)

project(BallClockProject)

# Set the source files
set(SOURCES
    main.c
    code/source/linkqueue/linkqueue.c
    code/source/sqstack/sqstack.c
)

# Create the executable
add_executable(ballclock_project ${SOURCES})

# Add include directories
target_include_directories(ballclock_project PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/code/lib/linkqueue 
${CMAKE_CURRENT_SOURCE_DIR}/code/lib/sqstack)

# Add the -g flag for debugging symbols
target_compile_options(ballclock_project PRIVATE -g)

# Set the output directory for the binary
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Optionally, set C standard
set_property(TARGET ballclock_project PROPERTY C_STANDARD 11)
