/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:13:06 by francoma          #+#    #+#             */
/*   Updated: 2023/03/06 15:22:02 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	read_mutex_int(t_mutex_int *mutex_int)
{
	int	val;

	pthread_mutex_lock(&mutex_int->mutex);
	val = mutex_int->val;
	pthread_mutex_unlock(&mutex_int->mutex);
	return (val);
}

void	write_mutex_int(t_mutex_int *mutex_int, int val)
{
	pthread_mutex_lock(&mutex_int->mutex);
	mutex_int->val = val;
	pthread_mutex_unlock(&mutex_int->mutex);
}

int	read_write_mutex_int(t_mutex_int *mutex_int, int new_val)
{
	int	prev_val;

	pthread_mutex_lock(&mutex_int->mutex);
	prev_val = mutex_int->val;
	mutex_int->val = new_val;
	pthread_mutex_unlock(&mutex_int->mutex);
	return (prev_val);
}
