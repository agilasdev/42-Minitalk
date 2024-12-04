# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymourchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 21:51:31 by ymourchi          #+#    #+#              #
#    Updated: 2022/01/05 21:51:33 by ymourchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = tools.c
CC = gcc
FLAGS = -Wall -Wextra -Werror
C_FLAGS = $(CC) $(FLAGS)

all : client server

client : tools.c client.c
	$(C_FLAGS) tools.c client.c -o client

server: tools.c server.c
	$(C_FLAGS) tools.c server.c -o server


clean :
	rm -rf *.o

fclean : clean
	rm -f server
	rm -f client

re : fclean all

.PHONY : all clean fclean re
