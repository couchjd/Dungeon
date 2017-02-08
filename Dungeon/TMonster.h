#ifndef T_MONSTER_H
#define T_MONSTER_H

#include "Actor.h"

enum MonsterType { ALIGOG, BAT, SETHRON, CAVEMAN, FIRBOLEG, HUND, LIZZOG, SPIDER };
class TMonster :	public Actor {
public:
	TMonster();
	TMonster(sf::Sprite*, std::string);
	~TMonster();
	std::string _name;

	virtual void move(MoveDir) override;
};

#endif