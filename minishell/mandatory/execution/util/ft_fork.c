/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:21:25 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/10 00:23:04 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_fork(t_pipe_fd_manager *pipe_fd_manager)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		if (pipe_fd_manager)
		{
			ft_close(&(pipe_fd_manager->old_fd));
			ft_close(&(pipe_fd_manager->pipe_fd[0]));
			ft_close(&(pipe_fd_manager->pipe_fd[1]));
		}
		perror("minishell: fork");
		g_exit_status = 1;
	}
	return (pid);
}
