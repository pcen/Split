#include "pch.h"
#include "application.h"

#include "events/window_events.h"
#include "display/window.h"
#include "rendering/cameras/camera.h"
#include "rendering/buffers/index_buffer.h"
#include "rendering/vertex_array.h"
#include "rendering/buffers/vertex_buffer.h"
#include "rendering/shaders/shader.h"
#include "rendering/renderer.h"
#include "rendering/cameras/camera.h"
#include "utils/geometry/cube.h"

#include "glad/glad.h"

namespace Split
{

	Application::Application() : m_running{ false }, m_window{ nullptr }, m_camera{ nullptr } {}

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
		m_camera = std::unique_ptr<Camera>(new Camera({ 0.0f, 0.0f, 3.0f }));
	}

	void Application::launch(void)
	{
		m_running = true;
		run();
	}

	void Application::run(void)
	{
		while (running())
		{
			update();
		}
	}

	void Application::update(void)
	{
		m_window->update();
		m_camera->update();
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
