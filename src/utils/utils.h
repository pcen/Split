#ifndef UTILS_H
#define UTILS_H

#include "rendering/textures/texture_formats.h"

namespace Split
{

	std::string read_file(std::string filepath);

	unsigned char* load_image(std::string path, TextureFormat format, int* width, int* height, int* bpp, int channels, bool flip);

}

#endif /* UTILS_H */
