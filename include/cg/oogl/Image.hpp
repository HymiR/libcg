/*
 * Image.hpp
 *
 *  Created on: 31.03.2011
 *      Author: sam
 */


#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cg/oogl/glIncludes.hpp>

#include <glm/fwd.hpp>

#include <string>


namespace cg
{
    namespace oogl
    {
        class Image
        {
        public:
            virtual ~Image();

            static Image* load(const std::string& fileName);

            glm::uint getWidth();
            glm::uint getHeight();
            glm::uint getDepth();

            int getFormat();
            int getType();
            int getBytesPerPixel();

            glm::uvec3 getDimensions();
            std::string getName();

            unsigned char* getData();

        protected:
            std::string fileName;
            unsigned int img;

            Image(const std::string& fileName, unsigned int img);

            static void initDevIL();
        };

        Image* loadImage(const std::string& fileName);
    }
}


#endif // IMAGE_HPP
