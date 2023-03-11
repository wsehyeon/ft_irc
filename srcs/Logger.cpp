#include "../includes/Logger.hpp"

Logger::Logger(){
	_logger = NULL;
	pthread_mutex_init(&key, 0);
}

Logger* Logger::getInstance(){
	if (_logger == NULL)
		_logger = new Logger();
	return _logger;
}

void Logger::insert(char *buf){
	pthread_mutex_lock(&key);
	std::cout << "[Logging insert]\n";
	input.push_back(buf);
	pthread_mutex_unlock(&key);

}

void *Logger::flush(void *arg){
	Logger * _this = static_cast<Logger*>(arg);
	while (true){
		for (std::vector<char *>::iterator it = _this->output.begin(); it != _this->output.end(); ++it){
			std::cout << "[Logging : " << *it << "]\n";
		}
		_this->output.clear();
		pthread_mutex_lock(&_this->key);
		// std::cout << "Logging swap...\n"; // too many print
		_this->input.swap(_this->output);
		pthread_mutex_unlock(&_this->key);
	}
	return arg;
};

// void swap(){
// 	pthread_mutex_lock(&key);
// 	input.swap(output);
// 	pthread_mutex_unlock(&key);
// }