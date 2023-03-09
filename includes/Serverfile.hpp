#ifndef __SERVERFILE_HPP__
# define __SERVERFILE_HPP__

#include "../includes/AEventfile.hpp"
#include "../includes/Clientfile.hpp"

class Server;

class Serverfile : public Eventfile{

private:
	Serverfile();
	Serverfile & operator=(const Serverfile &copy);
	Serverfile(const Serverfile &copy);

	// Server & _server;
public:
	~Serverfile();
	Serverfile(int);
	void on_read(change_list &, event_list &);
	void on_write();
};


#endif