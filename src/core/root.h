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
		static EventBus* eventBus(void);

	private:
		static void createSystems(void);
		static void initSystems(void);

		static void quitSystems(void);
		static void cleanupSystems(void);

		static bool initialized;

		// Initialized once
		static EventBus* s_eventBus;
	};

}
