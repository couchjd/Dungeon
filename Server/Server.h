#ifndef SERVER_H
#define SERVER_H

#include <SFML/Network.hpp>
#include "SLevelMap.h"
#include <list>
#include <iostream>

class Server {
public:
	Server();
	~Server();
	void Init();
	void Run();
	void Shutdown();
	static bool running;

private:
	sf::TcpListener listener;
	std::list<sf::TcpSocket*> clients;
	sf::SocketSelector selector;

};

#endif