#include "../includes/Serverfile.hpp"
#include "../includes/Server.hpp"
#include <vector>
#include <map>


Serverfile::Serverfile(int fd) : AEventfile(fd){
};

void Serverfile::on_read(change_list &ch, event_list &events){
	Server & server = Server::getInstance();
	int clientFd;
	if ((clientFd = accept(_fd, NULL, NULL)) <= 0)
		throw "accpet() error";
  	if ((fcntl(clientFd, F_SETFL, O_NONBLOCK)) == -1)
		throw "client socket fcntl() error";
	struct kevent e;
	EV_SET(&e, clientFd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0 ,0);
	ch.push_back(e);
	events.insert(std::make_pair(clientFd, new Clientfile(clientFd)));
};

void Serverfile::on_write(){
	throw "Server cant occure write event";
};

Serverfile::~Serverfile(){
	
}