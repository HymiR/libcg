/*
 * Navigator.cpp
 *
 *  Created on: 26.04.2011
 *      Author: sam
 */


#include <oogl/Navigator.hpp>

#include <glm/gtx/transform.hpp>


namespace oogl
{
	/**
	 *
	 */
	Navigator::Navigator(glm::vec2 rotateFactor, float scaleFactor, glm::vec2 translateFactor) :
		buttonState(0),
		rotateFactor(rotateFactor),
		scaleFactor(scaleFactor),
		translateFactor(translateFactor) {}


	/**
	 *
	 */
	Navigator::~Navigator() {}


	/**
	 *
	 */
	void Navigator::mouse(int button, int state, int x, int y)
	{
		if (button == 0 && state == 0)
			buttonState |= LEFT_DOWN;
		else
			buttonState &= ~LEFT_DOWN;
		if (button == 2 && state == 0)
			buttonState |= RIGHT_DOWN;
		else
			buttonState &= ~RIGHT_DOWN;
		if (button == 1 && state == 0)
			buttonState |= MIDDLE_DOWN;
		else
			buttonState &= ~MIDDLE_DOWN;
		lastMouse = glm::ivec2(x, y);
	}


	/**
	 *
	 */
	void Navigator::mouseMotion(int x, int y)
	{
		glm::ivec2 mouse = glm::ivec2(x, y);
		glm::vec2 dmouse = glm::vec2(mouse - lastMouse);
		lastMouse = mouse;

		if (buttonState & LEFT_DOWN) {
			glm::vec3 v1(0.0f, 1.0f, 0.0f);
			glm::vec3 v2(1.0f, 0.0f, 0.0f);

			matrix = glm::rotate(dmouse.x * rotateFactor.x, v1)
				* glm::rotate(dmouse.y * rotateFactor.y, v2)
				* matrix;
		}

		if (buttonState & RIGHT_DOWN) {
			float m = 1 + (dmouse.x + dmouse.y) * scaleFactor;
			matrix = glm::scale(glm::vec3(m, m, m)) * matrix;
		}

		if (buttonState & MIDDLE_DOWN) {
			glm::vec3 vec(dmouse.x * translateFactor.x, dmouse.y * translateFactor.y, 0.0f);
			matrix = glm::translate(vec) * matrix;
		}
	}


	/**
	 *
	 */
	void Navigator::keyboard(unsigned char key, int x, int y)
	{
		switch (key) {
			case 'r':
				matrix = glm::mat4();
				break;
		}
	}
}
