#include "../includes/AEventfile.hpp"

Eventfile::Eventfile(int fd){
	_fd = fd;
}

Eventfile::Eventfile(){
	
}

Eventfile::~Eventfile(){

}

Eventfile & Eventfile::operator=(const Eventfile & copy){
	return *this;
}


const int & Eventfile::getFd() const { return (_fd); };

