#pragma once
#include "PmVec3.h"
namespace Pm {

	//probably should make this pure virtual
	//a class for all your virtual buffer object and virtual buffer array needs
	class VBO_VBA {
	public:
		VBO_VBA(const unsigned _VBO, const unsigned _VAO);
	protected:
		virtual void bindBuffer();
		virtual void bindVertPointer();
		unsigned VBO, VAO;
	};

	class Triangle : public VBO_VBA {
	public:

		Triangle(const unsigned _VBO = 0, const unsigned _VAO = 0);

		///<HEARD YOU LIKE STUFF THAT ISN'T HARD CODED>
		///<WE GOT YOU COVERED BABY>
		Triangle(const Vec3& lefMost, const Vec3& top, const Vec3& rightMost,const Vec3& leftmostColour, const Vec3& TopColour, const Vec3& rightmostColour,const unsigned _VBO = 0, const unsigned _VAO = 0);
		void setPosition(const Vec3& leftMost, const Vec3&top, const Vec3 rightMost);
		void draw();
		static int triangles;

		Vec3 getLeft() const { return left; }
		Vec3 getTop() const { return top; }
		Vec3 getRight() const { return right; }
	private:
		void bindVertPointer() override;
		Vec3 left, top, right;
	};
}