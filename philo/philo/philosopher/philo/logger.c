/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:55:50 by dpotvin           #+#    #+#             */
/*   Updated: 2023/04/03 19:01:15 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Timestamp in Milisecond
long long int	get_timestamp(void)
{
	static t_stamp	stamp;
	struct timeval	time;
	long long int	ret;

	if (!stamp.init_mutex)
	{
		pthread_mutex_init(&stamp.t, 0);
		stamp.init_mutex = true;
	}
	pthread_mutex_lock(&stamp.t);
	gettimeofday(&time, NULL);
	if (!stamp.init)
	{
		stamp.starttime = time.tv_sec * 1000 + time.tv_usec / 1000;
		stamp.init = true;
	}
	ret = time.tv_sec * 1000 + time.tv_usec / 1000 - stamp.starttime;
	pthread_mutex_unlock(&stamp.t);
	return (ret);
}

// Basic Console Logger
void	consolelog(uint8_t mode, int nbr)
{
	static pthread_mutex_t	t;
	static t_bool			init;

	if (!init)
	{
		pthread_mutex_init(&t, 0);
		init = true;
	}
	pthread_mutex_lock(&t);
	if (!death_watcher(GET))
	{
		if (mode == EATING)
			printf("%lli %i is eating\n", get_timestamp(), nbr);
		else if (mode == SLEEPING)
			printf("%lli %i is sleeping\n", get_timestamp(), nbr);
		else if (mode == THINKING)
			printf("%lli %i is thinking\n", get_timestamp(), nbr);
		else if (mode == DIED && !death_watcher(GET))
			printf("%lli %i died\n", get_timestamp(), nbr);
		else if (mode == TOOKFORK)
			printf("%lli %i has taken a fork\n", get_timestamp(), nbr);
	}
	pthread_mutex_unlock(&t);
	if (mode == KILL_MUTEX)
		pthread_mutex_destroy(&t);
}

// Error Message + Return
int	errormsg(uint8_t mode)
{
	if (mode == ARGS)
		printf("Error with Arguments\n");
	else if (mode == THREAD)
		printf("Error while creating Thread\n");
	return (1);
}
