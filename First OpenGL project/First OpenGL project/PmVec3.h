#pragma once
namespace Pm {
	class Vec3 {
	public:
		Vec3(float X, float Y, float Z);
		
		void operator+=(const Vec3& v);
		void operator-=(const Vec3& v);
		float x, y, z;
	};
}