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
include test/core/CMakeFiles/test-core_func_packing.dir/depend.make

# Include the progress variables for this target.
include test/core/CMakeFiles/test-core_func_packing.dir/progress.make

# Include the compile flags for this target's objects.
include test/core/CMakeFiles/test-core_func_packing.dir/flags.make

test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o: test/core/CMakeFiles/test-core_func_packing.dir/flags.make
test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o: /home/comput-6/anim/Detection/submodule/glm/test/core/core_func_packing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o -c /home/comput-6/anim/Detection/submodule/glm/test/core/core_func_packing.cpp

test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.i"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/core && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/comput-6/anim/Detection/submodule/glm/test/core/core_func_packing.cpp > CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.i

test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.s"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/core && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/comput-6/anim/Detection/submodule/glm/test/core/core_func_packing.cpp -o CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.s

test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o.requires:

.PHONY : test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o.requires

test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o.provides: test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o.requires
	$(MAKE) -f test/core/CMakeFiles/test-core_func_packing.dir/build.make test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o.provides.build
.PHONY : test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o.provides

test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o.provides.build: test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o


# Object files for target test-core_func_packing
test__core_func_packing_OBJECTS = \
"CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o"

# External object files for target test-core_func_packing
test__core_func_packing_EXTERNAL_OBJECTS =

test/core/test-core_func_packing: test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o
test/core/test-core_func_packing: test/core/CMakeFiles/test-core_func_packing.dir/build.make
test/core/test-core_func_packing: test/core/CMakeFiles/test-core_func_packing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-core_func_packing"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-core_func_packing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/core/CMakeFiles/test-core_func_packing.dir/build: test/core/test-core_func_packing

.PHONY : test/core/CMakeFiles/test-core_func_packing.dir/build

test/core/CMakeFiles/test-core_func_packing.dir/requires: test/core/CMakeFiles/test-core_func_packing.dir/core_func_packing.cpp.o.requires

.PHONY : test/core/CMakeFiles/test-core_func_packing.dir/requires

test/core/CMakeFiles/test-core_func_packing.dir/clean:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/core && $(CMAKE_COMMAND) -P CMakeFiles/test-core_func_packing.dir/cmake_clean.cmake
.PHONY : test/core/CMakeFiles/test-core_func_packing.dir/clean

test/core/CMakeFiles/test-core_func_packing.dir/depend:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/comput-6/anim/Detection/submodule/glm /home/comput-6/anim/Detection/submodule/glm/test/core /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/core /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/core/CMakeFiles/test-core_func_packing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/core/CMakeFiles/test-core_func_packing.dir/depend

