#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

#define PM ProgramManager::Instance()

struct ShaderProgram {
	GLuint vertexShader = 0;
	GLuint geometryShader = 0;
	GLuint fragmentShader = 0;
};

class ProgramManager
{
private:

	ProgramManager() = default;
	ProgramManager(ProgramManager&) = delete;
	ProgramManager& operator= (const ProgramManager&) = delete;

public:

	inline static ProgramManager& Instance()
	{
		static ProgramManager pm;
		return pm;
	}

	//Automatizar el projecto para los hijos de GameObject

	GLuint CreationOfProgram(std::string fragmentPath, std::string geometryPath, std::string vertexPath);


	//Funcion que devolvera una string con todo el archivo leido
	std::string Load_File(const std::string& filePath);

	GLuint LoadFragmentShader(const std::string& filePath);
	GLuint LoadGeometryShader(const std::string& filePath);
	GLuint LoadVertexShader(const std::string& filePath);

	GLuint CreateProgram(const ShaderProgram& shaders);

};

