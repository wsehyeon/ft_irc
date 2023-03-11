#include "../includes/CommandInvoker.hpp"
#include <utility>

CommandInvoker::CommandInvoker()
{
    _commandMap.insert(std::make_pair("PRIVMSG", new PrivMsg()));
}

CommandInvoker::CommandInvoker(const CommandInvoker&){}

CommandInvoker& CommandInvoker::operator=(const CommandInvoker&){ return (*this); }

CommandInvoker::~CommandInvoker(){}

void CommandInvoker::executeCommand() const
{

}
