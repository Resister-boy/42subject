/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:46:42 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 15:25:24 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_fork	*init_forks(int philo_qty)
{
	t_fork	*forks;
	int		i;

	forks = malloc(sizeof(*forks) * philo_qty);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < philo_qty)
	{
		forks[i].used_by = NOBODY;
		if (pthread_mutex_init(&forks[i].mutex, NULL) != 0)
		{
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

static t_philosopher	*init_philosphers(t_simulation *simulation)
{
	t_philosopher	*philosophers;
	size_t			i;

	philosophers = malloc(sizeof(*philosophers) * simulation->philo_qty);
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < simulation->philo_qty)
	{
		philosophers[i].id = i;
		philosophers[i].eat_count = 0;
		philosophers[i].simulation = simulation;
		if (pthread_mutex_init(&philosophers[i].state.mutex, NULL) != 0
			|| pthread_create(&philosophers[i].t, NULL, philosophing,
				philosophers + i) != 0)
		{
			free(philosophers);
			return (NULL);
		}
		write_mutex_int(&philosophers[i].state, PHILOSOPHING);
		i++;
	}
	return (philosophers);
}

t_simulation	*init_simulation(int argc, char *argv[])
{
	static t_simulation	simulation;

	simulation.over.val = 0;
	if (pthread_mutex_init(&simulation.over.mutex, NULL) != SUCCESS
		|| pthread_mutex_init(&simulation.print_mutex, NULL) != SUCCESS)
		return (NULL);
	simulation.philo_qty = ft_atost(argv[1]);
	simulation.time_to_die = ft_atost(argv[2]) * 1000;
	simulation.time_to_eat = ft_atost(argv[3]) * 1000;
	simulation.time_to_sleep = ft_atost(argv[4]) * 1000;
	if (argc == 6)
		simulation.must_eat_count = ft_atost(argv[5]);
	else
		simulation.must_eat_count = 0;
	simulation.forks = init_forks(simulation.philo_qty);
	if (!simulation.forks)
		return (NULL);
	simulation.philosophers = init_philosphers(&simulation);
	if (!simulation.philosophers)
		return (NULL);
	return (&simulation);
}

void	end_simulation(t_simulation *simulation)
{
	size_t	i;

	i = 0;
	while (i < simulation->philo_qty)
	{
		pthread_mutex_destroy(&simulation->philosophers[i].state.mutex);
		pthread_mutex_destroy(&simulation->forks[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&simulation->over.mutex);
	pthread_mutex_destroy(&simulation->print_mutex);
	free(simulation->forks);
	free(simulation->philosophers);
}
