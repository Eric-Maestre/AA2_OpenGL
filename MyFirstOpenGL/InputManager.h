#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <GLFW/glfw3.h>

class InputManager
{
private:
	GLFWwindow* window;

	//ints ultima y actual tecla pulsada
	int keyPressed;
	int lastKeyPressed;

public:
	InputManager(GLFWwindow* window);
	int Update();

};

#endif
