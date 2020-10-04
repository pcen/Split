#include "pch.h"
#include "window.h"

#include "events/WindowEvents.h"

#include "glad/glad.h"

namespace Split
{
	Window::Window() : Window(800, 600, "Split Engine") {}

	Window::Window(int width, int height, std::string title, bool cursor)
		: m_width{ width },
		m_height{ height },
		m_title{ title },
		m_aspect_ratio{ (float)width / (float)height },
		m_open{ false },
		m_window{ nullptr },
		m_cursor{ cursor },
		m_mouse()
	{
		int window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;
		m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, window_flags);
		if (m_window == NULL)
			std::cerr << "ERROR: Failed to create window: " << SDL_GetError() << "\n";

		m_open = true;
	}

	Window::~Window()
	{
		std::cerr << "~Window()\n";
		SDL_DestroyWindow(m_window);
	}

	bool Window::open(void) const
	{
		return m_open;
	}

	void Window::update(double dt)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				m_open = false;
				break;
			default:
				break;
			}
		}
	}

	void Window::display(void)
	{
	
	}

	void Window::capture_cursor(bool capture)
	{
		SDL_SetRelativeMouseMode(capture ? SDL_TRUE : SDL_FALSE);
	}

	float Window::aspect_ratio(void)
	{
		return m_aspect_ratio;
	}

	bool Window::mouse_on_screen(void)
	{
		return m_mouse_on_screen;
	}

}
