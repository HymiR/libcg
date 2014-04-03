/*
 * timer.cpp
 *
 *  Created on: 21.05.2011
 *      Author: sam
 */


#include <oogl/glIncludes.hpp>
#include <oogl/timer.hpp>


namespace oogl
{
	/**
	 *
	 */
	timer::timer(const std::string& name)
		: cgutil::timer(name) {}


	/**
	 *
	 */
	void timer::start()
	{
		glFinish();
		cgutil::timer::start();
	}


	/**
	 *
	 */
	void timer::stop()
	{
		glFinish();
		cgutil::timer::stop();
	}
}
