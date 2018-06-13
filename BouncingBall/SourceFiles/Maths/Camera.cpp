#include "..\..\Includes\Maths\Camera.h"
#include <cmath>
#define PI 3.14159

Camera::Camera(const Vector3& a_position, const Vector3& a_eyeDirection, const Vector3& a_up, float a_far, float a_near, float a_FOV) :
position(a_position),
eyeDirection(a_eyeDirection),
up(a_up),
far(a_far),
near(a_near),
FOV(a_FOV)
{
	right=Vector3::CrossProduct(a_eyeDirection,a_up);

}

void Camera::SetViewMatrix()
{
	
	viewMatrix = Matrix4(
		Vector4(right.x,up.x,eyeDirection.x,position.x),
		Vector4(right.y, up.y, eyeDirection.y, position.y),
		Vector4(right.z, up.z, eyeDirection.z, position.z),
		Vector4(0, 0, 0, 1)
	);
}

void Camera::SetProjectionMatrix()
{
	const float radians = (FOV/2) * 180 / PI;
	float A=(far+near)/(far-near);
	float B=(2*far*near)/(far-near);
	projectionMatrix = Matrix4(
		Vector4(1/tanf(radians),0,0,0),
		Vector4(0,1/tanf(radians),0,0),
		Vector4(0,0,A,-1),
		Vector4(0,0,B,0)
	);
}
