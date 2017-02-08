#include "TMonster.h"

TMonster::TMonster(){
}

TMonster::TMonster(sf::Sprite* sprite, std::string name) : _name(name) {
	_sprite = *sprite;
}

TMonster::~TMonster(){
}

void TMonster::move(MoveDir) {
}
