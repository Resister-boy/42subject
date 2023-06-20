/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:40:02 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/20 21:22:21 by seonghle         ###   ########seoul.kr  */
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

static int	run_another(t_pipe *pipe, t_env_manager *env_manager)
{
	if (!pipe->cmds || !*pipe->cmds)
		exit(1);
	if (run_built_in(pipe, env_manager) == -1)
		run_execve(pipe, env_manager);
	else
		exit(1);
	return (0);
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
			run_another(pipe_info, env_manager);
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
	int	signum;

	i = -1;
	while (pipe)
	{
		if (pipe->is_redir_error)
		{
			pipe = pipe->next;
			continue ;
		}
		waitpid(pids[++i], &child_status, 0);
		check_exit_status(child_status, &signum);
		pipe = pipe->next;
	}
	if (signum && signum == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
	else if (signum)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}

int	execute_multiple_pipe(t_pipe_manager *p_man, t_env_manager *env_manager)
{
	pid_t	*pids;

	pids = malloc(sizeof(pid_t) * p_man->size);
	set_parent_ignore_signal();
	run_children(pids, p_man->head, env_manager);
	wait_children(pids, p_man->head);
	free(pids);
	return (0);
}
