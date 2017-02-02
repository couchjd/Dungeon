#include "DungeonTile.h"

DungeonTile::DungeonTile() {}

DungeonTile::DungeonTile(sf::Sprite* tileSprite, bool passable, std::string name) : 
	_sprite(tileSprite), isPassable(passable), tileName(name) {
}

void DungeonTile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*_sprite, states);
}

void DungeonTile::setTexture(sf::Sprite* sprite) {
	_sprite = sprite;
}

std::ostream& operator<<(std::ostream& os, const DungeonTile& tile) {
	os << tile.tileName;
	return os;
}