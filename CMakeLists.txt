# This file is part of the cg project.
# Copyright 2019 CyberViking Softwareschmiede GbR <leghissa@cyber-viking.com>.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


# we want the cool stuff
cmake_minimum_required(VERSION 3.13)
include(cmake/grabgitversion.cmake)
project(cg LANGUAGES CXX VERSION ${VERSION_STR})
include(include/files.cmake)
include(src/files.cmake)
set(LIB_NAME lib${PROJECT_NAME}) # libcg in this case
set (CMAKE_CXX_STANDARD 11)
# tell cmake to use our custom find-modules:
list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_SOURCE_DIR}/cmake/modules/")


# determine some libraries (the ones which cmake has a find_module for) to link against
# to check for existing find_modules  hit: cmake --help-module-list in your terminal.
# to check for info and variables set hit: cmake --help-module Find<ModuleName> in your terminal.
find_package(OpenGL REQUIRED)
find_package(GLEW 1.11 REQUIRED)
find_package(DevIL REQUIRED)
find_package(glm 0.9.7 REQUIRED)

# dependencies via pkgconfig:
#find_package(PkgConfig REQUIRED)
#pkg_search_module(GLFW REQUIRED glfw3)

# our custom find-modules in ./cmake/modules
find_package(Glm REQUIRED) # not to be confused with glm, the gl math library
find_package(Lib3ds 2 REQUIRED)


# generate config cpp file and append to sources
configure_file(
	cmake/config.inc
	src/cg/util/config.cpp
)
LIST(APPEND ${PROJECT_NAME}_SOURCES "src/cg/util/config.cpp")

# other files which aree considered as part of the project.
set(MISC
	"README.md"
	"LICENSE"
	"cmake-clean"
)
# generated library config files for finding this lib
set(FINDME
	"${CMAKE_BINARY_DIR}/${LIB_NAME}-config.cmake"
	"${CMAKE_BINARY_DIR}/${LIB_NAME}-config-version.cmake"
)
# cmake modules to be installed.
set(CMAKE
	"cmake/config.inc"
	"cmake/grabgitversion.cmake"
	"cmake/generateconfig.cmake"
	"cmake/modules/FindGlm.cmake"
	"cmake/modules/FindLib3ds.cmake"
	"cmake/modules/${LIB_NAME}-config.cmake.in"
)


# the target and it's properties
# build a shared lib (also add misc files here, in order to see them in the ide)
add_library (${PROJECT_NAME} SHARED
	${${PROJECT_NAME}_SOURCES}
	${${PROJECT_NAME}_HEADERS}
	${MISC}
	${MODS}
	${FINDME}
	${CMAKE}
)

# target properties for naming the lib according version number
set_target_properties (${PROJECT_NAME} PROPERTIES
	VERSION ${VERSION_STR}
	SOVERSION ${VERSION_MAJOR}
)

# add the determined header dirs as well as the project root to be used by cmake
include_directories(
	${CMAKE_SOURCE_DIR}/include
	${OpenGL_INCLUDE_DIR}
	${GLEW_INCLUDE_DIRS}
	#${GLFW_INCLUDE_DIRS}
	${IL_INCLUDE_DIRS}
	${GLM_INCLUDE_DIRS}
	${Glm_INCLUDE_DIR} # not to be confused with glm, the gl math library
	${Lib3ds_INCLUDE_DIRS}
)

# link against found libraries and
target_link_libraries(${PROJECT_NAME} PUBLIC
	${OPENGL_opengl_LIBRARY}
	${OPENGL_glu_LIBRARY} # NOTE this is for legacy stuff, like glm-obj
	${GLEW_LIBRARIES}
	#${GLFW_LIBRARIES}
	${IL_LIBRARIES}
	${ILU_LIBRARIES}
	${ILUT_LIBRARIES}
	${Glm_LIB} # not to be confused with glm, the gl math library
	${Lib3ds_LIBRARIES}
)

include(cmake/generateconfig.cmake)


# install targets
install (# install the lib
	TARGETS ${PROJECT_NAME}
	DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)
install (# install the find module of this lib.
	FILES ${FINDME}
	DESTINATION lib/cmake/${LIB_NAME}
)
install (# install header files preserving dir structure
	DIRECTORY include/
	DESTINATION ${CMAKE_INSTALL_PREFIX}/include
	FILES_MATCHING PATTERN "*.hpp"
)
