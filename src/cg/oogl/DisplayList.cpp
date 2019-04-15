/*
 * DisplayList.cpp
 *
 *  Created on: 10.02.2011
 *      Author: sam
 */


#include <cg/oogl/DisplayList.hpp>


namespace cg
{
    namespace oogl
    {
        /**
         * @brief DisplayList::DisplayList
         */
        DisplayList::DisplayList() { id = glGenLists(1); }


        /**
         * @brief DisplayList::~DisplayList
         */
        DisplayList::~DisplayList()
        {
            glDeleteLists(id, 1);
            id = 0;
        }


        /**
         * @brief DisplayList::begin
         */
        void DisplayList::begin() { glNewList(id, GL_COMPILE); }


        /**
         * @brief DisplayList::beginAndRender
         */
        void DisplayList::beginAndRender() { glNewList(id, GL_COMPILE_AND_EXECUTE); }


        /**
         * @brief DisplayList::end
         */
        void DisplayList::end() { glEndList(); }


        /**
         * @brief DisplayList::render
         */
        void DisplayList::render()
        {
            glPushMatrix();
            glCallList(id);
            glPopMatrix();
        }
    }
}
