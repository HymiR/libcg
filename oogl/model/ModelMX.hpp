/*
 * ModelMX.hpp
 * Copyright (C) HymiR <leghissa@fim.uni-passau.de>
 * 
 * ModelMX.hpp is free software.
 * 
 * You may redistribute it and/or modify it under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * ModelMX.hpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with ModelMX.hpp.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */


#ifndef MODMX_H
#define

#include <oogl/Texture.hpp>
#include <oogl/Model.hpp>

#include <vector>


namespace oogl
{
	namespace model
	{
		/**
		 * This is a Model loader for loading the MX model files used
		 * by the 6dof game "Forsaken".
		 */
		class ModelMX : public Model
		{
			private:
				void* file;
				float currentFrame;
				std::vector<oogl::Texture*> textures;

				void loadFile();
				void dump();

				oogl::Texture* abblyMaterial(void* material, RenderOptions options);
				std::string getDirectory(const std::string& fileName);


			public:
				ModelMX(std::string fileName, Model::LoadOptions options);
				~ModelMX();

		};
	}
}

#endif // MODX_H
