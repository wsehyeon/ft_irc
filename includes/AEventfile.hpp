#ifndef __AEVENTFILE_HPP__
# define __AEVENTFILE_HPP__

#include <vector>
#include "../includes/Server.hpp"

class Client;

class Eventfile{

private:
	Eventfile & operator=(const Eventfile & copy);
	Eventfile(const Eventfile & copy);

protected:
	Eventfile();
	// 생성할때 초기화 하면 on_read() 같은곳에서 매개변수로 안 받아도 되지 않을까??
	typedef std::vector<struct kevent> &change_list;
	typedef std::map<int, Eventfile *>  &event_list;
	int _fd;

public:
	Eventfile(int);
	virtual ~Eventfile();

	void setEvent(int, int, int, std::vector<struct kevent> & changeList);
	virtual void on_read(change_list &, event_list &) = 0;
	virtual void on_write() = 0;
	const int & getFd() const;

};


#endif