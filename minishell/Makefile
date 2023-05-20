# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:21:07 by jaehulee          #+#    #+#              #
#    Updated: 2023/05/19 16:51:03 by jaehulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
RM = rm
RMFLAGS = -rf 
SOURCES = ./minishell.c \
		./get_node.c \
		./get_redir.c \
		./get_cmd.c \
		./lib/ft_substr.c \
		./lib/ft_strncmp.c \
		./lib/ft_strlen.c \
		./lib/ft_strlcpy.c \
		./lib/ft_strjoin.c \
		./lib/ft_strdup.c \
		./lib/ft_strsdup.c \
		./lib/ft_split.c \
		./test/print.c 

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -lreadline -o $@ $^

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY: all clean fclean re