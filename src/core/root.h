#pragma once

namespace Split
{

	class EventBus;

	class Root
	{
	public:
		static bool start(void);
		static bool quit(void);
		static bool isInitialized(void);
		static EventBus* event_bus(void);

	private:
		static void create_systems(void);
		static void init_systems(void);

		static void quit_systems(void);
		static void cleanup_systems(void);

		static bool initialized;

		// Initialized once
		static EventBus* eventBus;
	};

}
