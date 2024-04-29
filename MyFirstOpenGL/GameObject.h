#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <glm.hpp>

class GameObject
{
protected:
	glm::vec3 position = glm::vec3(0.f);
	glm::vec3 rotation = glm::vec3(0.f);
	glm::vec3 scale = glm::vec3(1.f);

	glm::vec3 forward = glm::vec3(0.f);
	glm::vec3 forwardRotation = glm::vec3(0.f);
	float velocity = 0.0005f;
	float angularVelocity = -.05f;

	void Update();
};



#endif
