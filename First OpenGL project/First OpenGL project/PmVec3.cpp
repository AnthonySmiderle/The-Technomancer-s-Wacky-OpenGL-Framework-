#include "PmVec3.h"

Pm::Vec3::Vec3(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
}

void Pm::Vec3::operator+=(const Vec3 & v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

void Pm::Vec3::operator-=(const Vec3 & v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}
