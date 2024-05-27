#include "InputManager.h"

InputManager::InputManager(GLFWwindow* window)
{
	this->window = window;
}

int InputManager::Update()
{
	lastKeyPressed = keyPressed;

	keyPressed = 0;

	//casos posibles
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
		keyPressed = GLFW_KEY_1;
	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
		keyPressed = GLFW_KEY_2;
	else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
		keyPressed = GLFW_KEY_3;

	//comprobar ultima tecla pulsada y actual
	//si la actual es 0 y la ultima es != 0, la tecla ha sido pulsada y soltada

	if (keyPressed == 0 && lastKeyPressed != 0)
	{
		return lastKeyPressed;
	}

	return 0;

}
