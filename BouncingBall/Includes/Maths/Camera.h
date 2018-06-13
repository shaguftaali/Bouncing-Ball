#pragma once
#include "Matrix4.h"
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
	Camera(const Vector3& a_position,const Vector3& a_eyeDirection,const Vector3& a_up,float a_far, float a_near,float a_FOV);

private:
	Matrix4 viewMatrix;
	Matrix4 projectionMatrix;

	void SetViewMatrix();
	void SetProjectionMatrix();

};