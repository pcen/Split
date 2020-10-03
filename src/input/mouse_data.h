#pragma once

namespace Split
{

	typedef struct mouse_data
	{
		float x, y, dx, dy;
		bool initialized;
		mouse_data();
		void update(double xpos, double ypos);
	} mouse_data;

}
