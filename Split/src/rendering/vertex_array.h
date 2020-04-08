#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "vertex_buffer.h"


namespace Split
{

	class VertexBuffer;
	class IndexBuffer;

	class VertexArray
	{
	public:
		VertexArray();
		VertexArray(IndexBuffer* index_buffer, VertexBuffer* vertex_buffer);
		~VertexArray();

		void bind(void);
		void unbind(void);
		bool is_bound(void);

		void attach_index_buffer(IndexBuffer* index_buffer);
		void attach_vertex_buffer(VertexBuffer* vertex_buffer);

		void print(void);

	private:
		unsigned int m_id;
		bool m_bound;
		IndexBuffer* m_index_buffer;
		VertexBuffer* m_vertex_buffer;
	};

}

#endif /* VERTEX_ARRAY_H */
