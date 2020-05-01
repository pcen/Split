#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#include "texture.h"
#include "texture_formats.h"

namespace Split
{

	class Texture2D : public Texture
	{
	public:
		Texture2D(std::string path, TextureFormat format, int channels, int type);
		~Texture2D();

		void bind(unsigned int slot = 0) override;
		void unbind(void) override;
		bool has_buffer(void) override;
		void* get_buffer(void) override;
		int get_bpp(void) override;

		int get_width(void);
		int get_height(void);

	private:
		unsigned char* m_data;
		int m_type, m_width, m_height, m_bpp;
	};

}

#endif /* TEXTURE_2D_H */
