#ifndef ROOT_H
#define ROOT_H

namespace Split
{

	/* Forward declarations
	 */
	class Application;
	class EventBus;
	class Input;

	class Root
	{
	public:
		~Root();
		static Root* get_root(void);
		void run(int argc, char* argv[]);

		/* Access to single event bus
		 */
		static std::shared_ptr<EventBus> event_bus(void);

	private:
		static Root* root_instance;
		Root();

		void create_systems(void);
		void init_systems(void);
		void cleanup_systems(void);

		bool m_initialized = false;

		/* Initialized by Root class at engine entry
		 */
		std::unique_ptr<Application> s_application;
		std::shared_ptr<EventBus>    s_event_bus;
		std::unique_ptr<Input>       s_input;
	};

}

#endif /* ROOT_H */
