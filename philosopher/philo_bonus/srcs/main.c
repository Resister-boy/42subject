/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:49:01 by francoma          #+#    #+#             */
/*   Updated: 2023/03/07 14:30:18 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	valid_arg_format(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_issize_t(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	stop_simulation(t_simulation *simulation)
{
	size_t	i;

	i = 0;
	while (i < simulation->philo_qty)
	{
		close_numbered_semaphore(simulation->philosophers->has_forks.sem,
			SEM_PHILO, i);
		i++;
	}
	free(simulation->philosophers);
	sem_close(simulation->start);
	sem_unlink(SEM_START);
	sem_close(simulation->forks);
	sem_unlink(SEM_FORKS);
	sem_close(simulation->print);
	sem_unlink(SEM_PRINT);
}

static void	start_simulation(t_simulation *simulation)
{
	size_t	i;

	i = 0;
	while (i < simulation->philo_qty)
	{
		sem_post(simulation->start);
		i++;
	}
	wait_philosophers(simulation);
	stop_simulation(simulation);
}

int	main(int argc, char *argv[])
{
	t_simulation	*simulation;
	int				is_main_process;

	if ((argc != 5 && argc != 6) || !valid_arg_format(argc, argv))
		exit_error(WRONG_ARGS);
	simulation = init_simulation(argc, argv, &is_main_process);
	if (!simulation)
	{
		stop_simulation(simulation);
		exit_error(FAILED_TO_INIT_SIMULATION);
	}
	if (is_main_process)
		start_simulation(simulation);
	else
		philosophing(simulation->philosophers);
	return (EXIT_SUCCESS);
}
