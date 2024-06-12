#include "Camera.h"
#include <iostream>

Camera::Camera()
{
	position = glm::vec3(0.f, 1.f, -1.f);
}

void Camera::Update(float dt)
{
	ChangeState();

	if (stateOrbita)
	{
		angle += rotationSpeed * dt;
		position.x = center.x + radius * cos(angle);
		position.z = center.z + radius * sin(angle);
		std::cout << radius << std::endl;

		if (angle >= 360 + originalAngle)
			angle = originalAngle;
	}
}

void Camera::ChangeState()
{
	int stateNumber = IM.GetKey();;

	if (stateNumber == 1+48)
	{
		std::cout << "state 1" << std::endl;
		bool stateOrbita = false;
		bool stateGeneralThirdTroll = true;
		bool stateDetalleSecondTroll = false;
		bool stateDollyFirstTroll = false;
	}
	if (stateNumber == 2+48)
	{
		std::cout << "state 2" << std::endl;
		bool stateOrbita = false;
		bool stateGeneralThirdTroll = false;
		bool stateDetalleSecondTroll = true;
		bool stateDollyFirstTroll = false;
	}
	if (stateNumber == 3+48)
	{
		std::cout << "state 3" << std::endl;
		bool stateOrbita = false;
		bool stateGeneralThirdTroll = false;
		bool stateDetalleSecondTroll = false;
		bool stateDollyFirstTroll = true;
	}

}

