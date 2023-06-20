/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:11:09 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/20 23:10:31 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define READLINE_LIBRARY

# include <libft.h>
# include <ft_printf.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline.h>
# include <history.h>
# include <termios.h>
# include <dirent.h>

typedef struct termios	t_termios;

enum	e_status
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
};

enum	e_redir
{
	REDIR_INPUT,
	REDIR_HEREDOC,
	REDIR_OUTPUT,
	REDIR_APPEND,
	REDIR_AMBIGUOUS,
};

typedef struct s_tmp
{
	char			*args;
	struct s_tmp	*next;
}	t_tmp;

typedef struct s_io
{
	enum e_redir	type;
	char			*filename;
	char			*temp;
	struct s_io		*next;
}	t_io;

typedef struct s_pipe
{
	t_io			*redir;
	char			**cmds;
	int				in_fd;
	int				out_fd;
	int				here_doc_cnt;
	int				is_redir_error;
	t_tmp			*temp;
	struct s_pipe	*next;
}	t_pipe;

typedef struct s_pipe_manager
{
	t_pipe	*head;
	int		size;
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
char	**change_cmds(t_pipe *node, t_env_manager *e_man);

// get_cmd_util.c
void	change_cmds_util(t_tmp *tmp, char **cmds);
char	*handle_quote(char *str, t_env_manager *e_man);

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
void	quote_cmd_expand_util(char *str, size_t idx, char **buf, \
t_env_manager *e_man);

// expand_cmd_util.c
t_env	*expand_env_cmd(t_env_manager *e_man, char *str);
void	connect_cmd_tmp(char *cmd, t_pipe *node);
char	*expand_env_cmd_util(t_env_manager *e_man, char *str);

// expansion_util.c
int		is_valid_dollar(char *str, size_t idx);
size_t	get_dollar_count(char *str);
void	handle_env_result(t_env *env, char **buf, size_t i);
int		check_dollar(char *str);

// expand_redir.c
t_env	*expand_env_redir(t_env_manager *e_man, char *str);
void	handle_REDIR_AMBIGUOUS(t_io *redir, char *str);
void	handle_redir_expand(char *str, t_env_manager *e_man, t_io *redir);

// check_util.c
int		is_operator(char chr);
int		is_all_space(char *str);
int		ft_isspace(char chr);
int		check_built_in(char *str);
int		is_empty_prompt(char *prompt);

// free_util.c
void	free_prompt(t_pipe_manager *p_man);
void	free_double_str(char ***strs);
void	free_all_redir(t_io *redir);
void	free_redir(t_io *redir);
void	free_tmp(t_tmp *cur);

// temp_util.c
void	get_temp(char *str, t_pipe *node);
size_t	get_tmpsize(t_pipe *node);
t_tmp	*get_lasttmp(t_pipe *pipe);

// quote_util.c
int		check_quote_include(char *str);
int		check_is_quote(char chr, int status);
size_t	get_quote_count(char *str);

// test/print_pipe.c
void	print_pipe(t_pipe_manager *p_man);

////////////
// public //
////////////

// util
char	**ft_strsdup(char **strs);
size_t	ft_strslen(char **strs);
int		ft_strcmp(char *s1, char *s2);

// ft_perror.c
int		ft_perror_join(char *prefix, char *postfix);
int		ft_perror(char *cause);

// ft_isnum.c
int		is_unsigned_num(char *arg);
int		is_num(char *arg);

///////////////
// execution //
///////////////

// builtin ft_*.c
int		ft_export(char **args, t_env_manager *env_manager);
int		ft_unset(char **args, t_env_manager *env_manager);
int		ft_env(t_env_manager *env_manager);
int		ft_exit(char **args);
int		ft_echo(char **args);
int		ft_cd(char **args, t_env_manager *env_manager);
int		ft_pwd(void);

// built_in_util.c
int		is_ignore_first_arg(char *arg);

// env_manager.c
int		change_env_value(t_env_manager *env_manager, char *key, char *value);
t_env	*make_env(char *arg);
int		add_env(t_env_manager *env_manager, t_env *new_env);
int		delete_env(t_env_manager *env_manager, char *key);
t_env	*get_env(t_env *env, char *key);

// env_key_manager.c
int		get_key_value(char *arg, char **key, char **value);
int		is_valid_env_key(char *key);

// list_manager.c
t_env	*make_node(char *key, char *value);
int		free_node(t_env **node);
t_env	*get_last_node(t_env *head);

// env_converter.c
int		free_env(t_env_manager *env_manager);
char	**env_list_to_arr(t_env_manager *env_manager);
int		env_arr_to_list(t_env_manager *env_manager, char **envp);

// env_converter_util.c
int		is_exist_oldpwd(char *key);
int		check_shlvl(t_env *env);

// ft_execution_redir.c
int		execute_redirection(t_pipe_manager *p_man);

// free_exit.c
void	free_for_exit(t_env_manager *env_manager, int code);

// signal.c
void	set_child_signal(void);
<<<<<<< HEAD
void	set_newline_signal(void);
=======
void	set_parent_ignore_signal(void);
>>>>>>> da111faa5adfdf6c5ca6922fd020a340a94c91d1
void	set_heredoc_signal(void);
void	set_signal_parent(void);
void	set_signal(void);

// signal_handler.c
void	newline_ctrl_c(int signum);
void	heredoc_ctrl_c(int signum);
void	ctrl_c(int signum);
void	heredoc_parent_ctrl_c(int signum);

// redirection.c
int		output_redirection(char *outfile);
int		input_redirection(char *infile);
int		ft_heredoc(char *delimiter, int i);
int		append_redirection(char *outfile);

// heredoc.c
int		ft_heredoc(char *delimiter, int i);

// heredoc_util.c
char	*get_heredoc_filename(int i);
int		new_heredoc_open(int i);
int		heredoc_open(int i);

// execute.c
int		ft_execution(t_pipe_manager *p_man, t_env_manager *env_manager);

// execute_util.c
int		run_built_in(t_pipe *pipe, t_env_manager *env_manager);
void	run_execve(t_pipe *pipe, t_env_manager *env_manager);

// execute_single_pipe.c
int		execute_single_pipe(t_pipe_manager *p_man, \
	t_env_manager *env_manager);

// execute_multiple_pipe.c
int		execute_multiple_pipe(t_pipe_manager *p_man, \
	t_env_manager *env_manager);

// child_status_checker.c
int		check_exit_status(int child_status, int *signum);

#endif
