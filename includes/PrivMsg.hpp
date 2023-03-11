#ifndef __PRIVMSG_HPP__
#define  __PRIVMSG_HPP__

#include "ICommand.hpp"

class PrivMsg : public ICommand
{
    public:
        PrivMsg();
        PrivMsg(const PrivMsg&);
        PrivMsg& operator=(const PrivMsg&);
        ~PrivMsg();

        void execute();
};

#endif
