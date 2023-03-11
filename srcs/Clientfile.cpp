#include "../includes/Clientfile.hpp"
#include "../includes/Logger.hpp"

Clientfile::Clientfile(int fd) : Eventfile(fd){
	_client = Client(fd);
};

Clientfile::Clientfile(){}
Clientfile::~Clientfile(){}

void Clientfile::on_read(change_list &ch, event_list &events){
	char buf[512];
	memset(buf,0,512);
	recv(_fd, buf, 512, 0);
	Logger * logger = Logger::getInstance();
	logger->insert(buf);

};

void Clientfile::on_write(){
	//send
};