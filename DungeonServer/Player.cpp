#include "Player.h"
#include <iostream>

Player::Player(sf::Sprite* playerSprite) {
	_sprite = *playerSprite;
}

//### TO-DO ###
//This may be moved into the Game class
void Player::create(CharClass cClass) {
	switch (cClass) {
	case KNIGHT:
		break;
	}
}

void Player::move(MoveDir dir) {
	sf::Vector2f pos(getPosition().x, getPosition().y);
	sf::Vector2f rect(getTextureRect().width, getTextureRect().height);

	switch (dir) {
	case UP:
		setPosition(pos.x, pos.y - rect.y);
		break;
	case DOWN:
		setPosition(pos.x, pos.y + rect.y);
		break;
	case LEFT:
		setPosition(pos.x - rect.x, pos.y);
		break;
	case RIGHT:
		setPosition(pos.x + rect.x, pos.y);
		break;
	}
}

sf::Packet& operator <<(sf::Packet& packet, Player& player) {
	return packet << &player._name << &player.getPosition();
}

sf::Packet& operator >>(sf::Packet& packet, PlayerPacket& player) {
	return packet >> player.name >> player.x >> player.y;
}