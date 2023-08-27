/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:35:36 by francoma          #+#    #+#             */
/*   Updated: 2023/03/06 15:39:36 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "philo.h"

static void	mark_as_done(t_simulation *simulation, pid_t pid)
{
	size_t	i;

	i = 0;
	while (i < simulation->philo_qty)
	{
		if (simulation->philosophers[i].pid == pid)
		{
			simulation->philosophers[i].done = 1;
			break ;
		}
		i++;
	}
}

static void	kill_remaining_philosophers(t_simulation *simulation)
{
	size_t	i;

	i = 0;
	while (i < simulation->philo_qty)
	{
		if (!simulation->philosophers[i].done)
			kill(simulation->philosophers[i].pid, SIGKILL);
		i++;
	}
}

void	wait_philosophers(t_simulation *simulation)
{
	int		status;
	pid_t	pid;

	while (1)
	{
		pid = waitpid(ANY_CHILD_PROCESS, &status, 0);
		if (pid == NO_CHILD_PROCESS_LEFT)
			break ;
		mark_as_done(simulation, pid);
		if (status != 0)
		{
			kill_remaining_philosophers(simulation);
			break ;
		}
	}
}
