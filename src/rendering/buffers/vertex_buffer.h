#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

namespace Split
{

	typedef struct vertex_attribute
	{
		std::string name;
		unsigned long long offset;
		unsigned int count;
		bool normalized;
		vertex_attribute(const std::string& name, unsigned int count, bool normalized = false);
		friend std::ostream& operator << (std::ostream& os, const vertex_attribute& a);
	} vertex_attribute;

	class VertexAttributes
	{
		friend class VertexBuffer;
		VertexAttributes();
		~VertexAttributes();

		void calculate_stride(void);
		void set_offsets(void);

		size_t size(void);
		unsigned int get_stride(void);
		vertex_attribute& at(unsigned int i);
		
		unsigned int m_stride;
		std::vector<vertex_attribute> m_attributes;
		
	public:
		VertexAttributes& operator = (const std::initializer_list<vertex_attribute>& attributes);
		std::vector<vertex_attribute>::iterator begin();
		std::vector<vertex_attribute>::iterator end();
	};

	class VertexBuffer
	{
	public:
		VertexBuffer(float* buffer, unsigned int count, unsigned int mode);
		~VertexBuffer();

		void bind(void);
		void unbind(void);
		std::vector<float>& data(void);

		void print(void);

		void enable_attributes(void);

		VertexAttributes attributes;
	private:
		unsigned int m_count, m_mode, m_id;
		std::vector<float> m_data;
	};

	std::shared_ptr<VertexBuffer> create_vertex_buffer(float* buffer, unsigned int count, unsigned int mode);
}

#endif /* VERTEX_BUFFER_H */
