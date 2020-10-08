#include "pch.h"
#include "events/WindowEvents.h"
#include "Input.h"

namespace Split
{

	// Mouse Implementation
	Mouse::Mouse()
		: x{ 0 },
		y{ 0 },
		dx{ 0.0f },
		dy{ 0.0f },
		initialized{ false } {}

	void Mouse::update(double xpos, double ypos)
	{
		if (!initialized) {
			x = (float)xpos;
			y = (float)ypos;
			initialized = true;
		}
		dx = (float)xpos - x;
		dy = y - (float)ypos;
		x = (float)xpos;
		y = (float)ypos;
	}

	// Input Implementation

	bool Input::s_keyboard[512];
	Mouse Input::s_mouse;

	Input::Input()
	{
		eventBusSubscribe();
	}

	Input::~Input() {}

	void Input::eventBusSubscribe(void)
	{
		callbackSubscribe(&Input::on_key_press);
		callbackSubscribe(&Input::on_key_release);
		callbackSubscribe(&Input::on_mouse_move);
	}

	bool Input::key(int key)
	{
		return Input::s_keyboard[key];
	}

	void Input::on_key_press(KeyPress& key)
	{
		Input::s_keyboard[key.keycode()] = true;
	}

	void Input::on_key_release(KeyRelease& key)
	{
		Input::s_keyboard[key.keycode()] = false;
	}

	Mouse Input::mouse(void)
	{
		return Input::s_mouse;
	}

	void Input::on_mouse_move(MouseMove& m)
	{
		Input::s_mouse.x = m.x();
		Input::s_mouse.y = m.y();
		Input::s_mouse.dx = m.dx();
		Input::s_mouse.dy = m.dy();
	}

}
