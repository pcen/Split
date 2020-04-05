#include "pch.h"
#include "application.h"

namespace Split
{

	Application::Application() : m_running{ false }
	{

	}

	Application::~Application()
	{

	}

	bool Application::running(void)
	{
		return m_running;
	}

	void Application::init(EventBus* bus)
	{
		set_event_bus(bus);
		event_bus_subscribe();
	}

	void Application::launch(void)
	{
		m_running = true;
		run();
	}

	void Application::run(void)
	{
		while (running()) {}
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
