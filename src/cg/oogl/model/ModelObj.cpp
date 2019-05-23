/*
 * ModelObj.cpp
 *
 *  Created on: 26.03.2011
 *      Author: sam
 */

#include <cg/oogl/model/ModelObj.hpp>
#include <cg/oogl/DisplayList.hpp>
#include <cg/oogl/gl_error.hpp>
#include <cg/io/glm_ostream.hpp>
#include <cg/util/log.hpp>

#include <glm.h> // this is the glm-obj library for loading models, not the glm math stuff
#include <stdexcept>


namespace cg
{
    namespace oogl
    {
        namespace model
        {
            /**
             * @brief ModelObj::ModelObj
             * @param fileName
             * @param options
             */
            ModelObj::ModelObj(std::string fileName, Model::LoadOptions options)
                : Model(fileName, options)
                , displayList(nullptr)
            {
                loadFile();
            }


            /**
             * @brief ModelObj::~ModelObj
             */
            ModelObj::~ModelObj()
            {
                LOG_DEBUG << "free model " << fileName << std::endl;

                if(model)
                    glmDelete(model);

                delete displayList;
            }


            /**
             * @brief ModelObj::loadFile
             */
            void ModelObj::loadFile()
            {
                LOG_DEBUG << "load obj file " << fileName << std::endl;
                model = glmReadOBJ(fileName.c_str());

                if(!model) {
                    LOG_ERROR << "invalid model " << fileName << std::endl;
                    // TODO remove that! Use valid flag instead and bool() operator.
                    throw std::runtime_error("invalid model: " + fileName);
                }

                if(!(loadOptions & LOAD_NO_NORMALIZATION))
                    glmUnitize(model);

                GLfloat dim[3];
                glmDimensions(model, dim);
                glmVertexNormals(model, 90.0, GL_TRUE);

                boundingBox.min = glm::vec3(dim[0] * -0.5f, dim[1] * -0.5f, dim[2] * -0.5f);
                boundingBox.max = glm::vec3(dim[0] * 0.5f, dim[1] * 0.5f, dim[2] * 0.5f);
                dump();
                LOG_DEBUG << "loaded obj file " << fileName << std::endl;
            }


            /**
             * @brief ModelObj::render
             * @param options
             */
            void ModelObj::render(RenderOptions options)
            {
                LOG_DEBUG << "render obj file " << fileName << std::endl;
                //backup set attributes
                glPushAttrib(GL_ENABLE_BIT | GL_LIGHTING_BIT | GL_POLYGON_BIT | GL_TEXTURE_BIT);

                if(!(options & RENDER_NO_CULL_FACE)) {
                    glEnable(GL_CULL_FACE);
                    glCullFace(GL_BACK);
                }


                /**
                 * @brief glmMode - a bitwise OR of values describing what is to be rendered.
                 *             GLM_NONE     -  render with only vertices
                 *             GLM_FLAT     -  render with facet normals
                 *             GLM_SMOOTH   -  render with vertex normals
                 *             GLM_TEXTURE  -  render with texture coords
                 *             GLM_COLOR    -  render with colors (color material)
                 *             GLM_MATERIAL -  render with materials
                 */
                GLuint glmMode = 0;
                GLint shadeModel;
                glGetIntegerv(GL_SHADE_MODEL, &shadeModel);
                glmMode = glmMode | (shadeModel == GL_SMOOTH ? GLM_SMOOTH : GLM_FLAT);

                if(!(options & RENDER_NO_MATERIALS)) {
                    glmMode = glmMode | GLM_MATERIAL;

                    if(!(options & RENDER_NO_TEXTURES))
                        glmMode = glmMode | GLM_TEXTURE;
                }

                if(options & RENDER_NO_DISLAYLIST) {
                    LOG_DEBUG << "call glm to render model directly" << std::endl;
                    glPushMatrix();
                    glmDraw(model, glmMode);
                    glPopMatrix();
                } else if(displayList == nullptr) {
                    displayList = new oogl::DisplayList();
                    displayList->beginAndRender();
                    {
                        glPushMatrix();
                        LOG_DEBUG << "call glm to render model" << std::endl;
                        glmDraw(model, glmMode);
                        LOG_DEBUG << "called glm to render model" << std::endl;
                        glPopMatrix();
                    }
                    displayList->end();
                } else {
                    LOG_DEBUG << "call glm via displaylist" << std::endl;
                    displayList->render();
                }

                LOG_GL_ERRORS()
                glPopAttrib();
            }



            /**
             * @brief ModelObj::dump
             */
            void ModelObj::dump()
            {
                if(!LOG_IS_DEBUG_ENABLED)
                    return;

                BoundingSphere bs = getBoundingSphere();
                LOG_DEBUG << fileName << std::endl
                            << "\t"
                            << "name: " << model->pathname << std::endl
                            << "\t"
                            << "mtlib: " << model->mtllibname << std::endl
                            << "\t"
                            << "boundingBox: " << boundingBox.min << " - " << boundingBox.max << std::endl
                            << "\t"
                            << "boundingSphere: " << bs.center << " - " << bs.radius << std::endl
                            << "\t"
                            << "num materials: " << model->nummaterials << std::endl
                            << "\t"
                            << "num groups: " << model->numgroups << std::endl;
            }
        }
    }
}
