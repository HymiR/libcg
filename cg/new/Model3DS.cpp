/*
 * File:   Model3DS.cpp
 * Author: vidar
 *
 * Created on 11. Juni 2014, 15:42
 */


#include "Model3DS.hpp"


Model3DS::Model3DS(std::string path)
{
	this->filepath = path;
}

Model3DS::Model3DS(const Model3DS& orig)
{
}

Model3DS::~Model3DS()
{
}

bool Model3DS::loadModel()
{
}
