#ifndef MOUSE_DATA_H
#define MOUSE_DATA_H

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

#endif /* MOUSE_DATA_H */
