/*
 * Model.cpp
 *
 *  Created on: 17.02.2011
 *      Author: sam
 */


#include <cg/oogl/Model.hpp>
#include <cg/oogl/model/Model3ds.hpp>
#include <cg/oogl/model/ModelObj.hpp>
#include <cg/util/log.hpp>

#include <cassert>
#include <stdexcept>


namespace cg
{
	namespace oogl
	{
		Model::Model(const std::string fileName, Model::LoadOptions options)
			: fileName(fileName), loadOptions(options)
		{
		}


		Model::~Model() {}


		Model* loadModel(const std::string& fileName, Model::LoadOptions options)
		{
			std::string ext = "";

			if(fileName.find_last_of(".") != std::string::npos)
				ext = fileName.substr(fileName.find_last_of(".") + 1);

			if(ext == "3ds" || ext == "3DS" || ext == "3Ds" || ext == "3dS") {
				LOG_DEBUG << "loading 3ds model " << fileName << std::endl;
				return new model::Model3ds(fileName, options);
			} else if(ext == "obj" || ext == "OBJ" || ext == "OBj" || ext == "ObJ") {
				LOG_DEBUG << "loading obj model " << fileName << std::endl;
				return new model::ModelObj(fileName, options);
			}

			throw std::runtime_error("unsupported model type: " + fileName);
		}
	}
}
