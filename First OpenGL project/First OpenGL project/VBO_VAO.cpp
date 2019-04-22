#include "VBO_VAO.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace Pm {

	//todo
	VBO_VBA::VBO_VBA(const unsigned _VBO, const unsigned _VAO)
	{
		VBO = _VBO;
		VAO = _VAO;

		//generate those buffers and vertex arrays
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
	}

	void VBO_VBA::bindBuffer()
	{
		//bind the vertex array and the buffer to the context
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
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
	Triangle::Triangle(const unsigned _VBO, const unsigned _VAO)
		:VBO_VBA(_VBO, _VAO),left(0,0,0),top(0,0,0),right(0,0,0)
	{
		triangles++;
		float vertices[] = {
			-0.5f, -0.5f, 0.0f, // left  
			 0.5f, -0.5f, 0.0f, // right 
			 0.0f,  0.5f, 0.0f  // top   
		};
		bindBuffer();
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		bindVertPointer();
	}


	Triangle::Triangle(const Vec3 & leftMost, const Vec3 & Top, const Vec3 & rightMost, const unsigned _VBO, const unsigned _VAO)
		:VBO_VBA(_VBO, _VAO), left(leftMost), top(Top), right(rightMost)
	{

		triangles++;
		//create an array of floats that will contain the data that opengl uses to draw the damn triangle
		float vertices[] = {
			leftMost.x, leftMost.y, 0.0f, // left  
			 rightMost.x, rightMost.y, 0.0f, // right 
			 Top.x,  Top.y, 0.0f  // top   
		};

		bindBuffer();
		///<change stream draw to static draw>
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		bindVertPointer();

	}

	//this doesnt work but its neat
	void Triangle::setPosition(const Vec3 & leftMost, const Vec3 & Top, const Vec3 rightMost)
	{
		float vertices[] = {
			leftMost.x, leftMost.y, 0.0f, // left  
			 rightMost.x, rightMost.y, 0.0f, // right 
			 Top.x,  Top.y, 0.0f  // top   
		};
		bindBuffer();
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		bindVertPointer();

	}

	void Triangle::draw()
	{
		//rebind the vert array and draw the triangle again
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}
