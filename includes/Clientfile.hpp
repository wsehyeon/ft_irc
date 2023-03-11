#ifndef __CLIENTFILE_HPP__
# define __CLIENTFILE_HPP__

#include "../includes/AEventfile.hpp"
#include "../includes/Client.hpp"

class Clientfile : public AEventfile {
private:
	Client * _client;
	std::string buffer;
	Clientfile();
public:
	~Clientfile();
	Clientfile(int);
	void on_read(change_list &, event_list &);
	void on_write();
};

#endif