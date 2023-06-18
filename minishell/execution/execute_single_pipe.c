/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:40:05 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/16 13:28:02 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_exit_status;

static int	set_fd_child(t_pipe *pipe)
{
	if (pipe->in_fd)
		dup2(pipe->in_fd, STDIN_FILENO);
	if (pipe->out_fd)
		dup2(pipe->out_fd, STDOUT_FILENO);
	return (0);
}

int	execute_single_pipe(t_pipe_manager *p_man, t_env_manager *env_manager)
{
	t_pipe	*pipe;
	pid_t	pid;
	int		child_status;

	pipe = p_man->head;
	if (pipe && pipe->cmds)
	{
		if (pipe->is_redir_error)
			return (1);
		if (run_built_in(pipe, env_manager) == -1)
		{
			set_newline_signal();
			pid = fork();
			if (pid == -1 && ft_printf(2, "minishell: %s: fork error\n", \
				pipe->cmds[0]))
				free_for_exit(env_manager, 1);
			if (pid == 0 && !set_fd_child(pipe))
				run_execve(pipe, env_manager);
			waitpid(pid, &child_status, 0);
			check_exit_status(child_status);
			set_signal();
		}
	}
	return (0);
}
