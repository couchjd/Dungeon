#include "ActorManager.h"

ActorManager::ActorManager(SpriteManager *sm) : 
	_ALIGOG(&sm->sprites["aligog"]) 
{ }

ActorManager::~ActorManager()
{
}
