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
#include <oogl/Image.hpp>
#include <oogl/Texture.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "vboindexer.hpp"
#include "UVArray.h"
#include "NormalArray.h"
#include "VertexArray.h"
#include "TheMatrix.h"

typedef struct GEOMETRY {
	UVArray uv, iuv; // original geometry and indexed geometry of UV ...
	NormalArray no, ino; // ... Normals
	VertexArray vt, ivt; // ... Vertices
	std::vector<unsigned short> ind;
	GLuint vertexbuffer; // Handlers for the Vertex Buffer Objects: Vertices...
	GLuint uvbuffer; // ... UVs
	GLuint normalbuffer; // ... Normals
	GLuint elementbuffer; // ... Indices
	GLuint ShaderID;
	glm::vec3 InitialPosition;
}Geometry;

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

typedef struct MATERIAL {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat emission[4];
}Material;

typedef struct LIGHT {
	glm::vec3 position;
	GLuint LightHandle;
}Light;

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
		    
		    void addTexture(std::string path_texture);
		    
		    void addLight(glm::vec3 position);
		    
		    void addInitialPosition(uint geomnumber, glm::vec3 position);
		    
		    
	  protected:
		    std::vector<Geometry> geometries;
		    std::vector<Shader> shaders;
		    std::vector<Light> lights;
		    std::vector<oogl::Texture*>textures;
};

#endif	/* RENDERABLE_H */

