#ifndef ROOT_H
#define ROOT_H

namespace Split
{

	/* Forward declarations
	 */
	class Application;
	class EventBus;

	class Root
	{
	public:
		~Root();
		static Root* get_root(void);
		void run(int argc, char* argv[]);
		
		/* Access to single event bus
		 */
		static EventBus* event_bus(void);

	private:
		static Root* root;
		Root();

		void create_systems(void);
		void init_systems(void);
		void cleanup_systems(void);

		bool m_initialized = false;

		Application* s_application = nullptr;
		EventBus* s_event_bus      = nullptr;
	};

}

#endif /* ROOT_H */
