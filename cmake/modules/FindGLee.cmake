# - Try to find GLee
# Once done this will define
#
# GLEE_FOUND - system has GLee
# GLEE_INCLUDE_DIR - the GLee include directory
# GLEE_LIB - link these to use GLee
#
# You can set GLEE_ROOT using -D switch on command line if GLEE can't be found.
#

set(INLUDE_SEARCH_DIRS
	"/usr/include/GL"
	"/usr/local/include/GL")

set(LIB_SEARCH_DIRS
	"/usr/lib"
	"/usr/local/lib")

if(GLEE_ROOT)
	set(LIB_SEARCH_DIRS
		"${GLEE_ROOT}"
		"${GLEE_ROOT}/lib"
		${LIB_SEARCH_DIRS})
	set(INLUDE_SEARCH_DIRS
		"${GLEE_ROOT}"
		"${GLEE_ROOT}/include"
		${INLUDE_SEARCH_DIRS})
endif(GLEE_ROOT)


find_path(GLEE_INCLUDE_DIR
	NAMES GLee.h
	PATHS ${INLUDE_SEARCH_DIRS})

find_library(GLEE_LIB
	NAMES GLee
	PATHS ${LIB_SEARCH_DIRS})

if(GLEE_INCLUDE_DIR)
	message(STATUS "Found GLee include dir: ${GLEE_INCLUDE_DIR}")
else(GLEE_INCLUDE_DIR)
	message(STATUS "Could NOT find GLee headers.")
endif(GLEE_INCLUDE_DIR)

if(GLEE_LIB)
	message(STATUS "Found GLee library: ${GLEE_LIB}")
else(GLEE_LIB)
	message(STATUS "Could NOT find GLee library.")
endif(GLEE_LIB)

if(GLEE_INCLUDE_DIR AND GLEE_LIB)
	set(GLEE_FOUND TRUE)
else(GLEE_INCLUDE_DIR AND GLEE_LIB)
	message(FATAL_ERROR "Could not find GLee. Please install GLee (http://elf-stone.com/glee.php)")
endif(GLEE_INCLUDE_DIR AND GLEE_LIB)
