#pragma once
#include "Texture.h"
#include "PmVec3.h"

namespace Pm {

	class Cube {
	public:

		Cube(unsigned disposition = 0,bool irregularVertData = false, Texture TEXTURERECT = Texture("container.jpg"));

		void draw();
	private:
		void bindBuffers(unsigned disposition);
		void bindVertPointers();

		Texture textureRect;

		//static bool VAOExist;
		unsigned VAO;
		unsigned VBO, EBO;
		bool irregularVertData;
	};
}