/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:40:05 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/10 00:24:05 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_if_get_signal(int signum)
{
	if (signum && signum == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
	else if (signum)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}

static int	run_child(t_pipe *pipe, t_env_manager *env_manager)
{
	pid_t	pid;
	int		child_status;
	int		signum;

	set_parent_ignore_signal();
	pid = fork();
	if (pid == 0)
		run_execve(pipe, env_manager);
	waitpid(pid, &child_status, 0);
	check_exit_status(child_status, &signum);
	print_if_get_signal(signum);
	set_signal();
	return (0);
}

int	execute_single_pipe(t_pipe_manager *p_man, t_env_manager *env_manager)
{
	t_pipe	*pipe;
	int		std_in_out_fd[2];

	pipe = p_man->head;
	if (pipe)
	{
		if (pipe->is_redir_error)
		{
			g_exit_status = 1;
			return (0);
		}
		if (!pipe->cmds || !*pipe->cmds)
			return (0);
		std_in_out_fd[0] = dup(STDIN_FILENO);
		std_in_out_fd[1] = dup(STDOUT_FILENO);
		if (set_fd_single_pipe(pipe) || run_built_in(pipe, env_manager) == -1)
			run_child(pipe, env_manager);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		dup2(std_in_out_fd[0], STDIN_FILENO);
		dup2(std_in_out_fd[1], STDOUT_FILENO);
		close(std_in_out_fd[0]);
		close(std_in_out_fd[1]);
	}
	return (0);
}
