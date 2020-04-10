#include "pch.h"
#include "application.h"

#include "rendering/buffers/index_buffer.h"
#include "rendering/vertex_array.h"
#include "rendering/buffers/vertex_buffer.h"
#include "rendering/shaders/shader.h"
#include "rendering/renderer.h"
#include "rendering/cameras/camera.h"

#include "glad/glad.h"

namespace Split
{

	Application::Application() : m_running{ false }, m_window{ nullptr } {}

	Application::~Application() {}

	bool Application::running(void)
	{
		return m_running;
	}

	void Application::init(void)
	{
		event_bus_subscribe();
		m_window = std::unique_ptr<Window>(new Window());
		m_window->init();
	}

	void Application::launch(void)
	{
		m_running = true;
		run();
	}

	void Application::run(void)
	{
		m_window->capture_cursor(true);
		Camera cam({ 0.0f,0.0f,-10.0f });

		glm::mat4 proj = glm::perspective(glm::radians(45.0f), m_window->aspect_ratio(), 0.1f, 100.0f);
		unsigned int indeces[3] = {
			0, 1, 2
		};
		float verts[3 * 3] = {
			-5.0f, -5.0f, -1.0f,
			 5.0f, -0.5f, -1.0f,
			 0.0f,  5.0f, -1.0f
		};
		Split::Shader sh("C:\\cygwin64\\home\\Paul\\Dev\\Split\\Split\\src\\resources\\vert.glsl",
						 "C:\\cygwin64\\home\\Paul\\Dev\\Split\\Split\\src\\resources\\pixel.glsl");
		sh.bind();
		sh.set_uniform_mat4f("u_MVP", glm::mat4(1));


		Split::VertexBuffer vb(verts, 3 * 3, GL_STATIC_DRAW);
		vb.attributes = { {"points", 3 } };

		Split::IndexBuffer ib(indeces, 3, GL_STATIC_DRAW);

		Split::VertexArray va(&ib, &vb);

		Split::Renderer r;

		while (running())
		{
			glm::mat4 mvp = proj * cam.get_view_matrix();
			r.clear();
			sh.set_uniform_mat4f("u_MVP", mvp);
			r.push(&va);
			cam.update();
			m_window->update();
		}
	}

	void Application::on_window_close(WindowClose& wc)
	{
		m_running = false;
	}

	void Application::event_bus_subscribe(void)
	{
		callback_subscribe(&Application::on_window_close);
	}

}
