/*
 * File:   Renderable.h
 * Author: vidar
 *
 * Created on 31. Mai 2014, 14:12
 */


#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "vboindexer.hpp"
#include "TheMatrix.hpp"

#include <cg/oogl/GLSLShader.hpp>
#include <cg/oogl/GLSLProgram.hpp>
#include <cg/oogl/Image.hpp>
#include <cg/oogl/Texture.hpp>

#include <glm/fwd.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>
#include <string>


typedef struct GEOMETRY
{
	std::vector<glm::vec2> uv, iuv; // original geometry and indexed geometry of UV ...
	std::vector<glm::vec3> no, ino; // ... Normals
	std::vector<glm::vec3> vt, ivt; // ... Vertices
	std::vector<unsigned short> ind;
	GLuint vertexbuffer;  // Handlers for the Vertex Buffer Objects: Vertices...
	GLuint uvbuffer;	  // ... UVs
	GLuint normalbuffer;  // ... Normals
	GLuint elementbuffer; // ... Indices
	GLuint ShaderID;
	glm::vec3 InitialPosition;
} Geometry;

typedef struct SHADER
{
	GLuint ShaderID;
	GLuint GLSLProgramHandle;
	GLuint MVPHandle;
	GLuint VHandle;
	GLuint MHandle;
	GLuint textureHandle;
	GLuint vertexPosition_modelspaceHandle;
	GLuint vertexUVHandle;
	GLuint vertexNormal_modelspaceHandle;
} Shader;

typedef struct MATERIAL
{
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat emission[4];
} Material;

typedef struct LIGHT
{
	glm::vec3 position;
	GLuint LightHandle;
} Light;

class Renderable
{
public:
	Renderable();
	Renderable(const Renderable& orig);
	virtual ~Renderable();
	virtual void render();
	void addGeometry(
			std::vector<glm::vec3> vertices,
			std::vector<glm::vec2> uvs,
			std::vector<glm::vec3> normals);

	void addShader(
			std::string path_vs,
			std::string path_fs,
			bool standard = false);

	void addTexture(std::string path_texture);

	void addLight(glm::vec3 position);

	void addMaterial(Material material);

	void addInitialPosition(uint geomnumber, glm::vec3 position);

protected:
	std::vector<Geometry> geometries;
	std::vector<Shader> shaders;
	std::vector<Light> lights;
	std::vector<oogl::Texture*> textures;
	static Shader standardShader;
	void loadVBO(Geometry& geometry);
};

#endif /* RENDERABLE_H */
