#include "pch.h"
#include "input.h"

namespace Split
{

	static bool keyboard[512];
	static mouse_data mouse;

	Input::Input()
	{
		event_bus_subscribe();
	}

	Input::~Input() {}

	void Input::event_bus_subscribe(void)
	{
		callback_subscribe(&Input::on_key_press);
		callback_subscribe(&Input::on_key_release);
		callback_subscribe(&Input::on_mouse_move);
	}

	bool Input::key_pressed(int key)
	{
		return keyboard[key];
	}

	void Input::on_key_press(KeyPress& key)
	{
		keyboard[key.keycode()] = true;
	}

	void Input::on_key_release(KeyRelease& key)
	{
		keyboard[key.keycode()] = false;
	}

	float Input::mouse_x(void)
	{
		return mouse.x;
	}

	float Input::mouse_y(void)
	{
		return mouse.y;
	}

	mouse_data Input::get_mouse(void)
	{
		return mouse;
	}

	void Input::on_mouse_move(MouseMove& mouse_move)
	{
		mouse.x = mouse_move.x();
		mouse.y = mouse_move.y();
		mouse.dx = mouse_move.dx();
		mouse.dy = mouse_move.dy();
	}

}
