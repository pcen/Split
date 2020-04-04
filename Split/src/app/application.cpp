#include "pch.h"
#include "application.h"

namespace Split
{

	Application::Application() : app_running{ false }
	{

	}

	Application::~Application()
	{

	}

	bool Application::running(void)
	{
		return app_running;
	}

	void Application::init(void)
	{

	}

	void Application::launch(void)
	{
		app_running = true;
		run();
	}

	void Application::run(void)
	{
		while (running()) {}
	}

}

