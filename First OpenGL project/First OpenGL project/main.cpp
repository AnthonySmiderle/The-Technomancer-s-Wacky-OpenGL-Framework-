#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderProgram.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"
#include "Cube.h"
#include <vector>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);



float lastX = 400, lastY = 300;
float yaw = -90.0f;
float pitch = 0.0f;
bool firstMouse = true;
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

float dt = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

Pm::Camera defaultCamera;
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
int main() {

	//initialize glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow* window = glfwCreateWindow(800 *  2,600 * 2, "Whats a William", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << "\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << "\n";
		return -1;
	}






	Pm::Shader shaderProgram("vertexShaderSource.vert", "fragmentShaderSource.frag");
	Pm::Shader lightingShader("lightingShader.vert", "lightingShader.frag");
	Pm::Shader lampShader("lightingShader.vert", "lampShader.frag");
	
	//Pm::Cube test;
	//Pm::Cube test2(1);

	std::vector<Pm::Cube> cubes;

	for (int i = 0; i < 1; i++)
		cubes.push_back(Pm::Cube(i));

	Pm::Cube lightCube(2);

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		dt = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		
		//std::cout << "dt: " << dt << "\n";
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, test2.textureRect.getTextureId());

		glUseProgram(lightingShader.getId());

		lightingShader.loadModel();
		lightingShader.loadViewMatrix(defaultCamera);
		lightingShader.loadProjectionMatrix(800.0f * 2, 600.0f * 2);
		lightingShader.setVec3("objectColor", glm::vec3(1.0f, 0, 1.0f));
		lightingShader.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
		for (auto x : cubes)
			x.draw();

		glUseProgram(lampShader.getId());
		lampShader.loadModel();
		lampShader.loadViewMatrix(defaultCamera);
		lampShader.loadProjectionMatrix(800.0f * 2, 600.0f * 2);

		lightCube.draw();


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

	defaultCamera.move(window, 2.5f*dt);
}
void mouse_callback(GLFWwindow * window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	defaultCamera.doMouseMovement(xoffset, yoffset);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {

	glViewport(0, 0, width, height);

}