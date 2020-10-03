#include "pch.h"

#include "display/window.h"
#include "core/root.h"
#include "core/log.h"

using namespace Split;

int main(int argc, char* argv[])
{
	Root::start();

	Window window{};

	while (window.open()) {
		window.update(0.0);
	}

	Root::quit();
	return 0;
}
