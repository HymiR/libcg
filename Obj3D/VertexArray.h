/* 
 * File:   VertexArray.h
 * Author: vidar
 *
 * Created on 31. Mai 2014, 13:45
 */

#ifndef VERTEXARRAY_H
#define	VERTEXARRAY_H
#include <glm/glm.hpp>
#include <vector>

/**
 * This class contains the vertices of a mesh (a vertex has 3 coordinates
 * x,y and z) 3 (or 4) vertices make a face (triangle or rectangle) of the mesh
 */
class VertexArray {
public:
	  VertexArray();
	  VertexArray(const VertexArray& orig);
	  VertexArray(std::vector<glm::vec3> ve);
	  virtual ~VertexArray();
private:
	std::vector<glm::vec3> vertices;
};

#endif	/* VERTEXARRAY_H */

