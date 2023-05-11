# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 02:09:37 by jaehulee          #+#    #+#              #
#    Updated: 2023/05/09 22:52:18 by jaehulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf 
SOURCES = ./pipex.c \
		./utils/ft_command_utils.c \
		./utils/ft_print_utils.c \
		./utils/ft_process_utils.c \
		./utils/ft_free_utils.c \
		./utils/ft_here_doc_utils.c \
		./lib/ft_substr.c \
		./lib/ft_strncmp.c \
		./lib/ft_strlen.c \
		./lib/ft_strdup.c \
		./lib/ft_split.c \
		./lib/ft_strjoin.c \
		./lib/ft_lstnew.c \
		./lib/ft_lstlast.c \
		./lib/ft_lstadd_back.c \
		./lib/ft_strlcpy.c \
		./test/ft_print_cmd.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf $(OBJECTS)
	rm -rf $(BONUS_OBJECTS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re : fclean
	make

.PHONY: all bonus clean fclean re