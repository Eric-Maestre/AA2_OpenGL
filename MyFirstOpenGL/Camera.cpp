#include "Camera.h"

void Camera::Update()
{

	position += moveCameraVector;
	
	fFov += addFFov;
	fNear += addFNear;
	fFar += addFFar;
}

