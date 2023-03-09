#ifndef __SERVER_HPP__
# define __SERVER_HPP__

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/event.h>

#include "../includes/AEventfile.hpp"

# define BACKLOG 42
# define MAX_EVENTS 100
# define READ -1
# define WIRTE -2

class MessageHandler;
class Invoker;
class Logger;
class Channel;
class Client;
class Eventfile;

class Server {

private:
	static Server _server;
	
	int _kqFd;
	int _serverFd;
	Eventfile * _serverFile;
	std::string _password;
	std::map<int, Eventfile *> _events;
	std::map<std::string, Channel *> _channels;
	std::vector<struct kevent> _changeList;

	// Invoker _invoker;
	// Logger _logger;
	// MessageHandler _msgHandler;

	Server & operator=(const Server &copy);
	Server(Server &copy);
	void closing();
public:
	Server();
	~Server();
	
	void opening(char *port);
	void running();

	static Server & getInstance();

	const std::string & getPassword() const;
	const std::map<int, Eventfile *> & getEvents() const;
	const std::map<std::string, Channel *> & getChannels() const;
	const std::vector<struct kevent> & getChangeList() const;

};


#endif