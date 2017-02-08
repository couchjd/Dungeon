#ifndef MONSTER_H
#define MONSTER_H

#include "TMonster.h"

class Monster {
public:
	Monster();
	~Monster();
	std::string getName();
private:
	TMonster* monsterClass;
};

#endif