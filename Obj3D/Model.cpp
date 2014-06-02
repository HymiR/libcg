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

std::string Model::getFilepath() {
	  return this->filepath;
}
