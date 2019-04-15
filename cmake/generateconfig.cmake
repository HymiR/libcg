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


# set export variables
get_target_property(LINK_LIBRARIES ${PROJECT_NAME} INTERFACE_LINK_LIBRARIES)
#set(LINK_LIBRARIES GL GLU GLEW IL ILU ILUT glm 3ds)
set(EXP_INCLUDE_DIRS include/)
set(EXP_LIBRARY_DIRS lib/)
set(EXP_LIBRARIES ${LINK_LIBRARIES} ${PROJECT_NAME})

message("DDD Interface Link Libraries ${LINK_LIBRARIES}")

# generate library config files
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
	${CMAKE_BINARY_DIR}/libcg-config-version.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)
configure_package_config_file(
	${CMAKE_SOURCE_DIR}/cmake/modules/${LIB_NAME}-config.cmake.in
	${CMAKE_BINARY_DIR}/${LIB_NAME}-config.cmake
	INSTALL_DESTINATION lib/cmake/${LIB_NAME}
	PATH_VARS EXP_INCLUDE_DIRS EXP_LIBRARY_DIRS EXP_LIBRARIES
)
