/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:40:02 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/16 10:38:24 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_fd(t_pipe *pipe, int pipe_fd[], int old_fd, int i)
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
}

static int	run_children(pid_t *pids, t_pipe *pipe_info, \
	t_env_manager *env_manager)
{
	int	i;
	int	pipe_fd[2];
	int	old_fd;

	i = -1;
	while (pipe_info && pipe_info->cmds)
	{
		pipe(pipe_fd);
		pids[++i] = fork();
		if (pids[i] == 0)
		{
			if (pipe_info->is_redir_error)
				exit (1);
			set_fd(pipe_info, pipe_fd, old_fd, i);
			if (run_built_in(pipe_info, env_manager) == -1)
				run_execve(pipe_info, env_manager);
			else
				exit(1);
		}
		if (i != 0)
			close(old_fd);
		old_fd = pipe_fd[0];
		close(pipe_fd[1]);
		pipe_info = pipe_info->next;
	}
	close(pipe_fd[0]);
	return (0);
}

static int	wait_children(pid_t *pids, t_pipe *pipe)
{
	int	i;
	int	child_status;

	i = -1;
	while (pipe)
	{
		if (pipe->is_redir_error)
		{
			pipe = pipe->next;
			continue ;
		}
		waitpid(pids[++i], &child_status, 0);
		check_exit_status(child_status);
		pipe = pipe->next;
	}
	return (0);
}

int	execute_multiple_pipe(t_pipe_manager *p_man, t_env_manager *env_manager)
{
	pid_t	*pids;

	pids = malloc(sizeof(pid_t) * p_man->size);
	run_children(pids, p_man->head, env_manager);
	wait_children(pids, p_man->head);
	free(pids);
	return (0);
}