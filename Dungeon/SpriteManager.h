#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include <string>

class SpriteManager {
public:
	enum TileType ;
	SpriteManager();
	SpriteManager(const SpriteManager&) = delete;
	SpriteManager& operator=(const SpriteManager&) = delete;
	std::map<std::string, sf::Sprite> sprites;
	sf::Sprite* operator[](std::string key) { return &sprites[key]; }
	
private:
	sf::Texture _spriteSheet;
};

#endif // SPRITE_MANAGER_H