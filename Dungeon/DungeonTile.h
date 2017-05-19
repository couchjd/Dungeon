#ifndef DUNGEONTILE_H
#define DUNGEONTILE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Serializable.h"

class DungeonTile :	public sf::Drawable/*, public Serializable*/ {
public:
	DungeonTile(const DungeonTile&) = delete;
	DungeonTile& operator=(const DungeonTile&) = delete;
	DungeonTile();
	DungeonTile(sf::Sprite* tileSprite, bool passable, std::string name);
	friend std::ostream& operator<<(std::ostream& os, const DungeonTile& tile);
	std::string tileName;
	bool isPassable;

	void setTexture(sf::Sprite*);

	template<typename ... Args>
	void setPosition(Args&& ... args) {
		_sprite->setPosition(std::forward<Args>(args)...);
	}

	/*TO BE USED ONCE SERIALIZATION IS WORKING PROPERLY*/
	//virtual std::ostream& operator<<(std::ostream& outStream);
	//virtual std::ostream& operator>>(std::ostream& inStream);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Sprite* _sprite;
};


#endif