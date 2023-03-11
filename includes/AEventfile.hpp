#ifndef __IEVENTFILE_HPP__
# define __IEVENTFILE_HPP__

#include <vector>
#include "../includes/Server.hpp"

class Eventfile{
private:
	Eventfile & operator=(const Eventfile & copy);
	Eventfile(const Eventfile & copy);
	Eventfile();
protected:
	typedef std::vector<struct kevent> change_list;
	typedef std::map<int,Eventfile *> event_list;
	int _fd;
public:
	Eventfile(int);
	virtual ~Eventfile();
	virtual void on_read(change_list &, event_list &) = 0;
	virtual void on_write() = 0;
	const int & getFd() const;
};


#endif