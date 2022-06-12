#include "Game.h"
#include <iostream>

Game::Game(){

}

Game::~Game(){
}

void Game::Init() {
	_window = new sf::RenderWindow(sf::VideoMode(640, 480), "Dungeon of Doom", sf::Style::Titlebar | sf::Style::Close);
	
	_spriteManager = new SpriteManager();

	_levelMap = new LevelMap(_spriteManager);

	//Here we can call the createCharacter method and pass the results to
	//create the player character.

	_player = new Player(&_spriteManager->sprites["knight"]);

	_player->setPosition(sf::Vector2f(96.f, 96.f));

	_bgm = new sf::Music();
	_bgm->openFromFile("res/sound/bgm.wav");
}

void Game::Shutdown() {
	delete(_bgm);
	delete(_player);
	delete(_levelMap);
	delete(_spriteManager);
	delete(_window);
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
    MouseMove();
		_window->clear(sf::Color::Black);
		_window->draw(*_levelMap);
		_window->draw(*_player);
		_window->display();
	}
}

void Game::MouseMove() {
  if(_player->_isMoving) {
    if(_clock.getElapsedTime().asSeconds() > 0.1f) {
      _mousePos = sf::Mouse::getPosition(*_window);

      std::cout << "x: " << _mousePos.x << " y: " << _mousePos.y << std::endl;
      _clock.restart();

      if(_mousePos.x > _player->getPosition().x) {
        if(_levelMap->_dMap[(int)(_player->getPosition().x / TILE_SIZE) + 1][(int)_player->getPosition().y / TILE_SIZE]->isPassable)
          _player->move(RIGHT);
      }
      if(_mousePos.x < _player->getPosition().x) {
        if(_levelMap->_dMap[(int)(_player->getPosition().x / TILE_SIZE) - 1][(int)_player->getPosition().y / TILE_SIZE]->isPassable)
          _player->move(LEFT);
      }
      if(_mousePos.y > _player->getPosition().y) {
        if(_levelMap->_dMap[(int)_player->getPosition().x / TILE_SIZE][(int)(_player->getPosition().y / TILE_SIZE) + 1]->isPassable)
          _player->move(DOWN);
      }
      if(_mousePos.y < _player->getPosition().y) {
        if(_levelMap->_dMap[(int)_player->getPosition().x / TILE_SIZE][(int)(_player->getPosition().y / TILE_SIZE) - 1]->isPassable)
          _player->move(UP);
      }
      else;
    }
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
		if (event->mouseButton.button == sf::Mouse::Left) {
      _player->_isMoving = true;
		}
	}

  if(event->type == sf::Event::MouseButtonReleased) {
    if(event->mouseButton.button == sf::Mouse::Left) {
      _player->_isMoving = false;
    }
  }

	if (event->type == sf::Event::KeyPressed) {
		int rightBound = _player->getPosition().x + _player->getTextureRect().width;
		int bottomBound = _player->getPosition().y + _player->getTextureRect().height;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			_window->close();

		if (MOVE_RIGHT) && rightBound < _window->getSize().x) {
			if (_levelMap->_dMap[(int)(_player->getPosition().x / TILE_SIZE) + 1][(int)_player->getPosition().y / TILE_SIZE]->isPassable)
				_player->move(RIGHT);
		}
		if (MOVE_LEFT) && _player->getPosition().x > 0) {
			if (_levelMap->_dMap[(int)(_player->getPosition().x / TILE_SIZE) - 1][(int)_player->getPosition().y / TILE_SIZE]->isPassable)
				_player->move(LEFT);
		}
		if (MOVE_UP) && _player->getPosition().y > 0) {
			if (_levelMap->_dMap[(int)_player->getPosition().x / TILE_SIZE][(int)(_player->getPosition().y / TILE_SIZE) - 1]->isPassable)
				_player->move(UP);
		}
		if (MOVE_DOWN) && bottomBound < _window->getSize().y) {
			if (_levelMap->_dMap[(int)_player->getPosition().x / TILE_SIZE][(int)(_player->getPosition().y / TILE_SIZE) + 1]->isPassable)
				_player->move(DOWN);
		}
	}
}