/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:16:07 by jaehulee          #+#    #+#             */
/*   Updated: 2023/09/14 21:16:39 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating(t_philo *philo)
{
	if (check_philo_status(philo))
	{
		pthread_mutex_unlock(&(philo->table->forks[philo->left_fork]->fork));
		pthread_mutex_unlock(&(philo->table->forks[philo->right_fork]->fork));
		return (1);
	}
	pthread_mutex_lock(&(philo->table->mutex_last_eat));
	philo->last_eat = get_current_time();
	pthread_mutex_unlock(&(philo->table->mutex_last_eat));
	usleep(philo->table->args->time_to_eat * 1000);
	pthread_mutex_lock(&(philo->table->mutex_eat_count));
	philo->eat_count += 1;
	pthread_mutex_unlock(&(philo->table->mutex_eat_count));
	pthread_mutex_unlock(&(philo->table->forks[philo->left_fork]->fork));
	pthread_mutex_unlock(&(philo->table->forks[philo->right_fork]->fork));
	return (0);
}

static int	thinking(t_philo *philo)
{
	if (check_philo_status(philo))
		return (1);
	print_state(philo->philo_idx, "is thinking");
	return (0);
}

static int	sleeping(t_philo *philo)
{
	if (check_philo_status(philo))
		return (1);
	print_state(philo->philo_idx, "is sleeping");
	usleep(philo->table->args->time_to_sleep);
	philo->last_sleep = get_current_time();
	return (0);
}

void	*philo_life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&(philo->table->mutex_init));
	if (philo->philo_idx % 2)
		usleep(100);
	while (check_philo_status(philo))
	{
		if (get_fork(philo))
			break ;
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (philo);
}
