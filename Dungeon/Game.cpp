#include "Game.h"
#include <iostream>

Game::Game(){
	_window = new sf::RenderWindow(sf::VideoMode(640, 480), "Dungeon of Doom");

	_spriteManager = new SpriteManager();
	
	_levelMap = new LevelMap(_spriteManager);

	//Here we can call the createCharacter method and pass the results to
	//create the player character.

	_player = new Player(&_spriteManager->sprites["knight"]);
	_player->setPosition(sf::Vector2f(96.f, 96.f));
	
	_bgm = new sf::Music();
	_bgm->openFromFile("res/sound/bgm.wav");
}

Game::~Game(){
}

Player* Game::createCharacter() {
	//Need to implement this as a window to get info from player.
	return nullptr;
}

void Game::Run() {
	_bgm->setLoop(true);
	_bgm->play();
	_levelMap->create();
	while (_window->isOpen()) {
		sf::Event event;
		while (_window->pollEvent(event)) {
			handleEvents(&event);
		}
		_window->clear(sf::Color::Black);
		_window->draw(*_levelMap);
		_window->draw(*_player);
		_window->display();
	}
}


//Lots of work to be done here. The mouse and keyboard controls should probably be
//consolidated into another class so that there is less code duplication.
void Game::handleEvents(sf::Event* event) {
	
	if (event->type == sf::Event::Closed)
		_window->close();

	//This needs to be modified to keep the player moving as long as the button
	//is pressed instead of having to press it once per move.
	if (event->type == sf::Event::MouseButtonPressed) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (sf::Mouse::getPosition(*_window).x > _player->getPosition().x) {
				if (_levelMap->_dMap[(int)(_player->getPosition().x / TILE_SIZE) + 1][(int)_player->getPosition().y / TILE_SIZE]->isPassable)
					_player->move(RIGHT);
			}
			if (sf::Mouse::getPosition(*_window).x < _player->getPosition().x) {
				if (_levelMap->_dMap[(int)(_player->getPosition().x / TILE_SIZE) - 1][(int)_player->getPosition().y / TILE_SIZE]->isPassable)
					_player->move(LEFT);
			}
			if (sf::Mouse::getPosition(*_window).y > _player->getPosition().y) {
				if (_levelMap->_dMap[(int)_player->getPosition().x / TILE_SIZE][(int)(_player->getPosition().y / TILE_SIZE) + 1]->isPassable)
					_player->move(DOWN);
			}
			if (sf::Mouse::getPosition(*_window).y < _player->getPosition().y) {
				if (_levelMap->_dMap[(int)_player->getPosition().x / TILE_SIZE][(int)(_player->getPosition().y / TILE_SIZE) - 1]->isPassable)
					_player->move(UP);
			}
			else;
		}
	}

	if (event->type == sf::Event::KeyPressed) {
		int rightBound = _player->getPosition().x + _player->getTextureRect().width;
		int bottomBound = _player->getPosition().y + _player->getTextureRect().height;
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			_window->close();

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) && rightBound < _window->getSize().x) {
			if (_levelMap->_dMap[(int)(_player->getPosition().x / TILE_SIZE) + 1][(int)_player->getPosition().y / TILE_SIZE]->isPassable)
				_player->move(RIGHT);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) && _player->getPosition().x > 0) {
			if (_levelMap->_dMap[(int)(_player->getPosition().x / TILE_SIZE) - 1][(int)_player->getPosition().y / TILE_SIZE]->isPassable)
				_player->move(LEFT);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) && _player->getPosition().y > 0) {
			if (_levelMap->_dMap[(int)_player->getPosition().x / TILE_SIZE][(int)(_player->getPosition().y / TILE_SIZE) - 1]->isPassable)
				_player->move(UP);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) && bottomBound < _window->getSize().y) {
			if (_levelMap->_dMap[(int)_player->getPosition().x / TILE_SIZE][(int)(_player->getPosition().y / TILE_SIZE) + 1]->isPassable)
				_player->move(DOWN);
		}
	}
}