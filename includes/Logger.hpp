#ifndef __LOGGER_HPP__
# define __LOGGER_HPP__

#include <iostream>
#include <pthread.h>

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

class Logger;

class Logger {
private:
	static Logger *_logger;
	std::vector<char *> input;
	std::vector<char *> output;
	pthread_mutex_t key;
public:
	Logger(){
		_logger = NULL;
		pthread_mutex_init(&key, 0);
	}
	static Logger * getInstance(){
		if (_logger == NULL)
			_logger = new Logger();
		return _logger;
	}
	void insert(char *buf){
		pthread_mutex_lock(&key);
		input.push_back(buf);
		pthread_mutex_unlock(&key);
	}
	void swap(){
		pthread_mutex_lock(&key);
		input.swap(output);
		pthread_mutex_unlock(&key);
	}
	static void *flush(void *arg){
		while (true){
			for (std::vector<char *>::iterator it = output.begin(); it != output.end(); ++it){
				std::cout << *it;
			}
			output.clear();
			pthread_mutex_lock(&key);
			input.swap(output);
			pthread_mutex_unlock(&key);
		}
		return arg;
	}
};

#endif