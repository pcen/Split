#ifndef TEXTURE_H
#define TEXTURE_H

namespace Split
{

	class Texture
	{
	public:
		virtual ~Texture() {}

		virtual void bind(unsigned int slot = 0) = 0;
		virtual void unbind(void) = 0;
		virtual bool has_buffer(void) = 0;
		virtual void* get_buffer(void) = 0;
		virtual int get_bpp(void) = 0;

	protected:
		unsigned int m_id;
	};

}

#endif /* TEXTURE_H */
