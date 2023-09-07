/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:16:07 by jaehulee          #+#    #+#             */
/*   Updated: 2023/08/29 22:35:38 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
  pthread_mutex_lock(&(philo->table->mutex_init));
  if (philo->philo_idx % 2)
    usleep(100);
  while (check_philo_status(phlio->table))
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
}

int	eating(t_philo *philo)
{
  if (check_philo_status(philo->table))
  {
    pthread_mutex_unlock(&(philo->table->fork[philo->left]));
  	pthread_mutex_unlock(&(philo->table->fork[philo->right]));
    return (1);
  }
  pthread_mutex_lock(&(philo->table->mutex_last_eat));
  philo->last_eat = get_current_time();
  philo_mutex_unlock(&(philo->table->mutex_last_eat));
  usleep(philo->table->args->time_to_eat * 1000);
  pthread_mutex_lock(&(philo->table->mutex_eat_count));
  philo->eat_count += 1;
  pthread_mutex_unlock(&(philo->table->mutex_eat_count));
  pthread_mutex_unlock(&(philo->table->fork[philo->left]));
  pthread_mutex_unlock(&(philo->table->fork[philo->right]));
}

int	thinking(t_philo *philo)
{
	if (check_philo_status(philo->table))
    return (1);
  print_state(philo, "is thinking");
  return (0);
}

int	sleeping(t_philo *philo)
{
	if (check_philo_status(philo->table))
    return (1);
  print_state(philo, "is sleeping");
  usleep(philo->table->args->)
  philo->last_sleep = get_current_time();
  return (0);
}
