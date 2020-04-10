#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

namespace Split
{

	class IndexBuffer
	{
	public:
		IndexBuffer(unsigned int* buffer, unsigned int count, unsigned int mode);
		~IndexBuffer();

		void bind(void);
		void unbind(void);
		int get_count(void);
		bool is_bound(void);
		unsigned int get_id(void);
		std::vector<unsigned int>& data(void);

		void print(void);

	private:
		unsigned int m_id, m_count;
		bool m_bound;
		std::vector<unsigned int> m_data;
	};

	std::shared_ptr<IndexBuffer> create_index_buffer(unsigned int* buffer, unsigned int count, unsigned int mode);
}

#endif /* INDEX_BUFFER_H */
