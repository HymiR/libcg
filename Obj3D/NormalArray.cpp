/* 
 * File:   NormalArray.cpp
 * Author: vidar
 * 
 * Created on 31. Mai 2014, 13:46
 */

#include "NormalArray.h"

NormalArray::NormalArray() {
}

NormalArray::NormalArray(const NormalArray& orig) {
}

NormalArray::NormalArray(std::vector<glm::vec3> no) {
	  this->normals = no;
}

NormalArray::~NormalArray() {
}

