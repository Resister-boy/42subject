/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:57:44 by jaehulee          #+#    #+#             */
/*   Updated: 2023/09/14 18:15:38 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_thread(t_table **table)
{
	int	i;

	i = 0;
	while (i < (*table)->args->philo_count)
	{
		pthread_join((*table)->philos[i]->thread_id, NULL);
		i++;
	}
}

int	check_is_dead(t_philo *philo)
{
	int			i;
	long long	current;

	i = 0;
	while (i < philo->table->args->philo_count)
	{
		current = get_current_time();
		if ((current - philo->table->philos[i]->last_eat) >= \
		philo->table->args->time_to_die)
		{
			print_state(philo->table->philos[i]->philo_idx, "died");
			philo->table->is_done = 1;
			return (1);
		}
	}
	return (0);
}
