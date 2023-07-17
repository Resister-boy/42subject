/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:22:50 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/10 00:24:10 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static int	is_directory(char *cmd_path)
{
	t_stat	st;

	stat(cmd_path, &st);
	if (S_ISDIR(st.st_mode))
		return (1);
	return (0);
}

static int	check_execve_errno(char *cmd_path, int *errnum)
{
	int	execve_errno;

	execve_errno = errno;
	if (execve_errno == ENOEXEC)
		exit(127 | !ft_printf(2, "minishell: %s: command not found\n", \
			cmd_path));
	if (execve_errno == ENOENT)
		*errnum = 127;
	else
		*errnum = 126;
	if (execve_errno == EISDIR || is_directory(cmd_path))
		ft_printf(2, "minishell: %s: is a directory\n", cmd_path);
	else if (execve_errno == EACCES)
		ft_printf(2, "minishell: %s: Permission denied\n", cmd_path);
	else
	{
		if (ft_strchr(cmd_path, '/'))
			ft_printf(2, "minishell: %s: No such file or directory\n", \
				cmd_path);
		else
			ft_printf(2, "minishell: %s: command not found\n", cmd_path);
		exit(127);
	}
	return (0);
}

void	run_execve(t_pipe *pipe, t_env_manager *env_manager)
{
	int	errnum;

	set_child_signal();
	if (execve(pipe->cmds[0], \
		pipe->cmds, env_list_to_arr(env_manager)))
	{
		errnum = 0;
		check_execve_errno(pipe->cmds[0], &errnum);
		exit(errnum);
	}
}
