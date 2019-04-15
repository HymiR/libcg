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


LIST(APPEND ${PROJECT_NAME}_HEADERS
	include/cg/util/timer.hpp
	include/cg/util/log.hpp
	include/cg/util/loglevels.hpp
	include/cg/util/math.hpp
	include/cg/util/config.hpp
	include/cg/oogl/Model.hpp
	include/cg/oogl/glIncludes.hpp # simple includes, without glfw, especially internal
	include/cg/oogl/glfwIncludes.hpp # includes for usage with glfw, only for user
	include/cg/oogl/Texture.hpp
	include/cg/oogl/Navigator.hpp
	include/cg/oogl/timer.hpp
	include/cg/oogl/DisplayList.hpp
	include/cg/oogl/FrameBufferObject.hpp
	include/cg/oogl/gl_error.hpp
	include/cg/oogl/GLSLProgram.hpp
	include/cg/oogl/GLSLShader.hpp
	include/cg/oogl/Image.hpp
	include/cg/oogl/Texture2D.hpp
	include/cg/oogl/Texture3D.hpp
	include/cg/oogl/model/Model3ds.hpp
	include/cg/oogl/model/ModelObj.hpp
	include/cg/oogl/model/ModelMX.hpp
	include/cg/io/glm_ostream.hpp
)
