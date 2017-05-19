#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Player.h"
#include "SpriteManager.h"
#include "LevelMap.h"

enum GameMode { SINGLE_PLAYER, LOCAL_HOST, REMOTE_HOST };

class Game
{
public:
	Game();
	~Game();
	void Init();
	void Run();
	void Shutdown();

private:
	GameMode gameMode;
	bool remoteServer;	
	sf::Music* _bgm;
	sf::View* _view;
	sf::RenderWindow* _window;
	sf::TcpSocket* _socket;
	Player* _player;
	SpriteManager* _spriteManager;
	LevelMap* _levelMap;

	Player* createCharacter();
	void handleEvents(sf::Event*);
};

#endif // GAME_H