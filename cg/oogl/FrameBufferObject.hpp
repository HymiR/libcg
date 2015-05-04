/*
 * FrameBufferObject.hpp
 *
 *  Created on: 12.07.2010
 *      Author: sam
 */


#ifndef FRAMEBUFFEROBJECT_HPP
#define FRAMEBUFFEROBJECT_HPP

#include <cg/oogl/glIncludes.hpp>
#include <cg/oogl/Texture2D.hpp>
#include <cg/util/log.hpp>

#include <vector>
#include <memory>


namespace cg
{
	namespace oogl
	{
		/**
		 * @brief The FrameBufferObject class
		 */
		class FrameBufferObject
		{
		public:
			static FrameBufferObject* create(
					glm::uvec2 dim,
					const unsigned textureCount = 1,
					const GLint textureFormat = GL_RGBA,
					const GLint depthFormat = -1);

			static FrameBufferObject* createDepthOnly(
					glm::uvec2 dim,
					const GLint depthFormat = GL_DEPTH_COMPONENT24);

			virtual ~FrameBufferObject();

			void begin(unsigned int target = 0);
			void beginAll();
			void end();

			Texture2D* getTexture(unsigned int target = 0) { return textures[target]; }
			Texture2D* getDepthTexture() { return depthTexture; }

		protected:
			FrameBufferObject(
					glm::uvec2 dim,
					const std::vector<Texture2D*>& textures,
					Texture2D* depthTexture);

		private:
			glm::uvec2 dim;
			std::vector<Texture2D*> textures;
			Texture2D* depthTexture;
			GLuint fb;

			void beginCommon();
			void checkError();
		};
	}
}

#endif // FRAMEBUFFEROBJECT_HPP
