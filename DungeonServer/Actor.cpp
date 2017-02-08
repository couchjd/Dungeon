#include "Actor.h"

void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}