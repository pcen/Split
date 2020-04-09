#include "pch.h"
#include "vertex_array.h"

#include "glad/glad.h"
#include "buffers/index_buffer.h"
#include "buffers/vertex_buffer.h"

namespace Split
{

	VertexArray::VertexArray()
		: m_bound{ false }, m_index_buffer{ nullptr }, m_vertex_buffer{ nullptr }
	{
		glGenVertexArrays(1, &m_id);
	}

	VertexArray::VertexArray(IndexBuffer* index_buffer, VertexBuffer* vertex_buffer) : m_bound{ false }
	{
		glGenVertexArrays(1, &m_id);
		attach_index_buffer(index_buffer);
		attach_vertex_buffer(vertex_buffer);
	}

	VertexArray::~VertexArray()
	{
		glDeleteBuffers(1, &m_id);
	}

	void VertexArray::bind(void)
	{
		if (!is_bound()) {
			glBindVertexArray(m_id);
			m_bound = true;
		}
	}

	void VertexArray::unbind(void)
	{
		if (is_bound()) {
			glBindVertexArray(0);
			m_bound = false;
		}
	}

	bool VertexArray::is_bound(void)
	{
		return m_bound;
	}

	void VertexArray::attach_index_buffer(IndexBuffer* index_buffer)
	{
		bind();
		index_buffer->bind();
		m_index_buffer = index_buffer;
	}

	void VertexArray::attach_vertex_buffer(VertexBuffer* vertex_buffer)
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

}
