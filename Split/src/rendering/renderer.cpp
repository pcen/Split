#include "pch.h"
#include "renderer.h"
#include "rendering/vertex_array.h"
#include "glad/glad.h"

#define expand_colour(v) (v).x, (v).y, (v).z, 1.0f

namespace Split
{

	void draw_indexed_mesh(VertexArray* vertex_array)
	{
		vertex_array->bind();
		glDrawElements(GL_TRIANGLES, vertex_array->get_index_count(), GL_UNSIGNED_INT, nullptr);
	}

	void draw_indexed_mesh(std::shared_ptr<VertexArray>& vertex_array)
	{
		vertex_array->bind();
		glDrawElements(GL_TRIANGLES, vertex_array->get_index_count(), GL_UNSIGNED_INT, nullptr);
	}

	Renderer::Renderer() : m_clear_colour(1.0f, 0.0f, 1.0f)
	{
		use_depth_testing(true);
		use_backface_culling(true);
	}

	Renderer::~Renderer() {}

	void Renderer::clear(void)
	{
		glClearColor(expand_colour(m_clear_colour));
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::set_clear_colour(glm::vec3 colour)
	{
		m_clear_colour = colour;
	}

	void Renderer::begin(void)
	{
	
	}

	void Renderer::push(VertexArray* vertex_array)
	{
		draw_indexed_mesh(vertex_array);
	}

	void Renderer::push(std::shared_ptr<VertexArray>& vertex_array)
	{
		draw_indexed_mesh(vertex_array);
	}

	void Renderer::end(void)
	{
	
	}

	void Renderer::use_wireframe(bool use)
	{
		glPolygonMode(GL_FRONT_AND_BACK, use ? GL_LINE : GL_FILL);
	}

	void Renderer::use_backface_culling(bool use)
	{
		if (use) {
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
			glFrontFace(GL_CW);
		}
		else {
			glDisable(GL_CULL_FACE);
		}
	}

	void Renderer::use_depth_testing(bool use)
	{
		if (use)
			glEnable(GL_DEPTH_TEST);
		else
			glDisable(GL_DEPTH_TEST);
	}

}
