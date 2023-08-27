/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_manips.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:45:33 by francoma          #+#    #+#             */
/*   Updated: 2023/03/11 19:21:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_fork(t_philosopher *philo, t_fork *fork)
{
	if (fork->used_by == NOBODY)
	{
		fork->used_by = philo->id;
		print_msg(philo, MSG_FORK);
	}
	return (fork->used_by == philo->id);
}

int	take_forks(t_philosopher *philo)
{
	t_fork	*left_fork;
	t_fork	*right_fork;
	int		took_forks;

	left_fork = &philo->simulation->forks[philo->id];
	right_fork = &philo->simulation->forks[(philo->id + 1)
		% philo->simulation->philo_qty];
	if (left_fork == right_fork)
		return (0);
	pthread_mutex_lock(&left_fork->mutex);
	pthread_mutex_lock(&right_fork->mutex);
	took_forks = (take_fork(philo, left_fork) && take_fork(philo, right_fork));
	pthread_mutex_unlock(&left_fork->mutex);
	pthread_mutex_unlock(&right_fork->mutex);
	return (took_forks);
}

void	put_down_forks(t_philosopher *philo)
{
	t_fork	*left_fork;
	t_fork	*right_fork;

	left_fork = &philo->simulation->forks[philo->id];
	right_fork = &philo->simulation->forks[(philo->id + 1)
		% philo->simulation->philo_qty];
	pthread_mutex_lock(&left_fork->mutex);
	pthread_mutex_lock(&right_fork->mutex);
	left_fork->used_by = NOBODY;
	right_fork->used_by = NOBODY;
	pthread_mutex_unlock(&left_fork->mutex);
	pthread_mutex_unlock(&right_fork->mutex);
}
