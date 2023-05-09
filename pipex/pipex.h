/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:03:31 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 23:14:07 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define ERROR_CMD_NOT_EXIST	"Nonexistent command\n"
# define ERROR_CMD_UNEXECUTABLE	"Unexecutable command\n"

typedef struct s_cmd
{
	char			*cmd;
	char			*op;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipe
{
	int		in;
	int		out;
	t_cmd	*cmds;
	char	**paths;
	size_t	cmd_count;
}	t_pipe;

int		pipex(char **argv, char **envp, t_pipe *pip);
void	ft_init_pipe(t_pipe *pip);

// ft_command_utils.c
void	ft_find_path(char **envp, t_pipe *pip);
void	ft_find_cmd(char *envp, t_pipe *pip);
void	ft_store_cmd(int argc, char **argv, t_pipe *pip);
int		ft_check_executable(char *cmd_path);

// ft_process_utils.c 
int		ft_create_process(char **argv, t_pipe *pip);
void	ft_control_cproc(char **argv, t_pipe *pip, pid_t pid);
void	ft_control_pproc(char **argv, t_pipe *pip, pid_t pid);

// ft_free_utils.c
void	ft_close_fd(t_pipe *pip);

// ft_print_utils.c
void	ft_print_msg(char *msg);
void	ft_print_error(char *error);

// lib
char	*ft_substr(char *str, unsigned int start, size_t len);
int		ft_strncmp(char *s1, char *s2, int n);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	**ft_split(char *s, char c);
t_cmd	*ft_lstnew(char *command, char *option);
t_cmd	*ft_lstlast(t_cmd *lst);
void	ft_lstadd_back(t_cmd **lst, t_cmd *new);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char *src, size_t size);

// test
void	ft_print_cmd(t_pipe *pip);

#endif
