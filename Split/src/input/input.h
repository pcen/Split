#ifndef INPUT_H
#define INPUT_H

#include "events/event_bus_client.h"
#include "events/window_events.h"
#include "mouse_data.h"

namespace Split
{

	class Input : public EventBusClient
	{
		friend class Root;
	public:
		static bool key_pressed(int key);
		static float mouse_x(void);
		static float mouse_y(void);
		static mouse_data get_mouse(void);
		~Input();

	private:
		Input();
		void on_key_press(KeyPress& key_event);
		void on_key_release(KeyRelease& key_event);
		void on_mouse_move(MouseMove& mouse_event);

		void event_bus_subscribe(void) override;
	};

}

#endif /* INPUT_H */
