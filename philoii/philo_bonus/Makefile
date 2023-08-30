# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 20:07:09 by jaehulee          #+#    #+#              #
#    Updated: 2023/08/28 11:33:12 by jaehulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CFLAGS = -Wall -Wextra -Werror

bonus_srcs = 

bonus_objs = $(bonus_srcs:.c=.o)

all : $(NAME)

$(NAME) : $(bonus_objs)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf $(mandatory_objs)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY all clean fclean re