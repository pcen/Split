#include "pch.h"
#include "root.h"

#include "app/application.h"
#include "events/event_bus.h"
#include "input/input.h"

namespace Split
{
	extern Split::Application* create_application(void);

	Root* Root::root_instance = nullptr;

	Root::Root() {}

	Root::~Root()
	{
		Root::root_instance = nullptr;
	}

	Root* Root::get_root(void)
	{
		if (Root::root_instance == nullptr)
			Root::root_instance = new Root();
		return Root::root_instance;
	}

	void Root::run(int argc, char* argv[])
	{
		if (m_initialized)
			return;

		create_systems();
		init_systems();

		m_initialized = true;
		
		s_application->launch();
		
		cleanup_systems();
	}

	std::shared_ptr<EventBus> Root::event_bus(void)
	{
		return Root::root_instance->s_event_bus;
	}

	void Root::create_systems(void)
	{
		if (m_initialized)
			return;

		s_event_bus = std::shared_ptr<EventBus>(new EventBus());
		s_input = std::unique_ptr<Input>(new Input());
		s_application = std::unique_ptr<Application>(create_application());
	}

	void Root::init_systems(void)
	{
		if (m_initialized)
			return;

		s_application->init();
	}

	void Root::cleanup_systems(void)
	{
		if (!m_initialized)
			return;
	}

}
