#include "..\..\Includes\Maths\Vector3.h"
#include <cassert>
#include <cmath>

Vector3::Vector3():
	x(0),
	y(0),
	z(0)
{

}

Vector3::Vector3(float _x, float _y, float _z):
	x(_x),
	y(_y),
	z(_z)
{}

Vector3::~Vector3()
{}


 Vector3 Vector3::Add(const Vector3& v1, const Vector3& v2)
 {
 	return Vector3(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z);
 }

Vector3 Vector3::Sub(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector3 Vector3::CrossProduct(const Vector3& v1, const Vector3& v2)
{
	float i=(v1.y*v2.z)-(v2.y*v1.z);
	float j=-(v1.x*v2.z)+(v2.x*v1.z);
	float k=(v1.x*v2.y)-(v2.x*v1.y);

	return Vector3(i,j,k);
}

float Vector3::DotProduct(const Vector3& v1, const Vector3& v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

Vector3 Vector3::Multiplication(float scaler, const Vector3& v)
{
	return Vector3(scaler*v.x,scaler*v.y,scaler*v.z);
}

Vector3 Vector3::Division(float scaler, const Vector3& v)
{
	assert(scaler!=0);
	return Vector3(v.x/scaler, v.y/scaler, v.z/scaler);
}

Vector3 Vector3::Normalization(const Vector3& v)
{
	float magnitude=Magnitude(v);
	return Vector3(v.x/magnitude,v.y/magnitude,v.z/magnitude);
}

float Vector3::Magnitude(const Vector3& v)
{
	return sqrtf(SqrMagnitude(v));
}

float Vector3::SqrMagnitude(const Vector3& v)
{
	return (v.x*v.x + v.y*v.y+v.z*v.z);
}

float Vector3::Distance(const Vector3& v1, const Vector3& v2)
{
	return Magnitude(Sub(v1,v2));
}

Vector3 operator*(const Vector3 & A, float scaler)
{
	return Vector3(A.x*scaler,A.y*scaler,A.z*scaler);
}
