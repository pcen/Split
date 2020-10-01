#include "pch.h"
#include "vertex_buffer.h"
#include "glad/glad.h"

namespace Split
{

	vertex_attribute::vertex_attribute(const std::string& name, unsigned int count, bool normalized)
		: name{ name }, count{ count }, normalized{ normalized }, offset{ 0 } {}

	std::ostream& operator<<(std::ostream& os, const vertex_attribute& a)
	{
		os << a.name << ": count=" << a.count << ", normalized=" << (a.normalized ? "true" : "false");
		return os;
	}

	VertexAttributes::VertexAttributes()
		: m_stride{ 0 } {}

	VertexAttributes::~VertexAttributes() {}

	void VertexAttributes::calculate_stride(void)
	{
		m_stride = 0;
		for (auto& attribute : m_attributes)
			m_stride += sizeof(float) * attribute.count;
	}

	void VertexAttributes::set_offsets(void)
	{
		int offset = 0;
		for (auto& attribute : m_attributes) {
			attribute.offset = offset;
			offset += sizeof(float) * attribute.count;
		}
	}

	VertexAttributes& VertexAttributes::operator=(const std::initializer_list<vertex_attribute>& attributes)
	{
		m_attributes = std::vector<vertex_attribute>(attributes);
		calculate_stride();
		set_offsets();
		return *this;
	}

	size_t VertexAttributes::size(void) { return m_attributes.size(); }

	std::vector<vertex_attribute>::iterator VertexAttributes::begin() { return m_attributes.begin(); }

	std::vector<vertex_attribute>::iterator VertexAttributes::end() { return m_attributes.end(); }

	vertex_attribute& VertexAttributes::at(unsigned int i) { return m_attributes.at(i); }

	unsigned int VertexAttributes::get_stride(void) { return m_stride; }

	VertexBuffer::VertexBuffer(float* buffer, unsigned int count, unsigned int mode)
		: m_count{ count }, m_mode{ mode }, m_id{ 0 }
	{
		m_data = std::vector<float>(buffer, buffer + count);
		glCreateBuffers(1, &m_id);
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), buffer, mode);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_id);
	}

	void VertexBuffer::bind(void)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
	}

	void VertexBuffer::unbind(void)
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VertexBuffer::enable_attributes(void)
	{
		bind();
		for (int i = 0; i < attributes.size(); i++) {
			vertex_attribute& a = attributes.at(i);
			glVertexAttribPointer(
				i,
				a.count,
				GL_FLOAT,
				a.normalized ? GL_TRUE : GL_FALSE,
				attributes.get_stride(),
				(const void*)a.offset);
			glEnableVertexAttribArray(i);
			}
	}

	std::vector<float>& VertexBuffer::data(void)
	{
		return m_data;
	}

	void VertexBuffer::print(void)
	{
		std::vector<float>& contents = data();
		if (!contents.size()) {
			std::cerr << "\nVertex Buffer Empty\n\n";
			return;
		}
		std::cerr << "\nVertex Buffer Contents:\n" << contents[0];
		for (int i = 1; i < contents.size(); i++)
			std::cerr << ", " << contents[i];
		if (!attributes.size()) {
			std::cerr << "No Attributes\n\n";
			return;
		}
		std::cerr << "\nAttributes:\n";
		for (auto& a : attributes)
			std::cerr << a << "\n";
		std::cerr << "\n";
	}

	std::shared_ptr<VertexBuffer> create_vertex_buffer(float* buffer, unsigned int count, unsigned int mode)
	{
		return std::shared_ptr<VertexBuffer>(new VertexBuffer(buffer, count, mode));
	}

}
