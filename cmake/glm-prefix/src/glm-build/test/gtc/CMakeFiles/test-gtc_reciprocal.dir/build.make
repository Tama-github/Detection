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
include test/gtc/CMakeFiles/test-gtc_reciprocal.dir/depend.make

# Include the progress variables for this target.
include test/gtc/CMakeFiles/test-gtc_reciprocal.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtc/CMakeFiles/test-gtc_reciprocal.dir/flags.make

test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o: test/gtc/CMakeFiles/test-gtc_reciprocal.dir/flags.make
test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o: /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_reciprocal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o -c /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_reciprocal.cpp

test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.i"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_reciprocal.cpp > CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.i

test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.s"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_reciprocal.cpp -o CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.s

test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o.requires:

.PHONY : test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o.requires

test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o.provides: test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o.requires
	$(MAKE) -f test/gtc/CMakeFiles/test-gtc_reciprocal.dir/build.make test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o.provides.build
.PHONY : test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o.provides

test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o.provides.build: test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o


# Object files for target test-gtc_reciprocal
test__gtc_reciprocal_OBJECTS = \
"CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o"

# External object files for target test-gtc_reciprocal
test__gtc_reciprocal_EXTERNAL_OBJECTS =

test/gtc/test-gtc_reciprocal: test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o
test/gtc/test-gtc_reciprocal: test/gtc/CMakeFiles/test-gtc_reciprocal.dir/build.make
test/gtc/test-gtc_reciprocal: test/gtc/CMakeFiles/test-gtc_reciprocal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-gtc_reciprocal"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-gtc_reciprocal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/gtc/CMakeFiles/test-gtc_reciprocal.dir/build: test/gtc/test-gtc_reciprocal

.PHONY : test/gtc/CMakeFiles/test-gtc_reciprocal.dir/build

test/gtc/CMakeFiles/test-gtc_reciprocal.dir/requires: test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o.requires

.PHONY : test/gtc/CMakeFiles/test-gtc_reciprocal.dir/requires

test/gtc/CMakeFiles/test-gtc_reciprocal.dir/clean:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && $(CMAKE_COMMAND) -P CMakeFiles/test-gtc_reciprocal.dir/cmake_clean.cmake
.PHONY : test/gtc/CMakeFiles/test-gtc_reciprocal.dir/clean

test/gtc/CMakeFiles/test-gtc_reciprocal.dir/depend:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/comput-6/anim/Detection/submodule/glm /home/comput-6/anim/Detection/submodule/glm/test/gtc /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/gtc/CMakeFiles/test-gtc_reciprocal.dir/depend

