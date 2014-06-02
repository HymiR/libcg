/* 
 * File:   UVArray.cpp
 * Author: vidar
 * 
 * Created on 31. Mai 2014, 13:45
 */

#include "UVArray.h"

UVArray::UVArray() {
}

UVArray::UVArray(const UVArray& orig) {
}

UVArray::UVArray(std::vector<glm::vec2> uv) {
	  this->uvs = uv;
}

UVArray::~UVArray() {
}

