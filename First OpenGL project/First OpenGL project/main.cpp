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

	//////<vertex shader shit>
	///unsigned int vertexShader;
	///vertexShader = glCreateShader(GL_VERTEX_SHADER);
	///glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	///glCompileShader(vertexShader);
	///
	///
	///int  success;
	///char infoLog[512];
	///glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	///
	///if (!success) {
	///
	///	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	///	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
	///}
	///
	///
	//////<fragment shader shit>
	///unsigned int fragmentShader;
	///fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	///glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	///glCompileShader(fragmentShader);
	///
	///glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	///
	///if (!success) {
	///
	///	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	///	std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << "\n";
	///}
	///
	///
	//////<Linking shader program>
	///unsigned int shaderProgram;
	///shaderProgram = glCreateProgram();
	///
	///glAttachShader(shaderProgram, vertexShader);
	///glAttachShader(shaderProgram, fragmentShader);
	///glLinkProgram(shaderProgram);
	///
	///
	///glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	///
	///if (!success)
	///	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);	
	///
	///glUseProgram(shaderProgram);
	///
	///glDeleteShader(vertexShader);
	///glDeleteShader(fragmentShader);
	///
	///
	///ShaderProgram testProgram;

	///// set up vertex data (and buffer(s)) and configure vertex attributes
	///// ------------------------------------------------------------------
	///float vertices[] = {
	///	-0.5f, -0.5f, 0.0f, // left  
	///	 0.5f, -0.5f, 0.0f, // right 
	///	 0.0f,  0.5f, 0.0f  // top   
	///};
	///
	///unsigned int VBO, VAO;
	///glGenVertexArrays(1, &VAO);
	///glGenBuffers(1, &VBO);
	///// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	///glBindVertexArray(VAO);
	///
	///glBindBuffer(GL_ARRAY_BUFFER, VBO);
	///glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	///
	///glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	///glEnableVertexAttribArray(0);
	///
	///// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	///glBindBuffer(GL_ARRAY_BUFFER, 0);
	///
	///// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	///// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	///glBindVertexArray(0);


	Pm::ShaderProgram shaderProgram("vertexShaderSource.vert","fragmentShaderSource.frag");

	float timeValue = glfwGetTime();
	float greenValue = (sin(timeValue) / 2.0f) + 0.5f;

	if (glGetUniformLocation(shaderProgram.getProgram(), "ourColor") < 0)
		std::cout << "failed to find uniform!\n";

	int vertexColorLocation = glGetUniformLocation(shaderProgram.getProgram(), "ourColor");
	glUseProgram(shaderProgram.getProgram());
	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);


	Pm::Triangle test(Pm::Vec3(-0.3,-0.3,0),Pm::Vec3(0,0.3,0),Pm::Vec3(0.3,-0.3,0));


	while (!glfwWindowShouldClose(window))
	{

		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// draw our first triangle
		glUseProgram(shaderProgram.getProgram());
		///<>test.setPosition(test.getLeft(), test.getTop(), test.getRight());

		float timeValue = glfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		int vertexColorLocation = glGetUniformLocation(shaderProgram.getProgram(), "ourColor");
		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

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