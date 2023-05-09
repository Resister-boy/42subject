/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:37:34 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 23:22:13 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

int	ft_create_process(char **argv, t_pipe *pip)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (0);
	pip->in = fd[0];
	pip->out = fd[1];
	pid = fork();
	if (pid == -1)
	{
		ft_close_fd(pip);
		return (0);
	}
	else if (pid == 0)
		ft_control_cproc(argv, pip, pid);
	else
		ft_control_pproc(argv, pip, pid);
	return (1);
}

void	ft_control_cproc(char **argv, t_pipe *pip, pid_t pid)
{
	if (argv == NULL || pip == NULL)
		return ;
	printf("child pid: %d\n", pid);
}

void	ft_control_pproc(char **argv, t_pipe *pip, pid_t pid)
{
	if (argv == NULL || pip == NULL)
		return ;
	printf("perant pid: %d\n", pid);
}
