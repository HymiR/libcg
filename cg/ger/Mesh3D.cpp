/*
 * File:   Mesh3D.cpp
 * Author: vidar
 *
 * Created on 31. Mai 2014, 16:51
 */


#include "Mesh3D.hpp"
#include "Model3DS.hpp"
#include "ModelObj.hpp"


namespace cg
{
	namespace ger
	{
		Mesh3D::Mesh3D()
		{
		}

		Mesh3D::Mesh3D(const Mesh3D& orig)
		{
		}

		Mesh3D::~Mesh3D()
		{
		}

		void Mesh3D::addModel(std::string name)
		{

			Model* model = NULL;

			std::string modelspath = MODELPATH + "/" + name;
			std::string shaderspath = SHADERPATH + "/" + name;
			std::string texturespath = TEXTUREPATH + "/" + name;

			if(Helpers::folderExists(modelspath)) {
				std::vector<std::string> modelfiles = Helpers::getFilesFromFolder(modelspath);

				for(std::string thismodel : modelfiles) {
					std::string ext = Helpers::getExt(thismodel);
					if(ext == "3ds" || ext == "3DS" || ext == "3Ds" || ext == "3dS") {
						model = new Model3DS(thismodel);
					} else if(ext == "obj" || ext == "OBJ" || ext == "OBj" || ext == "ObJ") {
						model = new ModelObj(thismodel);
					} else {
						std::cout << "No module to load this model: " << thismodel << "\n";
						continue;
					}
					if(model) {
						if(!model->loadModel()) {
							delete model;
							model = NULL;
							continue;
						}
						if(Helpers::folderExists(shaderspath)) {
							std::vector<std::string> shaderfiles = Helpers::getFilesFromFolder(shaderspath);
							for(std::string s : shaderfiles) {
								model->addShaderPath(s);
							}
						}

						if(Helpers::folderExists(texturespath)) {
							std::vector<std::string> texturefiles = Helpers::getFilesFromFolder(texturespath);
							for(std::string t : texturefiles) {
								model->addTexturePath(t);
								model->addTexture(t);
							}
						}

						model->loadShaders();
						model->addShader(SHADERPATH + "/" + "standard.vertexshader",
								SHADERPATH + "/" + "standard.fragmentshader",
								true);

						Models.push_back(model);
						model = NULL;
					}
				}
			}
		}

		std::vector<Model*> Mesh3D::getModels()
		{
			return this->Models;
		}

		/**
		 * For simplicity we have only one model/mesh so we don't
		 * calculate a center point yet
		 * @param x
		 * @param y
		 * @param z
		 */
		void Mesh3D::setInitialPosition(GLfloat x, GLfloat y, GLfloat z)
		{
			for(Model* m : this->Models)
				m->setPosition(x, y, z);
		}
	}
}
