#include "pch.h"
#include "root.h"

#include "app/application.h"

static bool root_initialized = false;

static Application* s_application = nullptr;

void Root::init(int argc, char* argv[])
{
	if (root_initialized)
		return;

	create_systems();
	init_systems();
	root_initialized = true;
	s_application->launch();
	cleanup_systems();

}

void Root::create_systems(void)
{
	if (root_initialized)
		return;
	s_application = new Application();
}

void Root::init_systems(void)
{
	if (root_initialized)
		return;
	s_application->init();
}

void Root::cleanup_systems(void)
{
	if (!root_initialized)
		return;
	delete s_application;
}
