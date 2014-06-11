/* 
 * File:   Model3DS.h
 * Author: vidar
 *
 * Created on 11. Juni 2014, 15:42
 */

#ifndef MODEL3DS_H
#define	MODEL3DS_H
#include "Model.h"
#include "cstring"

class Model3DS : public Model {
public:
	  Model3DS(std::string path);
	  Model3DS(const Model3DS& orig);
	  virtual ~Model3DS();
	  void loadModel();
protected:

};

#endif	/* MODEL3DS_H */

