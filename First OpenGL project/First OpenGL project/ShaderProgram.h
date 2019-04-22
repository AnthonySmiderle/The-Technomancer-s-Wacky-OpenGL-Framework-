#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
namespace Pm {

	class ShaderProgram {
	public:
		//default constructor is all that you need to call
		
		ShaderProgram(std::string VERTSHADERSOURCE,std::string FRAGSHADERSOURCE);
		
		//get the program 
		unsigned getProgram() const { return shaderProgram; }
	private:
		//compiles the shader that you pass in
		void compileShader(unsigned shader, const char* tempString);
		void createProgram();
		

		unsigned shaderProgram;
		unsigned vertexShader;
		std::string vertexShaderSource;
		std::string fragmentShaderSource;
		unsigned fragmentShader;
	};
}
