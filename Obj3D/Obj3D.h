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
	   * A list of all files (with path) that are necessary to build 
	   * this model. 
	   * The program will decide on the basis of the file extensions
	   * what to do.
	   */
	  void initialise(std::vector<std::string> files);
	  void translate();
	  void rotate();
	  void animate();
	  
private:
	  std::vector<Mesh3D>* meshes;
};

#endif	/* OBJ3D_H */

