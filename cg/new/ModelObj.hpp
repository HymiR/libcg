/*
 * File:   ModelObj.h
 * Author: vidar
 *
 * Created on 01. Juni 2014, 21:34
 */


#ifndef MODELOBJ_H
#define MODELOBJ_H

#include "Model.hpp"

#include "cstring"


class ModelObj : public Model
{
public:
	ModelObj(std::string path);
	ModelObj(const ModelObj& orig);
	virtual ~ModelObj();
	bool loadModel();

protected:
};

#endif /* MODELOBJ_H */
