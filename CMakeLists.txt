#
# CMakeLists.txt
# This is the cmake file for the cgutils package.
#
#	Authors:
# 	Christian Rauecker
# 	Gerfried Essler
# 	Armin Leghissa
#


cmake_minimum_required(VERSION 2.6)

# project name and package version numbers
project(cgutils)
set(V_MAJOR 0)
set(V_MINOR 2)
set(V_PATCH 1)
set(V_LIB ${V_MAJOR}.${V_MINOR}.${V_PATCH})
set(LIBNAME ${PROJECT_NAME})

# tell cmake to use our custom find-modules:
set(CMAKE_MODULE_PATH
	${CMAKE_MODULE_PATH}
	"${PROJECT_SOURCE_DIR}/cmake/modules/"
)

# define a list containing the directories of our "library modules"
set(MODULES
	${PROJECT_SOURCE_DIR}/cgutil
	${PROJECT_SOURCE_DIR}/oogl
	${PROJECT_SOURCE_DIR}/glm
)

# cflags to prevent build from failing
add_definitions(-std=c++11 -Wall)


# listing the source files hardcoded instead by a find command has the
# advantage that only changed files were recompiled on performing
# incremental builds. (bug-fixing or development...)
# source file list
set(SRC
	"cgutil/timer.cpp"
	"oogl/Model.cpp"
	"oogl/FrameBufferObject.cpp"
	"oogl/Navigator.cpp"
	"oogl/Image.cpp"
	"oogl/timer.cpp"
	"oogl/DisplayList.cpp"
	"oogl/gl_error.cpp"
	"oogl/GLSLShader.cpp"
	"oogl/Texture2D.cpp"
	"oogl/Texture.cpp"
	"oogl/Texture3D.cpp"
	"oogl/GLSLProgram.cpp"
	"oogl/model/ModelObj.cpp"
	"oogl/model/Model3ds.cpp"
)

# header file list
set(HDR
	"cgutil/timer.hpp"
	"cgutil/shader.hpp"
	"cgutil/log.hpp"
	"cgutil/loglevels.hpp"
	"cgutil/math.hpp"
	"oogl/glfwIncludes.hpp"
	"oogl/Model.hpp"
	"oogl/glIncludes.hpp"
	"oogl/Texture.hpp"
	"oogl/Navigator.hpp"
	"oogl/timer.hpp"
	"oogl/DisplayList.hpp"
	"oogl/FrameBufferObject.hpp"
	"oogl/gl_error.hpp"
	"oogl/GLSLProgram.hpp"
	"oogl/GLSLShader.hpp"
	"oogl/Image.hpp"
	"oogl/Texture2D.hpp"
	"oogl/Texture3D.hpp"
	"oogl/model/Model3ds.hpp"
	"oogl/model/ModelObj.hpp"
	"glm/glm_ostream.hpp"
)


# determine some libraries (the ones which cmake has a find_module for) to link against
# to check for existing find_modules  hit: cmake --help-module-list in your terminal.
# to check for info and variables set hit: cmake --help-module Find<ModuleName> in your terminal.
find_package(DevIL REQUIRED)
find_package(OpenGL REQUIRED)

# our custom find-modules in ./cmake/modules
find_package(GLee REQUIRED)
find_package(Glm REQUIRED)
find_package(GLM REQUIRED)
find_package(Lib3ds REQUIRED)


# add the determined header dirs as well as the project root to be used by cmake
include_directories(
	${PROJECT_SOURCE_DIR}
	${IL_INCLUDE_DIRS}
	${OpenGL_INCLUDE_DIRS}
	${GLEE_INCLUDE_DIR}
	${Glm_INCLUDE_DIR}
	${GLM_INCLUDE_DIRS}
	${Lib3ds_INCLUDE_DIRS}
)

# build a shared lib from the source files and link against libs
add_library (${LIBNAME} SHARED ${SRC})

# link against found libraries and 
target_link_libraries(${LIBNAME}
	${IL_LIBRARIES}
	${ILU_LIBRARIES}
	${ILUT_LIBRARIES}
	${OpenGL_LIBRARIES}
	${GLEE_LIB}
	${Glm_LIB}
	${Lib3ds_LIBRARIES}
)


# target properties for naming the lib according version number
set_target_properties (${LIBNAME} PROPERTIES
	VERSION ${V_LIB}
	SOVERSION ${V_MAJOR}
)


# install targets
install (# install the lib
	TARGETS ${LIBNAME}
	DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)

install (# install header files preserving dir structure
	DIRECTORY ${MODULES}
	DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${LIBNAME}
	FILES_MATCHING PATTERN "*.hpp"
)


