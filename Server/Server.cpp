#include "Server.h"

Server::Server() {
}

Server::~Server() {
}

void Server::Init() {
	listener.listen(1234);
	selector.add(listener);
}

void Server::Run() {
	while(running) {
		// Make the selector wait for data on any socket
		if(selector.wait()) {
			// Test the listener
			if(selector.isReady(listener)) {
				// The listener is ready: there is a pending connection
				sf::TcpSocket* client = new sf::TcpSocket;
				if(listener.accept(*client) == sf::Socket::Done) {
					// Add the new client to the clients list
					std::cout << "CLIENT CONNECTED" << std::endl;
					clients.push_back(client);
					// Add the new client to the selector so that we will
					// be notified when he sends something
					selector.add(*client);
				}

				else {
					// Error, we won't get a new connection, delete the socket
					delete client;
				}
			}

			else {
				// The listener socket is not ready, test all other sockets (the clients)
				for(std::list<sf::TcpSocket*>::iterator it = clients.begin(); it != clients.end(); ++it) {
					sf::TcpSocket& client = **it;
					if(selector.isReady(client)) {
						char data[100];
						std::size_t received;
						// The client has sent some data, we can receive it
						sf::Packet packet;
						if(client.receive(packet) == sf::Socket::Done) {

							//std::cout << data << std::endl;
						}
					}
				}
			}
		}
	}
}