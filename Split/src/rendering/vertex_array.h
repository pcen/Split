#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "rendering/buffers/index_buffer.h"
#include "rendering/buffers/vertex_buffer.h"

namespace Split
{

	class VertexArray
	{
	public:
		VertexArray(std::shared_ptr<IndexBuffer> index_buffer, std::shared_ptr<VertexBuffer> vertex_buffer);
		~VertexArray();

		void bind(void);
		void unbind(void);
		unsigned int get_index_count(void);

		void attach_index_buffer(std::shared_ptr<IndexBuffer> index_buffer);
		void attach_vertex_buffer(std::shared_ptr<VertexBuffer> vertex_buffer);

		void print(void);

		std::shared_ptr<IndexBuffer> m_index_buffer;
		std::shared_ptr<VertexBuffer> m_vertex_buffer;
		unsigned int m_id, m_index_count;
	private:
	};

	std::shared_ptr<VertexArray> create_vertex_array(std::shared_ptr<IndexBuffer>& index_buffer, std::shared_ptr<VertexBuffer>& vertex_buffer);

}

#endif /* VERTEX_ARRAY_H */
