#ifndef __COMMANDINVOKER_HPP__
#define __COMMANDINVOKER_HPP__

#include <iostream>
#include <map>

#include "ICommand.hpp"

class CommandInvoker
{
        std::map<std::string, ICommand*> _commandMap;

        CommandInvoker(const CommandInvoker&);
        CommandInvoker& operator=(const CommandInvoker&);
    public:
        CommandInvoker();
        ~CommandInvoker();

        void executeCommand() const;
};

#endif
