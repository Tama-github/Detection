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
include test/gtx/CMakeFiles/test-gtx_component_wise.dir/depend.make

# Include the progress variables for this target.
include test/gtx/CMakeFiles/test-gtx_component_wise.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtx/CMakeFiles/test-gtx_component_wise.dir/flags.make

test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o: test/gtx/CMakeFiles/test-gtx_component_wise.dir/flags.make
test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o: /home/comput-6/anim/Detection/submodule/glm/test/gtx/gtx_component_wise.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o -c /home/comput-6/anim/Detection/submodule/glm/test/gtx/gtx_component_wise.cpp

test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.i"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/comput-6/anim/Detection/submodule/glm/test/gtx/gtx_component_wise.cpp > CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.i

test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.s"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/comput-6/anim/Detection/submodule/glm/test/gtx/gtx_component_wise.cpp -o CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.s

test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o.requires:

.PHONY : test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o.requires

test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o.provides: test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o.requires
	$(MAKE) -f test/gtx/CMakeFiles/test-gtx_component_wise.dir/build.make test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o.provides.build
.PHONY : test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o.provides

test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o.provides.build: test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o


# Object files for target test-gtx_component_wise
test__gtx_component_wise_OBJECTS = \
"CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o"

# External object files for target test-gtx_component_wise
test__gtx_component_wise_EXTERNAL_OBJECTS =

test/gtx/test-gtx_component_wise: test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o
test/gtx/test-gtx_component_wise: test/gtx/CMakeFiles/test-gtx_component_wise.dir/build.make
test/gtx/test-gtx_component_wise: test/gtx/CMakeFiles/test-gtx_component_wise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-gtx_component_wise"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-gtx_component_wise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/gtx/CMakeFiles/test-gtx_component_wise.dir/build: test/gtx/test-gtx_component_wise

.PHONY : test/gtx/CMakeFiles/test-gtx_component_wise.dir/build

test/gtx/CMakeFiles/test-gtx_component_wise.dir/requires: test/gtx/CMakeFiles/test-gtx_component_wise.dir/gtx_component_wise.cpp.o.requires

.PHONY : test/gtx/CMakeFiles/test-gtx_component_wise.dir/requires

test/gtx/CMakeFiles/test-gtx_component_wise.dir/clean:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx && $(CMAKE_COMMAND) -P CMakeFiles/test-gtx_component_wise.dir/cmake_clean.cmake
.PHONY : test/gtx/CMakeFiles/test-gtx_component_wise.dir/clean

test/gtx/CMakeFiles/test-gtx_component_wise.dir/depend:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/comput-6/anim/Detection/submodule/glm /home/comput-6/anim/Detection/submodule/glm/test/gtx /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtx/CMakeFiles/test-gtx_component_wise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/gtx/CMakeFiles/test-gtx_component_wise.dir/depend

