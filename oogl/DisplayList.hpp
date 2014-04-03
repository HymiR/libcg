/*
 * DisplayList.hpp
 *
 *  Created on: 10.02.2011
 *      Author: sam
 */

#pragma once

#include <oogl/glIncludes.hpp>


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

