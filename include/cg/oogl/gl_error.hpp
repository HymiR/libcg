/*
 * gl_error.hpp
 *
 *  Created on: 10.02.2011
 *      Author: sam
 */


#ifndef GL_ERROR_HPP
#define GL_ERROR_HPP

#include <cg/util/log.hpp>
#include <cg/oogl/glIncludes.hpp>


#define LOG_GL_ERRORS()                                                          \
    {                                                                            \
        for(GLenum err = glGetError(); err != GL_NO_ERROR; err = glGetError()) { \
            LOG_ERROR << "GL_ERROR: " << gluErrorString(err) << std::endl;       \
        }                                                                        \
    }

namespace cg
{
    namespace oogl
    {
        void dumpGLInfos();
    }
}


#endif // GL_ERROR_HPP
