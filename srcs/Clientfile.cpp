#include "../includes/Clientfile.hpp"

Clientfile::Clientfile(int fd) : Eventfile(fd){
	_client = Client(fd);
};

Clientfile::Clientfile(){}
Clientfile::~Clientfile(){}

void Clientfile::on_read(change_list &ch, event_list &events){
	char buf[512];
	memset(buf,0,512);
	recv(_fd, buf, 512, 0);
	std::cout << buf; // TODO : toss logger
};

void Clientfile::on_write(){
	//send
};