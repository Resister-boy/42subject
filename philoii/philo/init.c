/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:55:16 by jaehulee          #+#    #+#             */
/*   Updated: 2023/08/29 21:55:41 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_args(int argc, char **argv, t_table **table)
{
	(*table)->args->philo_count = atou(argv[1]);
	(*table)->args->time_to_die = atou(argv[2]);
	(*table)->args->time_to_eat = atou(argv[3]);
	(*table)->args->time_to_sleep = atou(argv[4]);
	if ((*table)->args->philo_count == -1 \
	|| (*table)->args->time_to_die == -1 \
	|| (*table)->args->time_to_eat == -1 \
	|| (*table)->args->time_to_sleep == -1)
		return (1);
	if (argc == 6)
	{
		(*table)->args->must_eat_count = atou(argv[5]);
		if ((*table)->args->must_eat_count == -1)
			return (1);
	}
	return (0);
}

static int	init_mutex_fork(t_table **table)
{
	int	i;

	if ((*table)->args->must_eat_count == 0)
		return (1);
	i = 0;
	(*table)->forks = (t_fork **)malloc(sizeof(t_fork *) * \
	((*table)->args->philo_count));
	if ((*table)->forks == NULL)
		return (1);
	while (i < (*table)->args->philo_count)
	{
		(*table)->forks[i] = (t_fork *)malloc(sizeof(t_fork));
		if ((*table)->forks[i] == NULL)
			return (1);
		pthread_mutex_init(&((*table)->forks[i]->fork), NULL);
		(*table)->forks[i]->idx = i;
		(*table)->forks[i]->status = 0;
		i++;
	}
	return (0);
}

static int	init_philos(t_table **table)
{
	int	i;

	i = 0;
	(*table)->philos = (t_philo **)malloc(sizeof(t_philo *) * \
	((*table)->args->philo_count));
	if ((*table)->philos == NULL)
		return (1);
	while (i < ((*table)->args->philo_count))
	{
		(*table)->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		(*table)->philos[i]->philo_idx = i;
		(*table)->philos[i]->eat_count = 0;
		(*table)->philos[i]->is_dead = 0;
		(*table)->philos[i]->last_ate = 0;
		(*table)->philos[i]->last_sleep = 0;
		i++;
	}
	return (0);
}

int	init_mutex_var(t_table **table)
{
	int	i;

	i = 0;
	if (init_mutex_fork(table))
		return (1);
	if (pthread_mutex_init(&((*table)->mutex_init), NULL)
		&& pthread_mutex_init(&((*table)->mutex_last_eat), NULL)
		&& pthread_mutex_init(&((*table)->mutex_eat_count), NULL)
		&& pthread_mutex_init(&((*table)->mutex_monitor), NULL))
		return (1);
	return (0);
}

int	init(int argc, char **argv, t_table **table)
{
	(*table)->args = (t_args *)malloc(sizeof(t_args));
	if ((*table)->args == NULL)
		return (1);
	if (init_args(argc, argv, table))
		return (1);
	if (init_mutex_var(table))
		return (1);
	if (init_philos(table))
		return (1);
	return (0);
}
