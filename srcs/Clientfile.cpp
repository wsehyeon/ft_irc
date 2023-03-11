#include "../includes/Clientfile.hpp"
#include "../includes/Logger.hpp"

Clientfile::Clientfile(int fd) : AEventfile(fd){
	_client = new Client(fd);
};

Clientfile::~Clientfile(){

}

void Clientfile::on_read(change_list &ch, event_list &events){
	char buf[512];
	memset(buf,0,512);
	recv(AEventfile::_fd, buf, 512, 0);
	Logger * logger = Logger::getInstance();
	logger->insert(buf);
};

void Clientfile::on_write(){
	//send
};