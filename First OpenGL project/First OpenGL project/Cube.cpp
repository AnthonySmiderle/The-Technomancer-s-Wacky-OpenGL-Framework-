#include "Cube.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace Pm {

	//unsigned Cube::VAO = 0;
	//bool Cube::VAOExist = false;
	Pm::Cube::Cube(unsigned disposition, bool irregularVertData, Texture TEXTURERECT)
		:textureRect(TEXTURERECT)
	{
		//if (not VAOExist) {
		glGenVertexArrays(1, &VAO);
		//	VAOExist = yes;
		//}
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		this->irregularVertData = irregularVertData;
		bindBuffers(disposition);
		bindVertPointers();
	}
	void Cube::bindBuffers(unsigned disposition)
	{
		if (!irregularVertData) {

			float vertices[] = {
		-0.5f + disposition, -0.5f + disposition, -0.5f + disposition,  0.0f + disposition, 0.0f + disposition,
		 0.5f + disposition, -0.5f + disposition, -0.5f + disposition,  1.0f + disposition, 0.0f + disposition,
		 0.5f + disposition,  0.5f + disposition, -0.5f + disposition,  1.0f + disposition, 1.0f + disposition,
		 0.5f + disposition,  0.5f + disposition, -0.5f + disposition,  1.0f + disposition, 1.0f + disposition,
		-0.5f + disposition,  0.5f + disposition, -0.5f + disposition,  0.0f + disposition, 1.0f + disposition,
		-0.5f + disposition, -0.5f + disposition, -0.5f + disposition,  0.0f + disposition, 0.0f + disposition,

		-0.5f + disposition, -0.5f + disposition,  0.5f + disposition,  0.0f + disposition, 0.0f + disposition,
		 0.5f + disposition, -0.5f + disposition,  0.5f + disposition,  1.0f + disposition, 0.0f + disposition,
		 0.5f + disposition,  0.5f + disposition,  0.5f + disposition,  1.0f + disposition, 1.0f + disposition,
		 0.5f + disposition,  0.5f + disposition,  0.5f + disposition,  1.0f + disposition, 1.0f + disposition,
		-0.5f + disposition,  0.5f + disposition,  0.5f + disposition,  0.0f + disposition, 1.0f + disposition,
		-0.5f + disposition, -0.5f + disposition,  0.5f + disposition,  0.0f + disposition, 0.0f + disposition,

		-0.5f + disposition,  0.5f + disposition,  0.5f + disposition,  1.0f + disposition, 0.0f + disposition,
		-0.5f + disposition,  0.5f + disposition, -0.5f + disposition,  1.0f + disposition, 1.0f + disposition,
		-0.5f + disposition, -0.5f + disposition, -0.5f + disposition,  0.0f + disposition, 1.0f + disposition,
		-0.5f + disposition, -0.5f + disposition, -0.5f + disposition,  0.0f + disposition, 1.0f + disposition,
		-0.5f + disposition, -0.5f + disposition,  0.5f + disposition,  0.0f + disposition, 0.0f + disposition,
		-0.5f + disposition,  0.5f + disposition,  0.5f + disposition,  1.0f + disposition, 0.0f + disposition,

		 0.5f + disposition,  0.5f + disposition,  0.5f + disposition,  1.0f + disposition, 0.0f + disposition,
		 0.5f + disposition,  0.5f + disposition, -0.5f + disposition,  1.0f + disposition, 1.0f + disposition,
		 0.5f + disposition, -0.5f + disposition, -0.5f + disposition,  0.0f + disposition, 1.0f + disposition,
		 0.5f + disposition, -0.5f + disposition, -0.5f + disposition,  0.0f + disposition, 1.0f + disposition,
		 0.5f + disposition, -0.5f + disposition,  0.5f + disposition,  0.0f + disposition, 0.0f + disposition,
		 0.5f + disposition,  0.5f + disposition,  0.5f + disposition,  1.0f + disposition, 0.0f + disposition,

		-0.5f + disposition, -0.5f + disposition, -0.5f + disposition,  0.0f + disposition, 1.0f + disposition,
		 0.5f + disposition, -0.5f + disposition, -0.5f + disposition,  1.0f + disposition, 1.0f + disposition,
		 0.5f + disposition, -0.5f + disposition,  0.5f + disposition,  1.0f + disposition, 0.0f + disposition,
		 0.5f + disposition, -0.5f + disposition,  0.5f + disposition,  1.0f + disposition, 0.0f + disposition,
		-0.5f + disposition, -0.5f + disposition,  0.5f + disposition,  0.0f + disposition, 0.0f + disposition,
		-0.5f + disposition, -0.5f + disposition, -0.5f + disposition,  0.0f + disposition, 1.0f + disposition,

		-0.5f + disposition,  0.5f + disposition, -0.5f + disposition,  0.0f + disposition, 1.0f + disposition,
		 0.5f + disposition,  0.5f + disposition, -0.5f + disposition,  1.0f + disposition, 1.0f + disposition,
		 0.5f + disposition,  0.5f + disposition,  0.5f + disposition,  1.0f + disposition, 0.0f + disposition,
		 0.5f + disposition,  0.5f + disposition,  0.5f + disposition,  1.0f + disposition, 0.0f + disposition,
		-0.5f + disposition,  0.5f + disposition,  0.5f + disposition,  0.0f + disposition, 0.0f + disposition,
		-0.5f + disposition,  0.5f + disposition, -0.5f + disposition,  0.0f + disposition, 1.0f + disposition
			};
			unsigned int indices[] = {
			0, 1, 3, // first triangle
			1, 2, 3  // second triangle
			};
			//bind the vertex array and the buffer to the context
			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		}
		else {
			float vertices[] = {
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
			};

			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


		}
	}
	void Cube::bindVertPointers()
	{
		//point the attrivute pointer in the right direction based on the size of our vector of floats
		//this will determine how many spaces in memory opengl should leave inbetween checkinf for data
		if (!irregularVertData) {

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		///<here goes some multicoloured shit, its 6* the size of a float now cause there are 6 entries into our "2d" array>
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		}
		else {
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);
		}
	}
	void Cube::draw()
	{
		glBindVertexArray(VAO);
		//if (!irregularVertData)
		//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}
