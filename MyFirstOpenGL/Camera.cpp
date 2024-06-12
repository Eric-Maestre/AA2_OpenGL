#include "Camera.h"
#include <iostream>

Camera::Camera()
{
	position = glm::vec3(0.f, 1.f, -1.f);
	originalPos = position;
}

void Camera::Update(float dt)
{
	ChangeState();

	if (stateOrbita)
	{
		angle += rotationSpeed * dt;
		position.x = center.x + radius * cos(angle);
		position.z = center.z + radius * sin(angle);

		if (angle >= 360 + originalAngle)
			angle = originalAngle;
	}
	else if (stateGeneralThirdTroll)
	{
		//plano general picado
		position = glm::vec3(0.f, 0.8f, 0.f);
	}
	else if (stateDetalleSecondTroll)
	{
		//plano detalle del cuerno
		position = glm::vec3(-0.6f, 1.3f, 0.f);
	}

}

void Camera::ChangeState()
{
	int stateNumber = IM.GetKey();;

	if (stateNumber == 1+48)
	{
		std::cout << "state 1" << std::endl;
		stateOrbita = false;
		stateGeneralThirdTroll = true;
		stateDetalleSecondTroll = false;
		stateDollyFirstTroll = false;

		fFov = 90.f;
		fNear = 0.1f;
		fFar = 10.f;
	}
	if (stateNumber == 2+48)
	{
		std::cout << "state 2" << std::endl;
		stateOrbita = false;
		stateGeneralThirdTroll = false;
		stateDetalleSecondTroll = true;
		stateDollyFirstTroll = false;

		fFov = 30.f;
		fNear = 0.05f;
		fFar = 4.f;
	}
	if (stateNumber == 3+48)
	{
		std::cout << "state 3" << std::endl;
		stateOrbita = false;
		stateGeneralThirdTroll = false;
		stateDetalleSecondTroll = false;
		stateDollyFirstTroll = true;

		fFov = 90.f;
		fNear = 0.1f;
		fFar = 10.f;
	}

}

