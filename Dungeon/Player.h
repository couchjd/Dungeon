#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Actor.h"

enum CharClass { KNIGHT, FIGHTER, SAGE, WIZARD, ALCHEMIST, JEWELLER, JONES };


class Player : public Actor {
public:
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	Player(sf::Sprite*);

	void create(CharClass);

	int strength;
	int intelligence;
	int wisdom;
	int dexterity;
	int constitution;
	int charisma;

	virtual void move(MoveDir) override;

private:
	//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	//sf::Sprite _sprite;
};

#endif