#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.hpp>
#include "Player.h"
#include "SpriteManager.h"
#include "LevelMap.h"

class Game
{
public:
	Game();
	~Game();
	void Run();

private:
	sf::Music* _bgm;
	sf::View* _view;
	sf::RenderWindow* _window;
	Player* _player;
	SpriteManager* _spriteManager;
	LevelMap* _levelMap;

	Player* createCharacter();
	void handleEvents(sf::Event*);
};

#endif // GAME_H