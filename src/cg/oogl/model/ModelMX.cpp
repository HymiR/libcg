/*
 * ModelMX.cpp
 * Copyright (C) HymiR <leghissa@fim.uni-passau.de>
 * 
 * 
 * ModelMX.cpp is free software.
 * 
 * You may redistribute it and/or modify it under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * ModelMX.cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with ModelMX.cpp.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */


#include <cg/oogl/model/ModelMX.hpp>
#include <cg/oogl/Model.hpp>
#include <cg/oogl/Texture.hpp>


namespace oogl
{
	namespace model
	{
		/**
		 *
		 */
		ModelMX::ModelMX(std::string fileName, Model::LoadOptions options)
			: Model(fileName, options)
			, currentFrame(0);
		{
			loadFile();
		}


		/**
		 *
		 */
		ModelMX::~ModelMX()
		{
			LOG_DEBUG << "free model " << fileName << std::endl;
			if(file)
				; // free the file structure

			for(Texture* texture : textures)
				delete texture;
		}
	}
}
