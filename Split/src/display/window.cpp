#include "pch.h"
#include "window.h"

#include "events/window_events.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Split
{

	Window::Window(int width, int height, std::string title, bool vsync, bool cursor)
		: m_width{ width }, m_height{ height }, m_title{ title }, m_aspect_ratio{ (float)width / (float)height },
		m_open{ false }, m_window{ nullptr }, m_vsync{ vsync }, m_cursor{ cursor }
	{
		
	}

	Window::Window() : Window(800, 600, "Split Engine") {}

	Window::~Window() {}

	void Window::init(void)
	{
		if (glfwInit() == GLFW_FALSE)
			std::cerr << "glfw init failed.\n";

		m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
		if (!m_window) {
			glfwTerminate();
			std::cerr << "glfw failed to create window.\n";
		}
		glfwMakeContextCurrent(m_window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			std::cerr << "gladLoadGLLoader failed.\n";

		glfwSetWindowUserPointer(m_window, this);
		glfwSetCursorPosCallback(m_window, mouse_move_callback);
		glfwSetMouseButtonCallback(m_window, mouse_button_callback);
		glfwSetScrollCallback(m_window, scroll_callback);
		glfwSetKeyCallback(m_window, key_callback);
		glfwSetWindowSizeCallback(m_window, window_size_callback);
		glfwSetWindowCloseCallback(m_window, window_close_callback);

		use_vsync(m_vsync);
		capture_cursor(!m_cursor);

		glViewport(0, 0, m_width, m_height);

		m_open = true;
	}

	bool Window::open(void)
	{
		return m_open;
	}

	void Window::update(void)
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	void Window::capture_cursor(bool capture)
	{
		glfwSetInputMode(m_window, GLFW_CURSOR, capture ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
	}

	void Window::use_vsync(bool use)
	{
		glfwSwapInterval(use ? 1 : 0);
	}

	float Window::aspect_ratio(void)
	{
		return m_aspect_ratio;
	}

	void Window::event_bus_subscribe(void)
	{
	
	}

	/* GLFW callback functions
	 */
	static void mouse_move_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* user = (Window*)glfwGetWindowUserPointer(window);
		user->m_mouse.update(xpos, ypos);
		user->post_event(MouseMove(user->m_mouse));
	}

	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* user = (Window*)glfwGetWindowUserPointer(window);
		switch (action) {
		case GLFW_PRESS:
			user->post_event(MousePress(button));
			break;
		case GLFW_RELEASE:
			user->post_event(MouseRelease(button));
			break;
		default:
			break;
		}
	}

	void scroll_callback(GLFWwindow* window, double dx, double dy)
	{
		Window* user = (Window*)glfwGetWindowUserPointer(window);
		user->post_event(MouseScroll((float)dx, (float)dy));
	}

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* user = (Window*)glfwGetWindowUserPointer(window);
		switch (action) {
		case GLFW_PRESS:
			user->post_event(KeyPress(key));
			break;
		case GLFW_REPEAT:
			user->post_event(KeyRepeat(key));
			break;
		case GLFW_RELEASE:
			user->post_event(KeyRelease(key));
			break;
		default:
			break;
		}
	}

	static void window_size_callback(GLFWwindow* window, int width, int height)
	{
		Window* user = (Window*)glfwGetWindowUserPointer(window);
		user->m_width = width;
		user->m_height = height;
		user->m_aspect_ratio = (float)width / (float)height;
		glViewport(0, 0, width, height);
		user->post_event(WindowResize(width, height));
	}

	static void window_close_callback(GLFWwindow* window)
	{
		Window* user = (Window*)glfwGetWindowUserPointer(window);
		user->m_open = false;
		user->post_event(WindowClose());
	}

}
