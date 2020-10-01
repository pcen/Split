#include "pch.h"
#include "launch.h"

#include "app/root.h"

namespace Split
{

	int launch(int argc, char* argv[], Application* app)
	{
		Split::Root* root = Split::Root::get_root();
		if (!root->is_initialized()) {
			/* only delete root if this is the first time launching
			 */
			root->run(argc, argv, app);
			delete root;
			return 0;
		}
		else {
			return 1;
		}
	}

}
