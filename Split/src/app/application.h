#ifndef APPLICATION_H
#define APPLICATION_H

#include "events/event_bus_client.h"

namespace Split
{
	/* Forward declerations
	 */
	class WindowClose;
	class Window;
	class Camera;

	class Application : public EventBusClient
	{
	public:
		Application();
		virtual ~Application();

		virtual bool running(void);
		virtual void init(void);
		virtual void launch(void);
		virtual void run(void);
		virtual void update(void);

		virtual void on_window_close(WindowClose& wc);

	protected:
		std::unique_ptr<Split::Window> m_window;
		std::unique_ptr<Split::Camera> m_camera;

	private:
		bool m_running;
		void event_bus_subscribe(void) override;
	};

	/* client returns application
	 */
	Application* create_application(void);

}

#endif /* APPLICATION_H */
