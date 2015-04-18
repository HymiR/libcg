/*
 * timer.hpp
 *
 *  Created on: 10.07.2010
 *      Author: sam
 */


#ifndef TIMER_HPP
#define TIMER_HPP

#include <string>


struct timer_;

namespace cgutil
{
	class timer
	{
	public:
		timer(const std::string& name);
		~timer();

	protected:
		virtual void start();
		virtual void stop();

	private:
		std::string name;
		timer_* impl_;
	};
}

#endif // TIMER_HPP
