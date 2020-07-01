#ifndef RENDERER_H
#define RENDERER_H

#include "rendering/vertex_array.h"
#include "rendering/shaders/shader.h"

namespace Split
{

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void clear(void);
		void set_clear_colour(glm::vec3 colour);

		void begin(glm::mat4 view_matrix);
		void push(std::shared_ptr<Shader>& shader, std::shared_ptr<VertexArray>& vertex_array, glm::mat4& transform = glm::mat4(1.0f));
		void end(void);

		void use_wireframe(bool use);
		void use_backface_culling(bool use);
		void use_depth_testing(bool use);

	private:
		glm::vec3 m_clear_colour;
		glm::mat4 m_view_matrix;
	};

}

#endif /* RENDERER_H */
