/* 
 * File:   Mesh3D.h
 * Author: vidar
 *
 * Created on 31. Mai 2014, 16:51
 */

#ifndef MESH3D_H
#define	MESH3D_H
#include "Model.h"
#include <vector>

/**
 * A Mesh3D object contains one to any number of models that make one single
 * 3D object (Obj3D) that will be rendered. The source file for the model can 
 * be any filetype that is supported.
 */
class Mesh3D : public Model {
public:
	  Mesh3D();
	  Mesh3D(const Mesh3D& orig);
	  virtual ~Mesh3D();
private:
	  std::vector<Model>* Models;
};

#endif	/* MESH3D_H */
