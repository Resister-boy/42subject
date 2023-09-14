/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:08:32 by jaehulee          #+#    #+#             */
/*   Updated: 2023/09/14 20:48:29 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_args(t_table *table)
{
	free(table->args);
}

static void	free_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args->philo_count)
	{
		free(table->philos[i]);
		i++;
	}
	free(table->philos);
}

static void	free_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args->philo_count)
	{
		free(table->forks[i]);
		pthread_mutex_destroy(&(table->forks[i]->fork));
		i++;
	}
	free(table->forks);
}

void	free_table(t_table **table)
{
	free_philos(*table);
	free_forks(*table);
	free_args(*table);
	pthread_mutex_destroy(&((*table)->mutex_init));
	pthread_mutex_destroy(&((*table)->mutex_print));
	pthread_mutex_destroy(&((*table)->mutex_monitor));
	pthread_mutex_destroy(&((*table)->mutex_eat_count));
	pthread_mutex_destroy(&((*table)->mutex_last_eat));
}
