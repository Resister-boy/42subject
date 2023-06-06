/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:11:09 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/06 12:24:56 by jaehulee         ###   ########.fr       */
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

// minishell.c
t_pipe	*get_lastnode(t_pipe_manager *p_man);

// ft_isspace.c
int		ft_isspace(char chr);

// get_node.c
int		parse_prompt(t_pipe_manager *p_man, char **envp, char *prompt);
t_pipe	*get_lastnode(t_pipe_manager *p_man);

// get_cmd.c
int		parse_cmd(t_pipe *node, char *prompt, size_t idx);
size_t	get_tmpsize(t_pipe *node);
char	**change_cmds(t_pipe *node, char **envp);
int		check_dollar(char *str);

// get_cmd_util.c 
char	*get_env_path(char **envp, char *str);

// get_redir.c
int		parse_in_redir(t_pipe *node, char *cmd, size_t idx);
int		parse_out_redir(t_pipe *node, char *cmd, size_t idx);
void	connect_redir(t_pipe *node, t_io *redirection);

// parse_utils.c
t_tmp	*get_lasttmp(t_pipe *pipe);
int		check_quote(char chr, int status);
int		parse_no_q(t_pipe *node, char *prompt, size_t idx);
int		parse_single_q(t_pipe *node, char *prompt, size_t idx);
int		parse_double_q(t_pipe *node, char *prompt, size_t idx);

// free_utils.c
void	free_tmps(t_pipe *node);

// total_join.c
size_t	total_len(char **str);
char	*total_join(char **str);

// expansion.c
void	expand_env_cmd(char *str, t_pipe *node);
char	*expand_env_redir(char *str);
void	expand_env_quote(char *buf, t_tmp *temp);
void	handle_redir_expand(char *str, t_io *redir);

// expansion_util.c
void	connect_cmd_tmp(char *str, t_pipe *node);
void	handle_expand(char *str, t_pipe *node);
void	get_temp(char *str, t_pipe *node);
size_t	get_dollar_count(char *str);
int		is_valid_dollar(char *str, size_t idx);

// libft_util
char	**ft_strsdup(char **strs);
size_t	ft_strslen(char **strs);

// test
void	print_pipe(t_pipe_manager *p_man);

int		is_all_space(char *str);

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
