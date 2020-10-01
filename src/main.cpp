#include "pch.h"

#include "display/window.h"

using namespace Split;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Window window{};

	while (window.open()) {
		window.update(0.0);
	}

	SDL_Quit();
	return 0;
}
