#include "../includes/Server.hpp"

Server Server::_server;

int main(int ac, char **av){
	Server& server = Server::getInstance();
	if (ac != 3)
		std::cerr << "check argument\nUsage: ./ircserv <port> <password>" << std::endl;
	try{
		server.opening(av[1]);
		server.running();
	}
	catch(const char *msg){
		std::cerr << msg << std::endl;
	}
}