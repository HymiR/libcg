/* 
 * File:   ModelObj.cpp
 * Author: vidar
 * 
 * Created on 01. Juni 2014, 21:34
 */

#include "ModelObj.h"
#include "objloader.hpp"
#include "Renderable.h"
#include <glm/glm.hpp>
#include <vector>

ModelObj::ModelObj(std::string path) {
	  this->filepath = path;
}

ModelObj::ModelObj(const ModelObj& orig) {
}

ModelObj::~ModelObj() {
}

void Model::loadModel() {
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	  
	loadOBJ(this->filepath, vertices, uvs, normals);
	
	addCoordinates(vertices, uvs, normals);
}