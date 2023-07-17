# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:21:07 by jaehulee          #+#    #+#              #
#    Updated: 2023/07/11 00:30:45 by jaehulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror -g3

mandatory_path = ./mandatory

parsing_path = $(mandatory_path)/parsing/

parsing_cmd_path = $(parsing_path)/cmd/

parsing_expand_path = $(parsing_path)/expand/

parsing_redir_path = $(parsing_path)/redir/

parsing_util_path = $(parsing_path)/util/

execution_path = $(mandatory_path)/execution/

execution_built_in_path = $(execution_path)/built_in/

execution_execute_path = $(execution_path)/execute/

execution_redirection_path = $(execution_path)/redirection/

execution_util_path = $(execution_path)/util/

env_path = $(mandatory_path)/env/

signal_path = $(mandatory_path)/signal/

parsing_srcs = parse_prompt.c

cmd_srcs = get_cmd.c get_cmd_util.c

expand_srcs = expand_cmd.c expand_quote_double.c expand_quote_none.c \
expand_redir.c expand_redir_util.c expand_util.c

redir_srcs = get_redir.c get_redir_util.c

parse_util_srcs = checker.c checker_util.c ft_strsdup.c ft_strslen.c \
get_pipe_node.c free_for_parse.c quote_manager.c syntax_error.c \
temp_manager.c total_join.c ft_strcmp.c

built_in_srcs = ft_export.c ft_unset.c ft_env.c ft_exit.c ft_echo.c ft_cd.c \
ft_pwd.c built_in_util.c

execute_srcs = execute.c execute_util.c fd_setter.c \
execute_single_pipe.c execute_multiple_pipe.c child_status_checker.c

redirection_srcs = execute_redirection.c open_redirection.c \
heredoc.c heredoc_util.c

execution_util_srcs = ft_perror.c ft_isnum.c ft_free.c free_exit.c ft_close.c \
ft_fork.c

env_srcs = env_manager.c list_manager.c env_converter.c env_converter_util.c \
env_key_manager.c

signal_srcs = signal.c signal_handler.c

all_srcs = $(mandatory_path)/main.c\
$(addprefix $(parsing_path), $(parsing_srcs)) \
$(addprefix $(parsing_cmd_path), $(cmd_srcs)) \
$(addprefix $(parsing_expand_path), $(expand_srcs)) \
$(addprefix $(parsing_redir_path), $(redir_srcs)) \
$(addprefix $(parsing_util_path), $(parse_util_srcs)) \
$(addprefix $(execution_built_in_path), $(built_in_srcs)) \
$(addprefix $(execution_execute_path), $(execute_srcs)) \
$(addprefix $(execution_redirection_path), $(redirection_srcs)) \
$(addprefix $(execution_util_path), $(execution_util_srcs)) \
$(addprefix $(env_path), $(env_srcs)) \
$(addprefix $(signal_path), $(signal_srcs))

RL_LIB = -L$(shell brew --prefix readline)/lib -lreadline -lhistory

RL_INCLUDES = -I$(shell brew --prefix readline)/include/readline

LIB = -Llibft -lft -Llibprintf -lprintf $(RL_LIB)

INCLUDE = -I./libft -I./libprintf -I$(mandatory_path)/ $(RL_INCLUDES)

objs = $(all_srcs:.c=.o)

ECHO_FLAG = 0

all : $(NAME)

$(NAME) : $(objs)
	make -C ./libft all
	make -C ./libprintf all
	$(CC) $(CFLAGS)  -o $@ $^ $(LIB)
ifneq ($(ECHO_FLAG),1)
	echo "Linked into executable \033[K\033[0;32m$(NAME) \033[0m"
	$(eval ECHO_FLAG = 0)
endif

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	printf "\033[Kcompile <$(notdir $<)>\r"

clean :
	make -C ./libft clean
	make -C ./libprintf clean
	$(RM) $(objs) maker
ifneq ($(ECHO_FLAG),1)
	echo "Success to execute \033[K\033[0;32mclean\033[0m"
	$(eval ECHO_FLAG = 0)
endif

fclean :
	make ECHO_FLAG=1 -s clean
	make -s -C ./libft fclean
	make -s -C ./libprintf fclean
	$(RM) $(NAME)
ifneq ($(ECHO_FLAG),1)
	echo "Success to execute \033[K\033[0;32mfclean\033[0m"
	$(eval ECHO_FLAG = 0)
endif

re :
	make ECHO_FLAG=1 -s fclean
	make ECHO_FLAG=1 all
	echo "Success to execute \033[K\033[0;32mre\033[0m"

.PHONY: all .c.o clean fclean re

.SILENT : all clean fclean re $(objs) $(NAME)
