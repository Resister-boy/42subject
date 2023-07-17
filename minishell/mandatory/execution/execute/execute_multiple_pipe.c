/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:40:02 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/10 00:47:48 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	run_another(t_pipe *pipe, t_env_manager *env_manager)
{
	if (!pipe->cmds || !*pipe->cmds)
		exit(1);
	if (run_built_in(pipe, env_manager) == -1)
		run_execve(pipe, env_manager);
	else
		exit(g_exit_status);
	return (0);
}

static int	exec_child(t_pipe *pipe, t_env_manager *env_manager, \
	t_pipe_fd_manager *pipe_fd_manager, int i)
{
	if (pipe->is_redir_error)
		exit(1);
	if (!pipe->cmds || !*pipe->cmds)
		exit(0);
	set_fd_multiple_pipe(pipe, pipe_fd_manager->pipe_fd, \
		pipe_fd_manager->old_fd, i);
	run_another(pipe, env_manager);
	return (0);
}

static int	run_children(pid_t *pid, t_pipe *pipe_info, \
	t_env_manager *env_manager)
{
	int					i;
	int					run_command_count;
	t_pipe_fd_manager	pipe_fd_manager;

	i = -1;
	pipe_fd_manager.pipe_fd[0] = -1;
	pipe_fd_manager.old_fd = -1;
	run_command_count = 0;
	while (pipe_info)
	{
		pipe(pipe_fd_manager.pipe_fd);
		run_command_count++;
		*pid = ft_fork(&pipe_fd_manager);
		if (*pid == -1)
			break ;
		else if (*pid == 0)
			exec_child(pipe_info, env_manager, &pipe_fd_manager, i);
		ft_close(&pipe_fd_manager.old_fd);
		pipe_fd_manager.old_fd = pipe_fd_manager.pipe_fd[0];
		close(pipe_fd_manager.pipe_fd[1]);
		pipe_info = pipe_info->next;
	}
	ft_close(&(pipe_fd_manager.pipe_fd[0]));
	return (run_command_count);
}

static int	wait_children(pid_t *pid, int run_command_cnt)
{
	int	signum;
	int	status;
	int	child_status;

	signum = 0;
	while (run_command_cnt--)
	{
		status = 0;
		if (*pid == wait(&status))
			child_status = status;
	}
	if (!g_exit_status)
		check_exit_status(child_status, &signum);
	if (signum && signum == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
	else if (signum)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}

int	execute_multiple_pipe(t_pipe_manager *p_man, t_env_manager *env_manager)
{
	pid_t	pid;
	int		run_command_cnt;

	set_parent_ignore_signal();
	run_command_cnt = run_children(&pid, p_man->head, env_manager);
	wait_children(&pid, run_command_cnt);
	return (0);
}
