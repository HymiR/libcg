/* 
 * File:   Obj3D.cpp
 * Author: vidar
 * 
 * Created on 31. Mai 2014, 16:45
 */

#include "Obj3D.h"

Obj3D::Obj3D() {
}

Obj3D::Obj3D(const Obj3D& orig) {
}

Obj3D::~Obj3D() {
}

void Obj3D::initialise(std::vector<std::string> modelnames) {
	  for(std::string modelname : modelnames) {
		    Mesh3D* mesh3d = new Mesh3D();
		    mesh3d->addModel(modelname);
		    this->meshes.push_back(mesh3d);
	  }
}

void Obj3D::spawnAt(GLfloat x, GLfloat y, GLfloat z) {
	  for(Mesh3D* mesh3d : this->meshes) {
		    mesh3d->setInitialPosition(x, y, z);
	  }
}

void Obj3D::draw() {
	  for(Mesh3D* mesh : this->meshes) {
		    for(Model* model : mesh->getModels()) {
			      model->render();
		    }
	  }
}

void Obj3D::animate() {
	  
}

void Obj3D::rotate() {
	  
}

void Obj3D::translate() {
	  
}
