/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:11:09 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/19 18:01:01 by jaehulee         ###   ########.fr       */
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

typedef struct s_pipe
{
	t_io			*redir;
	t_cmd			*cmd;
	char			*test;
	struct s_pipe	*next;
}	t_pipe;

typedef struct s_pipe_manager
{
	t_pipe			*head;
	int				len;
}	t_pipe_manager;

// minishell.c
t_pipe	*get_lastnode(t_pipe_manager *p_manager);
void	create_pipe_list(t_pipe_manager *p_manager, char *cmd, char **envp);
int		parsing(char *prompt, char **envp);

// get_redir.c
t_io	*get_redirs(char *cmds);
int		parse_in_redir(char *cmd, size_t idx, t_io **r_list);
int		parse_out_redir(char *cmd, size_t idx, t_io **r_list);
void	connect_redir(t_io **r_list, t_io *redir);

char	*ft_substr(char *str, unsigned int start, size_t len);
int		ft_strncmp(char *s1, char *s2, int n);
size_t	ft_strlen(char *str);
size_t	ft_strslen(char **strs);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	**ft_strsdup(char **strs);
char	**ft_split(char *s, char c);

void	print_pipe(t_pipe_manager *p_manager);
void	print_redir(t_pipe *pipe);

#endif
