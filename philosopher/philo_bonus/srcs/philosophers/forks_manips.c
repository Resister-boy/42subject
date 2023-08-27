/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_manips.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:45:33 by francoma          #+#    #+#             */
/*   Updated: 2023/03/07 13:08:05 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*take_forks(void *arg)
{
	t_philosopher	*philo;
	int				has_forks;

	philo = (t_philosopher *)arg;
	has_forks = (sem_wait(philo->simulation->forks) == 0);
	write_protected_int(&philo->has_forks, has_forks);
	if (has_forks)
	{
		print_msg(philo->simulation->print, MSG_FORK, philo->id);
		print_msg(philo->simulation->print, MSG_FORK, philo->id);
	}
	return (NULL);
}

void	put_down_forks(t_philosopher *philo)
{
	sem_post(philo->simulation->forks);
	write_protected_int(&philo->has_forks, 0);
}
