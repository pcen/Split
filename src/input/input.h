#pragma once

#include "events/EventBusClient.h"
#include "KeyCodes.h"

namespace Split
{
	class KeyPress;
	class KeyRelease;
	class MouseMove;

	struct Mouse
	{
	public:
		Mouse();
		float x, y, dx, dy;
		void update(double xpos, double ypos);
	private:
		bool initialized;
	};

	class Input : public EventBusClient
	{
		friend class Root;
	public:
		static bool key(int key);
		static Mouse mouse(void);

		~Input();

	private:
		Input();

		static Mouse s_mouse;
		static bool s_keyboard[512];

		void on_key_press(KeyPress& key_event);
		void on_key_release(KeyRelease& key_event);
		void on_mouse_move(MouseMove& mouse_event);

		void eventBusSubscribe(void) override;
	};

}
