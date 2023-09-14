/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:59:28 by jaehulee          #+#    #+#             */
/*   Updated: 2023/09/14 16:00:02 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	time;
	long long		current;

	gettimeofday(&time, NULL);
	current = ((long)time.tv_sec * 1000) + ((size_t)time.tv_usec / 1000);
	return (current);
}
