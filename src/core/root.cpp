#include "pch.h"
#include "root.h"

#include "events/event_bus.h"
#include "log.h"

namespace Split
{
	// Static data members
	EventBus* Root::eventBus = nullptr;
	bool Root::initialized = false;

	bool Root::start(void)
	{
		if (Root::initialized) {
			log_warn("Root::init: Root already initialized");
			return false;
		}

		Split::Log::init();

		create_systems();
		init_systems();

		Root::initialized = true;
		return true;
	}

	bool Root::quit(void)
	{
		if (!Root::initialized) {
			log_warn("Root::quit: Root not initialized");
			return false;
		}

		quit_systems();
		cleanup_systems();
		Root::initialized = false;
	}

	bool Root::isInitialized(void)
	{
		return Root::initialized;
	}

	EventBus* Root::event_bus(void)
	{
		return Root::eventBus;
	}

	void Root::create_systems(void)
	{
		log_info("Creating systems");
		Root::eventBus = new EventBus();
		log_info("Systems created");
	}

	void Root::init_systems(void)
	{
		log_info("Initializing systems");
		SDL_Init(SDL_INIT_EVERYTHING);
		log_info("Systems initialized");
	}

	void Root::quit_systems(void)
	{
		log_info("Quitting systems");
		SDL_Quit();
	}

	void Root::cleanup_systems(void)
	{
		log_info("Cleaning up systems");
		delete Root::eventBus;
	}

}
