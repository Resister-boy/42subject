/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:11:09 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/24 18:50:33 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>

enum	e_redir
{
	REDIR_SINGLE_IN = 0,
	REDIR_DOUBLE_IN,
	REDIR_SINGLE_OUT,
	REDIR_DOUBLE_OUT,
};

typedef struct s_io
{
	enum e_redir	type;
	char			*filename;
	struct s_io		*next;
}	t_io;

typedef struct s_cmd
{
	char	*path;
	char	**args;
}	t_cmd;

typedef struct s_tmp
{
	char			*args;
	struct s_tmp	*next;
}	t_tmp;

typedef struct s_pipe
{
	t_io			*redir;
	t_cmd			*cmd;
	char			*test;
	t_tmp			*temp;
	struct s_pipe	*next;
}	t_pipe;

typedef struct s_pipe_manager
{
	t_pipe			*head;
	int				len;
}	t_pipe_manager;

// minishell.c
t_pipe	*get_lastnode(t_pipe_manager *p_manager);
int		parsing(char *prompt, char **envp);

// check_space.c
int		check_space(char chr);

// get_node.c
int		parse_prompt(t_pipe_manager *p_man, char *prompt, char **envp);
void	create_pipe_node(t_pipe_manager *p_man);
void	get_content(t_pipe_manager *p_man, t_io *r_list);
int		is_valid_pipe(char *prompt, size_t idx, int status);
t_pipe	*get_lastnode(t_pipe_manager *p_man);

// get_cmd.c
int		parse_cmd(t_pipe_manager *p_man, char *prompt, size_t idx);
size_t	get_tmpsize(t_pipe *node);
t_cmd	*change_cmds(t_pipe *node);
int		check_dollar(char *str);

// get_redir.c
int		parse_in_redir(char *cmd, size_t idx, t_io **r_list);
int		parse_out_redir(char *cmd, size_t idx, t_io **r_list);
void	connect_redir(t_io **r_list, t_io *redir);

// parse_utils.c
t_tmp	*get_lasttmp(t_pipe *pipe);
int		check_quote(char chr, int *status);
int		parse_no_q(t_pipe_manager *p_man, char *prompt, size_t idx, \
t_io **r_list);
int		parse_single_q(t_pipe_manager *p_man, char *prompt, size_t idx);
int		parse_double_q(t_pipe_manager *p_man, char *prompt, size_t idx);

// free_utils.c
void	free_tmps(t_pipe *node);

// total_join.c
size_t	total_len(char **str);
char	*total_join(char **str);

// expansion.c
char	*expand_env(char **buf);

// lib
char	*ft_substr(char *str, unsigned int start, size_t len);
int		ft_strncmp(char *s1, char *s2, int n);
size_t	ft_strlen(char *str);
size_t	ft_strslen(char **strs);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	**ft_strsdup(char **strs);
char	**ft_split(char *s, char c);

void	print_pipe(t_pipe_manager *p_man);
void	print_redir(t_pipe *node);
void	print_cmd(t_pipe *node);

#endif
