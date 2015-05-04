/*
 * DisplayList.hpp
 *
 *  Created on: 10.02.2011
 *      Author: sam
 */


#ifndef DISPLAY_SIST_HPP
#define DISPLAY_LIST_HPP

#include "glIncludes.hpp"


namespace cg
{
	namespace oogl
	{
		/**
		 * @brief The DisplayList class
		 */
		class DisplayList
		{
		public:
			DisplayList();
			virtual ~DisplayList();

			void begin();
			void beginAndRender();
			void end();
			void render();


		private:
			GLuint id;
		};
	}
}

#endif // DISPLAY_LIST_HPP
