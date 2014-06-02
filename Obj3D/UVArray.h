/* 
 * File:   UVArray.h
 * Author: vidar
 *
 * Created on 31. Mai 2014, 13:45
 */

#ifndef UVARRAY_H
#define	UVARRAY_H
#include <glm/glm.hpp>
#include <vector>

/**
 * This class contains the UV coordinates for each vertex (a vertex has two uv 
 * coordinates) of a single mesh of a 3D object (a 3D Object can have more
 * than one mesh)
 */
class UVArray {
public:
	  UVArray();
	  UVArray(const UVArray& orig);
	  UVArray(std::vector<glm::vec2> uv);
	  virtual ~UVArray();
private:
	  std::vector<glm::vec2> uvs;
};

#endif	/* UVARRAY_H */

