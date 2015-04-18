/*
 * Model3ds.hpp
 *
 *  Created on: 26.03.2011
 *      Author: sam
 */


#ifndef MODEL3DS_HPP
#define MODEL3DS_HPP

#include <cg/oogl/Texture.hpp>
#include <cg/oogl/Model.hpp>

#include <lib3ds.h>

#include <vector>


namespace oogl
{
	namespace model
	{
		/**
		 *
		 */
		class Model3ds : public Model
		{
		public:
			Model3ds(std::string fileName, Model::LoadOptions options);
			~Model3ds();

			virtual void render(RenderOptions options = 0);


		private:
			Lib3dsFile* file;
			float currentFrame;
			std::vector<oogl::Texture*> textures;

			void loadFile();
			void renderNode(Lib3dsNode* node, RenderOptions options);
			void renderMeshNode(Lib3dsNode* node, RenderOptions options);
			void renderMeshImpl(Lib3dsMeshInstanceNode* node, Lib3dsMesh* mesh, RenderOptions options);

			void dump();

			oogl::Texture* applyMaterial(Lib3dsMaterial* material, RenderOptions options);
			std::string getDirectory(const std::string& fileName);
		};
	}
}


#endif // MODEL3DS_HPP
