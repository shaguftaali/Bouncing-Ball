#pragma once
class  Vector3
{
public:
	 Vector3();
	 Vector3(float _x,float _y,float _z);
	~ Vector3();

	float x;
	float y;
	float z;

	static Vector3 Add(const Vector3& v1, const Vector3& v2);

	static Vector3 Sub(const Vector3& v1, const Vector3& v2);

	static Vector3 CrossProduct(const Vector3& v1, const Vector3& v2);

	static float DotProduct(const Vector3& v1, const Vector3& v2);

	static Vector3 Multiplication(float scaler,const Vector3& v);

	static  Vector3 Division(float scaler,const Vector3& v);

	static  Vector3 Normalization(const Vector3& v);

	static  float Magnitude(const Vector3& v);

	static  float SqrMagnitude(const Vector3& v);

	static  float Distance(const Vector3& v1, const Vector3& v2);

	friend Vector3 operator *(const Vector3& A, float scaler);

private:

};

