#include "pch.h"
#include "utils.h"
#include "logging/log.h"

namespace Split
{

	std::string read_file(std::string filepath)
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
			core_log_error("Failed to read file \"{0}\"", filepath);
		}
		return contents;
	}

}