#include "pch.h"
#include "texture_2D.h"
#include "glad/glad.h"
#include "utils/utils.h"
#include "core/log.h"

namespace Split
{

	static unsigned int gl_texture_slot(unsigned int index)
	{
		if (index > GL_TEXTURE31 - GL_TEXTURE0) {
			log_error("Texture slot {0} invalid, defaulting to slot 0.", index);
			return GL_TEXTURE0;
		}
		return GL_TEXTURE0 + index;
	}

	Texture2D::Texture2D(std::string path, TextureFormat format, int channels, int type)
		: m_type{ type }
	{
		m_data = loadImage(path, format, &m_width, &m_height, &m_bpp, channels, true);
		if (!m_data)
			log_error("Failed to load texture file: {0}", path);

		glGenTextures(1, &m_id);
		glBindTexture(type, m_id);
		glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(type, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
	}

	Texture2D::~Texture2D()
	{
	}

	void Texture2D::bind(unsigned int slot)
	{
		glActiveTexture(gl_texture_slot(slot));
		glBindTexture(m_type, m_id);
	}

	void Texture2D::unbind(void)
	{
		glBindTexture(m_type, 0);
	}

	bool Texture2D::has_buffer(void)
	{
		return m_data != nullptr;
	}

	void* Texture2D::get_buffer(void)
	{
		return m_data;
	}

	int Texture2D::get_bpp(void)
	{
		return m_bpp;
	}

	int Texture2D::get_width(void)
	{
		return m_height;
	}

	int Texture2D::get_height(void)
	{
		return m_width;
	}

}
