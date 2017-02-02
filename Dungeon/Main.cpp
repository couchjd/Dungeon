#include <iostream>
#include "Game.h"

void main() {
	srand(time(NULL));
	Game* game = new Game();
	game->Run();
}

