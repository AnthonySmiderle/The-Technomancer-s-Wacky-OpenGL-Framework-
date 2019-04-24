#include "Texture.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
namespace Pm {

	Texture::Texture(std::string PATH)
	{
		path = PATH;
		

		///<if it wasn't obvious, a lot of this code isn't mine, but this entire section is ACTUALLY copy and pasted to shit so...not like other sections aren't but yeah>
		unsigned texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


		// load and generate the texture
		int width;
		int height;
		int nrChannels;
		auto data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);

	}
}
