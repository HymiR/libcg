/* 
 * File:   VertexArray.cpp
 * Author: vidar
 * 
 * Created on 31. Mai 2014, 13:45
 */

#include "VertexArray.h"

VertexArray::VertexArray() {
}

VertexArray::VertexArray(const VertexArray& orig) {
}

VertexArray::VertexArray(std::vector<glm::vec3> ve) {
	  this->vertices = ve;
}

VertexArray::~VertexArray() {
}

