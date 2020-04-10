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
		void set_clear_colour(glm::vec3 colour);

		void begin(void);
		void push(VertexArray* vertex_array);
		void push(std::shared_ptr<VertexArray>& vertex_array);
		void end(void);

		void use_wireframe(bool use);
		void use_backface_culling(bool use);
		void use_depth_testing(bool use);

	private:
		glm::vec3 m_clear_colour;
	};

}

#endif /* RENDERER_H */
