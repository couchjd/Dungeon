#ifndef ACTOR_MANAGER_H
#define ACTOR_MANAGER_H
#include "Monster.h"
#include "Player.h"
#include "SpriteManager.h"

class ActorManager {
public:
	ActorManager(SpriteManager*);
	~ActorManager();

	Monster _ALIGOG;

};

#endif