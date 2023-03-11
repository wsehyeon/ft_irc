#include "../includes/Logger.hpp"

Logger::Logger(){
	_logger = NULL;
	pthread_mutex_init(&key, 0);
}

void Logger::insert(char *buf){
	pthread_mutex_lock(&key);
	std::cout << "Logging insert...\n";
	input.push_back(buf);
	pthread_mutex_unlock(&key);

}

// void swap(){
// 	pthread_mutex_lock(&key);
// 	input.swap(output);
// 	pthread_mutex_unlock(&key);
// }