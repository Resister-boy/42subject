/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_start_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:13:39 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 15:37:33 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	*get_program_start_us(void)
{
	static size_t	start_us = 0;
	struct timeval	start_tv;

	if (!start_us)
	{
		gettimeofday(&start_tv, NULL);
		start_us = timeval_to_us(&start_tv);
	}
	return (&start_us);
}

void	set_program_start_time(void)
{
	*(get_program_start_us()) = 0;
	get_program_start_us();
}

size_t	ms_since_program_start(void)
{
	return ((now() - *(get_program_start_us())) / 1000);
}
