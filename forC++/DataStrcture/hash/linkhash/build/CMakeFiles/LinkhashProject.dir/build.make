# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/build

# Include any dependencies generated for this target.
include CMakeFiles/LinkhashProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LinkhashProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkhashProject.dir/flags.make

CMakeFiles/LinkhashProject.dir/main.c.o: CMakeFiles/LinkhashProject.dir/flags.make
CMakeFiles/LinkhashProject.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LinkhashProject.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LinkhashProject.dir/main.c.o   -c /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/main.c

CMakeFiles/LinkhashProject.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LinkhashProject.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/main.c > CMakeFiles/LinkhashProject.dir/main.c.i

CMakeFiles/LinkhashProject.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LinkhashProject.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/main.c -o CMakeFiles/LinkhashProject.dir/main.c.s

CMakeFiles/LinkhashProject.dir/main.c.o.requires:

.PHONY : CMakeFiles/LinkhashProject.dir/main.c.o.requires

CMakeFiles/LinkhashProject.dir/main.c.o.provides: CMakeFiles/LinkhashProject.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/LinkhashProject.dir/build.make CMakeFiles/LinkhashProject.dir/main.c.o.provides.build
.PHONY : CMakeFiles/LinkhashProject.dir/main.c.o.provides

CMakeFiles/LinkhashProject.dir/main.c.o.provides.build: CMakeFiles/LinkhashProject.dir/main.c.o


CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o: CMakeFiles/LinkhashProject.dir/flags.make
CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o: ../code/source/linkhash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o   -c /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/code/source/linkhash.c

CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/code/source/linkhash.c > CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.i

CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/code/source/linkhash.c -o CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.s

CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o.requires:

.PHONY : CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o.requires

CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o.provides: CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o.requires
	$(MAKE) -f CMakeFiles/LinkhashProject.dir/build.make CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o.provides.build
.PHONY : CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o.provides

CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o.provides.build: CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o


# Object files for target LinkhashProject
LinkhashProject_OBJECTS = \
"CMakeFiles/LinkhashProject.dir/main.c.o" \
"CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o"

# External object files for target LinkhashProject
LinkhashProject_EXTERNAL_OBJECTS =

LinkhashProject: CMakeFiles/LinkhashProject.dir/main.c.o
LinkhashProject: CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o
LinkhashProject: CMakeFiles/LinkhashProject.dir/build.make
LinkhashProject: CMakeFiles/LinkhashProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable LinkhashProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LinkhashProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinkhashProject.dir/build: LinkhashProject

.PHONY : CMakeFiles/LinkhashProject.dir/build

CMakeFiles/LinkhashProject.dir/requires: CMakeFiles/LinkhashProject.dir/main.c.o.requires
CMakeFiles/LinkhashProject.dir/requires: CMakeFiles/LinkhashProject.dir/code/source/linkhash.c.o.requires

.PHONY : CMakeFiles/LinkhashProject.dir/requires

CMakeFiles/LinkhashProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LinkhashProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LinkhashProject.dir/clean

CMakeFiles/LinkhashProject.dir/depend:
	cd /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/build /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/build /home/book/nfs_rootfs/git/study/forC++/datastrcture/hash/linkhash/build/CMakeFiles/LinkhashProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LinkhashProject.dir/depend

