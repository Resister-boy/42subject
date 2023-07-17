/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_setter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:54:01 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/10 15:56:04 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_fd_single_pipe(t_pipe *pipe)
{
	if (pipe->in_fd)
		dup2(pipe->in_fd, STDIN_FILENO);
	if (pipe->out_fd)
		dup2(pipe->out_fd, STDOUT_FILENO);
	return (0);
}

int	set_fd_multiple_pipe(t_pipe *pipe, int pipe_fd[], int old_fd, int i)
{
	close(pipe_fd[0]);
	if (pipe->in_fd > 0)
	{
		dup2(pipe->in_fd, STDIN_FILENO);
		if (i != 0)
			close(old_fd);
	}
	else if (i != 0)
	{
		dup2(old_fd, STDIN_FILENO);
		close(old_fd);
	}
	if (pipe->out_fd > 0)
		dup2(pipe->out_fd, STDOUT_FILENO);
	else if (pipe->next)
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	return (0);
}
