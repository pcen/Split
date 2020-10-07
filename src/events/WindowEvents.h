#pragma once

#include "event.h"
#include "input/Input.h"

namespace Split
{

	class WindowResize : public Event
	{
	public:
		WindowResize(unsigned int width, unsigned int height)
			: m_width{ width },
			m_height{ height }
		{}
		~WindowResize() {}

		unsigned int width(void) { return m_width; }
		unsigned int height(void) { return m_height; }
		glm::ivec2 dimensions(void) { return { (int)m_width, (int)m_height }; }

		NAME_EVENT("WindowResize")

	private:
		unsigned int m_width, m_height;
	};

	class WindowClose : public Event
	{
	public:
		WindowClose() {}
		~WindowClose() {}

		NAME_EVENT("WindowClose")
	};

	class MouseWindowBorder : public Event
	{
	public:
		MouseWindowBorder(bool entered)
			: m_entered{entered}
		{}
		~MouseWindowBorder() {}

		bool entered(void) { return m_entered; }

		NAME_EVENT("MouseWindowBorder")

	private:
		bool m_entered;
	};

	class KeyPress : public Event
	{
	public:
		KeyPress(int keycode, bool repeat)
			: m_keycode{ keycode },
			m_repeat{ repeat }
		{}
		~KeyPress() {}

		int keycode(void) { return m_keycode; }
		int is_repeat(void) { return m_repeat; }

		NAME_EVENT("KeyPress")

	private:
		int m_keycode;
		bool m_repeat;
	};

	class KeyRelease : public Event
	{
	public:
		KeyRelease(int keycode)
			: m_keycode{ keycode }
		{}
		~KeyRelease() {}

		int keycode(void) { return m_keycode; }

		NAME_EVENT("KeyRelease")

	private:
		int m_keycode;
	};

	class MouseMove : public Event
	{
	public:
		MouseMove(float x, float y, float dx, float dy)
			: m_x{ x },
			m_y{ y },
			m_dx{ dx },
			m_dy{ dy }
		{}
		MouseMove(Mouse mouse)
			: m_x{ mouse.x },
			m_y{ mouse.y },
			m_dx{ mouse.dx },
			m_dy{ mouse.dy }
		{}
		~MouseMove() {}

		float x(void) { return m_x; }
		float y(void) { return m_y; }
		float dx(void) { return m_dx; }
		float dy(void) { return m_dy; }

		NAME_EVENT("MouseMove")

	private:
		float m_x, m_y, m_dx, m_dy;
	};

	class MousePress : public Event
	{
	public:
		MousePress(int button)
			: m_button{ button }
		{}
		~MousePress() {}

		int button(void) { return m_button; }

		NAME_EVENT("MousePress")

	private:
		int m_button;
	};

	class MouseRelease : public Event
	{
	public:
		MouseRelease(int button)
			: m_button{ button }
		{}
		~MouseRelease() {}

		int button(void) { return m_button; }

		NAME_EVENT("MouseRelease")

	private:
		int m_button;
	};

	class MouseScroll : public Event
	{
	public:
		MouseScroll(float dx, float dy)
			: m_dx{ dx },
			m_dy{ dy }
		{}
		~MouseScroll() {}

		float dx(void) { return m_dx; }
		float dy(void) { return m_dy; }

		NAME_EVENT("MouseScroll")

	private:
		float m_dx, m_dy;
	};

}
