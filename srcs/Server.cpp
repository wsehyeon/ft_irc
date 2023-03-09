#include "../includes/Server.hpp"
#include "../includes/Serverfile.hpp"

Server & Server::operator=(const Server &copy){
	if (this == &copy)
		return (*this);
	// *this = copy.getInstance();
	return (*this);
}


Server::Server(Server &copy){
	// *this = copy.getInstance();
}

void Server::opening(char *port){
	struct sockaddr_in address;
	int sock_opt = 1;

	if ((_kqFd = kqueue()) <= 0)
		throw "kqeue() error";
	if ((_serverFd = socket(PF_INET, SOCK_STREAM, 0)) <= 0)
		throw "socket() error";
	if ((fcntl(_serverFd, F_SETFL, O_NONBLOCK)) < 0)
		throw "fcntl() error";
	if ((setsockopt(_serverFd, SOL_SOCKET, SO_REUSEADDR, &sock_opt, sizeof(sock_opt))) < 0)
		throw "setsockopt() error";

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(std::atoi(port));
	
	if ((bind(_serverFd, (struct sockaddr *)&address, sizeof(address))) < 0)
		throw "bind() error";
	if ((listen(_serverFd, BACKLOG)) < 0)
		throw "listen() error";

	// _serverFile = std::make_pair<_serverFd, Serverfile()>;
}

void Server::closing(){

}

Server::Server(){

}

Server::~Server(){

}

void Server::running(){
	
	_serverFile = new Serverfile(_serverFd);
	_serverFile->setEvent(_serverFd, READ, EV_ADD, _changeList);
	_events.insert(std::make_pair(_serverFd, _serverFile));
	//Q. udata에 자기 자신을 넣나?

	struct kevent eventList[MAX_EVENTS];
	struct kevent current;
	int count;
	while(true){
		count = kevent(_kqFd,_changeList.data(), _changeList.size(), eventList, MAX_EVENTS, 0);
		for (int idx = 0; idx < count; ++idx){
			current = eventList[idx];
			if (current.filter == EVFILT_READ)
				_events.find(current.ident)->second->on_read(_changeList, _events);
				// staitc_cast<Eventfile *>(current.udata).on_read();
			else if (current.filter == EVFILT_WRITE)
				_events.find(current.ident)->second->on_write();
				// staitc_cast<Eventfile *>(current.udata).on_write();
		}
		// close_sequence();
	}
}

Server & Server::getInstance(){
	return (_server);
}

const std::string & Server::getPassword() const { return (_password); }
const std::map<int, Eventfile *> & Server::getEvents() const { return (_events); }
const std::map<std::string, Channel *> & Server::getChannels() const { return (_channels); }
const std::vector<struct kevent> & Server::getChangeList() const { return (_changeList); }