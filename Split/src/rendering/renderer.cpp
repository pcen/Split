#include "pch.h"
#include "renderer.h"
#include "rendering/vertex_array.h"
#include "glad/glad.h"

namespace Split
{

	Renderer::Renderer() {}

	Renderer::~Renderer() {}

	void Renderer::clear(void)
	{
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::begin(void)
	{
	
	}

	void Renderer::push(VertexArray* vertex_array)
	{
		draw_indexed_mesh(vertex_array);
	}

	void Renderer::end(void)
	{
	
	}

	void Renderer::draw_indexed_mesh(VertexArray* vertex_array)
	{
		vertex_array->bind();
		glDrawElements(GL_TRIANGLES, vertex_array->get_index_count(), GL_UNSIGNED_INT, nullptr);
	}

}
