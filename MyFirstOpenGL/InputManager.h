#pragma once

#include <GLFW/glfw3.h>

#define IM InputManager::Instance()

class InputManager
{
private:
	GLFWwindow* window;

	//ints ultima y actual tecla pulsada
	int key;
	int keyPressed;
	int lastKeyPressed;

	InputManager() = default;
	InputManager(InputManager&) = delete;
	InputManager& operator= (const InputManager&) = delete;


public:

	inline static InputManager& Instance()
	{
		static InputManager im;
		return im;
	}

	void Init(GLFWwindow* window);
	void Update();

	//getter de la key para la camara
	int GetKey() { return key; }

	//setter de la key por si acaso
	void SetKey(int a) { key = a; }

};

