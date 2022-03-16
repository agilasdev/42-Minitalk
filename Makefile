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

NAME = minitalk.a
SRC = server_fn.c other_fn.c list_fn.c client_fn.c
CC = gcc
FLAGS = -Wall -Wextra -Werror
C_FLAGS = $(CC) $(FLAGS)

all : $(NAME)

$(NAME) : $(SRC:.c=.o)
	ar -rc $(NAME) $(SRC:.c=.o)
	$(C_FLAGS) $(NAME) main/server.c -o server
	$(C_FLAGS) $(NAME) main/client.c -o client

$(SRC:.c=.o) : $(SRC)
	$(C_FLAGS) -c $(SRC)

clean :
	rm -rf *.o

fclean : clean
	rm -f $(NAME)
	rm -f server
	rm -f client

re : fclean $(NAME)

.PHONY : all clean fclean re