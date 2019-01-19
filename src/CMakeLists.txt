
# allow to run application in the build dir
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
SET(CMAKE_INSTALL_RPATH "${SUBMODULE_INSTALL_DIRECTORY}/lib;${SUBMODULE_INSTALL_DIRECTORY}/bin;${LIBRARY_OUTPUT_PATH}")

set(Exe "Detection")

find_package(OpenCV REQUIRED) # define OPENGL_LIBRARIES
include_directories( ${OpenCV_INCLUDE_DIRS} )

find_package(OpenMP)
include_directories(${OpenMP_INCLUDE_DIRS})
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON )


FILE(GLOB_RECURSE folder_source ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.inl)
FILE(GLOB_RECURSE folder_header ${CMAKE_SOURCE_DIR}/src/*.hpp ${CMAKE_SOURCE_DIR}/src/*.h)


include_directories(
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src
        ${INCLUDE_DIRS}
)

SOURCE_GROUP("Source Files" FILES ${folder_source})
SOURCE_GROUP("Header Files" FILES ${folder_header})

add_executable(${Exe}
        ${folder_source}
        ${folder_header}
        )

add_dependencies(${Exe} glm_lib Ressources)

target_link_libraries(${Exe} ${app_libs} ${OpenCV_LIBS} ${OpenMP_INCLUDE_DIRS})

