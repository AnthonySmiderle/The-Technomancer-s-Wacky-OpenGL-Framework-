#pragma once
#include "Texture.h"
#include "PmVec3.h"
#define yes true
#define no false

namespace Pm {

	class Cube {
	public:

		Cube(unsigned disposition = 0,Texture TEXTURERECT = Texture("container.jpg"));

		Texture textureRect;
		void draw();
	private:
		void bindBuffers(unsigned disposition);
		void bindVertPointers();


		//static bool VAOExist;
		unsigned VAO;
		unsigned VBO, EBO;
	};
}