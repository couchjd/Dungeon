#include "Actor.h"

void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}

void Actor::move(sf::Vector2f moveVector) {
	this->setPosition(this->getPosition() + moveVector);
}