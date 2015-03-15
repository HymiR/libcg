/*
 * glutIncludes.hpp
 *
 *  Created on: 10.02.2011
 *      Author: sam
 *
 *  @deprecated {
 *  	This file should not be used anymore.
 *  	We don't support GLUT anymore, because it's archaic and outdated.
 *  	GLFW is used instead.
 *  	This file is only kept as fallback and will be deleted soon.
 *  }
 */


#ifndef GLUT_INCLUDES_HPP
#define GLUT_INCLUDES_HPP

#include <GL/GLee.h>

#ifdef WIN32
# include <GL/glu.h>
# include <GL/glut.h>
#elif defined(__APPLE__) || defined(__APPLE_CC__)
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else
# include <GL/glu.h>
# include <GL/glut.h>
#endif

#endif // GLUT_INCLUDES_HPP
