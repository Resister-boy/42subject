# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 20:21:37 by seonghle          #+#    #+#              #
#    Updated: 2023/06/12 15:53:57 by seonghle         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rc

NAME = libprintf.a

SRCS = ft_printf.c ft_print_hex_type.c ft_utoa.c \
ft_write_set_1.c ft_write_set_2.c printf_itoa.c printf_strlen.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -I./


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	printf "\033[Kcompile <$(notdir $<)>\r"

clean:
	$(RM) $(OBJS) all bonus

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all .c.o clean fclean re

.SILENT : all clean fclean re $(OBJS) $(NAME)