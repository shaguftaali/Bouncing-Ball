#pragma once
#include "Vector3.h"
#include "Matrix4.h"

class Transform
{

public:
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	void Translation(const Vector3& targetPosition);
	void Rotation(const Vector3& targetRotation);
	void Rotation(int axis, float angle);

	void Scale(const Vector3& _scale);

	Transform(const Vector3& a_position,const Vector3& a_rotation,const Vector3& a_scale);
	Transform(const Vector3& a_position, const Vector3& a_rotation);
	Transform(const Vector3& a_position);

private:
	Matrix4 modelMatrix;

	void SetModelMatrix();
};
