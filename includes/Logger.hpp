#ifndef __LOGGER_HPP__
# define __LOGGER_HPP__

#include <iostream>
#include <pthread.h>
#include <vector>

// normal
# define N "\033[0m"

// error msg
# define R "\033[31m"

// client msg
# define G "\033[32m"

// alert msg
# define Y "\033[33m" 

// server msg
# define B "\033[34m" 

class Logger {
private:
	Logger & operator=(Logger & copy);
	Logger(Logger & copy);

	static Logger*_logger;

	std::vector<char *> input;
	std::vector<char *> output;
	
	pthread_mutex_t key;
public:
	Logger();
	~Logger();
	static Logger* getInstance();
	
	void insert(char *buf);
	// void swap();
	
	static void *flush(void *arg);
};

#endif
