#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stb_image.h>
#include "Mesh.h"
#include "GameObject.h"
#include "Camera.h"
#include "InputManager.h"
#include "ProgramManager.h"
#include "Model.h"

#define WINDOW_WIDTH_DEFAULT 640
#define WINDOW_HEIGHT_DEFAULT 480

int windowWidth = WINDOW_WIDTH_DEFAULT;
int windowHeight = WINDOW_HEIGHT_DEFAULT;

std::vector <Model> models;

void Resize_Window(GLFWwindow* window, int iFrameBufferWidth, int iFrameBufferHeight) {

	//Definir nuevo tamaño del viewport
	glViewport(0, 0, iFrameBufferWidth, iFrameBufferHeight);

	windowWidth = iFrameBufferWidth;
	windowHeight = iFrameBufferHeight;
}

void main() {

	//Crear camara
	Camera mainCamera;

	//Definir semillas del rand según el tiempo
	srand(static_cast<unsigned int>(time(NULL)));

	//Inicializamos GLFW para gestionar ventanas e inputs
	glfwInit();

	//Configuramos la ventana
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	//Inicializamos la ventana
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "My Engine", NULL, NULL);

	//Iniciar Input Manager
	IM.Init(window);

	//Asignamos función de callback para cuando el frame buffer es modificado
	glfwSetFramebufferSizeCallback(window, Resize_Window);

	//Definimos espacio de trabajo
	glfwMakeContextCurrent(window);

	//Permitimos a GLEW usar funcionalidades experimentales
	glewExperimental = GL_TRUE;

	//Activamos cull face
	glEnable(GL_CULL_FACE);

	//Indicamos lado del culling
	glCullFace(GL_BACK);

	//Leer textura troll
	int width, height, nrChannels;
	unsigned char* textureInfo = stbi_load("Assets/Textures/troll.png", &width, &height, &nrChannels, 0);
	//Leer textura piedra
	int widthRock, heightRock, nrChannelsRock;
	unsigned char* textureInfoRock = stbi_load("Assets/Textures/rock.png", &widthRock, &heightRock, &nrChannelsRock, 0);

	//Inicializamos GLEW y controlamos errores
	if (glewInit() == GLEW_OK) {

		//Compilar shaders
		mainCamera.Update(0.4);

		//shader primer troll, color normal
		models.push_back(Model("MyFirstFragmentShader.glsl" , "GeometryOfModels.glsl","MyFirstVertexShader.glsl" , "Assets/Models/troll.obj"));

		//shader segundo troll, color azul
		models.push_back(Model("BlueTrollFragmentShader.glsl", "GeometryOfModels.glsl", "MyFirstVertexShader.glsl", "Assets/Models/troll.obj"));

		//shader tercer troll, color verde
		models.push_back(Model("GreenTrollFragmentShader.glsl", "GeometryOfModels.glsl", "MyFirstVertexShader.glsl", "Assets/Models/troll.obj"));

		//shader roca normal
		models.push_back(Model("MyFirstFragmentShader.glsl", "GeometryOfModels.glsl","MyFirstVertexShader.glsl", "Assets/Models/rock.obj"));
		models.push_back(Model("MyFirstFragmentShader.glsl", "GeometryOfModels.glsl", "MyFirstVertexShader.glsl", "Assets/Models/rock.obj"));
		models.push_back(Model("MyFirstFragmentShader.glsl", "GeometryOfModels.glsl", "MyFirstVertexShader.glsl", "Assets/Models/rock.obj"));
		models.push_back(Model("MyFirstFragmentShader.glsl", "GeometryOfModels.glsl", "MyFirstVertexShader.glsl", "Assets/Models/rock.obj"));

		//sahder nube roca
		models.push_back(Model("WhiteCloudFragmentShader.glsl", "GeometryOfModels.glsl", "MyFirstVertexShader.glsl", "Assets/Models/rock.obj"));
		models.push_back(Model("WhiteCloudFragmentShader.glsl", "GeometryOfModels.glsl", "MyFirstVertexShader.glsl", "Assets/Models/rock.obj"));

		//Definimos canal de textura activo
		glActiveTexture(GL_TEXTURE0);

		//Genero textura
		GLuint textureID;
		glGenTextures(1, &textureID);

		//Vinculo textura con el canal de textura
		glBindTexture(GL_TEXTURE_2D, textureID);

		//Configurar textura
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//Cargar datos de la imagen a la textura
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureInfo);

		//Generar mipmaps
		glGenerateMipmap(GL_TEXTURE_2D);

		//Liberar recursos de memoria por la imagen cargada
		stbi_image_free(textureInfo);

		//Generar segunda textura roca
		GLuint textureID2;
		glGenTextures(1, &textureID2);

		//vincular textura al espacio 1
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, textureID2);

		//configurar textura
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//cargar datos de la imagen a la textura
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthRock, heightRock, 0, GL_RGB, GL_UNSIGNED_BYTE, textureInfoRock);

		//generar mipmaps
		glGenerateMipmap(GL_TEXTURE_2D);

		//liberar recursos
		stbi_image_free(textureInfoRock);

		//Definimos color para limpiar el buffer de color
		glClearColor(0.f, 0.f, 0.f, 1.f);

		//Definimos modo de dibujo para cada cara
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//Indicar a la tarjeta GPU que programa debe usar

		//Asignar valores iniciales al programa
		for (int i = 0; i < models.size(); i++)
		{
			glUseProgram(models[i].GetProgram());
			glUniform2f(glGetUniformLocation(models[i].GetProgram(), "windowSize"), windowWidth, windowHeight);

		}

		//Asignar valor variable textura a usar
		for (int i = 0; i < 3; i++)
		{
			glUseProgram(models[i].GetProgram());
			glUniform1i(glGetUniformLocation(models[i].GetProgram(), "textureSampler"), 0);
		}

		for (int i = 3; i < models.size(); i++)
		{
			glUseProgram(models[i].GetProgram());
			glUniform1i(glGetUniformLocation(models[i].GetProgram(), "textureSampler"), 1);
		}

		//matrices de transformacion de los modelos
		//primer troll, medio
		models[0].position = glm::vec3(0.f,0.f, 0.8f);
		models[0].rotation = glm::vec3(0.f, 180.f, 0.f);
		models[0].scale = glm::vec3(0.4f);

		//segundo troll, derecha
		models[1].position = glm::vec3(-1.f, 0.f, 0.2f);
		models[1].rotation = glm::vec3(0.f, 90.f, 0.f);
		models[1].scale = glm::vec3(0.4f);

		//tercer troll, izquierda
		models[2].position = glm::vec3(1.f, 0.f, 0.2f);
		models[2].rotation = glm::vec3(0.f, 270.f, 0.f);
		models[2].scale = glm::vec3(0.4f);

		//cambiar el eje de rotacion de los modelos
		for (int i = 3; i < models.size(); i++)
		{
			models[i].SetRotationAngleZ();
		}

		//primer piedra, delante primer troll
		models[3].position = glm::vec3(0.f, 0.f, 0.4f);
		models[3].rotation = glm::vec3(0.f, 0.f, 90.f);
		models[3].scale = glm::vec3(0.2f);

		//segunda piedra, piedra derecha
		models[4].position = glm::vec3(0.3f, 0.f, 0.2f);
		models[4].rotation = glm::vec3(0.f, 0.f, 90.f);
		models[4].scale = glm::vec3(0.2f);

		//tercera piedra, piedra izquierda
		models[5].position = glm::vec3(-0.3f, 0.f, 0.2f);
		models[5].rotation = glm::vec3(0.f, 0.f, 90.f);
		models[5].scale = glm::vec3(0.2f);

		//cuarta piedra, piedra delantera
		models[6].position = glm::vec3(0.f, 0.f, 0.f);
		models[6].rotation = glm::vec3(0.f, 0.f, 90.f);
		models[6].scale = glm::vec3(0.2f);

		//primera nube, izquierda
		models[7].position = glm::vec3(-0.6f, 0.8f, 1.f);
		models[7].rotation = glm::vec3(0.f, 0.f, 90.f);
		models[7].scale = glm::vec3(0.2f);

		//segunda nube, derecha
		models[8].position = glm::vec3(0.6f, 0.7f, 1.f);
		models[8].rotation = glm::vec3(0.f, 0.f, 90.f);
		models[8].scale = glm::vec3(0.2f);

		for (int i = 0; i < models.size(); i++)
			models[i].GenerateAllMatrixs();

		glm::mat4 viewMatrix;

		//Generamos el game loop
		while (!glfwWindowShouldClose(window)) {

			//Pulleamos los eventos (botones, teclas, mouse...)
			glfwPollEvents();

			//Input Manager Update
			IM.Update();

			//camara state
			mainCamera.Update(0.4);

			//depth test
			glEnable(GL_DEPTH_TEST);

			//Limpiamos los buffers
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

			//matrices de la camara
			if(mainCamera.stateOrbita)
			viewMatrix = glm::lookAt(mainCamera.position,mainCamera.center, mainCamera.localVectorUp);
			else if(mainCamera.stateGeneralThirdTroll)
			viewMatrix = glm::lookAt(mainCamera.position, models[2].position, mainCamera.localVectorUp);
			else if(mainCamera.stateDetalleSecondTroll)
			viewMatrix = glm::lookAt(mainCamera.position, models[1].position, mainCamera.localVectorUp);
			else if(mainCamera.stateDollyFirstTroll)
			viewMatrix = glm::lookAt(mainCamera.position, models[0].position, mainCamera.localVectorUp);




			glm::mat4 projectionMatrix = glm::perspective(glm::radians(mainCamera.fFov), (float)windowWidth/(float)windowHeight, mainCamera.fNear, mainCamera.fFar);

			//pasar Uniforms

			//todos los modelos les afecta por igual la camara
			for (int i = 0; i < models.size(); i++)
			{
				glUseProgram(models[i].GetProgram());
				glUniformMatrix4fv(glGetUniformLocation(models[i].GetProgram(), "viewMatrix"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
				glUniformMatrix4fv(glGetUniformLocation(models[i].GetProgram(), "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
				models[i].Update();
			}

			//Cambiamos buffers
			glFlush();
			glfwSwapBuffers(window);
		}

		//Desactivar y eliminar programa
		glUseProgram(0);
		glDeleteProgram(models[0].GetProgram());
		glDeleteProgram(models[1].GetProgram());
		glDeleteProgram(models[2].GetProgram());



	}
	else {
		std::cout << "Ha petao." << std::endl;
		glfwTerminate();
	}

	//Finalizamos GLFW
	glfwTerminate();

}