#include "../includes/Server.hpp"
#include "../includes/Logger.hpp"

Server Server::_server;
Logger* Logger::_logger = NULL;

int main(int ac, char **av){
	Server& server = Server::getInstance();
	Logger * logger = Logger::getInstance();
	pthread_t logging;
	if (ac != 3)
		std::cerr << "check argument\nUsage: ./ircserv <port> <password>" << std::endl;
	try{
		pthread_create(&logging, NULL, Logger::flush, logger);
		server.opening(av[1], av[2]);
		server.running();
	}
	catch(const char *msg){
		std::cerr << msg << std::endl;
	}
	pthread_join(logging, NULL);
}


/***
 * void* thread_function(void* arg) {
  std::cout << "Thread function executing" << std::endl;
  return NULL;
}

int main() {
  std::cout << "Main function starts" << std::endl;

  pthread_t thread;
  int rc;

  // Create a new thread
  rc = pthread_create(&thread, NULL, thread_function, NULL);

  if (rc) {
    std::cerr << "Error: unable to create thread" << std::endl;
    return -1;
  }

  // Wait for the thread to finish
  pthread_join(thread, NULL);

  std::cout << "Main function ends" << std::endl;

  return 0;
}
 * 
 * 
*/
