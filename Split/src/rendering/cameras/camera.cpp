#include "pch.h"
#include "camera.h"
#include "events/window_events.h"
#include "events/event_bus_client.h"
#include "GLFW/glfw3.h"

#define normalized_x(v1, v2) (glm::normalize(glm::cross((v1), (v2))))

namespace Split
{

	enum class direction {
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT,
		UP,
		DOWN,
		NONE
	};

	Camera::Camera(glm::vec3 position) : m_position{ position }
	{
		m_front = glm::vec3(0.0f, 0.0f, -1.0f);
		m_up = glm::vec3(0.0f, 1.0f, 0.0f);
		m_speed = 4.0f;
		m_sensitivity = 0.02f;
		m_yaw = -90.0f;
		m_pitch = 0.0f;
		m_roll = 0.0f;
		update_view_matrix();
		event_bus_subscribe();
	}

	Camera::~Camera()
	{
		
	}
	
	void Camera::event_bus_subscribe(void)
	{
		callback_subscribe(&Camera::on_mouse_move);
		callback_subscribe(&Camera::on_keyboard_press);
	}

	glm::mat4 Camera::get_view_matrix(void)
	{
		return m_view_matrix;
	}

	void Camera::set_sensitivity(float sensitivity)
	{
		m_sensitivity = sensitivity;
	}

	void Camera::set_speed(float speed)
	{
		m_speed = speed;
	}

	void Camera::update_view_matrix(void)
	{
		m_view_matrix = glm::lookAt(m_position, m_position + m_front, m_up);
	}

	void Camera::on_keyboard_press(KeyPress& key_press)
	{
		switch (key_to_direction(key_press.keycode())) {
		case direction::FORWARD:
			m_position += m_front * m_speed;
			break;
		case direction::BACKWARD:
			m_position -= m_front * m_speed;
			break;
		case direction::LEFT:
			m_position -= normalized_x(m_front, m_up) * m_speed;
			break;
		case direction::RIGHT:
			m_position += normalized_x(m_front, m_up) * m_speed;
			break;
		case direction::UP:
			m_position += normalized_x(normalized_x(m_front, m_up), m_front) * m_speed;
			break;
		case direction::DOWN:
			m_position -= normalized_x(normalized_x(m_front, m_up), m_front) * m_speed;
			break;
		case direction::NONE:
			/* don't update view matrix */
			return;
		}
		update_view_matrix();
	}

	void Camera::on_mouse_move(MouseMove& mouse)
	{
		std::cerr << "mouse move\n";
		std::cerr << "dx: " << mouse.dx() << ", " << mouse.dy() << "\n";
		m_yaw += mouse.dx();
		m_pitch += mouse.dy();

		if (m_pitch > 89.0f)
			m_pitch = 89.0f;
		else if (m_pitch < -89.0f)
			m_pitch = -89.0f;

		m_front.x = std::cos(glm::radians(m_yaw)) * std::cos(glm::radians(m_pitch));
		m_front.y = std::sin(glm::radians(m_pitch));
		m_front.z = std::sin(glm::radians(m_yaw)) * std::cos(glm::radians(m_pitch));
		m_front = glm::normalize(m_front);
		update_view_matrix();
	}

	direction Camera::key_to_direction(int key)
	{
		switch (key) {
		case GLFW_KEY_W:
			return direction::FORWARD;
		case GLFW_KEY_S:
			return direction::BACKWARD;
		case GLFW_KEY_A:
			return direction::LEFT;
		case GLFW_KEY_D:
			return direction::RIGHT;
		case GLFW_KEY_SPACE:
			return direction::UP;
		case GLFW_KEY_LEFT_SHIFT:
			return direction::DOWN;
		default:
			return direction::NONE;
		}
	}

}
