/*
 * FrameBufferObject.cpp
 *
 *  Created on: 12.07.2010
 *      Author: sam
 */


#include <cg/oogl/FrameBufferObject.hpp>
#include <cg/oogl/gl_error.hpp>

#include <cassert>
#include <stdexcept>


namespace cg
{
	namespace oogl
	{
		/**
		 * @brief FrameBufferObject::create
		 * @param dim
		 * @param textureCount
		 * @param textureFormat
		 * @param depthFormat
		 * @return
		 */
		FrameBufferObject* FrameBufferObject::create(
				glm::uvec2 dim,
				const unsigned textureCount,
				const GLint textureFormat,
				const GLint depthFormat)
		{
			assert(textureCount <= 16);
			std::vector<Texture2D*> textures;

			for(unsigned i = 0; i < textureCount; ++i)
				textures.push_back(Texture2D::createColor(dim, textureFormat));

			Texture2D* depthTexture = NULL;

			if(depthFormat > 0)
				depthTexture = Texture2D::createDepth(dim, depthFormat);

			return new FrameBufferObject(dim, textures, depthTexture);
		}


		/**
		 * @brief FrameBufferObject::createDepthOnly
		 * @param dim
		 * @param depthFormat
		 * @return
		 */
		FrameBufferObject* FrameBufferObject::createDepthOnly(glm::uvec2 dim, const GLint depthFormat)
		{
			return create(dim, 0, 0, depthFormat);
		}



		/**
		 * @brief FrameBufferObject::FrameBufferObject
		 * @param dim
		 * @param textures
		 * @param depthTexture
		 */
		FrameBufferObject::FrameBufferObject(glm::uvec2 dim, const std::vector<Texture2D*>& textures, Texture2D* depthTexture)
			: dim(dim)
			, textures(textures)
			, depthTexture(depthTexture)
		{
			LOG_INFO << "create fbo: " << dim.x << " " << dim.y << std::endl;
			glGenFramebuffers(1, &fb);
			glBindFramebuffer(GL_FRAMEBUFFER, fb);
			LOG_GL_ERRORS();
			LOG_DEBUG << "attach textures" << std::endl;

			// attach
			assert(textures.size() <= 15);

			for(unsigned i = 0; i < textures.size(); ++i) {
				Texture2D* tex = textures[i];
				assert(dim.x == tex->getWidth() && dim.y == tex->getHeight());
				LOG_DEBUG << "attach color texture " << i << std::endl;
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, tex->textureId, 0);
			}

			if(textures.size() <= 0) {
				// instruct openGL that we won't bind a color texture with the currently binded FBO
				glDrawBuffer(GL_NONE);
				glReadBuffer(GL_NONE);
			}

			if(depthTexture != NULL) {
				assert(dim.x == depthTexture->getWidth() && dim.y == depthTexture->getHeight());
				LOG_DEBUG << "attach depth texture" << std::endl;
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthTexture->textureId, 0);
			}

			LOG_DEBUG << "check errors" << std::endl;
			checkError();
			LOG_DEBUG << "checked errors" << std::endl;
			glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
			LOG_GL_ERRORS();
		}


		/**
		 * @brief FrameBufferObject::checkError
		 */
		void FrameBufferObject::checkError()
		{
			GLuint status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

			if(status == GL_FRAMEBUFFER_COMPLETE) {
				LOG_DEBUG << "no errors" << std::endl;
				return;
			}

			switch(status) {
			case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
				LOG_ERROR << "can't create fbo: "
							<< "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT" << std::flush << std::endl;
				throw std::runtime_error("GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT");
			case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
				LOG_ERROR << "can't create fbo: "
							<< "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT" << std::flush << std::endl;
				throw std::runtime_error("GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT");
			case GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT:
				LOG_ERROR << "can't create fbo: "
							<< "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS" << std::flush << std::endl;
				throw std::runtime_error("GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS");
			case GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT:
				LOG_ERROR << "can't create fbo: "
							<< "GL_FRAMEBUFFER_INCOMPLETE_FORMATS" << std::flush << std::endl;
				throw std::runtime_error("GL_FRAMEBUFFER_INCOMPLETE_FORMATS");
			case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
				LOG_ERROR << "can't create fbo: "
							<< "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER" << std::flush << std::endl;
				throw std::runtime_error("GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER");
			case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
				LOG_ERROR << "can't create fbo: "
							<< "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER" << std::flush << std::endl;
				throw std::runtime_error("GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER");
			case GL_FRAMEBUFFER_UNSUPPORTED:
				LOG_ERROR << "can't create fbo: "
							<< "GL_FRAMEBUFFER_UNSUPPORTED" << std::flush << std::endl;
				throw std::runtime_error("GL_FRAMEBUFFER_UNSUPPORTED");
			default:
				LOG_ERROR << "unknown fbo error: " << status << std::flush << std::endl;
				throw std::runtime_error("unknown framebuffer error");
			}
		}


		/**
		 * @brief FrameBufferObject::~FrameBufferObject
		 */
		FrameBufferObject::~FrameBufferObject()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);

			for(Texture2D* texture : textures)
				delete texture;

			textures.clear();

			if(depthTexture != NULL)
				delete depthTexture;

			if(fb)
				glDeleteFramebuffers(1, &fb);
		}


		/**
		 * @brief FrameBufferObject::beginCommon
		 */
		void FrameBufferObject::beginCommon()
		{
			glPushAttrib(GL_VIEWPORT_BIT | GL_COLOR_BUFFER_BIT | GL_PIXEL_MODE_BIT);
			glBindTexture(GL_TEXTURE_2D, GL_NONE);
			glBindFramebuffer(GL_FRAMEBUFFER, fb);
			glViewport(0, 0, dim.x, dim.y);
			LOG_GL_ERRORS();
		}


		/**
		 * @brief FrameBufferObject::begin
		 * @param target
		 */
		void FrameBufferObject::begin(unsigned int target)
		{
			beginCommon();

			if(target <= 0 || target >= textures.size()) {
				glDrawBuffer(GL_NONE);
				glReadBuffer(GL_NONE);
			} else {
				glDrawBuffer(GL_COLOR_ATTACHMENT0 + target);
				glReadBuffer(GL_COLOR_ATTACHMENT0 + target);
			}

			LOG_GL_ERRORS();
		}


		/**
		 * @brief FrameBufferObject::beginAll
		 */
		void FrameBufferObject::beginAll()
		{
			beginCommon();
			GLenum* buffer = new GLenum[textures.size()];

			for(unsigned i = 0; i < textures.size(); ++i)
				buffer[i] = GL_COLOR_ATTACHMENT0 + i;

			glDrawBuffers(textures.size(), buffer);
			delete[] buffer;
			LOG_GL_ERRORS();
		}


		/**
		 * @brief FrameBufferObject::end
		 */
		void FrameBufferObject::end()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, GL_NONE);
			glPopAttrib();
		}
	}
}
