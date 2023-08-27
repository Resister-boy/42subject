/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:35:36 by francoma          #+#    #+#             */
/*   Updated: 2023/03/06 15:21:28 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philosophers_are_done(t_philosopher *philos, int qty)
{
	int	i;

	i = 0;
	while (i < qty)
	{
		if (read_mutex_int(&philos[i].state) != DONE)
			return (0);
		i++;
	}
	return (1);
}

static void	join_philosophers(t_simulation *simulation)
{
	size_t	i;

	i = 0;
	while (i < simulation->philo_qty)
	{
		pthread_join(simulation->philosophers[i].t, NULL);
		i++;
	}
}

void	wait_for_philosophers(t_simulation *simulation)
{
	while (!read_mutex_int(&simulation->over)
		&& !philosophers_are_done(simulation->philosophers,
			simulation->philo_qty))
		usleep(MAIN_SLEEP);
	join_philosophers(simulation);
}
