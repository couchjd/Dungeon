#ifndef GAME_H
#define GAME_H

#define MOVE_LEFT     (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
#define MOVE_RIGHT    (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
#define MOVE_UP       (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
#define MOVE_DOWN     (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
#define M_MOVE_LEFT
#define M_MOVE_RIGHT
#define M_MOVE_UP
#define M_MOVE_DOWN

#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Player.h"
#include "SpriteManager.h"
#include "LevelMap.h"

class Game
{
public:
	Game();
	~Game();
	void Init();
	void Run();
  void MouseMove();
	void Shutdown();

private:
	sf::Music* _bgm;
	sf::View* _view;
	sf::RenderWindow* _window;
  sf::Clock _clock;
  sf::Vector2i _mousePos;

	Player* _player;
	SpriteManager* _spriteManager;
	LevelMap* _levelMap;

	Player* createCharacter();
	void handleEvents(sf::Event*);
};

#endif // GAME_H