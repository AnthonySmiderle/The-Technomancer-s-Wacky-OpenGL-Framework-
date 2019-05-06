#include "ShaderProgram.h"
#include "IO.h"
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"
namespace Pm {

	

	Shader::Shader(std::string VERTSHADERSOURCE, std::string FRAGSHADERSOURCE)
	{
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		vertexShaderSource = VERTSHADERSOURCE;
		fragmentShaderSource = FRAGSHADERSOURCE;


		createProgram();
	}
	
	void Shader::createProgram()
	{
		//make a fucking string i guess
		std::string shaderSource = " ";


		//fucking string stream needs a string so we pass in a string
		loadFileAsString(vertexShaderSource, shaderSource);


		//openGL needs a c string so we pretend this c++ string is a fucking c string
		compileShader(vertexShader, shaderSource.c_str());


		//do it again for the fragment shader
		loadFileAsString(fragmentShaderSource, shaderSource);
		compileShader(fragmentShader, shaderSource.c_str());


		//create the shader program
		shaderProgram = glCreateProgram();


		//attatch and link the shader program to the shaders
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);


		int success;
		char infoLog[512];

		//set the integer value of the shader program based on its link status, and store it into success
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

		//if we did a dumb...aka if it failed to link
		if (!success) {
			//log the information into a c string and then print it out
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << infoLog << "\n";
		}

		//make opengl use the program we made
		glUseProgram(shaderProgram);


		//delete the memory allocated to the gpu by the sahders so we dont get memory leaks
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	}

	void Shader::loadModel()
	{
		glm::mat4 model = glm::mat4(1.0f); 
		unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	}

	void Shader::loadViewMatrix(Camera defaultCamera)
	{
		glm::mat4 view;
		view = defaultCamera.whereAreWeLooking();

		unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
	}

	void Shader::loadProjectionMatrix(float width, float height)
	{
		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, &projection[0][0]);

	}

	void Shader::compileShader(unsigned shader, const char* shaderSource)
	{
		//point opengl to the shader's source, then compile that shader
		glShaderSource(shader, 1, &shaderSource, NULL);
		glCompileShader(shader);

		int  success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << shader << "failed to compile : " << infoLog << "\n";
		}
	}

}
