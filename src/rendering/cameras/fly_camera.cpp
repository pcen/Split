#include "pch.h"
#include "fly_camera.h"
#include "events/window_events.h"
#include "events/event_bus_client.h"
#include "input/input.h"

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

	FlyCamera::FlyCamera(glm::vec3 position)
		: m_position{ position }, m_front{ glm::vec3(0.0f, 0.0f, -1.0f) },
		m_up{ glm::vec3(0.0f, 1.0f, 0.0f) }
	{
		m_speed = 6.0f;
		m_sensitivity = 0.5f;
		m_yaw = -90.0f; m_pitch = 0.0f; m_roll = 0.0f;
		m_real_speed = 0.0f;
		update_view_matrix();
		event_bus_subscribe();
	}

	FlyCamera::~FlyCamera() {}
	
	void FlyCamera::event_bus_subscribe(void)
	{
		callback_subscribe(&FlyCamera::on_mouse_move);
	}

	glm::mat4& FlyCamera::get_matrix(void) { return m_view_matrix; }

	void FlyCamera::set_sensitivity(float sensitivity) { m_sensitivity = sensitivity; }

	void FlyCamera::set_speed(float speed) { m_speed = speed; }

	void FlyCamera::update(double dt)
	{
		m_real_speed = m_speed * (float)dt;
		if (Input::key_pressed(KEY_W))
			keyboard_move(direction::FORWARD);
		if (Input::key_pressed(KEY_S))
			keyboard_move(direction::BACKWARD);
		if (Input::key_pressed(KEY_A))
			keyboard_move(direction::LEFT);
		if (Input::key_pressed(KEY_D))
			keyboard_move(direction::RIGHT);
		if (Input::key_pressed(KEY_LSHIFT));
			keyboard_move(direction::DOWN);
		if (Input::key_pressed(KEY_SPACE))
			keyboard_move(direction::UP);
	}

	void FlyCamera::update_view_matrix(void)
	{
		m_view_matrix = glm::lookAt(m_position, m_position + m_front, m_up);
	}

	void FlyCamera::on_mouse_move(MouseMove& mouse)
	{
		m_yaw += mouse.dx() * m_sensitivity;
		m_pitch += mouse.dy() * m_sensitivity;

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

	void FlyCamera::keyboard_move(direction move)
	{
		switch (move) {
		case direction::FORWARD:
			m_position += m_front * m_real_speed;
			break;
		case direction::BACKWARD:
			m_position -= m_front * m_real_speed;
			break;
		case direction::LEFT:
			m_position -= normalized_x(m_front, m_up) * m_real_speed;
			break;
		case direction::RIGHT:
			m_position += normalized_x(m_front, m_up) * m_real_speed;
			break;
		case direction::UP:
			m_position += normalized_x(normalized_x(m_front, m_up), m_front) * m_real_speed;
			break;
		case direction::DOWN:
			m_position -= normalized_x(normalized_x(m_front, m_up), m_front) * m_real_speed;
			break;
		case direction::NONE:
		default:
			/* don't update view matrix */
			return;
			break;
		}
		update_view_matrix();
	}

}
