#pragma once
#ifndef CAMERA_H
#define CAMERA_H	

#include "GameObject.h"
#include "InputManager.h"

class Camera : public GameObject
{
public:
	glm::vec3 localVectorUp = glm::vec3(0.f, 1.f, 0.f);

	float fFov = 90.f;
	float fNear = 0.1f;
	float fFar = 10.f;

	//vector para mover camera 
	glm::vec3  moveCameraVector = glm::vec3(0.f);

	//float para aumentar o disminuir fFoc, fNear y fFar
	float addFFov = 0.f;
	float addFNear = 0.f;
	float addFFar = 0.f;

	//varaibles para el movimiento orbital
	float angle = 0.f;
	float rotationSpeed = glm::radians(1.0f);
	float radius = 2.f;
	glm::vec3 center = glm::vec3(0.f);

	//angle se actualiza, posicion original por si me interesa que empiece siempre en el mismo sitio
	float originalAngle = angle;


	bool stateOrbita = true;
	bool stateGeneralThirdTroll = false;
	bool stateDetalleSecondTroll = false;
	bool stateDollyFirstTroll = false;


	Camera();
	void Update(float dt);
	void ChangeState();
};


#endif

