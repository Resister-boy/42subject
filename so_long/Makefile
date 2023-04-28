# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 13:50:49 by jaehulee          #+#    #+#              #
#    Updated: 2023/04/28 04:06:05 by jaehulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES = so_long.c \
		./utils/ft_parse_utils.c \
		./utils/ft_free_utils.c \
		./utils/ft_check_utils_1.c \
		./utils/ft_check_utils_2.c \
		./utils/ft_check_utils_3.c \
		./utils/ft_print_utils.c \
		./lib/ft_lstadd_back.c \
		./lib/ft_lstlast.c \
		./lib/ft_lstsize.c \
		./lib/ft_strdup.c \
		./lib/ft_strlen.c \
		./lib/ft_total_len.c \
		./lib/ft_strsdup.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./games/ft_play_utils_1.c \
		./games/ft_play_utils_2.c \
		./test/ft_print_map.c

all: $(NAME)

OBJECTS = $(SOURCES:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY: all clean fclean re