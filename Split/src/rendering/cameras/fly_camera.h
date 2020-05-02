#ifndef FLY_CAMERA_H
#define FLY_CAMERA_H

#include "events/event_bus_client.h"
#include "camera.h"

namespace Split
{
	/* Forward declarations
	 */
	class KeyPress;
	class MouseMove;

	enum class direction;

	class FlyCamera : public Camera, public EventBusListener
	{
	public:
		FlyCamera(glm::vec3 position);
		~FlyCamera();

		glm::mat4& get_view_matrix(void) override;

		void set_sensitivity(float sensitivity);
		void set_speed(float speed);

		void update(double dt) override;

		void on_mouse_move(MouseMove& mouse);

	private:
		glm::mat4 m_view_matrix;
		glm::vec3 m_position, m_front, m_up;
		float m_pitch, m_yaw, m_roll;
		float m_sensitivity, m_speed, m_real_speed;

		void keyboard_move(direction move);
		void event_bus_subscribe(void) override;
		void update_view_matrix(void);
	};

}

#endif /* FLY_CAMERA_H */
