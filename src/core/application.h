#pragma once

#include "events/EventBusClient.h"

namespace Split
{
	/* Forward declarations
	 */
	class WindowClose;  class KeyPress; class Window;  class Camera; class Timer;

	class Application : public EventBusClient
	{
	public:
		Application();
		virtual ~Application();

		virtual void init(void);
		virtual void launch(void);
		virtual void run(void);
		virtual void update(void);
		virtual void set_camera(Camera* camera);

		virtual void on_window_close(WindowClose& wc);
		virtual void on_key_press(KeyPress& key);

	protected:
		std::unique_ptr<Split::Window> m_window;
		std::unique_ptr<Split::Camera> m_camera;
		std::unique_ptr<Split::Timer> m_timer;
		bool m_running;

	private:
		void event_bus_subscribe(void) override;
	};

}
