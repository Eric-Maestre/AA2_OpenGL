#pragma once
#ifndef CAMERA_H
#define CAMERA_H	

#include "GameObject.h"

class Camera : public GameObject
{
public:
	glm::vec3 localVectorUp = glm::vec3(0.f, 1.f, 0.f);

	float fFov = 45.f;
	float fNear = 0.1f;
	float fFar = 10.f;

	//vector para mover camera 
	glm::vec3  moveCameraVector = glm::vec3(0.f);

	//float para aumentar o disminuir fFoc, fNear y fFar
	float addFFov = 0.f;
	float addFNear = 0.f;
	float addFFar = 0.f;

	void Update();
};


#endif

