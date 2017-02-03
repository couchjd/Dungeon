#pragma once
#include "Actor.h"

enum MonsterType { ALIGOG, BAT, SETHRON, CAVEMAN, FIRBOLEG, HUND, LIZZOG, SPIDER };
class Monster :	public Actor {
public:
	Monster();
	Monster(sf::Sprite*);
	~Monster();

	virtual void move(MoveDir) override;
};

