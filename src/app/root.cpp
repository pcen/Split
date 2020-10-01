#include "pch.h"
#include "root.h"

#include "app/application.h"
#include "events/event_bus.h"
#include "input/input.h"
#include "logging/log.h"

namespace Split
{

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

	void Root::run(int argc, char* argv[], Application* app)
	{
		if (m_initialized)
			return;

		Split::Log::init();
		log_info("Root run start");

		create_systems(app);
		init_systems();

		m_initialized = true;
		
		s_application->launch();
		
		cleanup_systems();
	}

	bool Root::is_initialized(void) const
	{
		return m_initialized;
	}

	std::shared_ptr<EventBus> Root::event_bus(void)
	{
		return Root::root_instance->s_event_bus;
	}

	void Root::create_systems(Application* app)
	{
		if (m_initialized) {
			log_warn("Cannot create_systems: Root already initialized");
			return;
		}

		log_info("Creating systems...");
		s_event_bus = std::shared_ptr<EventBus>(new EventBus());
		s_input = std::unique_ptr<Input>(new Input());
		s_application = std::unique_ptr<Application>(app);
		log_info("Systems created");
	}

	void Root::init_systems(void)
	{
		if (m_initialized) {
			log_warn("Cannot init_systems: Root already initialized");
			return;
		}

		log_info("Initializing systems...");
		s_application->init();
		log_info("Systems initialized");
	}

	void Root::cleanup_systems(void)
	{
		if (!m_initialized) {
			log_warn("Cannot cleanup_systems: Root is not initialized");
			return;
		}
	}

}