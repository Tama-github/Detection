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
include test/gtc/CMakeFiles/test-gtc_integer.dir/depend.make

# Include the progress variables for this target.
include test/gtc/CMakeFiles/test-gtc_integer.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtc/CMakeFiles/test-gtc_integer.dir/flags.make

test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o: test/gtc/CMakeFiles/test-gtc_integer.dir/flags.make
test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o: /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_integer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o -c /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_integer.cpp

test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.i"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_integer.cpp > CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.i

test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.s"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/comput-6/anim/Detection/submodule/glm/test/gtc/gtc_integer.cpp -o CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.s

test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o.requires:

.PHONY : test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o.requires

test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o.provides: test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o.requires
	$(MAKE) -f test/gtc/CMakeFiles/test-gtc_integer.dir/build.make test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o.provides.build
.PHONY : test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o.provides

test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o.provides.build: test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o


# Object files for target test-gtc_integer
test__gtc_integer_OBJECTS = \
"CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o"

# External object files for target test-gtc_integer
test__gtc_integer_EXTERNAL_OBJECTS =

test/gtc/test-gtc_integer: test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o
test/gtc/test-gtc_integer: test/gtc/CMakeFiles/test-gtc_integer.dir/build.make
test/gtc/test-gtc_integer: test/gtc/CMakeFiles/test-gtc_integer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-gtc_integer"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-gtc_integer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/gtc/CMakeFiles/test-gtc_integer.dir/build: test/gtc/test-gtc_integer

.PHONY : test/gtc/CMakeFiles/test-gtc_integer.dir/build

test/gtc/CMakeFiles/test-gtc_integer.dir/requires: test/gtc/CMakeFiles/test-gtc_integer.dir/gtc_integer.cpp.o.requires

.PHONY : test/gtc/CMakeFiles/test-gtc_integer.dir/requires

test/gtc/CMakeFiles/test-gtc_integer.dir/clean:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc && $(CMAKE_COMMAND) -P CMakeFiles/test-gtc_integer.dir/cmake_clean.cmake
.PHONY : test/gtc/CMakeFiles/test-gtc_integer.dir/clean

test/gtc/CMakeFiles/test-gtc_integer.dir/depend:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/comput-6/anim/Detection/submodule/glm /home/comput-6/anim/Detection/submodule/glm/test/gtc /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/test/gtc/CMakeFiles/test-gtc_integer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/gtc/CMakeFiles/test-gtc_integer.dir/depend

