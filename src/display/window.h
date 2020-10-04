#pragma once

#include "events/EventBusClient.h"
#include "input/mouse_data.h"

namespace Split
{

	class Window : public EventBusClient
	{
	public:
		Window(int width, int height, std::string title, bool cursor = true);
		Window();
		~Window();

		bool open(void) const;
		void update(double dt);
		void display(void);
		
		void capture_cursor(bool capture);

		float aspect_ratio(void);
		bool mouse_on_screen(void);

	private:
		SDL_Window* m_window;

		std::string m_title;
		bool m_open;

		mouse_data m_mouse;

		int m_width, m_height;
		float m_aspect_ratio;
		bool m_cursor;
		bool m_mouse_on_screen;
	};

}
