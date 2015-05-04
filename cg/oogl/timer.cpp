/*
 * timer.cpp
 *
 *  Created on: 21.05.2011
 *      Author: sam
 */


#include <cg/oogl/glIncludes.hpp>
#include <cg/oogl/timer.hpp>


namespace cg
{
	namespace oogl
	{
		/**
		 *
		 */
		timer::timer(const std::string& name)
			: util::timer(name)
		{
		}


		/**
		 *
		 */
		void timer::start()
		{
			glFinish();
			util::timer::start();
		}


		/**
		 *
		 */
		void timer::stop()
		{
			glFinish();
			util::timer::stop();
		}
	}
}
