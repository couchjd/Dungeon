#include <iostream>
#include "Game.h"


int main() {
	srand(time(NULL));
	Game game;
	game.Init();
	game.Run();
	game.Shutdown();

	return 0;
}

