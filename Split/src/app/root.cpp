#include "pch.h"
#include "root.h"

#include "app/application.h"
#include "events/event_bus.h"

namespace Split
{
	extern Split::Application* create_application(void);

	Root* Root::root = nullptr;

	Root::Root() {}

	Root::~Root() {}

	Root* Root::get_root(void)
	{
		if (Root::root == nullptr)
			Root::root = new Root();
		return Root::root;
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

	EventBus* Root::event_bus(void)
	{
		return Root::root->s_event_bus;
	}

	void Root::create_systems(void)
	{
		if (m_initialized)
			return;

		s_event_bus = new EventBus();
		s_application = create_application();
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

		delete s_application;
		delete s_event_bus;
	}

}
