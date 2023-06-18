# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 11:22:40 by seonghle          #+#    #+#              #
#    Updated: 2023/06/12 17:57:37 by seonghle         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = cr

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	   ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
	   ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memcmp.c\
	   ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
	   ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	   ft_putnbr_fd.c ft_memchr.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
			 ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			 ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)


$(NAME): all

all: $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)

all bonus:
	$(RM) all bonus $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $^
	touch $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	printf "\033[Kcompile <$(notdir $<)>\r"

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) all bonus

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: clean fclean re .c.o

.SILENT : all bonus clean fclean re $(OBJS) $(BONUS_OBJS) $(NAME)