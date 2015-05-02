/*
 * File:   TheMatrix.h
 * Author: vidar
 *
 * Created on 03. Juni 2014, 16:24
 */


#ifndef THEMATRIX_H
#define THEMATRIX_H

#include "Matrices.hpp"


class TheMatrix
{
public:
	TheMatrix();
	TheMatrix(const TheMatrix& orig);
	virtual ~TheMatrix();

	static Matrices* getPipeline();
	static void setPipeline(Matrices m);
	const static glm::mat4 getIdentityMatrix();

private:
	static Matrices PipelineMatrices;
	const static glm::mat4 IdentityMatrix;
};

static TheMatrix Pipeline;

#endif /* THEMATRIX_H */
