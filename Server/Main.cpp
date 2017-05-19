#include "Server.h"

int main() {
	Server server;
	server.Init();
	Server::running = true;
	server.Run();
	return 0;
}