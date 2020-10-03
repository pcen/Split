#pragma once

#include "event.h"
#include "input/mouse_data.h"

namespace Split
{

	/* Window events
	 */
	class WindowResize : public Event
	{
	public:
		WindowResize(unsigned int width, unsigned int height)
			: m_width{ width }, m_height{ height } {}
		~WindowResize() {}

		inline unsigned int width(void) { return m_width; }
		inline unsigned int height(void) { return m_height; }
		inline glm::ivec2 dimensions(void) { return { (int)m_width, (int)m_height }; }

		inline std::string str(void) const override
		{
			std::stringstream ss;
			ss << "Window Resize (" << m_width << ", " << m_height << ")";
			return ss.str();
		}

		EVENT_TYPE_METHODS(WINDOW_RESIZE)

	private:
		unsigned int m_width, m_height;
	};

	class WindowClose : public Event
	{
	public:
		WindowClose() {}
		~WindowClose() {}

		inline std::string str(void) const override { return "Window Close"; }
		EVENT_TYPE_METHODS(WINDOW_CLOSE)
	};

	class MouseWindowBorder : public Event
	{
	public:
		MouseWindowBorder(bool entered) : m_entered{entered} {}
		~MouseWindowBorder() {}

		inline bool entered(void) { return m_entered; }

		inline std::string str(void) const override
		{
			std::stringstream ss;
			ss << "Mouse Window Border: entered = " << (m_entered ? "true" : "false");
			return ss.str();
		}

		EVENT_TYPE_METHODS(MOUSE_WINDOW_BORDER)
	private:
		bool m_entered;
	};

	/* Keyboard generated events
	 */
	class KeyPress : public Event
	{
	public:
		KeyPress(int keycode, bool repeat) : m_keycode{ keycode }, m_repeat{ repeat } {}
		~KeyPress() {}

		inline int keycode(void) { return m_keycode; }
		inline int is_repeat(void) { return m_repeat; }

		inline std::string str(void) const override { return "Key Press"; }
		EVENT_TYPE_METHODS(KEY_PRESS)

	private:
		int m_keycode;
		bool m_repeat;
	};

	class KeyRelease : public Event
	{
	public:
		KeyRelease(int keycode) :m_keycode{ keycode } {}
		~KeyRelease() {}

		inline int keycode(void) { return m_keycode; }

		inline std::string str(void) const override { return "Key Release"; }
		EVENT_TYPE_METHODS(KEY_RELEASE)

	private:
		int m_keycode;
	};

	/* Mouse generated events
	 */
	class MouseMove : public Event
	{
	public:
		MouseMove(float x, float y, float dx, float dy)
			: m_x{ x }, m_y{ y }, m_dx{ dx }, m_dy{ dy } {}
		MouseMove(mouse_data mouse)
			: m_x{ mouse.x }, m_y{ mouse.y }, m_dx{ mouse.dx }, m_dy{ mouse.dy } {}
		~MouseMove() {}

		inline float x(void) { return m_x; }
		inline float y(void) { return m_y; }
		inline float dx(void) { return m_dx; }
		inline float dy(void) { return m_dy; }

		inline std::string str(void) const override {
			std::stringstream ss;
			ss << "Mouse Move (" << m_x << ", " << m_y << ")";
			return ss.str();
		}

		EVENT_TYPE_METHODS(MOUSE_MOVE)

	private:
		float m_x, m_y, m_dx, m_dy;
	};

	class MousePress : public Event
	{
	public:
		MousePress(int button) : m_button{ button } {}
		~MousePress() {}

		inline int button(void) { return m_button; }

		inline std::string str(void) const override
		{
			std::stringstream ss;
			ss << "Mouse Press: " << m_button;
			return ss.str();
		}

		EVENT_TYPE_METHODS(MOUSE_PRESS)

	private:
		int m_button;
	};

	class MouseRelease : public Event
	{
	public:
		MouseRelease(int button) : m_button{ button } {}
		~MouseRelease() {}

		inline int button(void) { return m_button; }

		inline std::string str(void) const override
		{
			std::stringstream ss;
			ss << "Mouse Release: " << m_button;
			return ss.str();
		}

		EVENT_TYPE_METHODS(MOUSE_RELEASE)

	private:
		int m_button;
	};

	class MouseScroll : public Event
	{
	public:
		MouseScroll(float dx, float dy) : m_dx{ dx }, m_dy{ dy } {}
		~MouseScroll() {}

		inline float dx(void) { return m_dx; }
		inline float dy(void) { return m_dy; }

		inline std::string str(void) const override
		{
			std::stringstream ss;
			ss << "Mouse Scroll: dx = " << m_dx << ", dy = " << m_dy;
			return ss.str();
		}

		EVENT_TYPE_METHODS(MOUSE_SCROLL)

	private:
		float m_dx, m_dy;
	};

}
