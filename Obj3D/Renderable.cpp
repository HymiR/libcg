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
  for(oogl::Texture* tex : textures) {
    delete tex;
  }
}

Shader Renderable::standardShader = {0,0,0,0,0,0,0,0};

void Renderable::addGeometry(std::vector<glm::vec3> vertices,
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

void Renderable::addInitialPosition(uint geomnumber, glm::vec3 position) {
	geometries.at(geomnumber).InitialPosition = position;
}

void Renderable::addShader(std::string path_vs,
			   std::string path_fs,
			   bool standard) {
	
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
	shader.textureHandle = glGetUniformLocation(programID, "myTextureSampler");
	shader.vertexNormal_modelspaceHandle = glGetAttribLocation(programID, "vertexNormal_modelspace");
	shader.vertexPosition_modelspaceHandle = glGetAttribLocation(programID, "vertexPosition_modelspace");
	shader.vertexUVHandle = glGetAttribLocation(programID, "vertexUV");
		
	if(standard) {
		standardShader = shader;  
	} else {
		shaders.push_back(shader);
	}
}

void Renderable::addMaterial(Material material) {
}

void Renderable::addLight(glm::vec3 position) {
	  Light light;
	  light.position = position;
	  // TODO: combine with shader
	  this->lights.push_back(light);
}

void Renderable::addTexture(std::string path_texture) {
	this->textures.push_back(oogl::loadTexture(path_texture));
}

void Renderable::render() {
	/**
	 * TODO:
	 * (Lichter setzen)
	 * Matrizen mit Shader verknüpfen
	 * think of a way to individually select:
	 *  -shaders
	 *  -textures
	 *  -geometries
	 * cleanup
         */
	  
	// For now we only use first geometric object and first shader
	// later we will use a little bit more sophisticated selection procedure
	// (vector.at(0))
	
	// Choose shader
	Shader* currentshader = NULL;
	if(shaders.size() > 0) {
		// Choose a special shader
		currentshader = &shaders.at(0);
	} else {
		currentshader = &standardShader;
	}
	  
	// Use our shader
	glUseProgram(currentshader->GLSLProgramHandle);
	
	// Choose geometry
	Geometry* currentgeometry = NULL;
	if(geometries.size() > 0) {
		// Choose our geometry
		currentgeometry = &geometries.at(0);
	} else {
		// TODO Think of what to do if we don't have geometry
	}
	
	// we do the lights later
	if(this->lights.size() > 0) {
		for(Light l : this->lights) {
			glUniform3f(l.LightHandle, l.position.x, l.position.y, l.position.z);
			glUniformMatrix4fv(currentshader->VHandle, 1, GL_FALSE, &(Pipeline.getPipeline()->V[0][0]));	  
		}
	}
	
	
	// We just use the global View Matrix
	glUniformMatrix4fv(currentshader->VHandle,
		1,
		GL_FALSE,
		&(Pipeline.getPipeline()->V[0][0])
	);
	
	// We want to render this at its initial coordinates relative to (0,0,0)
	glm::mat4 ModelMatrix = glm::translate(Pipeline.getIdentityMatrix(),
			        currentgeometry->InitialPosition);
		
	// We create a new MVP matrix for this object using global Perspective Matrix
	// and global View Matrix
	glm::mat4 MVP = Pipeline.getPipeline()->P * 
			Pipeline.getPipeline()->V *
			ModelMatrix;

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform of our currently loaded shader
	glUniformMatrix4fv(currentshader->MVPHandle, 1, GL_FALSE, &MVP[0][0]);
	glUniformMatrix4fv(currentshader->MHandle, 1, GL_FALSE, &ModelMatrix[0][0]);
	
	// Choose texture
	oogl::Texture* currenttexture = NULL;
	if(textures.size() > 0) {
	  currenttexture = textures.at(0);
	  // We use the texture of this object if we have one
	  currenttexture->bind();
	  glUniform1i(currentshader->textureHandle, currenttexture->getBindedTexture());
	}
	
	// Activate and configure the geometry we want to render
	// Vertices:
	glEnableVertexAttribArray(currentshader->vertexPosition_modelspaceHandle);
	glBindBuffer(GL_ARRAY_BUFFER, currentgeometry->vertexbuffer);
	glVertexAttribPointer(
		  currentshader->vertexPosition_modelspaceHandle, // The attribute we want to configure
		  3,                  // size
		  GL_FLOAT,           // type
		  GL_FALSE,           // normalized?
		  0,                  // stride
		  (void*)0            // array buffer offset
	);

	// UVs:
	glEnableVertexAttribArray(currentshader->vertexUVHandle);
	glBindBuffer(GL_ARRAY_BUFFER, currentgeometry->uvbuffer);
	glVertexAttribPointer(
		  currentshader->vertexUVHandle,     // The attribute we want to configure
		  2,                                // size : U+V => 2
		  GL_FLOAT,                         // type
		  GL_FALSE,                         // normalized?
		  0,                                // stride
		  (void*)0                          // array buffer offset
	);

	// Normals:
	glEnableVertexAttribArray(currentshader->vertexNormal_modelspaceHandle);
	glBindBuffer(GL_ARRAY_BUFFER, currentgeometry->normalbuffer);
	glVertexAttribPointer(
		  currentshader->vertexNormal_modelspaceHandle, // The attribute we want to configure
		  3,                                // size
		  GL_FLOAT,                         // type
		  GL_FALSE,                         // normalized?
		  0,                                // stride
		  (void*)0                          // array buffer offset
	);

	// Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, currentgeometry->elementbuffer);

	// Draw the triangles !
	glDrawElements(
		  GL_TRIANGLES,      // mode
		  currentgeometry->ind.size(),    // count
		  GL_UNSIGNED_SHORT,   // type
		  (void*)0           // element array buffer offset
	);
	
	glDisableVertexAttribArray(currentshader->vertexPosition_modelspaceHandle);
	glDisableVertexAttribArray(currentshader->vertexUVHandle);
	glDisableVertexAttribArray(currentshader->vertexNormal_modelspaceHandle);
	
	if(currenttexture){
		    currenttexture->unbind();
		    glDisable(GL_TEXTURE_2D);
	}
}
