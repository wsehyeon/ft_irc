#include "../includes/AEventfile.hpp"

AEventfile::AEventfile(int fd){
	_fd = fd;
}

AEventfile::AEventfile(){
	
}

AEventfile::~AEventfile(){

}

AEventfile & AEventfile::operator=(const AEventfile & copy){
	return *this;
}


const int & AEventfile::getFd() const { return (_fd); };

