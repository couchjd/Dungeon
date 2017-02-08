#ifndef ACTOR_MANAGER_H
#define ACTOR_MANAGER_H
#include "TMonster.h"
#include "Monster.h"
#include "Player.h"
#include "SpriteManager.h"

class ActorManager {
public:
	ActorManager(SpriteManager*);
	~ActorManager();

	TMonster _ALIGOG;
	TMonster _BAT;
	TMonster _SETHRON;
	TMonster _CAVEMAN;
	TMonster _FIRBOLEG;
	TMonster _HUND;
	TMonster _LIZZOG;
	TMonster _SPIDER;
};

#endif