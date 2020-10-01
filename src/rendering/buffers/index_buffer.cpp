#include "pch.h"
#include "index_buffer.h"
#include "glad/glad.h"

namespace Split
{

	IndexBuffer::IndexBuffer(unsigned int* buffer, unsigned int count, unsigned int mode)
		: m_id{ 0 }, m_count{ count }
	{
		m_data = std::vector<unsigned int>(buffer, buffer + count);
		glCreateBuffers(1, &m_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), buffer, mode);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &m_id);
	}

	void IndexBuffer::bind(void)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
	}

	void IndexBuffer::unbind(void)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	int IndexBuffer::get_count(void)
	{
		return m_count;
	}

	unsigned int IndexBuffer::get_id(void)
	{
		return m_id;
	}

	std::vector<unsigned int>& IndexBuffer::data(void)
	{
		return m_data;
	}

	void IndexBuffer::print(void)
	{
		std::vector<unsigned int> contents = data();
		if (!contents.size()) {
			std::cerr << "Index Buffer Empty\n";
			return;
		}
		std::cerr << "Index Buffer Contents:\n" << contents[0];
		for (int i = 1; i < contents.size(); i++)
			std::cerr << ", " << contents[i];
		std::cerr << "\n\n";
	}

	std::shared_ptr<IndexBuffer> create_index_buffer(unsigned int* buffer, unsigned int count, unsigned int mode)
	{
		return std::shared_ptr<IndexBuffer>(new IndexBuffer(buffer, count, mode));
	}

}
