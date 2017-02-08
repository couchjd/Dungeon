#include "ActorManager.h"

ActorManager::ActorManager(SpriteManager *sm) : 
	_ALIGOG(&sm->sprites["aligog"], "Aligog"),
	_BAT(&sm->sprites["bat"], "Giant Bat"),
	_SETHRON(&sm->sprites["sethron"], "Sethron"),
	_CAVEMAN(&sm->sprites["caveman"], "Caveman"),
	_FIRBOLEG(&sm->sprites["firboleg"], "Firboleg"),
	_HUND(&sm->sprites["hund"], "Schweinhund"),
	_LIZZOG(&sm->sprites["lizzog"], "Lizzog"),
	_SPIDER(&sm->sprites["spider"], "Giant Spider")
{ }

ActorManager::~ActorManager(){
}
