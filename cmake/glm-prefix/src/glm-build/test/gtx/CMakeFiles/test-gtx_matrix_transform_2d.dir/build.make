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
CMAKE_SOURCE_DIR = /home/comput-6/anim/Detection/submodule/glm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build

# Include any dependencies generated for this target.
include test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/depend.make

# Include the progress variables for this target.
include test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/flags.make

test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o: test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/flags.make
test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o: /home/comput-6/anim/Detection/submodule/glm/test/gtx/gtx_matrix_transform_2d.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o -c /home/comput-6/anim/Detection/submodule/glm/test/gtx/gtx_matrix_transform_2d.cpp

test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.i"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/comput-6/anim/Detection/submodule/glm/test/gtx/gtx_matrix_transform_2d.cpp > CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.i

test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.s"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/comput-6/anim/Detection/submodule/glm/test/gtx/gtx_matrix_transform_2d.cpp -o CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.s

test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o.requires:

.PHONY : test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o.requires

test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o.provides: test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o.requires
	$(MAKE) -f test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/build.make test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o.provides.build
.PHONY : test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o.provides

test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o.provides.build: test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o


# Object files for target test-gtx_matrix_transform_2d
test__gtx_matrix_transform_2d_OBJECTS = \
"CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o"

# External object files for target test-gtx_matrix_transform_2d
test__gtx_matrix_transform_2d_EXTERNAL_OBJECTS =

test/gtx/test-gtx_matrix_transform_2d: test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o
test/gtx/test-gtx_matrix_transform_2d: test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/build.make
test/gtx/test-gtx_matrix_transform_2d: test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-gtx_matrix_transform_2d"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-gtx_matrix_transform_2d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/build: test/gtx/test-gtx_matrix_transform_2d

.PHONY : test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/build

test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/requires: test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/gtx_matrix_transform_2d.cpp.o.requires

.PHONY : test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/requires

test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/clean:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx && $(CMAKE_COMMAND) -P CMakeFiles/test-gtx_matrix_transform_2d.dir/cmake_clean.cmake
.PHONY : test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/clean

test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/depend:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/comput-6/anim/Detection/submodule/glm /home/comput-6/anim/Detection/submodule/glm/test/gtx /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/gtx/CMakeFiles/test-gtx_matrix_transform_2d.dir/depend

