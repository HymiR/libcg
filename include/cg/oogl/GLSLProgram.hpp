/*
 * GLSLProgram.hpp
 *
 *  Created on: 12.07.2010
 *      Author: sam
 */


#ifndef GLSL_PROGRAM_HPP
#define GLSL_PROGRAM_HPP

#include <cg/oogl/glIncludes.hpp>

#include <glm/fwd.hpp>

#include <vector>
#include <map>
#include <memory>


namespace cg
{
    namespace oogl
    {
        class Texture;
        class GLSLShader;

        class GLSLAttrib
        {
        public:
            GLSLAttrib(const std::string name, const GLint id);

            operator bool();

            GLSLAttrib& operator=(const int value);
            GLSLAttrib& operator=(const glm::ivec2 value);
            GLSLAttrib& operator=(const glm::ivec3 value);
            GLSLAttrib& operator=(const glm::ivec4 value);

            GLSLAttrib& operator=(const glm::uint value);
            GLSLAttrib& operator=(const glm::uvec2 value);
            GLSLAttrib& operator=(const glm::uvec3 value);
            GLSLAttrib& operator=(const glm::uvec4 value);

            GLSLAttrib& operator=(const float value);
            GLSLAttrib& operator=(const glm::vec2 value);
            GLSLAttrib& operator=(const glm::vec3 value);
            GLSLAttrib& operator=(const glm::vec4 value);

            GLSLAttrib& operator=(const bool value);
            GLSLAttrib& operator=(const glm::bvec2 value);
            GLSLAttrib& operator=(const glm::bvec3 value);
            GLSLAttrib& operator=(const glm::bvec4 value);

            GLSLAttrib& operator=(const glm::mat2 value);
            GLSLAttrib& operator=(const glm::mat3 value);
            GLSLAttrib& operator=(const glm::mat4 value);

            GLSLAttrib& operator=(Texture* value);

            void set(const int value);
            void set(const glm::ivec2 value);
            void set(const glm::ivec3 value);
            void set(const glm::ivec4 value);

            void set(const glm::uint value);
            void set(const glm::uvec2 value);
            void set(const glm::uvec3 value);
            void set(const glm::uvec4 value);

            void set(const float value);
            void set(const glm::vec2 value);
            void set(const glm::vec3 value);
            void set(const glm::vec4 value);

            void set(const bool value);
            void set(const glm::bvec2 value);
            void set(const glm::bvec3 value);
            void set(const glm::bvec4 value);

            void set(const glm::mat2 value);
            void set(const glm::mat3 value);
            void set(const glm::mat4 value);

            void set(Texture* value);

        private:
            GLint id;
            std::string name;
        };


        class GLSLProgram
        {
        public:
            GLSLProgram(std::vector<GLSLShader*> shaders);
            virtual ~GLSLProgram();

            void bind() const;
            void unbind() const;

            GLuint getId() const { return prog; }

            inline GLSLAttrib uniform(const std::string& arg) { return (*this)[arg]; }

            GLSLAttrib operator[](const std::string& arg);

            static std::string getInfoLog(GLuint programId);
            static GLSLProgram* create(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
            static GLSLProgram* createFromSource(const std::string& vertexShader, const std::string& fragmentShader);
            static GLSLProgram* create(const std::string& vertexShaderFile, const std::string& geometryShaderFile, const std::string& fragmentShaderFile);

        private:
            GLuint prog;
            typedef std::vector<GLSLShader*> GLSLShaders;
            GLSLShaders shaders;
            std::map<const std::string, GLint> locationCache;

            void create();
            void link();
        };
    }
}


#endif // GLSL_PROGRAM_HPP
