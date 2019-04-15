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
         * @brief timer::timer
         * @param name
         */
        timer::timer(const std::string& name)
            : util::timer(name)
        {
        }


        /**
         * @brief timer::start
         */
        void timer::start()
        {
            glFinish();
            util::timer::start();
        }


        /**
         * @brief timer::stop
         */
        void timer::stop()
        {
            glFinish();
            util::timer::stop();
        }
    }
}
