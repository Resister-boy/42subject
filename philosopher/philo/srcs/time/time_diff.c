/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:46:28 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 15:36:39 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	timeval_to_us(struct timeval *tv)
{
	return (tv->tv_sec * 1000000 + tv->tv_usec);
}

size_t	now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (timeval_to_us(&now));
}
