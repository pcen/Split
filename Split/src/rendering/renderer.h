#ifndef RENDERER_H
#define RENDERER_H

namespace Split
{
	class VertexArray;

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void clear(void);

		void begin(void);
		void push(VertexArray* vertex_array);
		void end(void);

	private:
		void draw_indexed_mesh(VertexArray* vertex_array);
	};

}

#endif /* RENDERER_H */
