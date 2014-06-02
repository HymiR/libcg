/* 
 * File:   Renderable.h
 * Author: vidar
 *
 * Created on 31. Mai 2014, 14:12
 */

#ifndef RENDERABLE_H
#define	RENDERABLE_H
#include <vector>
#include <string>
#include <oogl/GLSLShader.hpp>
#include <oogl/GLSLProgram.hpp>
#include "vboindexer.hpp"
#include "UVArray.h"
#include "NormalArray.h"
#include "VertexArray.h"

typedef struct COORDINATES {
	UVArray uv, iuv; // original geometry and indexed geometry of UV ...
	NormalArray no, ino; // ... Normals
	VertexArray vt, ivt; // ... Vertices
	std::vector<unsigned short> ind;
	GLuint vertexbuffer; // Handlers for the Vertex Buffer Objects: Vertices...
	GLuint uvbuffer; // ... UVs
	GLuint normalbuffer; // ... Normals
	GLuint elementbuffer; // ... Indices
}Coordinates;

typedef struct SHADER {
	  GLuint ShaderID;
	  GLuint GLSLProgramHandle;
	  GLuint MVPHandle;
	  GLuint VHandle;
	  GLuint MHandle;
	  GLuint vertexPosition_modelspaceHandle;
	  GLuint vertexUVHandle;
	  GLuint vertexNormal_modelspaceHandle;
}Shader;

// TODO: überlegen wo Kopien und wo Referenzen sinnvoll wären
typedef struct MATRICES {
	  glm::mat4 MVP;
	  glm::mat4 M;
	  glm::mat4 V;
	  glm::mat4 P;
}Matrices;

class Renderable {
	  public:
		    Renderable();
		    Renderable(const Renderable& orig);
		    virtual ~Renderable();
		    virtual void render();
		    void addCoordinates(std::vector<glm::vec3> vertices, 
					std::vector<glm::vec2> uvs,
					std::vector<glm::vec3> normals);
		    void addShader(std::string path_vs, std::string path_fs);
		    
	  protected:
		    std::vector<Coordinates> coordinates;
		    std::vector<Shader> shaders;
};

#endif	/* RENDERABLE_H */

