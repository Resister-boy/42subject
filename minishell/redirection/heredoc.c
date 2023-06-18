/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 07:38:10 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/16 08:27:45 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static void	heredoc_child(int fd, char *delimiter)
{
	char *str;

	set_heredoc_signal();
	while (fd > 0)
	{
		str = readline("> ");
		if (!str)
			exit(0);
		if (!ft_strncmp(str, delimiter, ft_strlen(delimiter) + 1))
		{
			free(str);
			exit(0);
		}
		ft_printf(fd, "%s\n", str);
		free(str);
	}
	exit(1);
}

int	ft_heredoc(char *delimiter, int i)
{
	int		fd;
	pid_t	pid;
	int		child_status;

	fd = new_heredoc_open(i);
	set_signal_parent();
	pid = fork();
	if (pid == -1 && ft_printf(2, "minishell: here_doc: fork error\n"))
		return (-1);
	else if (pid == 0)
		heredoc_child(fd, delimiter);
	waitpid(pid, &child_status, 0);
	if (WEXITSTATUS(child_status) < 0)
		return (close(fd));
	g_exit_status = WEXITSTATUS(child_status);
	if (fd > -1)
	{
		close(fd);
		fd = heredoc_open(i);
	}
	return (fd);
}