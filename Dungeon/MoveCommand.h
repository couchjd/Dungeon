#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H

#include "Command.h"

class MoveCommand : public Command {
public:
	~MoveCommand();
	virtual void execute(Actor& actor, sf::Vector2f moveVector) {
		actor.move(moveVector);
	}
};

#endif