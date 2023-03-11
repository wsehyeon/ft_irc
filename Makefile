NAME = ircserv

SRC_DIR = srcs/
SRC_NAME = main.cpp Server.cpp Client.cpp AEventfile.cpp Serverfile.cpp Clientfile.cpp Logger.cpp
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))


all:
	c++ -g -I./includes/ $(SRCS) -o $(NAME)