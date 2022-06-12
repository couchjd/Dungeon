#include <SFML/Network.hpp>
#include <iostream>
#include <list>
#include "Player.h"

int main() {
	bool running = true;
	// Create a socket to listen to new connections
	sf::TcpListener listener;
	listener.listen(53000);
	// Create a list to store the future clients
	std::list<sf::TcpSocket*> clients;
	// Create a selector
	sf::SocketSelector selector;
	// Add the listener to the selector
	selector.add(listener);
	// Endless loop that waits for new connections
	while (running)	{
		// Make the selector wait for data on any socket
		if (selector.wait()) {
			// Test the listener
			if (selector.isReady(listener))	{
				// The listener is ready: there is a pending connection
				sf::TcpSocket* client = new sf::TcpSocket;
				if (listener.accept(*client) == sf::Socket::Done) {
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
				for (std::list<sf::TcpSocket*>::iterator it = clients.begin(); it != clients.end(); ++it) {
					sf::TcpSocket& client = **it;
					if (selector.isReady(client)) {
						char data[100];
						std::size_t received;
						// The client has sent some data, we can receive it
						sf::Packet packet;
						PlayerPacket player;
						if (client.receive(packet) == sf::Socket::Done)	{
							packet >> player.name >> player.x >> player.y ;
							
							std::cout << "NAME: " << player.name << std::endl;
							//std::cout << data << std::endl;
						}
					}
				}
			}
		}
	}
	return 0;
}