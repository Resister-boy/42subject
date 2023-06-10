/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:11:09 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/11 01:02:26 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define READLINE_LIBRARY

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
// # include "history.h"
# include <libft.h>
# include <termios.h>

enum	e_status
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
};

enum	e_redir
{
	REDIR_SINGLE_IN,
	REDIR_DOUBLE_IN,
	REDIR_SINGLE_OUT,
	REDIR_DOUBLE_OUT,
	AMBIGUOUS_REDIR,
};

typedef struct s_tmp
{
	char			*args;
	struct s_tmp	*next;
}	t_tmp;

typedef struct s_io
{
	enum e_redir	type;
	char			*sign;
	char			*temp;
	char			*filename;
	struct s_io		*next;
}	t_io;

typedef struct s_pipe
{
	t_io			*redir;
	char			**cmds;
	t_tmp			*temp;
	struct s_pipe	*next;
}	t_pipe;

typedef struct s_pipe_manager
{
	t_pipe			*head;
	int				size;
}	t_pipe_manager;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_env_manager
{
	t_env	*head;
	int		size;
}	t_env_manager;

// parse_prompt.c
int		parse_prompt(t_pipe_manager *p_man, t_env_manager *e_man, char *prompt);
int		parse_no_q(t_pipe *node, t_env_manager *e_man, char *prompt, \
size_t idx);
int		parse_double_q(t_pipe *node, t_env_manager *e_man, char *prompt, \
size_t idx);
int		parse_single_q(t_pipe *node, char *prompt, size_t idx);

// get_pipe_node.c
t_pipe	*get_lastnode(t_pipe_manager *p_man);
t_pipe	*create_pipe_node(t_pipe_manager *p_man, t_env_manager *e_man);
int		is_valid_pipe(char *prompt, size_t *idx, int status);

// total_join.c
size_t	total_len(char **str);
char	*total_join(char **str);

// get_cmd.c 
int		parse_cmd(t_pipe *node, t_env_manager *e_man, char *prompt, size_t idx);
char	*get_env_path(t_env_manager *e_man, char *str);
void	get_temp(char *str, t_pipe *node);
char	**change_cmds(t_pipe *node, t_env_manager *e_man);

// get_cmd_util.c
size_t	get_tmpsize(t_pipe *node);
t_tmp	*get_lasttmp(t_pipe *pipe);

// get_redir.c
void	init_redir(t_io *redir);
void	connect_redir(t_pipe *node, t_env_manager *e_man, t_io *cur_redir);
int		parse_out_redir(t_pipe *node, t_env_manager *e_man, char *cmd, \
size_t idx);
int		parse_in_redir(t_pipe *node, t_env_manager *e_man, char *cmd, \
size_t idx);

// expand_cmd.c
void	no_quote_cmd_expand(char *str, t_env_manager *e_man, t_pipe *node);
void	quote_cmd_expand(char *str, t_env_manager *e_man, t_tmp *temp);

// expand_cmd_util.c
t_env	*expand_env_cmd(t_env_manager *e_man, char *str);
void	connect_cmd_tmp(char *cmd, t_pipe *node);

// expansion_util.c
int		is_valid_dollar(char *str, size_t idx);
size_t	get_dollar_count(char *str);
void	handle_env_result(t_env *env, char **buf, size_t i);

// expand_redir.c
t_env	*expand_env_redir(t_env_manager *e_man, char *str);
void	handle_ambiguous_redir(t_io *redir, char *str);
void	handle_redir_expand(char *str, t_env_manager *e_man, t_io *redir);

// check_util.c
int		is_operator(char chr);
int		is_all_space(char *str);
int		ft_isspace(char chr);
int		check_quote(char chr, int status);
int		check_dollar(char *str);

// libft_util
char	**ft_strsdup(char **strs);
size_t	ft_strslen(char **strs);

// test/print_pipe.c
void	print_pipe(t_pipe_manager *p_man);

///////////////
// execution //
///////////////

// builtin ft_*
int		ft_export(char **args, t_env_manager *env_manager);
int		ft_unset(char **args, t_env_manager *env_manager);
int		ft_env(t_env_manager *env_manager);
int		ft_exit(char **args);
int		ft_echo(char **args);
int		ft_cd(char **args, t_env_manager *env_manager);
int		ft_pwd(void);

// built_in_util
int		is_ignore_first_arg(char *arg);

// env_manager
int		get_key_value(char *arg, char **key, char **value);
int		change_env_value(t_env_manager *env_manager, char *key, char *value);
t_env	*make_env(char *arg);
int		add_env(t_env_manager *env_manager, t_env *new_env);
int		delete_env(t_env_manager *env_manager, char *key);
t_env	*get_env(t_env *env, char *key);
int		is_valid_env_key(char *key);

// list_manager
t_env	*make_node(char *key, char *value);
int		free_node(t_env **node);
t_env	*get_last_node(t_env *head);

// env_converter
int		free_all_node(t_env	*head);
char	**env_list_to_arr(t_env_manager *env_manager);
int		env_arr_to_list(t_env_manager *env_manager, char **envp);

#endif
