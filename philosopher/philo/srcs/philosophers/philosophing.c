/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:18:20 by francoma          #+#    #+#             */
/*   Updated: 2023/03/11 19:22:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	thinking(t_philosopher *philo)
{
	if (print_msg(philo, MSG_THINK) == STOP)
		return (STOP);
	while (!take_forks(philo))
	{
		usleep(PHILO_SLEEP);
		if (is_starved(philo))
			return (die(philo));
		if (read_mutex_int(&philo->simulation->over))
			return (STOP);
	}
	return (CONTINUE);
}

static int	eating(t_philosopher *philo)
{
	if (print_msg(philo, MSG_EAT) == STOP)
		return (STOP);
	philo->last_meal_ms = now();
	while (now() - philo->last_meal_ms
		< philo->simulation->time_to_eat)
	{
		usleep(PHILO_SLEEP);
		if (is_starved(philo))
			return (die(philo));
		if (read_mutex_int(&philo->simulation->over))
			return (STOP);
	}
	put_down_forks(philo);
	philo->eat_count++;
	if (philo->simulation->must_eat_count
		&& philo->eat_count >= philo->simulation->must_eat_count)
	{
		write_mutex_int(&philo->state, DONE);
		return (STOP);
	}
	return (CONTINUE);
}

static int	sleeping(t_philosopher *philo)
{
	if (print_msg(philo, MSG_SLEEP) == STOP)
		return (STOP);
	philo->last_nap_ms = now();
	while (now() - philo->last_nap_ms
		< philo->simulation->time_to_sleep)
	{
		usleep(PHILO_SLEEP);
		if (is_starved(philo))
			return (die(philo));
		if (read_mutex_int(&philo->simulation->over))
			return (STOP);
	}
	return (CONTINUE);
}

void	*philosophing(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	philo->last_meal_ms = now();
	if (philo->id % 2)
		usleep(PHILO_ORDERING_SLEEP);
	while (thinking(philo) != STOP
		&& eating(philo) != STOP
		&& sleeping(philo) != STOP)
		;
	return (NULL);
}
