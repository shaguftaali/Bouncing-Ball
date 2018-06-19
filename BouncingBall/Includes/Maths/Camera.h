#pragma once
#include "Matrix4.h"
#include "Transform.h"

class Camera
{
public:
	Vector3 position;
	Vector3 eyeDirection;
	Vector3 up;
	Vector3 right;
	float far;
	float near;
	float FOV;
	Camera(const Vector3& a_position,const Vector3& a_target,float a_far, float a_near,float a_FOV);

	Matrix4 projectionMatrix;
	Matrix4 viewMatrix;

private:

	void SetViewMatrix();
	void SetProjectionMatrix();

};
