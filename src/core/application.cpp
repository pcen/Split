#include "pch.h"
#include "application.h"

#include "events/WindowEvents.h"
#include "display/window.h"
#include "rendering/cameras/camera.h"
#include "rendering/cameras/fly_camera.h"
#include "input/KeyCodes.h"
#include "time.h"

namespace Split
{
	Application::Application() : m_running{ false }, m_window{ nullptr }, m_camera{ nullptr } {}

	Application::~Application() {}

	void Application::init(void)
	{
		event_bus_subscribe();
		m_window = std::unique_ptr<Window>(new Window());
		m_camera = std::unique_ptr<Camera>();
		m_timer = std::unique_ptr<Timer>(new Timer());
	}

	void Application::launch(void)
	{
		m_running = true;
		run();
	}

	void Application::run(void)
	{
		while (m_running)
		{
			update();
		}
	}

	void Application::update(void)
	{
		// m_timer->update_deltatime();
		m_window->update(0.0);
		m_camera->update(0.0);
	}

	void Application::set_camera(Camera* camera)
	{
		m_camera.reset(camera);
	}

	void Application::on_window_close(WindowClose& wc)
	{
		m_running = false;
	}

	void Application::on_key_press(KeyPress& key)
	{
		if (key.keycode() == KEY_ESCAPE)
			m_running = false;
	}

	void Application::event_bus_subscribe(void)
	{
		callback_subscribe(&Application::on_window_close);
		callback_subscribe(&Application::on_key_press);
	}

}
