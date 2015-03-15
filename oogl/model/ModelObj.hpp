/*
 * ModelObj.hpp
 *
 *  Created on: 26.03.2011
 *      Author: sam
 */


#ifndef MODEL_OBJ_HPP
#define MODEL_OBJ_HPP

#include <glm.h> // this is the glm-obj library for loading models, not the glm math stuff

#include <oogl/Model.hpp>
#include <oogl/DisplayList.hpp>


namespace oogl
{
	namespace model
	{
		/**
		 *
		 */
		class ModelObj : public Model
		{
			public:
				ModelObj(std::string fileName, Model::LoadOptions options);
				virtual ~ModelObj();

				virtual void render(RenderOptions options = 0);


			private:
				GLMmodel* model;
				oogl::DisplayList *displayList;

				void loadFile();
				void dump();
		};
	}
}


#endif // MODEL_OBJ_HPP

