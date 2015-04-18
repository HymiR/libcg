#
# CMakeLists.txt
# This is the cmake file for the cg package.
#
#	Authors:
# 	Christian Rauecker
# 	Gerfried Essler
# 	Armin Leghissa
#


cmake_minimum_required(VERSION 2.6)

# project name and package version numbers
project(cg)
set(V_MAJOR 0)
set(V_MINOR 2)
set(V_PATCH 2)
set(V_LIB ${V_MAJOR}.${V_MINOR}.${V_PATCH})
set(LIBNAME ${PROJECT_NAME})

# tell cmake to use our custom find-modules:
set(CMAKE_MODULE_PATH
	${CMAKE_MODULE_PATH}
	"${PROJECT_SOURCE_DIR}/cmake/modules/"
)

# define a list containing the directories of our "library modules"
set(MODULES
	${PROJECT_SOURCE_DIR}/cg/util
	${PROJECT_SOURCE_DIR}/cg/oogl
	${PROJECT_SOURCE_DIR}/cg/io
	${PROJECT_SOURCE_DIR}/cg/new
)

# cflags to prevent build from failing
add_definitions(-std=c++11 -Wall)


# listing the source files hardcoded instead by a find command has the
# advantage that only changed files were recompiled on performing
# incremental builds. (bug-fixing or development...)
# source file list
set(SRC
	"cg/util/timer.cpp"
	"cg/oogl/Model.cpp"
	"cg/oogl/FrameBufferObject.cpp"
	"cg/oogl/Navigator.cpp"
	"cg/oogl/Image.cpp"
	"cg/oogl/timer.cpp"
	"cg/oogl/DisplayList.cpp"
	"cg/oogl/gl_error.cpp"
	"cg/oogl/GLSLShader.cpp"
	"cg/oogl/Texture2D.cpp"
	"cg/oogl/Texture.cpp"
	"cg/oogl/Texture3D.cpp"
	"cg/oogl/GLSLProgram.cpp"
	"cg/oogl/model/ModelObj.cpp"
	"cg/oogl/model/Model3ds.cpp"
	"cg/new/Mesh3D.cpp"
	"cg/new/Obj3D.cpp"
	"cg/new/vboindexer.cpp"
	"cg/new/Model.cpp"
	"cg/new/objloader.cpp"
	"cg/new/ModelObj.cpp"
	"cg/new/Model3DS.cpp"
	"cg/new/Renderable.cpp"
	"cg/new/TheMatrix.cpp"
	"cg/new/Helpers.cpp"
)

# header file list
set(HDR
	"cg/util/timer.hpp"
	"cg/util/shader.hpp"
	"cg/util/log.hpp"
	"cg/util/loglevels.hpp"
	"cg/util/math.hpp"
	"cg/oogl/glfwIncludes.hpp"
	"cg/oogl/Model.hpp"
	"cg/oogl/glIncludes.hpp"
	"cg/oogl/Texture.hpp"
	"cg/oogl/Navigator.hpp"
	"cg/oogl/timer.hpp"
	"cg/oogl/DisplayList.hpp"
	"cg/oogl/FrameBufferObject.hpp"
	"cg/oogl/gl_error.hpp"
	"cg/oogl/GLSLProgram.hpp"
	"cg/oogl/GLSLShader.hpp"
	"cg/oogl/Image.hpp"
	"cg/oogl/Texture2D.hpp"
	"cg/oogl/Texture3D.hpp"
	"cg/oogl/model/Model3ds.hpp"
	"cg/oogl/model/ModelObj.hpp"
	"cg/io/glm_ostream.hpp"
	"cg/new/Mesh3D.h"
	"cg/new/ModelObj.h"
	"cg/new/Obj3D.h"
	"cg/new/Model.h"
	"cg/new/Renderable.h"
	"cg/new/objloader.hpp"
	"cg/new/vboindexer.hpp"
	"cg/new/Matrices.h"
	"cg/new/TheMatrix.h"
	"cg/new/Paths.h"
	"cg/new/Model3DS.h"
	"cg/new/Helpers.h"
)


# determine some libraries (the ones which cmake has a find_module for) to link against
# to check for existing find_modules  hit: cmake --help-module-list in your terminal.
# to check for info and variables set hit: cmake --help-module Find<ModuleName> in your terminal.
find_package(DevIL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)

# our custom find-modules in ./cmake/modules
find_package(GLee REQUIRED)
find_package(Glm REQUIRED)
find_package(Lib3ds REQUIRED)

# Anti-Masochist-Library
find_package(Boost REQUIRED)

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


