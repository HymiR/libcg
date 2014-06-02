/* 
 * File:   Model.h
 * Author: vidar
 *
 * Created on 31. Mai 2014, 15:24
 */

#ifndef MODEL_H
#define	MODEL_H
#include <cstring>
#include "Renderable.h"

class Model : public Renderable {
public:
	  Model();
	  Model(const Model& orig);
	  virtual ~Model();
	  /*
	   * This method will be implemented by specialised model loaders.
	   * The purpose of the model loader is to extract the vertices, 
	   * normals, uv coordinates, smoothing groups, material information etc.
	   * and save it to the corresponding arrays.
	   */
	  virtual void loadModel() = 0;
	  
	  std::string getFilepath();
	  
	  void setFilepath(std::string path);
protected:
	  std::string filepath;

};

#endif	/* MODEL_H */

