/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:22:50 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/16 11:42:38 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	run_built_in(t_pipe *pipe, t_env_manager *env_manager)
{
	int	res;

	res = -1;
	if (!pipe->cmds || !*(pipe->cmds))
		return (-1);
	if (ft_strncmp(*(pipe->cmds), "cd", 3) == 0)
		res = ft_cd(pipe->cmds + 1, env_manager);
	else if (ft_strncmp(*pipe->cmds, "echo", 5) == 0)
		res = ft_echo(pipe->cmds + 1);
	else if (ft_strncmp(*(pipe->cmds), "env", 4) == 0)
		res = ft_env(env_manager);
	else if (ft_strncmp(*(pipe->cmds), "exit", 5) == 0)
		res = ft_exit(pipe->cmds + 1);
	else if (ft_strncmp(*(pipe->cmds), "export", 7) == 0)
		res = ft_export(pipe->cmds + 1, env_manager);
	else if (ft_strncmp(*(pipe->cmds), "pwd", 4) == 0)
		res = ft_pwd();
	else if (ft_strncmp(*(pipe->cmds), "unset", 6) == 0)
		res = ft_unset(pipe->cmds + 1, env_manager);
	if (res != -1)
		g_exit_status = res;
	return (res);
}

void	run_execve(t_pipe *pipe, t_env_manager *env_manager)
{
	if (execve(pipe->cmds[0], \
		pipe->cmds, env_list_to_arr(env_manager)))
	{
		perror("minishell");
		exit(127);
	}
}
