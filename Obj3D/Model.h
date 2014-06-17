/* 
 * File:   Model.h
 * Author: vidar
 *
 * Created on 31. Mai 2014, 15:24
 */

#ifndef MODEL_H
#define	MODEL_H
#include <cstring>
#include <vector>
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
	  
	  /*
	   * Loading shaders works always the same so we need just a simple
	   * non abstract function to add the vertex and fragment shaders 
	   * to our model
	   * 
	   * IMPORTANT: Shaders come ALWAYS in pairs: one vertex and one fragment
	   * with the same file name and vertexshader/fragmentshader as extension
	   */
	  void loadShaders();
	  
	  void setPosition(GLfloat x, GLfloat y, GLfloat z);
	  
	  std::string getFilepath();
	  std::vector<std::string> getTextures();
	  std::vector<std::string> getShaders();
	  
	  void setFilepath(std::string path);
	  void addTexturePath(std::string texturepath);
	  void addShaderPath(std::string shaderpath);
protected:
	  std::string filepath;
	  std::vector<std::string> shaderpaths;
	  std::vector<std::string> texturepaths;

};

#endif	/* MODEL_H */

