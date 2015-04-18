/*
 * File:   ModelObj.cpp
 * Author: vidar
 *
 * Created on 01. Juni 2014, 21:34
 */


#include "ModelObj.hpp"
#include "objloader.hpp"
#include "Renderable.hpp"

#include <glm.h> // The glm-obj loader, not the GL Math lib GLM
#include <glm/glm.hpp>

#include <vector>


ModelObj::ModelObj(std::string path)
{
	this->filepath = path;
}

ModelObj::ModelObj(const ModelObj& orig)
{
}

ModelObj::~ModelObj()
{
}

bool ModelObj::loadModel()
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	// TODO: This loader is bullshit use the one below
	if(loadOBJ(this->filepath.c_str(), vertices, uvs, normals)) {
	} else {
		std::cout << "Error loading obj file, giving up.\n";
		return false;
	}

	/*
	GLMmodel* model = glmReadOBJ(this->filepath.c_str());
	for(uint i = 0; i < model->numvertices; i++) {
		glm::vec3 vertex(model->vertices[i],
				 model->vertices[i+1],
				 model->vertices[i+2]);
		vertices.push_back(vertex);
	}
	for(uint i = 0; i < model->numnormals; i++) {
		glm::vec3 normal(model->normals[i],
				 model->normals[i+1],
				 model->normals[i+2]);
		normals.push_back(normal);
	}
	for(uint i = 0; i < model->numtexcoords; i++) {
		glm::vec2 uv(model->texcoords[i],
				 model->texcoords[i+1]);
		uvs.push_back(uv);
	}
	*/

	addGeometry(vertices, uvs, normals);
	return true;
}
