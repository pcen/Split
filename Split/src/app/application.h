#ifndef APPLICATION_H
#define APPLICATION_H

#include "display/window.h"
#include "events/window_events.h"
#include "events/event_bus_client.h"

namespace Split
{

	class Application : public EventBusClient
	{
	public:
		Application();
		virtual ~Application();

		virtual bool running(void);
		virtual void init(void);
		virtual void launch(void);
		virtual void run(void);

		virtual void on_window_close(WindowClose& wc);

	private:
		void event_bus_subscribe(void) override;

		Window* m_window;

		bool m_running;
	};

	/* client returns application
	 */
	Application* create_application(void);

}

#endif /* APPLICATION_H */
