#pragma once
#include "Texture.h"
#include "PmVec3.h"
#include <vector>
namespace Pm {

	class Cube {
	public:

		Cube(float* verts, const unsigned sizeOfArray, Texture* TEXTURERECT,bool irregularVertData = false );

		void draw();
		Texture getTexture() const { return textureRect; }
	private:
		void bindBuffers(float * verts,const unsigned sizeOfArray);
		void bindVertPointers();

		Texture textureRect;

		//static bool VAOExist;
		unsigned VAO;
		unsigned VBO, EBO;
		bool irregularVertData;
	};
}