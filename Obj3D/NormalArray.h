/* 
 * File:   NormalArray.h
 * Author: vidar
 *
 * Created on 31. Mai 2014, 13:46
 */

#ifndef NORMALARRAY_H
#define	NORMALARRAY_H
#include <glm/glm.hpp>
#include <vector>

/**
 * This class contains the normals (or normal vectors) of each face of a mesh.
 * (one normal for each face)
 * The normal vectors are needed to indicate the front and the back of the face.
 */
class NormalArray {
public:
	  NormalArray();
	  NormalArray(const NormalArray& orig);
	  NormalArray(std::vector<glm::vec3> no);
	  virtual ~NormalArray();
private:
	std::vector<glm::vec3> normals;
};

#endif	/* NORMALARRAY_H */

