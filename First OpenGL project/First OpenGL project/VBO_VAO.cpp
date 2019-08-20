#include "VBO_VAO.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Pm {

	VBO_VBA::VBO_VBA(const unsigned _VBO, const unsigned _VAO)
	{
		VBO = _VBO;
		VAO = _VAO;

		//generate those buffers and vertex arrays
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
	}

	void VBO_VBA::bindBuffer()
	{
		float vertices[] = {
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
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

	void VBO_VBA::bindVertPointer()
	{
		//point the attrivute pointer in the right direction based on the size of our vector of floats
		//this will determine how many spaces in memory opengl should leave inbetween checkinf for data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);


		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);
	}

	int Triangle::triangles = 0;
	Triangle::Triangle(const unsigned _VBO, const unsigned _VAO, Texture TEXTURERECT, Texture TEXTURERECT2)
		:VBO_VBA(_VBO, _VAO), left(0, 0, 0), top(0, 0, 0), right(0, 0, 0), textureRect(TEXTURERECT), textureRect2(TEXTURERECT2)
	{
		triangles++;
		///<i dunno if this is a triangle anymore chief>


		bindBuffer();

		bindVertPointer(1);
	}


	Triangle::Triangle(const Vec3 & leftMost, const Vec3 & Top, const Vec3 & rightMost, const Vec3& leftmostColour, const Vec3& TopColour, const Vec3& rightmostColour, const unsigned _VBO, const unsigned _VAO)
		:VBO_VBA(_VBO, _VAO), left(leftMost), top(Top), right(rightMost), textureRect("container.jpg"), textureRect2("gottem.png")
	{

		triangles++;
		//create an array of floats that will contain the data that opengl uses to draw the damn triangle
		float vertices[] = {
			//positions                     //CAUSE COLOURS ARE THE THING THAT MAKE THE WORLD BETTER
			leftMost.x, leftMost.y,   0.0f, leftmostColour.x,leftmostColour.y,leftmostColour.z, // left  
			rightMost.x, rightMost.y, 0.0f, rightmostColour.x,rightmostColour.y,rightmostColour.z, // right 
			Top.x,  Top.y,            0.0f, TopColour.x,TopColour.y,TopColour.z // top   
		};

		bindBuffer();
		///<change stream draw to static draw>
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		bindVertPointer();

	}

	//this doesnt work but its neat
	//void Triangle::setPosition(const Vec3 & leftMost, const Vec3 & Top, const Vec3 rightMost)
	//{
	//	float vertices[] = {
	//		leftMost.x, leftMost.y, 0.0f, // left  
	//		 rightMost.x, rightMost.y, 0.0f, // right 
	//		 Top.x,  Top.y, 0.0f  // top   
	//	};
	//	bindBuffer();
	//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//	bindVertPointer();
	//
	//}


	///<use this function when you want to have a fucking triangle with a texture in it>
	void Triangle::bindVertPointer(int dummy)
	{
		//point the attrivute pointer in the right direction based on the size of our vector of floats
		//this will determine how many spaces in memory opengl should leave inbetween checkinf for data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		///<here goes some multicoloured shit, its 6* the size of a float now cause there are 6 entries into our "2d" array>
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);




	}

	void Triangle::bindVertPointer()
	{
		//point the attrivute pointer in the right direction based on the size of our vector of floats
		//this will determine how many spaces in memory opengl should leave inbetween checkinf for data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		///<here goes some multicoloured shit, its 6* the size of a float now cause there are 6 entries into our "2d" array>
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);
	}
	void Triangle::bindBuffer1()
	{
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		//bind the vertex array and the buffer to the context
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBindTexture(GL_TEXTURE_2D, textureRect.getTextureId());
		glBindVertexArray(VAO);

	}

	void Triangle::draw()
	{
		//rebind the vert array and draw the triangle again
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	void Triangle::draw(int dummy) {

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 36);

	}
}
