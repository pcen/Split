#include "pch.h"
#include "application.h"

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
		while (running())
		{
			do_something();
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
