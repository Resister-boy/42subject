/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:11:09 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/10 00:58:28 by seonghle         ###   ########seoul.kr  */
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
# include <errno.h>
# include <sys/stat.h>

int						g_exit_status;
typedef struct termios	t_termios;
typedef struct stat		t_stat;

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
	REDIR_HEREDOC_QUOTE,
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

typedef struct s_pipe_fd_manager
{
	int	pipe_fd[2];
	int	old_fd;
}	t_pipe_fd_manager;

// parse_prompt.c
int		parsing(t_pipe_manager *p_man, \
	t_env_manager *env_manager, char *prompt);

// get_pipe_node.c
t_pipe	*get_lastnode(t_pipe_manager *p_man);
t_pipe	*create_pipe_node(t_pipe_manager *p_man, t_env_manager *e_man);
int		is_valid_pipe(char *prompt, int *idx);

// total_join.c
int		total_len(char **str);
char	*total_join(char **str);

// get_cmd.c 
int		parse_cmd(t_pipe *node, t_env_manager *e_man, char *prompt, int idx);
char	*get_env_path(t_env_manager *e_man, char *str);
void	parse_cmd_util(char *str, t_env_manager *e_man, t_pipe *node);

// get_cmd_util.c
char	*handle_quote(char *str, t_env_manager *e_man);
void	handle_quote_util(char *str, char **buf, t_env_manager *e_man);

// get_redir.c
void	init_redir(t_io *redir);
void	connect_redir(t_pipe *node, t_env_manager *e_man, t_io *cur_redir);
int		parse_out_redir(t_pipe *node, t_env_manager *e_man, char *cmd, \
	int idx);
int		parse_in_redir(t_pipe *node, t_env_manager *e_man, char *cmd, \
	int idx);

// get_redir_util.c
int		get_last_char(char *prompt, int idx, char quote);
int		get_out_redir_content(char *cmd, t_io *redir, int idx);
int		get_in_redir_content(char *cmd, t_io *redir, int idx);
t_io	*get_last_redir(t_pipe *node);

// quote_expand_util.c
void	quote_cmd_expand(char *str, t_env_manager *e_man, t_tmp *temp);
void	quote_cmd_expand_util(char *str, int idx, char **buf, \
	t_env_manager *e_man);
char	*expand_by_quote(char *str, int start, int idx, \
	t_env_manager *e_man);
void	change_cmds_util(t_tmp *tmp, char **cmds);
int		handle_not_dollar(char *str, int idx, char **buf, int *i);

// no_quote_expand_util.c
int		get_dollar_scope(char *str, int i);
void	no_quote_cmd_expand(char *str, t_env_manager *e_man, t_pipe *node);
void	no_quote_expand_util(char *str, int idx, char **buf, \
	t_env_manager *e_man);
int		handle_exit_status(int idx, char **buf, int *i);

// expand_cmd_util.c
t_env	*expand_env_cmd(t_env_manager *e_man, char *str);
void	connect_cmd_tmp(char *cmd, t_pipe *node);
char	*expand_env_cmd_util(t_env_manager *e_man, char *str);
char	*expand_exit_status(void);
char	**change_cmds(t_pipe *node, t_env_manager *e_man);

// expansion_util.c
int		is_valid_dollar(char *str, int idx);
int		get_dollar_count(char *str);
void	handle_env_result(char *str, char **buf, int i, \
	t_env_manager *e_man);
int		check_dollar(char *str);

// expand_redir.c
int		check_is_ambiguous(char *str, char *file);
void	handle_redir_ambiguous(t_io *redir, char *str);
void	handle_redir_expand(char *str, t_env_manager *e_man, t_io *redir);
void	handle_redir_copy(char *str, t_io *redir);
char	**handle_redir_copy_util(char *str, int len);

// expand_redir_util.c
int		handle_redir_str_dq(char *str, char **buf, int i, int *j);
int		handle_redir_str_sq(char *str, char **buf, int i, int *j);
int		handle_redir_str_no(char *str, char **buf, int i, int *j);

// check_util.c
int		is_operator(char chr);
int		is_all_space(char *str);
int		ft_isspace(char chr);
int		check_built_in(char *str);
int		check_status(char chr, int status);

// free_util.c
void	free_prompt(t_pipe_manager *p_man);
void	free_double_str(char ***strs);
void	free_all_redir(t_io *redir);
void	free_redir(t_io *redir);
void	free_tmp(t_tmp *cur);

// temp_util.c
void	get_temp(char *str, t_pipe *node);
int		get_tmpsize(t_pipe *node);
t_tmp	*get_lasttmp(t_pipe *pipe);

// quote_util.c
int		check_quote_include(char *str);
int		check_is_quote(char chr, int status);
int		get_quote_count(char *str);

// valid_util.c
int		valid_pipe(char *prompt);
int		valid_redir(char *cmd, int idx);
int		check_valid_quote(char *prompt);
int		check_empty_prompt(char *prompt);

// error_util.c
int		unexpected_token_error(char *token);

// test/print_pipe.c
void	print_pipe(t_pipe_manager *p_man);

////////////
// public //
////////////

// util
char	**ft_strsdup(char **strs);
int		ft_strslen(char **strs);
int		ft_strcmp(char *s1, char *s2);

// ft_perror.c
int		ft_perror_join(char *prefix, char *postfix);
int		ft_perror(char *cause);

// ft_isnum.c
int		is_unsigned_num(char *arg);
int		is_num(char *arg);

// ft_free.c
int		ft_free(void **target);
int		ft_free_2dim(void ***target);

// ft_close.c
int		ft_close(int *fd);

// ft_fork.c
int		ft_fork(t_pipe_fd_manager *pipe_fd_manager);

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
int		execute_redirection(t_pipe_manager *p_man, \
	t_env_manager *env_manager);

// free_exit.c
void	free_for_exit(t_env_manager *env_manager, int code);

// signal.c
void	set_child_signal(void);
void	set_parent_ignore_signal(void);
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
int		append_redirection(char *outfile);

// heredoc.c
int		ft_heredoc(t_io *redir, int i, \
	t_env_manager *env_manager, int *is_sigint);

// heredoc_util.c
char	*get_heredoc_filename(int i);
int		new_heredoc_open(int i);
int		heredoc_open(int i);
int		unlink_temp_file(void);

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

// fd_setter.c
int		set_fd_single_pipe(t_pipe *pipe);
int		set_fd_multiple_pipe(t_pipe *pipe, int pipe_fd[], int old_fd, int i);

#endif
