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

	void Application::init(void)
	{

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

}

