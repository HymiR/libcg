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
	  
	if(folderExists(MODELPATH + name)) {
		std::string ext = getExt(name);
		if(ext == "3ds" || ext == "3DS" || ext == "3Ds" || ext == "3dS") {
			  model = new Model3DS(MODELPATH + name);
		} else if (ext == "obj" || ext == "OBJ" || ext == "OBj" || ext == "ObJ") {
			  model = new ModelObj(MODELPATH + name);
		} 
	} else if(folderExists(SHADERPATH + name)) {
		
	} else if (folderExists(TEXTUREPATH + name)) {
		  
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