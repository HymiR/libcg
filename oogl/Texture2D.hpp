/*
 * Texture2D.hpp
 *
 *  Created on: 26.05.2011
 *      Author: sam
 */


#include <oogl/Texture.hpp>
#include <oogl/Image.hpp>


#ifndef TEXTURE_2D_HPP
#define TEXTURE_2D_HPP


namespace oogl
{
	/**
	 *
	 */
	class Texture2D: public Texture
	{
		public:
			static Texture2D* load(Image *image);
			static Texture2D* createDepth(const glm::uvec2& dim, const GLint format);
			static Texture2D* createColor(const glm::uvec2& dim, const GLint format);
			static Texture2D* createContainer(const GLint format);
			virtual ~Texture2D();

			glm::uint getWidth() {return dim.x;}

			glm::uint getHeight() {return dim.y;}

			glm::uvec2 getDimensions() {return dim;}

			void setSize(const glm::uint& width, const glm::uint& height);
			void render();

		protected:
			Texture2D(const std::string& name, const glm::uvec2& dim, const GLuint textureId, GLint format);

		private:
			glm::uvec2 dim;
	};
}


#endif // TEXTURE_2D_HPP
