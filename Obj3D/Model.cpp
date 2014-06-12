/* 
 * File:   Model.cpp
 * Author: vidar
 * 
 * Created on 31. Mai 2014, 15:24
 */

#include "Model.h"

Model::Model() {
}

Model::Model(const Model& orig) {
}

Model::~Model() {
}

void Model::setFilepath(std::string path) {
	  this->filepath = path;
}

void Model::addTexture(std::string texturepath) {
	  this->texturepaths.push_back(texturepath);
}

void Model::addShader(std::string shaderpath) {
	  this->shaderpaths.push_back(shaderpath);
}

std::string Model::getFilepath() {
	  return this->filepath;
}

std::vector<std::string> Model::getTextures() {
	  return this->texturepaths;
}

std::vector<std::string> Model::getShaders() {
	  return this->shaderpaths;
}

void Model::loadShaders() {
	  std::vector<std::string> vertexshaders;
	  std::vector<std::string> fragmentshaders;
	  
	  for(std::string shader : this->shaderpaths) {
		  
	  }
}