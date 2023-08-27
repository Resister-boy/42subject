/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:46:42 by francoma          #+#    #+#             */
/*   Updated: 2023/03/07 13:22:50 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_main_semaphores(t_simulation *simulation)
{
	sem_unlink(SEM_START);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	if (init_semaphore(&simulation->start, SEM_START, 0) == ERROR
		|| init_semaphore(&simulation->forks, SEM_FORKS,
			simulation->philo_qty / 2) == ERROR
		|| init_semaphore(&simulation->print, SEM_PRINT, 1) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static t_philosopher	*filter_philosophers(t_philosopher *philosophers,
		int i)
{
	static t_philosopher	philosopher;

	philosopher = philosophers[i];
	free(philosophers);
	return (&philosopher);
}

static t_philosopher	*init_philosopher(size_t i, t_simulation *simulation,
	t_philosopher *philosopher)
{
	philosopher->id = i;
	philosopher->done = 0;
	if (init_numbered_semaphore(&philosopher->has_forks.sem, SEM_PHILO, i, 1)
		== ERROR)
		return (NULL);
	write_protected_int(&philosopher->has_forks, 0);
	philosopher->last_meal_ms = now();
	philosopher->eat_count = 0;
	philosopher->simulation = simulation;
	philosopher->pid = fork();
	return (philosopher);
}

static t_philosopher	*init_philosphers(t_simulation *simulation,
	int *is_main_process)
{
	t_philosopher	*philosophers;
	size_t			i;

	philosophers = malloc(sizeof(*philosophers)
			* simulation->philo_qty);
	if (!philosophers)
		return (NULL);
	*is_main_process = 0;
	i = 0;
	while (i < simulation->philo_qty)
	{
		if (!init_philosopher(i, simulation, &philosophers[i]))
			return (NULL);
		if (philosophers[i].pid == 0)
			return (filter_philosophers(philosophers, i));
		i++;
	}
	*is_main_process = 1;
	return (philosophers);
}

t_simulation	*init_simulation(int argc, char *argv[], int *is_main_process)
{
	static t_simulation	simulation;

	simulation.philo_qty = ft_atost(argv[1]);
	if (init_main_semaphores(&simulation) == ERROR)
		return (NULL);
	simulation.time_to_die = ft_atost(argv[2]);
	simulation.time_to_eat = ft_atost(argv[3]);
	simulation.time_to_sleep = ft_atost(argv[4]);
	if (argc == 6)
		simulation.must_eat_count = ft_atost(argv[5]);
	else
		simulation.must_eat_count = 0;
	simulation.philosophers = init_philosphers(&simulation, is_main_process);
	if (!simulation.philosophers)
		return (NULL);
	return (&simulation);
}
