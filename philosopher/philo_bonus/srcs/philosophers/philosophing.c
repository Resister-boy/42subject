/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:18:20 by francoma          #+#    #+#             */
/*   Updated: 2023/03/07 13:08:01 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	thinking(t_philosopher *philo)
{
	pthread_t	forks_taker;

	print_msg(philo->simulation->print, MSG_THINK, philo->id);
	pthread_create(&forks_taker, NULL, take_forks, philo);
	while (!read_protected_int(&philo->has_forks))
	{
		usleep(PHILO_SLEEP);
		if (is_starved(philo))
			return (die(philo));
	}
	pthread_detach(forks_taker);
}

static void	eating(t_philosopher *philo)
{
	print_msg(philo->simulation->print, MSG_EAT, philo->id);
	philo->last_meal_ms = now();
	philo->eat_count++;
	while (!is_done_eating(philo))
	{
		if (is_starved(philo))
			return (die(philo));
		usleep(PHILO_SLEEP);
	}
	put_down_forks(philo);
	if (has_eaten_enough_times(philo))
		exit(DONE);
}

static void	sleeping(t_philosopher *philo)
{
	print_msg(philo->simulation->print, MSG_SLEEP, philo->id);
	philo->last_nap_ms = now();
	while (!is_done_sleeping(philo))
	{
		usleep(PHILO_SLEEP);
		if (is_starved(philo))
			return (die(philo));
	}	
}

void	*philosophing(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	sem_wait(philo->simulation->start);
	set_program_start_time();
	philo->last_meal_ms = now();
	while (1)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}
