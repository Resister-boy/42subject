/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:18:41 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 15:36:26 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	die(t_philosopher *philo)
{
	print_last_msg(philo, MSG_DIE);
	return (STOP);
}

int	is_starved(t_philosopher *philo)
{
	return (now() - philo->last_meal_ms
		>= philo->simulation->time_to_die);
}
