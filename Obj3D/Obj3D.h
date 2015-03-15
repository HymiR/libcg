/* 
 * File:   Obj3D.h
 * Author: vidar
 *
 * Created on 31. Mai 2014, 16:45
 */


#ifndef OBJ3D_H
#define	OBJ3D_H

#include "Mesh3D.h"
#include <vector>
#include <cstring>


/**
 * This is the main class for all 3D objects that will be used in the 3D
 * application. It abstracts all methods that are required to load 3D
 * geometry, textures, materials and shaders of model-, texture-, 
 * shader-, and animation files and render them to the view.
 */

class Obj3D {
	public:
		Obj3D();
		Obj3D(const Obj3D& orig);
		virtual ~Obj3D();

		/**
		 * Give the name(s) of the models that make up this object
		 * They will be loaded from the models/shaders/textures/...
		 * folders  (for simplicity only ose one for now)
		 */
		void initialise(std::vector<std::string> modelnames);

		/**
		 * The same as initialise(std::vector<std::string>)
		 * but only for one model
		 * @param modelname
		 */
		void initialise(std::string modelname);

		/**
		 * Put the initialised model into the world
		 * at the given coordinates
		 */
		void spawnAt(GLfloat x, GLfloat y, GLfloat z);
		void draw();
		void translate();
		void rotate();
		void animate();

	private:
		/**
		 * For simplicity we will only use one mesh for now
		 */
		std::vector<Mesh3D*> meshes;
};

#endif	/* OBJ3D_H */

