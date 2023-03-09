#include "../includes/AEventfile.hpp"

Eventfile::Eventfile(int fd){
	_fd = fd;
}

Eventfile::Eventfile(){
	
}

Eventfile::~Eventfile(){

}

void Eventfile::setEvent(int ident, int filter, int flags, std::vector<struct kevent> & changeList){
	struct kevent e;;
	EV_SET(&e, ident, filter, flags, 0,0,0);
	changeList.push_back(e);
}

const int & Eventfile::getFd() const { return (_fd); };

