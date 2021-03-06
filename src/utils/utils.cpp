#include "pch.h"
#include "utils.h"
#include "core/log.h"
#include "stb_image.h"

namespace Split
{

	std::string readFile(std::string filepath)
	{
		std::string contents;
		std::ifstream ifs;
		ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try {
			ifs.open(filepath);
			contents = std::string(std::istreambuf_iterator<char>(ifs), {});
			ifs.close();
		}
		catch (std::ifstream::failure error) {
			log_error("Failed to read file \"{0}\"", filepath);
		}
		return contents;
	}

	unsigned char* loadImage(std::string path, TextureFormat format, int* width, int* height, int* bpp, int channels, bool flip)
	{
		if (flip)
			stbi_set_flip_vertically_on_load(1);

		return stbi_load(path.c_str(), width, height, bpp, channels);
	}

}
