#pragma once

#include "rendering/textures/texture_formats.h"

namespace Split
{
	// Read a text file and return the contents in a std::string
	std::string readFile(std::string filepath);

	// Load an image file
	unsigned char* loadImage(std::string path, TextureFormat format, int* width, int* height, int* bpp, int channels, bool flip);

}
