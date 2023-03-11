#ifndef __IEVENTFILE_HPP__
# define __IEVENTFILE_HPP__

#include <vector>
#include "../includes/Server.hpp"

class AEventfile{
private:
	AEventfile & operator=(const AEventfile & copy);
	AEventfile(const AEventfile & copy);
	AEventfile();
protected:
	typedef std::vector<struct kevent> change_list;
	typedef std::map<int,AEventfile *> event_list;
	int _fd;
public:
	AEventfile(int);
	virtual ~AEventfile();
	virtual void on_read(change_list &, event_list &) = 0;
	virtual void on_write() = 0;
	const int & getFd() const;
};


#endif