# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 19:14:55 by jaehulee          #+#    #+#              #
#    Updated: 2023/09/14 20:45:31 by jaehulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRCS = ./main.c \
		./philo.c \
		./init.c \
		./parse.c \
		./print.c \
		./free.c \
		./thread.c \
		./time.c \
		./utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make all

.PHONY: all clean fclean re