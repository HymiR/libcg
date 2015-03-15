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
#include "Paths.h"
#include "Helpers.h"


/**
 * A Mesh3D object contains one to any number of models that make one single
 * 3D object (Obj3D) that will be rendered. The source file for the model can 
 * be any filetype that is supported.
 */
class Mesh3D {
	public:
		Mesh3D();
		Mesh3D(const Mesh3D& orig);
		virtual ~Mesh3D();
		/**
		 * @param The name of the folder/s where the files of the object is
		 * located, for example if name contains "canon" the function will 
		 * search in:
		 * models/canon
		 * shaders/canon
		 * sounds/canon
		 * ...
		 */
		void addModel(std::string name);

		/**
		 * This function sets the initial position of the meshes
		 * It also calculates offsets of the single meshes from the center 
		 * point of the whole model which can consist of several meshes
		 */
		void setInitialPosition(GLfloat x, GLfloat y, GLfloat z);

		std::vector<Model*> getModels();

	private:
		std::vector<Model*> Models;
};

#endif	/* MESH3D_H */

