#include "pch.h"
#include "mouse_data.h"

namespace Split
{

	mouse_data::mouse_data()
		: x{ 0 }, y{ 0 }, dx{ 0.0f }, dy{ 0.0f } {}

	void mouse_data::update(double xpos, double ypos)
	{
		if (!initialized) {
			x = (float)xpos;
			y = (float)ypos;
			initialized = true;
		}
		dx = (float)xpos - x;
		dy = (float)ypos - y;
		x = (float)xpos;
		y = (float)ypos;
	}

}
