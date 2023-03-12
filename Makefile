NAME = ircserv

SRC_DIR = srcs/
SRC_NAME = AEventfile.cpp Client.cpp Clientfile.cpp CommandInvoker.cpp Logger.cpp PrivMsg.cpp Server.cpp Serverfile.cpp main.cpp
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))

all:
	c++ -g -I./includes/ $(SRCS) -o $(NAME)
