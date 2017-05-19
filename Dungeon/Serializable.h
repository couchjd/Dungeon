#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
#include <iostream>

class Serializable {
public:
	virtual void serialize(const Serializable&) = 0;
	//virtual Serializable unserialize(const Archive&) = 0;
};

#endif