#include "..\..\Includes\Maths\Transform.h"
#include <cmath>
#define PI 3.14159

void Transform::Translation(const Vector3 & targetPosition)
{
	const Matrix4 mat4 = Matrix4(
		Vector4(1,0,0,1),
		Vector4(0,1,0,1),
		Vector4(0,0,1,1),
		Vector4(0,0,0,1)
	);

	Vector4 vec4=mat4*Vector4(targetPosition.x,targetPosition.y,targetPosition.z,1);
	position=Vector3(vec4.x,vec4.y,vec4.z);

}

void Transform::Rotation(const Vector3 & Rotation)
{
	

}

void Transform::Rotation(int axis, float angle)
{
	Matrix4 mat4;
	Vector4 vec4;
	const float radians=angle*180/PI;
	switch (axis)
	{
	case 0:
	default:
		//X axis

		mat4=Matrix4(
		
			Vector4(1,0,0,0),
			Vector4(0,cosf(radians),-sinf(radians),0),
			Vector4(0,sinf(radians),cosf(radians),0),
			Vector4(0,0,0,1)

			
		);

		break;

	case 1:
		mat4 = Matrix4(

			Vector4(cosf(radians), 0, sinf(radians), 0),
			Vector4(0, 1, 0, 0),
			Vector4(- sinf(radians),0, cosf(radians), 0),
			Vector4(0, 0, 0, 1)


		);
		break;

	case 2:
		mat4 = Matrix4(

			Vector4(cosf(radians),-sinf(radians),0, 0),
			Vector4(sinf(radians), 0, cosf(radians), 0),
			Vector4(0, 0, 1, 0),
			Vector4(0, 0, 0, 1)


		);
		break;

	}

	vec4 = mat4 * Vector4(rotation.x, rotation.y, rotation.z, 1);
	rotation = Vector3(vec4.x, vec4.y, vec4.z);
}

void Transform::Scale(const Vector3 & _scale)
{
	
	const Vector4 vec4= Matrix4::IdentityMat*Vector4(_scale.x,_scale.y,_scale.z,1);
	scale= Vector3(vec4.x,vec4.y,vec4.z);

}

Transform::Transform(const Vector3 & a_position, const Vector3 & a_rotation, const Vector3 & a_scale):
position(a_position),
rotation(a_rotation),
scale(a_scale)
{
	SetModelMatrix();

}

Transform::Transform(const Vector3 & a_position, const Vector3 & a_rotation):
	position(a_position),
	rotation(a_rotation),
	scale(Vector3())
{
	
	SetModelMatrix();
}

Transform::Transform(const Vector3 & a_position):
	position(a_position),
	rotation(Vector3()),
	scale(Vector3())
{
	SetModelMatrix();
}



void Transform::SetModelMatrix()
{
	const Matrix4 scaleMat = Matrix4(
		Vector4(scale.x,0,0,0),
		Vector4(0,scale.y,0,0),
		Vector4(0,0,scale.z,0),
		Vector4(0,0,0,1)

	);

	const Matrix4 translationMat = Matrix4(
		Vector4(1, 0, 0, position.x),
		Vector4(0, 1, 0, position.y),
		Vector4(0, 0, 1, position.z),
		Vector4(0, 0, 0, 1)

	);

	const Matrix4 x_RoatationMat = Matrix4(
		Vector4(1,0,0,0),
		Vector4(0,rotation.y,rotation.z,0),
		Vector4(0,rotation.y,rotation.z,0),
		Vector4(0,0,0,1)
	);

	const Matrix4 y_RoatationMat = Matrix4(
		Vector4(rotation.x, 0, rotation.z, 0),
		Vector4(0, 1, 0, 0),
		Vector4(rotation.x, 0, rotation.z, 0),
		Vector4(0, 0, 0, 1)
	);

	const Matrix4 z_RoatationMat = Matrix4(
		Vector4(rotation.x,rotation.z,0, 0),
		Vector4(rotation.x, rotation.y,0, 0),
		Vector4(0,0,1, 0),
		Vector4(0, 0, 0, 1)
	);

	const Matrix4 p1=x_RoatationMat*scaleMat;
	const Matrix4 p2=y_RoatationMat*p1;
	const Matrix4 p3=z_RoatationMat*p2;
	modelMatrix=translationMat*p3;
}
