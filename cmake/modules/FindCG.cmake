# - Try to find libcg
# Once done this will define
#
# CG_FOUND - system has libcg
# CG_INCLUDE_DIR - the libcg include directory
# CG_LIB - link these to use libcg
#
# You can set CG_ROOT using -D switch on command line if CG can't be found.
#

set(INLUDE_SEARCH_DIRS
	"/usr/include"
	"/usr/local/include")

set(LIB_SEARCH_DIRS
	"/usr/lib"
	"/usr/local/lib")

if(CG_ROOT)
	set(LIB_SEARCH_DIRS
		"${CG_ROOT}"
		"${CG_ROOT}/lib"
		${LIB_SEARCH_DIRS})
	set(INLUDE_SEARCH_DIRS
		"${CG_ROOT}"
		"${CG_ROOT}/include"
		${INLUDE_SEARCH_DIRS})
endif(CG_ROOT)


# this is simply an heuristic "evidence" of the headers being installed, not a consistency check.
# so one file should be completely sufficient.
# in this particular case we want to assure that the minimum required edition is installed.
find_path(CG_INCLUDE_DIR
	NAMES oogl/Model.hpp ger/Model.hpp
	PATHS ${INLUDE_SEARCH_DIRS}/cg/)

find_library(CG_LIB
	NAMES cg
	PATHS ${LIB_SEARCH_DIRS})

if(CG_INCLUDE_DIR)
	message(STATUS "Found libcg include dir: ${CG_INCLUDE_DIR}")
else(CG_INCLUDE_DIR)
	message(STATUS "Could NOT find libcg headers.")
endif(CG_INCLUDE_DIR)

if(CG_LIB)
	message(STATUS "Found libcg library: ${CG_LIB}")
else(CG_LIB)
	message(STATUS "Could NOT find libcg library.")
endif(CG_LIB)

if(CG_INCLUDE_DIR AND CG_LIB)
	set(CG_FOUND TRUE)
else(CG_INCLUDE_DIR AND CG_LIB)
	message(FATAL_ERROR "Could not find libcg. Please install libcg (https://github.com/HymiR/libcg)")
endif(CG_INCLUDE_DIR AND CG_LIB)
