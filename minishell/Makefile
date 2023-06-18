# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:21:07 by jaehulee          #+#    #+#              #
#    Updated: 2023/06/18 22:43:15 by jaehulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

parsing_path = ./parsing/

built_in_path = ./built_in/

env_path = ./env/

libft_util_path = ./libft_util/

execution_path = ./execution/

free_path = ./free/

signal_path = ./signal/

redirection_path = ./redirection/

test_path = ./test/

parsing_srcs = parse_prompt.c get_pipe_node.c check_util.c \
expansion_util.c get_cmd.c get_cmd_util.c get_redir.c total_join.c \
expand_cmd.c expand_cmd_util.c expand_redir.c free_util.c temp_util.c quote_util.c

built_in_srcs = ft_export.c ft_unset.c ft_env.c ft_exit.c ft_echo.c ft_cd.c \
ft_pwd.c built_in_util.c

env_srcs = env_manager.c list_manager.c env_converter.c

libft_util_srcs = ft_strsdup.c ft_strslen.c ft_strcmp.c

execution_srcs = execute.c execute_util.c \
execute_single_pipe.c execute_multiple_pipe.c child_status_checker.c

free_srcs = free_exit.c

signal_srcs = signal.c signal_handler.c

redirection_srcs = execute_redirection.c open_redirection.c \
heredoc.c heredoc_util.c

test_src = print_pipe.c

all_srcs = $(addprefix $(built_in_path), $(built_in_srcs)) \
$(addprefix $(env_path), $(env_srcs)) \
$(addprefix $(parsing_path), $(parsing_srcs)) \
$(addprefix $(libft_util_path), $(libft_util_srcs)) \
$(addprefix $(execution_path), $(execution_srcs)) \
$(addprefix $(free_path), $(free_srcs)) \
$(addprefix $(signal_path), $(signal_srcs)) \
$(addprefix $(redirection_path), $(redirection_srcs)) \
$(addprefix $(test_path), $(test_src)) \
main.c

RL_LIB = -L$(shell brew --prefix readline)/lib -lreadline
RL_INCLUDES = -I$(shell brew --prefix readline)/include/readline -I./include

LIB = -Llibft -lft -Llibprintf -lprintf

INCLUDE = -I./libft -I./libprintf -I./

objs = $(all_srcs:.c=.o)

ECHO_FLAG = 0

all : $(NAME)

$(NAME) : $(objs)
	make -C ./libft all
	make -C ./libprintf all
	$(CC) $(CFLAGS)  -o $@ $^ $(LIB) $(RL_LIB)
ifneq ($(ECHO_FLAG),1)
	echo "Linked into executable \033[0;32m$(NAME) \033[0m"
	$(eval ECHO_FLAG = 0)
endif

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) $(RL_INCLUDES)
	printf "\033[Kcompile <$(notdir $<)>\r"

clean :
	make -C ./libft clean
	make -C ./libprintf clean
	$(RM) $(objs)
ifneq ($(ECHO_FLAG),1)
	echo "Success to execute \033[0;32mclean\033[0m"
	$(eval ECHO_FLAG = 0)
endif

fclean :
	make ECHO_FLAG=1 -s clean
	make -s -C ./libft fclean
	make -s -C ./libprintf fclean
	$(RM) $(NAME)
ifneq ($(ECHO_FLAG),1)
	echo "Success to execute \033[0;32mfclean\033[0m"
	$(eval ECHO_FLAG = 0)
endif

re :
	make ECHO_FLAG=1 -s fclean
	make ECHO_FLAG=1 all
	echo "Success to execute \033[0;32mre             \033[0m"

.PHONY: all .c.o clean fclean re

.SILENT : all clean fclean re $(objs) $(NAME)