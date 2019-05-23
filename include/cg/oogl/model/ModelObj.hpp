/*
 * ModelObj.hpp
 *
 *  Created on: 26.03.2011
 *      Author: sam
 */


#ifndef MODEL_OBJ_HPP
#define MODEL_OBJ_HPP

#include <cg/oogl/Model.hpp>


typedef struct _GLMmodel GLMmodel;

namespace cg
{
    namespace oogl
    {
        class DisplayList;

        namespace model
        {
            /**
             * @brief The ModelObj class
             */
            class ModelObj : public Model
            {
            public:
                ModelObj(std::string fileName, Model::LoadOptions options);
                virtual ~ModelObj();

                virtual void render(RenderOptions options = 0);


            private:
                GLMmodel* model;
                oogl::DisplayList* displayList;

                void loadFile();
                void dump();
            };
        }
    }
}


#endif // MODEL_OBJ_HPP
