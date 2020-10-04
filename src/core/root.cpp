#include "pch.h"
#include "root.h"

#include "events/EventBus.h"
#include "log.h"

namespace Split
{
	// Static data members
	EventBus* Root::s_eventBus = nullptr;
	bool Root::initialized = false;

	bool Root::start(void)
	{
		if (Root::initialized) {
			log_warn("Root::init: Root already initialized");
			return false;
		}

		Split::Log::init();

		createSystems();
		initSystems();

		Root::initialized = true;
		return true;
	}

	bool Root::quit(void)
	{
		if (!Root::initialized) {
			log_warn("Root::quit: Root not initialized");
			return false;
		}

		quitSystems();
		cleanupSystems();
		Root::initialized = false;
		return true;
	}

	bool Root::isInitialized(void)
	{
		return Root::initialized;
	}

	EventBus* Root::eventBus(void)
	{
		return Root::s_eventBus;
	}

	void Root::createSystems(void)
	{
		log_info("Creating systems");
		
		Root::s_eventBus = new EventBus();

		log_info("Systems created");
	}

	void Root::initSystems(void)
	{
		log_info("Initializing systems");
		
		SDL_Init(SDL_INIT_EVERYTHING);
		
		log_info("Systems initialized");
	}

	void Root::quitSystems(void)
	{
		log_info("Quitting systems");
		
		SDL_Quit();

		log_info("Systems quit");
	}

	void Root::cleanupSystems(void)
	{
		log_info("Cleaning up systems");

		delete Root::s_eventBus;

		log_info("Systems cleaned up");
	}

}
