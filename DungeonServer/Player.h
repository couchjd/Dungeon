#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Actor.h"

enum CharClass { KNIGHT, FIGHTER, SAGE, WIZARD, ALCHEMIST, JEWELLER, JONES };

struct PlayerPacket {
	std::string name;
	float x;
	float y;
};

class Player : public Actor {
public:
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	Player(sf::Sprite*);

	void create(CharClass);

	std::string _name;

	int strength;
	int intelligence;
	int wisdom;
	int dexterity;
	int constitution;
	int charisma;

	virtual void move(MoveDir) override;
};

#endif