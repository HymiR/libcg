/* 
 * File:   Renderable.cpp
 * Author: vidar
 * 
 * Created on 31. Mai 2014, 14:12
 */

#include "Renderable.h"

Renderable::Renderable() {
	  this->texture = NULL;
}

Renderable::Renderable(const Renderable& orig) {
}

Renderable::~Renderable() {
	  if(texture) {
		  delete texture;
	  }
}

void Renderable::addCoordinates(std::vector<glm::vec3> vertices,
				std::vector<glm::vec2> uvs,
				std::vector<glm::vec3> normals)
{
	Geometry geoms;
	geoms.vt = VertexArray(vertices);
	geoms.uv = UVArray(uvs);
	geoms.no = NormalArray(normals);
	  
	std::vector<unsigned short> indices;
	std::vector<glm::vec3> indexed_vertices;
	std::vector<glm::vec2> indexed_uvs;
	std::vector<glm::vec3> indexed_normals;
	  
	// index those coodinates
	indexVBO(vertices, uvs, normals, indices, indexed_vertices, indexed_uvs, indexed_normals);
	  
	geoms.ivt = VertexArray(indexed_vertices);
	geoms.iuv = UVArray(indexed_uvs);
	geoms.ino = NormalArray(indexed_normals);
	geoms.ind = indices;
	  
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
	
	geoms.vertexbuffer = vertexbuffer;
	geoms.uvbuffer = uvbuffer;
	geoms.normalbuffer = normalbuffer;
	geoms.elementbuffer = elementbuffer;
	// Think of something to make this modifyable
	geoms.InitialPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	
	geometries.push_back(geoms);
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

void Renderable::addLight(glm::vec3 position) {
	  Light light;
	  light.position = position;
	  // TODO: combine with shader
	  this->lights.push_back(light);
}

void Renderable::addTexture(std::string path_texture) {
	this->texture = oogl::loadTexture(path_texture);
}

void Renderable::render() {
	/**
	 * TODO:
	 * (Lichter setzen)
	 * Matrizen mit Shader verknüpfen
	 * Shader auswählen
	 * 
	 * (texturen aktivieren)
	 * textur mit shader verbinden
	 * aufräumen
         */
	  
	// For now we only use first geometric object and first shader
	// later we will use a little bit more sophisticated selection procedure
	// (vector.at(0))
	  
	// Use our shader
	glUseProgram(shaders.at(0).GLSLProgramHandle);
	
	// we do the lights later
	if(this->lights.size() > 0) {
		for(Light l : this->lights) {
			glUniform3f(l.LightHandle, l.position.x, l.position.y, l.position.z);
			glUniformMatrix4fv(shaders.at(0).VHandle, 1, GL_FALSE, &(Pipeline.getPipeline()->V[0][0]));	  
		}
	}
	
	
	// We just use the global View Matrix
	glUniformMatrix4fv(shaders.at(0).VHandle,
			   1,
			   GL_FALSE,
			   &(Pipeline.getPipeline()->V[0][0])
	);
		
	// We want to render this at its initial coordinates relative to (0,0,0)
	glm::mat4 ModelMatrix = glm::translate(Pipeline.getIdentityMatrix(),
					       geometries.at(0).InitialPosition
	);
		
	// We create a new MVP matrix for this object using global Perspective Matrix
	// and global View Matrix
	glm::mat4 MVP = Pipeline.getPipeline()->P * 
			Pipeline.getPipeline()->V *
			ModelMatrix;

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform of our currently loaded shader
	glUniformMatrix4fv(shaders.at(0).MVPHandle, 1, GL_FALSE, &MVP[0][0]);
	glUniformMatrix4fv(shaders.at(0).MHandle, 1, GL_FALSE, &ModelMatrix[0][0]);
	
	// We activate the texture of this object if we have one
	if(this->texture) {
		  this->texture->bind(0);
	}

	// Activate and configure the geometry we want to render
	// Vertices:
	glEnableVertexAttribArray(shaders.at(0).vertexPosition_modelspaceHandle);
	glBindBuffer(GL_ARRAY_BUFFER, geometries.at(0).vertexbuffer);
	glVertexAttribPointer(
		shaders.at(0).vertexPosition_modelspaceHandle, // The attribute we want to configure
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// UVs:
	glEnableVertexAttribArray(shaders.at(0).vertexUVHandle);
	glBindBuffer(GL_ARRAY_BUFFER, geometries.at(0).uvbuffer);
	glVertexAttribPointer(
		shaders.at(0).vertexUVHandle,     // The attribute we want to configure
		2,                                // size : U+V => 2
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	// Normals:
	glEnableVertexAttribArray(shaders.at(0).vertexNormal_modelspaceHandle);
	glBindBuffer(GL_ARRAY_BUFFER, geometries.at(0).normalbuffer);
	glVertexAttribPointer(
		shaders.at(0).vertexNormal_modelspaceHandle, // The attribute we want to configure
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	// Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometries.at(0).elementbuffer);

	// Draw the triangles !
	glDrawElements(
		GL_TRIANGLES,      // mode
		geometries.at(0).ind.size(),    // count
		GL_UNSIGNED_SHORT,   // type
		(void*)0           // element array buffer offset
	);
	
	if(this->texture){
		  this->texture->unbind();
		  glDisable(GL_TEXTURE_2D);
	}
	
}
