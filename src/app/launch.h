#ifndef LAUNCH_H
#define LAUNCH_H

namespace Split {

	/* Application* is only passed to Split::Root, so no definition is
	 * required in launch.cpp
	 */
	class Application;
	
	int launch(int argc, char* argv[], Application* app);
}


#endif /* LAUNCH_H */
