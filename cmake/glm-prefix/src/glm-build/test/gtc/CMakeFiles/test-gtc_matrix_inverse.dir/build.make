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
include test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/depend.make

# Include the progress variables for this target.
include test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/flags.make

test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o: test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/flags.make
test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o: /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_matrix_inverse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o -c /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_matrix_inverse.cpp

test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.i"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_matrix_inverse.cpp > CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.i

test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.s"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_matrix_inverse.cpp -o CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.s

test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o.requires:

.PHONY : test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o.requires

test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o.provides: test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o.requires
	$(MAKE) -f test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/build.make test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o.provides.build
.PHONY : test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o.provides

test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o.provides.build: test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o


# Object files for target test-gtc_matrix_inverse
test__gtc_matrix_inverse_OBJECTS = \
"CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o"

# External object files for target test-gtc_matrix_inverse
test__gtc_matrix_inverse_EXTERNAL_OBJECTS =

test/gtc/test-gtc_matrix_inverse: test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o
test/gtc/test-gtc_matrix_inverse: test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/build.make
test/gtc/test-gtc_matrix_inverse: test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-gtc_matrix_inverse"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-gtc_matrix_inverse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/build: test/gtc/test-gtc_matrix_inverse

.PHONY : test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/build

test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/requires: test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/gtc_matrix_inverse.cpp.o.requires

.PHONY : test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/requires

test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/clean:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && $(CMAKE_COMMAND) -P CMakeFiles/test-gtc_matrix_inverse.dir/cmake_clean.cmake
.PHONY : test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/clean

test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/depend:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/comput-6/anim/Detection/submodule/glm /home/comput-6/anim/Detection/submodule/glm/test/gtc /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/gtc/CMakeFiles/test-gtc_matrix_inverse.dir/depend

