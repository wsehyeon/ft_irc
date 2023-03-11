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
	Logger & operator=(Logger & copy);
	Logger(Logger & copy);

	static Logger*_logger;

	std::vector<char *> input;
	std::vector<char *> output;
	
	pthread_mutex_t key;
public:
	Logger();
	~Logger();
	static Logger* getInstance(){
		if (_logger == NULL)
			_logger = new Logger();
		return _logger;
	}
	
	void insert(char *buf);
	// void swap();
	
	static void *flush(void *arg){
		Logger * _this = static_cast<Logger*>(arg);
		while (true){
			for (std::vector<char *>::iterator it = _this->output.begin(); it != _this->output.end(); ++it){
				std::cout << "Logging..." << *it;
			}
			_this->output.clear();
			pthread_mutex_lock(&_this->key);
			// std::cout << "Logging swap...\n"; // too many print
			_this->input.swap(_this->output);
			pthread_mutex_unlock(&_this->key);
		}
		return arg;
	};
};

#endif