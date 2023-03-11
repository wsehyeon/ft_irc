#ifndef __ICOMMAND_HPP__
#define __ICOMMAND_HPP__

class ICommand
{
    public:
        virtual ~ICommand();

        virtual void execute()=0;
};

#endif
