#include "ShaderProgram.h"
#include "IO.h"
#include <stdio.h>

namespace Pm {

	

	ShaderProgram::ShaderProgram(std::string VERTSHADERSOURCE, std::string FRAGSHADERSOURCE)
	{
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		vertexShaderSource = VERTSHADERSOURCE;
		fragmentShaderSource = FRAGSHADERSOURCE;


		createProgram();
	}
	
	void ShaderProgram::createProgram()
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

	void ShaderProgram::compileShader(unsigned shader, const char* shaderSource)
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
