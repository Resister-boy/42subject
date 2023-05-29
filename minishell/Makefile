# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:21:07 by jaehulee          #+#    #+#              #
#    Updated: 2023/05/29 07:27:08 by jaehulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

parsing_path = ./parsing/

built_in_path = ./built_in/

env_path = ./env/

libft_util_path = ./libft_util/

parsing_srcs = parsing.c get_node.c check_utils.c expansion.c expansion_util.c free_utils.c \
get_cmd.c get_cmd_util.c get_node.c get_redir.c total_join.c

built_in_srcs = ft_export.c ft_unset.c ft_env.c ft_exit.c ft_echo.c ft_cd.c \
ft_pwd.c built_in_util.c

env_srcs = env_manager.c list_manager.c env_converter.c

libft_util_srcs = ft_strsdup.c ft_strslen.c

all_srcs = $(addprefix $(built_in_path), $(built_in_srcs)) \
$(addprefix $(env_path), $(env_srcs)) \
$(addprefix $(parsing_path), $(parsing_srcs)) \
$(addprefix $(libft_util_path), $(libft_util_srcs)) \
main.c \
./test/print_pipe.c

LDFLAGS = -L$(shell brew --prefix readline)/lib -lreadline
INCLUDES = -I$(shell brew --prefix readline)/include/readline -I./include

objs = $(all_srcs:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I./libft -I./ $(INCLUDES)

$(NAME) : $(objs)
	echo $(LDFLAGS)
	make -C ./libft
	$(CC) $(CFLAGS)  -o $@ $^ -Llibft -lft $(LDFLAGS)

clean :
	make -C ./libft clean
	$(RM) $(objs)

fclean : clean
	make -C ./libft fclean
	$(RM) $(NAME)

re : fclean
	make

.PHONY: all clean fclean re