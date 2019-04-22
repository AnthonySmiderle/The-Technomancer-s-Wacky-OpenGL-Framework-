#pragma once
#include "PmVec3.h"
namespace Pm {

	//probably should make this pure virtual
	//a class for all your virtual buffer object and virtual buffer array needs
	class VBO_VBA {
	public:
		VBO_VBA(const unsigned _VBO, const unsigned _VAO);
	protected:
		void bindBuffer();
		void bindVertPointer();
		unsigned VBO, VAO;
	};

	class Triangle : public VBO_VBA {
	public:

		Triangle(const unsigned _VBO = 0, const unsigned _VAO = 0);
		Triangle(const Vec3& lefMost, const Vec3& top, const Vec3& rightMost, const unsigned _VBO = 0, const unsigned _VAO = 0);
		void setPosition(const Vec3& leftMost, const Vec3&top, const Vec3 rightMost);
		void draw();
		static int triangles;

		Vec3 getLeft() const { return left; }
		Vec3 getTop() const { return top; }
		Vec3 getRight() const { return right; }
	private:
		Vec3 left, top, right;
	};
}