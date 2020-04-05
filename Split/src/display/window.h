#ifndef WINDOW_H
#define WINDOW_H

#include "events/event_bus_client.h"

/* Forward declare to avoid glfw header
 */
struct GLFWwindow;

namespace Split
{

	class Window : public EventBusClient
	{
	public:
		Window(int width, int height, std::string title, bool vsync = true, bool cursor = true);
		Window();
		~Window();

		void init(void);
		bool open(void);
		void update(void);
		void capture_cursor(bool capture);
		void use_vsync(bool use);
		float aspect_ratio(void);

	private:
		std::string m_title;
		bool m_open;

		GLFWwindow* m_window;

		int m_width, m_height;
		float m_aspect_ratio;
		bool m_vsync, m_cursor;

		void event_bus_subscribe(void) override;

		friend void mouse_move_callback(GLFWwindow* window, double xpos, double ypos);
		friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void window_size_callback(GLFWwindow* window, int width, int height);
		friend void window_close_callback(GLFWwindow* window);
	};

}

#endif /* WINDOW_H */
