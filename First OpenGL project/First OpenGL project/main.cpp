#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "VBO_VAO.h"
#include <iostream>
#include "ShaderProgram.h"



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main() {

	//initialize glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow* window = glfwCreateWindow(800, 600, "TRIANGLE", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << "\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << "\n";
		return -1;
	}

	Pm::Shader shaderProgram("vertexShaderSource.vert","fragmentShaderSource.frag");

	//float timeValue = glfwGetTime();
	//float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
	//
	//if (glGetUniformLocation(shaderProgram.getProgram(), "ourColor") < 0)
	//	std::cout << "failed to find uniform!\n";
	//
	//int vertexColorLocation = glGetUniformLocation(shaderProgram.getProgram(), "ourColor");
	//glUseProgram(shaderProgram.getProgram());
	//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);


	Pm::Triangle test(Pm::Vec3(-0.3f,-0.3f,0),Pm::Vec3(0,0.3f,0),Pm::Vec3(0.3f,-0.3f,0),Pm::Vec3(0,1.0f,0),Pm::Vec3(0,0,1.0f),Pm::Vec3(1.0f,0,0));


	while (!glfwWindowShouldClose(window))
	{

		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// draw our first triangle
		glUseProgram(shaderProgram.getProgram());
		///<>test.setPosition(test.getLeft(), test.getTop(), test.getRight());

		//float timeValue = glfwGetTime();
		//float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		//int vertexColorLocation = glGetUniformLocation(shaderProgram.getProgram(), "ourColor");
		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

		test.draw();


		glfwSwapBuffers(window);
		glfwPollEvents();


	}
	glfwTerminate();

	return 0;
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {

	glViewport(0, 0, width, height);

}