#pragma once
#include "stb_image.h"
#include <string>
namespace Pm {
	class Texture {
	public:
		Texture(std::string PATH);

	private:
		std::string path;
	};
}