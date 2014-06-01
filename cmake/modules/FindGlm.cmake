# - Try to find Glm, the Alias Wavefront OBJ file library
#
# Website: http://devernay.free.fr/hacks/glm/
# License: GPL-2
# Author : Armin Leghissa.
#
# Once done this will define
#
# Glm_FOUND - system has Glm
# Glm_INCLUDE_DIR - the Glminclude directory
# Glm_LIB - link these to use Glm
#
# If Glm stuff wasn't found, you can set the variable: Glm_ROOT
# On commandline use -DGlm_ROOT=<path>
# This is specially useful for building on Windows.
#

set(INLUDE_SEARCH_DIRS
	"/usr/include"
	"/usr/local/include")

set(LIB_SEARCH_DIRS
	"/usr/lib"
	"/usr/local/lib")

if(Glm_ROOT)
	set(LIB_SEARCH_DIRS
		"${Glm_ROOT}"
		"${Glm_ROOT}/lib"
		${LIB_SEARCH_DIRS})
	set(INLUDE_SEARCH_DIRS
		"${Glm_ROOT}"
		"${Glm_ROOT}/include"
		${INLUDE_SEARCH_DIRS})
endif(Glm_ROOT)

find_path(Glm_INCLUDE_DIR
	NAMES glm.h
	PATHS ${INLUDE_SEARCH_DIRS})

find_library(Glm_LIB
	NAMES glm
	PATHS ${LIB_SEARCH_DIRS})


if(Glm_INCLUDE_DIR)
	message(STATUS "Found Glm include dir: ${Glm_INCLUDE_DIR}")
else(Glm_INCLUDE_DIR)
	message(STATUS "Could NOT find Glm headers.")
endif(Glm_INCLUDE_DIR)

if(Glm_LIB)
	message(STATUS "Found Glm library: ${Glm_LIB}")
else(Glm_LIB)
	message(STATUS "Could NOT find Glm library.")
endif(Glm_LIB)

if(Glm_INCLUDE_DIR AND Glm_LIB)
	set(Glm_FOUND TRUE)
endif(Glm_INCLUDE_DIR AND Glm_LIB)
