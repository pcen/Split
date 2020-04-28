#include "pch.h"
#include "vertex_array.h"

#include "glad/glad.h"
#include "buffers/index_buffer.h"
#include "buffers/vertex_buffer.h"

namespace Split
{

	VertexArray::VertexArray(std::shared_ptr<IndexBuffer> index_buffer, std::shared_ptr<VertexBuffer> vertex_buffer)
	{
		glGenVertexArrays(1, &m_id);
		attach_index_buffer(index_buffer);
		attach_vertex_buffer(vertex_buffer);
		unbind();
	}

	VertexArray::~VertexArray()
	{
		glDeleteBuffers(1, &m_id);
	}

	void VertexArray::bind(void)
	{
		glBindVertexArray(m_id);
	}

	void VertexArray::unbind(void)
	{
		glBindVertexArray(0);
	}

	unsigned int VertexArray::get_index_count(void)
	{
		return m_index_count;
	}

	void VertexArray::attach_index_buffer(std::shared_ptr<IndexBuffer> index_buffer)
	{
		bind();
		index_buffer->bind();
		m_index_buffer = index_buffer;
		m_index_count = index_buffer->get_count();
	}

	void VertexArray::attach_vertex_buffer(std::shared_ptr<VertexBuffer> vertex_buffer)
	{
		bind();
		vertex_buffer->enable_attributes();
		m_vertex_buffer = vertex_buffer;
	}

	void VertexArray::print(void)
	{
		std::cerr << "=== Vertex Array Data ===\n";
		if (m_vertex_buffer)
			m_vertex_buffer->print();
		if (m_index_buffer)
			m_index_buffer->print();
		std::cerr << "=== Vertex Array Data End ===\n";
	}

	std::shared_ptr<VertexArray> create_vertex_array(std::shared_ptr<IndexBuffer>& index_buffer, std::shared_ptr<VertexBuffer>& vertex_buffer)
	{
		return std::shared_ptr<VertexArray>(new VertexArray(index_buffer, vertex_buffer));
	}

}
