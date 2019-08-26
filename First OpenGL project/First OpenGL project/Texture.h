#pragma once
#include "stb_image.h"
#include <string>
namespace Pm {
	class Texture {
	public:
		Texture(std::string PATH);
		unsigned load();
		unsigned getTextureId() const { return texture; }
	private:
		std::string path;
		unsigned texture;
	};
}