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
include test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/depend.make

# Include the progress variables for this target.
include test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/progress.make

# Include the compile flags for this target's objects.
include test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/flags.make

test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o: test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/flags.make
test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o: /home/comput-6/anim/Detection/submodule/glm/test/ext/ext_quaternion_trigonometric.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/ext && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o -c /home/comput-6/anim/Detection/submodule/glm/test/ext/ext_quaternion_trigonometric.cpp

test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.i"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/ext && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/comput-6/anim/Detection/submodule/glm/test/ext/ext_quaternion_trigonometric.cpp > CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.i

test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.s"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/ext && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/comput-6/anim/Detection/submodule/glm/test/ext/ext_quaternion_trigonometric.cpp -o CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.s

test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o.requires:

.PHONY : test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o.requires

test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o.provides: test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o.requires
	$(MAKE) -f test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/build.make test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o.provides.build
.PHONY : test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o.provides

test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o.provides.build: test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o


# Object files for target test-ext_quaternion_trigonometric
test__ext_quaternion_trigonometric_OBJECTS = \
"CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o"

# External object files for target test-ext_quaternion_trigonometric
test__ext_quaternion_trigonometric_EXTERNAL_OBJECTS =

test/ext/test-ext_quaternion_trigonometric: test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o
test/ext/test-ext_quaternion_trigonometric: test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/build.make
test/ext/test-ext_quaternion_trigonometric: test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-ext_quaternion_trigonometric"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/ext && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-ext_quaternion_trigonometric.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/build: test/ext/test-ext_quaternion_trigonometric

.PHONY : test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/build

test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/requires: test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/ext_quaternion_trigonometric.cpp.o.requires

.PHONY : test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/requires

test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/clean:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/ext && $(CMAKE_COMMAND) -P CMakeFiles/test-ext_quaternion_trigonometric.dir/cmake_clean.cmake
.PHONY : test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/clean

test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/depend:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/comput-6/anim/Detection/submodule/glm /home/comput-6/anim/Detection/submodule/glm/test/ext /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/ext /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/ext/CMakeFiles/test-ext_quaternion_trigonometric.dir/depend

