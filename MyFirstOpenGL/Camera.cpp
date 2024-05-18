#include "Camera.h"

Camera::Camera()
{
	position = glm::vec3(0.f, 0.f, -1.f);
}

void Camera::Update()
{

	position += moveCameraVector;
	
	fFov += addFFov;
	fNear += addFNear;
	fFar += addFFar;
}

