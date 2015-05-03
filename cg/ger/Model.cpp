/*
 * File:   Model.cpp
 * Author: vidar
 *
 * Created on 31. Mai 2014, 15:24
 */


#include "Model.hpp"
#include "Helpers.hpp"


namespace cg
{
	namespace ger
	{
		Model::Model() {}

		Model::Model(const Model& orig) {}

		Model::~Model() {}

		void Model::setFilepath(std::string path)
		{
			this->filepath = path;
		}

		void Model::addTexturePath(std::string texturepath)
		{
			this->texturepaths.push_back(texturepath);
		}

		void Model::addShaderPath(std::string shaderpath)
		{
			this->shaderpaths.push_back(shaderpath);
		}

		std::string Model::getFilepath()
		{
			return this->filepath;
		}

		std::vector<std::string> Model::getTextures()
		{
			return this->texturepaths;
		}

		std::vector<std::string> Model::getShaders()
		{
			return this->shaderpaths;
		}

		void Model::loadShaders()
		{
			std::vector<std::string> vertexshaders;
			std::vector<std::string> fragmentshaders;

			for(std::string shader : this->shaderpaths) {
				if(Helpers::getExt(shader) == "vertexshader" || Helpers::getExt(shader) == "vertex") {
					vertexshaders.push_back(shader);
				} else if(Helpers::getExt(shader) == "fragmentshader" || Helpers::getExt(shader) == "fragment") {
					fragmentshaders.push_back(shader);
				} else {
					std::cout << "Shader: " + shader + " : unknown extension!\n";
				}
			}

			// TODO: REALLY test this abominable shit later on!
			for(size_t v = 0; v < vertexshaders.size(); v++) {
				for(size_t f = 0; f < fragmentshaders.size(); f++) {
					if(Helpers::getFileName(vertexshaders.at(v)) == Helpers::getFileName(fragmentshaders.at(f))) {
						// We found the associated fragmentshader for this vertexshader
						addShader(vertexshaders.at(v), fragmentshaders.at(f));
						break;
					}
				}
				// TODO: what to do with single shaders??
			}
		}

		void Model::setPosition(GLfloat x, GLfloat y, GLfloat z)
		{
			// For now we use just the first geometry, think of something better
			addInitialPosition(0, glm::vec3(x, y, z));
		}
	}
}
