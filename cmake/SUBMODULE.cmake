include(ExternalProject)


set(SUBMODULE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/submodule)
# as CMAKE_INSTALL_PREFIX is set to ROGUE_BUILD_DIRECTORY by default, we might also use it
set(SUBMODULE_INSTALL_DIRECTORY ${BUILD_DIRECTORY}/submodule)
set(SUBMODULE_BUILD_TYPE Release)

include(SUBGLM)
