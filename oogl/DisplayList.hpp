/*
 * DisplayList.hpp
 *
 *  Created on: 10.02.2011
 *      Author: sam
 */


#include <oogl/glIncludes.hpp>


#ifndef DISPLAY_SIST_HPP
#define DISPLAY_LIST_HPP


namespace oogl
{
	/**
	 *
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

#endif // DISPLAY_LIST_HPP
