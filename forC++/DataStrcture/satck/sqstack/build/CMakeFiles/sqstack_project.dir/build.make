# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/build

# Include any dependencies generated for this target.
include CMakeFiles/sqstack_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sqstack_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sqstack_project.dir/flags.make

CMakeFiles/sqstack_project.dir/main.c.o: CMakeFiles/sqstack_project.dir/flags.make
CMakeFiles/sqstack_project.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sqstack_project.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sqstack_project.dir/main.c.o   -c /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/main.c

CMakeFiles/sqstack_project.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sqstack_project.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/main.c > CMakeFiles/sqstack_project.dir/main.c.i

CMakeFiles/sqstack_project.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sqstack_project.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/main.c -o CMakeFiles/sqstack_project.dir/main.c.s

CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.o: CMakeFiles/sqstack_project.dir/flags.make
CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.o: ../code/sqstack/sqstack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.o   -c /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/code/sqstack/sqstack.c

CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/code/sqstack/sqstack.c > CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.i

CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/code/sqstack/sqstack.c -o CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.s

# Object files for target sqstack_project
sqstack_project_OBJECTS = \
"CMakeFiles/sqstack_project.dir/main.c.o" \
"CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.o"

# External object files for target sqstack_project
sqstack_project_EXTERNAL_OBJECTS =

sqstack_project: CMakeFiles/sqstack_project.dir/main.c.o
sqstack_project: CMakeFiles/sqstack_project.dir/code/sqstack/sqstack.c.o
sqstack_project: CMakeFiles/sqstack_project.dir/build.make
sqstack_project: CMakeFiles/sqstack_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable sqstack_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sqstack_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sqstack_project.dir/build: sqstack_project

.PHONY : CMakeFiles/sqstack_project.dir/build

CMakeFiles/sqstack_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sqstack_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sqstack_project.dir/clean

CMakeFiles/sqstack_project.dir/depend:
	cd /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/build /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/build /home/ubuntu/Desktop/forC++/datastrcture/satck/sqstack/build/CMakeFiles/sqstack_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sqstack_project.dir/depend

