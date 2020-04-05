#include "pch.h"
#include "root.h"

#include "app/application.h"
#include "events/event_bus.h"

namespace Split
{
	extern Split::Application* create_application(void);
	
	static bool root_initialized      = false;

	static Application* s_application = nullptr;
	static EventBus* s_event_bus      = nullptr;

	void Root::init(int argc, char* argv[])
	{
		if (root_initialized)
			return;

		create_systems();
		init_systems();
		root_initialized = true;
		s_application->launch();
		cleanup_systems();

	}

	void Root::create_systems(void)
	{
		if (root_initialized)
			return;

		s_event_bus = new EventBus();
		s_application = create_application();
	}

	void Root::init_systems(void)
	{
		if (root_initialized)
			return;

		s_application->init(s_event_bus);
	}

	void Root::cleanup_systems(void)
	{
		if (!root_initialized)
			return;

		delete s_application;
		delete s_event_bus;
	}

}