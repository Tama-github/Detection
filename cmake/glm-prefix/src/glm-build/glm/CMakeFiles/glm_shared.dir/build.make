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
include glm/CMakeFiles/glm_shared.dir/depend.make

# Include the progress variables for this target.
include glm/CMakeFiles/glm_shared.dir/progress.make

# Include the compile flags for this target's objects.
include glm/CMakeFiles/glm_shared.dir/flags.make

glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o: glm/CMakeFiles/glm_shared.dir/flags.make
glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o: /home/comput-6/anim/Detection/submodule/glm/glm/detail/glm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/glm && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glm_shared.dir/detail/glm.cpp.o -c /home/comput-6/anim/Detection/submodule/glm/glm/detail/glm.cpp

glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glm_shared.dir/detail/glm.cpp.i"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/glm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/comput-6/anim/Detection/submodule/glm/glm/detail/glm.cpp > CMakeFiles/glm_shared.dir/detail/glm.cpp.i

glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glm_shared.dir/detail/glm.cpp.s"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/glm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/comput-6/anim/Detection/submodule/glm/glm/detail/glm.cpp -o CMakeFiles/glm_shared.dir/detail/glm.cpp.s

glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o.requires:

.PHONY : glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o.requires

glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o.provides: glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o.requires
	$(MAKE) -f glm/CMakeFiles/glm_shared.dir/build.make glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o.provides.build
.PHONY : glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o.provides

glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o.provides.build: glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o


# Object files for target glm_shared
glm_shared_OBJECTS = \
"CMakeFiles/glm_shared.dir/detail/glm.cpp.o"

# External object files for target glm_shared
glm_shared_EXTERNAL_OBJECTS =

glm/libglm_shared.so: glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o
glm/libglm_shared.so: glm/CMakeFiles/glm_shared.dir/build.make
glm/libglm_shared.so: glm/CMakeFiles/glm_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libglm_shared.so"
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/glm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glm_shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glm/CMakeFiles/glm_shared.dir/build: glm/libglm_shared.so

.PHONY : glm/CMakeFiles/glm_shared.dir/build

glm/CMakeFiles/glm_shared.dir/requires: glm/CMakeFiles/glm_shared.dir/detail/glm.cpp.o.requires

.PHONY : glm/CMakeFiles/glm_shared.dir/requires

glm/CMakeFiles/glm_shared.dir/clean:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/glm && $(CMAKE_COMMAND) -P CMakeFiles/glm_shared.dir/cmake_clean.cmake
.PHONY : glm/CMakeFiles/glm_shared.dir/clean

glm/CMakeFiles/glm_shared.dir/depend:
	cd /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/comput-6/anim/Detection/submodule/glm /home/comput-6/anim/Detection/submodule/glm/glm /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/glm /home/comput-6/anim/Detection/cmake/glm-prefix/src/glm-build/glm/CMakeFiles/glm_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glm/CMakeFiles/glm_shared.dir/depend

