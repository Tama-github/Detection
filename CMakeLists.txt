cmake_minimum_required(VERSION 3.0.2)

project(Detection)


# Be nice and export compile commands by default, this is handy for clang-tidy
# and for other tools.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# We can use include() and find_package() for scripts in there
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Ask for C++17 for all files
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable helpfull warnings
#add_compile_options(-Wall -Wextra -Wnon-virtual-dtor -Wunused -pedantic)
add_compile_options(-Wall -Wextra -Wunused)

set(BUILD_DIRECTORY            ${CMAKE_CURRENT_SOURCE_DIR}/build)
# Set default install location to dist folder in build dir
# we do not want to install to /usr by default
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${BUILD_DIRECTORY}" CACHE PATH
            "Install path prefix, prepended onto install directories." FORCE )
endif()

set(BIN_DIRECTORY              ${BUILD_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY   ${BIN_DIRECTORY}/bin)
set(EXECUTABLE_OUTPUT_PATH           ${BIN_DIRECTORY}/bin)
set(LIBRARY_OUTPUT_PATH              ${BIN_DIRECTORY}/lib)

set(SRC_DIR                    ${CMAKE_CURRENT_SOURCE_DIR}/src)


################################################################################
# Build submodule

include(SUBMODULE)

set(INCLUDE_DIRS)
list(APPEND INCLUDE_DIRS "${SRC_DIR}" "${GLM_INCLUDE_DIR}")

################################################################################
#Build
add_subdirectory(${SRC_DIR})



