/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_start_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:13:39 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 15:57:54 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	*get_program_start_time(void)
{
	static size_t	start_ms = 0;
	struct timeval	start_tv;

	if (!start_ms)
	{
		gettimeofday(&start_tv, NULL);
		start_ms = timeval_to_ms(start_tv);
	}
	return (&start_ms);
}

void	set_program_start_time(void)
{
	*(get_program_start_time()) = 0;
	get_program_start_time();
}

size_t	ms_since_program_start(void)
{
	return (now() - *(get_program_start_time()));
}
