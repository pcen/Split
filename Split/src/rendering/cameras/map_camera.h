#ifndef MAP_CAMERA_H
#define MAP_CAMERA_H

#include "events/event_bus_client.h"

namespace Split
{

	/* Forward declarations
	 */
	class KeyPress;
	class MouseWindowBorder;
	class WindowResize;
	struct mouse_data;

	class MapCamera : public EventBusListener
	{
	public:
		MapCamera(glm::vec3 position, glm::ivec2 screen_size);
		~MapCamera();

		glm::mat4& get_view_matrix(void);

		void set_sensitivity(float sensitivity);
		void set_speed(float speed);

		void update(double dt);

	private:
		glm::mat4 m_view_matrix;
		glm::vec3 m_position, m_front, m_up;
		glm::ivec2 m_screen_size;
		float m_pitch, m_yaw, m_roll;
		float m_sensitivity, m_speed, m_real_speed;
		bool m_mouse_on_screen;
		int m_move_threshold;

		bool move_in_x(mouse_data& mouse);
		bool move_in_y(mouse_data& mouse);

		void on_window_resize(WindowResize& resize);
		void on_mouse_window_border(MouseWindowBorder& event);
		void on_key_press(KeyPress& key);
		void event_bus_subscribe(void) override;
		void update_view_matrix(void);
	};

}

#endif /* MAP_CAMERA_H */
