/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:18:41 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 15:17:26 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_starved(t_philosopher *philo)
{
	return (now() - philo->last_meal_ms
		>= philo->simulation->time_to_die);
}

void	die(t_philosopher *philo)
{
	print_last_msg(philo->simulation->print, MSG_DIE, philo->id);
	exit(DEAD);
}

int	is_done_sleeping(t_philosopher *philo)
{
	return (now() - philo->last_nap_ms
		>= philo->simulation->time_to_sleep);
}

int	is_done_eating(t_philosopher *philo)
{
	return (now() - philo->last_meal_ms
		>= philo->simulation->time_to_eat);
}

int	has_eaten_enough_times(t_philosopher *philo)
{
	return (philo->simulation->must_eat_count > 0
		&& philo->eat_count >= philo->simulation->must_eat_count);
}
