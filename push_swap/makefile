# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 13:19:44 by jaehulee          #+#    #+#              #
#    Updated: 2023/04/12 16:56:01 by jaehulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = push_swap.c \
		./utils/arg_utils.c \
		./utils/command_utils.c \
		./utils/etc_utils.c \
		./utils/stack_utils.c \
		./utils/print_utils.c \
		./utils/push_utils.c \
		./utils/swap_utils.c \
		./utils/sort_utils_1.c \
		./utils/sort_utils_2.c \
		./utils/sort_utils_3.c \
		./utils/sort_utils_4.c \
		./utils/sort_utils_5.c \
		./utils/sort_utils_6.c \
		./lib/ft_atoi.c \
		./lib/ft_lstadd_back.c \
		./lib/ft_lstnew.c \
		./lib/ft_lstlast.c \
		./lib/ft_lstsize.c \
		./lib/ft_split.c \
		./lib/ft_strlcpy.c \
		./lib/ft_strlen.c \
		./lib/ft_strdup.c \
		./command/ft_push.c \
		./command/ft_reverse_rotate.c \
		./command/ft_rotate.c \
		./command/ft_swap.c \

BONUS_SOURCES = ./checker_utils/checker.c \
			./checker_utils/checker_utils.c \
			./checker_utils/ft_strncmp.c \
			./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			./utils/arg_utils.c \
			./utils/command_utils.c \
			./utils/etc_utils.c \
			./utils/stack_utils.c \
			./utils/print_utils.c \
			./utils/push_utils.c \
			./utils/swap_utils.c \
			./utils/sort_utils_1.c \
			./utils/sort_utils_2.c \
			./utils/sort_utils_3.c \
			./utils/sort_utils_4.c \
			./utils/sort_utils_5.c \
			./utils/sort_utils_6.c \
			./lib/ft_atoi.c \
			./lib/ft_lstadd_back.c \
			./lib/ft_lstnew.c \
			./lib/ft_lstlast.c \
			./lib/ft_lstsize.c \
			./lib/ft_split.c \
			./lib/ft_strlcpy.c \
			./lib/ft_strlen.c \
			./lib/ft_strdup.c \
			./command/ft_push.c \
			./command/ft_reverse_rotate.c \
			./command/ft_rotate.c \
			./command/ft_swap.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all : $(NAME)

bonus: $(NAME) $(BONUS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS) : $(BONUS_OBJECTS)
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