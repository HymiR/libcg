/* 
 * File:   Renderable.cpp
 * Author: vidar
 * 
 * Created on 31. Mai 2014, 14:12
 */

#include "Renderable.h"

Renderable::Renderable() {
}

Renderable::Renderable(const Renderable& orig) {
}

Renderable::~Renderable() {
}

void Renderable::addCoordinates(std::vector<glm::vec3> vertices,
				std::vector<glm::vec2> uvs,
				std::vector<glm::vec3> normals)
{
	Coordinates coords;
	coords.vt = VertexArray(vertices);
	coords.uv = UVArray(uvs);
	coords.no = NormalArray(normals);
	  
	std::vector<unsigned short> indices;
	std::vector<glm::vec3> indexed_vertices;
	std::vector<glm::vec2> indexed_uvs;
	std::vector<glm::vec3> indexed_normals;
	  
	// index those coodinates
	indexVBO(vertices, uvs, normals, indices, indexed_vertices, indexed_uvs, indexed_normals);
	  
	coords.ivt = VertexArray(indexed_vertices);
	coords.iuv = UVArray(indexed_uvs);
	coords.ino = NormalArray(indexed_normals);
	coords.ind = indices;
	  
	// initialise VBO and load coordinates
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, indexed_vertices.size() * sizeof(glm::vec3), &indexed_vertices[0], GL_STATIC_DRAW);

	GLuint uvbuffer;
	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, indexed_uvs.size() * sizeof(glm::vec2), &indexed_uvs[0], GL_STATIC_DRAW);

	GLuint normalbuffer;
	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, indexed_normals.size() * sizeof(glm::vec3), &indexed_normals[0], GL_STATIC_DRAW);

	// Generate a buffer for the indices as well
	GLuint elementbuffer;
	glGenBuffers(1, &elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0] , GL_STATIC_DRAW);
	
	coords.vertexbuffer = vertexbuffer;
	coords.uvbuffer = uvbuffer;
	coords.normalbuffer = normalbuffer;
	coords.elementbuffer = elementbuffer;
	
	coordinates.push_back(coords);
}

void Renderable::addShader(std::string path_vs, std::string path_fs) {
	
	Shader shader;
	  
	//create program
	GLuint programID = glCreateProgram();

	//compile shaders
	GLuint vertexshader = oogl::loadShader(path_vs,GL_VERTEX_SHADER);
	GLuint fragmentshader = oogl::loadShader(path_fs,GL_FRAGMENT_SHADER);

	//attach shaders
	glAttachShader(programID, vertexshader);
	glAttachShader(programID, fragmentshader);

	//link program
	glLinkProgram(programID);
	
	shader.GLSLProgramHandle = programID;
	shader.MVPHandle = glGetUniformLocation(programID, "MVP");
	shader.MHandle = glGetUniformLocation(programID, "M");
	shader.VHandle = glGetUniformLocation(programID, "V");
	shader.vertexNormal_modelspaceHandle = glGetAttribLocation(programID, "vertexNormal_modelspace");
	shader.vertexPosition_modelspaceHandle = glGetAttribLocation(programID, "vertexPosition_modelspace");
	shader.vertexUVHandle = glGetAttribLocation(programID, "vertexUV");
	
	shaders.push_back(shader);
}

void Renderable::render() {
}
