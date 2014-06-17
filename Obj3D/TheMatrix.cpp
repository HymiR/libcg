/* 
 * File:   TheMatrix.cpp
 * Author: vidar
 * 
 * Created on 03. Juni 2014, 16:24
 */

#include "TheMatrix.h"

const glm::mat4 TheMatrix::IdentityMatrix = glm::mat4(1);
Matrices TheMatrix::PipelineMatrices = {
					glm::mat4(),
					glm::mat4(),
					glm::mat4(),
					glm::mat4()
};

TheMatrix::TheMatrix() {
}

TheMatrix::TheMatrix(const TheMatrix& orig) {
}

TheMatrix::~TheMatrix() {
}

Matrices* TheMatrix::getPipeline() {
	  return &PipelineMatrices;
}

const glm::mat4 TheMatrix::getIdentityMatrix() {
	  return IdentityMatrix;
}

void TheMatrix::setPipeline(Matrices m) {
	  PipelineMatrices.M = m.M;
	  PipelineMatrices.MVP = m.MVP;
	  PipelineMatrices.P = m.P;
	  PipelineMatrices.V = m.V;
}