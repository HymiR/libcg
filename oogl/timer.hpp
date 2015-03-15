/*
 * timer.hpp
 *
 *  Created on: 21.05.2011
 *      Author: sam
 */


#ifndef OOGL_TIMER_HPP
#define OOGL_TIMER_HPP

#include <string>
#include <cgutil/timer.hpp>


namespace oogl
{
	class timer: cgutil::timer
	{
		public:
			timer(const std::string& name);

		protected:
			virtual void start();
			virtual void stop();
	};
}


#endif // OOGL_TIMER_HPP

