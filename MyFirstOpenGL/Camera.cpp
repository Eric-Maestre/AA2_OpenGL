#include "Camera.h"

void Camera::Update()
{

	position += moveCameraVector;
	
	fFov += addFFov;
	fNear += addFNear;
	fFar += addFFar;
}

glm::vec3 Camera::GetPosition()
{
	return position;
}

glm::vec3 Camera::GetLocalVectorUp()
{
	return localVectorUp;
}

float Camera::getFFov()
{
	return fFov;
}

float Camera::getFNEar()
{
	return fNear;
}

float Camera::GetFFar()
{
	return fFar;
}
