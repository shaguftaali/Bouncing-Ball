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
//	position=Vector3(vec4.x,vec4.y,vec4.z);
	position=targetPosition;
	SetModelMatrix();

}

void Transform::Rotation(const Vector3 & Rotation)
{
	

}

void Transform::Rotation(int axis, float angle)
{
	Matrix4 mat4;
	Vector4 vec4;
	const float radians =angle*(PI / 180);
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
	
	//const Vector4 vec4= Matrix4::IdentityMat*Vector4(_scale.x,_scale.y,_scale.z,1);
	scale= _scale;
	SetModelMatrix();
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
	scale(Vector3(1,1,1))
{
	
	SetModelMatrix();
}

Transform::Transform(const Vector3 & a_position):
	position(a_position),
	rotation(Vector3()),
	scale(Vector3(1,1,1))
{
	SetModelMatrix();
}



void Transform::SetModelMatrix()
{
	Vector3 radin=rotation*(PI/180);
	const Matrix4 scaleMat = Matrix4(
		Vector4(scale.x,0,0,0),
		Vector4(0,scale.y,0,0),
		Vector4(0,0,scale.z,0),
		Vector4(0,0,0,1)

	);

	

	const Matrix4 translationMat = Matrix4(
		Vector4(1, 0, 0, 0),
		Vector4(0, 1, 0, 0),
		Vector4(0, 0, 1, 0),
		Vector4(position.x, position.y, position.z, 1)

	);

	const Matrix4 x_RoatationMat = Matrix4(
		Vector4(1,0,0,0),
		Vector4(0,cos(radin.x),-sin(radin.x),0),
		Vector4(0, sin(radin.x), cos(radin.x),0),
		Vector4(0,0,0,1)
	);

	const Matrix4 y_RoatationMat = Matrix4(
		Vector4(cos(radin.y), 0, sin(radin.y), 0),
		Vector4(0, 1, 0, 0),
		Vector4(-sin(radin.y), 0, cos(radin.y), 0),
		Vector4(0, 0, 0, 1)
	);

	const Matrix4 z_RoatationMat = Matrix4(
		Vector4(cos(radin.z), -sin(radin.z),0, 0),
		Vector4(sin(radin.z), cos(radin.z),0, 0),
		Vector4(0,0,1, 0),
		Vector4(0, 0, 0, 1)
	);

	const Matrix4 p1=x_RoatationMat*scaleMat;
	const Matrix4 p2=y_RoatationMat*p1;
	const Matrix4 p3=z_RoatationMat*p2;
	modelMatrix=translationMat*p3;
}
