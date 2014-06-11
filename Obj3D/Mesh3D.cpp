/* 
 * File:   Mesh3D.cpp
 * Author: vidar
 * 
 * Created on 31. Mai 2014, 16:51
 */

#include "Mesh3D.h"
#include "Model3DS.h"
#include "ModelObj.h"

Mesh3D::Mesh3D() {
}

Mesh3D::Mesh3D(const Mesh3D& orig) {
}

Mesh3D::~Mesh3D() {
}

void Mesh3D::addModel(std::string name) {
	  
	Model* model = NULL;
	
	std::string modelspath = MODELPATH + "/" + name;
	std::string shaderspath = SHADERPATH + "/" + name;
	std::string texturespath = TEXTUREPATH + "/" + name;
	
	if(folderExists(modelspath)) {
		std::vector<std::string> modelfiles = getFilesFromFolder(modelspath);
		
		// For now we take only the first model in the list
		std::string firstmodel = modelfiles.at(0);
		std::string ext = getExt(firstmodel);
		if(ext == "3ds" || ext == "3DS" || ext == "3Ds" || ext == "3dS") {
			  model = new Model3DS(firstmodel);
		} else if (ext == "obj" || ext == "OBJ" || ext == "OBj" || ext == "ObJ") {
			  model = new ModelObj(firstmodel);
		}
		
	} else if(folderExists(shaderspath)) {
		
	} else if (folderExists(texturespath)) {
		  
	}
	Models.push_back(model);
}

bool Mesh3D::folderExists(std::string path) {
	struct stat buf;
	if (stat(path.c_str(), &buf) != -1) {
		return true;
	}
	return false;
}

std::string Mesh3D::getExt(std::string path) {
	std::string ext = "";
	if(path.find_last_of(".") != std::string::npos)
		ext = path.substr(path.find_last_of(".")+1);
	return ext;
}

std::vector<std::string> Mesh3D::getFilesFromFolder(std::string path) {
	boost::filesystem::path meshfilepath(path);
	std::vector<std::string> files;
	  
	boost::filesystem::directory_iterator end_itr;
	for(boost::filesystem::directory_iterator itr( meshfilepath );
	    itr != end_itr; ++itr ) {
		files.push_back(itr->path().c_str());
	}
	  
	return files;
}