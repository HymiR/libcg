/*
 * glfwIncludes.hpp
 *
 *  Created on: 01.04.2014
 *      Author: Armin Leghissa
 */


#include <GL/GLee.h>


#ifndef GLFW_INCLUDES_HPP
#define GLFW_INCLUDES_HPP


#define GLFW_INCLUDE_GLU

#ifdef WIN32
# define GLFW_DLL
# include <GLFW/glfw3.h>
#elif defined(__APPLE__) || defined(__APPLE_CC__)
# include <GLFW/glfw3.h>
#else
# include <GLFW/glfw3.h>
#endif

#endif // GLFW_INCLUDES_HPP
